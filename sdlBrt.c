/*
    Name:       sdlBrt.c
    Purpose:    Core (wxBasic) version for sdlBasic
    Author:     David Cuny
    modify __vroby__ <__vroby__@libero.it>
    Copyright:  (c) 2001 David Cuny <dcuny@lanset.com>
    Licence:    LGPL
*/

/*
#define __DEBUG_MEMORY__
#define __DEBUG_TRACE__
*/



#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>

#include "sdlBrt.h"
#include "unzip/unzip.h"
#include "SDLengine/SDLengine.h"
#include "BASengine/BASengine.h"

#include "shared.h"
#include "trace.h"
#include "error.h"
#include "stack.h"
#include "data.h"
#include "symbol.h"
#include "var.h"
#include "array.h"
#include "node.h"
#include "builtin.h"

#include "class.h"

PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER|PSP_THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

#define  MAXFILES  40

char basfiles[MAXFILES][64];
int filecount ;
char sdlbasicfile[64];

int PSP_TV_CABLE = 0;
int PSP_TV_LACED = 0;

//____________________________________________________________________________________________________________________

/* get command line args, return offset if main file is tagged */
long findBind( char *title)
{
    FILE    *file;
    char    tag[32];
    long tagOffset;

    /* get the name of the *this* file */
    file = fopen( title, "r" );
    if (file == NULL) {
        ePrintf( Init, "Can't open file %s", title);
    }

    /* look to see if it ends with a bind tag */
    fseek( file, -18, 2 );
    fgets( tag, 18, file );
    fclose( file );

    /* examine the tag */
    if (strcspn(tag,"bind") != 0) {
        /* parse the number */
        sscanf( tag+2, "%ld", &tagOffset );
	//tagOffset=0;
	printf("tagoffset:%ld\n",tagOffset);
        if (tagOffset == 0) {
            ePrintf( Init, "Tag in %s is corrupt %d", title);
	    exit(2);
        }
        /* return the offset */
        return tagOffset;
    } else {
        /* no offset */
        return 0;
    }
}
//____________________________________________________________________________________________________________________

