/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>
#include <stack>
#include <stdio.h>

#include "helpers.h"
#include "code_gen.h"

using namespace std;

#define YYERROR_VERBOSE 1

extern int yylex();
extern int yyparse();
extern int yylineno;
extern int yyleng;
extern char* yytext;
void yyerror(const char* s);

int offsetValue;
string text;
typeRecord* variableRecord;
vector<int> decDimensionList;
vector<typeRecord*> globalVariables;
eletype resultType;
stack<vector<typeRecord*> > parameterListStack;
vector<typeRecord*> typeRecordList;

int nextNum;
vector<string> functionInstruction;
registerSet temporarySet;

vector<functionEntry*> functionEntryRecord;
functionEntry* activeFunctionPointer;
functionEntry* callFunctionPointer;
vector<string> switchVariable;
vector<functionEntry*> callFunctionPointerList;
vector<string> dimensionList;
int scope;
int found;
bool errorFound;
int numberOfParameters;
string conditionVariable;

vector<pair<string,int>> stringVariable;

#line 119 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 54 "parser.y" /* yacc.c:355  */

    #include "helpers.h"
    #include "code_gen.h"

#line 154 "parser.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    DATAFLOAT = 261,
    DATAINT = 262,
    ID = 263,
    NEWLINE = 264,
    READ = 265,
    PRINT = 266,
    COLON = 267,
    QUESTION = 268,
    DOT = 269,
    LCURLYB = 270,
    RCURLYB = 271,
    LSQUAREB = 272,
    RSQUAREB = 273,
    LPARE = 274,
    RPARE = 275,
    SEMI = 276,
    COMMA = 277,
    ASSIGN = 278,
    IF = 279,
    ELSE = 280,
    CASE = 281,
    BREAK = 282,
    DEFAULT = 283,
    CONTINUE = 284,
    WHILE = 285,
    FOR = 286,
    RETURN = 287,
    SWITCH = 288,
    MAIN = 289,
    LSHIFT = 290,
    RSHIFT = 291,
    PLUSASSIGNMENT = 292,
    MINASSIGNMENT = 293,
    MULASSIGNMENT = 294,
    MODASSIGNMENT = 295,
    DIVASSIGNMENT = 296,
    INCREMENT = 297,
    DECREMENT = 298,
    XOR = 299,
    BITAND = 300,
    BITOR = 301,
    PLUS = 302,
    MINUS = 303,
    DIV = 304,
    MUL = 305,
    MOD = 306,
    NOT = 307,
    AND = 308,
    OR = 309,
    LESSTHAN = 310,
    GREATTHAN = 311,
    LESSEQUAL = 312,
    GREATEQUAL = 313,
    EQUAL = 314,
    NOTEQUAL = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 59 "parser.y" /* yacc.c:355  */

    int intValue;
    float floatValue;
    char *idName;
    int quad;

    struct expression expressionValue;
    struct switchCaser switchCaseValue;
    struct switchTemp switchTempValue;
    struct condition2temp conditionTemp;
    struct whileExpression whileExpressionValue;
    struct statement statementValue;
    struct shortCircuit shortCircuitValue;

#line 242 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 259 "parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   106,   129,   136,   148,   149,   153,   165,
     179,   190,   199,   208,   217,   231,   234,   235,   238,   248,
     249,   250,   251,   254,   280,   293,   294,   297,   298,   301,
     381,   484,   595,   599,   605,   614,   623,   641,   659,   677,
     695,   708,   727,   747,   791,   835,   851,   905,   906,   910,
     916,   922,   931,   937,   945,   945,   955,   963,   969,  1022,
    1030,  1054,  1062,  1070,  1097,  1112,  1112,  1129,  1142,  1142,
    1161,  1168,  1184,  1202,  1254,  1306,  1358,  1410,  1462,  1502,
    1529,  1539,  1547,  1547,  1567,  1567,  1586,  1593,  1593,  1609,
    1616,  1626,  1635,  1647,  1647,  1672,  1681,  1691,  1699,  1705,
    1712,  1717,  1726,  1733,  1749,  1764,  1772,  1778,  1788,  1801,
    1820,  1819,  1867,  1866,  1900,  1911,  1954,  1997,  2010,  2034,
    2058,  2082,  2096,  2103,  2135,  2142,  2149,  2156,  2164,  2177,
    2201,  2227,  2270
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "DATAFLOAT",
  "DATAINT", "ID", "NEWLINE", "READ", "PRINT", "COLON", "QUESTION", "DOT",
  "LCURLYB", "RCURLYB", "LSQUAREB", "RSQUAREB", "LPARE", "RPARE", "SEMI",
  "COMMA", "ASSIGN", "IF", "ELSE", "CASE", "BREAK", "DEFAULT", "CONTINUE",
  "WHILE", "FOR", "RETURN", "SWITCH", "MAIN", "LSHIFT", "RSHIFT",
  "PLUSASSIGNMENT", "MINASSIGNMENT", "MULASSIGNMENT", "MODASSIGNMENT",
  "DIVASSIGNMENT", "INCREMENT", "DECREMENT", "XOR", "BITAND", "BITOR",
  "PLUS", "MINUS", "DIV", "MUL", "MOD", "NOT", "AND", "OR", "LESSTHAN",
  "GREATTHAN", "LESSEQUAL", "GREATEQUAL", "EQUAL", "NOTEQUAL", "$accept",
  "FUNCTION_DEFINATION", "FUNC_HEAD", "RES_ID", "DECL_PLIST", "DECL_PL",
  "DECL_PARAM", "BODY", "STATEMENT_LIST", "VARIABLE_DECLARATION",
  "MAIN_PROG", "MAINFUNCTION", "PROG", "MAIN_HEAD", "D", "T", "L",
  "DEC_ID_ARR", "DEC_BR_DIMLIST", "EXPR1", "EXPR21", "EXPR2", "FUNC_CALL",
  "PARAMLIST", "STATEMENT", "$@1", "PLIST", "$@2", "IFSTMT", "$@3",
  "IFEXP", "ASSIGNMENT", "SWITCHCASE", "TEMP1", "TEMP2", "CASELIST", "$@4",
  "$@5", "$@6", "M3", "LHS", "N3", "FORLOOP", "FOREXP", "$@7", "P3", "Q3",
  "Q4", "ASSIGNMENT1", "M2", "M1", "WHILESTMT", "WHILEEXP", "TP1",
  "BR_DIMLIST", "CONDITION1", "$@8", "CONDITION2", "$@9", "TERM", "FACTOR",
  "ID_ARR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -232

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-232)))

