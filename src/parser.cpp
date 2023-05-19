/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
  

#line 85 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EXTERN = 3,                     /* EXTERN  */
  YYSYMBOL_RETURN = 4,                     /* RETURN  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_SWITCH = 9,                     /* SWITCH  */
  YYSYMBOL_CASE = 10,                      /* CASE  */
  YYSYMBOL_DEFAULT = 11,                   /* DEFAULT  */
  YYSYMBOL_ARRAY = 12,                     /* ARRAY  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_UNTIL = 14,                     /* UNTIL  */
  YYSYMBOL_BREAK = 15,                     /* BREAK  */
  YYSYMBOL_GAD = 16,                       /* GAD  */
  YYSYMBOL_SEMI = 17,                      /* SEMI  */
  YYSYMBOL_COLON = 18,                     /* COLON  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_LONG = 20,                      /* LONG  */
  YYSYMBOL_CHAR = 21,                      /* CHAR  */
  YYSYMBOL_FLOAT = 22,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 23,                    /* DOUBLE  */
  YYSYMBOL_VOID = 24,                      /* VOID  */
  YYSYMBOL_CEQ = 25,                       /* CEQ  */
  YYSYMBOL_CNE = 26,                       /* CNE  */
  YYSYMBOL_CLT = 27,                       /* CLT  */
  YYSYMBOL_CLE = 28,                       /* CLE  */
  YYSYMBOL_CGT = 29,                       /* CGT  */
  YYSYMBOL_CGE = 30,                       /* CGE  */
  YYSYMBOL_EQUAL = 31,                     /* EQUAL  */
  YYSYMBOL_LPAREN = 32,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 33,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 34,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 35,                    /* RBRACE  */
  YYSYMBOL_LBRACK = 36,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 37,                    /* RBRACK  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_DOT = 39,                       /* DOT  */
  YYSYMBOL_ARW = 40,                       /* ARW  */
  YYSYMBOL_XOR = 41,                       /* XOR  */
  YYSYMBOL_NOT = 42,                       /* NOT  */
  YYSYMBOL_OR = 43,                        /* OR  */
  YYSYMBOL_AND = 44,                       /* AND  */
  YYSYMBOL_PLUS = 45,                      /* PLUS  */
  YYSYMBOL_MINUS = 46,                     /* MINUS  */
  YYSYMBOL_MUL = 47,                       /* MUL  */
  YYSYMBOL_DIV = 48,                       /* DIV  */
  YYSYMBOL_INTEGER = 49,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 50,                /* IDENTIFIER  */
  YYSYMBOL_REAL = 51,                      /* REAL  */
  YYSYMBOL_CHARACTER = 52,                 /* CHARACTER  */
  YYSYMBOL_STRING = 53,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_stmts = 56,                     /* stmts  */
  YYSYMBOL_stmt = 57,                      /* stmt  */
  YYSYMBOL_IfStmt = 58,                    /* IfStmt  */
  YYSYMBOL_LoopStmt = 59,                  /* LoopStmt  */
  YYSYMBOL_WhileStmt = 60,                 /* WhileStmt  */
  YYSYMBOL_ForStmt = 61,                   /* ForStmt  */
  YYSYMBOL_SwitchStmt = 62,                /* SwitchStmt  */
  YYSYMBOL_CaseList = 63,                  /* CaseList  */
  YYSYMBOL_CaseStmt = 64,                  /* CaseStmt  */
  YYSYMBOL_BreakStmt = 65,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 66,              /* ContinueStmt  */
  YYSYMBOL_block = 67,                     /* block  */
  YYSYMBOL_var_decl = 68,                  /* var_decl  */
  YYSYMBOL_varType = 69,                   /* varType  */
  YYSYMBOL_func_decl = 70,                 /* func_decl  */
  YYSYMBOL_func_decl_args = 71,            /* func_decl_args  */
  YYSYMBOL_ident = 72,                     /* ident  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_call_args = 74,                 /* call_args  */
  YYSYMBOL_const_value = 75                /* const_value  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   442

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
       0,   106,   106,   110,   113,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   134,   137,   142,   143,   146,
     150,   154,   158,   159,   162,   163,   165,   167,   173,   176,
     181,   182,   183,   189,   190,   191,   192,   201,   205,   206,
     207,   212,   216,   217,   218,   219,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   236,
     239,   242,   245,   250,   251,   252,   255,   256,   257,   258
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "EXTERN", "RETURN",
  "FOR", "IF", "ELSE", "WHILE", "SWITCH", "CASE", "DEFAULT", "ARRAY",
  "CONTINUE", "UNTIL", "BREAK", "GAD", "SEMI", "COLON", "INT", "LONG",
  "CHAR", "FLOAT", "DOUBLE", "VOID", "CEQ", "CNE", "CLT", "CLE", "CGT",
  "CGE", "EQUAL", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK",
  "RBRACK", "COMMA", "DOT", "ARW", "XOR", "NOT", "OR", "AND", "PLUS",
  "MINUS", "MUL", "DIV", "INTEGER", "IDENTIFIER", "REAL", "CHARACTER",
  "STRING", "$accept", "program", "stmts", "stmt", "IfStmt", "LoopStmt",
  "WhileStmt", "ForStmt", "SwitchStmt", "CaseList", "CaseStmt",
  "BreakStmt", "ContinueStmt", "block", "var_decl", "varType", "func_decl",
  "func_decl_args", "ident", "expression", "call_args", "const_value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     173,    15,   -28,   -26,   -22,     2,   -91,   -91,   -20,   -91,
     -91,   -91,   -91,   101,   -91,   -91,   -91,   -91,   -91,    35,
     173,   -91,   -91,   -91,   -91,   -91,   -91,    23,    25,    34,
     -20,   -91,   -14,   184,   -91,   -91,   190,   101,   101,   101,
     101,    44,   265,   -91,   -91,   -91,   -91,   -91,    41,   101,
     101,   101,   -91,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   -91,   222,   289,   298,   322,
     101,   -91,   101,    -8,    21,   388,   388,   -13,   334,    50,
      50,    50,    50,    50,    50,   234,   394,   -21,   -21,   -91,
     -91,   101,    47,    47,    48,   358,   388,   -91,   -20,   -10,
      51,   -91,   101,    53,   228,    70,    80,   -91,   -91,   -91,
     -17,    47,    -8,   -91,   388,   101,   101,   -91,   123,    47,
      -2,   -91,   -91,   388,   364,   -91,   -91,   101,    82,   -91,
     -91,    47,   259,    47,   -91,    47,   -91,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    27,    26,     0,    33,
      34,    35,    36,     0,    66,    41,    67,    68,    69,     0,
       2,     3,    13,    14,    18,    17,    12,     0,     0,     0,
       0,     6,    44,     0,    45,     9,     0,     0,     0,     0,
       0,    58,     0,     1,     4,    10,    11,     5,    30,     0,
      63,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     0,     0,     0,
       0,    60,     0,    38,     0,    42,    64,     0,     0,    52,
      53,    54,    55,    56,    57,    47,    46,    50,    51,    48,
      49,     0,     0,     0,     0,     0,    31,    39,     0,     0,
       0,    43,     0,    61,     0,     0,    15,    19,    23,    59,
      30,     0,     0,    32,    65,     0,     0,    29,     0,     0,
       0,    37,    40,    62,     0,    28,    16,     0,     0,    21,
      22,     0,     0,     0,    20,     0,    25,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,     1,   -19,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -90,   -68,   -66,   -91,   -91,    -6,    -1,
     -91,   -91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,   120,
     130,    27,    28,   106,    29,    30,    31,    99,    32,    33,
      77,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    44,    41,   107,    37,    97,    38,    98,   127,   128,
      39,     9,    42,    10,    72,    11,    12,    49,    50,    74,
     101,   121,    51,   111,    48,   102,    63,    64,   112,   126,
      15,     8,    35,   129,    40,    43,    66,    67,    68,    69,
      45,   134,    46,   136,   122,   137,    98,    13,    75,    76,
      78,    47,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    14,    15,    16,    17,    18,    95,
     100,    96,    72,    73,     1,     2,     3,    74,     4,     5,
      70,   105,   108,     6,   115,     7,     8,   119,   113,     9,
     104,    10,   110,    11,    12,    61,    62,    63,    64,    44,
     133,   114,    13,     0,     0,   117,   118,     0,     0,     0,
       0,     0,     0,     0,   123,   124,     0,     8,     0,    14,
      15,    16,    17,    18,     0,     0,   132,     1,     2,     3,
       0,     4,     5,    13,     0,     0,     6,     0,     7,     8,
       0,     0,     9,     0,    10,     0,    11,    12,     0,     0,
      14,    15,    16,    17,    18,    13,     0,     0,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,    16,    17,    18,     1,     2,     3,
       0,     4,     5,     0,     0,     0,     6,     0,     7,     8,
       0,     0,     9,     0,    10,     0,    11,    12,     0,     0,
       0,    52,     0,     0,     0,    13,     0,    65,     0,    53,
      54,    55,    56,    57,    58,    53,    54,    55,    56,    57,
      58,     0,    14,    15,    16,    17,    18,    59,    60,    61,
      62,    63,    64,    59,    60,    61,    62,    63,    64,    91,
       0,     0,     0,     0,     0,   116,     0,    53,    54,    55,
      56,    57,    58,    53,    54,    55,    56,    57,    58,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    59,    60,    61,    62,    63,    64,   135,    60,    61,
      62,    63,    64,     0,    53,    54,    55,    56,    57,    58,
      53,    54,    55,    56,    57,    58,     0,     0,    71,     0,
       0,     0,    59,    60,    61,    62,    63,    64,    59,    60,
      61,    62,    63,    64,    53,    54,    55,    56,    57,    58,
       0,     0,    92,    53,    54,    55,    56,    57,    58,     0,
       0,    93,    59,    60,    61,    62,    63,    64,     0,     0,
       0,    59,    60,    61,    62,    63,    64,    53,    54,    55,
      56,    57,    58,     0,     0,    94,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   103,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    53,    54,    55,    56,    57,    58,    53,
      54,    55,    56,    57,    58,   109,     0,   131,     0,     0,
       0,    59,    60,    61,    62,    63,    64,    59,    60,    61,
      62,    63,    64,    53,    54,    55,    56,    57,    58,    53,
      54,    55,    56,    57,    58,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,    64,     0,     0,    61,
      62,    63,    64
};

static const yytype_int16 yycheck[] =
{
       1,    20,     8,    93,    32,    73,    32,    73,    10,    11,
      32,    19,    13,    21,    31,    23,    24,    31,    32,    36,
      33,   111,    36,    33,    30,    38,    47,    48,    38,   119,
      50,    16,    17,    35,    32,     0,    37,    38,    39,    40,
      17,   131,    17,   133,   112,   135,   112,    32,    49,    50,
      51,    17,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    49,    50,    51,    52,    53,    70,
      49,    72,    31,    32,     4,     5,     6,    36,     8,     9,
      36,    34,    34,    13,    31,    15,    16,     7,    37,    19,
      91,    21,    98,    23,    24,    45,    46,    47,    48,   118,
      18,   102,    32,    -1,    -1,    35,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,   116,    -1,    16,    -1,    49,
      50,    51,    52,    53,    -1,    -1,   127,     4,     5,     6,
      -1,     8,     9,    32,    -1,    -1,    13,    -1,    15,    16,
      -1,    -1,    19,    -1,    21,    -1,    23,    24,    -1,    -1,
      49,    50,    51,    52,    53,    32,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    13,    -1,    15,    16,
      -1,    -1,    19,    -1,    21,    -1,    23,    24,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    32,    -1,    17,    -1,    25,
      26,    27,    28,    29,    30,    25,    26,    27,    28,    29,
      30,    -1,    49,    50,    51,    52,    53,    43,    44,    45,
      46,    47,    48,    43,    44,    45,    46,    47,    48,    17,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    25,    26,    27,
      28,    29,    30,    25,    26,    27,    28,    29,    30,    25,
      26,    27,    28,    29,    30,    43,    44,    45,    46,    47,
      48,    43,    44,    45,    46,    47,    48,    18,    44,    45,
      46,    47,    48,    -1,    25,    26,    27,    28,    29,    30,
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
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    -1,    45,
      46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     8,     9,    13,    15,    16,    19,
      21,    23,    24,    32,    49,    50,    51,    52,    53,    55,
      56,    57,    58,    59,    60,    61,    62,    65,    66,    68,
      69,    70,    72,    73,    75,    17,    73,    32,    32,    32,
      32,    72,    73,     0,    57,    17,    17,    17,    72,    31,
      32,    36,    17,    25,    26,    27,    28,    29,    30,    43,
      44,    45,    46,    47,    48,    17,    73,    73,    73,    73,
      36,    33,    31,    32,    36,    73,    73,    74,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    17,    33,    33,    33,    73,    73,    68,    69,    71,
      49,    33,    38,    37,    73,    34,    67,    67,    34,    37,
      72,    33,    38,    37,    73,    31,    17,    35,    56,     7,
      63,    67,    68,    73,    73,    35,    67,    10,    11,    35,
      64,    33,    73,    18,    67,    18,    67,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    62,    63,    63,    64,    64,    65,    66,    67,    67,
      68,    68,    68,    69,    69,    69,    69,    70,    71,    71,
      71,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    75,    75,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     2,     3,     2,
       2,     2,     1,     1,     1,     5,     7,     1,     1,     5,
       9,     7,     2,     0,     4,     3,     1,     1,     3,     2,
       2,     4,     5,     1,     1,     1,     1,     6,     0,     1,
       3,     1,     3,     4,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     5,
       3,     4,     6,     0,     1,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: stmts  */
