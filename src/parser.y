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
  int token;//标注终结符token
  //标注int double char string
  int iVal;
  std::string *sVal;
  double dVal;
  char cVal;
  std::string *strVal;

	Node *node;
	NBlock *block;

  //定义抽象类
  NDeclaration *ndelc;//declaration抽象类
  std::vector<NDeclaration*> *ndelcs;//declarations抽象类
  
  //变量定义
  NVariableDeclaration *var_decl;
	std::vector<NVariableDeclaration*> *var_decls;
//函数定义
  NFunctionDeclaration *func_decl;
  //std::vector<NFunctionDeclaration*> *func_decls;
  

  NExpression *expr;//表达式
	NStatement *stmt;//声明
	NIdentifier *ident;//标识符
  
  //关键词
	NForStatement *forStatement;
  NIfStatement *ifStatement;
  NSwitchStatement *switchStatement;
  NWhileStatement *whileStatement;
  NCaseStatement *caseStatement;
  NLoopStatement *loopStatement;
  CaseList *caseList;
  NBreakStatement *breakStatement;
  

	std::vector<NExpression*> *expressionList;

	
	
}

/* 定义终结符token
 */
%token  <token>TEXTERN TRETURN FOR IF ELSE WHILE SWITCH CASE DEFAULT ARRAY
CONTINUE LONG UNTIL BREAK GAD SEMI COLON 
%token  <token>TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token  <token>TLPAREN TRPAREN TLBRACE TRBRACE TLBRACK TRBRACK TCOMMA TDOT
%token  <token>ARW BXOR BNOT OR AND
%token <token>TPLUS TMINUS TMUL TDIV
%token<iVal> TINTEGER
%token<sVal> TIDENTIFIER 
%token<dVal> TDOUBLE
%token<cVal> CHARACTER
%token<strVal> STRING
/* 定义我们的非终结符所代表的节点类型。这些类型引用了上面的%union声明
 */
%type <ident> ident
%type <expr> const_value expression 
%type <block> program stmts block
%type <stmt> stmt var_decl func_decl extern_decl
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
/* 数学运算符的运算符优先级 */
%left OR
%left AND
%left TCEQ TCNE TCLT TCLE TCGT TCGE
%left TPLUS TMINUS
%left TMUL TDIV



%start program

%%
program: 
    stmts { 
        programBlock = $1; 
    };
	stmts: //多个声明
    stmt {
        $$ = new NBlock(); $$->statements.push_back($<stmt>1);
    }
    | stmts stmt {
       $1->statements.push_back($<stmt>2);
    };


  stmt ://声明
  var_decl| func_decl | extern_decl
	 | expression { $$ = new NExpressionStatement(*$1); }
	 | TRETURN expression { $$ = new NReturnStatement(*$2); }
   //| TRETURN { $$ = new NReturnStatement(); }
	 | BreakStmt  { $$ = $1; }
   | SwitchStmt	{  $$ = $1;} 
   |IfStmt { $$ = $1; }
   |LoopStmt { $$ = $1; }
    ;


//以下都是关键字声明
  IfStmt:
       IF TLPAREN expression TRPAREN block {
        $$ = new NIfStatement(*$3, *$5);
    }
  | IF TLPAREN expression TRPAREN block ELSE block {
        $$ = new NIfStatement(*$3, *$5, $7);
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
  SwitchStmt:	SWITCH TLPAREN expression TRPAREN TLBRACE CaseList TRBRACE		
      {  $$ = new NSwitchStatement(*$3,*$6);   }
        ;

  CaseList:	CaseList CaseStmt										{  $$ = $1; $$->push_back($2);   }	
        |														{  $$ = new CaseList();   }
        ;

  CaseStmt:	CASE expression COLON block									{  $$ = new NCaseStatement($2,*$4);   }
        | DEFAULT COLON block									{  $$ = new NCaseStatement(*$3);   }
        ;
  BreakStmt:	BREAK {  $$ = new NBreakStatement();   }
  ;
  
  //代码块
  block: 
    TLBRACE stmts TRBRACE {
        $$ = $2;
    }
    | TLBRACE TRBRACE {
        $$ = new NBlock();
    };

  //变量定义、函数定义，函数参数定义，extern定义
  var_decl : ident ident { $$ = new NVariableDeclaration(*$1, *$2); }
      | ident ident TEQUAL expression { $$ = new NVariableDeclaration(*$1, *$2, $4); }
      | ident ident TLBRACK TINTEGER TRBRACK { // 定义数组
        $$ = new NArrayDeclaration(*$1, *$2, $4);
    }
      ;
  extern_decl : TEXTERN ident ident TLPAREN func_decl_args TRPAREN
                  { $$ = new NExternDeclaration(*$2, *$3, *$5); delete $5; }
              ;
  func_decl : ident ident TLPAREN func_decl_args TRPAREN block 
  { $$ = new NFunctionDeclaration(*$1, *$2, *$4, *$6); delete $4; }
  ;

  func_decl_args : /*blank*/  { $$ = new VariableList(); }
  | var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
  | func_decl_args TCOMMA var_decl { $1->push_back($<var_decl>3); }
  ;

  //标识符
  ident : 
  TIDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
      ;

  //表达式
  expression : ident TEQUAL expression { $$ = new NAssignment(*$<ident>1, *$3); }
  | ident TLPAREN call_args TRPAREN { $$ = new NMethodCall(*$1, *$3); delete $3; }
  | ident { $<ident>$ = $1; }
  | const_value
  /*以下$2的值为yyval.token，在实现ast.cpp时需要yacc生成的宏*/
  | expression AND expression {$$ = new NBinaryOperator(*$1, $2, *$3);}
  | expression OR expression {$$ = new NBinaryOperator(*$1, $2, *$3);}
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
  |GAD ident {//数组和地址表达式
        $$ = new getAddr(*$2);
    }
    | GAD ident TLBRACK expression TRBRACK {
        $$ = new getArrayAddr(*$2, *$4);
    }
    | TLPAREN expression TRPAREN {
        $$ = $2;
    }
     | ident TLBRACK expression TRBRACK { // array element access
        $$ = new ArrayElement(*$1, *$3);
    }
    | ident TLBRACK expression TRBRACK TEQUAL expression { // array element access
        $$ = new ArrayElementAssign(*$1, *$3, *$6);
    }
	 ;

   call_args : /*blank*/  { $$ = new ExpressionList(); }//调用函数时的参数
		  | expression { $$ = new ExpressionList(); $$->push_back($1); }
		  | call_args TCOMMA expression  { $1->push_back($3); }
		  ;


    const_value : TINTEGER { $$ = new NInteger($1); }//const值
		| TDOUBLE { $$ = new NDouble($1); }
    | CHARACTER { $$ = new NChar($1);}
    | STRING { $$ = new NString(*$1); }
		;
%%
