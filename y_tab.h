/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */


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

#include "const.h"
#include "eval.h"
#include "keyword.h"
#include "lexer.h"
#include "class.h"

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Integer = 258,
     Hex = 259,
     Float = 260,
     String = 261,
     FunctionName = 262,
     SubName = 263,
     ForwardSubName = 264,
     ForwardFunctionName = 265,
     BuiltinName = 266,
     ConstantName = 267,
     VariableName = 268,
     ArrayName = 269,
     TypeName = 270,
     ClassName = 271,
     MethodName = 272,
     Undefined = 273,
     And = 274,
     Append = 275,
     As = 276,
     Call = 277,
     Case = 278,
     Class = 279,
     Close = 280,
     Common = 281,
     Const = 282,
     Continue = 283,
     Declare = 284,
     Default = 285,
     Delete = 286,
     Dim = 287,
     Do = 288,
     Each = 289,
     Else = 290,
     ElseIf = 291,
     End = 292,
     EndX = 293,
     Erase = 294,
     Error = 295,
     Exit = 296,
     Explicit = 297,
     For = 298,
     Function = 299,
     Get = 300,
     GetRef = 301,
     GoTo = 302,
     If = 303,
     In = 304,
     IncludeFile = 305,
     ZipIncludeFile = 306,
     Input = 307,
     Inv = 308,
     Is = 309,
     Let = 310,
     Line = 311,
     Loop = 312,
     Mod = 313,
     New = 314,
     Next = 315,
     NoConsole = 316,
     Not = 317,
     Or = 318,
     Open = 319,
     Option = 320,
     Output = 321,
     Preserve = 322,
     Print = 323,
     QBasic = 324,
     ReDim = 325,
     Return = 326,
     Select = 327,
     Set = 328,
     Shared = 329,
     Shl = 330,
     Shr = 331,
     Static = 332,
     Step = 333,
     Sub = 334,
     Then = 335,
     To = 336,
     Until = 337,
     Wend = 338,
     While = 339,
     With = 340,
     Xor = 341,
     Ge = 342,
     Le = 343,
     Ne = 344,
     IncrSelf = 345,
     UMinus = 346,
     Gt = 347,
     Lt = 348,
     Eq = 349
   };
#endif
/* Tokens.  */
#define Integer 258
#define Hex 259
#define Float 260
#define String 261
#define FunctionName 262
#define SubName 263
#define ForwardSubName 264
#define ForwardFunctionName 265
#define BuiltinName 266
#define ConstantName 267
#define VariableName 268
#define ArrayName 269
#define TypeName 270
#define ClassName 271
#define MethodName 272
#define Undefined 273
#define And 274
#define Append 275
#define As 276
#define Call 277
#define Case 278
#define Class 279
#define Close 280
#define Common 281
#define Const 282
#define Continue 283
#define Declare 284
#define Default 285
#define Delete 286
#define Dim 287
#define Do 288
#define Each 289
#define Else 290
#define ElseIf 291
#define End 292
#define EndX 293
#define Erase 294
#define Error 295
#define Exit 296
#define Explicit 297
#define For 298
#define Function 299
#define Get 300
#define GetRef 301
#define GoTo 302
#define If 303
#define In 304
#define IncludeFile 305
#define ZipIncludeFile 306
#define Input 307
#define Inv 308
#define Is 309
#define Let 310
#define Line 311
#define Loop 312
#define Mod 313
#define New 314
#define Next 315
#define NoConsole 316
#define Not 317
#define Or 318
#define Open 319
#define Option 320
#define Output 321
#define Preserve 322
#define Print 323
#define QBasic 324
#define ReDim 325
#define Return 326
#define Select 327
#define Set 328
#define Shared 329
#define Shl 330
#define Shr 331
#define Static 332
#define Step 333
#define Sub 334
#define Then 335
#define To 336
#define Until 337
#define Wend 338
#define While 339
#define With 340
#define Xor 341
#define Ge 342
#define Le 343
#define Ne 344
#define IncrSelf 345
#define UMinus 346
#define Gt 347
#define Lt 348
#define Eq 349




/* Copy the first part of user declarations.  */


/* comma: return a sequence of items to execute */
Node *comma( Node *node1, Node *node2 );

/* blockName: returns name of block */
char *blockName( int klass );