#line 106 "parser.y"
          { 
        programBlock = (yyvsp[0].block); 
    }
#line 1298 "parser.cpp"
    break;

  case 3: /* stmts: stmt  */
#line 110 "parser.y"
         {
        (yyval.block) = new Block(); (yyval.block)->statementList.push_back((yyvsp[0].stmt));
    }
#line 1306 "parser.cpp"
    break;

  case 4: /* stmts: stmts stmt  */
#line 113 "parser.y"
                 {
       (yyvsp[-1].block)->statementList.push_back((yyvsp[0].stmt));
    }
#line 1314 "parser.cpp"
    break;

  case 5: /* stmt: var_decl SEMI  */
#line 119 "parser.y"
                  {}
#line 1320 "parser.cpp"
    break;

  case 7: /* stmt: expression SEMI  */
#line 121 "parser.y"
                           { (yyval.stmt) = new ExpressionStatement(*(yyvsp[-1].expr)); }
#line 1326 "parser.cpp"
    break;

  case 8: /* stmt: RETURN expression SEMI  */
#line 122 "parser.y"
                                  { (yyval.stmt) = new ReturnStatement((yyvsp[-1].expr)); }
#line 1332 "parser.cpp"
    break;

  case 9: /* stmt: RETURN SEMI  */
#line 123 "parser.y"
                 { (yyval.stmt) = new ReturnStatement(); }