#define YYTABLE_NINF -107

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,   -21,  -232,     8,  -232,    24,    26,  -232,    60,  -232,
      74,    95,    54,    49,   115,  -232,   266,    48,  -232,  -232,
    -232,  -232,   266,  -232,    57,   116,  -232,   120,   121,  -232,
    -232,  -232,   118,   133,   133,  -232,    -2,    17,   122,   123,
      29,    36,    -2,   126,   133,   133,    75,    16,   130,   173,
    -232,   139,  -232,  -232,    67,  -232,  -232,  -232,   134,   127,
    -232,   -12,  -232,  -232,  -232,   135,    97,    99,    43,  -232,
      30,   136,   137,  -232,   147,   141,   151,    -2,   143,   139,
    -232,  -232,    -2,   142,   144,   146,   145,   148,   266,   152,
     153,    -2,  -232,  -232,   155,   149,   158,    -2,  -232,   150,
      -2,  -232,  -232,  -232,  -232,  -232,  -232,    42,  -232,  -232,
      -8,    16,    16,    16,    16,    16,    16,    16,    16,   266,
    -232,    -2,    -2,    -2,    -2,    -2,    -2,   167,   266,  -232,
    -232,    16,    16,    16,  -232,  -232,  -232,    48,  -232,  -232,
     172,  -232,   157,  -232,   175,   165,   169,    -2,    -2,  -232,
    -232,   178,  -232,  -232,   176,  -232,    -2,  -232,   177,  -232,
     188,    43,    43,    69,    69,    69,    69,    69,    69,   193,
    -232,  -232,  -232,  -232,  -232,  -232,   266,   194,   111,   114,
    -232,  -232,  -232,  -232,  -232,   195,  -232,  -232,    -2,  -232,
     199,  -232,  -232,   192,  -232,  -232,   197,   202,  -232,    -2,
      -2,  -232,  -232,  -232,  -232,    -2,   204,  -232,  -232,    99,
    -232,  -232,    35,   198,  -232,     1,   216,   219,  -232,  -232,
    -232,   225,  -232,  -232,   221,   220,  -232,  -232,  -232,   266,
      -2,   228,  -232,   266,   227,  -232,   223,   232,  -232,  -232,
     217,    35,   223,  -232,  -232,    35,  -232
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    26,     0,    22,     0,     0,    21,     0,    17,
       0,     0,     0,     0,     0,     5,     0,     7,     1,    19,
      20,    16,     0,    15,    29,    24,    27,     0,    62,    25,
     126,   124,   131,     0,     0,    54,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
      50,     0,   114,    35,    40,   128,    13,    51,     0,     0,
      57,     0,    49,    98,    52,     0,    72,   109,    45,   117,
     121,     0,     6,     8,     0,     0,     0,     0,    31,     0,
      23,    61,     0,    65,   132,   131,     0,     0,     0,     0,
       0,     0,    56,    59,     0,     0,     0,   100,    99,     0,
       0,   119,   120,   125,   127,   123,    34,   121,     2,    14,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     112,     0,     0,     0,   129,   130,     3,     0,    10,    18,
       0,    30,     0,    28,     0,     0,    47,     0,     0,    63,
      60,     0,   122,    70,     0,   105,     0,    95,     0,    58,
       0,    43,    44,    37,    38,    41,    42,    36,    39,     0,
      78,    74,    75,    76,    73,    77,     0,     0,     0,     0,
     116,   115,   118,     9,    33,     0,   107,    46,     0,    66,
       0,    55,    71,     0,    89,    80,    67,     0,   103,     0,
       0,    32,    64,   108,   104,   100,     0,   101,    92,   111,
     113,    97,    86,     0,    93,     0,     0,     0,   102,    96,
      81,     0,    81,    79,     0,     0,    84,    81,    87,     0,
     100,     0,    82,     0,     0,    91,     0,     0,    88,    69,
       0,    86,     0,    94,    85,    86,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -232,   235,  -232,  -232,  -232,  -232,   109,   -22,  -232,    44,
    -232,   238,  -232,  -232,  -232,     2,  -232,   179,  -232,    59,
     210,    15,  -232,  -232,   211,  -232,  -232,  -232,  -232,  -232,
    -232,   -35,  -232,  -232,  -184,  -231,  -232,  -232,  -232,  -232,
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,   -94,  -232,
      45,  -232,  -232,   196,  -232,  -232,  -232,    62,  -232,   -16,
     -24,   -13
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    71,    72,    73,    48,    49,    50,
       8,     9,    10,    11,    12,    51,    25,    26,    78,    52,
      53,    54,    55,   145,    56,    88,   146,   147,    57,   207,
      58,    59,    60,   206,   226,   217,   237,   231,   233,   205,
      61,   240,    62,    63,   219,   225,   214,   127,    99,   213,
      95,    64,    65,   130,    84,    66,   178,    67,   179,    68,
      69,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    89,    13,   158,    30,    31,    32,    98,   220,    76,
     244,   121,    13,    14,   246,    77,    15,    36,    90,    74,
      86,    87,    30,    31,    32,   122,   123,   124,   125,   126,
      94,   101,   102,   105,   107,    36,    91,    96,   228,    16,
      44,    45,   141,   232,     7,    17,    46,   144,  -102,   221,
      47,    29,     2,   -90,    20,    97,   154,    24,    44,    45,
      18,   215,    98,   216,    46,   160,   151,   -90,   -90,   -90,
     -90,   -90,   134,   135,    76,    23,    -4,     1,     2,     3,
      77,   103,   104,    85,   134,   135,   170,   171,   172,   173,
     174,   175,   131,   132,   133,   161,   162,   169,   107,   107,
     107,   107,   107,   107,   107,   107,   177,   180,   181,   182,
      22,   211,   189,   190,   111,   112,   111,   112,   107,   107,
     107,   193,   113,   114,   115,   116,   117,   118,   163,   164,
     165,   166,   167,   168,    27,    82,   235,    83,    79,    74,
      80,    85,    81,    92,    93,   100,   108,   110,   120,   119,
     128,  -106,  -106,   202,   197,   138,   136,   139,   140,   137,
     142,   148,   -48,    82,   185,   199,   149,   200,   156,   150,
      98,   159,   152,   153,    28,   155,    29,     2,   157,    30,
      31,    32,   176,    33,    34,   187,   107,   107,    35,   -11,
     184,   188,    36,   186,   191,    98,   192,    37,   194,   -11,
      38,   -11,    39,    40,    41,    42,    43,   234,   195,   196,
     198,   238,   204,   201,   241,    44,    45,   203,   208,   212,
     245,    46,   -68,   218,    28,    47,    29,     2,   222,    30,
      31,    32,   227,    33,    34,   223,   229,   243,    35,   -12,
     236,   230,    36,   239,   242,    19,   183,    37,    21,   -12,
      38,   -12,    39,    40,    41,    42,    43,   106,   143,   210,
     109,   209,   129,   224,     0,    44,    45,    28,     0,    29,
       2,    46,    30,    31,    32,    47,    33,    34,     0,     0,
       0,    35,   -12,     0,     0,    36,     0,     0,     0,     0,
      37,     0,     0,    38,     0,    39,    40,    41,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    45,
       0,     0,     0,     0,    46,     0,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      22,    36,     0,    97,     6,     7,     8,    42,     7,    17,
     241,    23,    10,    34,   245,    23,     8,    19,     1,    17,
      33,    34,     6,     7,     8,    37,    38,    39,    40,    41,
       1,    44,    45,    46,    47,    19,    19,     1,   222,    15,
      42,    43,    77,   227,     0,    19,    48,    82,    19,    48,
      52,     3,     4,    23,    10,    19,    91,     8,    42,    43,
       0,    26,    97,    28,    48,   100,    88,    37,    38,    39,
      40,    41,    42,    43,    17,    21,    19,     3,     4,     5,
      23,     6,     7,     8,    42,    43,   121,   122,   123,   124,
     125,   126,    49,    50,    51,   111,   112,   119,   111,   112,
     113,   114,   115,   116,   117,   118,   128,   131,   132,   133,
      15,   205,   147,   148,    47,    48,    47,    48,   131,   132,
     133,   156,    55,    56,    57,    58,    59,    60,   113,   114,
     115,   116,   117,   118,    19,    17,   230,    19,    22,   137,
      20,     8,    21,    21,    21,    19,    16,     8,    21,    15,
      15,    54,    53,   188,   176,     8,    20,    16,     7,    22,
      17,    17,    20,    17,     7,    54,    21,    53,    19,    21,
     205,    21,    20,    20,     1,    20,     3,     4,    20,     6,
       7,     8,    15,    10,    11,    20,   199,   200,    15,    16,
      18,    22,    19,    18,    16,   230,    20,    24,    21,    26,
      27,    28,    29,    30,    31,    32,    33,   229,    20,    16,
      16,   233,    20,    18,   236,    42,    43,    18,    16,    15,
     242,    48,    25,    25,     1,    52,     3,     4,    12,     6,
       7,     8,     7,    10,    11,    16,    15,    20,    15,    16,
      12,    21,    19,    16,    12,    10,   137,    24,    10,    26,
      27,    28,    29,    30,    31,    32,    33,    47,    79,   200,
      49,   199,    66,   218,    -1,    42,    43,     1,    -1,     3,
       4,    48,     6,     7,     8,    52,    10,    11,    -1,    -1,
      -1,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    27,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    62,    63,    64,    70,    71,    72,
      73,    74,    75,    76,    34,     8,    15,    19,     0,    62,
      70,    72,    15,    21,     8,    77,    78,    19,     1,     3,
       6,     7,     8,    10,    11,    15,    19,    24,    27,    29,
      30,    31,    32,    33,    42,    43,    48,    52,    68,    69,
      70,    76,    80,    81,    82,    83,    85,    89,    91,    92,
      93,   101,   103,   104,   112,   113,   116,   118,   120,   121,
     122,    65,    66,    67,    76,    68,    17,    23,    79,    22,
      20,    21,    17,    19,   115,     8,   122,   122,    86,    92,
       1,    19,    21,    21,     1,   111,     1,    19,    92,   109,
      19,   122,   122,     6,     7,   122,    81,   122,    16,    85,
       8,    47,    48,    55,    56,    57,    58,    59,    60,    15,
      21,    23,    37,    38,    39,    40,    41,   108,    15,   114,
     114,    49,    50,    51,    42,    43,    20,    22,     8,    16,
       7,    92,    17,    78,    92,    84,    87,    88,    17,    21,
      21,    68,    20,    20,    92,    20,    19,    20,   109,    21,
      92,   120,   120,    82,    82,    82,    82,    82,    82,    68,
      92,    92,    92,    92,    92,    92,    15,    68,   117,   119,
     121,   121,   121,    67,    18,     7,    18,    20,    22,    92,
      92,    16,    20,    92,    21,    20,    16,    68,    16,    54,
      53,    18,    92,    18,    20,   100,    94,    90,    16,   118,
      80,   109,    15,   110,   107,    26,    28,    96,    25,   105,
       7,    48,    12,    16,   111,   106,    95,     7,    95,    15,
      21,    98,    95,    99,    68,   109,    12,    97,    68,    16,
     102,    68,    12,    20,    96,    68,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    64,    65,    65,    66,    66,
      67,    68,    68,    69,    69,    70,    71,    71,    72,    73,
      73,    73,    73,    74,    75,    76,    76,    77,    77,    78,
      78,    78,    79,    79,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    83,    84,    84,    85,
      85,    85,    85,    85,    86,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    87,    88,    87,    89,    90,    89,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    93,
      94,    95,    97,    96,    98,    96,    96,    99,    96,   100,
     101,   102,   103,   105,   104,   104,   106,   107,   108,   109,
     109,   110,   111,   112,   113,   113,   114,   115,   115,   116,
     117,   116,   119,   118,   118,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     4,     2,     2,     1,     0,     1,     3,
       2,     1,     0,     1,     2,     2,     2,     1,     4,     2,
       2,     1,     1,     4,     2,     1,     1,     1,     3,     1,
       3,     2,     4,     3,     2,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     4,     1,     0,     1,
       1,     1,     1,     2,     0,     4,     2,     1,     3,     2,
       3,     2,     1,     3,     3,     0,     2,     4,     0,    11,
       3,     4,     1,     3,     3,     3,     3,     3,     3,     8,
       0,     0,     0,     8,     0,     7,     0,     0,     5,     0,
       1,     0,     5,     0,    13,     3,     0,     0,     0,     1,
       0,     0,     0,     4,     5,     3,     0,     3,     4,     1,
       0,     5,     0,     5,     1,     3,     3,     1,     3,     2,
       2,     1,     3,     2,     1,     2,     1,     2,     1,     2,
       2,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 97 "parser.y" /* yacc.c:1646  */
    {
        deleteVariableList(activeFunctionPointer, scope);
        activeFunctionPointer = NULL;
        scope = 0;
        string s = "function end";
        gen(functionInstruction, s, nextNum);
    }
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 107 "parser.y" /* yacc.c:1646  */
    {
        int found = 0;
        searchFunc(activeFunctionPointer, functionEntryRecord, found);
        if(found){
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Function " << activeFunctionPointer->name <<  " already declared." << endl;
            errorFound = true;
            delete activeFunctionPointer;
            // cout<<"Function head me activeFunctionPointer deleted"<<endl;
        }   
        else{
            activeFunctionPointer->numOfParam = typeRecordList.size();
            activeFunctionPointer->parameterList = typeRecordList;
            activeFunctionPointer->functionOffset = 0;
            typeRecordList.clear();
            addFunction(activeFunctionPointer, functionEntryRecord);
            scope = 2;
            string s = "function begin _" + activeFunctionPointer->name;
            gen(functionInstruction, s, nextNum);
        }
    }
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 130 "parser.y" /* yacc.c:1646  */
    {
        scope=1;
        activeFunctionPointer = new functionEntry;
        activeFunctionPointer->name = string((yyvsp[0].idName));
        activeFunctionPointer->returnType = resultType;
    }
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 137 "parser.y" /* yacc.c:1646  */
    {
        scope=1;
        activeFunctionPointer = new functionEntry;
        activeFunctionPointer->name = string((yyvsp[0].idName));
        activeFunctionPointer->returnType = NULLVOID;
    }
#line 1591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 154 "parser.y" /* yacc.c:1646  */
    {
        int found = 0;
        typeRecord* pn = NULL;
        searchParameter(variableRecord->name, typeRecordList, found , pn );
        if (found){
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Redeclaration of parameter " << variableRecord->name <<endl;
        } else {
            // cout << "Variable: "<< variableRecord->name << " declared." << endl;
            typeRecordList.push_back(variableRecord);
        }
    }
#line 1607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 166 "parser.y" /* yacc.c:1646  */
    {
        int found = 0;
        typeRecord* pn = NULL;
        searchParameter(variableRecord->name, typeRecordList, found, pn);
        if(found){
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Redeclaration of parameter " << variableRecord->name <<endl;
        } else {
            // cout << "Variable: "<< variableRecord->name << " declared." << endl;
            typeRecordList.push_back(variableRecord);
        }
    }
#line 1623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 180 "parser.y" /* yacc.c:1646  */
    {
        variableRecord = new typeRecord;
        variableRecord->name = string((yyvsp[0].idName));
        variableRecord->type = SIMPLE;
        variableRecord->tag = VARIABLE;
        variableRecord->scope = scope;
        variableRecord->elementType = resultType;
    }
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 191 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        merge((yyval.statementValue).nextList, (yyvsp[0].statementValue).nextList);
        (yyval.statementValue).breakList = new vector<int>;
        merge((yyval.statementValue).breakList, (yyvsp[0].statementValue).breakList);
        (yyval.statementValue).continueList = new vector<int>;
        merge((yyval.statementValue).continueList, (yyvsp[0].statementValue).continueList);
    }
