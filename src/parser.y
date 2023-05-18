%{
	#include "ast.hpp"
  #include <cstdio>
  #include <cstdlib>
  #include <string>
  #include <iostream>

	Block *programBlock; /* the top level root node of our final AST */

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
}

/* 定义终结符token
 */
%token  <token>EXTERN RETURN FOR IF ELSE WHILE SWITCH CASE DEFAULT ARRAY
%token  <token> CONTINUE UNTIL BREAK GAD SEMI COLON 
%token  <token> INT LONG CHAR FLOAT DOUBLE VOID
%token  <token>CEQ CNE CLT CLE CGT CGE EQUAL
%token  <token>LPAREN RPAREN LBRACE RBRACE LBRACK RBRACK COMMA DOT
%token  <token>ARW XOR NOT OR AND
%token <token> PLUS MINUS MUL DIV
%token<iVal> INTEGER
%token<sVal> IDENTIFIER 
%token<dVal> REAL
%token<cVal> CHARACTER
%token<strVal> STRING
/* 定义我们的非终结符所代表的节点类型。这些类型引用了上面的%union声明
 */
%type <ident> ident
%type <expr> const_value expression 
%type <block> program stmts block
%type <stmt> stmt var_decl func_decl // extern_decl
%type<ifStatement>							IfStmt
%type<forStatement>							ForStmt
%type<whileStatement>						WhileStmt

%type<switchStatement>						SwitchStmt
%type<caseList>							CaseList
%type<caseStatement>							CaseStmt
%type<breakStatement>						BreakStmt
%type<continueStatement>						ContinueStmt
%type<loopStatement>            LoopStmt
%type <expressionList>             call_args
%type <var_decls>               func_decl_args
%type<varType>  varType
/* 数学运算符的运算符优先级 */
%left OR
%left AND
%left CEQ CNE CLT CLE CGT CGE
%left PLUS MINUS
%left MUL DIV



%start program

%%
program: 
    stmts { 
        programBlock = $1; 
    };
	stmts: //多个声明
    stmt {
        $$ = new Block(); $$->statementList.push_back($<stmt>1);
    }
    | stmts stmt {
       $1->statementList.push_back($<stmt>2);
    };


  stmt ://声明
  var_decl| func_decl // | extern_decl
	 | expression { $$ = new ExpressionStatement(*$1); }
	 | RETURN expression { $$ = new ReturnStatement($2); }
   | RETURN { $$ = new ReturnStatement(); }
	 | BreakStmt  { $$ = $1; }
   | ContinueStmt  { $$ = $1; }
   | SwitchStmt	{  $$ = $1;} 
   | IfStmt { $$ = $1; }
   | LoopStmt { $$ = $1; }
    ;


//以下都是关键字声明
  IfStmt:
       IF LPAREN expression RPAREN block {
        $$ = new IfStatement(*$3, *$5);
    }
  | IF LPAREN expression RPAREN block ELSE block {
        $$ = new IfStatement(*$3, *$5, $7);
    }
  
  LoopStmt:
  ForStmt{ $$ = $1; }
  |WhileStmt{ $$ = $1; }
  ;
  
  WhileStmt:WHILE LPAREN expression RPAREN block {
        $$ = new WhileStatement(*$3, *$5);
    };
  
  ForStmt:FOR LPAREN expression SEMI expression SEMI expression RPAREN block
   {
        $$ = new ForStatement(*$5, *$3,*$7,*$9);
    };
  SwitchStmt:	SWITCH LPAREN expression RPAREN LBRACE CaseList RBRACE		
      {  $$ = new SwitchStatement(*$3,*$6);   }
        ;

  CaseList:	CaseList CaseStmt										{  $$ = $1; $$->push_back($2);   }	
        |														{  $$ = new CaseList();   }
        ;

  CaseStmt:	CASE expression COLON block									{  $$ = new CaseStatement($2,*$4);   }
        | DEFAULT COLON block									{  $$ = new CaseStatement(*$3);   }
        ;
  BreakStmt:	BREAK {  $$ = new BreakStatement();   }
  ;
    ContinueStmt:	CONTINUE {  $$ = new ContinueStatement();   }
  ;
  
  
  //代码块
  block: 
    LBRACE stmts RBRACE {
        $$ = $2;
    }
    | LBRACE RBRACE {
        $$ = new Block();
    };

  //变量定义、函数定义，函数参数定义，extern定义
  var_decl :varType ident{ $$ = new VariableDeclaration(*$1, *$2); }
      | varType ident EQUAL expression { $$ = new VariableDeclaration(*$1, *$2, $4); }
      | varType ident LBRACK INTEGER RBRACK { // 定义数组
              $$ = new VariableDeclaration(*$1, *$2, $4);
    }
      ;

    varType:
      INT													    {  $$ = new VarType(VarType::TypeID::_Int); }
			| CHAR													{  $$ = new VarType(VarType::TypeID::_Char);  }
			| DOUBLE												{  $$ = new VarType(VarType::TypeID::_Double);  }
			| VOID			                    {  $$ = new VarType(VarType::TypeID::_Void); }
      ;

