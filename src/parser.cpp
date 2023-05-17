/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include "ast.hpp"
  #include <cstdio>
  #include <cstdlib>
  #include <string>
  #include <iostream>

	Block *programBlock; /* the top level root node of our final AST */

	extern int yylex();
	void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }
  

#line 84 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    EXTERN = 258,
    RETURN = 259,
    FOR = 260,
    IF = 261,
    ELSE = 262,
    WHILE = 263,
    SWITCH = 264,
    CASE = 265,
    DEFAULT = 266,
    ARRAY = 267,
    CONTINUE = 268,
    UNTIL = 269,
    BREAK = 270,
    GAD = 271,
    SEMI = 272,
    COLON = 273,
    INT = 274,
    LONG = 275,
    CHAR = 276,
    FLOAT = 277,
    DOUBLE = 278,
    VOID = 279,
    CEQ = 280,
    CNE = 281,
    CLT = 282,
    CLE = 283,
    CGT = 284,
    CGE = 285,
    EQUAL = 286,
    LPAREN = 287,
    RPAREN = 288,
    LBRACE = 289,
    RBRACE = 290,
    LBRACK = 291,
    RBRACK = 292,
    COMMA = 293,
    DOT = 294,
    ARW = 295,
    XOR = 296,
    NOT = 297,
    OR = 298,
    AND = 299,
    PLUS = 300,
    MINUS = 301,
    MUL = 302,
    DIV = 303,
    INTEGER = 304,
    IDENTIFIER = 305,
    REAL = 306,
    CHARACTER = 307,
    STRING = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

  int token;//标注终结符token
  //标注int double char string
  int iVal;
  std::string *sVal;
  double dVal;
  char cVal;
  std::string *strVal;

	Node *node;
	Block *block;

  //定义抽象类
  Declaration *ndelc;//declaration抽象类
  std::vector<Declaration*> *ndelcs;//declarations抽象类
  
  //变量定义
  VariableDeclaration *var_decl;
	std::vector<VariableDeclaration*> *var_decls;

  //函数定义
  FunctionDeclaration *func_decl;
  //std::vector<FunctionDeclaration*> *func_decls;
  

  Expression *expr;//表达式
	Statement *stmt;//声明
	Identifier *ident;//标识符
  
  //关键词
	ForStatement *forStatement;
  IfStatement *ifStatement;
  SwitchStatement *switchStatement;
  WhileStatement *whileStatement;
  CaseStatement *caseStatement;
  LoopStatement *loopStatement;
  CaseList *caseList;
  BreakStatement *breakStatement;
  ContinueStatement *continueStatement;

	std::vector<Expression*> *expressionList;
  VarType *varType;

