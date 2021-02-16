/*
    Name:       node.c
    Purpose:    Parse tree data structure for wxBasic
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

Node *opNode( int op, Node *left, Node *right )
{
    Node    *node;

    node = (Node *) eMalloc( sizeof( Node ) );
    node->op = op;
    node->left = left;
    node->right = right;
    node->next = NULL;
    node->trace = -1;    
    return node;
}

Node *intNode( int op, int value, Node *left, Node *right )
{
    Node    *node;

    node = opNode( op, left, right );
    node->value.iValue = value;
    return node;
}

Node *floatNode( int op, Number value, Node *left, Node *right )
{
    Node    *node;

    node = opNode( op, left, right );
    node->value.fValue = value;
    return node;
}


Node *stringNode( int op, char *string, Node *left, Node *right )
{
    Node    *node;

    node = opNode( op, left, right );
    node->value.string = string;
    return node;
}


Node *symbolNode( int op, Symbol *symbol, Node *left, Node *right )
{
    Node    *node;

    node = opNode( op, left, right );
    node->value.symbol = symbol;
    return node;
}


void freeNode( Node *node )
{
    if (node != NULL) {
        freeNode( node->left );
        freeNode( node->right );
    }
    free( node );
}
