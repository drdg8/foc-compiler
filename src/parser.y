%{
	#include "ast.hpp"
        #include <cstdio>
        #include <cstdlib>
        #include <string>
#include <iostream>
	NBlock *programBlock; /* the top level root node of our final AST */

	extern int yylex();
	void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }
%}

/* Represents the many different ways we can access our data */
%union {
  int token;
  
  int iVal;
  std::string *sVal;
  double dVal;
  char cVal;
  bool bVal;
  std::string *strVal;

	Node *node;
	NBlock *block;
	
  NDeclaration *ndelc;//declaration抽象类
  std::vector<NDeclaration*> *ndelcs;//declarations抽象类
  
  NVariableDeclaration *var_decl;//变量定义
	std::vector<NVariableDeclaration*> *var_decls;

  NFunctionDeclaration *func_decl//函数定义
  std::vector<NFunctionDeclaration*> *func_decls 
  NFuncBody *func_body;//函数体

  NExpression *expr;
	NStatement *statement;
	NIdentifier *ident;//VarType就是NIdentifier
	NForStatement *forStatement;
  NIfStatement *ifStatement;
  NWhileStatement *whileStatement;
  NCaseStatement *caseStatement;
  NLoopStatement *loopStatement;

  CaseList *caseList;
  NBreakStatement *breakStatement;
  

	std::vector<NExpression*> *exprvec;

	
	
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token  <token>TEXTERN TRETURN FOR IF ELSE DO WHILE SWITCH CASE DEFAULT ARRAY CONST INT CHAR FLOAT DOUBLE
VOID BOOL CONTINUE LONG UNTIL BREAK
%token  <token>TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token  <token>TLPAREN TRPAREN TLBRACE TRBRACE TLBRACK TRBRACK TCOMMA TDOT
%token  <token>ARW BXOR BNOT
%token <token>TPLUS TMINUS TMUL TDIV
%token<iVal> TINTEGER
%token<sVal> TIDENTIFIER 
%token<dVal> TDOUBLE
%token<cVal> CHARACTER
%token<strVal> STRING
/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident
%type <expr> const_value expression
%type <block> program stmts block
%type <statement> stmt var_decl func_decl extern_decl //non_label_stmt
%type<ifStatement>							IfStmt
%type<forStatement>							ForStmt
%type<whileStatement>						WhileStmt
%type<doStatement>							DoStmt
%type<switchStatement>						SwitchStmt
%type<caseList>							CaseList
%type<caseStatement>							CaseStmt
%type<breakStatement>						BreakStmt
%type<loopStatement>            LoopStmt
/* Operator precedence for mathematical operators */
%left TCEQ TCNE TCLT TCLE TCGT TCGE
%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%
program: 
    stmts { 
        programBlock = $1; 
    };
	stmts: 
    stmt {
        $$ = new NBlock(); $$->statements.push_back($<stmt>1);
    }
    | stmts stmt {
       $1->statements.push_back($<stmt>2);
    };

  stmt :
  var_decl| func_decl | extern_decl

	 | expression { $$ = new NExpressionStatement(*$1); }
	 | TRETURN expression { $$ = new NReturnStatement(*$2); }
   | TRETURN { $$ = new NReturnStatement(); }
	 | BREAK  {  $$ = new BreakStatementNode(); }
   | IF TLPAREN expression TRPAREN block {
        $$ = new NIfStatement(*$3, *$5);
    }
   | IF TLPAREN expression TRPAREN block ELSE block {
        $$ = new NIfStatement(*$3, *$5, *$7);
    }
%%
