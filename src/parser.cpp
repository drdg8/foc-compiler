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
	NBlock *programBlock; /* the top level root node of our final AST */

	extern int yylex();
	void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }

#line 83 "parser.cpp"

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
  YYSYMBOL_TEXTERN = 3,                    /* TEXTERN  */
  YYSYMBOL_TRETURN = 4,                    /* TRETURN  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_SWITCH = 9,                     /* SWITCH  */
  YYSYMBOL_CASE = 10,                      /* CASE  */
  YYSYMBOL_DEFAULT = 11,                   /* DEFAULT  */
  YYSYMBOL_ARRAY = 12,                     /* ARRAY  */
  YYSYMBOL_CONST = 13,                     /* CONST  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_CHAR = 15,                      /* CHAR  */
  YYSYMBOL_FLOAT = 16,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 17,                    /* DOUBLE  */
  YYSYMBOL_VOID = 18,                      /* VOID  */
  YYSYMBOL_BOOL = 19,                      /* BOOL  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_LONG = 21,                      /* LONG  */
  YYSYMBOL_UNTIL = 22,                     /* UNTIL  */
  YYSYMBOL_BREAK = 23,                     /* BREAK  */
  YYSYMBOL_GAD = 24,                       /* GAD  */
  YYSYMBOL_SEMI = 25,                      /* SEMI  */
  YYSYMBOL_COLON = 26,                     /* COLON  */
  YYSYMBOL_TCEQ = 27,                      /* TCEQ  */
  YYSYMBOL_TCNE = 28,                      /* TCNE  */
  YYSYMBOL_TCLT = 29,                      /* TCLT  */
  YYSYMBOL_TCLE = 30,                      /* TCLE  */
  YYSYMBOL_TCGT = 31,                      /* TCGT  */
  YYSYMBOL_TCGE = 32,                      /* TCGE  */
  YYSYMBOL_TEQUAL = 33,                    /* TEQUAL  */
  YYSYMBOL_TLPAREN = 34,                   /* TLPAREN  */
  YYSYMBOL_TRPAREN = 35,                   /* TRPAREN  */
  YYSYMBOL_TLBRACE = 36,                   /* TLBRACE  */
  YYSYMBOL_TRBRACE = 37,                   /* TRBRACE  */
  YYSYMBOL_TLBRACK = 38,                   /* TLBRACK  */
  YYSYMBOL_TRBRACK = 39,                   /* TRBRACK  */
  YYSYMBOL_TCOMMA = 40,                    /* TCOMMA  */
  YYSYMBOL_TDOT = 41,                      /* TDOT  */
  YYSYMBOL_ARW = 42,                       /* ARW  */
  YYSYMBOL_BXOR = 43,                      /* BXOR  */
  YYSYMBOL_BNOT = 44,                      /* BNOT  */
  YYSYMBOL_OR = 45,                        /* OR  */
  YYSYMBOL_AND = 46,                       /* AND  */
  YYSYMBOL_TPLUS = 47,                     /* TPLUS  */
  YYSYMBOL_TMINUS = 48,                    /* TMINUS  */
  YYSYMBOL_TMUL = 49,                      /* TMUL  */
  YYSYMBOL_TDIV = 50,                      /* TDIV  */
  YYSYMBOL_TINTEGER = 51,                  /* TINTEGER  */
  YYSYMBOL_TIDENTIFIER = 52,               /* TIDENTIFIER  */
  YYSYMBOL_TDOUBLE = 53,                   /* TDOUBLE  */
  YYSYMBOL_CHARACTER = 54,                 /* CHARACTER  */
  YYSYMBOL_STRING = 55,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_stmts = 58,                     /* stmts  */
  YYSYMBOL_stmt = 59,                      /* stmt  */
  YYSYMBOL_IfStmt = 60,                    /* IfStmt  */
  YYSYMBOL_LoopStmt = 61,                  /* LoopStmt  */
  YYSYMBOL_WhileStmt = 62,                 /* WhileStmt  */
  YYSYMBOL_ForStmt = 63,                   /* ForStmt  */
  YYSYMBOL_SwitchStmt = 64,                /* SwitchStmt  */
  YYSYMBOL_CaseList = 65,                  /* CaseList  */
  YYSYMBOL_CaseStmt = 66,                  /* CaseStmt  */
  YYSYMBOL_BreakStmt = 67,                 /* BreakStmt  */
  YYSYMBOL_block = 68,                     /* block  */
  YYSYMBOL_var_decl = 69,                  /* var_decl  */
  YYSYMBOL_extern_decl = 70,               /* extern_decl  */
  YYSYMBOL_func_decl = 71,                 /* func_decl  */
  YYSYMBOL_func_decl_args = 72,            /* func_decl_args  */
  YYSYMBOL_ident = 73,                     /* ident  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_call_args = 75,                 /* call_args  */
  YYSYMBOL_const_value = 76                /* const_value  */
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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   399

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   103,   103,   107,   110,   116,   116,   116,   117,   118,
     120,   121,   122,   123,   129,   132,   137,   138,   141,   145,
     149,   153,   154,   157,   158,   160,   165,   168,   173,   174,
     175,   179,   182,   186,   187,   188,   193,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   216,   219,   222,   225,   230,   231,
     232,   236,   237,   238,   239
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
  "\"end of file\"", "error", "\"invalid token\"", "TEXTERN", "TRETURN",
  "FOR", "IF", "ELSE", "WHILE", "SWITCH", "CASE", "DEFAULT", "ARRAY",
  "CONST", "INT", "CHAR", "FLOAT", "DOUBLE", "VOID", "BOOL", "CONTINUE",
  "LONG", "UNTIL", "BREAK", "GAD", "SEMI", "COLON", "TCEQ", "TCNE", "TCLT",
  "TCLE", "TCGT", "TCGE", "TEQUAL", "TLPAREN", "TRPAREN", "TLBRACE",
  "TRBRACE", "TLBRACK", "TRBRACK", "TCOMMA", "TDOT", "ARW", "BXOR", "BNOT",
  "OR", "AND", "TPLUS", "TMINUS", "TMUL", "TDIV", "TINTEGER",
  "TIDENTIFIER", "TDOUBLE", "CHARACTER", "STRING", "$accept", "program",
  "stmts", "stmt", "IfStmt", "LoopStmt", "WhileStmt", "ForStmt",
  "SwitchStmt", "CaseList", "CaseStmt", "BreakStmt", "block", "var_decl",
  "extern_decl", "func_decl", "func_decl_args", "ident", "expression",
  "call_args", "const_value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     167,   -29,    83,    -9,    -7,    -6,    -4,   -66,   -29,    83,
     -66,   -66,   -66,   -66,   -66,    38,   167,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -28,   337,   -66,
     -29,   -25,   337,    83,    83,    83,    83,    21,   214,   -66,
     -66,    83,    83,    83,   -22,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    24,   157,   238,
     247,   271,    83,   -66,   337,   337,   -21,   283,    83,   -29,
      10,    20,    20,    20,    20,    20,    20,   343,   349,   -13,
     -13,   -66,   -66,   -29,    83,    26,    26,    29,   307,   -66,
      83,    40,   337,   -66,   -20,   -29,    32,   -18,   183,   107,
      67,   -66,   -66,   -66,   337,    83,    26,   -29,   -12,   -66,
     -66,    83,   -66,   144,    26,    -8,   337,   -66,   -66,   313,
     -66,   -66,    83,    50,   -66,   -66,    26,   208,    26,   -66,
      26,   -66,   -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
      61,    36,    62,    63,    64,     0,     2,     3,    12,    13,
      17,    16,    11,    10,     5,     7,     6,    39,     8,    40,
       0,    39,     9,     0,     0,     0,     0,    53,     0,     1,
       4,     0,    58,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    37,    59,     0,     0,     0,    33,
       0,    47,    48,    49,    50,    51,    52,    42,    41,    45,
      46,    43,    44,    33,     0,     0,     0,     0,     0,    38,
       0,    56,    29,    34,     0,     0,     0,     0,     0,     0,
      14,    18,    22,    54,    60,     0,     0,     0,    28,    30,
      31,     0,    27,     0,     0,     0,    57,    32,    35,     0,
      26,    15,     0,     0,    20,    21,     0,     0,     0,    19,
       0,    24,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -19,   -15,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -51,   -65,   -66,   -66,    -5,    56,    -2,   -66,
     -66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    15,    16,    17,    18,    19,    20,    21,    22,   115,
     125,    23,   100,    24,    25,    26,    94,    31,    28,    66,
      29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    40,   122,   123,    93,    41,    42,    38,    41,    42,
      43,    68,    69,    43,    89,   106,    70,   110,    93,    90,
     107,    68,   107,    11,    11,    33,    70,    34,    35,   124,
      36,    58,    59,    60,    61,   101,    55,    56,    39,    64,
      65,    67,   118,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,   117,    27,    30,    83,    62,
      88,    96,    99,   121,    37,   102,    92,    53,    54,    55,
      56,   109,    27,   105,   114,   129,   128,   131,    97,   132,
     113,     0,    98,    44,     0,     0,    57,     0,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,     0,   116,     0,     0,     0,     8,     0,   119,
       1,     2,     3,     4,     0,     5,     6,     9,     0,     0,
     127,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       7,     8,     0,     0,    10,    11,    12,    13,    14,    95,
       0,     9,     0,     0,   112,     0,     0,     1,     2,     3,
       4,   108,     5,     6,     0,    27,     0,     0,    10,    11,
      12,    13,    14,    95,     0,     0,     0,     7,     8,    27,
       1,     2,     3,     4,     0,     5,     6,     0,     9,     0,
       0,   120,    84,     0,    45,    46,    47,    48,    49,    50,
       7,     8,     0,     0,     0,    10,    11,    12,    13,    14,
       0,     9,    51,    52,    53,    54,    55,    56,   111,     0,
      45,    46,    47,    48,    49,    50,     0,     0,    10,    11,
      12,    13,    14,     0,     0,     0,     0,     0,    51,    52,
      53,    54,    55,    56,   130,    45,    46,    47,    48,    49,
      50,    45,    46,    47,    48,    49,    50,     0,     0,    63,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    51,
      52,    53,    54,    55,    56,    45,    46,    47,    48,    49,
      50,     0,     0,    85,    45,    46,    47,    48,    49,    50,
       0,     0,    86,    51,    52,    53,    54,    55,    56,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    45,    46,
      47,    48,    49,    50,     0,     0,    87,     0,     0,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    91,     0,     0,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    45,    46,    47,    48,    49,    50,
      45,    46,    47,    48,    49,    50,   103,     0,   126,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    51,    52,
      53,    54,    55,    56,    45,    46,    47,    48,    49,    50,
      45,    46,    47,    48,    49,    50,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,    52,
      53,    54,    55,    56,     0,     0,    53,    54,    55,    56
};

