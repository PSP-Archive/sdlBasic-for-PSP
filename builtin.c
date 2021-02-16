/*
    Name:       builtin.c
    Purpose:    builtin routines for wxBasic modify for sdlBasic
    Author:     David Cuny    modify __vroby__
    Copyright:  (c) 2001 David Cuny <dcuny@lanset.com>
    Licence:    LGPL
*/

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

//#include "const.h"
//#include "eval.h"
//#include "keyword.h"
//#include "lexer.h"
#include "class.h"

extern char *symbolName[];

void notYet( char *name )
{
    error_description="not implemented yet ";
    error_type=1;
    ePrintf( Runtime, "%s is not implemented yet", name );
}
//_______________________________________________________________________________________________________________________

/* basPrintStack: debugging wrapper of printStack */
void basPrintStack()
{
    printStack();
    pushNumber( 0 );
}

//_______________________________________________________________________________________________________________________

/* basConcat: concatenate two strings */
void basConcat()
{
    int     len1, len2;
    char    *string1, *string2, *buffer;

    string2 = popString();
    string1 = popString();


    len1 = strlen( string1 ),
    len2 = strlen( string2 );

    buffer = (char *)eMalloc( len1 + len2 + 1 );

    memcpy( buffer, string1, len1 );
    memcpy( buffer+len1, string2, len2 );
    buffer[len1+len2] = '\0';
    pushString( buffer );
    /*
    * ivanixcu: debug memleak
    */
    eFree(string1);
    eFree(string2);
}
//_______________________________________________________________________________________________________________________

/* basConvBas: returns representation from base to base */
void basConvBase()
{
    notYet("ConvBase");
    pushNumber(0);
}
//_______________________________________________________________________________________________________________________

void basIndexes()
{
    int     indexes;

    /* array is on stack */
    indexes = getArrayIndexes();
    popNumber();

    pushNumber(indexes);
}
//_______________________________________________________________________________________________________________________



//_________________________________________________________________________________________________________________________
//
// Run time
//_________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________

/* bas Arguments :return the arguments(n) or the number of arguments */
void basArgument()
{
    int     index;

    if (argCount==0){
	//copyStackItem( localstart );
	pushNumber(cmdArgc);
    }
    else{
	index = (int)popNumber();
	//copyStackItem( localstart+index );
	pushStringCopy( cmdArgv[index]);
    }
}
//_______________________________________________________________________________________________________________________


/* basArgc: return number of args in caller */
void basArgc()
{
    /* arg count is at localstart */
    //copyStackItem( localstart );
    pushNumber(cmdArgc);
}
//_______________________________________________________________________________________________________________________

/* basArgv: return arg onto stack */
void basArgv()
{
    int     index;
    index = (int)popNumber();
    pushStringCopy( cmdArgv[index]);
}
//_______________________________________________________________________________________________________________________

/* basCommand: returns requested arg from command line */
void basCommand()
{
    int     argNum;

    /* was an arg passed? */
    if (argCount == 0) {
        /* return count of args */
        pushNumber( cmdArgc );

    } else {

        /* get arg number */
        argNum = popNumber();
        if (argNum < 0 || argNum > cmdArgc) {
            /* out of range */
            pushStringCopy( "" );

        } else {
            /* return copy of arg */
            pushStringCopy( cmdArgv[ argNum-1 ] );
        }
    }
}
//_______________________________________________________________________________________________________________________

//setenv(varname,value): set a enviremont variable in currently os. if variable exist it will be overwrite
void basSetEnv()
{
    char * varname;
    char *value;
#if defined(WIN32)
    char *cmd;
#endif

    value=popString();
    varname=popString();
#if defined(WIN32)
    cmd=(char *)malloc(512);
    strcpy(cmd,"set ");
    strcat(cmd,varname);
    strcat(cmd,"=");
    strcat(cmd,value);
    cmd[strlen(cmd)]='\0';
    pushNumber(system(cmd));
#else
    pushNumber(setenv(varname,value,1));
#endif
}

//_______________________________________________________________________________________________________________________

//getenv(varname): return the value of enviremont variable in currently os
void basGetEnv()
{
    char *varname;
    varname=popString();
    pushStringCopy( getenv(varname) );
    eFree(varname);
}
//_______________________________________________________________________________________________________________________

/* basRun: run command on new thread */
void basRun()
{
    notYet("Run");
    pushNumber(0);
}
//_______________________________________________________________________________________________________________________

/* basShell: execute command, wait until finished */
void basShell()
{
    char    *string;
    string = popString();
    system(string);
    eFree(string);
    pushNumber(0);
}
//_______________________________________________________________________________________________________________________

/* basStop:block the code and start debug */
void basStop()
{
    debug=1;
    error_type=2;
    error_description="stop encountered";
    screendebug();
    pushNumber(0);
}
//_______________________________________________________________________________________________________________________
//
// Array
//_________________________________________________________________________________________________________________________

/* basLBound: returns lower bound of array */
void basLBound()
{
    int     index, range;

    index = popNumber();
    /* leave array pointer on stack */

    range = getArrayBound( index, 0 );

    /* pop array pointer */
    popNumber();

    pushNumber(range);
}
//_______________________________________________________________________________________________________________________

/* basQuickSort: sort an array */
void basQuickSort()
{
    notYet("QuickSort");
    pushNumber(0);
}
//_______________________________________________________________________________________________________________________

/* basUBound: upperbound of array */
void basUBound()
{
    int     index, range;

    index = popNumber();
    /* leave array pointer on stack */

    range = getArrayBound( index, 1 );

    /* pop array pointer */
    popNumber();

    pushNumber(range);
}
//_______________________________________________________________________________________________________________________
//
//Strings
//_________________________________________________________________________________________________________________________

/* basAsc: returns ascii value of first char in string */
void basAsc()
{
    char    *string;
    string = popString();
//    pushNumber( (unsigned char)string[0] );
    pushNumber( asc(string));
    eFree( string );
}
//_______________________________________________________________________________________________________________________

/* basChr: return string corresponding to ascii key value */
void basChr()
{
    char    *buffer = (char *)eMalloc(sizeof(char)*2);
    buffer[0] = (char)popNumber();
    buffer[1] = '\0';
    pushString( buffer );
}
//_______________________________________________________________________________________________________________________

/* basFormat: returns formatted string with embedded args */
void basFormat()
{
    notYet("Format");
    pushNumber(0);
}
//_______________________________________________________________________________________________________________________

/* basInsert: insert source string to target at index */
void basInsert()
{
    char    *source, *target;
    //*,dest;
    int     i;

    i = (int)popNumber();
    target = popString();
    source = popString();

	//dest = (char *) eMalloc(strlen(source)+strlen(target)+1);

	//strcpy(dest,"");
	//strncpy(dest,source,i);
	//strcpy(&dest[i],target);
	//strcat(dest,source+i);
	//pushStringCopy(dest);

	pushString((char *)insert(source,target,i));
    //eFree(dest);
    eFree(source);
    eFree(target);
}
//_______________________________________________________________________________________________________________________

/* basInstr: returns position in source that target was found */
void basInstr()
{
    //int searchLen, findLen, i;
    int     start;
    char    *find, *search;

    find = popString();
    search = popString();
    if (argCount==3) {
        start = (int)popNumber()-1;
        if (start < 0) {
            start = 0;
        }

    } else {
        start = 0;
    }

    //searchLen = strlen( search );
    //findLen = strlen( find );

    /* searching for empty string? */
    //if (searchLen == 0 || findLen == 0) {
    //    pushNumber( 0 );
    //    return;
    //}

    //start = (int)floor( start );
    //for ( i = start; i < searchLen; i++ ) {
    //    if (strncmp( search+i, find, findLen ) == 0) {
    //        pushNumber( i+1 );
    //        return;
    //    }
    //}

    /* not found */
    //pushNumber( 0 );

    pushNumber(instr(start,find, search));

    /* ivanixcu: fix memleak */
    eFree(find);
    eFree(search);
}
//_______________________________________________________________________________________________________________________

/* basLCase: convert string to lower case */
void basLCase()
{
    //int     len, i;
    char    *string;

    string = popString();
    pushString(lcase(string));

    //len = strlen( string );
    //for ( i = 0; i<len; i++){
    //    string[i] = (char)tolower( (int)string[i] );
    //}
    //pushStringCopy( string );
    //eFree(string);
}
//_______________________________________________________________________________________________________________________

/* basLeft: returns leftmost chars in string */
void basLeft()
{
    //int len, newLen;
    //char    *left;

    int     pos;
    char    *string;


    pos = (int)popNumber();
    string = popString();

    pushString(left(string,pos));

    /*
    len = strlen(string);
    if (pos > len-1) {
        pushStringCopy( string );
	eFree(string);
        return;
    }

    if (pos < 1) {
        eFree( string );
        pushStringCopy( "" );
        return;
    }

    newLen = (pos);
    left = (char *) eMalloc(newLen+1);
    for (pos=newLen;pos>0;pos--)left[pos]='\0';
    //memcpy(left,string,newLen);
    strncpy(left,string,newLen);
    left[newLen] = '\0';
    eFree( string );
    pushStringCopy( left );
    eFree(left);
    */
}
//_______________________________________________________________________________________________________________________

/* basLen: return length of string */
void basLen()
{
    char    *string;
    string = popString();
    pushNumber(len(string));
    /*
    pushNumber( strlen( string ) );
    eFree( string );
    */
}
//_______________________________________________________________________________________________________________________

/* basLTrim: returns string with left whitespace removed */
void basLTrim()
{
    //char    *trimmed;
    char    *string;

    string = popString();
    pushString(ltrim(string));

    /*
    trimmed = string;
    while ( trimmed[0] != '\0' ) {
        if (!isspace(trimmed[0])) {
            break;
        }
        trimmed++;
    }
    pushStringCopy( trimmed );
    eFree( string );
    */
}
//_______________________________________________________________________________________________________________________

/* basMid: returns string with chars 1..n from source */
void basMid()
{
    //int j,len;
    //char    *buffer;

    int     i,n;
    char    *string;

    n=0;
    /* get args */
    if (argCount==3)
	n = (int)popNumber();

    i = (int)popNumber();
    string = popString();

    if (argCount!=3)
	n=strlen(string)+1-i;

    pushString(mid(string, i, n));

    /* early outs
    len = strlen( string ) - i;
    if ( i < 1 || len < 0 ) {
        pushStringCopy("");
	eFree( string );
        return;
    }

    buffer = (char *)eMalloc(len+2);
    for ( j = 0; j < n; j++ ) {
        if (string[i+j-1] == '\0' ) {
            break;
        }
        buffer[j] = string[i+j-1];
    }
    buffer[j] = '\0';
    pushStringCopy( buffer );
    eFree( string );
    */
}
//_______________________________________________________________________________________________________________________

/* basReplace: replace string from source with replace starting at index */
void basReplace()
{
    //int     a;
    //char    *dest;

    int     i;
    char    *src, *rep;

    rep = popString();
    src = popString();
    if (argCount == 3)
	i = (int)popNumber();
    else
	i = 0;

    pushString(replace(src, rep, i));

    /*
    dest=eCopyString(src);
    for(a=0;a<strlen(rep);a++){
	if ((a+i)>=strlen(dest))break;
	dest[i+a]=rep[a];
    }


    pushString(dest);
    eFree(rep);
    eFree(src);
    */
}
//_______________________________________________________________________________________________________________________