#line 1649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 200 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector<int>;
    }
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 209 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        merge((yyval.statementValue).nextList, (yyvsp[0].statementValue).nextList);
        (yyval.statementValue).breakList = new vector<int>;
        merge((yyval.statementValue).breakList, (yyvsp[0].statementValue).breakList);
        (yyval.statementValue).continueList = new vector<int>;
        merge((yyval.statementValue).continueList, (yyvsp[0].statementValue).continueList);
    }
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 218 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        merge((yyval.statementValue).nextList, (yyvsp[-1].statementValue).nextList);
        merge((yyval.statementValue).nextList, (yyvsp[0].statementValue).nextList);
        (yyval.statementValue).breakList = new vector<int>;
        merge((yyval.statementValue).breakList, (yyvsp[-1].statementValue).breakList);
        merge((yyval.statementValue).breakList, (yyvsp[0].statementValue).breakList);
        (yyval.statementValue).continueList = new vector<int>;
        merge((yyval.statementValue).continueList, (yyvsp[-1].statementValue).continueList);
        merge((yyval.statementValue).continueList, (yyvsp[0].statementValue).continueList);
    }
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 239 "parser.y" /* yacc.c:1646  */
    {
        deleteVariableList(activeFunctionPointer, scope);
        activeFunctionPointer=NULL;
        scope=0;
        string s = "function end";
        gen(functionInstruction, s, nextNum);
    }
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 255 "parser.y" /* yacc.c:1646  */
    {   
        scope=1;
        activeFunctionPointer = new functionEntry;
        activeFunctionPointer->name = string("main");
        activeFunctionPointer->returnType = INTEGER;
        activeFunctionPointer->numOfParam = 0;
        activeFunctionPointer->parameterList.clear();
        activeFunctionPointer->variableList.clear();
        activeFunctionPointer->functionOffset = 0;      ;
        typeRecordList.clear();
        searchFunc(activeFunctionPointer, functionEntryRecord, found);
        if (found) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Function " << activeFunctionPointer->name <<  " already declared." << endl;
            delete activeFunctionPointer;
            activeFunctionPointer = NULL;
        }
        else {
            addFunction(activeFunctionPointer, functionEntryRecord);
            scope = 2; 
            string s = "function begin main";
            gen(functionInstruction, s, nextNum);
        }
    }
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 281 "parser.y" /* yacc.c:1646  */
    {
        patchDataType(resultType, typeRecordList, scope);
        if(scope > 1){
            insertSymTab(typeRecordList, activeFunctionPointer);
        }
        else if(scope == 0){
            insertGlobalVariables(typeRecordList, globalVariables);
        }
        typeRecordList.clear();
    }
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 293 "parser.y" /* yacc.c:1646  */
    { resultType = INTEGER; }
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 294 "parser.y" /* yacc.c:1646  */
    { resultType = FLOATING; }
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 302 "parser.y" /* yacc.c:1646  */
    {
        int found = 0;
        typeRecord* vn = NULL;
        // cout << "Scope : "<<scope<<endl;
        if(activeFunctionPointer!=NULL && scope > 0){
            searchVariable(string((yyvsp[0].idName)), activeFunctionPointer, found, vn, scope);
            if (found) {
                if(vn->isValid==true){
                    cout << BOLD(FRED("ERROR : ")) << "Line no. :" << yylineno << " Variable " << string((yyvsp[0].idName)) << " already declared at same level " << scope << endl ;
                }
                else{
                    if(vn->elementType == resultType){
                        vn->isValid=true;
                        vn->maxDimlistOffset = max(vn->maxDimlistOffset,1);
                        vn->type=SIMPLE;
                    }
                    else {
                        variableRecord = new typeRecord;
                        variableRecord->name = string((yyvsp[0].idName));
                        variableRecord->type = SIMPLE;
                        variableRecord->tag = VARIABLE;
                        variableRecord->scope = scope;
                        variableRecord->isValid=true;
                        variableRecord->maxDimlistOffset=1;
                        typeRecordList.push_back(variableRecord);
                    }
                }
            }
            else if (scope == 2) {
                typeRecord* pn = NULL;
                searchParameter(string((yyvsp[0].idName)), activeFunctionPointer->parameterList, found , pn);
                if (found) {
                    // printf("Line no. %d: Vaiable %s is already declared as a parameter with scope %d\n", yylineno, $1, scope);
                    cout << BOLD(FRED("ERROR : ")) << "Line no. :" << yylineno << " Variable " << string((yyvsp[0].idName)) << " already declared in parameters " << endl ;
                }
                else {
                    variableRecord = new typeRecord;
                    variableRecord->name = string((yyvsp[0].idName));
                    variableRecord->type = SIMPLE;
                    variableRecord->tag = VARIABLE;
                    variableRecord->scope = scope;
                    variableRecord->isValid=true;
                    variableRecord->maxDimlistOffset=1;
                    typeRecordList.push_back(variableRecord);
                }
            }
            else {
                variableRecord = new typeRecord;
                variableRecord->name = string((yyvsp[0].idName));
                variableRecord->type = SIMPLE;
                variableRecord->tag = VARIABLE;
                variableRecord->scope = scope;
                variableRecord->isValid=true;
                variableRecord->maxDimlistOffset=1;
                typeRecordList.push_back(variableRecord);
            }
        }
        else if(scope == 0){
            searchGlobalVariable(string((yyvsp[0].idName)), globalVariables, found, vn, scope);
            if (found) {
                // printf("Variable %s already declared at global level \n", $1);
                cout << BOLD(FRED("ERROR : ")) << "Line no. :" << yylineno << " Variable " << string((yyvsp[0].idName)) << " already declared at global level " << endl ;
            }
            else{
                variableRecord = new typeRecord;
                variableRecord->name = string((yyvsp[0].idName));
                variableRecord->type = SIMPLE;
                variableRecord->tag = VARIABLE;
                variableRecord->scope = scope;
                variableRecord->isValid=true;
                variableRecord->maxDimlistOffset=1;
                // cout<<"variable name: "<<variableRecord->name<<endl;
                typeRecordList.push_back(variableRecord);
            }
        }
        else {
            errorFound = true;
        }
    }
#line 1839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 382 "parser.y" /* yacc.c:1646  */
    {
        int found = 0;
        typeRecord* vn = NULL;
        if(activeFunctionPointer!=NULL){
            searchVariable(string((yyvsp[-2].idName)), activeFunctionPointer, found, vn, scope);
            bool varCreated = false;;
            if (found) {
                if(vn->isValid==true){
                    cout << BOLD(FRED("ERROR : ")) << "Line no. :" << yylineno << " Variable " << string((yyvsp[-2].idName)) << " already declared at same level " << scope << endl ;
                }
                else{
                    if(vn->elementType == resultType){
                        vn->isValid=true;
                        vn->maxDimlistOffset = max(vn->maxDimlistOffset,1);
                        vn->type=SIMPLE;
                        varCreated = true;
                    }
                    else {
                        variableRecord = new typeRecord;
                        variableRecord->name = string((yyvsp[-2].idName));
                        variableRecord->type = SIMPLE;
                        variableRecord->tag = VARIABLE;
                        variableRecord->scope = scope;
                        variableRecord->isValid=true;
                        variableRecord->maxDimlistOffset=1;
                        typeRecordList.push_back(variableRecord);
                        varCreated = true;
                    }
                }
            }
            else if (scope == 2) {
                typeRecord* pn = NULL;
                searchParameter(string((yyvsp[-2].idName)), activeFunctionPointer->parameterList, found , pn);
                if (found) {
                    cout << BOLD(FRED("ERROR : ")) << "Line no. :" << yylineno << " Variable " << string((yyvsp[-2].idName)) << " already declared at parameter level " << endl ;
                } 
                else {
                    variableRecord = new typeRecord;
                    variableRecord->name = string((yyvsp[-2].idName));
                    variableRecord->type = SIMPLE;
                    variableRecord->tag = VARIABLE;
                    variableRecord->scope = scope;
                    variableRecord->maxDimlistOffset=1;
                    variableRecord->isValid=true;
                    typeRecordList.push_back(variableRecord);
                    varCreated = true;
                }
            }
            else {
                variableRecord = new typeRecord;
                variableRecord->name = string((yyvsp[-2].idName));
                variableRecord->type = SIMPLE;
                variableRecord->tag = VARIABLE;
                variableRecord->scope = scope;
                variableRecord->maxDimlistOffset=1;
                variableRecord->isValid=true;
                typeRecordList.push_back(variableRecord);
                varCreated = true;
            }
            if(varCreated){
                if ((yyvsp[0].expressionValue).type == ERRORTYPE) {
                    errorFound = true;
                }
                else if ((yyvsp[0].expressionValue).type == NULLVOID) {
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Cannot assign void to non-void type " << string((yyvsp[-2].idName)) << endl;
                    errorFound = true;
                }
                else {
                    string registerName;
                    if (resultType == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                        registerName = temporarySet.getRegister();
                        string s = registerName + " = convertToInt(" + (*((yyvsp[0].expressionValue).registerName)) + ")";   
                        cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                        gen(functionInstruction, s, nextNum);
                        temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
                    }
                    else if(resultType == FLOATING && ((yyvsp[0].expressionValue).type == INTEGER || (yyvsp[0].expressionValue).type == BOOLEAN)) {
                        registerName = temporarySet.getFloatRegister();
                        string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")";
                        cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                        gen(functionInstruction, s, nextNum);
                        temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
                    }
                    else {
                        registerName = *((yyvsp[0].expressionValue).registerName);
                    }
                    string dataType = elementTypeMapper(resultType);
                    dataType += "_" + to_string(scope);
                    string s =  "_" + string((yyvsp[-2].idName)) + "_" + dataType + " = " + registerName ;
                    gen(functionInstruction, s, nextNum);
                    temporarySet.freeRegister(registerName);
                }   
            }
        }
        else if(scope == 0){
            cout << BOLD(FRED("ERROR : ")) << "Line No " << yylineno << ": ID assignments not allowed in global level : Variable " << string((yyvsp[-2].idName)) << endl;
            errorFound = true;
        }
        else {
            errorFound = true;
        }
    }
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 485 "parser.y" /* yacc.c:1646  */
    {  
        if (activeFunctionPointer != NULL) {
            int found = 0;
            typeRecord* vn = NULL;
            searchVariable(string((yyvsp[-1].idName)), activeFunctionPointer, found, vn,scope); 
            if (found) {
                if(vn->isValid==true){
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Variable " << string((yyvsp[-1].idName)) << " already declared at same level " << scope << endl;
                }
                else{
                    if(vn->elementType == resultType){
                        vn->isValid=true;
                        int a=1;
                        for(auto it : decDimensionList){
                            a*=(it);
                        }
                        vn->maxDimlistOffset = max(vn->maxDimlistOffset,a);
                        if(vn->type==ARRAY){
                            vn->dimensionList.clear();
                        }
                        vn->type=ARRAY;
                        vn->dimensionList = decDimensionList;
                    }
                    else {
                        variableRecord = new typeRecord;
                        variableRecord->name = string((yyvsp[-1].idName));
                        variableRecord->type = ARRAY;
                        variableRecord->tag = VARIABLE;
                        variableRecord->scope = scope;
                        variableRecord->dimensionList = decDimensionList;
                        variableRecord->isValid=true;
                        int a=1;
                        for(auto it : decDimensionList){
                            a*=(it);
                        }
                        variableRecord->maxDimlistOffset = a;
                        typeRecordList.push_back(variableRecord);
                    }
                }
            }
            else if (scope == 2) {
                typeRecord* pn = NULL;
                searchParameter(string((yyvsp[-1].idName)), activeFunctionPointer->parameterList, found, pn);
                if (found) {
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Variable " << string((yyvsp[-1].idName)) << " already declared at parameter level " << endl;
                } 
                else {
                    variableRecord = new typeRecord;
                    variableRecord->name = string((yyvsp[-1].idName));
                    variableRecord->type = ARRAY;
                    variableRecord->tag = VARIABLE;
                    variableRecord->scope = scope;
                    variableRecord->dimensionList = decDimensionList;
                    variableRecord->isValid=true;
                    int a=1;
                    for(auto it : decDimensionList){
                        a*=(it);
                    }
                    variableRecord->maxDimlistOffset = a;
                    typeRecordList.push_back(variableRecord);
                }
            }
            else{
                variableRecord = new typeRecord;
                variableRecord->name = string((yyvsp[-1].idName));
                variableRecord->type = ARRAY;
                variableRecord->tag = VARIABLE;
                variableRecord->scope = scope;
                variableRecord->dimensionList = decDimensionList;
                variableRecord->isValid=true;
                int a=1;
                for(auto it : decDimensionList){
                    a*=(it);
                }
                variableRecord->maxDimlistOffset = a;
                typeRecordList.push_back(variableRecord);
            }
            // decDimensionList.clear();
        }
        else if(scope == 0){
            typeRecord* vn = NULL;
            searchGlobalVariable(string((yyvsp[-1].idName)), globalVariables, found, vn, scope);
            if (found) {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Variable " << string((yyvsp[-1].idName)) << " already declared at global level " << endl;
            }
            else{
                variableRecord = new typeRecord;
                variableRecord->name = string((yyvsp[-1].idName));
                variableRecord->type = ARRAY;
                variableRecord->tag = VARIABLE;
                variableRecord->scope = scope;
                variableRecord->dimensionList = decDimensionList;
                variableRecord->isValid=true;
                int a=1;
                for(auto it : decDimensionList){
                    a*=(it);
                }
                variableRecord->maxDimlistOffset = a;
                // cout<<"variable name: "<<variableRecord->name<<endl;
                typeRecordList.push_back(variableRecord);   
            }
        }   
        else{
            errorFound = 1;
        }
        decDimensionList.clear();
    }
#line 2058 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 596 "parser.y" /* yacc.c:1646  */
    {
        decDimensionList.push_back(atoi((yyvsp[-1].idName)));
    }
#line 2066 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 600 "parser.y" /* yacc.c:1646  */
    {
        decDimensionList.push_back(atoi((yyvsp[-1].idName)));
    }
#line 2074 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 606 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expressionValue).type = (yyvsp[0].expressionValue).type;
        if ((yyvsp[0].expressionValue).type != ERRORTYPE && (yyvsp[0].expressionValue).type != NULLVOID) {
            (yyval.expressionValue).registerName = (yyvsp[0].expressionValue).registerName;
            string s = (*((yyval.expressionValue).registerName)) + " = ~" + (*((yyvsp[0].expressionValue).registerName));   
            gen(functionInstruction, s, nextNum);
        }
    }
#line 2087 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 615 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expressionValue).type = (yyvsp[0].expressionValue).type;
        if ((yyvsp[0].expressionValue).type != ERRORTYPE && (yyvsp[0].expressionValue).type != NULLVOID) {
            (yyval.expressionValue).registerName = (yyvsp[0].expressionValue).registerName;    
        }
    }
#line 2098 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 624 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE;
        }
        else if((yyvsp[-2].expressionValue).type == NULLVOID || (yyvsp[0].expressionValue).type == NULLVOID){
            (yyval.expressionValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else {
            (yyval.expressionValue).type = BOOLEAN;
            (yyval.expressionValue).registerName = new string(temporarySet.getRegister());     
            string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " == " + (*((yyvsp[0].expressionValue).registerName))   ;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
            temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));  
        }   
    }
