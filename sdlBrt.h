/*
    Name:       sdlBasic.h
    Purpose:    Core (wxBasic) version for sdlBasic
    Author:     David Cuny - __vroby__ based on sdlBasic.c
    Copyright:  (c) 2001 David Cuny <dcuny@lanset.com>
    Licence:    LGPL
*/


#define PROGNAME    "sdlBasic runtime"
#define RELEASE     "20070714"
#define DATEOF      "14-Lug-2007"
#define COPYRIGHT   "(c) 2001 David Cuny and sdlBasic team"
#define LICENSE     "Lesser GNU Public License"
#define SDLBASIC    1

#ifdef AMIGA
#define Node ExecNode
#include <exec/nodes.h>
#undef Node
#endif

/*

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
#ifdef __amigaos4__
#include <sys/stat.h>
#endif

#if !defined(FBSD) && !defined(__amigaos4__) && !defined(__APPLE__)
#include <malloc.h>
#else
#include <stdlib.h>
#endif

#if defined(WIN32)
#include <windows.h>
#endif
*/

extern int yylex();
extern void yyerror( char* );
/*
#include "unzip/unzip.h"
#include "SDLengine/SDLengine.h"
#include "BASengine/BASengine.h" 	
//#include "GLengine/GLengine.h"


#include "shared.h"         		
#include "trace.h"         
#include "error.h"         
#include "stack.h"          
#include "data.h"           	
#include "symbol.h"         	
#include "var.h"            	
#include "array.h"          	
#include "node.h"           
//#include "BASengine/file.h"  	
//#include "BASengine/dir.h"		
//#include "BASengine/datafunction.h"
//#include "BASengine/membank.h"
#include "builtin.h"      

//#include "const.h"          
#include "eval.h"           
#include "keyword.h"       
#include "lexer.h"        
//#include "class.h" 
*/    
