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
  //std::vector<NFunctionDeclaration*> *func_decls
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
  

	std::vector<NExpression*> *expressionList;

	
	
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token  <token>TEXTERN TRETURN FOR IF ELSE WHILE SWITCH CASE DEFAULT ARRAY CONST INT CHAR FLOAT DOUBLE
VOID BOOL CONTINUE LONG UNTIL BREAK GAD SEMI COLON
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

%type<switchStatement>						SwitchStmt
%type<caseList>							CaseList
%type<caseStatement>							CaseStmt
%type<breakStatement>						BreakStmt
%type<loopStatement>            LoopStmt
%type <expressionList>             call_args
%type <var_decls>               func_decl_args
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
	 | BreakStmt  { $$ = $1; }
   | SwitchStmt	{  $$ = $1;} 
   |IfStmt { $$ = $1; }
   |LoopStmt { $$ = $1; }
    ;
    IfStmt:
       IF TLPAREN expression TRPAREN block {
        $$ = new NIfStatement(*$3, *$5);
    }
   | IF TLPAREN expression TRPAREN block ELSE block {
        $$ = new NIfStatement(*$3, *$5, *$7);
    }
  LoopStmt:
  ForStmt{ $$ = $1; }
  |WhileStmt{ $$ = $1; }
  ;
  WhileStmt:WHILE TLPAREN expression TRPAREN block {
        $$ = new NWhileStatement(*$3, *$5);
    };
   ForStmt:FOR TLPAREN expression SEMI expression SEMI expression TRPAREN block
   {
        $$ = new NForStatement(*$5, *$3,*$7,*$9);
    };
  block: 
    TLBRACE stmts TRBRACE {
        $$ = $2;
    }
    | TLBRACE TRBRACE {
        $$ = new NBlock();
    };

var_decl : ident ident { $$ = new NVariableDeclaration(*$1, *$2); }
		 | ident ident TEQUAL expression { $$ = new NVariableDeclaration(*$1, *$2, $4); }
		 ;
extern_decl : TEXTERN ident ident TLPAREN func_decl_args TRPAREN
                { $$ = new NExternDeclaration(*$2, *$3, *$5); delete $5; }
            ;
ident : 
TIDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
	  ;
  expression : ident TEQUAL expression { $$ = new NAssignment(*$<ident>1, *$3); }
	 | ident TLPAREN call_args TRPAREN { $$ = new NMethodCall(*$1, *$3); delete $3; }
	 | ident { $<ident>$ = $1; }
	 | const_value
         | expression TMUL expression { $$ = new NBinaryOperator(*$1, $2, *$3); }
         | expression TDIV expression { $$ = new NBinaryOperator(*$1, $2, *$3); }
         | expression TPLUS expression { $$ = new NBinaryOperator(*$1, $2, *$3); }
         | expression TMINUS expression { $$ = new NBinaryOperator(*$1, $2, *$3); }
 	 | expression TCEQ expression { $$ = new NBinaryOperator(*$1, $2, *$3); }
   | expression TCNE expression { $$ = new NBinaryOperator(*$1, $2, *$3); }
   | expression TCLT expression { $$ = new NBinaryOperator(*$1, $2, *$3); }
   | expression TCLE expression { $$ = new NBinaryOperator(*$1, $2, *$3); }
   | expression TCGT expression { $$ = new NBinaryOperator(*$1, $2, *$3); }
   | expression TCGE expression { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | TLPAREN expression TRPAREN { $$ = $2; }
	 ;

   call_args : /*blank*/  { $$ = new ExpressionList(); }
		  | expression { $$ = new ExpressionList(); $$->push_back($1); }
		  | call_args TCOMMA expression  { $1->push_back($3); }
		  ;

      func_decl : ident ident TLPAREN func_decl_args TRPAREN block 
			{ $$ = new NFunctionDeclaration(*$1, *$2, *$4, *$6); delete $4; }
		  ;
      func_decl_args : /*blank*/  { $$ = new VariableList(); }
		  | var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
		  | func_decl_args TCOMMA var_decl { $1->push_back($<var_decl>3); }
		  ;
    const_value : TINTEGER { $$ = new NInteger($1); delete $1; }
		| TDOUBLE { $$ = new NDouble($1); delete $1; }
		;
    SwitchStmt:	SWITCH TLPAREN expression TRPAREN TLBRACE CaseList TRBRACE		
    {  $$ = new NSwitchStatement($3,$6);   }
			;

CaseList:	CaseList CaseStmt										{  $$ = $1; $$->push_back($2);   }	
			|														{  $$ = new CaseList();   }
			;

CaseStmt:	CASE expression COLON block									{  $$ = new NCaseStatement($2,$4);   }
			| DEFAULT COLON block									{  $$ = new NCaseStatement($3);   }
			;
BreakStmt:	BREAK {  $$ = new NBreakStatement();   }
;
%%