static const yytype_int16 yycheck[] =
{
       2,    16,    10,    11,    69,    33,    34,     9,    33,    34,
      38,    33,    34,    38,    35,    35,    38,    35,    83,    40,
      40,    33,    40,    52,    52,    34,    38,    34,    34,    37,
      34,    33,    34,    35,    36,    86,    49,    50,     0,    41,
      42,    43,   107,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,   106,     0,     1,    34,    38,
      62,    51,    36,   114,     8,    36,    68,    47,    48,    49,
      50,    39,    16,    33,     7,   126,    26,   128,    83,   130,
      99,    -1,    84,    27,    -1,    -1,    30,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    24,    -1,   111,
       3,     4,     5,     6,    -1,     8,     9,    34,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    51,    52,    53,    54,    55,    83,
      -1,    34,    -1,    -1,    37,    -1,    -1,     3,     4,     5,
       6,    95,     8,     9,    -1,    99,    -1,    -1,    51,    52,
      53,    54,    55,   107,    -1,    -1,    -1,    23,    24,   113,
       3,     4,     5,     6,    -1,     8,     9,    -1,    34,    -1,
      -1,    37,    25,    -1,    27,    28,    29,    30,    31,    32,
      23,    24,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      -1,    34,    45,    46,    47,    48,    49,    50,    25,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    26,    27,    28,    29,    30,    31,
      32,    27,    28,    29,    30,    31,    32,    -1,    -1,    35,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    45,
      46,    47,    48,    49,    50,    27,    28,    29,    30,    31,
      32,    -1,    -1,    35,    27,    28,    29,    30,    31,    32,
      -1,    -1,    35,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    27,    28,
      29,    30,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    45,    46,    47,    48,
      49,    50,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    27,    28,    29,    30,    31,    32,
      27,    28,    29,    30,    31,    32,    39,    -1,    35,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    45,    46,
      47,    48,    49,    50,    27,    28,    29,    30,    31,    32,
      27,    28,    29,    30,    31,    32,    27,    28,    29,    30,
      31,    32,    45,    46,    47,    48,    49,    50,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    23,    24,    34,
      51,    52,    53,    54,    55,    57,    58,    59,    60,    61,
      62,    63,    64,    67,    69,    70,    71,    73,    74,    76,
      73,    73,    74,    34,    34,    34,    34,    73,    74,     0,
      59,    33,    34,    38,    73,    27,    28,    29,    30,    31,
      32,    45,    46,    47,    48,    49,    50,    73,    74,    74,
      74,    74,    38,    35,    74,    74,    75,    74,    33,    34,
      38,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    34,    25,    35,    35,    35,    74,    35,
      40,    39,    74,    69,    72,    73,    51,    72,    74,    36,
      68,    68,    36,    39,    74,    33,    35,    40,    73,    39,
      35,    25,    37,    58,     7,    65,    74,    68,    69,    74,
      37,    68,    10,    11,    37,    66,    35,    74,    26,    68,
      26,    68,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    63,
      64,    65,    65,    66,    66,    67,    68,    68,    69,    69,
      69,    70,    71,    72,    72,    72,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      75,    76,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     5,     7,     1,     1,     5,     9,
       7,     2,     0,     4,     3,     1,     3,     2,     2,     4,
       5,     6,     6,     0,     1,     3,     1,     3,     4,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     5,     3,     4,     6,     0,     1,
       3,     1,     1,     1,     1
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
#line 103 "parser.y"
          { 
        programBlock = (yyvsp[0].block); 
    }
#line 1289 "parser.cpp"
    break;

  case 3: /* stmts: stmt  */
#line 107 "parser.y"
         {
        (yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[0].stmt));
    }
