/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EXTERN = 258,                  /* EXTERN  */
    RETURN = 259,                  /* RETURN  */
    FOR = 260,                     /* FOR  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    WHILE = 263,                   /* WHILE  */
    SWITCH = 264,                  /* SWITCH  */
    CASE = 265,                    /* CASE  */
    DEFAULT = 266,                 /* DEFAULT  */
    ARRAY = 267,                   /* ARRAY  */
    CONTINUE = 268,                /* CONTINUE  */
    UNTIL = 269,                   /* UNTIL  */
    BREAK = 270,                   /* BREAK  */
    GAD = 271,                     /* GAD  */
    SEMI = 272,                    /* SEMI  */
    COLON = 273,                   /* COLON  */
    INT = 274,                     /* INT  */
    LONG = 275,                    /* LONG  */
    CHAR = 276,                    /* CHAR  */
    FLOAT = 277,                   /* FLOAT  */
    DOUBLE = 278,                  /* DOUBLE  */
    VOID = 279,                    /* VOID  */
    CEQ = 280,                     /* CEQ  */
    CNE = 281,                     /* CNE  */
    CLT = 282,                     /* CLT  */
    CLE = 283,                     /* CLE  */
    CGT = 284,                     /* CGT  */
    CGE = 285,                     /* CGE  */
    EQUAL = 286,                   /* EQUAL  */
    LPAREN = 287,                  /* LPAREN  */
    RPAREN = 288,                  /* RPAREN  */
    LBRACE = 289,                  /* LBRACE  */
    RBRACE = 290,                  /* RBRACE  */
    LBRACK = 291,                  /* LBRACK  */
    RBRACK = 292,                  /* RBRACK  */
    COMMA = 293,                   /* COMMA  */
    DOT = 294,                     /* DOT  */
    ARW = 295,                     /* ARW  */
    XOR = 296,                     /* XOR  */
    NOT = 297,                     /* NOT  */
    OR = 298,                      /* OR  */
    AND = 299,                     /* AND  */
    PLUS = 300,                    /* PLUS  */
    MINUS = 301,                   /* MINUS  */
    MUL = 302,                     /* MUL  */
    DIV = 303,                     /* DIV  */
    INTEGER = 304,                 /* INTEGER  */
    IDENTIFIER = 305,              /* IDENTIFIER  */
    REAL = 306,                    /* REAL  */
    CHARACTER = 307,               /* CHARACTER  */
    STRING = 308                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
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

#line 161 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
