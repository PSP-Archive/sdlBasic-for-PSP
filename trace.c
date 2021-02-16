/*
    Name:       trace.c
    Purpose:    Code tracing for wxBasic
    Author:     David Cuny
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

 sourceLineCounter = 0;  /* value of next SourceCode->id */
SourceCode  *lastSourceLink = NULL ;

/* add a line of source code to the linked list */
int eAddSourceCode( int theFileNum, int theLineNum, char *text )
{
    SourceCode  *link;

    /* fill in the link */
    link = (SourceCode *)eMalloc( sizeof( SourceCode ) );
    link->id = sourceLineCounter;
    link->fileNum = theFileNum;
    link->lineNum = theLineNum;
    link->text = eCopyString( text );
    link->prior = lastSourceLink;
    lastSourceLink = link;
    return sourceLineCounter++;
}

/* search source for line of text */
SourceCode *eFindSource( int id )
{
    SourceCode  *code;
    code = lastSourceLink;
    while (code != NULL) {
        if (code->id == id) {
            return code;
        }
        code = code->prior;
    }
    return NULL;
}