#line 1297 "parser.cpp"
    break;

  case 4: /* stmts: stmts stmt  */
#line 110 "parser.y"
                 {
       (yyvsp[-1].block)->statements.push_back((yyvsp[0].stmt));
    }
#line 1305 "parser.cpp"
    break;

  case 8: /* stmt: expression  */
#line 117 "parser.y"
                      { (yyval.stmt) = new NExpressionStatement(*(yyvsp[0].expr)); }
#line 1311 "parser.cpp"
    break;

  case 9: /* stmt: TRETURN expression  */
#line 118 "parser.y"
                              { (yyval.stmt) = new NReturnStatement(*(yyvsp[0].expr)); }
#line 1317 "parser.cpp"
    break;

  case 10: /* stmt: BreakStmt  */
#line 120 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].breakStatement); }
#line 1323 "parser.cpp"
    break;

  case 11: /* stmt: SwitchStmt  */
#line 121 "parser.y"
                {  (yyval.stmt) = (yyvsp[0].switchStatement);}
#line 1329 "parser.cpp"
    break;

  case 12: /* stmt: IfStmt  */
#line 122 "parser.y"
           { (yyval.stmt) = (yyvsp[0].ifStatement); }
#line 1335 "parser.cpp"
    break;

  case 13: /* stmt: LoopStmt  */