#line 1338 "parser.cpp"
    break;

  case 10: /* stmt: BreakStmt SEMI  */
#line 124 "parser.y"
                     { (yyval.stmt) = (yyvsp[-1].breakStatement); }
#line 1344 "parser.cpp"
    break;

  case 11: /* stmt: ContinueStmt SEMI  */
#line 125 "parser.y"
                        { (yyval.stmt) = (yyvsp[-1].continueStatement); }
#line 1350 "parser.cpp"
    break;

  case 12: /* stmt: SwitchStmt  */
#line 126 "parser.y"
                {  (yyval.stmt) = (yyvsp[0].switchStatement);}
#line 1356 "parser.cpp"
    break;

  case 13: /* stmt: IfStmt  */
#line 127 "parser.y"
            { (yyval.stmt) = (yyvsp[0].ifStatement); }
#line 1362 "parser.cpp"
    break;

  case 14: /* stmt: LoopStmt  */
#line 128 "parser.y"
              { (yyval.stmt) = (yyvsp[0].loopStatement); }
#line 1368 "parser.cpp"
    break;

  case 15: /* IfStmt: IF LPAREN expression RPAREN block  */
#line 134 "parser.y"
                                         {
        (yyval.ifStatement) = new IfStatement(*(yyvsp[-2].expr), *(yyvsp[0].block));
    }