#line 2120 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 642 "parser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE){
            (yyval.expressionValue).type = ERRORTYPE;
        }
        else if((yyvsp[-2].expressionValue).type == NULLVOID || (yyvsp[0].expressionValue).type == NULLVOID){
            (yyval.expressionValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            (yyval.expressionValue).type = BOOLEAN;
            (yyval.expressionValue).registerName = new string(temporarySet.getRegister());     
            string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " < " + (*((yyvsp[0].expressionValue).registerName));   
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
            temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));  
        }   
    }
#line 2142 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 660 "parser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE){
            (yyval.expressionValue).type = ERRORTYPE;
        }
        else if((yyvsp[-2].expressionValue).type == NULLVOID || (yyvsp[0].expressionValue).type == NULLVOID){
            (yyval.expressionValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            (yyval.expressionValue).type = BOOLEAN;
            (yyval.expressionValue).registerName = new string(temporarySet.getRegister());     
            string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " > " + (*((yyvsp[0].expressionValue).registerName));   
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
            temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));  
        }   
    }
#line 2164 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 678 "parser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE){
            (yyval.expressionValue).type = ERRORTYPE;
        }
        else if((yyvsp[-2].expressionValue).type == NULLVOID || (yyvsp[0].expressionValue).type == NULLVOID){
            (yyval.expressionValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            (yyval.expressionValue).type = BOOLEAN;
            (yyval.expressionValue).registerName = new string(temporarySet.getRegister());     
            string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " != " + (*((yyvsp[0].expressionValue).registerName));   
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
            temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));  
        }   
    }
#line 2186 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 696 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expressionValue).type = (yyvsp[0].expressionValue).type; 
        if((yyval.expressionValue).type == ERRORTYPE){
            errorFound = true;
        }
        else{
            if((yyvsp[0].expressionValue).type != NULLVOID){
                (yyval.expressionValue).registerName = new string(*((yyvsp[0].expressionValue).registerName)); 
                delete (yyvsp[0].expressionValue).registerName; 
            }
        }    
    }
#line 2203 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 709 "parser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE){
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else if((yyvsp[-2].expressionValue).type == NULLVOID || (yyvsp[0].expressionValue).type == NULLVOID){
            (yyval.expressionValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            (yyval.expressionValue).type = BOOLEAN;
            (yyval.expressionValue).registerName = new string(temporarySet.getRegister());     
            string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " <= " + (*((yyvsp[0].expressionValue).registerName));   
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
            temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));  
        }   
    }
#line 2226 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 728 "parser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE){
            (yyval.expressionValue).type = ERRORTYPE;
        }
        else if((yyvsp[-2].expressionValue).type == NULLVOID || (yyvsp[0].expressionValue).type == NULLVOID){
            (yyval.expressionValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            (yyval.expressionValue).type = BOOLEAN;
            (yyval.expressionValue).registerName = new string(temporarySet.getRegister());     
            string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " >= " + (*((yyvsp[0].expressionValue).registerName));  
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
            temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));  
        }   
    }
#line 2248 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 748 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE; 
            errorFound = true; 
        }
        else {
            if (arithmeticCompatible((yyvsp[-2].expressionValue).type, (yyvsp[0].expressionValue).type)) {
                (yyval.expressionValue).type = compareTypes((yyvsp[-2].expressionValue).type,(yyvsp[0].expressionValue).type);

                if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[-2].expressionValue).registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
                    (yyvsp[-2].expressionValue).registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }
                else if ((yyvsp[-2].expressionValue).type == FLOATING && (yyvsp[0].expressionValue).type == INTEGER) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
                    (yyvsp[0].expressionValue).registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }

                if ((yyval.expressionValue).type == INTEGER) 
                    (yyval.expressionValue).registerName = new string(temporarySet.getRegister());
                else
                    (yyval.expressionValue).registerName = new string(temporarySet.getFloatRegister());
                    
                string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " + " + (*((yyvsp[0].expressionValue).registerName));;   
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));   
            }
            else {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << "Type mismatch in expression" << endl;
                (yyval.expressionValue).type = ERRORTYPE;
            }
        }
    }
#line 2296 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 792 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;  
        }
        else {
            if (arithmeticCompatible((yyvsp[-2].expressionValue).type, (yyvsp[0].expressionValue).type)) {
                (yyval.expressionValue).type = compareTypes((yyvsp[-2].expressionValue).type,(yyvsp[0].expressionValue).type);

                if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[-2].expressionValue).registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
                    (yyvsp[-2].expressionValue).registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }
                else if ((yyvsp[-2].expressionValue).type == FLOATING && (yyvsp[0].expressionValue).type == INTEGER) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
                    (yyvsp[0].expressionValue).registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }

                if ((yyval.expressionValue).type == INTEGER) 
                    (yyval.expressionValue).registerName = new string(temporarySet.getRegister());
                else
                    (yyval.expressionValue).registerName = new string(temporarySet.getFloatRegister());
                    
                string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " - " + (*((yyvsp[0].expressionValue).registerName));;   
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));   
            }
            else {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << "Type mismatch in expression" << endl;
                (yyval.expressionValue).type = ERRORTYPE;
            }
        }
    }
#line 2344 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 836 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expressionValue).type = (yyvsp[0].expressionValue).type; 
        if ((yyvsp[0].expressionValue).type == ERRORTYPE) {
            errorFound = true;
        }
        else {
            if((yyvsp[0].expressionValue).type!= NULLVOID){
                (yyval.expressionValue).registerName = new string(*((yyvsp[0].expressionValue).registerName)); 
                delete (yyvsp[0].expressionValue).registerName;
            }         
        } 
    }
#line 2361 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 852 "parser.y" /* yacc.c:1646  */
    {
        callFunctionPointer = new functionEntry;
        callFunctionPointer->name = string((yyvsp[-3].idName));
        callFunctionPointer->parameterList = typeRecordList;
        callFunctionPointer->numOfParam = typeRecordList.size();
        int found = 0;
        // printFunction(activeFunctionPointer);
        // printFunction(callFunctionPointer);
        int vfound=0;
        typeRecord* vn;
        searchVariable(callFunctionPointer->name,activeFunctionPointer,vfound,vn,scope);
        if (vfound) {
            (yyval.expressionValue).type = ERRORTYPE;
            cout<< BOLD(FRED("ERROR : ")) << "Line no." << yylineno << ": called object "<< callFunctionPointer->name << " is not a function or function pointer"<< endl;
        }
        else {
            compareFunc(callFunctionPointer,functionEntryRecord,found);
            (yyval.expressionValue).type = ERRORTYPE;
            if (found == 0) {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << "No function with name " << string((yyvsp[-3].idName)) << " exists" << endl;
            }
            else if (found == -1) {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << "call parameter list does not match with defined paramters of function " << string((yyvsp[-3].idName)) << endl;
            }
            else {
                (yyval.expressionValue).type = callFunctionPointer->returnType;
                if(callFunctionPointer->returnType == INTEGER){
                    (yyval.expressionValue).registerName = new string(temporarySet.getRegister());
                    gen(functionInstruction, "refparam " + (*((yyval.expressionValue).registerName)), nextNum);
                    gen(functionInstruction, "call _" + callFunctionPointer->name + ", " + to_string(typeRecordList.size() + 1 ), nextNum);
                }
                else if(callFunctionPointer->returnType == FLOATING){
                    (yyval.expressionValue).registerName = new string(temporarySet.getFloatRegister());
                    gen(functionInstruction, "refparam " + (*((yyval.expressionValue).registerName)), nextNum);
                    gen(functionInstruction, "call _" + callFunctionPointer->name + ", " + to_string(typeRecordList.size() + 1 ), nextNum);
                }
                else if (callFunctionPointer->returnType == NULLVOID) {
                    (yyval.expressionValue).registerName = NULL;
                    gen(functionInstruction, "call _" + callFunctionPointer->name + ", " + to_string(typeRecordList.size()), nextNum);
                }
                else {
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Illegal return type of function " << callFunctionPointer->name << endl;
                }
            }
        }
        typeRecordList.clear();
        typeRecordList.swap(parameterListStack.top());
        parameterListStack.pop();
    }
#line 2417 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 906 "parser.y" /* yacc.c:1646  */
    {parameterListStack.push(typeRecordList); typeRecordList.clear();}
#line 2423 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 911 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
    }
#line 2433 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 917 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
    }
#line 2443 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 923 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
        merge((yyval.statementValue).continueList, (yyvsp[0].statementValue).continueList);
        merge((yyval.statementValue).breakList, (yyvsp[0].statementValue).breakList);

    }
#line 2456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 932 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
    }
#line 2466 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 938 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
        if ((yyvsp[-1].expressionValue).type != NULLVOID && (yyvsp[-1].expressionValue).type != ERRORTYPE)
            temporarySet.freeRegister(*((yyvsp[-1].expressionValue).registerName));
    }
#line 2478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 945 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2484 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 946 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
        deleteVariableList(activeFunctionPointer, scope);
        scope--;
        merge((yyval.statementValue).continueList, (yyvsp[-1].statementValue).continueList);
        merge((yyval.statementValue).breakList, (yyvsp[-1].statementValue).breakList);
    }
#line 2498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 956 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
        (yyval.statementValue).breakList->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
    }
#line 2510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 964 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
    }
#line 2520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 970 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
        if ((yyvsp[-1].expressionValue).type != ERRORTYPE && activeFunctionPointer != NULL) {
            if (activeFunctionPointer->returnType == NULLVOID && (yyvsp[-1].expressionValue).type != NULLVOID) {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": function " << activeFunctionPointer->name << " has void return type not " << (yyvsp[-1].expressionValue).type << endl;
            }
            else if (activeFunctionPointer->returnType != NULLVOID && (yyvsp[-1].expressionValue).type == NULLVOID) {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": function " << activeFunctionPointer->name << " has non-void return type" << endl;
            }
            else {
                string s;
                if (activeFunctionPointer->returnType != NULLVOID && (yyvsp[-1].expressionValue).type != NULLVOID) {
                    if ((yyvsp[-1].expressionValue).type == INTEGER && activeFunctionPointer->returnType == FLOATING)  {
                        string floatReg = temporarySet.getFloatRegister();
                        s = floatReg + " = " + "convertToFloat(" + *((yyvsp[-1].expressionValue).registerName) + ")";
                        cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                        gen(functionInstruction, s, nextNum);
                        s = "return " + floatReg;
                        gen(functionInstruction, s, nextNum);
                        temporarySet.freeRegister(*((yyvsp[-1].expressionValue).registerName));
                        temporarySet.freeRegister(floatReg);
                    }
                    else if ((yyvsp[-1].expressionValue).type == FLOATING && activeFunctionPointer->returnType == INTEGER) {
                        string intRegister = temporarySet.getRegister();
                        s = intRegister + " = " + "convertToInt(" + *((yyvsp[-1].expressionValue).registerName) + ")";
                        cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                        gen(functionInstruction, s, nextNum);
                        s = "return " + intRegister;
                        gen(functionInstruction, s, nextNum);
                        temporarySet.freeRegister(*((yyvsp[-1].expressionValue).registerName));
                        temporarySet.freeRegister(intRegister);
                    }
                    else {
                        s = "return " + *((yyvsp[-1].expressionValue).registerName);
                        gen(functionInstruction, s, nextNum);
                        temporarySet.freeRegister(*((yyvsp[-1].expressionValue).registerName));
                    }
                }
                else if (activeFunctionPointer->returnType == NULLVOID && (yyvsp[-1].expressionValue).type == NULLVOID) {
                    s = "return";
                    gen(functionInstruction, s, nextNum);
                }
                else {
                    errorFound = 1;
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Exactly one of function " << activeFunctionPointer->name << "and this return statement has void return type" << endl;
                    if ((yyvsp[-1].expressionValue).type != NULLVOID) temporarySet.freeRegister(*((yyvsp[-1].expressionValue).registerName));
                }
            }
        }
    }
#line 2577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1023 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
        (yyval.statementValue).continueList->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
    }
#line 2589 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1031 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
        if((yyvsp[-1].expressionValue).type == ERRORTYPE){
            errorFound = true;
        }
        else{
            string registerName;
            if ((yyvsp[-1].expressionValue).type == INTEGER){
                registerName = temporarySet.getRegister();
            }
            else {
                registerName = temporarySet.getFloatRegister();
            }
            string s = registerName + " = " + (*((yyvsp[-1].expressionValue).registerName)) ;
            gen(functionInstruction, s, nextNum);
            s = "print " + registerName;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(registerName);
            if ((yyvsp[-1].expressionValue).offsetRegName != NULL) temporarySet.freeRegister(*((yyvsp[-1].expressionValue).offsetRegName));
        }
    }