#line 123 "parser.y"
             { (yyval.stmt) = (yyvsp[0].loopStatement); }
#line 1341 "parser.cpp"
    break;

  case 14: /* IfStmt: IF TLPAREN expression TRPAREN block  */
#line 129 "parser.y"
                                           {
        (yyval.ifStatement) = new NIfStatement(*(yyvsp[-2].expr), *(yyvsp[0].block));
    }
#line 1349 "parser.cpp"
    break;

  case 15: /* IfStmt: IF TLPAREN expression TRPAREN block ELSE block  */
#line 132 "parser.y"
                                                   {
        (yyval.ifStatement) = new NIfStatement(*(yyvsp[-4].expr), *(yyvsp[-2].block), (yyvsp[0].block));
    }
#line 1357 "parser.cpp"
    break;

  case 16: /* LoopStmt: ForStmt  */
#line 137 "parser.y"
         { (yyval.loopStatement) = (yyvsp[0].forStatement); }
#line 1363 "parser.cpp"
    break;

  case 17: /* LoopStmt: WhileStmt  */
#line 138 "parser.y"
            { (yyval.loopStatement) = (yyvsp[0].whileStatement); }
#line 1369 "parser.cpp"
    break;

  case 18: /* WhileStmt: WHILE TLPAREN expression TRPAREN block  */