/* basReplaceSubStr: replace substring in source with withstring */
void basReplaceSubStr()
{
    //unsigned int i;
    //char    *dest;
    int start;
    char *source, *replace, *with;

    with = popString();
    replace = popString();
    source = popString();
    if (argCount==4)
	start=popNumber();
    else
	start=0;

    pushString(replacesubstr(start, source, replace, with));

    /*
    i=0;
    while (i<strlen(source)){
		if (strncmp(source+i,replace,strlen(replace))==0){
			dest = (char *) eMalloc( strlen(source)+ strlen(with)+1 );
			strcpy(dest,"");
			strncpy(dest,source,i);
			dest[i] = '\0';
			strcat(dest,with);
			strcat(dest,source+i+strlen(replace));
			eFree(source);
			source = (char *) eMalloc(strlen(dest)+1);
			strcpy(source,dest);
			eFree(dest);
			i+=strlen(with);
		}
		i++;
	}
    eFree( with );
    eFree( replace );
    pushStringCopy(source);
    eFree( source );
    */
}
//_______________________________________________________________________________________________________________________

/* basReverse: reverse a string */
void basReverse()
{
    //int     len, i, j;
    //char    *buffer;
    char    *string;

    string = popString();
    pushString(reverse(string));

    /*
    len = strlen( string );

    buffer = (char *)eMalloc(len+1);
    j = len-1;
    for( i = 0; i < len; i++ ) {
        buffer[j--] = string[i];
    }
    buffer[len] = '\0';

    pushString(buffer);
    eFree( string );
    */
}
//_______________________________________________________________________________________________________________________

/* basRight: returns rightmost chars in string */
void basRight()
{
    //int     len, newLen;
    //char    *right;

    int     pos;
    char    *string;

    pos = (int)popNumber();
    string = popString();
    pushString(right(string,pos));

    /*
    len = strlen(string);

    if (pos >= len) {
        pushStringCopy( string );
	eFree( string );
        return;
    }

    if (pos < 1) {
        eFree( string );
        pushStringCopy( "" );
        return;
    }

    newLen = pos+1;
    right = (char *)eMalloc((newLen+1));
    memcpy(right,string+(len-pos),newLen);
    right[newLen]=0;
    pushStringCopy( right );

    eFree( right );
    eFree( string );
    */
}
//_______________________________________________________________________________________________________________________

/* basRInstr: reverse Instr function, search from end to start */
void basRInstr()
{
    //int     searchLen, findLen, i;

    int     start;
    char    *find, *search;

    find = popString();
    search = popString();

    /* optional starting position */
    if (argCount==3) {
        start = (int)popNumber()-1;
        //if (start > searchLen ) {
        //    start = searchLen-1;
        //}
    } else {
	start=-1;
        //start = searchLen-1;
    }

    pushNumber(rinstr( search, find, start));

    /*
    findLen = strlen( find );
    searchLen = strlen( search );


    // searching for empty string?
    if (searchLen == 0 || findLen == 0) {
        pushNumber( 0 );
        return;
    }


    // search
    for ( i = start; i >= 0; i-- ) {
        if (strncmp( search+i, find, findLen ) == 0) {
            pushNumber( i+1 );
            return;
        }
    }

    // not found
    pushNumber( 0 );
   */
}
//_______________________________________________________________________________________________________________________

/* basRTrim: right trim string */
void basRTrim()
{
    //int     len, i;

    char    *string;
    string = popString();
    pushString(rtrim(string));

    /*
    len = strlen(string);
    for ( i = len-1; i > -1; i-- ) {
        if (!isspace(string[i])) {
            string[i+1] = '\0';
            pushString( string );
            return;
        }
    }
    string[0] = '\0';
    pushString( string );
    */
}
//_______________________________________________________________________________________________________________________

/* basSpace: return string with n spaces in it */
void basSpace()
{
    //char    *string;
    int     n;
    n = (int)popNumber();
    pushString(space(n));

    /*
    if (n<0) {
        n = 0;
    }

    string = (char *)eMalloc((unsigned int)n+1);
    memset(string,' ',n);
    string[n] = '\0';
    pushString(string);
    */
}
//_______________________________________________________________________________________________________________________

/* basStr: return string representation of numeric expression */
void basStr()
{
    char    *string;
    string = popString();
    pushStringCopy( string );
    eFree(string);
}
//_______________________________________________________________________________________________________________________

/* basStrF: converts a floating point or number value to a string */
void basStrF()
{
    char    *string;
    string = popString();
    pushStringCopy( string );
    eFree(string);
}
//_______________________________________________________________________________________________________________________

/* basString: returns string m chars wide with n in it */
void basString()
{
    //int     l,i;
    //char    *buffer;

    int     n;
    char    *_string;

    _string = popString();
    n = (int)popNumber();
    pushString(string( n, _string));

    /*
    l=strlen(string)+1;

    buffer = (char *)eMalloc((l*n)+1);
    strcpy(buffer,"");
    for (i=0;i<n;i++)
	strcat(buffer,string);
    buffer[(l*n)] = '\0';
    pushStringCopy( buffer );
    eFree (buffer);
    */
}
//_______________________________________________________________________________________________________________________

/* basTally:  returns number of occurances of matchstring */
void basTally()
{
    //int	    i,ret;
    int     start;
    char    *src, *sub;

    /* get the args */
    sub = popString();
    src = popString();

    /* optional start */
    if (argCount==3) {
        start = popNumber();
	}
    else {
	start = 0;
    }
    pushNumber(tally( src, sub, start));

    /*
    ret=0;
    for(i=start;i<strlen(src);i++)
        if (strncmp(src+i,sub,strlen(sub))==0)
            ret++;

	eFree(src);
	eFree(sub);
    pushNumber(ret);
    */
}
//_______________________________________________________________________________________________________________________

/* basTrim: returns string with left and right whitespace removed */
void basTrim()
{
    //  int     len, i;
    //  char *trimmed;

      char    *string;

    string = popString();
    pushString(trim( string));

    /*
    len = strlen(string);
    for ( i = len-1; i > -1; i-- ) {
        if (!isspace(string[i])) {
            string[i+1] = '\0';
            //pushString( string );
            break;
        }
    }

    if (i==0)
	    string[0] = '\0';

    trimmed=string;
    while ( trimmed[0] != '\0' ) {
        if (!isspace(trimmed[0])) {
            break;
        }
        trimmed++;
    }

    pushStringCopy( trimmed );
    eFree( string );
    */
}
//_______________________________________________________________________________________________________________________

/* basTypeOf:  returns string with datatype */
void basTypeOf()
{
    int         datatype;
    Variant     *v;
    v = getStackPointer( tos );
    datatype = v->datatype;
    dropTos();
    switch(datatype) {
    case DATA_NUMBER:
        pushStringCopy( "number" );
        break;

    case DATA_STRING:
        pushStringCopy( "string" );
        break;

    case DATA_OBJECT:
        pushStringCopy( "object" );
        break;

    default:
        pushStringCopy( "unknown" );
        break;
    }
}
//_______________________________________________________________________________________________________________________

/* basUCase: convert string to upper case */
void basUCase()
{
    //int     len, i;
    char    *string;

    string = popString();
    pushString(ucase(string));

    /*
    len = strlen( string );
    for ( i = 0; i<len; i++){
        string[i] = toupper( string[i] );
    }
    pushString( string );
    */
}
//_______________________________________________________________________________________________________________________

/* basVal: returns closest numeric representation of number */
void basVal()
{
    char    *string;
    string = popString();
    pushNumber( val(string) );
    eFree( string );
}
//_______________________________________________________________________________________________________________________
//
//Maths
//_________________________________________________________________________________________________________________________

/* basAbs: returns absolute value of number */
void basAbs()
{
    Number  n;
    n = popNumber();
    if (n < 0) {
        pushNumber( -n );
    } else {
        pushNumber( n );
    }
}
//_______________________________________________________________________________________________________________________