#line 2617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1055 "parser.y" /* yacc.c:1646  */
    {
        errorFound = 1;
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
        cout << BOLD(FRED("ERROR : ")) << FYEL("Line no. " + to_string(yylineno) + ": Syntax error") << endl;
    }
#line 2629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1063 "parser.y" /* yacc.c:1646  */
    {
        errorFound = 1;
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
        cout << BOLD(FRED("ERROR : ")) << FYEL("Line no. " + to_string(yylineno) + ": Syntax error") << endl;
    }
#line 2641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1071 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList = new vector <int>;
        if((yyvsp[-1].expressionValue).type == ERRORTYPE){
            errorFound = true;
        }
        else{
            string registerName;
            if ((yyvsp[-1].expressionValue).type == INTEGER){
                registerName = temporarySet.getRegister();
            }
            else {
                registerName = temporarySet.getFloatRegister();
            }
            string s;
            s = "read " + registerName;
            gen(functionInstruction, s, nextNum);
            s = (*((yyvsp[-1].expressionValue).registerName)) + " = " +  registerName;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(registerName);
            if ((yyvsp[-1].expressionValue).offsetRegName != NULL) temporarySet.freeRegister(*((yyvsp[-1].expressionValue).offsetRegName));
        }
    }
#line 2670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1098 "parser.y" /* yacc.c:1646  */
    {
        variableRecord = new typeRecord;
        variableRecord->elementType = (yyvsp[0].expressionValue).type;
        if ((yyvsp[0].expressionValue).type == ERRORTYPE) {
            errorFound = true;
        }
        else {
            variableRecord->name = *((yyvsp[0].expressionValue).registerName);
            variableRecord->type = SIMPLE;
            gen(functionInstruction, "param " +  *((yyvsp[0].expressionValue).registerName), nextNum);
            temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
        }
        typeRecordList.push_back(variableRecord);
    }
#line 2689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1112 "parser.y" /* yacc.c:1646  */
    {parameterListStack.push(typeRecordList); typeRecordList.clear();}
#line 2695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1113 "parser.y" /* yacc.c:1646  */
    {
        variableRecord = new typeRecord;
        variableRecord->elementType = (yyvsp[0].expressionValue).type;
        if ((yyvsp[0].expressionValue).type == ERRORTYPE) {
            errorFound = true;
        }
        else {
            variableRecord->name = *((yyvsp[0].expressionValue).registerName);
            variableRecord->type = SIMPLE; 
            gen(functionInstruction, "param " +  *((yyvsp[0].expressionValue).registerName), nextNum);   
            temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
        }
        typeRecordList.push_back(variableRecord);
    }
#line 2714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1130 "parser.y" /* yacc.c:1646  */
    {
        deleteVariableList(activeFunctionPointer,scope);
        scope--;
        (yyval.statementValue).nextList= new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList= new vector<int>;
        merge((yyval.statementValue).nextList, (yyvsp[-3].whileExpressionValue).falseList);
        merge((yyval.statementValue).breakList, (yyvsp[-1].statementValue).breakList);
        merge((yyval.statementValue).continueList, (yyvsp[-1].statementValue).continueList);
        backPatch((yyval.statementValue).nextList,nextNum,functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
    }
#line 2731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1142 "parser.y" /* yacc.c:1646  */
    {deleteVariableList(activeFunctionPointer,scope);}
#line 2737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1143 "parser.y" /* yacc.c:1646  */
    {
        deleteVariableList(activeFunctionPointer,scope);
        scope--;
        (yyval.statementValue).nextList= new vector<int>;
        (yyval.statementValue).breakList = new vector<int>;
        (yyval.statementValue).continueList= new vector<int>;
        backPatch((yyvsp[-10].whileExpressionValue).falseList,(yyvsp[-3].quad),functionInstruction);
        merge((yyval.statementValue).nextList,(yyvsp[-5].statementValue).nextList );
        backPatch((yyval.statementValue).nextList,nextNum,functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
        merge((yyval.statementValue).breakList, (yyvsp[-8].statementValue).breakList);
        merge((yyval.statementValue).continueList, (yyvsp[-8].statementValue).continueList);
        merge((yyval.statementValue).breakList, (yyvsp[-1].statementValue).breakList);
        merge((yyval.statementValue).continueList, (yyvsp[-1].statementValue).continueList);
    }
#line 2757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1162 "parser.y" /* yacc.c:1646  */
    {
        errorFound = 1;
        (yyval.whileExpressionValue).falseList = new vector <int>;
        cout << BOLD(FRED("ERROR : ")) << FYEL("Line no. " + to_string(yylineno) + ": Syntax error in if, discarding tokens till RPARE") << endl;
        scope++;
    }
#line 2768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1169 "parser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].expressionValue).type != ERRORTYPE && (yyvsp[-1].expressionValue).type!=NULLVOID){
            (yyval.whileExpressionValue).falseList = new vector <int>;
            (yyval.whileExpressionValue).falseList->push_back(nextNum);
            if((yyvsp[-1].expressionValue).type == NULLVOID){
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << "condition in if statement can't be empty" << endl;
                errorFound=true;
            }
            gen(functionInstruction, "if "+ (*((yyvsp[-1].expressionValue).registerName)) + " == 0 goto L", nextNum);
            scope++;
            temporarySet.freeRegister(*((yyvsp[-1].expressionValue).registerName));
        } 
    }
#line 2786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1185 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expressionValue).type = (yyvsp[0].shortCircuitValue).type;
        if((yyval.expressionValue).type != ERRORTYPE && (yyval.expressionValue).type != NULLVOID) {
            (yyval.expressionValue).registerName = (yyvsp[0].shortCircuitValue).registerName;
            if((yyvsp[0].shortCircuitValue).jumpList!=NULL){
                vector<int>* queryList = new vector<int>;
                queryList->push_back(nextNum);
                gen(functionInstruction,"goto L",nextNum);
                backPatch((yyvsp[0].shortCircuitValue).jumpList, nextNum, functionInstruction);
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
                gen(functionInstruction,(*((yyval.expressionValue).registerName)) + " = 1",nextNum) ;
                backPatch(queryList,nextNum,functionInstruction);
                queryList->clear();
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
            }
        }
    }