#line 141 "parser.y"
                                                   {
        (yyval.whileStatement) = new NWhileStatement(*(yyvsp[-2].expr), *(yyvsp[0].block));
    }
#line 1377 "parser.cpp"
    break;

  case 19: /* ForStmt: FOR TLPAREN expression SEMI expression SEMI expression TRPAREN block  */
#line 146 "parser.y"
   {
        (yyval.forStatement) = new NForStatement(*(yyvsp[-4].expr), *(yyvsp[-6].expr),*(yyvsp[-2].expr),*(yyvsp[0].block));
    }
#line 1385 "parser.cpp"
    break;

  case 20: /* SwitchStmt: SWITCH TLPAREN expression TRPAREN TLBRACE CaseList TRBRACE  */
#line 150 "parser.y"
      {  (yyval.switchStatement) = new NSwitchStatement((yyvsp[-4].expr),(yyvsp[-1].caseList));   }
#line 1391 "parser.cpp"
    break;

  case 21: /* CaseList: CaseList CaseStmt  */
#line 153 "parser.y"
                                                                                                                {  (yyval.caseList) = (yyvsp[-1].caseList); (yyval.caseList)->push_back((yyvsp[0].caseStatement));   }
#line 1397 "parser.cpp"
    break;

  case 22: /* CaseList: %empty  */
#line 154 "parser.y"
                                                                                                                        {  (yyval.caseList) = new CaseList();   }
#line 1403 "parser.cpp"
    break;

  case 23: /* CaseStmt: CASE expression COLON block  */
#line 157 "parser.y"
                                                                                                                {  (yyval.caseStatement) = new NCaseStatement((yyvsp[-2].expr),(yyvsp[0].block));   }
#line 1409 "parser.cpp"
    break;

  case 24: /* CaseStmt: DEFAULT COLON block  */
#line 158 "parser.y"
                                                                                                {  (yyval.caseStatement) = new NCaseStatement((yyvsp[0].block));   }
#line 1415 "parser.cpp"
    break;

  case 25: /* BreakStmt: BREAK  */
#line 160 "parser.y"
                      {  (yyval.breakStatement) = new NBreakStatement();   }
#line 1421 "parser.cpp"
    break;

  case 26: /* block: TLBRACE stmts TRBRACE  */
#line 165 "parser.y"
                          {
        (yyval.block) = (yyvsp[-1].block);
    }
#line 1429 "parser.cpp"
    break;

  case 27: /* block: TLBRACE TRBRACE  */
#line 168 "parser.y"
                      {
        (yyval.block) = new NBlock();
    }
#line 1437 "parser.cpp"
    break;

  case 28: /* var_decl: ident ident  */