int interpret( int cmdArgc, char **cmdArgv )
{

    int i,r;
    long offset;


    /* initialize */
    argCountStack = newStack(32);	/* count of parameters */
    blockStack = newStack(32);		/* control block stack */
    lineStack = newStack(32);		/* current line number */
    sharedStack = newStack(128);	/* list of shared variables */
    currentScope = NULL;            	/* routine being defined */
    oldScopeP=0;			/* intial oldScope=0 */
    oldScope[oldScopeP]=currentScope;	/*oldScope0 =NULL */
    currentType = NULL;             	/* no type being defined */
    initKeywords();                 	/* builtin keywords */
    initBuiltins();                 	/* builtin functions */
    initConsts();                   	/* builtin constants */



    // if name of executable <> sdlBrt =autoboot
    r=strlen(cmdArgv[0]);

	if (cmdArgc==1) {
	    	cmdArgv[cmdArgc]=(char *)malloc(strlen(sdlbasicfile)+1);
		cmdArgc=2;
		strcpy(cmdArgv[1],sdlbasicfile);
	}
#ifdef UNIX
	if (0) { //deniska no need to do binding for psp
    //if (strncasecmp(cmdArgv[0]+(r-10),"sdlbrt.prx",10)!=0 ){
    //if (strncasecmp(cmdArgv[0]+(r-9),"EBOOT.PBP",9)!=0 ){
#else
    if (strnicmp(cmdArgv[0]+(r-10),"sdlbrt.exe",10)!=0 && strnicmp(cmdArgv[0]+(r-6),"sdlbrt",6)!=0 ){
#endif
	/* load the bindfile */
	offset=findBind( cmdArgv[0]);
	if (offset!=0){
	    if (!pushIncludeFile( cmdArgv[0], offset )){
		ePrintf( Init, "File not found\n");
		return -1;
	    }
	}
	else{
#ifdef UNIX
	    cmdArgv[cmdArgc]=(char *)malloc(strlen(cmdArgv[0])+16);
	    strcpy(cmdArgv[cmdArgc],cmdArgv[0]);
	    strcat(cmdArgv[cmdArgc],".sdlbas\0");
#else
	    cmdArgv[cmdArgc]=(char *)malloc(strlen(cmdArgv[0])+16);
	    strncpy(cmdArgv[cmdArgc],cmdArgv[0],strlen(cmdArgv[0])-4 );
	    strcat(cmdArgv[cmdArgc],".sdlbas\0");
#endif
	    if (!pushIncludeFile( cmdArgv[cmdArgc], 0 )){
		ePrintf( Init, "File not found\n");
		return -1;
	    }
	}

	/* shift args over by 1 */
        cmdArgc++;
        for ( i = cmdArgc; i > 0; i-- ) {
            cmdArgv[i] = cmdArgv[i-1];
        }
        /* first arg is "sdlbrt" */
        strcpy(cmdArgv[0] ,"sdlBrt" );
    }
    else{
	if(cmdArgc>1){
	    if (!fileExist(cmdArgv[1]) ){
		ePrintf( Init,"%s: file not found ....\n",cmdArgv[1]);
		exit(2);
	    }
	}
	/* load the file */
	if (!pushIncludeFile( cmdArgv[1], 0 )) {
	    ePrintf( Init, "File not found\n");
	    return -1;
	}
    }

    /* parse the file */
    yyparse();

    /* deferred? */
    if (deferredCode != NULL) {
        eval( deferredCode );
        freeNode( deferredCode );
    }
    return 0;
}

//____________________________________________________________________________________________________________________

void pspDveScreenInit(int mode);
void pspDveScreenClear(void);
void pspDveScreenPrintf(const char *fmt, ...) __attribute__((format(printf,1,2)));
int pspDveScreenPrintData(const char *buff, int size);
void pspDveScreenSetBackColor(u32 color);
void pspDveScreenSetTextColor(u32 color);

void debugPrintf(const char *fmt, ...) __attribute__((format(printf,1,2)));

void debugSetup() {
	/* get SDL video preferences */
	FILE *fd;
	char temp[256];
	int x;

	fd = fopen("SDL_VID_PREFS", "r");
	if (fd != NULL)
	{
		for (;;)
		{
			temp[0] = 0;
			fgets(temp, 255, fd);
			if (temp[0] == 0)
				break;
			if (!strncmp(temp, "-vmode", 6))
			{
				temp[0] = 0;
				fgets(temp, 255, fd);
				sscanf(temp, "%d", &x);
				PSP_TV_CABLE = x;
			}
			if (!strncmp(temp, "-laced", 6))
			{
				temp[0] = 0;
				fgets(temp, 255, fd);
				sscanf(temp, "%d", &x);
				PSP_TV_LACED = x;
			}
		}
		fclose(fd);
	}
	else
	{
		/* no prefs file - default to "normal" LCD */
		PSP_TV_CABLE = 0;
		PSP_TV_LACED = 0;
	}

	if (!PSP_TV_CABLE)
	{
		pspDebugScreenInit();
		pspDebugScreenClear();
	}
	else
	{
		pspDveScreenInit((PSP_TV_CABLE == 1) ? 0 : PSP_TV_LACED ? 2 : 1);
		pspDveScreenClear();
	}

}

void debugScreenSetBackColor(u32 c) {
	if (!PSP_TV_CABLE)
		pspDebugScreenSetBackColor(c);
	else
		pspDveScreenSetBackColor(c);
}

void debugScreenSetTextColor(u32 c) {
	if (!PSP_TV_CABLE)
		pspDebugScreenSetTextColor(c);
	else
		pspDveScreenSetTextColor(c);
}

void debugScreenClear() {
	if (!PSP_TV_CABLE)
		pspDebugScreenClear();
	else
		pspDveScreenClear();
}

void debugPrintf(const char *format, ...)
{
	va_list	opt;
	char	buff[2048];
	int		bufsz;

	va_start(opt, format);
	bufsz = vsnprintf( buff, (size_t) sizeof(buff), format, opt);
	if (!PSP_TV_CABLE)
		pspDebugScreenPrintData(buff, bufsz);
	else
		pspDveScreenPrintData(buff, bufsz);
	va_end(opt);
}

void readBasFiles() {
	filecount =0;
  DIR *dp;
  struct dirent *dir;
  if ( (dp = opendir(".")) == NULL ) {
    fprintf(stderr, "Can't open directory: ");
    exit(1);
  }
  while ((dir = readdir(dp)) != NULL && filecount<MAXFILES) {
        if (strstr(dir->d_name,".sdlbas")==NULL) continue;
    //printf("%s\n", dir->d_name);
    strcpy(basfiles[filecount],dir->d_name);
    filecount++;
  }
  closedir(dp);
}

void printlogo() {
	debugScreenSetBackColor(0x00770000);
	debugScreenClear();
	if (PSP_TV_CABLE)
		debugPrintf("\n\n\n\n\n");
	debugPrintf("\
\t\t  ___  ___  __      ___   __   ___  __  __\t\t \n \
\t\t/ __)(   \\(  )    (  ,) (  ) / __)(  )/ _) \n \
\t\t\\__ \\ ) ) ))(__    ) ,\\ /__\\ \\__ \\ )(( (_ \n \
\t\t(___/(___/(____)  (___/(_)(_)(___/(__)\\__)       \n\
\n\n");

}

void selectBasFile(){
	int i;
    int selected=0;
	SceCtrlData cpad;

	debugSetup();

	memset(sdlbasicfile,0,64);
	readBasFiles();
	if (filecount==0) {
		printlogo();
		debugScreenSetBackColor(0x00000077);
		debugPrintf("\n\n\n\n\t\t\tNO .SDLBAS FILES FOUND!\n\n\n\n\tPLEASE PLASE THE FILES IN THE DIRECTORY WITH EBOOT.PBP.\n\n\n\n\n");
		sceKernelDelayThread(3000000);
		return;

	}
	if (filecount==1)  {//only one file
                strcpy(sdlbasicfile,basfiles[0]);
		return;
	}

	while (strlen(sdlbasicfile)==0) {
		printlogo();
		debugScreenSetBackColor(0x00007700);
		debugPrintf("\t\t\t\tPLEASE SELECT THE FILE:\t\t\t\t\t");
		debugScreenSetBackColor(0x00000000);
		debugPrintf("\n\n");
		for (i=0; i<filecount; i++) {
            if (i==selected) {
				debugScreenSetTextColor(0x00ffff00);
				if (PSP_TV_CABLE)
					debugPrintf("\t");
                debugPrintf(">>> ");
				debugScreenSetTextColor(0xffffffff);
			}
            else {
				if (PSP_TV_CABLE)
					debugPrintf("\t");
                debugPrintf("    ");
			}
            debugPrintf("%s\n",basfiles[i]);
        }
		for (i=0; i< 23-filecount; i++)
            debugPrintf("\n");

		while (1) {
            sceCtrlReadBufferPositive(&cpad, 1);
            if ((cpad.Buttons & PSP_CTRL_UP) || (cpad.Ly <= 0x30)){
                if (selected>0) selected--;
                    break;
            }
            if ((cpad.Buttons & PSP_CTRL_DOWN) || (cpad.Ly >= 0xD0)){
                if (selected<filecount-1) selected++;
                    break;
            }
            if (cpad.Buttons & PSP_CTRL_CROSS) {
                strcpy(sdlbasicfile,basfiles[selected]);
                    break;
            }
        }
		sceKernelDelayThread(80000);
		sceDisplayWaitVblankStart();
	}
}


int main(int argc, char **argv)
{
    int r,r1;
    char *curdir;
    int audio,socket,debug,defaults;


    /* default settings */
    audio=1;
    socket=1;
    defaults=1;
    debug=0;

    remove("sdlBasic.err");

    /* the command line param */
    r1=0;
    for (r=0;r<argc;r++){
	cmdArgv[r1]=eCopyString(argv[r]);
#ifdef UNIX
	if (strcasecmp(cmdArgv[r1],"--nodefaults")==0)
	    defaults=0;
	if (strcasecmp(cmdArgv[r1],"--nosound")==0)
	    audio=0;
	if (strcasecmp(cmdArgv[r1],"--nosocket")==0)
	    socket=0;
	if (strcasecmp(cmdArgv[r1],"--debug")==0)
	    debug=1;
	if (strcasecmp(cmdArgv[r1],"--version")==0){
	    printf( "sdlBasic runtime(sdlBrt) release  %s\n", RELEASE);
	    exit(0);
	}
	if (strcasecmp(cmdArgv[r1],"--license")==0){
	    printf( "%s\n", LICENSE);
	    exit(0);
	}
	if (strcasecmp(cmdArgv[r1],"--copyright")==0){
	    printf(  "%s: see documentation for all contributors \n", COPYRIGHT);
	    exit(0);
	}
	if (strcasecmp(cmdArgv[r1],"--help")==0){
	    printf(  "sdlBasic runtime(sdlBrt) release  %s\n syntax: sdlBrt [option] foo.sdlbas \n Options:\n --nosound  : disable sound\n --nosocket : disable socket commands\n --nodefaults : disable creation of default display\n --debug    : start the program step by step\n --version  : software version\n --license  : license of software\n --copyright: credits of software\n --help     : this help\n",RELEASE );
	    exit(0);
	}
#else
	if (stricmp(cmdArgv[r1],"--nodefaults")==0)
	    defaults=0;
	if (stricmp(cmdArgv[r1],"--nosound")==0)
	    audio=0;
	if (stricmp(cmdArgv[r1],"--nosocket")==0)
	    socket=0;
	if (stricmp(cmdArgv[r1],"--debug")==0)
	    debug=1;
	if (stricmp(cmdArgv[r1],"--version")==0){
	    printf( "sdlBasic runtime(sdlBrt) release  %s\n", RELEASE);
	    exit(0);
	}
	if (stricmp(cmdArgv[r1],"--license")==0){
	    printf( "%s\n", LICENSE);
	    exit(0);
	}
	if (stricmp(cmdArgv[r1],"--copyright")==0){
	    printf(  "%s: see documentation for all contributors \n", COPYRIGHT);
	    exit(0);
	}
	if (strcasecmp(cmdArgv[r1],"--help")==0){
	    printf(  "sdlBasic runtime(sdlBrt) release  %s\n syntax: sdlBrt [option] foo.sdlbas \n Options:\n --nosound  : disable sound\n --nosocket : disable socket commands\n --nodefaults : disable creation of default display\n --debug    : start the program step by step\n --version  : software version\n --license  : license of software\n --copyright: credits of software\n --help     : this help\n",RELEASE );
	    exit(0);
	}
#endif
	if (cmdArgv[r1][0]!='-')
	    r1++;
	else
	    eFree(cmdArgv[r1]);
    }
    cmdArgc=r1;

    r=strlen(cmdArgv[0]);
#ifdef UNIX
    if (strncasecmp(cmdArgv[0]+(r-6),"sdlbrt",6)==0 ){
#else
    if (strnicmp(cmdArgv[0]+(r-10),"sdlbrt.exe",10)==0 || strnicmp(cmdArgv[0]+(r-6),"sdlbrt",6)==0 ){
#endif
	// if missing file name return a little message of the syntax
	if (cmdArgc <= 1) {
	   printf("sdlBasic runtime (sdlBrt) syntax: sdlBrt program.sdlbas\n");
	return 0;
	}
    }

	scePowerSetClockFrequency (333,333,166);

    /*initializing SDLengine module */
    r=initialize(audio,socket,defaults);
	if (r < 0)
		exit(0);

	if (argc==1) {
		selectBasFile();
	}

/* gp2x Problem with allocation strings ??? */
#if defined(WIN32)
	fontPath=(char *)malloc(256);
	strcpy(fontPath,getenv("WINDIR"));
	strcat(fontPath,"\\fonts\\DejaVuSans.ttf\0");
	if (!fileExist(fontPath))fontPath=".\\DejaVuSans.ttf";
#else
	fontPath=(char *) malloc(256);
	strcpy(fontPath,font_prefix);
	strcat(fontPath,"/dejavu/DejaVuSans.ttf\0");
	if (!fileExist(fontPath))fontPath="./DejaVuSans.ttf";
#endif


/*
#if defined(WIN32)
	fontPath=(char *)malloc(256);
	strcpy(fontPath,getenv("WINDIR"));
	strcat(fontPath,"\\fonts\\DejaVuSans.ttf\0");
	if (!fileExist(fontPath))fontPath=".\\DejaVuSans.ttf";
//#elif defined(GP2X)
//	fontPath=(char *) malloc(256);
//	strcpy(fontPath,"/mnt/sd/sdlBasic/share/fonts/ttf/dejavu/DejaVuSans.ttf");
//	if (!fileExist(fontPath))strcpy(fontPath,"./DejaVuSans.ttf");
    	//printf(" font:%s| \n",fontPath); //Debug
#else
	fontPath=(char *) malloc(256);
	strcpy(fontPath,font_prefix);
	strcat(fontPath,"/dejavu/DejaVuSans.ttf\0");
	if (!fileExist(fontPath))fontPath="./DejaVuSans.ttf";
#endif
*/



    if (r != 0){
	ePrintf( Init,"error number %d. Please reinstall sdlBasic.\n",r);
	return -1;
    }
    /*initialize basic data function buffer */
    init_data();

    /* initialize lvldir */
    lvldir=0;

    /* initialize sistem memory bank */
    init_membank();

    if (cmdArgc<=1  ){
	cmdArgv[1]=cmdArgv[0];
    }
    /* autochange directory */
#ifdef UNIX
    if(cmdArgv[1][0]=='/'){
	r=strlen(cmdArgv[1]);
	curdir=(char *)malloc(r+1);
	while(cmdArgv[1][r]!='/')r--;
	strncpy(curdir,cmdArgv[1],r);
	chdir(curdir);
    }
#elif AMIGA
    {
	r=strlen(cmdArgv[1]);
	curdir=(char *)malloc(r+1);

	if (curdir)
	{
	    STRPTR path;
	    strcpy(curdir,cmdArgv[1]);
	    path = FilePart(curdir);
	    *path = 0;
	    chdir(curdir);
	}
    }
#else
    if(cmdArgv[1][2]=='\\'){
	r=strlen(cmdArgv[1]);
	curdir=(char *)malloc(r+1);
	while(cmdArgv[1][r]!='\\')r--;
	strncpy(curdir,cmdArgv[1],r);
	chdir(curdir);
    }
#endif

    /* starting interpreter */
    r= interpret(cmdArgc, cmdArgv);
    /* terminate SDLengine */
    terminate();
    return r;
}