#line 2808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1203 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else if ((yyvsp[0].expressionValue).type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *((yyvsp[-2].expressionValue).registerName) << endl;
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else {
            (yyval.expressionValue).type = (yyvsp[-2].expressionValue).type;
            string registerName;
            if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expressionValue).registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else if((yyvsp[-2].expressionValue).type == FLOATING && ((yyvsp[0].expressionValue).type == INTEGER || (yyvsp[0].expressionValue).type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else {
                registerName = *((yyvsp[0].expressionValue).registerName);
            }
            string s, temporaryRegister;
            if((yyvsp[-2].expressionValue).type == INTEGER){
                temporaryRegister = temporarySet.getRegister();
                s = temporaryRegister + " = " + (*((yyvsp[-2].expressionValue).registerName));
                gen(functionInstruction, s, nextNum);
            }
            else{
                temporaryRegister = temporarySet.getFloatRegister();
                s = temporaryRegister + " = " + (*((yyvsp[-2].expressionValue).registerName));   
                gen(functionInstruction, s, nextNum);
            }
            s = registerName + " = " + registerName + " % " + temporaryRegister;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(temporaryRegister);
            s = (*((yyvsp[-2].expressionValue).registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            (yyval.expressionValue).registerName = new string(registerName);
            if ((yyvsp[-2].expressionValue).offsetRegName != NULL) temporarySet.freeRegister(*((yyvsp[-2].expressionValue).offsetRegName));
        }
    }
#line 2864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1255 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else if ((yyvsp[0].expressionValue).type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *((yyvsp[-2].expressionValue).registerName) << endl;
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else {
            (yyval.expressionValue).type = (yyvsp[-2].expressionValue).type;
            string registerName;
            if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expressionValue).registerName)) + ")";  
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else if((yyvsp[-2].expressionValue).type == FLOATING && ((yyvsp[0].expressionValue).type == INTEGER || (yyvsp[0].expressionValue).type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else {
                registerName = *((yyvsp[0].expressionValue).registerName);
            }
            string s, temporaryRegister;
            if((yyvsp[-2].expressionValue).type == INTEGER){
                temporaryRegister = temporarySet.getRegister();
                s = temporaryRegister + " = " + (*((yyvsp[-2].expressionValue).registerName));
                gen(functionInstruction, s, nextNum);
            }
            else{
                temporaryRegister = temporarySet.getFloatRegister();
                s = temporaryRegister + " = " + (*((yyvsp[-2].expressionValue).registerName));   
                gen(functionInstruction, s, nextNum);
            }
            s = registerName + " = " + registerName + " + " + temporaryRegister;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(temporaryRegister);
            s = (*((yyvsp[-2].expressionValue).registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            (yyval.expressionValue).registerName = new string(registerName);
            if ((yyvsp[-2].expressionValue).offsetRegName != NULL) temporarySet.freeRegister(*((yyvsp[-2].expressionValue).offsetRegName));
        }
    }
#line 2920 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1307 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else if ((yyvsp[0].expressionValue).type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *((yyvsp[-2].expressionValue).registerName) << endl;
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else {
            (yyval.expressionValue).type = (yyvsp[-2].expressionValue).type;
            string registerName;
            if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expressionValue).registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else if((yyvsp[-2].expressionValue).type == FLOATING && ((yyvsp[0].expressionValue).type == INTEGER || (yyvsp[0].expressionValue).type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")"; 
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else {
                registerName = *((yyvsp[0].expressionValue).registerName);
            }
            string s, temporaryRegister;
            if((yyvsp[-2].expressionValue).type == INTEGER){
                temporaryRegister = temporarySet.getRegister();
                s = temporaryRegister + " = " + (*((yyvsp[-2].expressionValue).registerName));
                gen(functionInstruction, s, nextNum);
            }
            else{
                temporaryRegister = temporarySet.getFloatRegister();
                s = temporaryRegister + " = " + (*((yyvsp[-2].expressionValue).registerName));   
                gen(functionInstruction, s, nextNum);
            }
            s = registerName + " = " + registerName + " - " + temporaryRegister;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(temporaryRegister);
            s = (*((yyvsp[-2].expressionValue).registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            (yyval.expressionValue).registerName = new string(registerName);
            if ((yyvsp[-2].expressionValue).offsetRegName != NULL) temporarySet.freeRegister(*((yyvsp[-2].expressionValue).offsetRegName));
        }
    }
#line 2976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1359 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else if ((yyvsp[0].expressionValue).type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *((yyvsp[-2].expressionValue).registerName) << endl;
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else {
            (yyval.expressionValue).type = (yyvsp[-2].expressionValue).type;
            string registerName;
            if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expressionValue).registerName)) + ")"; 
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else if((yyvsp[-2].expressionValue).type == FLOATING && ((yyvsp[0].expressionValue).type == INTEGER || (yyvsp[0].expressionValue).type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")";  
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else {
                registerName = *((yyvsp[0].expressionValue).registerName);
            }
            string s, temporaryRegister;
            if((yyvsp[-2].expressionValue).type == INTEGER){
                temporaryRegister = temporarySet.getRegister();
                s = temporaryRegister + " = " + (*((yyvsp[-2].expressionValue).registerName));
                gen(functionInstruction, s, nextNum);
            }
            else{
                temporaryRegister = temporarySet.getFloatRegister();
                s = temporaryRegister + " = " + (*((yyvsp[-2].expressionValue).registerName));   
                gen(functionInstruction, s, nextNum);
            }
            s = registerName + " = " + registerName + " * " + temporaryRegister;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(temporaryRegister);
            s = (*((yyvsp[-2].expressionValue).registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            (yyval.expressionValue).registerName = new string(registerName);
            if ((yyvsp[-2].expressionValue).offsetRegName != NULL) temporarySet.freeRegister(*((yyvsp[-2].expressionValue).offsetRegName));
        }
    }
#line 3032 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1411 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else if ((yyvsp[0].expressionValue).type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *((yyvsp[-2].expressionValue).registerName) << endl;
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else {
            (yyval.expressionValue).type = (yyvsp[-2].expressionValue).type;
            string registerName;
            if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expressionValue).registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else if((yyvsp[-2].expressionValue).type == FLOATING && ((yyvsp[0].expressionValue).type == INTEGER || (yyvsp[0].expressionValue).type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else {
                registerName = *((yyvsp[0].expressionValue).registerName);
            }
            string s, temporaryRegister;
            if((yyvsp[-2].expressionValue).type == INTEGER){
                temporaryRegister = temporarySet.getRegister();
                s = temporaryRegister + " = " + (*((yyvsp[-2].expressionValue).registerName));
                gen(functionInstruction, s, nextNum);
            }
            else{
                temporaryRegister = temporarySet.getFloatRegister();
                s = temporaryRegister + " = " + (*((yyvsp[-2].expressionValue).registerName));   
                gen(functionInstruction, s, nextNum);
            }
            s = registerName + " = " + registerName + " / " + temporaryRegister;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(temporaryRegister);
            s = (*((yyvsp[-2].expressionValue).registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            (yyval.expressionValue).registerName = new string(registerName);
            if ((yyvsp[-2].expressionValue).offsetRegName != NULL) temporarySet.freeRegister(*((yyvsp[-2].expressionValue).offsetRegName));
        }
    }
#line 3088 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1463 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else if ((yyvsp[0].expressionValue).type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *((yyvsp[-2].expressionValue).registerName) << endl;
            (yyval.expressionValue).type = ERRORTYPE;
            errorFound = true;
        }
        else {
            (yyval.expressionValue).type = (yyvsp[-2].expressionValue).type;
            string registerName;
            if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expressionValue).registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else if((yyvsp[-2].expressionValue).type == FLOATING && ((yyvsp[0].expressionValue).type == INTEGER || (yyvsp[0].expressionValue).type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
            }
            else {
                registerName = *((yyvsp[0].expressionValue).registerName);
            }
            string s = (*((yyvsp[-2].expressionValue).registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            (yyval.expressionValue).registerName = new string(registerName);
            if ((yyvsp[-2].expressionValue).offsetRegName != NULL) temporarySet.freeRegister(*((yyvsp[-2].expressionValue).offsetRegName));
        }
    }
#line 3130 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1503 "parser.y" /* yacc.c:1646  */
    {
        deleteVariableList(activeFunctionPointer,scope);
        scope--;

        int q=nextNum;
        vector<int>* queryList = new vector<int>;
        queryList->push_back(q);
        gen(functionInstruction, "goto L", nextNum);
        backPatch((yyvsp[-3].whileExpressionValue).falseList, nextNum, functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
        reverse((yyvsp[-1].switchCaseValue).casePair->begin(), (yyvsp[-1].switchCaseValue).casePair->end());
        for(auto it : *((yyvsp[-1].switchCaseValue).casePair)){
            if(it.first == "default"){
                gen(functionInstruction, "goto L"+to_string(it.second), nextNum);
            }
            else{
                gen(functionInstruction, "if "+ (*((yyvsp[-5].expressionValue).registerName)) +" == "+ it.first + " goto L" + to_string(it.second), nextNum);
            }
        }
        (yyvsp[-1].switchCaseValue).casePair->clear();
        backPatch(queryList, nextNum, functionInstruction);
        backPatch((yyvsp[-1].switchCaseValue).breakList, nextNum, functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
    }
#line 3159 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1530 "parser.y" /* yacc.c:1646  */
    {
        (yyval.whileExpressionValue).begin=nextNum;
        (yyval.whileExpressionValue).falseList = new vector<int>;
        (yyval.whileExpressionValue).falseList->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
        scope++;
    }
#line 3171 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1540 "parser.y" /* yacc.c:1646  */
    {
        (yyval.switchTempValue).casePair = new vector<pair<string,int>>;

    }
#line 3180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1547 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[0].switchTempValue).casePair->push_back(make_pair("-"+string((yyvsp[-1].idName)), nextNum));
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
        }
#line 3189 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1552 "parser.y" /* yacc.c:1646  */
    {
        (yyval.switchCaseValue).nextList = new vector<int>;
        (yyval.switchCaseValue).breakList = new vector<int>;
        (yyval.switchCaseValue).continueList = new vector <int>;
        (yyval.switchCaseValue).casePair = new vector<pair<string,int>>;
        merge((yyval.switchCaseValue).continueList,(yyvsp[0].switchCaseValue).continueList);
        merge((yyval.switchCaseValue).breakList, (yyvsp[0].switchCaseValue).breakList);
        merge((yyval.switchCaseValue).nextList, (yyvsp[0].switchCaseValue).nextList);
        merge((yyval.switchCaseValue).continueList,(yyvsp[-1].statementValue).continueList);
        merge((yyval.switchCaseValue).breakList, (yyvsp[-1].statementValue).breakList);
        merge((yyval.switchCaseValue).nextList, (yyvsp[-1].statementValue).nextList);
        mergeSwitch((yyval.switchCaseValue).casePair, (yyvsp[0].switchCaseValue).casePair);
        mergeSwitch((yyval.switchCaseValue).casePair, (yyvsp[-4].switchTempValue).casePair);
    }
#line 3208 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1567 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[0].switchTempValue).casePair->push_back(make_pair(string((yyvsp[-1].idName)), nextNum));
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
        }
#line 3217 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1572 "parser.y" /* yacc.c:1646  */
    {
        (yyval.switchCaseValue).nextList = new vector<int>;
        (yyval.switchCaseValue).breakList = new vector<int>;
        (yyval.switchCaseValue).continueList = new vector <int>;
        (yyval.switchCaseValue).casePair = new vector<pair<string,int>>;
        merge((yyval.switchCaseValue).continueList,(yyvsp[-1].statementValue).continueList);
        merge((yyval.switchCaseValue).breakList, (yyvsp[-1].statementValue).breakList);
        merge((yyval.switchCaseValue).nextList, (yyvsp[-1].statementValue).nextList);
        merge((yyval.switchCaseValue).continueList,(yyvsp[0].switchCaseValue).continueList);
        merge((yyval.switchCaseValue).breakList, (yyvsp[0].switchCaseValue).breakList);
        merge((yyval.switchCaseValue).nextList, (yyvsp[0].switchCaseValue).nextList);
        mergeSwitch((yyval.switchCaseValue).casePair, (yyvsp[0].switchCaseValue).casePair);
        mergeSwitch((yyval.switchCaseValue).casePair, (yyvsp[-4].switchTempValue).casePair);
    }
#line 3236 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1587 "parser.y" /* yacc.c:1646  */
    {
        (yyval.switchCaseValue).nextList = new vector<int>;
        (yyval.switchCaseValue).breakList = new vector<int>;
        (yyval.switchCaseValue).continueList = new vector <int>;
        (yyval.switchCaseValue).casePair = new vector<pair<string,int>>;
    }
#line 3247 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1593 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[0].switchTempValue).casePair->push_back(make_pair("default", nextNum));
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
    }
#line 3256 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1597 "parser.y" /* yacc.c:1646  */
    {
        (yyval.switchCaseValue).nextList = new vector<int>;
        (yyval.switchCaseValue).breakList = new vector<int>;
        (yyval.switchCaseValue).casePair = new vector<pair<string,int>>;
        (yyval.switchCaseValue).continueList = new vector <int>;
        merge((yyval.switchCaseValue).continueList,(yyvsp[0].statementValue).continueList);
        merge((yyval.switchCaseValue).breakList, (yyvsp[0].statementValue).breakList);
        merge((yyval.switchCaseValue).nextList, (yyvsp[0].statementValue).nextList);
        mergeSwitch((yyval.switchCaseValue).casePair, (yyvsp[-2].switchTempValue).casePair);
    }
#line 3271 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1610 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.quad) = nextNum;
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum); 
    }
#line 3280 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1617 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expressionValue).type = (yyvsp[0].expressionValue).type;
        if ((yyval.expressionValue).type != ERRORTYPE) {
            (yyval.expressionValue).registerName = (yyvsp[0].expressionValue).registerName;
            (yyval.expressionValue).offsetRegName = (yyvsp[0].expressionValue).offsetRegName;
        } 
    }
#line 3292 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1627 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.whileExpressionValue).begin = nextNum; 
        (yyval.whileExpressionValue).falseList = new vector<int>;
        (yyval.whileExpressionValue).falseList->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
    }
#line 3303 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1636 "parser.y" /* yacc.c:1646  */
    {
        deleteVariableList(activeFunctionPointer, scope);
        scope--;
        gen(functionInstruction, "goto L" + to_string((yyvsp[-4].whileExpressionValue).begin), nextNum); 
        merge((yyvsp[-4].whileExpressionValue).falseList,(yyvsp[-1].statementValue).breakList);
        backPatch((yyvsp[-1].statementValue).continueList,(yyvsp[-4].whileExpressionValue).begin, functionInstruction);
        backPatch((yyvsp[-4].whileExpressionValue).falseList, nextNum, functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum); 
    }
#line 3317 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1647 "parser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].expressionValue).type!=NULLVOID){
            gen(functionInstruction, "if "+ (*((yyvsp[-1].expressionValue).registerName)) + " == 0 goto L", nextNum);
        }
    }
#line 3327 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1652 "parser.y" /* yacc.c:1646  */
    {
        backPatch((yyvsp[-1].whileExpressionValue).falseList,(yyvsp[-8].quad),functionInstruction);
        backPatch((yyvsp[-4].whileExpressionValue).falseList,nextNum,functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum); 
        (yyval.whileExpressionValue).falseList = new vector<int>;
        if((yyvsp[-7].expressionValue).type!=NULLVOID){
            (yyval.whileExpressionValue).falseList->push_back((yyvsp[-6].whileExpressionValue).begin);
        }
        (yyval.whileExpressionValue).begin = (yyvsp[-4].whileExpressionValue).begin;
        scope++;
        if((yyvsp[-10].expressionValue).type!=NULLVOID){
            temporarySet.freeRegister(*((yyvsp[-10].expressionValue).registerName));
        }
        if((yyvsp[-7].expressionValue).type!=NULLVOID){
            temporarySet.freeRegister(*((yyvsp[-7].expressionValue).registerName));
        }
        if((yyvsp[-2].expressionValue).type!=NULLVOID){
            temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
        }
    }
#line 3352 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1673 "parser.y" /* yacc.c:1646  */
    {
        errorFound = 1;
        (yyval.whileExpressionValue).falseList = new vector<int>;
        cout << BOLD(FRED("ERROR : ")) << FYEL("Line no. " + to_string(yylineno) + ": Syntax error in for loop, discarded token till RPARE") << endl;
        scope++;
    }
#line 3363 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1682 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.whileExpressionValue).falseList = new vector<int>;
        (yyval.whileExpressionValue).falseList->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
        (yyval.whileExpressionValue).begin = nextNum; 
        gen(functionInstruction, "L"+to_string(nextNum)+":", nextNum);
    }
#line 3375 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1692 "parser.y" /* yacc.c:1646  */
    {
        (yyval.whileExpressionValue).begin = nextNum;
        (yyval.whileExpressionValue).falseList = new vector<int>;
        (yyval.whileExpressionValue).falseList->push_back(nextNum);
    }
#line 3385 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1700 "parser.y" /* yacc.c:1646  */
    {
        (yyval.quad) = nextNum;
    }
#line 3393 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1706 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expressionValue).type= (yyvsp[0].expressionValue).type;
        if ((yyvsp[0].expressionValue).type != ERRORTYPE && (yyvsp[0].expressionValue).type != NULLVOID) {
            (yyval.expressionValue).registerName = (yyvsp[0].expressionValue).registerName;
        }
    }
#line 3404 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1712 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expressionValue).type = NULLVOID;
    }
#line 3412 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1718 "parser.y" /* yacc.c:1646  */
    {
        (yyval.statementValue).nextList = new vector<int>;
        ((yyval.statementValue).nextList)->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
    }
#line 3422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1727 "parser.y" /* yacc.c:1646  */
    {
        (yyval.quad)=nextNum;
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
    }