#line 173 "parser.y"
                         { (yyval.stmt) = new NVariableDeclaration(*(yyvsp[-1].ident), *(yyvsp[0].ident)); }
#line 1443 "parser.cpp"
    break;

  case 29: /* var_decl: ident ident TEQUAL expression  */
#line 174 "parser.y"
                                      { (yyval.stmt) = new NVariableDeclaration(*(yyvsp[-3].ident), *(yyvsp[-2].ident), (yyvsp[0].expr)); }
#line 1449 "parser.cpp"
    break;

  case 30: /* var_decl: ident ident TLBRACK TINTEGER TRBRACK  */
#line 175 "parser.y"
                                             { // 定义数组
        (yyval.stmt) = new NArrayDeclaration(*(yyvsp[-4].ident), *(yyvsp[-3].ident), (yyvsp[-1].iVal));
    }
#line 1457 "parser.cpp"
    break;

  case 31: /* extern_decl: TEXTERN ident ident TLPAREN func_decl_args TRPAREN  */
#line 180 "parser.y"
                  { (yyval.stmt) = new NExternDeclaration(*(yyvsp[-4].ident), *(yyvsp[-3].ident), *(yyvsp[-1].var_decls)); delete (yyvsp[-1].var_decls); }
#line 1463 "parser.cpp"
    break;

  case 32: /* func_decl: ident ident TLPAREN func_decl_args TRPAREN block  */
#line 183 "parser.y"
  { (yyval.stmt) = new NFunctionDeclaration(*(yyvsp[-5].ident), *(yyvsp[-4].ident), *(yyvsp[-2].var_decls), *(yyvsp[0].block)); delete (yyvsp[-2].var_decls); }
#line 1469 "parser.cpp"
    break;

  case 33: /* func_decl_args: %empty  */
#line 186 "parser.y"
                              { (yyval.var_decls) = new VariableList(); }
#line 1475 "parser.cpp"
    break;

  case 34: /* func_decl_args: var_decl  */
#line 187 "parser.y"
             { (yyval.var_decls) = new VariableList(); (yyval.var_decls)->push_back((yyvsp[0].var_decl)); }
#line 1481 "parser.cpp"
    break;

  case 35: /* func_decl_args: func_decl_args TCOMMA var_decl  */
#line 188 "parser.y"
                                   { (yyvsp[-2].var_decls)->push_back((yyvsp[0].var_decl)); }
#line 1487 "parser.cpp"
    break;

  case 36: /* ident: TIDENTIFIER  */
#line 193 "parser.y"
              { (yyval.ident) = new NIdentifier(*(yyvsp[0].sVal)); delete (yyvsp[0].sVal); }
#line 1493 "parser.cpp"
    break;

  case 37: /* expression: ident TEQUAL expression  */
#line 197 "parser.y"
                                       { (yyval.expr) = new NAssignment(*(yyvsp[-2].ident), *(yyvsp[0].expr)); }
#line 1499 "parser.cpp"
    break;

  case 38: /* expression: ident TLPAREN call_args TRPAREN  */
#line 198 "parser.y"
                                    { (yyval.expr) = new NMethodCall(*(yyvsp[-3].ident), *(yyvsp[-1].expressionList)); delete (yyvsp[-1].expressionList); }
#line 1505 "parser.cpp"
    break;

  case 39: /* expression: ident  */
#line 199 "parser.y"
          { (yyval.ident) = (yyvsp[0].ident); }
#line 1511 "parser.cpp"
    break;

  case 41: /* expression: expression AND expression  */
#line 201 "parser.y"
                              {(yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));}
#line 1517 "parser.cpp"
    break;

  case 42: /* expression: expression OR expression  */
#line 202 "parser.y"
                             {(yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));}
#line 1523 "parser.cpp"
    break;

  case 43: /* expression: expression TMUL expression  */