/*
  extern_decl : EXTERN varType ident LPAREN func_decl_args RPAREN
                  { $$ = new ExternDeclaration(*$2, *$3, *$5); delete $5; }
              ;
*/

  func_decl : varType ident LPAREN func_decl_args RPAREN block 
  { $$ = new FunctionDeclaration(*$1, *$2, *$4, *$6); delete $4; }
  ;

  func_decl_args : /*blank*/  { $$ = new VariableList(); }
  | var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
  | func_decl_args COMMA var_decl { $1->push_back($<var_decl>3); }
  ;

  //标识符
  ident : 
  IDENTIFIER { $$ = new Identifier(*$1); delete $1; }
      ;

  //表达式
  expression : ident EQUAL expression { $$ = new Assign(*$<ident>1, *$3); }
  | ident LPAREN call_args RPAREN { $$ = new Call(*$1, *$3); delete $3; }
  | ident { $<ident>$ = $1; }
  | const_value
  /*以下$2的值为yyval.token，在实现ast.cpp时需要yacc生成的宏*/
  | expression AND expression {$$ = new BinaryOp(*$1, $2, *$3);}
  | expression OR expression {$$ = new BinaryOp(*$1, $2, *$3);}
  | expression MUL expression { $$ = new BinaryOp(*$1, $2, *$3); }
  | expression DIV expression { $$ = new BinaryOp(*$1, $2, *$3); }
  | expression PLUS expression { $$ = new BinaryOp(*$1, $2, *$3); }
  | expression MINUS expression { $$ = new BinaryOp(*$1, $2, *$3); }
  | expression CEQ expression { $$ = new BinaryOp(*$1, $2, *$3); }
  | expression CNE expression { $$ = new BinaryOp(*$1, $2, *$3); }
  | expression CLT expression { $$ = new BinaryOp(*$1, $2, *$3); }
  | expression CLE expression { $$ = new BinaryOp(*$1, $2, *$3); }
  | expression CGT expression { $$ = new BinaryOp(*$1, $2, *$3); }
  | expression CGE expression { $$ = new BinaryOp(*$1, $2, *$3); }
  |GAD ident {//数组和地址表达式
        $$ = new GetAddr(*$2);
    }
    | GAD ident LBRACK expression RBRACK {
        $$ = new GetArrayAddr(*$2, *$4);
    }
    | LPAREN expression RPAREN {
        $$ = $2;
    }
     | ident LBRACK expression RBRACK { // array element access
        $$ = new ArrayElement(*$1, *$3);
    }
    | ident LBRACK expression RBRACK EQUAL expression { // array element access
        $$ = new ArrayAssign(*$1, *$3, *$6);
    }
	 ;

   call_args : /*blank*/  { $$ = new ExpressionList(); }//调用函数时的参数
		  | expression { $$ = new ExpressionList(); $$->push_back($1); }
		  | call_args COMMA expression  { $1->push_back($3); }
		  ;

    const_value : INTEGER { $$ = new Integer($1); }//const值
		| REAL { $$ = new Double($1); }
    | CHARACTER { $$ = new Char($1);}
    | STRING { $$ = new String(*$1); }
		;
%%