/* checkBlockEnd: make sure the block ends correctly */
void checkBlockEnd(int got);

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
    int     iValue;         /* integer value */
    Number  fValue;         /* float value */
    char    *strValue;      /* string pointer */
    Node    *node;          /* parse node */
    Symbol  *symbol;        /* symbol */
}
/* Line 187 of yacc.c.  */
#line 342 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 355 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3387

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  117
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  318
/* YYNRULES -- Number of states.  */
#define YYNSTATES  635

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   349

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     112,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    97,     2,   111,     2,   103,    98,     2,
     106,   107,   100,    95,   109,    96,   115,   101,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   113,   116,
       2,     2,     2,   110,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   108,   102,   114,   104,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    99,     2,   105,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    13,    16,    19,    22,
      24,    27,    29,    31,    34,    35,    37,    43,    47,    52,
      55,    58,    62,    63,    69,    70,    76,    77,    83,    84,
      90,    93,    96,    99,   102,   103,   109,   112,   116,   119,
     123,   124,   129,   132,   136,   137,   143,   144,   150,   154,
     157,   162,   168,   171,   174,   177,   180,   183,   186,   187,
     196,   197,   207,   213,   214,   223,   229,   234,   239,   243,
     244,   250,   251,   257,   260,   261,   268,   269,   276,   279,
     280,   288,   289,   297,   298,   299,   307,   308,   316,   317,
     318,   326,   327,   335,   338,   341,   345,   351,   358,   364,
     369,   377,   384,   388,   391,   394,   397,   401,   405,   412,
     419,   424,   428,   433,   437,   440,   441,   449,   452,   453,
     458,   459,   466,   467,   473,   478,   483,   484,   490,   492,
     494,   496,   500,   503,   505,   507,   509,   516,   520,   521,
     527,   532,   533,   538,   541,   546,   551,   556,   561,   566,
     571,   574,   575,   579,   584,   587,   592,   597,   602,   607,
     612,   617,   622,   627,   632,   637,   642,   647,   652,   657,
     662,   667,   672,   677,   680,   683,   688,   693,   698,   704,
     705,   711,   714,   715,   721,   724,   725,   731,   734,   736,
     737,   742,   744,   746,   748,   751,   755,   757,   759,   761,
     763,   765,   766,   771,   773,   776,   777,   782,   784,   787,
     788,   793,   796,   797,   802,   804,   806,   809,   812,   817,
     819,   821,   822,   825,   828,   829,   830,   836,   837,   843,
     844,   850,   851,   855,   856,   860,   861,   865,   870,   871,
     875,   877,   879,   888,   897,   904,   911,   917,   921,   923,
     926,   929,   933,   937,   939,   940,   941,   944,   947,   952,
     957,   959,   963,   967,   971,   975,   979,   983,   987,   989,
     993,   995,   999,  1001,  1003,  1004,  1007,  1010,  1015,  1022,
    1027,  1032,  1034,  1036,  1040,  1044,  1047,  1049,  1050,  1053,
    1056,  1057,  1059,  1062,  1063,  1069,  1072,  1077,  1078,  1086,
    1091,  1095,  1098,  1103,  1105,  1107,  1108,  1109,  1112,  1114,
    1116,  1118,  1120,  1125,  1127,  1131,  1134,  1136,  1139
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     118,     0,    -1,   118,   120,    -1,    -1,    37,    48,    -1,
      37,    43,    -1,    37,    44,    -1,    37,    79,    -1,    37,
      84,    -1,    57,    -1,    37,    72,    -1,    60,    -1,    83,
      -1,   120,   119,    -1,    -1,   121,    -1,   105,   156,   106,
     107,   151,    -1,   105,   156,     1,    -1,   105,   156,   106,
       1,    -1,   156,   151,    -1,    12,    94,    -1,     7,    94,
     156,    -1,    -1,     7,   106,   122,   165,   151,    -1,    -1,
       8,   106,   123,   165,   151,    -1,    -1,    10,   106,   124,
     165,   151,    -1,    -1,     9,   106,   125,   165,   151,    -1,
       7,   151,    -1,     8,   151,    -1,    10,   151,    -1,     9,
     151,    -1,    -1,    11,   106,   126,   165,   151,    -1,    11,
     151,    -1,    25,   197,   151,    -1,    25,   151,    -1,    27,
     195,   151,    -1,    -1,    26,   127,   181,   151,    -1,    28,
     151,    -1,    31,   156,   151,    -1,    -1,    32,    26,   128,
     181,   151,    -1,    -1,    32,    74,   129,   186,   151,    -1,
      32,   181,   151,    -1,    38,   151,    -1,    39,    14,   193,
     151,    -1,    39,    14,   108,   178,   151,    -1,    41,    33,
      -1,    41,    43,    -1,    41,    44,    -1,    41,    79,    -1,
      41,    84,    -1,    41,     1,    -1,    -1,    48,   130,   156,
      80,   151,   119,   152,   151,    -1,    -1,    43,    34,    13,
      49,    14,   193,   131,   151,   119,    -1,    43,    34,    13,
      49,     1,    -1,    -1,    43,    34,    18,    49,    14,   132,
     151,   119,    -1,    43,    34,    18,    49,     1,    -1,    43,
      34,    13,     1,    -1,    43,    34,    18,     1,    -1,    43,
      34,     1,    -1,    -1,    43,    13,   133,   176,   151,    -1,
      -1,    43,    18,   134,   176,   151,    -1,    43,     1,    -1,
      -1,    29,    44,    18,   135,   167,   151,    -1,    -1,    29,
      79,    18,   136,   167,   151,    -1,    29,     1,    -1,    -1,
      44,    18,   137,   167,   151,   119,   151,    -1,    -1,    79,
      18,   138,   167,   151,   119,   151,    -1,    -1,    -1,    44,
       7,   139,   188,   140,   119,   151,    -1,    -1,    44,    10,
     141,   167,   151,   119,   151,    -1,    -1,    -1,    79,     8,
     142,   188,   143,   119,   151,    -1,    -1,    79,     9,   144,
     167,   151,   119,   151,    -1,    44,     1,    -1,    79,     1,
      -1,    50,     6,   151,    -1,    51,     6,   109,     6,   151,
      -1,    56,    52,   197,   109,   150,   151,    -1,    52,   197,
     109,   150,   151,    -1,    56,    52,   197,     1,    -1,    64,
     156,    43,   194,    21,   197,   151,    -1,    64,   156,    43,
     194,    21,     1,    -1,    64,   156,     1,    -1,    65,    42,
      -1,    65,    61,    -1,    65,    69,    -1,    68,   177,   151,
      -1,   110,   177,   151,    -1,    68,   111,   156,   109,   177,
     151,    -1,    56,    66,   197,   109,   177,   151,    -1,    68,
     111,   156,     1,    -1,    71,    14,   112,    -1,    71,    14,
     193,   112,    -1,    71,   156,   151,    -1,    71,   151,    -1,
      -1,    72,    23,   145,   156,   151,   153,   151,    -1,    72,
       1,    -1,    -1,    74,   146,   186,   151,    -1,    -1,    84,
     147,   156,   151,   119,   151,    -1,    -1,    33,   148,   151,
     119,   151,    -1,   150,    94,   156,   151,    -1,   150,    90,
     156,   151,    -1,    -1,    18,   106,   149,   165,   151,    -1,
     151,    -1,    18,    -1,    13,    -1,    14,   108,   178,    -1,
      14,     1,    -1,   112,    -1,   113,    -1,     1,    -1,    36,
     156,    80,   151,   119,   152,    -1,    35,   151,   119,    -1,
      -1,    23,   154,   151,   119,   153,    -1,    23,    35,   151,
     119,    -1,    -1,   156,    81,   156,   155,    -1,   156,   155,
      -1,    54,    94,   156,   155,    -1,    54,    89,   156,   155,
      -1,    54,    92,   156,   155,    -1,    54,    93,   156,   155,
      -1,    54,    88,   156,   155,    -1,    54,    87,   156,   155,
      -1,   109,   154,    -1,    -1,   106,   156,   107,    -1,   156,
     104,   192,   156,    -1,    96,   156,    -1,   156,   100,   192,
     156,    -1,   156,   101,   192,   156,    -1,   156,   102,   192,
     156,    -1,   156,   103,   192,   156,    -1,   156,    75,   192,
     156,    -1,   156,    76,   192,   156,    -1,   156,    58,   192,
     156,    -1,   156,    53,   192,   156,    -1,   156,    95,   192,
     156,    -1,   156,    98,   192,   156,    -1,   156,    96,   192,
     156,    -1,   156,    99,   192,   156,    -1,   156,    94,   192,
     156,    -1,   156,    89,   192,   156,    -1,   156,    93,   192,
     156,    -1,   156,    92,   192,   156,    -1,   156,    88,   192,
     156,    -1,   156,    87,   192,   156,    -1,    62,   156,    -1,
      97,   156,    -1,   156,    19,   192,   156,    -1,   156,    63,
     192,   156,    -1,   156,    86,   192,   156,    -1,   156,    49,
     192,    14,   193,    -1,    -1,    16,    17,   106,   157,   165,
      -1,    16,    17,    -1,    -1,   156,    17,   106,   158,   165,
      -1,   156,    17,    -1,    -1,    59,    16,   106,   159,   165,
      -1,    59,    16,    -1,    59,    -1,    -1,    16,   106,   160,
     165,    -1,    16,    -1,    18,    -1,    13,    -1,    14,   193,
      -1,    14,   108,   178,    -1,    14,    -1,    12,    -1,     3,
      -1,     5,    -1,     6,    -1,    -1,    11,   106,   161,   165,
      -1,    11,    -1,    11,     1,    -1,    -1,     7,   106,   162,
     165,    -1,     7,    -1,     7,     1,    -1,    -1,    10,   106,
     163,   165,    -1,    10,     1,    -1,    -1,    18,   106,   164,
     165,    -1,     1,    -1,   107,    -1,   166,   107,    -1,   166,
       1,    -1,   156,   109,   192,   166,    -1,   156,    -1,     1,
      -1,    -1,   106,   107,    -1,   106,   168,    -1,    -1,    -1,
      18,   108,   114,   169,   175,    -1,    -1,    13,   108,   114,
     170,   175,    -1,    -1,    14,   108,   114,   171,   175,    -1,
      -1,    18,   172,   175,    -1,    -1,    13,   173,   175,    -1,
      -1,    14,   174,   175,    -1,   115,   115,   115,   107,    -1,
      -1,   109,   192,   168,    -1,   107,    -1,     1,    -1,    94,
     156,    81,   156,    78,   156,   151,   119,    -1,    94,   156,
      81,   156,    78,   156,   151,   119,    -1,    94,   156,    81,
     156,   151,   119,    -1,    94,   156,    81,   156,   151,   119,
      -1,    94,   156,    81,   156,     1,    -1,    94,   156,     1,
      -1,     1,    -1,   116,   177,    -1,   109,   177,    -1,   156,
     109,   177,    -1,   156,   116,   177,    -1,   156,    -1,    -1,
      -1,   179,   180,    -1,   156,   114,    -1,   156,   109,   192,
     180,    -1,   182,   109,   192,   181,    -1,   182,    -1,    18,
     108,   114,    -1,    18,   108,   183,    -1,    13,   108,   114,
      -1,    13,   108,   183,    -1,    14,   108,   114,    -1,    14,
     108,   183,    -1,    18,    94,   156,    -1,    18,    -1,    13,
      94,   156,    -1,    13,    -1,    14,    94,   156,    -1,    14,
      -1,     1,    -1,    -1,   184,   185,    -1,   156,   114,    -1,
     156,    81,   156,   114,    -1,   156,    81,   156,   109,   192,
     185,    -1,   156,   109,   192,   185,    -1,   187,   109,   192,
     186,    -1,   187,    -1,    13,    -1,    14,   108,   114,    -1,
      14,   108,     1,    -1,    14,     1,    -1,     1,    -1,    -1,
     106,   107,    -1,   106,   189,    -1,    -1,   107,    -1,    13,
     107,    -1,    -1,    13,   109,   192,   190,   189,    -1,    13,
       1,    -1,    14,   108,   114,   107,    -1,    -1,    14,   108,
     114,   109,   192,   191,   189,    -1,    14,   108,   114,     1,
      -1,    14,   108,     1,    -1,    14,     1,    -1,   115,   115,
     115,   107,    -1,     1,    -1,   112,    -1,    -1,    -1,   108,
     114,    -1,    52,    -1,    66,    -1,    20,    -1,     1,    -1,
     196,   109,   192,   195,    -1,   196,    -1,    18,    94,   156,
      -1,    18,     1,    -1,     1,    -1,   111,   156,    -1,   156,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   191,   191,   219,   225,   229,   233,   238,   243,   247,
     252,   256,   260,   264,   275,   280,   290,   293,   296,   299,
     314,   317,   325,   324,   333,   332,   341,   340,   349,   348,
     357,   363,   370,   376,   384,   383,   391,   397,   400,   403,
     407,   406,   416,   422,   427,   426,   438,   437,   447,   450,
     453,   456,   460,   466,   472,   478,   484,   490,   496,   495,
     505,   504,   512,   517,   516,   524,   527,   530,   533,   538,
     537,   546,   545,   555,   560,   559,   574,   573,   587,   592,
     591,   607,   606,   624,   637,   623,   650,   649,   675,   687,
     674,   702,   701,   725,   728,   732,   737,   742,   747,   752,
     755,   758,   761,   764,   768,   773,   778,   781,   784,   787,
     790,   793,   796,   799,   805,   813,   812,   820,   824,   823,
     834,   833,   841,   840,   851,   855,   888,   887,   900,   909,
     913,   916,   920,   926,   927,   928,   943,   948,   952,   957,
     960,   965,   970,   973,   976,   979,   982,   985,   988,   991,
     997,  1001,  1007,  1012,  1015,  1022,  1025,  1028,  1031,  1034,
    1037,  1044,  1047,  1054,  1057,  1060,  1063,  1070,  1073,  1076,
    1079,  1082,  1085,  1091,  1094,  1101,  1108,  1115,  1118,  1126,
    1125,  1134,  1139,  1138,  1145,  1152,  1151,  1158,  1161,  1165,
    1164,  1173,  1176,  1180,  1183,  1186,  1191,  1194,  1197,  1200,
    1203,  1207,  1206,  1214,  1218,  1222,  1221,  1229,  1233,  1237,
    1236,  1244,  1248,  1247,  1260,  1265,  1268,  1271,  1276,  1280,
    1284,  1302,  1303,  1304,  1305,  1310,  1309,  1315,  1314,  1319,
    1318,  1323,  1322,  1328,  1327,  1332,  1331,  1335,  1340,  1344,
    1345,  1346,  1351,  1356,  1361,  1364,  1367,  1370,  1373,  1378,
    1381,  1384,  1387,  1390,  1394,  1398,  1398,  1406,  1410,  1417,
    1426,  1431,  1436,  1442,  1446,  1451,  1455,  1460,  1464,  1469,
    1472,  1476,  1479,  1483,  1489,  1489,  1496,  1500,  1504,  1508,
    1515,  1516,  1520,  1533,  1545,  1548,  1551,  1556,  1557,  1558,
    1559,  1564,  1566,  1574,  1573,  1580,  1584,  1591,  1590,  1597,
    1601,  1604,  1607,  1612,  1619,  1620,  1624,  1626,  1630,  1633,
    1636,  1639,  1644,  1652,  1657,  1661,  1664,  1669,  1671
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Integer", "Hex", "Float", "String",
  "FunctionName", "SubName", "ForwardSubName", "ForwardFunctionName",
  "BuiltinName", "ConstantName", "VariableName", "ArrayName", "TypeName",
  "ClassName", "MethodName", "Undefined", "And", "Append", "As", "Call",
  "Case", "Class", "Close", "Common", "Const", "Continue", "Declare",
  "Default", "Delete", "Dim", "Do", "Each", "Else", "ElseIf", "End",
  "EndX", "Erase", "Error", "Exit", "Explicit", "For", "Function", "Get",
  "GetRef", "GoTo", "If", "In", "IncludeFile", "ZipIncludeFile", "Input",
  "Inv", "Is", "Let", "Line", "Loop", "Mod", "New", "Next", "NoConsole",
  "Not", "Or", "Open", "Option", "Output", "Preserve", "Print", "QBasic",
  "ReDim", "Return", "Select", "Set", "Shared", "Shl", "Shr", "Static",
  "Step", "Sub", "Then", "To", "Until", "Wend", "While", "With", "Xor",
  "Ge", "Le", "Ne", "IncrSelf", "UMinus", "Gt", "Lt", "Eq", "'+'", "'-'",
  "'!'", "'&'", "'|'", "'*'", "'/'", "'\\\\'", "'%'", "'^'", "'~'", "'('",
  "')'", "'['", "','", "'?'", "'#'", "'\\n'", "':'", "']'", "'.'", "';'",
  "$accept", "program", "block", "statement", "command", "@1", "@2", "@3",
  "@4", "@5", "@6", "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14",
  "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22", "@23", "@24",
  "@25", "@26", "@27", "@28", "lval", "sep", "elseIf", "cases",
  "caseTests", "caseTail", "expr", "@29", "@30", "@31", "@32", "@33",
  "@34", "@35", "@36", "argList", "argItems", "parmlist", "parmitem",
  "@37", "@38", "@39", "@40", "@41", "@42", "parmtail", "loopTail",
  "printList", "indexList", "@43", "indexListTail", "dimList", "dimItem",
  "dimIndexList", "@44", "dimIndexItems", "sharedList", "sharedItem",
  "declaredList", "declaredItem", "@45", "@46", "optSep", "optBrackets",
  "fileMode", "constList", "constItem", "fileHandle", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,    43,    45,    33,    38,   124,
      42,    47,    92,    37,    94,   126,    40,    41,    91,    44,
      63,    35,    10,    58,    93,    46,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   117,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   120,   121,   121,   121,   121,
     121,   121,   122,   121,   123,   121,   124,   121,   125,   121,
     121,   121,   121,   121,   126,   121,   121,   121,   121,   121,
     127,   121,   121,   121,   128,   121,   129,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   130,   121,
     131,   121,   121,   132,   121,   121,   121,   121,   121,   133,
     121,   134,   121,   121,   135,   121,   136,   121,   121,   137,
     121,   138,   121,   139,   140,   121,   141,   121,   142,   143,
     121,   144,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   145,   121,   121,   146,   121,
     147,   121,   148,   121,   121,   121,   149,   121,   121,   150,
     150,   150,   150,   151,   151,   151,   152,   152,   152,   153,
     153,   153,   154,   154,   154,   154,   154,   154,   154,   154,
     155,   155,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   157,
     156,   156,   158,   156,   156,   159,   156,   156,   156,   160,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   161,   156,   156,   156,   162,   156,   156,   156,   163,
     156,   156,   164,   156,   156,   165,   165,   165,   166,   166,
     166,   167,   167,   167,   167,   169,   168,   170,   168,   171,
     168,   172,   168,   173,   168,   174,   168,   168,   168,   175,
     175,   175,   176,   176,   176,   176,   176,   176,   176,   177,
     177,   177,   177,   177,   177,   179,   178,   180,   180,   181,
     181,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   184,   183,   185,   185,   185,   185,
     186,   186,   187,   187,   187,   187,   187,   188,   188,   188,
     188,   189,   189,   190,   189,   189,   189,   191,   189,   189,
     189,   189,   189,   189,   192,   192,   193,   193,   194,   194,
     194,   194,   195,   195,   196,   196,   196,   197,   197
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     2,     2,     2,     1,
       2,     1,     1,     2,     0,     1,     5,     3,     4,     2,
       2,     3,     0,     5,     0,     5,     0,     5,     0,     5,
       2,     2,     2,     2,     0,     5,     2,     3,     2,     3,
       0,     4,     2,     3,     0,     5,     0,     5,     3,     2,
       4,     5,     2,     2,     2,     2,     2,     2,     0,     8,
       0,     9,     5,     0,     8,     5,     4,     4,     3,     0,
       5,     0,     5,     2,     0,     6,     0,     6,     2,     0,
       7,     0,     7,     0,     0,     7,     0,     7,     0,     0,
       7,     0,     7,     2,     2,     3,     5,     6,     5,     4,
       7,     6,     3,     2,     2,     2,     3,     3,     6,     6,
       4,     3,     4,     3,     2,     0,     7,     2,     0,     4,
       0,     6,     0,     5,     4,     4,     0,     5,     1,     1,
       1,     3,     2,     1,     1,     1,     6,     3,     0,     5,
       4,     0,     4,     2,     4,     4,     4,     4,     4,     4,
       2,     0,     3,     4,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     2,     2,     4,     4,     4,     5,     0,
       5,     2,     0,     5,     2,     0,     5,     2,     1,     0,
       4,     1,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     0,     4,     1,     2,     0,     4,     1,     2,     0,
       4,     2,     0,     4,     1,     1,     2,     2,     4,     1,
       1,     0,     2,     2,     0,     0,     5,     0,     5,     0,
       5,     0,     3,     0,     3,     0,     3,     4,     0,     3,
       1,     1,     8,     8,     6,     6,     5,     3,     1,     2,
       2,     3,     3,     1,     0,     0,     2,     2,     4,     4,
       1,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     3,     1,     1,     0,     2,     2,     4,     6,     4,
       4,     1,     1,     3,     3,     2,     1,     0,     2,     2,
       0,     1,     2,     0,     5,     2,     4,     0,     7,     4,
       3,     2,     4,     1,     1,     0,     0,     2,     1,     1,
       1,     1,     4,     1,     3,     2,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     1,   135,   198,   199,   200,     0,     0,     0,
       0,     0,   197,   193,     0,   191,   192,     0,    40,     0,
       0,     0,     0,     0,   122,     0,     0,     0,     0,     0,
      58,     0,     0,     0,     0,   188,     0,     0,     0,     0,
       0,     0,   118,     0,   120,     0,     0,     0,     0,     0,
     133,   134,     2,    15,     0,   128,     0,   135,     0,    22,
      30,   135,    24,    31,    28,    33,   135,    26,    32,   135,
      34,    36,    20,   132,   255,   194,   181,   189,   126,     0,
       0,     0,   197,   193,   196,   192,     0,    38,   318,     0,
       0,   316,     0,     0,   313,    42,    78,     0,     0,   214,
       0,   273,   270,   272,   268,    44,    46,     0,   260,     0,
      49,   306,    57,    52,    53,    54,    55,    56,    73,    69,
      71,     0,    93,    83,    86,    79,     0,     0,     0,     0,
       0,     0,   187,   173,     0,   103,   104,   105,     0,     0,
       0,   253,     0,   196,   114,     0,   117,   115,     0,    94,
      88,    91,    81,     0,   154,   174,     0,     0,     0,     0,
       0,   184,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,    19,    21,     0,     0,     0,
       0,     0,     0,     0,     0,   307,   195,     0,   179,     0,
       0,     0,   208,   205,   211,   209,   204,   201,   255,   212,
     317,    37,     0,   315,     0,    39,   305,    74,    76,    43,
       0,   274,     0,   274,     0,   274,     0,     0,    48,   305,
       0,   255,     0,     0,     0,    68,     0,     0,   287,   221,
     221,     0,    95,     0,     0,     0,     0,   185,   102,     0,
     250,     0,   249,     0,     0,   106,   111,   194,   113,     0,
     286,   282,     0,     0,   281,   287,   221,   221,     0,    17,
       0,   152,   107,     0,     0,   182,   304,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     214,   215,   219,     0,     0,   206,     0,     0,     0,   210,
       0,   202,     0,   256,     0,   190,     0,   213,   195,    41,
     314,     0,   221,   221,   269,   263,   264,     0,   271,   265,
     266,   267,   261,   262,     0,     0,     0,     0,     9,    11,
      12,     0,     0,     0,    50,   248,     0,     0,     0,    66,
       0,    67,     0,     0,    84,   238,     0,     0,     0,     0,
     130,     0,   129,     0,    99,     0,     0,     0,   311,   310,
     308,   309,     0,   110,     0,   251,   252,   112,     0,   285,
       0,   119,   305,    89,     0,     0,     0,    18,     0,   125,
     124,     0,   175,   306,   162,   161,   176,   159,   160,   177,
     172,   171,   168,   170,   169,   167,   163,   165,   164,   166,
     155,   156,   157,   158,   153,   305,    23,   217,   216,    25,
      29,    27,    35,   305,   257,   180,   127,   312,     0,     0,
       0,   275,    45,    47,   259,     5,     6,     4,    10,     7,
       8,   123,    13,    51,     0,    70,    72,    62,   306,    65,
      63,   303,     0,     0,   288,     0,   289,     0,   233,   235,
     231,   222,     0,   223,     0,     0,     0,    96,   255,    98,
       0,     0,   186,     0,     0,   141,   284,   283,     0,     0,
       0,     0,     0,    16,   183,     0,   178,     0,     0,    75,
      77,     0,   305,   276,   247,     0,    60,     0,   295,   292,
     305,   301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   131,    97,   109,   101,     0,
     108,     0,     0,   280,     0,     0,     0,   121,   218,   258,
       0,     0,     0,     0,     0,   293,   300,     0,     0,    85,
     227,   241,   240,   305,   234,   229,   236,   225,   232,     0,
      87,    80,     0,     0,     0,   100,     0,     0,     0,   151,
     116,    90,    92,    82,   305,   277,   279,   135,     0,     0,
       0,    64,     0,   299,   296,   305,   302,     0,   238,     0,
       0,   237,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,     0,     0,   244,    61,
     291,   294,   297,   228,   239,   230,   226,   137,     0,   140,
     151,   151,   151,   151,   151,   151,   141,   151,   150,   278,
       0,     0,     0,   149,   148,   145,   146,   147,   144,   139,
     142,   242,   298,   138,   136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   341,   342,    53,   187,   189,   191,   190,   193,
      90,   226,   227,   126,   533,   497,   233,   234,   322,   323,
     240,   267,   238,   457,   239,   265,   479,   266,   259,   148,
     153,   109,   200,    54,    55,   554,   522,   558,   595,    56,
     314,   391,   367,   199,   194,   188,   192,   201,   303,   304,
     356,   463,   580,   577,   579,   510,   506,   508,   544,   347,
     142,   196,   197,   313,   107,   108,   326,   327,   431,   263,
     264,   354,   456,   572,   621,   277,    75,   372,    93,    94,
      89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -535