#line 1376 "parser.cpp"
    break;

  case 16: /* IfStmt: IF LPAREN expression RPAREN block ELSE block  */
#line 137 "parser.y"
                                                 {
        (yyval.ifStatement) = new IfStatement(*(yyvsp[-4].expr), *(yyvsp[-2].block), (yyvsp[0].block));
    }
#line 1384 "parser.cpp"
    break;

  case 17: /* LoopStmt: ForStmt  */
#line 142 "parser.y"
         { (yyval.loopStatement) = (yyvsp[0].forStatement); }
#line 1390 "parser.cpp"
    break;

  case 18: /* LoopStmt: WhileStmt  */
#line 143 "parser.y"
            { (yyval.loopStatement) = (yyvsp[0].whileStatement); }
#line 1396 "parser.cpp"
    break;

  case 19: /* WhileStmt: WHILE LPAREN expression RPAREN block  */
#line 146 "parser.y"
                                                 {
        (yyval.whileStatement) = new WhileStatement(*(yyvsp[-2].expr), *(yyvsp[0].block));
    }
#line 1404 "parser.cpp"
    break;

  case 20: /* ForStmt: FOR LPAREN expression SEMI expression SEMI expression RPAREN block  */
#line 151 "parser.y"
   {
        (yyval.forStatement) = new ForStatement(*(yyvsp[-4].expr), *(yyvsp[-6].expr),*(yyvsp[-2].expr),*(yyvsp[0].block));
    }