#line 203 "parser.y"
                               { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1529 "parser.cpp"
    break;

  case 44: /* expression: expression TDIV expression  */
#line 204 "parser.y"
                               { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1535 "parser.cpp"
    break;

  case 45: /* expression: expression TPLUS expression  */
#line 205 "parser.y"
                                { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1541 "parser.cpp"
    break;

  case 46: /* expression: expression TMINUS expression  */
#line 206 "parser.y"
                                 { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1547 "parser.cpp"
    break;

  case 47: /* expression: expression TCEQ expression  */
#line 207 "parser.y"
                               { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1553 "parser.cpp"
    break;

  case 48: /* expression: expression TCNE expression  */
#line 208 "parser.y"
                               { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1559 "parser.cpp"
    break;

  case 49: /* expression: expression TCLT expression  */
#line 209 "parser.y"
                               { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1565 "parser.cpp"
    break;

  case 50: /* expression: expression TCLE expression  */
#line 210 "parser.y"
                               { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1571 "parser.cpp"
    break;

  case 51: /* expression: expression TCGT expression  */
#line 211 "parser.y"
                               { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1577 "parser.cpp"
    break;

  case 52: /* expression: expression TCGE expression  */
#line 212 "parser.y"
                               { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1583 "parser.cpp"
    break;

  case 53: /* expression: GAD ident  */
#line 213 "parser.y"
             {//数组和地址表达式
        (yyval.expr) = new getAddr(*(yyvsp[0].ident));
    }
#line 1591 "parser.cpp"
    break;

  case 54: /* expression: GAD ident TLBRACK expression TRBRACK  */
#line 216 "parser.y"
                                           {
        (yyval.expr) = new getArrayAddr(*(yyvsp[-3].ident), *(yyvsp[-1].expr));
    }
#line 1599 "parser.cpp"
    break;

  case 55: /* expression: TLPAREN expression TRPAREN  */
#line 219 "parser.y"
                                 {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1607 "parser.cpp"
    break;

  case 56: /* expression: ident TLBRACK expression TRBRACK  */
#line 222 "parser.y"
                                        { // array element access
        (yyval.expr) = new ArrayElement(*(yyvsp[-3].ident), *(yyvsp[-1].expr));
    }
#line 1615 "parser.cpp"
    break;

  case 57: /* expression: ident TLBRACK expression TRBRACK TEQUAL expression  */
#line 225 "parser.y"
                                                         { // array element access
        (yyval.expr) = new ArrayElementAssign(*(yyvsp[-5].ident), *(yyvsp[-3].expr), *(yyvsp[0].expr));
    }
#line 1623 "parser.cpp"
    break;

  case 58: /* call_args: %empty  */
#line 230 "parser.y"
                          { (yyval.expressionList) = new ExpressionList(); }
#line 1629 "parser.cpp"
    break;

  case 59: /* call_args: expression  */
#line 231 "parser.y"
                               { (yyval.expressionList) = new ExpressionList(); (yyval.expressionList)->push_back((yyvsp[0].expr)); }
#line 1635 "parser.cpp"
    break;

  case 60: /* call_args: call_args TCOMMA expression  */
#line 232 "parser.y"
                                                 { (yyvsp[-2].expressionList)->push_back((yyvsp[0].expr)); }
#line 1641 "parser.cpp"
    break;

  case 61: /* const_value: TINTEGER  */
#line 236 "parser.y"
                           { (yyval.expr) = new NInteger((yyvsp[0].iVal)); }
#line 1647 "parser.cpp"
    break;

  case 62: /* const_value: TDOUBLE  */
#line 237 "parser.y"
                          { (yyval.expr) = new NDouble((yyvsp[0].dVal)); }
#line 1653 "parser.cpp"
    break;

  case 63: /* const_value: CHARACTER  */
#line 238 "parser.y"
                { (yyval.expr) = new NChar((yyvsp[0].cVal));}
#line 1659 "parser.cpp"
    break;

  case 64: /* const_value: STRING  */
#line 239 "parser.y"
             { (yyval.expr) = new NString(*(yyvsp[0].strVal)); }
#line 1665 "parser.cpp"
    break;


#line 1669 "parser.cpp"

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

#line 241 "parser.y"