#line 3431 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1734 "parser.y" /* yacc.c:1646  */
    {
        deleteVariableList(activeFunctionPointer,scope);
        scope--;

        gen(functionInstruction, "goto L" + to_string((yyvsp[-3].whileExpressionValue).begin), nextNum);
        backPatch((yyvsp[-1].statementValue).nextList, (yyvsp[-3].whileExpressionValue).begin, functionInstruction);
        backPatch((yyvsp[-1].statementValue).continueList, (yyvsp[-3].whileExpressionValue).begin, functionInstruction);
        (yyval.statementValue).nextList = new vector<int>;
        merge((yyval.statementValue).nextList, (yyvsp[-3].whileExpressionValue).falseList);
        merge((yyval.statementValue).nextList, (yyvsp[-1].statementValue).breakList);
        backPatch((yyval.statementValue).nextList,nextNum,functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
    }
#line 3449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1750 "parser.y" /* yacc.c:1646  */
    {
        scope++;
        if((yyvsp[-1].expressionValue).type == NULLVOID || (yyvsp[-1].expressionValue).type == ERRORTYPE){
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout<<"Expression in if statement can't be empty"<<endl;
            errorFound = true;
        }
        else{
            (yyval.whileExpressionValue).falseList = new vector<int>;
            ((yyval.whileExpressionValue).falseList)->push_back(nextNum);
            gen(functionInstruction, "if " + *((yyvsp[-1].expressionValue).registerName) + "== 0 goto L", nextNum);
            (yyval.whileExpressionValue).begin = (yyvsp[-3].quad); 
        }
    }
#line 3468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1765 "parser.y" /* yacc.c:1646  */
    {   
        (yyval.whileExpressionValue).falseList = new vector<int>;
        cout << BOLD(FRED("ERROR : ")) << FYEL("Line no. " + to_string(yylineno) + ": Syntax error in while loop, discarding tokens till RPARE") << endl;
        scope++;
    }
#line 3478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1773 "parser.y" /* yacc.c:1646  */
    {
    (yyval.conditionTemp).temp = new vector<int>;
}
#line 3486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1779 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].expressionValue).type == INTEGER) {
            dimensionList.push_back(*((yyvsp[-1].expressionValue).registerName));
        }
        else {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "One of the dimension of an array cannot be evaluated to integer" << endl;
        }
    }
#line 3500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1789 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].expressionValue).type == INTEGER) {
            dimensionList.push_back(*((yyvsp[-1].expressionValue).registerName));
        }
        else {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "One of the dimension of an array cannot be evaluated to integer" << endl;
        }  
    }
#line 3514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1802 "parser.y" /* yacc.c:1646  */
    {
        (yyval.shortCircuitValue).type = (yyvsp[0].shortCircuitValue).type;
        if ((yyval.shortCircuitValue).type != ERRORTYPE && (yyval.shortCircuitValue).type != NULLVOID) {
            (yyval.shortCircuitValue).registerName = (yyvsp[0].shortCircuitValue).registerName; 
            if((yyvsp[0].shortCircuitValue).jumpList!=NULL){
                vector<int>* queryList = new vector<int>;
                queryList->push_back(nextNum);
                gen(functionInstruction,"goto L",nextNum);
                backPatch((yyvsp[0].shortCircuitValue).jumpList, nextNum, functionInstruction);
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
                gen(functionInstruction,(*((yyval.shortCircuitValue).registerName)) + " = 0",nextNum) ;
                backPatch(queryList,nextNum,functionInstruction);
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
                queryList->clear();   
            }
        }
    }
#line 3536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1820 "parser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].shortCircuitValue).type!=ERRORTYPE){
            (yyvsp[0].conditionTemp).temp->push_back(nextNum);
            gen(functionInstruction, "if " + *((yyvsp[-1].shortCircuitValue).registerName) + "!= 0 goto L", nextNum);

        }
    }
#line 3548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1828 "parser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-4].shortCircuitValue).type==ERRORTYPE || (yyvsp[0].shortCircuitValue).type==ERRORTYPE){
            (yyval.shortCircuitValue).type = ERRORTYPE;
        }
        else if((yyvsp[-4].shortCircuitValue).type == NULLVOID || (yyvsp[0].shortCircuitValue).type == NULLVOID){
            (yyval.shortCircuitValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ": Both the expessions should not be NULL" << endl;
        }
        else{
            (yyval.shortCircuitValue).type = BOOLEAN;
            (yyval.shortCircuitValue).registerName = new string(temporarySet.getRegister());
            vector<int>* queryList = new vector<int>;
            if((yyvsp[0].shortCircuitValue).jumpList!=NULL){
                queryList->push_back(nextNum);
                gen(functionInstruction,"goto L",nextNum);
                backPatch((yyvsp[0].shortCircuitValue).jumpList, nextNum, functionInstruction);
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
                gen(functionInstruction,(*((yyvsp[0].shortCircuitValue).registerName)) + " = 0",nextNum) ;
                backPatch(queryList,nextNum,functionInstruction);
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
                queryList->clear();
            }
            
            (yyval.shortCircuitValue).jumpList = new vector<int>;
            merge((yyval.shortCircuitValue).jumpList,(yyvsp[-4].shortCircuitValue).jumpList);
            
            merge((yyval.shortCircuitValue).jumpList, (yyvsp[-3].conditionTemp).temp);
            ((yyval.shortCircuitValue).jumpList)->push_back(nextNum);
            gen(functionInstruction, "if " + *((yyvsp[0].shortCircuitValue).registerName) + "!= 0 goto L", nextNum);
            string s = (*((yyval.shortCircuitValue).registerName)) + " = 0";   
            gen(functionInstruction,s,nextNum);
            temporarySet.freeRegister(*((yyvsp[-4].shortCircuitValue).registerName));
            temporarySet.freeRegister(*((yyvsp[0].shortCircuitValue).registerName)); 
        }
    }
#line 3588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1867 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-1].shortCircuitValue).type!=ERRORTYPE ){

          ((yyvsp[0].conditionTemp).temp)->push_back(nextNum);
         gen(functionInstruction, "if " + *((yyvsp[-1].shortCircuitValue).registerName) + " == 0 " +" goto L", nextNum);
      } 
    }
#line 3600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1875 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-4].shortCircuitValue).type==ERRORTYPE || (yyvsp[0].expressionValue).type==ERRORTYPE) {
            (yyval.shortCircuitValue).type = ERRORTYPE;
        }
        else if((yyvsp[-4].shortCircuitValue).type == NULLVOID || (yyvsp[0].expressionValue).type == NULLVOID){
            (yyval.shortCircuitValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ": Both the expessions should not be NULL" << endl;
        }
        else{
            (yyval.shortCircuitValue).type = BOOLEAN;
            (yyval.shortCircuitValue).registerName = new string(temporarySet.getRegister());
            (yyval.shortCircuitValue).jumpList = new vector<int>;
            merge((yyval.shortCircuitValue).jumpList,(yyvsp[-4].shortCircuitValue).jumpList);
            vector<int>* queryList = new vector<int>;

            merge((yyval.shortCircuitValue).jumpList, (yyvsp[-3].conditionTemp).temp);
            ((yyval.shortCircuitValue).jumpList)->push_back(nextNum);
            gen(functionInstruction, "if " + *((yyvsp[0].expressionValue).registerName) + " == 0 "+" goto L", nextNum);

            string s = (*((yyval.shortCircuitValue).registerName)) + " = 1";   
            gen(functionInstruction,s,nextNum);
            temporarySet.freeRegister(*((yyvsp[-4].shortCircuitValue).registerName));
            temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));   
        }
    }
#line 3630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1901 "parser.y" /* yacc.c:1646  */
    {
        (yyval.shortCircuitValue).type = (yyvsp[0].expressionValue).type;
        if ((yyvsp[0].expressionValue).type != ERRORTYPE && (yyvsp[0].expressionValue).type != NULLVOID) {
            (yyval.shortCircuitValue).registerName = (yyvsp[0].expressionValue).registerName; 
            (yyval.shortCircuitValue).jumpList = new vector<int>;
            (yyval.shortCircuitValue).jumpList=NULL;   
        }
    }
#line 3643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1912 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE;  
        }
        else {
            if (arithmeticCompatible((yyvsp[-2].expressionValue).type, (yyvsp[0].expressionValue).type)) {
                (yyval.expressionValue).type = compareTypes((yyvsp[-2].expressionValue).type,(yyvsp[0].expressionValue).type);

                if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[-2].expressionValue).registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
                    (yyvsp[-2].expressionValue).registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }
                else if ((yyvsp[-2].expressionValue).type == FLOATING && (yyvsp[0].expressionValue).type == INTEGER) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
                    (yyvsp[0].expressionValue).registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }

                if ((yyval.expressionValue).type == INTEGER) 
                    (yyval.expressionValue).registerName = new string(temporarySet.getRegister());
                else
                    (yyval.expressionValue).registerName = new string(temporarySet.getFloatRegister());
                    
                string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " * " + (*((yyvsp[0].expressionValue).registerName));;   
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));   
            }
            else {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << "Type mismatch in expression" << endl;
                (yyval.expressionValue).type = ERRORTYPE;
            }
        }
    }
#line 3690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1955 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
        (yyval.expressionValue).type = ERRORTYPE;  
        }
        else {
            if (arithmeticCompatible((yyvsp[-2].expressionValue).type, (yyvsp[0].expressionValue).type)) {
                (yyval.expressionValue).type = compareTypes((yyvsp[-2].expressionValue).type,(yyvsp[0].expressionValue).type);

                if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == FLOATING) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[-2].expressionValue).registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
                    (yyvsp[-2].expressionValue).registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }
                else if ((yyvsp[-2].expressionValue).type == FLOATING && (yyvsp[0].expressionValue).type == INTEGER) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[0].expressionValue).registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));
                    (yyvsp[0].expressionValue).registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }

                if ((yyval.expressionValue).type == INTEGER) 
                    (yyval.expressionValue).registerName = new string(temporarySet.getRegister());
                else
                    (yyval.expressionValue).registerName = new string(temporarySet.getFloatRegister());
                    
                string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " / " + (*((yyvsp[0].expressionValue).registerName));   
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));   
            }
            else {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                cout << "Type mismatch in expression" << endl;
                (yyval.expressionValue).type = ERRORTYPE;
            }
        }   
    }
#line 3737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1998 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expressionValue).type = (yyvsp[0].expressionValue).type; 
        if ((yyvsp[0].expressionValue).type == ERRORTYPE) {
            errorFound = true;
        }
        else {
            if((yyvsp[0].expressionValue).type != NULLVOID){
                (yyval.expressionValue).registerName = new string(*((yyvsp[0].expressionValue).registerName)); 
                delete (yyvsp[0].expressionValue).registerName;
            }  
        } 
    }
#line 3754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 2011 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expressionValue).type == ERRORTYPE || (yyvsp[0].expressionValue).type == ERRORTYPE) {
            (yyval.expressionValue).type = ERRORTYPE;  
        }
        else {
            if ((yyvsp[-2].expressionValue).type == INTEGER && (yyvsp[0].expressionValue).type == INTEGER) {
                (yyval.expressionValue).type = INTEGER;
                (yyval.expressionValue).registerName = new string(temporarySet.getRegister());  
                string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[-2].expressionValue).registerName)) + " % " + (*((yyvsp[0].expressionValue).registerName));;   
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*((yyvsp[-2].expressionValue).registerName));
                temporarySet.freeRegister(*((yyvsp[0].expressionValue).registerName));   
            }
            else {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                cout << "Type mismatch in expression" << endl;
                (yyval.expressionValue).type = ERRORTYPE;
            }
        }   
    }
#line 3779 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 2035 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].expressionValue).type == INTEGER) {
            (yyval.expressionValue).type = INTEGER;
            string newReg = temporarySet.getRegister();
            string s = newReg + " = " + (*((yyvsp[0].expressionValue).registerName)); // T2 = i
            gen(functionInstruction, s, nextNum);
            string newReg2 = temporarySet.getRegister();
            (yyval.expressionValue).registerName = new string(newReg2);
            s = newReg2 + " = " + newReg + " + 1"; // T3 = T2+1
            gen(functionInstruction, s, nextNum);
            s = (*((yyvsp[0].expressionValue).registerName)) + " = " + newReg2; // i = T3
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(newReg); 
            if((yyvsp[0].expressionValue).offsetRegName != NULL){
                temporarySet.freeRegister((*((yyvsp[0].expressionValue).offsetRegName)));
            }     
        }
        else {
            (yyval.expressionValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "Cannot increment non-integer type variable "<<*((yyvsp[0].expressionValue).registerName) << endl; 
        }
    }