/* basACos: returns arccos of number */
void basACos()
{
    pushNumber( acos( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basASin: returns arcsin of number */
void basASin()
{
    pushNumber( asin( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basATan: returns arctan of number */
void basATan()
{
    pushNumber( atan( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basBin: returns binary representation of number */
void basBin()
{
    int i,l;
    char    *buffer ,*ret;

    buffer = (char *)eMalloc(1024);
    i = (int)popNumber();
    strcpy(buffer,"");

    if (i==0)strcat(buffer,"0");

    while(i>0){
	if ((i%2)==0)
	    strcat(buffer,"0");
	else
	    strcat(buffer,"1");
	i=i /2;
    }
    l=strlen(buffer);

    ret = (char *)eMalloc(l+1);
    for (i=0;i<l;i++)
	ret[i]=buffer[l-i-1];
    ret[l]='\0';
    eFree(buffer);
    pushString( ret );
}
//_______________________________________________________________________________________________________________________

/* basCos: returns cos of number */
void basCos()
{
    pushNumber( cos( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basExp: returns exponential function */
void basExp()
{
    pushNumber( exp( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basFix: truncate fractional number, rounding down towards zero */
void basFix()
{
    pushNumber( floor( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basFrac: return fractional portion of number */
void basFrac()
{
    Number  n;
    n = popNumber();
    n -= floor(n);
    pushNumber(n);
}
//_______________________________________________________________________________________________________________________

/* basHex: returns hexidecimal representation of number */
void basHex()
{
    int i;
    char    *buffer = (char *)eMalloc(16);
    i = (int)popNumber();
    sprintf( buffer, "%x", i);
    pushString( buffer );
}
//_______________________________________________________________________________________________________________________

/* basInt: convert to 32 bit integer, truncating decimals */
void basInt()
{
    pushNumber( (int)popNumber() );
}
//_______________________________________________________________________________________________________________________

/* basLog: returns natural log of expression */
void basLog()
{
    pushNumber( log( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basRandomize: reseed the random number generator */
void basRandomize()
{
    int seed;
    if (argCount==1) {
        seed = (int)popNumber();
    } else {
        seed = time(NULL);
    }
    srand( seed );
    pushNumber(0);
}
//_______________________________________________________________________________________________________________________

/* basRnd: return an random number */
void basRnd()
{
    int upper, result;

    result = rand();
    if (argCount==1) {
        upper = (int)popNumber();
        result = (result % (upper-1))+1;
    }
    pushNumber( (Number)result );
}
//_______________________________________________________________________________________________________________________

/* basRound: round to nearest integer */
void basRound()
{
    Number n1, n2;
    n1 = popNumber();
    n2 = floor(n1);
    if (n2 == 0) {
        /* leave it alone */

    } else if (n2 > 0) {
        if ((n1 - n2) > 0.5) {
            n2++;
        }
    } else {
        if (-(n2 - n1) > 0.5) {
            n2++;
        }
    }
    pushNumber( n2 );
}
//_______________________________________________________________________________________________________________________

/* basSgn: returns sign of numeric expression */
void basSgn()
{
    Number  n;
    n = popNumber();
    if (n < 0) {
        pushNumber(-1);
    } else if (n > 0) {
        pushNumber(1);
    } else {
        pushNumber(0);
    }
}
//_______________________________________________________________________________________________________________________

/* basSin: returns sine of given angle in radians */
void basSin()
{
    pushNumber( sin( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basSqr: return square root - make sure it's non-negative */
void basSqr()
{
    pushNumber( sqrt( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basTan: return tanget of given angle in radians */
void basTan()
{
    pushNumber( tan( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basMin: return min number of the operands */
void basMin()
{
    double a,b;
    a=popNumber();
    b=popNumber();
    if (b<a)a=b;
    pushNumber(a);
}
//_______________________________________________________________________________________________________________________

/* basMax: return max number of the operands */
void basMax()
{
    double a,b;
    a=popNumber();
    b=popNumber();
    if (b>a)a=b;
    pushNumber(a);
}
//_______________________________________________________________________________________________________________________

/* basBitwiseAnd: return the logic and of the operands */
void basBitwiseAnd()
{
        int a,b;
    a=popNumber();
    b=popNumber();
    pushNumber(a & b);
}
//_______________________________________________________________________________________________________________________

/* basBitwiseOr: return the logic or of the operands */
void basBitwiseOr()
{
        int a,b;
    a=popNumber();
    b=popNumber();
    pushNumber(a | b);
}
//_______________________________________________________________________________________________________________________

/* basBitwiseXor: return the logic xor of the operands */
void basBitwiseXor()
{
    int a,b;
    a=popNumber();
    b=popNumber();
    pushNumber(a ^ b);
}
//_______________________________________________________________________________________________________________________
//
//Files
//_________________________________________________________________________________________________________________________

/* basEof: returns nonzero if Eof */
void basEof()
{
    pushNumber( (Number)fileEof( (int)popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basFileExists: returns true if the file exists */
void basFileExists()
{
    char    *fname;

    fname = popString();
    pushNumber(FileExists(fname));
    eFree(fname);
}
//_______________________________________________________________________________________________________________________

/* basFileCopy : copy a file */
void basFileCopy()
{
    char *source;
    char *dest;
    int ret;

    dest=popString();
    source=popString();
    ret=filecopy(source,dest);
    if (ret==-1){
	error_description="file copy error";
	error_type=1;
	ePrintf( Runtime, "file Error \n");
    }
    eFree( dest );
    eFree( source );
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

/* basFileMove:move a file */
void basFileMove()
{
    char *source;
    char *dest;
    int ret;

    dest=popString();
    source=popString();
    ret=filemove(source,dest);
    if (ret==-1){
	error_description="file move error";
	error_type=1;
	ePrintf( Runtime, "file Error \n");
    }
    eFree( dest );
    eFree( source );
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

/* basFileRename: move a file */
void basFileRename()
{
    char *source;
    char *dest;
    int ret;

    dest=popString();
    source=popString();
    ret=filerename(source,dest);
    if (ret==-1){
	error_description="file rename error";
	error_type=1;
	ePrintf( Runtime, "file Error \n");
    }
    eFree( dest );
    eFree( source );
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

/* basFreeFile: return the handle of the next free file */
void basFreeFile()
{
    pushNumber(fileFree());
}
//_______________________________________________________________________________________________________________________

/* basKill: delete filename */
void basKill()
{
    char    *name = popString();
    remove( name );
    eFree(name);
    pushNumber(0);
}
//_______________________________________________________________________________________________________________________

/* basLoc: returns position in file */
void basLoc()
{
    pushNumber( filePosition( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basLof: returns length of file */
void basLof()
{
    pushNumber( fileSize( popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basReadByte: return a byte from the file */
void basReadByte()
{
    pushNumber( (Number)fileReadByte( (char)popNumber() ) );
}
//_______________________________________________________________________________________________________________________

/* basSeek: seek file position/return current file position */
void basSeek()
{
    int     file, pos;

    /* which version? */
    if (argCount==2) {
        /* seek to position */
        pos = popNumber();
        file = popNumber();
        pushNumber( fileSeek( file, pos ));

    } else {
        /* return position in file */
        file = popNumber();
        pushNumber( filePosition( file ) );
    }
}
//_______________________________________________________________________________________________________________________


/* basWriteByte: return a byte from the file */
void basWriteByte()
{
    char    c;
    int     fileNum;

    c = popNumber();
    fileNum = popNumber();
    fileWriteByte( fileNum, c );
    pushNumber( 0 );
}

//_______________________________________________________________________________________________________________________
//
//Dirs
//_________________________________________________________________________________________________________________________

/* basChDir: change directory */
void basChDir()
{
    char    *name;
    name = popString();
    pushNumber(chdir(name));
     eFree(name);
}
//_______________________________________________________________________________________________________________________

/* basDir: returns current path */
void basDir()
{
	pushStringCopy(dir());
}
//_______________________________________________________________________________________________________________________

/* basDirExists: returns true if directory exists */
void basDirExists()
{
	char *path;
	path=popString();
	pushNumber(direxists(path));
	eFree(path);
}
//_______________________________________________________________________________________________________________________

/* basDirFirst: returns first entry in path dir */
void basDirFirst()
{
	char *path;
	path = popString();
	pushStringCopy(dirfirst(path));
	eFree(path);
}
//_______________________________________________________________________________________________________________________

/* basDirNext: returns next entry in  path dir */
void basDirNext()
{
	pushStringCopy(dirnext());
}
//_______________________________________________________________________________________________________________________

/* basMkDir: create a new directory */
#if !defined(WIN32) & !defined(__amigaos4__)
    int mkdir(char *name); //used for forcing the warning
    //int chmod(char *name,int p); //used for forcing the warning //deniska
#endif

void basMkDir()
{
    char    *name;
    name = popString();
#ifdef __amigaos4__
    pushNumber(mkdir(name,0777));
#else
   mkdir(name);
#ifndef WIN32
    //chmod(name,0777);
#endif
    pushNumber(0);
#endif
}
//_______________________________________________________________________________________________________________________

/* basRmDir: remove directory */
void basRmDir()
{
    char    *name;
    name = popString();
    pushNumber(rmdir(name));
    eFree(name);
}
//_______________________________________________________________________________________________________________________

//Data function support
//_________________________________________________________________________________________________________________________

/* basData: load in array the data */
void basData()
{
    int i;
    char *datavalue[255];

    for( i=argCount-1;i>=0;i--){
	datavalue[i]=popString();
    }

    for( i=0;i<argCount;i++){
	loaddata(datavalue[i]);
	/* ivanixcu: fix memleak */
        eFree(datavalue[i]);
    }


    pushNumber(argCount);
}
//_______________________________________________________________________________________________________________________

/* basRead: return the data stored */
void basRead()
{
    if (argCount==1){
	datapointer=popNumber();
	if (datapointer>dataenter)datapointer=-1;
	if (datapointer<0){
	    error_description="read data error";
	    error_type=1;
	    ePrintf( Runtime, "%d it's out of range\n", datapointer );
	}
	pushNumber(datapointer);
    }
    else{
	if (datapointer>=dataenter){
	    error_description="read data error";
	    error_type=1;
	    ePrintf( Runtime, "%d it's out of range\n", datapointer );
}
	pushString(readdata());
    }
}
//_______________________________________________________________________________________________________________________

//Date and time
//_________________________________________________________________________________________________________________________

/* basDate: returns date in MM-DD-YYYY format */
void basDate()
{
    time_t      t;
    struct tm   *tmp;
    char        *buffer = (char *)eMalloc(11);

    /* get time */
    t = time(NULL);
    tmp = localtime(&t);

    sprintf( buffer, "%02d-%02d-%04d",
        tmp->tm_mon+1, tmp->tm_mday, tmp->tm_year+1900 );

    pushString( buffer );
}
//_______________________________________________________________________________________________________________________

/* basTicks: returns current timer value */
void basTicks()
{
#ifdef UNIX
    //fixed using mandel demo
    pushNumber( clock()/826 );
#else
    pushNumber( clock() );
#endif
}
//_______________________________________________________________________________________________________________________

/* basTime: return time in HH:MM:SS format */
void basTime()
{
    time_t      t;
    struct tm   *tmp;
    char        *buffer = (char *)eMalloc(9);

    /* get time */
    t = time(NULL);
    tmp = localtime(&t);

    sprintf( buffer, "%02d:%02d:%02d",
        tmp->tm_hour, tmp->tm_min, tmp->tm_sec );

    pushString( buffer );
}
//_______________________________________________________________________________________________________________________

//_______________________________________________________________________________________________________________________

//Memory Bank
//_________________________________________________________________________________________________________________________

//reservebank(bank,size)			: make a raw memory bank. there are 256 bank ( 0 - 255)
void basReserveBank()
{
    int bank;
    long size;
    int ret;

    size=popNumber();
    bank=popNumber();

    ret=reservebank(bank,size);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}
//_________________________________________________________________________________________________________________________

//baseimage(bank,image)			: link a  memory bank with image bitmap
void basBaseImage()
{
    int bank;
    int image;
    int ret;

    image=popNumber();
    bank=popNumber();

    ret=baseimage(bank,image);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//baseimageCC(bank,image)			: link a  memory bank with image bitmap
void basBaseImageCC()
{
    int bank;
    int imageCC;
    int ret;

    imageCC=popNumber();
    bank=popNumber();

    ret=baseimageCC(bank,imageCC);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//basescreen(bank,image)			: link a  memory bank with image bitmap
void basBaseScreen()
{
    int bank;
    int screen;
    int ret;

    screen=popNumber();
    bank=popNumber();

    ret=basescreen(bank,screen);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//basesound(bank,sound)			: link a  memory bank with soundb bank
void basBaseSound()
{
    int bank;
    int sound;
    int ret;

    sound=popNumber();
    bank=popNumber();

    ret=basesound(bank,sound);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//freebase(bank)				: disconnect a base from bank
void basFreeBase()
{
    int bank;
    int ret;

    bank=popNumber();

    ret=freebase(bank);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}

//_______________________________________________________________________________________________________________________

//freebank(bank)				: destroy a memory bank
void basFreeBank()
{
    int bank;
    int ret;

    bank=popNumber();

    ret=freebank(bank);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}

//_______________________________________________________________________________________________________________________

//copybank(s,d)				: copy the banco s in d
void basCopyBank()
{
    int s,d;
    int ret;

    d=popNumber();
    s=popNumber();

    ret=copybank(s,d);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);

}

//_______________________________________________________________________________________________________________________

//loadbank(filename,optional bank)	: load a file in memory bank (if omitted the current )
void basLoadBank()
{
	char	*filename;
	int bank;

	int ret;

    if (argCount==2)
	bank = popNumber();
    else
	bank=-1;

    filename=popString();
    ret =loadbank(filename,bank);
	eFree(filename);
    if (ret==-1) ePrintf( Runtime, "%s not found Error\n", filename );
    pushNumber(ret);

}

//_______________________________________________________________________________________________________________________

//savebank(filename,optional bank)	: save memory bank in a file
void basSaveBank()
{
	char	*filename;
	int bank;

	int ret;

    if (argCount==2)
	bank = popNumber();
    else
	bank=-1;

    filename=popString();
    ret =savebank(filename,bank);
	eFree(filename);
    if (ret==-1) ePrintf( Runtime, "%s not found Error\n", filename );
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//setbank(optional bank)			: set the current bank
void basSetBank()
{
    int bank;
    int ret;

    if (argCount==1)
	bank=popNumber();
    else
	bank=-1;

    ret=setbank(bank);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//sizebank(optional bank)			: return the bank memory size
void basSizeBank()
{
    int bank;
    int ret;

    if (argCount==1)
	bank=popNumber();
    else
	bank=-1;

    ret=sizebank(bank);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//poke(optional bank,address,value)	: write a byte value in memory bank at specific address
void basPoke()
{
    int bank;
    long address;
    unsigned char value;
    int ret;


    value=popNumber();
    address=popNumber();

    if (argCount==3)
	bank = popNumber();
    else
	bank=-1;

    ret=poke(bank,address,value);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}

//_______________________________________________________________________________________________________________________

//doke(optional bank,address,value)       : write a 16bit value in memory bank at specific address
void basDoke()
{
    int bank;
    long address;
    unsigned short value;
    int ret;


    value=popNumber();
    address=popNumber();

    if (argCount==3)
	bank = popNumber();
    else
	bank=-1;

    ret=doke(bank,address,value);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}

//_______________________________________________________________________________________________________________________

//loke(optional bank,address,value)	: write a 32bit value in memory bank at specific address
void basLoke()
{
    int bank;
    long address;
    unsigned int value;
    int ret;


    value=popNumber();
    address=popNumber();

    if (argCount==3)
	bank = popNumber();
    else
	bank=-1;

    ret=loke(bank,address,value);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}

//_______________________________________________________________________________________________________________________

//peek(optional bank,address)		: read a byte value in memory bank at specific address
void basPeek()
{
    int bank;
    long address;
    int ret;


    address=popNumber();
    if (argCount==2)
	bank = popNumber();
    else
	bank=-1;

    ret=peek(bank,address);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}

//_______________________________________________________________________________________________________________________

//deek(optional bank,address)		: read a 16bit value in memory bank at specific address
void basDeek()
{
    int bank;
    long address;
    int ret;


    address=popNumber();
    if (argCount==2)
	bank = popNumber();
    else
	bank=-1;

    ret=deek(bank,address);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//leek(optional bank,address)		: read a 32bit value in memory bank at specific address
void basLeek()
{
    int bank;
    long address;
    int ret;


    address=popNumber();
    if (argCount==2)
	bank = popNumber();
    else
	bank=-1;

    ret=leek(bank,address);
    if (ret==-1) ePrintf( Runtime, "membank Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//memcopy(sbank,s,dbank,d,size)		: copy a part of bank memory s in d
void basMemCopy()
{
    int sbank,s,dbank,d,size;
    int ret;

    size=popNumber();
    d=popNumber();
    dbank=popNumber();
    s=popNumber();
    sbank=popNumber();

    ret=memcopy(sbank,s,dbank,d,size);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}

//_______________________________________________________________________________________________________________________
//
//------- SDLengine-link ------------------------------------------------------------------------------------------
//_______________________________________________________________________________________________________________________

//_________________________________________________________________________________________________________________________
//
//Screen
//_________________________________________________________________________________________________________________________

//setdefaults(w,h,bpp,m): : open the display, perform initializations on cursor and fonts and sets default values on sprites, bobs and screens system.
void basSetDefaults()
{
    int width,height,bpp,mode;
    int ret;

    mode = popNumber();
    bpp = popNumber();
    height = popNumber();
    width = popNumber();

    ret=setdefaults( width,height,bpp,mode);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//setdisplay(w,h,bpp,m): open the screen/window in double buffer. 0=screen|1=window|2=resizable
void basSetDisplay()
{
    int width,height,bpp,mode;
    int ret;

    mode = popNumber();
    bpp = popNumber();
    height = popNumber();
    width = popNumber();

    ret=setdisplay( width,height,bpp,mode);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________
//setalphachannel(v): activate deactivate alpha channel trasparency
void basSetAlphaChannel()
{
    int ret;
    int v;
    v=popNumber();
    ret=setalphachannel(v);
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//setcaption: change the display window title
void basSetCaption()
{
    int ret;
    char *title;

    title=popString();
    ret=setcaption(title);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
    eFree(title);
}
//_______________________________________________________________________________________________________________________

//caption: return the current display window title
void basCaption()
{
    char *title;
    caption(&title);
    pushString(title);
}
//_______________________________________________________________________________________________________________________

//displaymode: give the display mode
void basDisplayMode()
{
    pushNumber( displaymode() );
}
//_______________________________________________________________________________________________________________________

//displaywidth: give the display width
void basDisplayWidth()
{
    pushNumber( displaywidth() );
}
//_______________________________________________________________________________________________________________________

//displayheight: give the display height
void basDisplayHeight()
{
    pushNumber( displayheight() );
}
//_______________________________________________________________________________________________________________________

//displaybpp: give the display color depth
void basDisplayBpp()
{
    pushNumber( displaybpp() );
}
//_______________________________________________________________________________________________________________________

//screen(n): attivated the logic screen n
void basScreen()
{
    int n;
    int ret;
    if (argCount!=0)
	    n = popNumber();
    else
	    n=-1;
    if (n>7)ePrintf( Runtime, "SDLengine  Error:you can use 0 to 7 screen !!! \n");
    ret=screen(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//screenz(n,z)				: set the zorder position of screen if z =-1 report actual z position
void basScreenZ()
{
    int n,z;
    int ret;
    if (argCount!=1)
	    z = popNumber();
    else
	    z=-1;
    n = popNumber();

    if (n>7)ePrintf( Runtime, "SDLengine  Error:you can use 0 to 7 screen !!! \n");
    ret=screenz(n,z);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//lastscreen: return the last screen open
void basLastScreen()
{
    int ret;
    ret=lastscreen();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//directscreen: direct drawing on display like a screen(more fast but sprite and offset does not works)
void basDirectScreen()
{
    int ret;
    ret=directscreen();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//screenopen(n,w,h,dx,dy,dw,dh,flag): open the logic screen n of dimension w,h in display coordinates dx,dy,dw,dh
void basScreenOpen()
{
    int n,w,h,dx,dy,dw,dh,flag;
    int ret;

    flag = popNumber();
    dh = popNumber();
    dw = popNumber();
    dy = popNumber();
    dx = popNumber();
     h = popNumber();
     w = popNumber();
     n = popNumber();

    if (n>7)ePrintf( Runtime, "SDLengine  Error:you can use 0 to 7 screen !!! \n");
    ret=screenopen(n,w,h,dx,dy,dw,dh,flag);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//screenclose(n): close the logic screen n
void basScreenClose()
{
    int n;
    int ret;

    n = popNumber();

    ret=screenclose(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//screenclone(n,s,x,y,w,h,flag): create a  new viewport in logic screen s
void basScreenClone()
{
    int ret;
    int n,s,x,y,w,h,flag;

    flag = popNumber();
    h = popNumber();
    w = popNumber();
    y = popNumber();
    x = popNumber();
    s = popNumber();
    n = popNumber();

    if (n>7)ePrintf( Runtime, "SDLengine Error:you can use 0 to 7 screen !!! \n");
    ret=screenclone(n,s,x,y,w,h,flag);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//screencopy(n,x,y,w,h,nd,xd,yd): copy a portion of screen n in a screen nd
void basScreenCopy()
{
    int n,x,y,w,h,nd,xd,yd;
    int ret;

    yd = popNumber();
    xd = popNumber();
    nd = popNumber();
    h = popNumber();
    w = popNumber();
    y = popNumber();
    x = popNumber();
    n = popNumber();

    if (n>7 || n<0)ePrintf( Runtime, "SDLengine Error: Error:you can use 0 to 7 screen !!! \n");
    if (nd>7 || nd<0)ePrintf( Runtime, "SDLengine Error: Error:you can use 0 to 7 screen !!! \n");
    ret=screencopy(n,x,y,w,h,nd,xd,yd);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//screenfade(n,t): fade the screen n in t time
void basScreenFade()
{
    int n,t;
    int ret;

    if (argCount==2)
	t = popNumber();
    else
	t=-1;

    n = popNumber();

    ret=screenfade(n,t);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//screenfadein(n,i,t): fade the screen n to image i in t time
void basScreenFadein()
{
    int n,i,t;
    int ret;

    if (argCount ==3){
	t = popNumber();
	i = popNumber();
    }else{
	t=-1;
	i=-1;
    }
    n = popNumber();

    ret=screenfadein(n,i,t);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//screencrossfade(n,i,t): fade the screen n from current screen  to image i in t time
void basScreenCrossFade()
{
    int n,i,t;
    int ret;

    if (argCount ==3){
	t = popNumber();
	i = popNumber();
    }else{
	t=-1;
	i=-1;
    }
    n = popNumber();

    ret=screencrossfade(n,i,t);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//screenalpha(n,a): set alpha(trasparency) of screen n
void basScreenAlpha()
{
	int ret;
	int n,a;
    a = popNumber();
    n = popNumber();
    ret=screenalpha(n,a);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//screenlock(n): lock the  screen n for direct graphics access
void basScreenLock()
{
	int ret;
	int n;
     n = popNumber();
    ret=screenlock(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//screenunlock(n): unlock the  screen n for direct graphics access
void basScreenUnlock()
{
	int ret;
	int n;
     n = popNumber();
    ret=screenunlock(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//screenrect(x,y,w,h,flag): change the display output coordinates of the current screen
void basScreenRect()
{
    int x,y,w,h,flag;

    flag = popNumber();
    h = popNumber();
    w = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber(screenrect(x,y,w,h,flag));
}
//_______________________________________________________________________________________________________________________

//xscreenrect: give the x coordinate of current screen viewport
void basXScreenRect()
{
    pushNumber( xscreenrect() );
}
//_______________________________________________________________________________________________________________________

//yscreenrect: give the y coordinate of current screen viewport
void basYScreenRect()
{
    pushNumber( yscreenrect() );
}
//_______________________________________________________________________________________________________________________

//wscreenrect: give the w value of current screen viewport
void basWScreenRect()
{
    pushNumber( wscreenrect() );
}
//_______________________________________________________________________________________________________________________

//hscreenrect: give the h value of current screen viewport
void basHScreenRect()
{
    pushNumber( hscreenrect() );
}
//_______________________________________________________________________________________________________________________

//flagscreenrect: give the flag value of current screen viewport
void basFlagScreenRect()
{
    pushNumber( flagscreenrect() );
}
//_______________________________________________________________________________________________________________________

//screenwidth: give the current screen width
void basScreenWidth()
{
    pushNumber( screenwidth() );
}
//_______________________________________________________________________________________________________________________

//screenheight: give the current screen height
void basScreenHeight()
{
    pushNumber( screenheight() );
}
//_______________________________________________________________________________________________________________________

//offset(x,y): set the logical current screen position
void basOffset()
{
    int xoff,yoff;

    yoff = popNumber();
    xoff = popNumber();
    offset(xoff,yoff);

    pushNumber( 0 );
}
//_______________________________________________________________________________________________________________________

//xoffset: give the x coordinate offset in current screen
void basXOffset()
{
    pushNumber( xoffset() );
}
//_______________________________________________________________________________________________________________________

//yoffset: give the y coordinate offset in current screen
void basYOffset()
{
    pushNumber( yoffset() );
}
//_______________________________________________________________________________________________________________________

//cls: clear the current logic screen
void basCls()
{
    pushNumber( cls() );
}
//_______________________________________________________________________________________________________________________

//screenswap: update display,bobsystem,spritesystem
void basScreenSwap()
{
    int ret;
    ret= screenswap();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//autoback setautoback(m): enable / disable automatic screenswap  m=0 disable m>0 wait m milliseconds and perform screenswap m<0 perform the invocate in code screenswap after m milliseconds
void basAutoBack()
{
    int m;
    if (argCount==1)
	    m=popNumber();
    else
	    m=-1;
    pushNumber(autoback(m));
}
//_______________________________________________________________________________________________________________________

//dualplayfield(m): set/unset automatic update of a screen upper sprite
void basDualPlayfield()
{
    int m;
	if (argCount==1)
		m=popNumber();
	else
		m=-1;

    pushNumber(dualplayfield(m));
}
//_______________________________________________________________________________________________________________________

//waitvbl: wait automatic screenswap
void basWaitVbl()
{
	int ret;

    ret= waitvbl();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//fps(n): set/unset or give the current frame rate counter
void basFps()
{
    int n;
	if (argCount==1)
		n=popNumber();
	else
		n=-1;

    pushNumber(fps(n));
}
//_______________________________________________________________________________________________________________________

//_________________________________________________________________________________________________________________________
//
//Graphics
//_________________________________________________________________________________________________________________________

//rgb(r,g,b): give current color in Uint32 format
void basRgb()
{
	int r,g,b;
    b = popNumber();
    g = popNumber();
    r = popNumber();

    pushNumber( rgb(r,g,b) );
}
//_______________________________________________________________________________________________________________________

//enablepalette(optional state=0|1 disable|enable|check)   			: enable disable and check the palettemode in 8 bit display
void basEnablePalette()
{
    int s;
    int ret;
    if (argCount==1)
	s=popNumber();
    else
	s=-1;
    ret=enablepalette(s);
    if (ret==-1) ePrintf( Runtime, "enablepalette Error\n");
    pushNumber(ret );

}

//_______________________________________________________________________________________________________________________

//color (c,optional v): set  palette color c with value v se missing give the current color c
void basColor()
{
	int c,v;
	int ret;
    if (argCount==2)
	v=popNumber();
    else
	v=-1;
    c=popNumber();

    ret=color(c,v);

    if (ret==-1) ePrintf( Runtime, "%s color Error\n", c );
    pushNumber(ret );
}
//_______________________________________________________________________________________________________________________

//palette(optional 0-255 param): set all palettes color
void basPalette()
{
	int i,v;
	int ret;
    ret=-1;
    for (i=0;i<argCount;i++){
	v=popNumber();
	ret=color(argCount-i-1,v);
	if (ret==-1)break;
    }
    pushNumber(ret );
}
//_______________________________________________________________________________________________________________________

//colorcycling(s,e,d=0|1)			: move the palettecolor one color forward or back work only in 8bit display
void basColorCycling()
{
    int s,e,d,delay;
    int ret;

    switch(argCount){
	case 4:
	    delay=popNumber();
	    d=popNumber();
	    e=popNumber();
	    s=popNumber();
	    break;

	case 3:
	    delay=0;
	    d=popNumber();
	    e=popNumber();
	    s=popNumber();
	    break;

	default:
	    delay=0;
	    d=0;
	    e=0;
	    s=-1;
	    break;
    }
    ret=colorcycling(s,e,d,delay);
    pushNumber(ret );
}
//_______________________________________________________________________________________________________________________

//ink(c): select the current color in Uint32 format
void basInk()
{
	int c;
    if (argCount==1)
	c=popNumber();
    else
	    c=-1;
    pushNumber( ink(c) );
}
//_______________________________________________________________________________________________________________________

//point(x,y)				: give the color of x,y point
void basPoint()
{
	int x,y;
    y = popNumber();
    x = popNumber();

    pushNumber( point(x,y) );
}
//_______________________________________________________________________________________________________________________

//dot(x,y): write x,y point with a current color
void basDot()
{
	int x,y;
    y = popNumber();
    x = popNumber();

    pushNumber( dot(x,y) );
}
//_______________________________________________________________________________________________________________________

//plot(x,y,c): write x,y point with a c color
void basPlot()
{
	int x,y,c;
    c = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( dot_ex(x,y,c) );
}
//_______________________________________________________________________________________________________________________

//line(x,y,x1,y1): write a line
void basLine()
{
	int x,y,x1,y1;
    y1 = popNumber();
    x1 = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( line(x,y,x1,y1) );
}
//_______________________________________________________________________________________________________________________

//box(x,y,x1,y1): write a empty rettangle
void basBox()
{
	int x,y,x1,y1;
    y1 = popNumber();
    x1 = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( box(x,y,x1,y1) );
}
//_______________________________________________________________________________________________________________________

//bar(x,y,x1,y1): write a fill rettangle
void basBar()
{
	int x,y,x1,y1;
    y1 = popNumber();
    x1 = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( bar(x,y,x1,y1) );
}
//_______________________________________________________________________________________________________________________

//rectangle(x,y,w,h,mode)			: write a rettangle w and h are the sizes mode=0 empty 1=filled
void basRectangle()
{
	int x,y,x1,y1,mode;
    if
	(argCount==4)mode=0;
    else
	mode = popNumber();
    y1 = popNumber();
    x1 = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( rectangle(x,y,x1,y1,mode) );
}

//_______________________________________________________________________________________________________________________

//circle(x,y,r): write a circle
void basCircle()
{
	int x,y,r;
    r = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( circle(x,y,r) );
}
//_______________________________________________________________________________________________________________________

//fillcircle(x,y,r): write a fill circle
void basFillCircle()
{
	int x,y,r;
    r = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( fillcircle(x,y,r) );
}
//_______________________________________________________________________________________________________________________

//ellipse(x,y,rx,ry): write a ellipse
void basEllipse()
{
	int x,y,rx,ry;
    ry = popNumber();
    rx= popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( ellipse(x,y,rx,ry) );
}
//_______________________________________________________________________________________________________________________

//fillellipse(x,y,rx,ry): write a fill ellipse
void basFillEllipse()
{
	int x,y,rx,ry;
    ry = popNumber();
    rx = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( fillellipse(x,y,rx,ry) );
}
//_______________________________________________________________________________________________________________________

//paint(x,y): fill a close area
void basPaint()
{
	int x,y;
    y = popNumber();
    x = popNumber();

    pushNumber(paint(x,y) );
}
//_______________________________________________________________________________________________________________________

//triangle(x1,y1,x2,y2,x3,y3): draw a fill triangle
void basTriangle()
{
	int x1,y1,x2,y2,x3,y3;
    y3 = popNumber();
    x3 = popNumber();
    y2 = popNumber();
    x2 = popNumber();
    y1 = popNumber();
    x1 = popNumber();

    pushNumber( triangle(x1,y1,x2,y2,x3,y3));
}
//_______________________________________________________________________________________________________________________
//polyline(x,y,x1,y1,x2,y2,.....): make a perimeter of a polygon
void basPolyLine()
{
    int i,x,y,xfirst,yfirst,xold,yold,count;

    count=argCount;
    yold = popNumber();
    xold = popNumber();
    xfirst=xold;
    yfirst=yold;

    for(i=0;i<(count/2)-1;i++){
	y = popNumber();
	x = popNumber();
	line(xold,yold,x,y);
	yold=y;
	xold=x;
    }
    line(xold,yold,xfirst,yfirst);

    pushNumber(0);
}
//_______________________________________________________________________________________________________________________

//polygon(x,y,x1,y1,x2,y2,.....): make a fill polygon
void basPolyGon()
{
    int i,xa,ya,xb,yb,xfirst,yfirst,count;
    count=argCount;

    ya = popNumber();
    xa = popNumber();
    yfirst=ya;
    xfirst=xa;
    for(i=0;i<(count/2)-1;i++){
	yb = popNumber();
	xb = popNumber();
	triangle(xfirst,yfirst,xa,ya,xb,yb);
	xa=xb;
	ya=yb;
    }

    pushNumber(0);
}

//_______________________________________________________________________________________________________________________
//
//graphics input output
//_________________________________________________________________________________________________________________________

//loadimage(filename,optional n): load a graphics file in a slot n return n
void basLoadImage()
{
	char	*filename;
	int n;
	int ret;

	if (argCount==1)
		n=-1;
	else
		n = popNumber();

    filename=popString();
    ret =loadimage(filename,n);
	eFree(filename);
    if (ret==-1) ePrintf( Runtime, "%s not found Error\n", filename );
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//loadzipimage(zipfile,filename,optional n): load a graphics file in a slot n return n
void basLoadZipImage()
{
	char	*zipfile;
	char	*filename;
	int n;
	int ret;

	if (argCount==2)
		n=-1;
	else
		n = popNumber();

    filename=popString();
    zipfile=popString();

    ret =loadzipimage(zipfile,filename,n);


    if (ret==-1) ePrintf( Runtime, "%s not found Error\n", filename );
    pushNumber(ret);

    eFree(filename);
    eFree(zipfile);

}
//_______________________________________________________________________________________________________________________

//saveimage(filename,n): save slot n in a graphics file(only bmp)
void basSaveImage()
{
	char	*filename;
	int n;

	int ret;

    n = popNumber();
    filename=popString();

    ret= saveimage(filename,n);
	eFree(filename);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//loadsound(filename,n): load a wave file in a sound slot n
void basLoadSound()
{
	char	*filename;
	int n;
	int ret;

    if (argCount==1)
	n=-1;
    else
	n = popNumber();

    filename=popString();

    ret=loadsound(filename,n);
	eFree(filename);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//loadzipsound(zipfile,filename,n): load a zipped wave file in a sound slot n
void basLoadZipSound()
{
	char	*zipfile;
	char	*filename;
	int n;
	int ret;

    if (argCount==2)
	n=-1;
    else
	n = popNumber();

    filename=popString();
    zipfile=popString();

    ret=loadzipsound(zipfile,filename,n);
	eFree(filename);
	eFree(zipfile);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//savesound(filename,n): save a wave file from a sound slot n
void basSaveSound()
{
	char	*filename;
	int n;

	int ret;

    n = popNumber();
    filename=popString();

    ret=savesound(filename,n);
	eFree(filename);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//loadmusic(filename): load a music module (xm,mod,ogg and only for linux mp3)
void basLoadMusic()
{
	char	*filename;

	int ret;
    filename=popString();

    ret=loadmusic(filename);
	eFree(filename);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);


}
//_______________________________________________________________________________________________________________________

//loadzipmusic(zipfile,filename): load a zipped music module (xm,mod,ogg and only for linux mp3)

void basLoadZipMusic()
{
	char	*zipfile;
	char	*filename;

	int ret;
    filename=popString();
    zipfile=popString();

    ret=loadzipmusic(zipfile,filename);
	eFree(filename);
	eFree(zipfile);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);


}

//_______________________________________________________________________________________________________________________
//
// Image manipulation
//_________________________________________________________________________________________________________________________

//hotspot(n,x,y): select the point of coordinates in a imageslot (n,0,0=up left(default) | n,1,1=center | n,2,2 =down right)n= image
void basHotSpot()
{
	int n,x,y;
	int ret;

    y=popNumber();
    x=popNumber();
    n=popNumber();


    ret=hotspot(n,x,y);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//setcolorkey(c): set the colorkey for bitmap transparency default=0
void basSetColorKey()
{
	int ret;
	int c;
    c = popNumber();
    ret=setcolorkey(c);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//imageexists(n): give 1 if the image buffer n exist 0 if empty
void basImageExists()
{
	int n;
	int ret;
    n = popNumber();
    ret=imageexists(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//imagewidth(n): give the image n width or error if image n if empty
void basImageWidth()
{
	int n;
	int ret;
    n = popNumber();
    ret=imagewidth(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//imageheight(n): give the image n height or error if image n if empty
void basImageHeight()
{
	int n;
	int ret;
    n = popNumber();
    ret=imageheight(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//deleteimage(n): erase the image n of the memory
void basDeleteImage()
{
	int ret;
	int n;
    n = popNumber();
    ret=deleteimage(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//copyimage(s,d): copy image s to image d
void basCopyImage()
{
	int ret;
	int s,d;
    d = popNumber();
    s = popNumber();
    ret=copyimage(s,d);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//setalpha(n,a): set trasparency
void basSetAlpha()
{
	int ret;
	int n,a;
    a = popNumber();
    n = popNumber();
    ret=setalpha(n,a);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//zoomimage(n,zoomx,zoomy): zoom image
void basZoomImage()
{
	int ret;
	int n;
	double zoomx,zoomy;
    zoomy = popNumber();
    zoomx = popNumber();
    n = popNumber();
    ret=zoomimage(n,zoomx,zoomy);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//rotateimage(n,angle): rotate image
void basRotateImage()
{
	int ret;
	int n;
	double angle;

    angle = popNumber();
    n = popNumber();
    ret=rotateimage(n,angle);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//rotozoomimage(n,angle,zoom): rotate and zoom image
void basRotozoomImage()
{
	int ret;
	int n;
	double angle,zoom;

    zoom = popNumber();
    angle = popNumber();
    n = popNumber();
    ret=rotozoomimage(n,angle,zoom);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//mirrorimage(n,x,y): vertical-orizontal mirror
void basMirrorImage()
{
	int ret;
	int n;
	int x,y;

    y = popNumber();
    x = popNumber();
    n = popNumber();
    ret=mirrorimage(n,x,y);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________
//
// Blitting
//_________________________________________________________________________________________________________________________

//blt(n,sx,sy,sw,sh,dx,dy): copy a part of graphics slot in screen
void basBlt()
{
    int n,sx,sy,sw,sh,dx,dy;
    int ret;

    dy = popNumber();
    dx = popNumber();
    sh = popNumber();
    sw = popNumber();
    sy = popNumber();
    sx = popNumber();
    n = popNumber();

    ret=blt(n,sx,sy,sw,sh,dx,dy);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//pastebob(x,y,n): copy on screen image n at x,y performing clip
void basPasteBob()
{
	int x,y,n;
        int ret;

    n = popNumber();
    y = popNumber();
    x = popNumber();

    ret=pastebob(x,y,n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//pasteicon(x,y,n): copy on screen image n at x,y without clipping
void basPasteIcon()
{
	int x,y,n;
	int ret;

    n = popNumber();
    y = popNumber();
    x = popNumber();

    ret= pasteicon(x,y,n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//grab(n,x,y,w,h): grab a a selectarea and copy it in slot n
void basGrab()
{
	int n,x,y,w,h;
	int ret;

    h = popNumber();
    w = popNumber();
    y = popNumber();
    x = popNumber();
    n = popNumber();

    ret=grab(n,x,y,w,h);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________
//
// Sprite system
//_______________________________________________________________________________________________________________________

//spriteclip(x,y,w,h): set the visibilty area of sprites
void basSpriteClip()
{
	int x,y,w,h;

    h = popNumber();
    w = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( spriteclip(x,y,w,h) );
}
//_______________________________________________________________________________________________________________________

//sprite(n,x,y,fr): set or move the sprite n at x,y with image fr
void basSprite()
{
	int n,x,y,fr;
	int ret;

    fr = popNumber();
    y = popNumber();
    x = popNumber();
    n = popNumber();

    ret=sprite(n,x,y,fr);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//deletesprite(n): unset sprite n
void basDeleteSprite()
{
	int n;

    n = popNumber();

    pushNumber( deletesprite(n) );
}
//_______________________________________________________________________________________________________________________

//xsprite(n): give the x of sprite n
void basXSprite()
{
	int n;

    n = popNumber();

    pushNumber( xsprite(n) );
}
//_______________________________________________________________________________________________________________________

//ysprite(n): give the y of sprite n
void basYSprite()
{
	int n;

    n = popNumber();

    pushNumber( ysprite(n) );
}
//_______________________________________________________________________________________________________________________

//spritewidth(n): give the width of sprite n
void basSpriteWidth()
{
	int n;

    n = popNumber();

    pushNumber( spritewidth(n) );
}
//_______________________________________________________________________________________________________________________

//spriteheight(n): give the height of sprite n
void basSpriteHeight()
{
	int n;

    n = popNumber();

    pushNumber( spriteheight(n) );
}
//_______________________________________________________________________________________________________________________

//frsprite(n): give the frame of sprite n
void basFrSprite()
{
	int n;

    n = popNumber();

    pushNumber( frsprite(n) );
}
//_______________________________________________________________________________________________________________________

//livesprite(n): give 1 if sprite n is "live"
void basLiveSprite()
{
	int n;

    n = popNumber();

    pushNumber( livesprite(n) );
}
//_______________________________________________________________________________________________________________________

//spritehit(n,optional x): give 1 if sprite n have a collission with sprite x if x=-1 with any
void basSpriteHit()
{
	int n,x;
	int ret;

	if (argCount==1)
		x=-1;
	else
		x = popNumber();
    n = popNumber();

	ret=spritehit(n,x);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret  );
}
//_______________________________________________________________________________________________________________________

// spritez(n,z): set the zorder position of sprite if z =-1 report actual z position
void basSpriteZ()
{
	int n,z;
	int ret;

	if (argCount==1)
		z=-1;
	else
		z = popNumber();
    n = popNumber();

	ret=spritez(n,z);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret  );
}
//_______________________________________________________________________________________________________________________

//lastsprite: return the last sprite active
void basLastSprite()
{
    int ret;
    ret=lastsprite();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//autoupdatesprite(m): set/ unset automatic sprites update at screenswap
void basAutoUpdateSprite()
{
	int m;

    m = popNumber();

    pushNumber( autoupdatesprite(m) );
}
//_______________________________________________________________________________________________________________________

//updatesprite				: manual sprites updates at next screenswap
void basUpdateSprite()
{

    pushNumber( updatesprite() );
}
//_______________________________________________________________________________________________________________________
//
// Bob system
//_________________________________________________________________________________________________________________________

//setbob(n,scr): set bob n at logic screen scr
void basSetBob()
{
	int n,scr;

    scr = popNumber();
    n = popNumber();

    pushNumber( setbob(n,scr) );
}
//_______________________________________________________________________________________________________________________

//bob(n,x,y,fr): set or move bob n at x,y with frame fr
void basBob()
{
	int n,x,y,fr;
	int ret;

    fr = popNumber();
    y = popNumber();
    x = popNumber();
    n = popNumber();

    ret=bob(n,x,y,fr);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//deletebob(n): unset bob n
void basDeleteBob()
{
	int n;

    n = popNumber();

    pushNumber( deletebob(n) );
}
//_______________________________________________________________________________________________________________________

//xbob(n): give x of bob n
void basXBob()
{
	int n;

    n = popNumber();

    pushNumber( xbob(n) );
}
//_______________________________________________________________________________________________________________________

//ybob(n): give y of bob n
void basYBob()
{
	int n;

    n = popNumber();

    pushNumber( ybob(n) );
}
//_______________________________________________________________________________________________________________________

//bobwidth(n): give width of bob n
void basBobWidth()
{
	int n;

    n = popNumber();

    pushNumber( bobwidth(n) );
}
//_______________________________________________________________________________________________________________________

//bobheight(n): give height of bob n
void basBobHeight()
{
	int n;

    n = popNumber();

    pushNumber( bobheight(n) );
}
//_______________________________________________________________________________________________________________________

//frbob(n): give the frame of bob n
void basFrBob()
{
	int n;

    n = popNumber();

    pushNumber( frbob(n) );
}
//_______________________________________________________________________________________________________________________

//livebob(n): give 1 if bob n is "live"
void basLiveBob()
{
	int n;

    n = popNumber();

    pushNumber( livebob(n) );
}
//_______________________________________________________________________________________________________________________

//bobhit(n,optional x): give 1 if bob n have a collision with bob x if x=-1 with any
void basBobHit()
{
	int n,x;
	int ret;

	if (argCount==1)
		x=-1;
	else
		x = popNumber();
    n = popNumber();

	ret=bobhit(n,x);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret  );

}
//_______________________________________________________________________________________________________________________

// bobz(n,z): set the zorder position of bob if z =-1 report actual z position
void basBobZ()
{
	int n,z;
	int ret;

	if (argCount==1)
		z=-1;
	else
		z = popNumber();
    n = popNumber();

	ret=bobz(n,z);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret  );
}
//_______________________________________________________________________________________________________________________

//lastbob: return the last bob active
void basLastBob()
{
    int ret;
    ret=lastbob();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//autoupdatebob(m): set/ unset automatic bobs update at screenswap
void basAutoUpdateBob()
{
	int m;

    m = popNumber();

    pushNumber( autoupdatebob(m) );
}
//_______________________________________________________________________________________________________________________

//updatebob: manual bobs updates at next screenswap
void basUpdateBob()
{

    pushNumber( updatebob() );
}

//_______________________________________________________________________________________________________________________
//
// Text draw
//_________________________________________________________________________________________________________________________

//text(x,y,s,testo): print the text testo  on current screen with s size
void basText()
{
	char	*txt;
	int x,y,s,o;
	int ret;

    if (argCount==5)
	o=popNumber();
    else
	o=0;

    txt=popString();
    s = popNumber();
    y = popNumber();
    x = popNumber();

    ret=text(x,y,s,txt,o);
	eFree(txt);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//setfont(path): select the font
void basSetFont()
{
	char	*path;
	int ret;

    path=popString();

    ret=setfont(path);
	//eFree(path);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//getfont()	: get the font selected
void basGetFont()
{
    pushString(getfont());
}
//_______________________________________________________________________________________________________________________

//textrender(testo,s,n): make an image slot n with the text  write with a current font and size s
void basTextRender()
{
	char	*txt;
	int s,n,o;

	int ret;

	n=-1;
	o=0;

    if (argCount==4){
	o=popNumber();
	n = popNumber();
    }
    if (argCount==3)
	n = popNumber();


    s = popNumber();
    txt=popString();

    ret=textrender(txt,s,n,o);
	eFree(txt);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________
//
// Print screen
//_________________________________________________________________________________________________________________________

//pen(c)					: set prints color (without parameter give the current color)
void basPen()
{

	int c;
	int ret;

    if (argCount==1)
		c = popNumber();
	else c=-1;

    ret=pen(c);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//paper(c): set caractere back color (without parameter give the current color)
void basPaper()
{

	int c;
	int ret;

    if (argCount==1)
		c = popNumber();
	else c=-1;

    ret=paper(c);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//fprints(testo): print a text monospace without cariage return
void basfPrints()
{
	int ret;
	char *txt;

    txt = popString();
	ret=fprints(txt);
	eFree(txt);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//prints(testo): print a text monospace
void basPrints()
{

	int ret;
	char *txt;

    txt = popString();
	ret=prints(txt);
	eFree(txt);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//locate(x,y): move the cursor at x y
void basLocate()
{

	int x,y;

    y = popNumber();
    x = popNumber();

    pushNumber(locate(x,y) );

}
//_______________________________________________________________________________________________________________________

//atx: give x of cursor
void basAtx()
{
    pushNumber(atx());
}
//_______________________________________________________________________________________________________________________

//aty: give y of cursor
void basAty()
{
    pushNumber(aty());
}
//_______________________________________________________________________________________________________________________

//curson: show the text cursor on screen at(atx,aty)
void basCursOn()
{
    pushNumber(curson());
}
//_______________________________________________________________________________________________________________________

//cursoff: hide the text cursor
void basCursOff()
{
    pushNumber(cursoff());
}
//_______________________________________________________________________________________________________________________

//inputs(prompt,defs): give the string insert to keyboard(default is default text)
void basInputs()
{
	char *txt;
	char *request;
	char defs[255];
	txt=popString();
	strcpy(defs,txt);
	request=popString();
	inputs(request,defs);
	pushStringCopy(defs);
	eFree(txt);


}
//_______________________________________________________________________________________________________________________

//zoneinputs(x,y,l,default): give the string insert to keyboard in  x,y coordinates with l lenght
void basZoneInputs()
{
	char *txt;
	int l,y,x;

	char defs[255];
	txt=popString();
	strcpy(defs,txt);
	l=popNumber();
	y=popNumber();
	x=popNumber();
	zoneinputs(x,y,l,defs);
	/* ivanixcu: should push copy of string */
        pushStringCopy(defs);
}
//_______________________________________________________________________________________________________________________
//
// Sounds and music
//_______________________________________________________________________________________________________________________

//isenabledsound()			: return 1 if sdlsound was enabled
void basIsEnabledSound()
{
    pushNumber( isenabledsound());
}
//_______________________________________________________________________________________________________________________

//soundexists(n): give 1 if the sound buffer n exist 0 if empty
void basSoundExists()
{
	int n;
    n = popNumber();
    pushNumber( soundexists(n) );

}
//_______________________________________________________________________________________________________________________

//deletesound(n): delete the sound bank from memory
void basDeleteSound()
{
	int n;
	int ret;
    n = popNumber();
    ret=deletesound(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//copysound(s,d): copy the sound bank s in d bank
void basCopySound()
{
	int s,d;
	int ret;
    d = popNumber();
    s = popNumber();
    ret=copysound(s,d);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//musicexists(): give 1 if the music is load 0 if empty
void basMusicExists()
{
    pushNumber( musicexists() );
}
//_________________________________________________________________________________________________________________________

//playsound(n,c,optional l): play the sound n in  channel c l loops
void basPlaySound()
{
	int n,c,l;
	int ret;
    if (argCount==3)
	l=popNumber();
    else
	l=0;
    c = popNumber();
    n = popNumber();

    ret=playsound(n,c,l);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//playfreqsound(n,c,rate,optional l): play the sound n in  channel c at freq rate l loops
void basPlayFreqSound()
{
	int n,c,l;
	float rate;
	int ret;
    if (argCount==4)
	l=popNumber();
    else
	l=0;

    rate = popNumber();
    c = popNumber();
    n = popNumber();

    ret=playfreqsound(n,c,rate,l);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//volumesound(c,optional v): change the volume of channel c (-1  all) at value v (0-128) without v or -1 give the current volume
void basVolumeSound()
{
	int ret;
	int c,v;

    if (argCount==2)
	    v = popNumber();
    else
	    v=-1;

    c = popNumber();

    ret=volumesound(c,v);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//stopsound(optional c): stop the  wave play in channel c (-1 or none =all)
void basStopSound()
{
    int c;
    if (argCount==1)
	    c=popNumber();
    else
	    c=-1;
    pushNumber( stopsound(c));
}
//_______________________________________________________________________________________________________________________

//pausesound(optional c): paused channel c (-1 or none =all)
void basPauseSound()
{
    int c;
    if (argCount==1)
	    c=popNumber();
    else
	    c=-1;
    pushNumber( pausesound(c));
}
//_______________________________________________________________________________________________________________________

//resumesound(optional c): unpaused channel c (-1 or none =all)
void basResumeSound()
{
    int c;
    if (argCount==1)
	    c=popNumber();
    else
	    c=-1;
    pushNumber( resumesound(c));
}
//_______________________________________________________________________________________________________________________

//vumetersound(optional c): give the current state of sound channel (-1 or none=all)
void basVuMeterSound()
{
    int c;
    if (argCount==1)
	    c=popNumber();
    else
	    c=-1;
    pushNumber( vumetersound(c));
}
//_______________________________________________________________________________________________________________________

//positionsound(c,angle,dist): position sound in 3d space
void basPositionSound()
{
    int c,angle,dist;

    dist=popNumber();
    angle=popNumber();
    c=popNumber();

    pushNumber( positionsound(c,angle,dist));
}
//_______________________________________________________________________________________________________________________

//soundchannels(n): dinamically change the number of channells managed by sdlBasic
void basSoundChannels()
{
    int n;

    n=popNumber();
    pushNumber( soundchannels(n));
}
//_______________________________________________________________________________________________________________________

//playmusic(n): play track xm,mod,ogg,mp3 n=number of ripetition(-1 always)
void basPlayMusic()
{
	int n;
	int ret;

    n = popNumber();

    ret=playmusic(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//positionmusic(p): move the execution at p second
void basPositionMusic()
{
	int p;
	int ret;

    p = popNumber();

    ret=positionmusic(p);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//stopmusic: terminate the music play
void basStopMusic()
{
    pushNumber( stopmusic() );
}
//_______________________________________________________________________________________________________________________

//pausemusic: set pause of the current music
void basPauseMusic(void)
{
    pushNumber( pausemusic() );
}
//_______________________________________________________________________________________________________________________

//resumemusic: unset pause of musica
void basResumeMusic(void)
{
    pushNumber( resumemusic() );
}
//_______________________________________________________________________________________________________________________

//rewindmusic: report at start the music
void basRewindMusic(void)
{
    pushNumber( rewindmusic() );
}
//_______________________________________________________________________________________________________________________

//fademusic(t): music fade
void basFadeMusic()
{
    int t;
    int ret;

    if(argCount==1)
	t = popNumber();
    else
	t=-1;

    ret=fademusic(t);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//volumemusic(optional v): change the volume of music (0-128) -1 or none give the current volume
void basVolumeMusic()
{
    int v;
    int ret;
    if (argCount==1)
	    v = popNumber();
    else
	    v=-1;

    ret=volumemusic(v);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//speedmusic(v): change the speed of music
void basSpeedMusic()
{
	int v;
	    v = popNumber();
    pushNumber( speedmusic(v));

}
//_______________________________________________________________________________________________________________________

// CD support
//_________________________________________________________________________________________________________________________

//numdrivescd() 				: returns the number of cd-rom drives on the system.
void basNumDrivesCD()
{
    int ret;
    ret=numdrivescd();

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//namecd(drive)				: returns a human-readable, system-dependent identifier for the cd-rom.
void basNameCD()
{
    int drive;
    int ret;

    char name[255];
    strcpy(name,"      ");
    drive=popNumber();
    ret=namecd(name,drive);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushString(name);

}
//_______________________________________________________________________________________________________________________

//opencd(n,drive)				: opens a cd-rom drive for access.
void basOpenCD()
{
    int n,drive;
    int ret;

    drive=popNumber();

    if (argCount==2)
	n=popNumber();
    else
	n=-1;

    ret=opencd(n,drive);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}
//_______________________________________________________________________________________________________________________

//indrivecd(n)				: return 1 if cd is in driver
void basInDriveCD()
{
    int n;
    int ret;

    n=popNumber();

    ret=indrivecd(n);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//trackscd(n) 				: return the number of tracks in cd
void basTracksCD()
{
    int n;
    int ret;

    n=popNumber();

    ret=trackscd(n);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//curtrackcd(n)				: return the current track in cd
void basCurTrackCD()
{
    int n;
    int ret;

    n=popNumber();

    ret=curtrackcd(n);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//curframecd(n)				: return the current frame in cd
void basCurFrameCD()
{
    int n;
    int ret;

    n=popNumber();

    ret=curframecd(n);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//playcd(n,s,l) 				: play a cd
void basPlayCD()
{
    int n,s,l;
    int ret;

    if (argCount==3)
	l=popNumber();
    else
	l=0;

    if (argCount>=2)
	s=popNumber();
    else
	s=0;

    n=popNumber();

    ret=playcd(n,s,l);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//playtrackscd(n,trk1,fr1,ntrks,nfrs)	: play the given cd track(s)0=all
void basPlayTracksCD()
{
    int n,trk1,fr1,ntrks,nfrs;
    int ret;

    switch(argCount){
	case 5:
	    nfrs=popNumber();
	    ntrks=popNumber();
	    fr1=popNumber();
	    trk1=popNumber();
	    n=popNumber();
	    break;
	case 4:
	    ntrks=popNumber();
	    fr1=popNumber();nfrs=1;
	    trk1=popNumber();
	    n=popNumber();
	    break;
	case 3:
	    nfrs=0;
	    ntrks=popNumber();
	    fr1=0;
	    trk1=popNumber();
	    n=popNumber();
	    break;
	case 2:
	    nfrs=0;
	    fr1=0;
	    trk1=popNumber();ntrks=1;
	    n=popNumber();
	default:
	    nfrs=0;
	    ntrks=0;
	    fr1=0;
	    trk1=0;
	    n=popNumber();
	    break;
    }

    ret=playtrackscd(n,trk1,fr1,ntrks,nfrs);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//pausecd(n) 				: pauses a cdrom
void basPauseCD()
{
    int n;
    int ret;

    n=popNumber();

    ret=pausecd(n);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//resumecd(n) 				: resumes a cdrom
void basResumeCD()
{
    int n;
    int ret;

    n=popNumber();

    ret=resumecd(n);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//stopcd(n)				: stops a cdrom
void basStopCD()
{
    int n;
    int ret;

    n=popNumber();

    ret=stopcd(n);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//ejectcd(n) 				: ejects a cdrom
void basEjectCD()
{
    int n;
    int ret;

    n=popNumber();

    ret=ejectcd(n);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//closecd(n) 				: closes a cd handle
void basCloseCD()
{
    int n;
    int ret;

    n=popNumber();

    ret=closecd(n);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//tracktypecd(n,t)			: return SDL_AUDIO_TRACK(0...) or SDL_DATA_TRACK(1...)
void basTrackTypeCD()
{
    int n,t;
    int ret;

    t=popNumber();
    n=popNumber();

    ret=tracktypecd(n,t);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//tracklengthcd(n,t)			: return the length of track t
void basTrackLengthCD()
{
    int n,t;
    int ret;

    t=popNumber();
    n=popNumber();

    ret=tracklengthcd(n,t);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//trackoffsetcd(n,t)			: return the offset to the beginning of this track in frames
void basTrackOffsetCD()
{
    int n,t;
    int ret;

    t=popNumber();
    n=popNumber();

    ret=trackoffsetcd(n,t);

    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________
//
// Video mpeg
//_________________________________________________________________________________________________________________________

//loadmpeg(fname,usesound)		: load a mpeg video

void basLoadMpeg()
{
    char *fname;
    int usesound;
    int ret;

    usesound=popNumber();
    fname=popString();

    ret=loadmpeg(fname,usesound);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_________________________________________________________________________________________________________________________

//plaympeg(optional loop)		: play a mpeg1 video
void basPlayMpeg()
{
    int loop;
    int ret;

    if (argCount==1)
	loop=popNumber();
    else
	loop=0;

    ret=plaympeg(loop);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_________________________________________________________________________________________________________________________

//stopmpeg()				: terminate the video play
void basStopMpeg()
{
    int ret;
    ret=stopmpeg();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_________________________________________________________________________________________________________________________

//deletempeg()				: unload mpeg video
void basDeleteMpeg()
{
    int ret;
    ret=deletempeg();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_________________________________________________________________________________________________________________________

//pausempeg()				: Pause/Resume playback of an SMPEG object
void basPauseMpeg()
{
    int ret;
    ret=pausempeg();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_________________________________________________________________________________________________________________________

//rewindmpeg()				: Rewind the play position of an SMPEG object to the beginning of the MPEG
void basRewindMpeg()
{
    int ret;
    ret=rewindmpeg();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}

//_________________________________________________________________________________________________________________________

//seekmpeg(p)				: Seek 'bytes' bytes in the MPEG stream
void basSeekMpeg()
{
    int p;
    int ret;
    p=popNumber();
    ret=seekmpeg(p);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}

//_________________________________________________________________________________________________________________________

//skipmpeg(s)				: Skip 'seconds' seconds in the MPEG stream
void basSkipMpeg()
{
    double p;
    int ret;
    p=popNumber();
    ret=skipmpeg(p);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_________________________________________________________________________________________________________________________

//statusmpeg()				: return 1 if plaympeg work or 0 in other case
void basStatusMpeg()
{
    int ret;
    ret=statusmpeg();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}


//_______________________________________________________________________________________________________________________
//
// Keyboard
//_________________________________________________________________________________________________________________________

//key(keycode): give 1 if is press the key keycode
void basKey()
{
    int ret;
    int keycode;

    keycode = popNumber();
    ret=key(keycode);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber( ret );
}
//_______________________________________________________________________________________________________________________

//inkey: give ascii code of key press
void basInkey()
{
    pushNumber(inkey());
}
//_______________________________________________________________________________________________________________________

//waitkey(optional keycode): wait a key pression (0 =any key)
void basWaitKey()
{
    int keycode;

    if (argCount==1)
        keycode = popNumber();
    else
	keycode=0;
    pushNumber(waitkey(keycode));
}
//_______________________________________________________________________________________________________________________
//
// Mouse
//_________________________________________________________________________________________________________________________

//xmouse: give mouse x coordinate on display
void basXMouse()
{
    pushNumber( xmouse() );
}
//_______________________________________________________________________________________________________________________

//ymouse: give mouse y coordinate on display
void basYMouse()
{
    pushNumber( ymouse() );
}
//_______________________________________________________________________________________________________________________

//xmousescreen(n): give mouse x coordinate on screen
void basXMouseScreen()
{
    int n;
    n=popNumber();
    pushNumber( xmousescreen(n) );
}
//_______________________________________________________________________________________________________________________

//ymousescreen(n): give mouse y coordinate on screen
void basYMouseScreen()
{
    int n;
    n=popNumber();
    pushNumber( ymousescreen(n) );
}
//_______________________________________________________________________________________________________________________

//bmouse: give the buttonclick on the mouse
void basBMouse()
{
    pushNumber( bmouse() );
}
//_______________________________________________________________________________________________________________________

//changemouse(optional n): change mouse from default(0) to emulate with sprite 0 - image 0 (1,2,3)without n return current pointer
void basChangeMouse()
{
    int n;
    int ret;
    if (argCount==1)
	n=popNumber();
    else
	n=-1;

    ret=changemouse(n);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

// locatemouse: move cursor at xy coordinates
void basLocateMouse()
{
    int x,y;
    int ret;
    y=popNumber();
    x=popNumber();
    ret=locatemouse(x,y);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);

}

//_______________________________________________________________________________________________________________________

//mouseshow: show the mouse cursor
void basMouseShow()
{
    pushNumber( mouseshow() );
}
//_______________________________________________________________________________________________________________________

//mousehide: hide the mouse cursor
void basMouseHide()
{
    pushNumber( mousehide() );
}
//_______________________________________________________________________________________________________________________

//mousezone(x,y,w,h): give 1 if the mouse pointer is in rectangle(xy with size wh)
void basMouseZone()
{
    int x,y,w,h;


    h = popNumber();
    w = popNumber();
    y = popNumber();
    x = popNumber();

    pushNumber( mousezone(x,y,w,h) );

}
//_______________________________________________________________________________________________________________________
//
// Joystick
//_________________________________________________________________________________________________________________________

//numjoysticks: Count available joysticks.
void basNumJoySticks()
{
    int ret;
    ret=numjoysticks();
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//namejoystick(i): Get joystick name
void basNameJoyStick()
{
   char *ret;
    int i;

    i=popNumber();
    ret=namejoystick(i);
    if (ret==NULL) ePrintf( Runtime, "SDLengine Error \n");
    pushString(ret);
}
//_______________________________________________________________________________________________________________________

//numaxesjoystick(i): Get the number of joystick axes
void basNumAxesJoyStick(void)
{
   int ret;
    int i;

    i=popNumber();
    ret=numaxesjoystick(i);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//numballsjoystick(i): Get the number of joystick trackballs
void basNumBallsJoyStick(void)
{
   int ret;
    int i;

    i=popNumber();
    ret=numballsjoystick(i);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//numhatsjoystick(i): Get the number of joystick hats
void basNumHatsJoyStick(void)
{
   int ret;
    int i;

    i=popNumber();
    ret=numhatsjoystick(i);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//numbuttonsjoystick(i): Get the number of joysitck buttons
void basNumButtonsJoyStick(void)
{
   int ret;
    int i;

    i=popNumber();
    ret=numbuttonsjoystick(i);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//getaxisjoystick(i,a): Get the current state of an axis
void basGetAxisJoyStick(void)
{
   int ret;
    int a,i;

    a=popNumber();
    i=popNumber();
    ret=getaxisjoystick(i,a);
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//gethatjoystick(i,a): Get the current state of a joystick hat
void basGetHatJoyStick(void)
{
   int ret;
    int a,i;

    a=popNumber();
    i=popNumber();
    ret=gethatjoystick(i,a);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//getbuttonjoystick(i,a): Get the current state of a given button on a given joystick
void basGetButtonJoyStick(void)
{
   int ret;
    int a,i;

    a=popNumber();
    i=popNumber();
    ret=getbuttonjoystick(i,a);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//xgetballjoystick(i,a): Get relative trackball motion
void basXGetBallJoyStick(void)
{
   int ret;
    int a,i;

    a=popNumber();
    i=popNumber();
    ret=xgetballjoystick(i,a);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//ygetballjoystick(i,a): Get relative trackball motion
void basYGetBallJoyStick(void)
{
   int ret;
    int a,i;

    a=popNumber();
    i=popNumber();
    ret=ygetballjoystick(i,a);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//joy: give joystick boolean coordinate
void basJoy()
{
    int i,ret;
    i=popNumber();
    ret=joy(i);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//bjoy					: give joystick button pressed
void basBJoy()
{
    int i,ret;
    i=popNumber();
    ret=bjoy(i);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________

//waitbjoy					: wait joystick button pressed
void basWaitBJoy()
{
    int i,ret;
    if (argCount==1)
	i=popNumber();
    else
	i=0;
    ret=waitbjoy(i);
    if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
    pushNumber(ret);
}
//_______________________________________________________________________________________________________________________
//
// SDLtime
//_________________________________________________________________________________________________________________________

//wait(t): wait t milliseconds
void basWait()
{
	int t;
	int ret;

	t= popNumber();
	ret=waitTime(t);
	if (ret==-1) ePrintf( Runtime, "SDLengine Error \n");
	pushNumber( ret);
}
//_______________________________________________________________________________________________________________________

//timer: give the current tick
void basTimer()
{
	pushNumber( chrono());
}
//_______________________________________________________________________________________________________________________
//
// SOCKET
//_________________________________________________________________________________________________________________________

//isenabledsock()				: return 1 if sdlnet was enabled
void basIsEnabledSock()
{
/*
    int ret;
    ret=isenabledsock();
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
*/
}

//_______________________________________________________________________________________________________________________

//sock=getfreesock()			: return the first free sock in sdlSocket array
void basGetFreeSock()
{
/*
    int ret;
    ret=getfreesock();
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
*/
}
//_______________________________________________________________________________________________________________________

/*sock=OpenSock(port) 			: Server side socket sock is the stream. in sdlBasic there are 256 stream and \
					  sintax is very similar of file open close.*/
void basOpenSock()
{
/*
    int port;
    int ret;

    port= popNumber();
    ret=opensock(port);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
*/
}
//_______________________________________________________________________________________________________________________

//clientsock=AcceptSock(serversock)	: Accept the client connection
void basAcceptSock()
{
/*
    int serversock;
    int ret;

    serversock= popNumber();
    ret=acceptsock(serversock);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
*/
}

//_______________________________________________________________________________________________________________________

//IsServerReady(Sock)			: True/False if server is sending data    
void basIsServerReady()
{
/*
    int sock;
    int ret;

    sock= popNumber();
    ret=isserverready(sock);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
*/
}

//_______________________________________________________________________________________________________________________

//sock=ConnectSock(ServerName,port)	: client side socket connection
void basConnectSock()
{
/*
    int port;
    char *servername;
    int ret;

    port= popNumber();
    servername=popString();
    ret=connectsock(servername,port);
    //if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
*/
}

//_______________________________________________________________________________________________________________________

//*ConnectionReadySock(sock)		: the server have accepted the connection
/*
void ConnectionReadySock()
{
    int sock;
    int ret;

    sock= popNumber();
    ret=connectionready(sock);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
}
*/
//_______________________________________________________________________________________________________________________

//IsClientReady(Sock)			: True/False if client is sending data
void basIsClientReady()
{
/*
    int sock;
    int ret;

    sock= popNumber();
    ret=isclientready(sock);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
*/
}
//_______________________________________________________________________________________________________________________

//CloseSock(sock)				: Close the socket connection. Works for client and server
void basCloseSock()
{
/*
    int sock;
    int ret;

    sock= popNumber();
    ret=closesock(sock);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
*/
}

//_______________________________________________________________________________________________________________________

//*PeekSock(Sock, NumBytes)		: Peek information coming from socket, but do not clear.
/*
void basPeekSock(void)
{
    int sock,numbytes;

    char *ret;

    numbytes= popNumber();
    sock= popNumber();
    ret=peeksock(sock,numbytes);
    if (ret==NULL) ePrintf( Runtime, "SDLengine socket Error \n");
    pushString(ret);
}
*/
//_______________________________________________________________________________________________________________________

//ReadSock(Sock, NumBytes)		: Read NumBytes
void basReadSock()
{
/*
    int sock,numbytes;

    numbytes= popNumber();
    sock= popNumber();
    pushString(readsock(sock,numbytes));
*/
}

//_______________________________________________________________________________________________________________________

//ReadByteSock(Sock)			: Read a single byte      
void basReadByteSock()
{
/*
    int sock;
    int ret;

    sock= popNumber();
    ret=readbytesock(sock);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
*/
}
//_______________________________________________________________________________________________________________________

//ReadLineSock(Sock)			: Read complete line
void basReadLineSock()
{
/*
    int sock;

    sock= popNumber();
    pushString(readlinesock(sock));
*/
}
//_______________________________________________________________________________________________________________________

//WriteSock(Sock, Message, NumBytes)	: Sends NumBytes from Message
void basWriteSock()
{
/*
    int sock,numbytes;
    char *message;
    int ret;

    numbytes= popNumber();
    message=popString();
    sock= popNumber();
    ret=writesock(sock,message,numbytes);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber(ret);
*/
}
//_______________________________________________________________________________________________________________________

//WriteByteSock(Sock, Byte)		: Sends a single byte
void basWriteByteSock()
{
/*
    int sock;
    char byte;
    int ret;

    byte=popNumber();
    sock= popNumber();
    ret=writebytesock(sock,byte);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber(ret);
*/
}
//_______________________________________________________________________________________________________________________

//WriteLineSock(Sock, Message)		: Send Message
void basWriteLineSock()
{
/*
    int sock;
    char *message;
    int ret;

    message=popString();
    sock= popNumber();
    ret=writelinesock(sock,message);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber(ret);
*/
}
//_______________________________________________________________________________________________________________________

//getremoteip(sock)			: return the ip address of remote client connetted
void basGetRemoteIp()
{
/*
    int sock;

    sock= popNumber();
    pushString(getremoteip(sock));
*/
}
//_______________________________________________________________________________________________________________________

//getremoteport(sock)			: return the port address of remote client connetted
void basGetRemotePort()
{
/*
    int sock;
    int ret;

    sock= popNumber();
    ret=getremoteport(sock);
    if (ret==-1) ePrintf( Runtime, "SDLengine socket Error \n");
    pushNumber( ret);
*/
}

//_______________________________________________________________________________________________________________________

//getlocalip()				: return the local ip
void basGetLocalIp()
{
 //   pushString(getlocalip());
}

//_______________________________________________________________________________________________________________________

/*--- end ---------------------------------------------------------------*/

/* addBuiltin: add a builtin to the dictionary */
void addBuiltin( char *name, void (*routine)(void), int args, int optargs )
{
    Symbol  *s;
    s = findSymbol( name, NULL );
    if (s==NULL) {
        s = addSymbol( name, NULL, SYM_BUILTIN );
        s->builtin = routine;
        s->args = args;
        s->optargs = optargs;

    } else {
        ePrintf( Runtime, "builtin %s is already declared as a %s",
            s->name, symbolName[s->symboltype] );
    }

}

/* initBuiltins: install all the builtins */
void initBuiltins()
{
    int i;

    for (i = 0; builtin[i].name != NULL; i++) {
        addBuiltin( builtin[i].name,
                    builtin[i].routine,
                    builtin[i].args,
                    builtin[i].optargs );
    }
}