#line 234 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   448

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   110,   113,   119,   119,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   133,   136,   141,   142,
     145,   149,   153,   157,   158,   161,   162,   164,   166,   172,
     175,   180,   181,   182,   185,   186,   187,   192,   193,   194,
     195,   196,   197,   199,   202,   206,   207,   208,   213,   217,
     218,   219,   220,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   237,   240,   243,   246,
     251,   252,   253,   257,   258,   259,   260
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EXTERN", "RETURN", "FOR", "IF", "ELSE",
  "WHILE", "SWITCH", "CASE", "DEFAULT", "ARRAY", "CONTINUE", "UNTIL",
  "BREAK", "GAD", "SEMI", "COLON", "INT", "LONG", "CHAR", "FLOAT",
  "DOUBLE", "VOID", "CEQ", "CNE", "CLT", "CLE", "CGT", "CGE", "EQUAL",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COMMA",
  "DOT", "ARW", "XOR", "NOT", "OR", "AND", "PLUS", "MINUS", "MUL", "DIV",
  "INTEGER", "IDENTIFIER", "REAL", "CHARACTER", "STRING", "$accept",
  "program", "stmts", "stmt", "IfStmt", "LoopStmt", "WhileStmt", "ForStmt",
  "SwitchStmt", "CaseList", "CaseStmt", "BreakStmt", "ContinueStmt",
  "block", "var_decl", "varType", "extern_decl", "func_decl",
  "func_decl_args", "ident", "expression", "call_args", "const_value", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     211,   -37,   100,   -17,   -15,    -7,     3,   -78,   -78,   -37,
     -78,   -78,   -78,   -78,   -78,   -78,   100,   -78,   -78,   -78,
     -78,   -78,    23,   211,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -37,   -78,   -78,   -20,   388,   -78,   -37,
     -12,   388,   100,   100,   100,   100,    -5,   265,   -78,   -78,
      -3,   100,   100,   100,   -10,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,    16,   222,   289,
     298,   322,   100,   -78,   100,    20,   388,   388,    -4,   334,
     100,   -14,    22,    34,    34,    34,    34,    34,    34,   394,
     400,    -9,    -9,   -78,   -78,   -14,   100,    12,    12,    42,
     358,   388,    40,   -78,   100,    52,   388,   -78,    -1,   -37,
      47,    14,   228,   106,    78,   -78,   -78,   -78,   -78,   388,
     100,    12,   -14,    37,   -78,   -78,   100,   -78,   160,    12,
      -8,   388,   -78,   -78,   364,   -78,   -78,   100,    68,   -78,
     -78,    12,   259,    12,   -78,    12,   -78,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,     0,     0,     0,     0,    28,    27,     0,
      37,    38,    39,    40,    41,    42,     0,    73,    48,    74,
      75,    76,     0,     2,     3,    14,    15,    19,    18,    13,
      11,    12,     5,     0,     7,     6,    51,     8,    52,     0,
      51,     9,     0,     0,     0,     0,    65,     0,     1,     4,
      31,     0,    70,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,     0,    49,    71,     0,     0,
       0,    45,     0,    59,    60,    61,    62,    63,    64,    54,
      53,    57,    58,    55,    56,    45,     0,     0,     0,     0,
       0,    32,     0,    50,     0,    68,    35,    46,     0,     0,
       0,     0,     0,     0,    16,    20,    24,    66,    33,    72,
       0,     0,     0,    34,    36,    43,     0,    30,     0,     0,
       0,    69,    44,    47,     0,    29,    17,     0,     0,    22,
      23,     0,     0,     0,    21,     0,    26,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -23,   -22,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -54,   -77,   -78,   -78,   -78,     0,    65,
      -2,   -78,   -78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    27,    28,    29,   130,
     140,    30,    31,   114,    32,    33,    34,    35,   108,    40,
      37,    78,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,    49,   137,   138,   107,    10,    11,    12,    13,    14,
      15,    51,    52,    18,    47,    42,    53,    43,   107,    51,
      52,    80,    81,    48,    53,    44,    82,   139,    74,   103,
      18,    72,   121,    75,   104,    45,    18,   122,    65,    66,
      68,    69,    70,    71,   115,   133,   113,   125,    95,    76,
      77,    79,   122,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    36,    39,   132,    80,   102,
     100,   110,   101,    82,    46,   136,   116,   118,   106,    63,
      64,    65,    66,   120,   124,   129,   143,   144,    36,   146,
     128,   147,     0,     0,   112,   111,     0,     0,    50,     0,
       0,    54,   119,     0,    67,     0,    49,     0,     0,     1,
       2,     3,     4,     0,     5,     6,     9,     0,   131,     7,
       0,     8,     9,     0,   134,    10,    11,    12,    13,    14,
      15,     0,    16,     0,     0,   142,     0,     0,    16,     0,
       0,   127,     0,     0,     0,     0,   109,     0,     0,    17,
      18,    19,    20,    21,     0,    17,    18,    19,    20,    21,
     109,     0,     0,     1,     2,     3,     4,     0,     5,     6,
       0,     0,     0,     7,   123,     8,     9,     0,    36,    10,
      11,    12,    13,    14,    15,     0,     0,   109,     0,     0,
       0,     0,    16,    36,     0,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    21,     1,     2,     3,     4,     0,     5,
       6,     0,     0,     0,     7,     0,     8,     9,     0,     0,
      10,    11,    12,    13,    14,    15,     0,     0,     0,    96,
       0,     0,     0,    16,     0,   126,     0,    55,    56,    57,
      58,    59,    60,    55,    56,    57,    58,    59,    60,     0,
      17,    18,    19,    20,    21,    61,    62,    63,    64,    65,
      66,    61,    62,    63,    64,    65,    66,   145,     0,     0,
       0,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      55,    56,    57,    58,    59,    60,     0,     0,    73,     0,
       0,     0,    61,    62,    63,    64,    65,    66,    61,    62,
      63,    64,    65,    66,    55,    56,    57,    58,    59,    60,
       0,     0,    97,    55,    56,    57,    58,    59,    60,     0,
       0,    98,    61,    62,    63,    64,    65,    66,     0,     0,
       0,    61,    62,    63,    64,    65,    66,    55,    56,    57,
      58,    59,    60,     0,     0,    99,     0,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,   105,     0,     0,     0,     0,     0,    61,    62,    63,
      64,    65,    66,    55,    56,    57,    58,    59,    60,    55,
      56,    57,    58,    59,    60,   117,     0,   141,     0,     0,
       0,    61,    62,    63,    64,    65,    66,    61,    62,    63,
      64,    65,    66,    55,    56,    57,    58,    59,    60,    55,
      56,    57,    58,    59,    60,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    62,    63,
      64,    65,    66,     0,     0,    63,    64,    65,    66
};