#line 1412 "parser.cpp"
    break;

  case 21: /* SwitchStmt: SWITCH LPAREN expression RPAREN LBRACE CaseList RBRACE  */
#line 155 "parser.y"
      {  (yyval.switchStatement) = new SwitchStatement(*(yyvsp[-4].expr),*(yyvsp[-1].caseList));   }
#line 1418 "parser.cpp"
    break;

  case 22: /* CaseList: CaseList CaseStmt  */
#line 158 "parser.y"
                                                                                                                {  (yyval.caseList) = (yyvsp[-1].caseList); (yyval.caseList)->push_back((yyvsp[0].caseStatement));   }
#line 1424 "parser.cpp"
    break;

  case 23: /* CaseList: %empty  */
#line 159 "parser.y"
                                                                                                                        {  (yyval.caseList) = new CaseList();   }
#line 1430 "parser.cpp"
    break;

  case 24: /* CaseStmt: CASE expression COLON block  */
#line 162 "parser.y"
                                                                                                                {  (yyval.caseStatement) = new CaseStatement((yyvsp[-2].expr),*(yyvsp[0].block));   }
#line 1436 "parser.cpp"
    break;

  case 25: /* CaseStmt: DEFAULT COLON block  */
#line 163 "parser.y"
                                                                                                {  (yyval.caseStatement) = new CaseStatement(*(yyvsp[0].block));   }
#line 1442 "parser.cpp"
    break;

  case 26: /* BreakStmt: BREAK  */
#line 165 "parser.y"
                      {  (yyval.breakStatement) = new BreakStatement();   }
#line 1448 "parser.cpp"
    break;

  case 27: /* ContinueStmt: CONTINUE  */
#line 167 "parser.y"
                                 {  (yyval.continueStatement) = new ContinueStatement();   }
#line 1454 "parser.cpp"
    break;

  case 28: /* block: LBRACE stmts RBRACE  */
#line 173 "parser.y"
                        {
        (yyval.block) = (yyvsp[-1].block);
    }
#line 1462 "parser.cpp"
    break;

  case 29: /* block: LBRACE RBRACE  */
#line 176 "parser.y"
                    {
        (yyval.block) = new Block();
    }
#line 1470 "parser.cpp"
    break;

  case 30: /* var_decl: varType ident  */