static const yytype_int16 yypact[] =
{
    -535,  1288,  -535,  3065,  -535,  -535,  -535,   674,    46,    49,
      54,   791,   -55,    22,  1695,    28,   148,   442,  -535,    79,
      30,    40,  2227,   215,  -535,    30,    75,   171,   190,   191,
    -535,    38,    48,  1948,   165,   123,  2227,  2227,   202,   168,
    1888,    84,  -535,   304,  -535,  2227,  2227,  2227,  2227,   642,
    -535,  -535,  -535,  -535,   159,  -535,  1821,  3125,  2227,  -535,
    -535,  -535,  -535,  -535,  -535,  -535,  3185,  -535,  -535,  3245,
    -535,  -535,  -535,  -535,    27,  -535,    71,  -535,  -535,   940,
      77,  1057,  -535,  -535,    89,    93,  2227,  -535,  3005,    30,
     277,  -535,    20,    30,    97,  -535,  -535,   203,   234,  -535,
    1821,  -535,   124,   174,   221,  -535,  -535,    30,   176,    30,
    -535,   175,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,
    -535,   100,  -535,  -535,  -535,  -535,  2227,    30,   185,   195,
    1948,  1948,   167,   217,  2273,  -535,  -535,  -535,   642,  2227,
     642,  2394,    30,   164,  -535,  1821,  -535,  -535,   209,  -535,
    -535,  -535,  -535,  2227,  3005,   217,  2109,  2825,    30,  2227,
    2227,   219,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,  -535,  3005,  2080,  2080,  2080,
    2080,  2080,  2080,  2080,  2080,  -535,   220,  2227,  -535,  2080,
    2080,  2080,  -535,  -535,  -535,  -535,  -535,  -535,    27,  -535,
    3005,  -535,    30,  -535,  2227,  -535,   218,  -535,  -535,  -535,
    2227,   223,  2227,   225,  2227,   229,   277,   209,  -535,   218,
    1627,    27,    30,    21,    21,  -535,   116,   194,   238,   239,
     239,  2885,  -535,   317,   293,    39,   222,  -535,  -535,   193,
    -535,  2013,  -535,   642,   642,  -535,  -535,   235,  -535,  2227,
    -535,  -535,    16,    30,   226,   238,   239,   239,  1821,  -535,
      19,  -535,  -535,  1821,  1821,  -535,  -535,  2227,   332,  2227,
    2227,  2227,  2227,  2227,  2227,  2227,  2227,  2227,  2227,  2227,
    2227,  2227,  2227,  2227,  2227,  2227,  2227,  2227,  2227,  2227,
    -535,  -535,  2703,    30,    50,  -535,    30,    30,    30,  -535,
      30,  -535,  2518,  -535,  2080,  -535,    30,  -535,  -535,  -535,
    3005,    79,   239,   239,  3005,  -535,  -535,  2227,  3005,  -535,
    -535,  3005,  -535,  -535,    30,    30,   277,   254,  -535,  -535,
    -535,    30,  1174,    30,  -535,  -535,  2227,    30,    30,  -535,
     107,  -535,   256,    29,  -535,    81,    30,    30,    30,    30,
    -535,    45,  -535,    30,  -535,   293,   642,  2080,  -535,  -535,
    -535,  -535,   327,  -535,   642,  -535,  -535,  -535,  1821,  -535,
      14,  -535,   218,  -535,    30,    30,  1627,  -535,    30,  -535,
    -535,  2080,   511,   245,   217,   217,   511,    36,    36,   511,
    3283,  3283,  3283,  3283,  3283,  3283,   217,   217,   217,   217,
      36,    36,    36,    36,   337,   218,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,   218,  -535,  -535,  -535,  -535,    30,    30,
    2455,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,  -535,  2334,  -535,  -535,  -535,   245,  -535,
    -535,  -535,    18,    82,  -535,   240,  -535,  1627,   253,   258,
     259,  -535,   255,  -535,  1627,  1627,  1401,  -535,  -535,  -535,
      30,    30,  -535,  1964,    30,   345,  -535,  -535,   209,  1627,
    1627,  1627,    30,  -535,  -535,    27,  -535,  2246,  2227,  -535,
    -535,  2227,   218,  -535,  -535,  2227,  -535,    30,  -535,  -535,
     218,  -535,    15,   257,    30,   260,    47,   261,    47,   272,
      47,   269,    30,    30,   211,  -535,  -535,  -535,  3065,    30,
    -535,  2213,    30,  -535,    30,    30,    30,  -535,  -535,  -535,
    2580,  2227,  1756,    30,  1174,  -535,  -535,    80,   262,  -535,
    -535,  -535,  -535,   218,  -535,  -535,  -535,  -535,  -535,   266,
    -535,  -535,    30,  2227,    30,  -535,    30,   270,    30,  2642,
    -535,  -535,  -535,  -535,   218,  -535,  -535,  -535,  2227,  1627,
    1174,  -535,    78,  -535,  -535,   218,  -535,    47,    92,    47,
      47,  -535,  1627,  2945,  -535,  1627,  2227,  2227,  2227,  2227,
    2227,  2227,  1514,  2227,  1249,  -535,  2227,  1821,  -535,  -535,
    -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,    30,  -535,
    2764,  2764,  2764,  2764,  2764,  2764,   345,  2764,  -535,  -535,
    1627,    78,  1401,  -535,  -535,  -535,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,   211,  -535
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -535,  -535,  -334,   386,  -535,  -535,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,  -232,    -7,  -239,  -213,  -190,  -215,   343,
    -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -165,   -82,
    -103,  -172,  -535,  -535,  -535,  -535,  -535,  -535,  -340,   173,
     -42,  -199,  -535,   -80,   -76,  -535,  -135,  -535,  -420,  -216,
    -535,   144,  -534,  -535,  -535,  -107,  -106,  -535,    90,  -535,
     -27
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -255
static const yytype_int16 yytable[] =
{
      60,    63,    65,    68,    71,   232,   129,   158,   442,   318,
      87,   335,   363,    95,   212,   476,   536,   379,   110,   498,
     387,   213,   345,   305,   306,   307,   308,   309,   310,   311,
     451,    61,   343,   144,   315,   316,   317,   257,   601,    72,
     364,    96,   452,   453,   127,    76,    73,    61,   541,   185,
      61,   417,   482,   161,   128,    66,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   204,   451,
      91,   573,   211,   501,    97,   146,   215,   632,   330,   111,
     333,   452,   453,   219,   458,   459,   250,    92,   252,   460,
     228,   235,   230,   245,   246,   458,   459,   147,   447,   321,
     460,   566,  -130,   236,   214,   346,  -130,   349,   237,    98,
     242,   448,   336,   504,   380,   499,   388,   500,   477,   537,
     512,   513,   514,   470,    77,   255,   454,   357,   258,   132,
     184,   195,    50,    51,   455,   524,   525,   526,   365,   425,
     334,   272,    62,   468,   542,    64,   543,   418,    50,    51,
      67,    50,    51,   384,   385,   350,    50,    51,   546,    99,
     548,     4,   112,     5,     6,    79,   619,   198,    80,    81,
      82,    83,    84,   205,    15,   600,    85,   574,   461,   575,
     502,   118,   122,   455,   368,   351,   462,   208,   123,   209,
     571,   124,   472,   119,   113,   319,   216,   462,   120,   125,
     260,   375,   376,   369,   114,   115,   101,   130,   220,   428,
     429,   217,   261,   262,   121,   344,   484,    35,   102,   103,
      36,   131,   221,   104,   161,   598,   599,   603,  -129,   605,
     606,   105,  -129,   352,   135,   370,   552,   553,   607,   159,
     116,   609,   218,   160,    78,   117,   381,   449,   616,   371,
     434,   386,   523,   136,    45,    46,   389,   390,   222,   515,
     450,   137,   208,   247,    48,   478,   256,   138,   101,   139,
    -254,  -254,   223,   231,   140,   229,   631,   486,   633,   106,
     102,   103,   167,   168,   243,   104,   416,   435,   436,   419,
     420,   421,   437,   422,   244,   149,   360,   361,   487,   426,
    -131,   362,   150,   151,  -131,   224,   488,   180,   181,   182,
     183,   184,   152,   359,   471,   275,   438,   432,   433,   225,
     276,   366,   474,   439,   441,   382,   443,   325,   440,   329,
     445,   446,   496,   332,   353,   355,   393,   377,   473,   464,
     465,   466,   467,   485,   161,   503,   469,   586,   587,   588,
      88,   505,   589,   590,   591,   100,   507,   509,   521,   576,
     511,   475,   538,   581,   540,   545,    88,   480,   481,   133,
     134,   483,   141,   145,   549,   531,   547,    52,   154,   155,
     156,   157,   141,   535,   634,   623,   624,   625,   626,   627,
     628,   186,   630,   629,   618,   528,   604,   348,   529,   383,
       0,   427,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   489,   490,     0,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,     0,   578,     0,     0,     0,
       0,     0,     0,     3,     0,     4,   519,     5,     6,    79,
       0,     0,    80,    81,    82,    83,    84,   596,    15,     0,
      85,     0,     0,   516,   517,     0,     0,   520,   602,   241,
       0,     0,     0,    88,    88,   527,     0,     0,     0,     0,
       0,   141,   251,   141,     0,     0,     0,     0,     0,     0,
     534,     0,     0,     0,     0,     0,   268,   539,     0,     0,
       0,    35,   273,   274,    36,   550,   551,     0,     0,     0,
       0,     0,   555,     0,     0,   560,     0,   561,   562,   563,
       0,     0,     0,     0,     0,   569,   570,     0,   161,     0,
     302,   302,   302,   302,   302,   302,   302,   302,    45,    46,
     312,     0,   302,   302,   302,   582,     0,   584,    48,   585,
       0,   592,     0,    86,    50,    51,     0,   320,     0,     0,
     163,     0,     0,   324,   164,   328,     0,   331,     0,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   168,     0,     0,
     620,     0,     0,     0,     0,     0,   141,   141,   170,   171,
     172,   622,   378,   173,   174,   175,   176,   177,     0,   178,
     179,   180,   181,   182,   183,   184,     0,     0,     0,     0,
     392,     0,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,    99,     0,     4,     0,     5,     6,    79,
       0,     0,    80,    81,    82,    83,    84,   302,    15,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     430,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   444,
       0,  -207,     0,  -207,     0,     0,     0,     0,     0,     0,
       0,    35,     0,     0,    36,     0,     0,     0,     0,   141,
     302,     0,     0,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,  -207,     0,     0,     0,  -207,     0,     0,
       0,     0,  -207,     0,   302,     0,     0,  -207,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,    48,  -207,
    -207,   138,     0,     0,  -254,  -254,     0,     0,   140,     0,
    -207,  -207,  -207,  -207,     0,     0,  -207,  -207,    58,  -207,
    -207,     0,  -207,  -207,  -207,  -207,  -207,  -207,  -207,     0,
      59,     0,     0,     0,     0,     0,    50,    51,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -203,     0,
    -203,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,   312,     0,     0,   530,     0,     0,     0,   532,     0,
    -203,     0,     0,     0,  -203,     0,     0,     0,     0,  -203,
       0,     0,     0,     0,  -203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   559,     0,  -203,  -203,     0,     0,
       0,     0,     0,     0,   430,     0,     0,  -203,  -203,  -203,
    -203,     0,     0,  -203,  -203,  -203,  -203,  -203,     0,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,   583,    70,     0,     0,
       0,     0,     0,    50,    51,     0,     0,     0,     0,     0,
       0,   597,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
     611,   612,   613,   614,   615,     0,   617,   559,     0,   430,
    -207,   202,     0,  -207,     0,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,     0,  -207,  -207,  -207,  -207,
       0,     0,     0,  -207,     0,  -207,  -207,  -207,  -207,  -207,
       0,  -207,  -207,  -207,     0,  -207,  -207,  -207,  -207,  -207,
       0,  -207,     0,  -207,  -207,     0,     0,     0,  -207,  -207,
    -207,  -207,  -207,  -207,     0,     0,  -207,  -207,  -207,  -207,
    -207,     0,  -207,  -207,  -207,  -207,     0,     0,  -207,     0,
       0,  -207,  -207,     0,  -207,  -207,  -207,     0,  -207,  -207,
    -207,  -207,     0,  -207,  -207,     0,  -207,  -207,  -207,  -207,
       0,     0,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,   203,  -207,     0,  -207,
    -207,     0,  -207,  -207,  -207,     0,  -207,  -203,   206,     0,
    -203,     0,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,     0,  -203,  -203,  -203,  -203,     0,     0,     0,
    -203,     0,  -203,  -203,  -203,  -203,  -203,     0,  -203,  -203,
    -203,     0,  -203,  -203,  -203,  -203,  -203,     0,  -203,     0,
    -203,  -203,     0,     0,     0,  -203,  -203,  -203,  -203,  -203,
    -203,     0,     0,  -203,  -203,  -203,  -203,  -203,     0,  -203,
    -203,  -203,  -203,     0,     0,  -203,     0,     0,  -203,  -203,
       0,  -203,  -203,  -203,     0,  -203,  -203,  -203,  -203,     0,
    -203,  -203,     0,  -203,  -203,  -203,  -203,     0,     0,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,   207,  -203,     0,  -203,  -203,     0,  -203,
    -203,  -203,     0,  -203,   -14,     3,     0,     4,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
      15,     0,    16,     0,     0,     0,     0,   -14,     0,    17,
      18,    19,    20,    21,     0,    22,    23,    24,     0,   -14,
     -14,   337,    25,    26,     0,    27,     0,    28,    29,     0,
       0,     0,    30,     0,    31,    32,    33,     0,     0,     0,
      34,   338,     0,    35,   339,     0,    36,     0,    37,    38,
       0,     0,    39,     0,     0,    40,    41,     0,    42,     0,
      99,     0,     4,    43,     5,     6,    79,   340,    44,    80,
      81,    82,    83,    84,     0,    15,     0,    85,     0,     0,
      45,    46,     0,     0,     0,     0,     0,     0,     0,    47,
      48,     0,     0,     0,    49,     0,    50,    51,     2,     3,
       0,     4,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   557,    15,     0,    16,     0,    35,     0,
       0,    36,     0,    17,    18,    19,    20,    21,     0,    22,
      23,    24,     0,     0,     0,     0,    25,    26,     0,    27,
       0,    28,    29,     0,     0,     0,    30,     0,    31,    32,
      33,     0,     0,     0,    34,    45,    46,    35,     0,     0,
      36,     0,    37,    38,     0,    48,    39,     0,     0,    40,
      41,     0,    42,     0,     0,     0,     0,    43,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,     0,    47,    48,     0,     0,     0,    49,     0,
      50,    51,     3,     0,     4,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,    15,     0,    16,
       0,     0,     0,     0,     0,     0,    17,    18,    19,    20,
      21,     0,    22,    23,    24,     0,   -14,   -14,   337,    25,
      26,     0,    27,     0,    28,    29,     0,     0,     0,    30,
       0,    31,    32,    33,     0,     0,     0,    34,   338,     0,
      35,   339,     0,    36,     0,    37,    38,     0,     0,    39,
       0,     0,    40,    41,     0,    42,     0,     0,     0,     0,
      43,     0,     0,     0,   340,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,    47,    48,     0,     0,
       0,    49,     0,    50,    51,     3,     0,     4,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
      15,     0,    16,     0,     0,     0,     0,   -14,     0,    17,
      18,    19,    20,    21,     0,    22,    23,    24,     0,     0,
       0,   337,    25,    26,     0,    27,     0,    28,    29,     0,
       0,     0,    30,     0,    31,    32,    33,     0,     0,     0,
      34,   338,     0,    35,   339,     0,    36,     0,    37,    38,
       0,     0,    39,     0,     0,    40,    41,     0,    42,     0,
       0,     0,     0,    43,     0,     0,     0,   340,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    46,     0,     0,     0,     0,     0,     0,     0,    47,
      48,     0,     0,     0,    49,     0,    50,    51,     3,     0,
       4,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,    15,     0,    16,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,    21,     0,    22,    23,
      24,     0,     0,     0,   337,    25,    26,     0,    27,     0,
      28,    29,     0,     0,     0,    30,     0,    31,    32,    33,
       0,     0,     0,    34,   338,     0,    35,   339,     0,    36,
       0,    37,    38,     0,     0,    39,    73,     0,    40,    41,
       0,    42,     0,     0,     0,     0,    43,     0,     0,     0,
     340,    44,  -196,     0,  -196,     0,     0,     0,     0,     0,
       0,     0,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,    47,    48,     0,     0,     0,    49,     0,    50,
      51,     0,     0,     0,  -196,     0,     0,     0,  -196,     0,
       0,     0,     0,  -196,     0,     0,     0,   567,  -196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -196,  -196,     0,   161,     0,   162,     0,     0,     0,     0,
       0,  -196,  -196,  -196,  -196,     0,     0,  -196,  -196,  -196,
    -196,  -196,     0,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
       0,     0,     0,    74,     0,   163,     0,  -196,  -196,   164,
       0,     0,     0,     0,   165,     0,     0,     0,     0,   166,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,     0,   568,     0,     0,     0,   161,     0,
     162,     0,   169,   170,   171,   172,     0,     0,   173,   174,
     175,   176,   177,     0,   178,   179,   180,   181,   182,   183,
     184,     0,     0,     0,     0,     0,     0,     0,    50,    51,
     163,     0,     0,     0,   164,     0,     0,     0,     0,   165,
       0,     0,     0,     0,   166,     0,     0,     0,     0,     3,
       0,     4,     0,     5,     6,    79,   167,   168,    80,    81,
      82,    83,   143,     0,    15,     0,    85,   169,   170,   171,
     172,     0,     0,   173,   174,   175,   176,   177,     0,   178,
     179,   180,   181,   182,   183,   184,     0,     0,     0,     0,
       0,     0,     0,    50,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,     0,    99,
      36,     4,     0,     5,     6,    79,     0,     0,    80,    81,
      82,    83,    84,     0,    15,   518,    85,     4,     0,     5,
       6,    79,     0,     0,    80,    81,    82,    83,    84,     0,
      15,     0,    85,     0,    45,    46,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
      50,    51,     0,     0,     0,     0,     0,    35,     0,     0,
      36,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,    36,     0,     0,     0,
     161,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,    86,
      45,    46,   163,     0,     0,     0,   164,     0,     0,     0,
      48,   165,     0,     0,     0,    86,   166,     0,     0,     0,
       0,   300,     0,     4,     0,     5,     6,    79,   167,   168,
      80,    81,    82,    83,    84,     0,    15,     0,    85,   169,
     170,   171,   172,     0,     0,   173,   174,   175,   176,   177,
     269,   178,   179,   180,   181,   182,   183,   184,     0,     0,
       0,     0,   374,     0,     0,     0,   161,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,   164,     0,     0,     0,     0,   165,     0,     0,
       0,     0,   166,     0,     0,     0,    45,    46,     0,     0,
       0,     0,     0,     0,   167,   168,    48,   301,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,     0,
       0,   173,   174,   175,   176,   177,     0,   178,   179,   180,
     181,   182,   183,   184,    99,   270,     4,     0,     5,     6,
      79,     0,     0,    80,    81,    82,    83,    84,    99,    15,
       4,    85,     5,     6,    79,     0,     0,    80,    81,    82,
      83,    84,     0,    15,     0,    85,     0,   300,   556,     4,
       0,     5,     6,    79,     0,     0,    80,    81,    82,    83,
      84,     0,    15,     0,    85,     0,     0,   557,     0,     0,
       0,     0,    35,     0,   248,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,    36,
     161,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     0,    36,    45,
      46,     0,     0,     0,     0,     0,   249,     0,     0,    48,
       0,     0,   163,    45,    46,     0,   164,     0,     0,     0,
       0,   165,     0,    48,     0,   494,   166,     0,     0,     0,
       0,     0,    45,    46,     0,     0,     0,     0,   167,   168,
       0,   161,    48,   162,     0,     0,     0,     0,     0,   169,
     170,   171,   172,     0,     0,   173,   174,   175,   176,   177,
       0,   178,   179,   180,   181,   182,   183,   184,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   164,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   161,     0,   162,     0,   495,     0,     0,     0,     0,
     169,   170,   171,   172,     0,     0,   173,   174,   175,   176,
     177,     0,   178,   179,   180,   181,   182,   183,   184,     0,
       0,     0,     0,   163,     0,     0,     0,   164,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,     0,   161,     0,   162,     0,     0,     0,     0,     0,
     169,   170,   171,   172,     0,     0,   173,   174,   175,   176,
     177,     0,   178,   179,   180,   181,   182,   183,   184,     0,
       0,     0,     0,   253,   163,     0,     0,     0,   164,     0,
     254,     0,     0,   165,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,     0,     0,     0,   161,   491,   162,     0,     0,
       0,   169,   170,   171,   172,     0,     0,   173,   174,   175,
     176,   177,     0,   178,   179,   180,   181,   182,   183,   184,
       0,     0,     0,     0,   492,     0,     0,   163,     0,   493,
       0,   164,     0,     0,     0,     0,   165,     0,     0,     0,
       0,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,     0,     0,   161,     0,   162,
       0,     0,     0,     0,   169,   170,   171,   172,     0,     0,
     173,   174,   175,   176,   177,     0,   178,   179,   180,   181,
     182,   183,   184,     0,     0,     0,     0,   423,     0,   163,
       0,     0,   424,   164,     0,     0,     0,     0,   165,     0,
       0,     0,     0,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,     0,     0,   161,
       0,   162,     0,     0,     0,     0,   169,   170,   171,   172,
       0,     0,   173,   174,   175,   176,   177,     0,   178,   179,
     180,   181,   182,   183,   184,     0,     0,     0,     0,   564,
       0,   163,     0,     0,   565,   164,     0,     0,     0,     0,
     165,     0,     0,     0,     0,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,     0,
     161,     0,   162,   593,     0,     0,     0,     0,   169,   170,
     171,   172,     0,     0,   173,   174,   175,   176,   177,     0,
     178,   179,   180,   181,   182,   183,   184,     0,     0,     0,
       0,   594,   163,     0,     0,     0,   164,     0,     0,     0,
       0,   165,     0,     0,     0,     0,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   168,
       0,   161,     0,   162,     0,     0,     0,     0,     0,   169,
     170,   171,   172,     0,     0,   173,   174,   175,   176,   177,
       0,   178,   179,   180,   181,   182,   183,   184,     0,     0,
       0,     0,   415,   163,     0,     0,     0,   164,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,     0,   161,     0,   162,     0,     0,     0,     0,     0,
     169,   170,   171,   172,     0,     0,   173,   174,   175,   176,
     177,     0,   178,   179,   180,   181,   182,   183,   184,     0,
       0,     0,     0,   594,   163,     0,     0,     0,   164,     0,
       0,     0,     0,   165,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,   161,     0,   162,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,     0,     0,   173,   174,   175,
     176,   177,     0,   178,   179,   180,   181,   182,   183,   184,
       0,     0,   271,     0,   163,     0,     0,     0,   164,     0,
       0,     0,     0,   165,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,   161,     0,   162,   358,     0,     0,     0,     0,
       0,   169,   170,   171,   172,     0,     0,   173,   174,   175,
     176,   177,     0,   178,   179,   180,   181,   182,   183,   184,
       0,     0,     0,     0,   163,     0,     0,     0,   164,     0,
       0,     0,     0,   165,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,   161,     0,   162,   608,     0,     0,     0,     0,
       0,   169,   170,   171,   172,     0,     0,   173,   174,   175,
     176,   177,     0,   178,   179,   180,   181,   182,   183,   184,
       0,     0,     0,     0,   163,     0,     0,     0,   164,     0,
       0,     0,     0,   165,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,  -214,     0,  -214,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,     0,     0,   173,   174,   175,
     176,   177,     0,   178,   179,   180,   181,   182,   183,   184,
       0,     0,     0,     0,  -214,     0,     0,     0,  -214,     0,
       0,     0,     0,  -214,     0,     0,     0,     0,  -214,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -214,  -214,  -208,     0,  -208,     0,     0,     0,     0,     0,
       0,  -214,  -214,  -214,  -214,     0,     0,  -214,  -214,  -214,
    -214,     0,     0,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
       0,     0,     0,     0,  -208,     0,     0,     0,  -208,     0,
       0,     0,     0,  -208,     0,     0,     0,     0,  -208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -208,  -208,  -211,     0,  -211,     0,     0,     0,     0,     0,
       0,  -208,  -208,  -208,  -208,     0,     0,  -208,  -208,  -208,
    -208,     0,     0,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
       0,     0,     0,     0,  -211,     0,     0,     0,  -211,     0,
       0,     0,     0,  -211,     0,     0,     0,     0,  -211,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -211,  -211,  -204,     0,  -204,     0,     0,     0,     0,     0,
       0,  -211,  -211,  -211,  -211,     0,     0,  -211,  -211,  -211,
    -211,     0,     0,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
       0,     0,     0,     0,  -204,     0,     0,     0,  -204,     0,
     161,     0,     0,  -204,     0,     0,     0,     0,  -204,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -204,  -204,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -204,  -204,  -204,  -204,     0,   164,  -204,  -204,  -204,
    -204,   165,     0,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,   177,
       0,   178,   179,   180,   181,   182,   183,   184
};

static const yytype_int16 yycheck[] =
{
       7,     8,     9,    10,    11,   111,    33,    49,   342,   208,
      17,   227,   244,    20,    90,     1,     1,     1,    25,     1,
       1,     1,     1,   188,   189,   190,   191,   192,   193,   194,
       1,     1,   231,    40,   199,   200,   201,   143,   572,    94,
       1,     1,    13,    14,     6,    17,     1,     1,     1,    56,
       1,     1,   386,    17,     6,     1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,     1,     1,
       1,     1,    89,     1,    44,     1,    93,   621,   223,    14,
     225,    13,    14,   100,    13,    14,   138,    18,   140,    18,
     107,     1,   109,   130,   131,    13,    14,    23,     1,   216,
      18,   531,    90,    13,    94,    94,    94,     1,    18,    79,
     127,    14,   229,   457,   108,   107,   107,   109,   114,   114,
     464,   465,   466,   365,   106,   142,   107,   240,   145,    16,
     104,   114,   112,   113,   115,   479,   480,   481,   109,   314,
     226,   158,   106,   108,   107,   106,   109,   107,   112,   113,
     106,   112,   113,   266,   267,    49,   112,   113,   508,     1,
     510,     3,     1,     5,     6,     7,   596,   106,    10,    11,
      12,    13,    14,   106,    16,   107,    18,   107,   107,   109,
     108,     1,     1,   115,     1,     1,   115,   108,     7,   106,
     534,    10,   367,    13,    33,   212,   109,   115,    18,    18,
       1,   253,   254,    20,    43,    44,     1,    52,    94,   322,
     323,    18,    13,    14,    34,   232,   391,    59,    13,    14,
      62,    66,   108,    18,    17,   569,   570,   577,    90,   579,
     580,    26,    94,    49,    42,    52,    35,    36,   582,    90,
      79,   585,    18,    94,   106,    84,   263,     1,   592,    66,
     336,   268,   478,    61,    96,    97,   273,   274,    94,   468,
      14,    69,   108,   106,   106,   382,   112,   109,     1,   111,
     112,   113,   108,   108,   116,   109,   620,   393,   622,    74,
      13,    14,    75,    76,   109,    18,   303,    43,    44,   306,
     307,   308,    48,   310,   109,     1,    13,    14,   415,   316,
      90,    18,     8,     9,    94,    94,   423,   100,   101,   102,
     103,   104,    18,     6,   366,   106,    72,   334,   335,   108,
     112,   109,   374,    79,   341,   109,   343,   114,    84,   114,
     347,   348,   448,   114,   106,   106,    14,   112,    21,   356,
     357,   358,   359,   108,    17,   115,   363,    87,    88,    89,
      17,   108,    92,    93,    94,    22,   108,   108,    23,   107,
     115,   378,   115,   107,   114,   114,    33,   384,   385,    36,
      37,   388,    39,    40,   115,   492,   114,     1,    45,    46,
      47,    48,    49,   500,   633,   610,   611,   612,   613,   614,
     615,    58,   617,   616,   594,   487,   578,   234,   488,   265,
      -1,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,   473,     5,     6,     7,
      -1,    -1,    10,    11,    12,    13,    14,   564,    16,    -1,
      18,    -1,    -1,   470,   471,    -1,    -1,   474,   575,   126,
      -1,    -1,    -1,   130,   131,   482,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     497,    -1,    -1,    -1,    -1,    -1,   153,   504,    -1,    -1,
      -1,    59,   159,   160,    62,   512,   513,    -1,    -1,    -1,
      -1,    -1,   519,    -1,    -1,   522,    -1,   524,   525,   526,
      -1,    -1,    -1,    -1,    -1,   532,   533,    -1,    17,    -1,
     187,   188,   189,   190,   191,   192,   193,   194,    96,    97,
     197,    -1,   199,   200,   201,   552,    -1,   554,   106,   556,
      -1,   558,    -1,   111,   112,   113,    -1,   214,    -1,    -1,
      49,    -1,    -1,   220,    53,   222,    -1,   224,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,
     597,    -1,    -1,    -1,    -1,    -1,   253,   254,    87,    88,
      89,   608,   259,    92,    93,    94,    95,    96,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
     277,    -1,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,     1,    -1,     3,    -1,     5,     6,     7,
      -1,    -1,    10,    11,    12,    13,    14,   314,    16,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     327,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,
      -1,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,   366,
     367,    -1,    -1,    -1,    -1,    -1,    -1,   374,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    58,    -1,   391,    -1,    -1,    63,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    75,
      76,   109,    -1,    -1,   112,   113,    -1,    -1,   116,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      19,    -1,    -1,    -1,    -1,    -1,   473,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     487,   488,    -1,    -1,   491,    -1,    -1,    -1,   495,    -1,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   521,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,   531,    -1,    -1,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    95,    96,    -1,    98,
      99,   100,   101,   102,   103,   104,   553,   106,    -1,    -1,
      -1,    -1,    -1,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,   568,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   586,
     587,   588,   589,   590,   591,    -1,   593,   594,    -1,   596,
       0,     1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    -1,    23,    -1,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    -1,    -1,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    -1,    -1,    68,    -1,
      -1,    71,    72,    -1,    74,    75,    76,    -1,    78,    79,
      80,    81,    -1,    83,    84,    -1,    86,    87,    88,    89,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
     110,    -1,   112,   113,   114,    -1,   116,     0,     1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    -1,    -1,
      23,    -1,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    -1,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,
      -1,    74,    75,    76,    -1,    78,    79,    80,    81,    -1,
      83,    84,    -1,    86,    87,    88,    89,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,     0,     1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    -1,    35,
      36,    37,    38,    39,    -1,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    -1,    -1,    -1,
      56,    57,    -1,    59,    60,    -1,    62,    -1,    64,    65,
      -1,    -1,    68,    -1,    -1,    71,    72,    -1,    74,    -1,
       1,    -1,     3,    79,     5,     6,     7,    83,    84,    10,
      11,    12,    13,    14,    -1,    16,    -1,    18,    -1,    -1,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,    -1,   112,   113,     0,     1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    54,    16,    -1,    18,    -1,    59,    -1,
      -1,    62,    -1,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    -1,    -1,    -1,    56,    96,    97,    59,    -1,    -1,
      62,    -1,    64,    65,    -1,   106,    68,    -1,    -1,    71,
      72,    -1,    74,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,    -1,
     112,   113,     1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    36,    37,    38,
      39,    -1,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    -1,    -1,    -1,    56,    57,    -1,
      59,    60,    -1,    62,    -1,    64,    65,    -1,    -1,    68,
      -1,    -1,    71,    72,    -1,    74,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,    -1,   112,   113,     1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    -1,    -1,
      -1,    37,    38,    39,    -1,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    -1,    -1,    -1,
      56,    57,    -1,    59,    60,    -1,    62,    -1,    64,    65,
      -1,    -1,    68,    -1,    -1,    71,    72,    -1,    74,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,    -1,   112,   113,     1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      -1,    -1,    -1,    56,    57,    -1,    59,    60,    -1,    62,
      -1,    64,    65,    -1,    -1,    68,     1,    -1,    71,    72,
      -1,    74,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      83,    84,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,    -1,   112,
     113,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,     1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    -1,    17,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,   108,    -1,    49,    -1,   112,   113,    53,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    -1,    78,    -1,    -1,    -1,    17,    -1,
      19,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    95,    96,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,     1,
      -1,     3,    -1,     5,     6,     7,    75,    76,    10,    11,
      12,    13,    14,    -1,    16,    -1,    18,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    95,    96,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,     1,
      62,     3,    -1,     5,     6,     7,    -1,    -1,    10,    11,
      12,    13,    14,    -1,    16,     1,    18,     3,    -1,     5,
       6,     7,    -1,    -1,    10,    11,    12,    13,    14,    -1,
      16,    -1,    18,    -1,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
     112,   113,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      62,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    62,    -1,    -1,    -1,
      17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,   111,
      96,    97,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
     106,    58,    -1,    -1,    -1,   111,    63,    -1,    -1,    -1,
      -1,     1,    -1,     3,    -1,     5,     6,     7,    75,    76,
      10,    11,    12,    13,    14,    -1,    16,    -1,    18,    86,
      87,    88,    89,    -1,    -1,    92,    93,    94,    95,    96,
       1,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    17,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,   106,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    -1,
      -1,    92,    93,    94,    95,    96,    -1,    98,    99,   100,
     101,   102,   103,   104,     1,   106,     3,    -1,     5,     6,
       7,    -1,    -1,    10,    11,    12,    13,    14,     1,    16,
       3,    18,     5,     6,     7,    -1,    -1,    10,    11,    12,
      13,    14,    -1,    16,    -1,    18,    -1,     1,    35,     3,
      -1,     5,     6,     7,    -1,    -1,    10,    11,    12,    13,
      14,    -1,    16,    -1,    18,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    -1,     1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    62,
      17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    62,    96,
      97,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,   106,
      -1,    -1,    49,    96,    97,    -1,    53,    -1,    -1,    -1,
      -1,    58,    -1,   106,    -1,     1,    63,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    -1,    -1,    -1,    75,    76,
      -1,    17,   106,    19,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    -1,    -1,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    17,    -1,    19,    -1,    81,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,    49,    -1,    -1,    -1,    53,    -1,
     116,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    -1,    -1,    -1,    17,    81,    19,    -1,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    49,    -1,   114,
      -1,    53,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    -1,    -1,    17,    -1,    19,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    -1,    -1,
      92,    93,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,   109,    -1,    49,
      -1,    -1,   114,    53,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      -1,    -1,    92,    93,    94,    95,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,   109,
      -1,    49,    -1,    -1,   114,    53,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,
      17,    -1,    19,    81,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    -1,    -1,    92,    93,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,   109,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    -1,    -1,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,   109,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,   107,    -1,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    17,    -1,    19,    80,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    17,    -1,    19,    80,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    -1,
      17,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    -1,    53,    92,    93,    94,
      95,    58,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      -1,    98,    99,   100,   101,   102,   103,   104
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   118,     0,     1,     3,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    16,    18,    25,    26,    27,
      28,    29,    31,    32,    33,    38,    39,    41,    43,    44,
      48,    50,    51,    52,    56,    59,    62,    64,    65,    68,
      71,    72,    74,    79,    84,    96,    97,   105,   106,   110,
     112,   113,   120,   121,   150,   151,   156,     1,    94,   106,
     151,     1,   106,   151,   106,   151,     1,   106,   151,     1,
     106,   151,    94,     1,   108,   193,    17,   106,   106,     7,
      10,    11,    12,    13,    14,    18,   111,   151,   156,   197,
     127,     1,    18,   195,   196,   151,     1,    44,    79,     1,
     156,     1,    13,    14,    18,    26,    74,   181,   182,   148,
     151,    14,     1,    33,    43,    44,    79,    84,     1,    13,
      18,    34,     1,     7,    10,    18,   130,     6,     6,   197,
      52,    66,    16,   156,   156,    42,    61,    69,   109,   111,
     116,   156,   177,    14,   151,   156,     1,    23,   146,     1,
       8,     9,    18,   147,   156,   156,   156,   156,   177,    90,
      94,    17,    19,    49,    53,    58,    63,    75,    76,    86,
      87,    88,    89,    92,    93,    94,    95,    96,    98,    99,
     100,   101,   102,   103,   104,   151,   156,   122,   162,   123,
     125,   124,   163,   126,   161,   114,   178,   179,   106,   160,
     149,   164,     1,   106,     1,   106,     1,   106,   108,   106,
     156,   151,   181,     1,    94,   151,   109,    18,    18,   151,
      94,   108,    94,   108,    94,   108,   128,   129,   151,   109,
     151,   108,   193,   133,   134,     1,    13,    18,   139,   141,
     137,   156,   151,   109,   109,   197,   197,   106,     1,    43,
     177,   156,   177,   109,   116,   151,   112,   193,   151,   145,
       1,    13,    14,   186,   187,   142,   144,   138,   156,     1,
     106,   107,   151,   156,   156,   106,   112,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
       1,   107,   156,   165,   166,   165,   165,   165,   165,   165,
     165,   165,   156,   180,   157,   165,   165,   165,   178,   151,
     156,   192,   135,   136,   156,   114,   183,   184,   156,   114,
     183,   156,   114,   183,   181,   186,   192,    37,    57,    60,
      83,   119,   120,   178,   151,     1,    94,   176,   176,     1,
      49,     1,    49,   106,   188,   106,   167,   167,    80,     6,
      13,    14,    18,   150,     1,   109,   109,   159,     1,    20,
      52,    66,   194,     1,   109,   177,   177,   112,   156,     1,
     108,   151,   109,   188,   167,   167,   151,     1,   107,   151,
     151,   158,   156,    14,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   109,   151,     1,   107,   151,
     151,   151,   151,   109,   114,   165,   151,   195,   167,   167,
     156,   185,   151,   151,   181,    43,    44,    48,    72,    79,
      84,   151,   119,   151,   156,   151,   151,     1,    14,     1,
      14,     1,    13,    14,   107,   115,   189,   140,    13,    14,
      18,   107,   115,   168,   151,   151,   151,   151,   108,   151,
     150,   177,   165,    21,   177,   151,     1,   114,   192,   143,
     151,   151,   119,   151,   165,   108,   193,   192,   192,   151,
     151,    81,   109,   114,     1,    81,   193,   132,     1,   107,
     109,     1,   108,   115,   119,   108,   173,   108,   174,   108,
     172,   115,   119,   119,   119,   178,   151,   151,     1,   197,
     151,    23,   153,   186,   119,   119,   119,   151,   166,   180,
     156,   192,   156,   131,   151,   192,     1,   114,   115,   151,
     114,     1,   107,   109,   175,   114,   175,   114,   175,   115,
     151,   151,    35,    36,   152,   151,    35,    54,   154,   156,
     151,   151,   151,   151,   109,   114,   185,     1,    78,   151,
     151,   119,   190,     1,   107,   109,   107,   170,   192,   171,
     169,   107,   151,   156,   151,   151,    87,    88,    89,    92,
      93,    94,   151,    81,   109,   155,   192,   156,   119,   119,
     107,   189,   192,   175,   168,   175,   175,   119,    80,   119,
     156,   156,   156,   156,   156,   156,   119,   156,   154,   185,
     151,   191,   151,   155,   155,   155,   155,   155,   155,   153,
     155,   119,   189,   119,   152
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