static const yytype_int16 yycheck[] =
{
       2,    23,    10,    11,    81,    19,    20,    21,    22,    23,
      24,    31,    32,    50,    16,    32,    36,    32,    95,    31,
      32,    31,    32,     0,    36,    32,    36,    35,    31,    33,
      50,    36,    33,    36,    38,    32,    50,    38,    47,    48,
      42,    43,    44,    45,    98,   122,    34,    33,    32,    51,
      52,    53,    38,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     1,   121,    31,    49,
      72,    49,    74,    36,     9,   129,    34,    37,    80,    45,
      46,    47,    48,    31,    37,     7,    18,   141,    23,   143,
     113,   145,    -1,    -1,    96,    95,    -1,    -1,    33,    -1,
      -1,    36,   104,    -1,    39,    -1,   128,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    16,    -1,   120,    13,
      -1,    15,    16,    -1,   126,    19,    20,    21,    22,    23,
      24,    -1,    32,    -1,    -1,   137,    -1,    -1,    32,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    81,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    49,    50,    51,    52,    53,
      95,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    13,   109,    15,    16,    -1,   113,    19,
      20,    21,    22,    23,    24,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    32,   128,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    13,    -1,    15,    16,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    32,    -1,    17,    -1,    25,    26,    27,
      28,    29,    30,    25,    26,    27,    28,    29,    30,    -1,
      49,    50,    51,    52,    53,    43,    44,    45,    46,    47,
      48,    43,    44,    45,    46,    47,    48,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      25,    26,    27,    28,    29,    30,    -1,    -1,    33,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    43,    44,
      45,    46,    47,    48,    25,    26,    27,    28,    29,    30,
      -1,    -1,    33,    25,    26,    27,    28,    29,    30,    -1,
      -1,    33,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    25,    26,    27,
      28,    29,    30,    -1,    -1,    33,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    43,    44,    45,    46,    47,
      48,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    25,    26,    27,    28,    29,    30,    25,
      26,    27,    28,    29,    30,    37,    -1,    33,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    43,    44,    45,
      46,    47,    48,    25,    26,    27,    28,    29,    30,    25,
      26,    27,    28,    29,    30,    25,    26,    27,    28,    29,
      30,    43,    44,    45,    46,    47,    48,    -1,    44,    45,
      46,    47,    48,    -1,    -1,    45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    13,    15,    16,
      19,    20,    21,    22,    23,    24,    32,    49,    50,    51,
      52,    53,    55,    56,    57,    58,    59,    60,    61,    62,
      65,    66,    68,    69,    70,    71,    73,    74,    76,    73,
      73,    74,    32,    32,    32,    32,    73,    74,     0,    57,
      73,    31,    32,    36,    73,    25,    26,    27,    28,    29,
      30,    43,    44,    45,    46,    47,    48,    73,    74,    74,
      74,    74,    36,    33,    31,    36,    74,    74,    75,    74,
      31,    32,    36,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    32,    17,    33,    33,    33,
      74,    74,    49,    33,    38,    37,    74,    68,    72,    73,
      49,    72,    74,    34,    67,    67,    34,    37,    37,    74,
      31,    33,    38,    73,    37,    33,    17,    35,    56,     7,
      63,    74,    67,    68,    74,    35,    67,    10,    11,    35,
      64,    33,    74,    18,    67,    18,    67,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    59,    59,
      60,    61,    62,    63,    63,    64,    64,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    71,    72,    72,    72,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    76,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     5,     7,     1,     1,
       5,     9,     7,     2,     0,     4,     3,     1,     1,     3,
       2,     2,     4,     5,     2,     4,     5,     1,     1,     1,
       1,     1,     1,     6,     6,     0,     1,     3,     1,     3,
       4,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     5,     3,     4,     6,
       0,     1,     3,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 106 "parser.y"
          { 
        programBlock = (yyvsp[0].block); 
    }
#line 1572 "parser.cpp"
    break;

  case 3:
#line 110 "parser.y"
         {
        (yyval.block) = new Block(); (yyval.block)->statementList.push_back((yyvsp[0].stmt));
    }
#line 1580 "parser.cpp"
    break;

  case 4:
#line 113 "parser.y"
                 {
       (yyvsp[-1].block)->statementList.push_back((yyvsp[0].stmt));
    }
#line 1588 "parser.cpp"
    break;

  case 8:
#line 120 "parser.y"
                      { (yyval.stmt) = new ExpressionStatement(*(yyvsp[0].expr)); }
#line 1594 "parser.cpp"
    break;

  case 9:
#line 121 "parser.y"
                             { (yyval.stmt) = new Return((yyvsp[0].expr)); }
#line 1600 "parser.cpp"
    break;

  case 10:
#line 122 "parser.y"
            { (yyval.stmt) = new Return(); }
#line 1606 "parser.cpp"
    break;

  case 11:
#line 123 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].breakStatement); }
#line 1612 "parser.cpp"
    break;

  case 12:
#line 124 "parser.y"
                   { (yyval.stmt) = (yyvsp[0].continueStatement); }
#line 1618 "parser.cpp"
    break;

  case 13:
#line 125 "parser.y"
                {  (yyval.stmt) = (yyvsp[0].switchStatement);}
#line 1624 "parser.cpp"
    break;

  case 14:
#line 126 "parser.y"
           { (yyval.stmt) = (yyvsp[0].ifStatement); }
#line 1630 "parser.cpp"
    break;

  case 15:
#line 127 "parser.y"
             { (yyval.stmt) = (yyvsp[0].loopStatement); }
#line 1636 "parser.cpp"
    break;

  case 16:
#line 133 "parser.y"
                                         {
        (yyval.ifStatement) = new IfStatement(*(yyvsp[-2].expr), *(yyvsp[0].block));
    }
#line 1644 "parser.cpp"
    break;

  case 17:
#line 136 "parser.y"
                                                 {
        (yyval.ifStatement) = new IfStatement(*(yyvsp[-4].expr), *(yyvsp[-2].block), (yyvsp[0].block));
    }
#line 1652 "parser.cpp"
    break;

  case 18:
#line 141 "parser.y"
         { (yyval.loopStatement) = (yyvsp[0].forStatement); }
#line 1658 "parser.cpp"
    break;

  case 19:
#line 142 "parser.y"
            { (yyval.loopStatement) = (yyvsp[0].whileStatement); }
#line 1664 "parser.cpp"
    break;

  case 20:
#line 145 "parser.y"
                                                 {
        (yyval.whileStatement) = new WhileStatement(*(yyvsp[-2].expr), *(yyvsp[0].block));
    }
#line 1672 "parser.cpp"
    break;

  case 21:
#line 150 "parser.y"
   {
        (yyval.forStatement) = new ForStatement(*(yyvsp[-4].expr), *(yyvsp[-6].expr),*(yyvsp[-2].expr),*(yyvsp[0].block));
    }
#line 1680 "parser.cpp"
    break;

  case 22:
#line 154 "parser.y"
      {  (yyval.switchStatement) = new SwitchStatement(*(yyvsp[-4].expr),*(yyvsp[-1].caseList));   }
#line 1686 "parser.cpp"
    break;

  case 23:
#line 157 "parser.y"
                                                                                                                {  (yyval.caseList) = (yyvsp[-1].caseList); (yyval.caseList)->push_back((yyvsp[0].caseStatement));   }
#line 1692 "parser.cpp"
    break;

  case 24:
#line 158 "parser.y"
                                                                                                                        {  (yyval.caseList) = new CaseList();   }
#line 1698 "parser.cpp"
    break;

  case 25:
#line 161 "parser.y"
                                                                                                                {  (yyval.caseStatement) = new CaseStatement((yyvsp[-2].expr),*(yyvsp[0].block));   }
#line 1704 "parser.cpp"
    break;

  case 26:
#line 162 "parser.y"
                                                                                                {  (yyval.caseStatement) = new CaseStatement(*(yyvsp[0].block));   }
#line 1710 "parser.cpp"
    break;

  case 27:
#line 164 "parser.y"
                      {  (yyval.breakStatement) = new BreakStatement();   }
#line 1716 "parser.cpp"
    break;

  case 28:
#line 166 "parser.y"
                                 {  (yyval.continueStatement) = new ContinueStatement();   }
#line 1722 "parser.cpp"
    break;

  case 29:
#line 172 "parser.y"
                        {
        (yyval.block) = (yyvsp[-1].block);
    }
#line 1730 "parser.cpp"
    break;

  case 30:
#line 175 "parser.y"
                    {
        (yyval.block) = new Block();
    }
#line 1738 "parser.cpp"
    break;

  case 31:
#line 180 "parser.y"
                         { (yyval.stmt) = new VariableDeclaration((yyvsp[-1].varType), *(yyvsp[0].ident)); }
#line 1744 "parser.cpp"
    break;

  case 32:
#line 181 "parser.y"
                                       { (yyval.stmt) = new VariableDeclaration((yyvsp[-3].varType), *(yyvsp[-2].ident), (yyvsp[0].expr)); }
#line 1750 "parser.cpp"
    break;

  case 33:
#line 182 "parser.y"
                                            { // 定义数组
              (yyval.stmt) = new ArrayDeclaration((yyvsp[-4].varType), *(yyvsp[-3].ident), (yyvsp[-1].iVal));
    }
#line 1758 "parser.cpp"
    break;

  case 34:
#line 185 "parser.y"
                   { (yyval.stmt) = new VariableDeclaration((yyvsp[-1].ident), *(yyvsp[0].ident)); }
#line 1764 "parser.cpp"
    break;

  case 35:
#line 186 "parser.y"
                                     { (yyval.stmt) = new VariableDeclaration((yyvsp[-3].ident), *(yyvsp[-2].ident), (yyvsp[0].expr)); }
#line 1770 "parser.cpp"
    break;

  case 36:
#line 187 "parser.y"
                                          { // 定义数组
        (yyval.stmt) = new ArrayDeclaration((yyvsp[-4].ident), *(yyvsp[-3].ident), (yyvsp[-1].iVal));
    }
#line 1778 "parser.cpp"
    break;

  case 37:
#line 192 "parser.y"
                                                                                                                    {  (yyval.varType) = new VarType(VarType::_Int); }
#line 1784 "parser.cpp"
    break;

  case 38:
#line 193 "parser.y"
                                                                                                                                {  (yyval.varType) = new VarType(VarType::_Long);  }
#line 1790 "parser.cpp"
    break;

  case 39:
#line 194 "parser.y"
                                                                                                                                {  (yyval.varType) = new VarType(VarType::_Char);  }
#line 1796 "parser.cpp"
    break;

  case 40:
#line 195 "parser.y"
                                                                                                                                {  (yyval.varType) = new VarType(VarType::_Float);  }
#line 1802 "parser.cpp"
    break;

  case 41:
#line 196 "parser.y"
                                                                                                                                {  (yyval.varType) = new VarType(VarType::_Double);  }
#line 1808 "parser.cpp"
    break;

  case 42:
#line 197 "parser.y"
                                                                    {  (yyval.varType) = new VarType(VarType::_Void); }
#line 1814 "parser.cpp"
    break;

  case 43:
#line 200 "parser.y"
                  { (yyval.stmt) = new ExternDeclaration(*(yyvsp[-4].ident), *(yyvsp[-3].ident), *(yyvsp[-1].var_decls)); delete (yyvsp[-1].var_decls); }
#line 1820 "parser.cpp"
    break;

  case 44:
#line 203 "parser.y"
  { (yyval.stmt) = new FunctionDeclaration(*(yyvsp[-5].ident), *(yyvsp[-4].ident), *(yyvsp[-2].var_decls), *(yyvsp[0].block)); delete (yyvsp[-2].var_decls); }
#line 1826 "parser.cpp"
    break;

  case 45:
#line 206 "parser.y"
                              { (yyval.var_decls) = new VariableList(); }
#line 1832 "parser.cpp"
    break;

  case 46:
#line 207 "parser.y"
             { (yyval.var_decls) = new VariableList(); (yyval.var_decls)->push_back((yyvsp[0].var_decl)); }
#line 1838 "parser.cpp"
    break;

  case 47:
#line 208 "parser.y"
                                  { (yyvsp[-2].var_decls)->push_back((yyvsp[0].var_decl)); }
#line 1844 "parser.cpp"
    break;

  case 48:
#line 213 "parser.y"
             { (yyval.ident) = new Identifier(*(yyvsp[0].sVal)); delete (yyvsp[0].sVal); }
#line 1850 "parser.cpp"
    break;

  case 49:
#line 217 "parser.y"
                                      { (yyval.expr) = new Assign(*(yyvsp[-2].ident), *(yyvsp[0].expr)); }
#line 1856 "parser.cpp"
    break;

  case 50:
#line 218 "parser.y"
                                  { (yyval.expr) = new Call(*(yyvsp[-3].ident), *(yyvsp[-1].expressionList)); delete (yyvsp[-1].expressionList); }
#line 1862 "parser.cpp"
    break;

  case 51:
#line 219 "parser.y"
          { (yyval.ident) = (yyvsp[0].ident); }
#line 1868 "parser.cpp"
    break;

  case 53:
#line 222 "parser.y"
                              {(yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));}
