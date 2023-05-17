/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 155 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