#line 181 "parser.y"
                         {(yyval.stmt) = new VariableDeclaration(*(yyvsp[-1].varType), *(yyvsp[0].ident)); }
#line 1476 "parser.cpp"
    break;

  case 31: /* var_decl: varType ident EQUAL expression  */
#line 182 "parser.y"
                                       { (yyval.stmt) = new VariableDeclaration(*(yyvsp[-3].varType), *(yyvsp[-2].ident), (yyvsp[0].expr));  }
#line 1482 "parser.cpp"
    break;

  case 32: /* var_decl: varType ident LBRACK INTEGER RBRACK  */
#line 183 "parser.y"
                                            { // 定义数组
              (yyval.stmt) = new VariableDeclaration(*(yyvsp[-4].varType), *(yyvsp[-3].ident), (yyvsp[-1].iVal));
    }
#line 1490 "parser.cpp"
    break;

  case 33: /* varType: INT  */
#line 189 "parser.y"
                                                                                                                    {(yyval.varType) = new VarType(VarType::TypeID::_Int); }
#line 1496 "parser.cpp"
    break;

  case 34: /* varType: CHAR  */
#line 190 "parser.y"
                                                                                                                                {  (yyval.varType) = new VarType(VarType::TypeID::_Char);  }
#line 1502 "parser.cpp"
    break;

  case 35: /* varType: DOUBLE  */
#line 191 "parser.y"
                                                                                                                                {  (yyval.varType) = new VarType(VarType::TypeID::_Double);  }
#line 1508 "parser.cpp"
    break;

  case 36: /* varType: VOID  */
#line 192 "parser.y"
                                                                    {  (yyval.varType) = new VarType(VarType::TypeID::_Void); }
#line 1514 "parser.cpp"
    break;

  case 37: /* func_decl: varType ident LPAREN func_decl_args RPAREN block  */
#line 202 "parser.y"
  { (yyval.stmt) = new FunctionDeclaration(*(yyvsp[-5].varType), *(yyvsp[-4].ident), *(yyvsp[-2].var_decls), *(yyvsp[0].block)); delete (yyvsp[-2].var_decls); }
#line 1520 "parser.cpp"
    break;

  case 38: /* func_decl_args: %empty  */
#line 205 "parser.y"
                              { (yyval.var_decls) = new VariableList(); }
#line 1526 "parser.cpp"
    break;

  case 39: /* func_decl_args: var_decl  */
#line 206 "parser.y"
             { (yyval.var_decls) = new VariableList(); (yyval.var_decls)->push_back((yyvsp[0].var_decl)); }
#line 1532 "parser.cpp"
    break;

  case 40: /* func_decl_args: func_decl_args COMMA var_decl  */
#line 207 "parser.y"
                                  { (yyvsp[-2].var_decls)->push_back((yyvsp[0].var_decl)); }
#line 1538 "parser.cpp"
    break;

  case 41: /* ident: IDENTIFIER  */
#line 212 "parser.y"
             { (yyval.ident) = new Identifier(*(yyvsp[0].sVal)); delete (yyvsp[0].sVal); }
#line 1544 "parser.cpp"
    break;

  case 42: /* expression: ident EQUAL expression  */
#line 216 "parser.y"
                                      { (yyval.expr) = new Assign(*(yyvsp[-2].ident), *(yyvsp[0].expr)); }
#line 1550 "parser.cpp"
    break;

  case 43: /* expression: ident LPAREN call_args RPAREN  */
#line 217 "parser.y"
                                  { (yyval.expr) = new Call(*(yyvsp[-3].ident), *(yyvsp[-1].expressionList)); delete (yyvsp[-1].expressionList); }
#line 1556 "parser.cpp"
    break;

  case 44: /* expression: ident  */
#line 218 "parser.y"
          { (yyval.ident) = (yyvsp[0].ident); }
#line 1562 "parser.cpp"
    break;

  case 46: /* expression: expression AND expression  */
#line 221 "parser.y"
                              {(yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));}
#line 1568 "parser.cpp"
    break;

  case 47: /* expression: expression OR expression  */