#line 1874 "parser.cpp"
    break;

  case 54:
#line 223 "parser.y"
                             {(yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));}
#line 1880 "parser.cpp"
    break;

  case 55:
#line 224 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1886 "parser.cpp"
    break;

  case 56:
#line 225 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1892 "parser.cpp"
    break;

  case 57:
#line 226 "parser.y"
                               { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1898 "parser.cpp"
    break;

  case 58:
#line 227 "parser.y"
                                { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1904 "parser.cpp"
    break;

  case 59:
#line 228 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1910 "parser.cpp"
    break;

  case 60:
#line 229 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1916 "parser.cpp"
    break;

  case 61:
#line 230 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1922 "parser.cpp"
    break;

  case 62:
#line 231 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1928 "parser.cpp"
    break;

  case 63:
#line 232 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1934 "parser.cpp"
    break;

  case 64:
#line 233 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1940 "parser.cpp"
    break;

  case 65:
#line 234 "parser.y"
             {//数组和地址表达式
        (yyval.expr) = new GetAddr(*(yyvsp[0].ident));
    }
#line 1948 "parser.cpp"
    break;

  case 66:
#line 237 "parser.y"
                                         {
        (yyval.expr) = new GetArrayAddr(*(yyvsp[-3].ident), *(yyvsp[-1].expr));
    }
#line 1956 "parser.cpp"
    break;

  case 67:
#line 240 "parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1964 "parser.cpp"
    break;

  case 68:
#line 243 "parser.y"
                                      { // array element access
        (yyval.expr) = new ArrayElement(*(yyvsp[-3].ident), *(yyvsp[-1].expr));
    }
#line 1972 "parser.cpp"
    break;

  case 69:
#line 246 "parser.y"
                                                      { // array element access
        (yyval.expr) = new ArrayAssign(*(yyvsp[-5].ident), *(yyvsp[-3].expr), *(yyvsp[0].expr));
    }
#line 1980 "parser.cpp"
    break;

  case 70:
#line 251 "parser.y"
                          { (yyval.expressionList) = new ExpressionList(); }
#line 1986 "parser.cpp"
    break;

  case 71:
#line 252 "parser.y"
                               { (yyval.expressionList) = new ExpressionList(); (yyval.expressionList)->push_back((yyvsp[0].expr)); }
#line 1992 "parser.cpp"
    break;

  case 72:
#line 253 "parser.y"
                                                { (yyvsp[-2].expressionList)->push_back((yyvsp[0].expr)); }
#line 1998 "parser.cpp"
    break;

  case 73:
#line 257 "parser.y"
                          { (yyval.expr) = new Integer((yyvsp[0].iVal)); }
#line 2004 "parser.cpp"
    break;

  case 74:
#line 258 "parser.y"
                       { (yyval.expr) = new Double((yyvsp[0].dVal)); }
#line 2010 "parser.cpp"
    break;

  case 75:
#line 259 "parser.y"
                { (yyval.expr) = new Char((yyvsp[0].cVal));}
#line 2016 "parser.cpp"
    break;

  case 76:
#line 260 "parser.y"
             { (yyval.expr) = new String(*(yyvsp[0].strVal)); }
#line 2022 "parser.cpp"
    break;


#line 2026 "parser.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 262 "parser.y"