#line 3807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 2059 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].expressionValue).type == INTEGER) {
            (yyval.expressionValue).type = INTEGER;   
            string newReg = temporarySet.getRegister();
            string s = newReg + " = " + (*((yyvsp[0].expressionValue).registerName)); // T2 = i
            gen(functionInstruction, s, nextNum);
            string newReg2 = temporarySet.getRegister();
            (yyval.expressionValue).registerName = new string(newReg2);
            s = newReg2 + " = " + newReg + " - 1"; // T3 = T2+1
            gen(functionInstruction, s, nextNum);
            s = (*((yyvsp[0].expressionValue).registerName)) + " = " + newReg2; // i = T3
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(newReg);
            if((yyvsp[0].expressionValue).offsetRegName != NULL){
                temporarySet.freeRegister((*((yyvsp[0].expressionValue).offsetRegName)));
            }         
        }
        else {
            (yyval.expressionValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "Cannot increment non-integer type variable " << *((yyvsp[0].expressionValue).registerName) << endl; 
        }
    }
#line 3835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 2083 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expressionValue).type = (yyvsp[0].expressionValue).type;
        if ((yyval.expressionValue).type != ERRORTYPE) {
            if ((yyval.expressionValue).type == INTEGER)
                (yyval.expressionValue).registerName = new string(temporarySet.getRegister());
            else (yyval.expressionValue).registerName = new string(temporarySet.getFloatRegister());
            string s = (*((yyval.expressionValue).registerName)) + " = " + (*((yyvsp[0].expressionValue).registerName)) ;
            gen(functionInstruction, s, nextNum);
            if((yyvsp[0].expressionValue).offsetRegName != NULL){
                temporarySet.freeRegister((*((yyvsp[0].expressionValue).offsetRegName)));
            }
        }
    }
#line 3853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 2097 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expressionValue).type = (yyvsp[-1].expressionValue).type; 
        if ((yyvsp[-1].expressionValue).type != ERRORTYPE) {
            (yyval.expressionValue).registerName = (yyvsp[-1].expressionValue).registerName;
        }
    }
#line 3864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 2104 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expressionValue).type = (yyvsp[0].expressionValue).type;
        if((yyvsp[0].expressionValue).type != ERRORTYPE){
            string s="";
            if ((yyval.expressionValue).type == INTEGER){
                (yyval.expressionValue).registerName = new string(temporarySet.getRegister());
                string temp=temporarySet.getRegister();
                string temp1=temporarySet.getRegister();
                gen(functionInstruction, temp + " = 0", nextNum);
                gen(functionInstruction, temp1 + " = " +  (*((yyvsp[0].expressionValue).registerName)), nextNum);
                s = (*((yyval.expressionValue).registerName)) + " = " + temp + " -" + temp1 ;
                temporarySet.freeRegister(temp);
                temporarySet.freeRegister(temp1);
            }
            else{ 
                (yyval.expressionValue).registerName = new string(temporarySet.getFloatRegister());
                string temp=temporarySet.getFloatRegister();
                string temp1=temporarySet.getRegister();
                gen(functionInstruction, temp + " = 0", nextNum);
                gen(functionInstruction, temp1 + " = " +  (*((yyvsp[0].expressionValue).registerName)), nextNum);
                s = (*((yyval.expressionValue).registerName)) + " = 0 -" + temp1 ;
                temporarySet.freeRegister(temp);
                temporarySet.freeRegister(temp1);
            }
            // string s = (*($$.registerName)) + " = 0 -" + (*($2.registerName)) ;
            gen(functionInstruction, s, nextNum);
            if((yyvsp[0].expressionValue).offsetRegName != NULL){
                temporarySet.freeRegister((*((yyvsp[0].expressionValue).offsetRegName)));
            }
        }       
    }
#line 3900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 2136 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expressionValue).type = INTEGER; 
        (yyval.expressionValue).registerName = new string(temporarySet.getRegister());
        string s = (*((yyval.expressionValue).registerName)) + " = " + string((yyvsp[0].idName)) ;
        gen(functionInstruction, s, nextNum);  
    }
#line 3911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 2143 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expressionValue).type = FLOATING;
        (yyval.expressionValue).registerName = new string(temporarySet.getFloatRegister());
        string s = (*((yyval.expressionValue).registerName)) + " = " + string((yyvsp[0].idName)) ;
        gen(functionInstruction, s, nextNum);  
    }
#line 3922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 2150 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expressionValue).type = FLOATING;
        (yyval.expressionValue).registerName = new string(temporarySet.getFloatRegister());
        string s = (*((yyval.expressionValue).registerName)) + " = " + string((yyvsp[0].idName)) ;
        gen(functionInstruction, s, nextNum);  
    }
#line 3933 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 2157 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expressionValue).type = INTEGER; 
        (yyval.expressionValue).registerName = new string(temporarySet.getRegister());
        string s = (*((yyval.expressionValue).registerName)) + " = -" + string((yyvsp[0].idName)) ;
        gen(functionInstruction, s, nextNum);  
        
    }
#line 3945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 2165 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expressionValue).type = (yyvsp[0].expressionValue).type; 
        if ((yyvsp[0].expressionValue).type == ERRORTYPE) {
            if ((yyvsp[0].expressionValue).type == NULLVOID){
                delete callFunctionPointer;
            }
            else {
                (yyval.expressionValue).registerName = (yyvsp[0].expressionValue).registerName;
                delete callFunctionPointer;
            }
        }; 
    }
#line 3962 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 2178 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].expressionValue).type == INTEGER) {
            (yyval.expressionValue).type = INTEGER;   
            string newReg = temporarySet.getRegister();
            (yyval.expressionValue).registerName = new string(newReg); 
            string s = newReg + " = " + (*((yyvsp[-1].expressionValue).registerName)) ;
            gen(functionInstruction, s, nextNum); // T2 = i
            string newReg2 = temporarySet.getRegister();
            s = newReg2 + " = " + newReg + " + 1"; // T3 = T2+1
            gen(functionInstruction, s, nextNum);
            s = (*((yyvsp[-1].expressionValue).registerName)) + " = " + newReg2; // i = T3
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(newReg2);
            if((yyvsp[-1].expressionValue).offsetRegName != NULL){
                temporarySet.freeRegister((*((yyvsp[-1].expressionValue).offsetRegName)));
            }
        }
        else {
            (yyval.expressionValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "Cannot increment non-integer type variable "<< *((yyvsp[-1].expressionValue).registerName) << endl; 
        }
    }
#line 3990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2202 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].expressionValue).type == INTEGER) {
            (yyval.expressionValue).type = INTEGER;   
            string newReg = temporarySet.getRegister();
            (yyval.expressionValue).registerName = new string(newReg);
            string s = newReg + " = " + (*((yyvsp[-1].expressionValue).registerName)); // T0 = i
            gen(functionInstruction, s, nextNum);
            string newReg2 = temporarySet.getRegister();
            s = newReg2 + " = " + newReg + " - 1"; // T3 = T2+1
            gen(functionInstruction, s, nextNum);
            s = (*((yyvsp[-1].expressionValue).registerName)) + " = " + newReg2; // i = T3
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(newReg2); 
            if((yyvsp[-1].expressionValue).offsetRegName != NULL){
                temporarySet.freeRegister((*((yyvsp[-1].expressionValue).offsetRegName)));
            }    
        }
        else {
            (yyval.expressionValue).type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "Cannot increment non-integer type variable " << *((yyvsp[-1].expressionValue).registerName) << endl; 
        }
    }
#line 4018 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 2228 "parser.y" /* yacc.c:1646  */
    {   
        // retrieve the highest level id with same name in param list or var list or global list
        int found = 0;
        typeRecord* vn = NULL;
        searchCallVariable(string((yyvsp[0].idName)), activeFunctionPointer, found, vn, globalVariables); 
        (yyval.expressionValue).offsetRegName = NULL;
        if(found){
            if (vn->type == SIMPLE) {
                (yyval.expressionValue).type = vn->elementType;
                string dataType = elementTypeMapper((yyval.expressionValue).type);
                dataType += "_" + to_string(vn->scope);
                (yyval.expressionValue).registerName = new string("_" + string((yyvsp[0].idName)) + "_" + dataType);
            }
            else {
                (yyval.expressionValue).type = ERRORTYPE;
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << (yyvsp[0].idName) << " is declared as an array but is being used as a singleton" << endl; 
            }
        }
        else {
            if (activeFunctionPointer != NULL)
                searchParameter(string ((yyvsp[0].idName)), activeFunctionPointer->parameterList, found, vn);
            if (found) {
                if (vn->type == SIMPLE) {
                    (yyval.expressionValue).type = vn->elementType;
                    string dataType = elementTypeMapper((yyval.expressionValue).type);
                    dataType += "_" + to_string(vn->scope);
                    (yyval.expressionValue).registerName = new string("_" + string((yyvsp[0].idName)) + "_" + dataType);
                }
                else {
                    (yyval.expressionValue).type = ERRORTYPE;
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                    cout << (yyvsp[0].idName) << " is declared as an array but is being used as a singleton" << endl;
                }
            }
            else {
                (yyval.expressionValue).type = ERRORTYPE;
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                cout << "Undeclared identifier " << (yyvsp[0].idName) << endl;
            }
        }
    }
#line 4065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 2271 "parser.y" /* yacc.c:1646  */
    {
        // retrieve the highest level id with same name in param list or var list
        int found = 0;
        typeRecord* vn = NULL;
        (yyval.expressionValue).offsetRegName = NULL; 
        if((yyvsp[0].expressionValue).type == ERRORTYPE){
            errorFound = true;
            (yyval.expressionValue).type = ERRORTYPE;
        }
        else{
            searchCallVariable(string((yyvsp[-1].idName)), activeFunctionPointer, found, vn, globalVariables); 
            if(found){
                if (vn->type == ARRAY) {
                    if (dimensionList.size() == vn->dimensionList.size()) {
                        (yyval.expressionValue).type = vn->elementType;
                        // calculate linear address using dimensions then pass to FACTOR
                        string offsetRegister = temporarySet.getRegister();
                        string dimlistRegister = temporarySet.getRegister();
                        string s = offsetRegister + " = 0";
                        gen(functionInstruction, s, nextNum);
                        for (int i = 0; i < vn->dimensionList.size(); i++) {
                            s = offsetRegister + " = " + offsetRegister + " + " + dimensionList[i];
                            gen(functionInstruction, s, nextNum);
                            // offset += dimensionList[i];
                            if (i != vn->dimensionList.size()-1) {
                                // offset *= vn->dimensionList[i+1];
                                s = dimlistRegister + " = " + to_string(vn->dimensionList[i+1]);
                                gen(functionInstruction, s, nextNum);                                
                                s = offsetRegister + " = " + offsetRegister + " * " + dimlistRegister;
                                gen(functionInstruction, s, nextNum);
                            }
                            temporarySet.freeRegister(dimensionList[i]);
                        }
                        string dataType = elementTypeMapper((yyval.expressionValue).type);
                        dataType += "_" + to_string(vn->scope); 
                        s = "_" + string((yyvsp[-1].idName)) + "_" + dataType ;
                        s += "[" + offsetRegister + "]";
                        (yyval.expressionValue).registerName = new string(s);
                        temporarySet.freeRegister(dimlistRegister);
                        (yyval.expressionValue).offsetRegName = new string(offsetRegister);
                        
                    }
                    else {
                        (yyval.expressionValue).type = ERRORTYPE;
                        cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                        cout << "Dimension mismatch: " << (yyvsp[-1].idName) << " should have " << dimensionList.size() <<" dimensions" << endl;
                    }
                }
                else {
                    (yyval.expressionValue).type = ERRORTYPE;
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                    cout << string((yyvsp[-1].idName)) << " is declared as a singleton but is being used as an array" << endl; 
                }
            }
            else {
                (yyval.expressionValue).type = ERRORTYPE;
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                cout << "Undeclared identifier " << (yyvsp[-1].idName) << endl;
            }
            dimensionList.clear();
        }
    }
#line 4132 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 4136 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2335 "parser.y" /* yacc.c:1906  */


void yyerror(const char *s)
{      
    errorFound=1;
    fprintf (stderr, "%s\n", s);
    // cout << "Line no. " << yylineno << ": Syntax error" << endl;
    // fflush(stdout);
}

int main(int argc, char **argv)
{
    offsetValue = 0;
    errorFound=false;
    nextNum = 0;
    scope = 0;
    found = 0;

    switchVariable.clear();
    dimensionList.clear();
    
    yyparse();
    populateOffsets(functionEntryRecord, globalVariables);
    ofstream outinter;
    outinter.open("./output/intermediate_code.txt");
    if(!errorFound){
        for(auto it:functionInstruction){
            outinter<<it<<endl;
        }
        cout << BOLD(FGRN("Intermediate Code Generated")) << endl;
    } else {
        cout << BOLD(FRED("Exited without intermediate code generation")) << endl;
    }
    outinter.close();
}