#line 222 "parser.y"
                             {(yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));}
#line 1574 "parser.cpp"
    break;

  case 48: /* expression: expression MUL expression  */
#line 223 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1580 "parser.cpp"
    break;

  case 49: /* expression: expression DIV expression  */
#line 224 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1586 "parser.cpp"
    break;

  case 50: /* expression: expression PLUS expression  */
#line 225 "parser.y"
                               { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1592 "parser.cpp"
    break;

  case 51: /* expression: expression MINUS expression  */
#line 226 "parser.y"
                                { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1598 "parser.cpp"
    break;

  case 52: /* expression: expression CEQ expression  */
#line 227 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1604 "parser.cpp"
    break;

  case 53: /* expression: expression CNE expression  */
#line 228 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1610 "parser.cpp"
    break;

  case 54: /* expression: expression CLT expression  */
#line 229 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1616 "parser.cpp"
    break;

  case 55: /* expression: expression CLE expression  */
#line 230 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1622 "parser.cpp"
    break;

  case 56: /* expression: expression CGT expression  */
#line 231 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1628 "parser.cpp"
    break;

  case 57: /* expression: expression CGE expression  */
#line 232 "parser.y"
                              { (yyval.expr) = new BinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1634 "parser.cpp"
    break;

  case 58: /* expression: GAD ident  */
#line 233 "parser.y"
             {//数组和地址表达式
        (yyval.expr) = new GetAddr(*(yyvsp[0].ident));
    }
#line 1642 "parser.cpp"
    break;

  case 59: /* expression: GAD ident LBRACK expression RBRACK  */
#line 236 "parser.y"
                                         {
        (yyval.expr) = new GetArrayAddr(*(yyvsp[-3].ident), *(yyvsp[-1].expr));
    }
#line 1650 "parser.cpp"
    break;

  case 60: /* expression: LPAREN expression RPAREN  */
#line 239 "parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1658 "parser.cpp"
    break;

  case 61: /* expression: ident LBRACK expression RBRACK  */
#line 242 "parser.y"
                                      { // array element access
        (yyval.expr) = new ArrayElement(*(yyvsp[-3].ident), *(yyvsp[-1].expr));
    }
#line 1666 "parser.cpp"
    break;

  case 62: /* expression: ident LBRACK expression RBRACK EQUAL expression  */
#line 245 "parser.y"
                                                      { // array element access
        (yyval.expr) = new ArrayAssign(*(yyvsp[-5].ident), *(yyvsp[-3].expr), *(yyvsp[0].expr));
    }
#line 1674 "parser.cpp"
    break;

  case 63: /* call_args: %empty  */
#line 250 "parser.y"
                          { (yyval.expressionList) = new ExpressionList(); }
#line 1680 "parser.cpp"
    break;

  case 64: /* call_args: expression  */
#line 251 "parser.y"
                               { (yyval.expressionList) = new ExpressionList(); (yyval.expressionList)->push_back((yyvsp[0].expr)); }
#line 1686 "parser.cpp"
    break;

  case 65: /* call_args: call_args COMMA expression  */
#line 252 "parser.y"
                                                { (yyvsp[-2].expressionList)->push_back((yyvsp[0].expr)); }
#line 1692 "parser.cpp"
    break;

  case 66: /* const_value: INTEGER  */
#line 255 "parser.y"
                          { (yyval.expr) = new Integer((yyvsp[0].iVal)); }
#line 1698 "parser.cpp"
    break;

  case 67: /* const_value: REAL  */
#line 256 "parser.y"
                       { (yyval.expr) = new Double((yyvsp[0].dVal)); }
#line 1704 "parser.cpp"
    break;

  case 68: /* const_value: CHARACTER  */
#line 257 "parser.y"
                { (yyval.expr) = new Char((yyvsp[0].cVal));}
#line 1710 "parser.cpp"
    break;

  case 69: /* const_value: STRING  */
#line 258 "parser.y"
             { (yyval.expr) = new String(*(yyvsp[0].strVal)); }
#line 1716 "parser.cpp"
    break;


#line 1720 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 260 "parser.y"

