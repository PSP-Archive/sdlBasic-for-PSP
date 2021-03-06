/*
    Name:       eval.h
    Purpose:    evaluates nodes generated by parser for wxBasic
    Author:     David Cuny
    Copyright:  (c) 2001 David Cuny <dcuny@lanset.com>
    Licence:    LGPL
*/

/* control loop flags */
int     exitDoFlag ;
int     exitForFlag ;
int     exitRoutineFlag ;
int     exitWhileFlag ;
int     continueFlag ;


/* comparisons */
enum {
    EQ = 1,
    NE,
    GT,
    LT,
    GE,
    LE
};

/* print flags */
enum {
    PRINT,
    PRINT_TAB,
    PRINT_NEWLINE
};

/* opcodes */
enum {
    OpAdd = 1,
    OpAnd,
    OpArgList,
    OpArrayGet,
    OpArrayPtr,
    OpArraySet,
    OpAssign,
    OpBuiltin,
    OpBuiltinCall,
    OpCase,
    OpCaseCmp,
    OpCaseElse,
    OpCaseRange,
    OpCaseSelect,
    OpClassMethod,
    OpClassMethodCall,
    OpClose,
    OpCmp,
    OpComma,
    OpConcat,
    OpConstGet,
    OpConstSet,
    OpContinue,
    OpDelete,
    OpDestroy,
    OpDiv,
    OpDo,
    OpEnd,
    OpErase,
    OpExitDo,
    OpExitFor,
    OpExitRoutine,
    OpExitWhile,
    OpFloat,
    OpFor,
    OpForEach,
    OpForStep,
    OpFunction,
    OpFunctionCall,
    OpIDiv,
    OpIf,
    OpIfTrue,
    OpIn,
    OpInitArray,
    OpInput,
    OpInt,
    OpInv,
    OpLineInput,
    OpMethod,
    OpMethodCall,
    OpMod,
    OpMul,
    OpNegate,
    OpNew,
    OpNewTmp,
    OpNoOp,
    OpNot,
    OpOpen,
    OpOr,
    OpOrBits,
    OpPower,
    OpPrint,
    OpPrintValue,
    OpReturnValue,
    OpReturnSetValue,
    OpShl,
    OpShr,
    OpString,
    OpSub,
    OpUndefined,
    OpVar,
    OpWhile,
    OpXor
};

/* opcodes 
char *opcodeName[] = {
    "Undefined",
    "OpAdd",
    "OpAnd",
    "OpArgList",
    "OpArrayGet",
    "OpArrayPtr",
    "OpArraySet",
    "OpAssign",
    "OpBuiltin",
    "OpBuiltinCall",
    "OpCase",
    "OpCaseCmp",
    "OpCaseElse",
    "OpCaseRange",
    "OpCaseSelect",
    "OpClassMethod",
    "OpClassMethodCall",
    "OpClose",
    "OpCmp",
    "OpComma",
    "OpConcat",
    "OpConstGet",
    "OpConstSet",
    "OpContinue",
    "OpDelete",
    "OpDestroy",
    "OpDiv",
    "OpDo",
    "OpEnd",
    "OpErase",
    "OpExitDo",
    "OpExitFor",
    "OpExitRoutine",
    "OpExitWhile",
    "OpFloat",
    "OpFor",
    "OpForEach",
    "OpForStep",
    "OpFunction",
    "OpFunctionCall",
    "OpIDiv",
    "OpIf",
    "OpIfTrue",
    "OpIn",
    "OpInitArray",
    "OpInput",
    "OpInt",
    "OpInv",
    "OpLineInput",
    "OpMethod",
    "OpMethodCall",
    "OpMod",
    "OpMul",
    "OpNegate",
    "OpNew",
    "OpNewTmp",
    "OpNoOp",
    "OpNot",
    "OpOpen",
    "OpOr",
    "OpOrBits",
    "OpPower",
    "OpPrint",
    "OpPrintValue",
    "OpReturnValue",
    "OpReturnSetValue",
    "OpShl",
    "OpShr",
    "OpString",
    "OpSub",
    "OpUndefined",
    "OpVar",
    "OpWhile",
    "OpXor"
};
*/

void stringCompare( int op, int popFlag );
void numberCompare( int op, int popFlag );
void stringRangeCompare(void);
void numberRangeCompare(void);
void eval( Node *node );
