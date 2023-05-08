#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <vector>
#include <string>
#include <llvm/IR/Value.h>

class CodeGenContext;
class Statement;
class Expression;
class VariableDeclaration;
class CaseStatement;
typedef std::vector<Statement*> StatementList;
typedef std::vector<Expression*> ExpressionList;
typedef std::vector<VariableDeclaration*> VariableList;
typedef std::vector<CaseStatement*> CaseList;
class Node {
public:
	virtual ~Node() {}
	virtual llvm::Value* codeGen(CodeGenContext& context) { return NULL; }
};

class Expression : public Node {
};

class Statement : public Node {
};
// class NFuncBody : public Node {//函数体
// 	public:
// 		//Its content
// 		Statement* Content;

// 		NFuncBody(Statement* Content) :Content(Content) {}
// 		~NFuncBody(void) {}
// 		llvm::Value* codeGen(CodeGenContext& context);
		
// 	};
class Integer : public Expression {
public:
	long long value;
	Integer(long long value) : value(value) { }
	llvm::Value* codeGen(CodeGenContext& context);
};

class Double : public Expression {
public:
	double value;
	Double(double value) : value(value) { }
	llvm::Value* codeGen(CodeGenContext& context);
};
class Char : public Expression {
public:
  Char(char value) : value(value) {}
  llvm::Value* codeGen(CodeGenContext& context);
  
public:
  char value;
};

class String : public Expression {
public:
  String(std::string &value) : value(value) {}
  llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value *GetAddr(CodeGenContext& context);
public:
  std::string &value;
};

class Identifier : public Expression {
public:
	std::string name;
	Identifier(const std::string& name) : name(name) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Call : public Expression {
public:
	const Identifier& id;
	ExpressionList arguments;
	Call(const Identifier& id, ExpressionList& arguments) :
		id(id), arguments(arguments) { }
	Call(const Identifier& id) : id(id) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class BinaryOp : public Expression {
public:
	int op;
	Expression& lhs;
	Expression& rhs;
	BinaryOp(Expression& lhs, int op, Expression& rhs) :
		lhs(lhs), rhs(rhs), op(op) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Assign : public Expression {
public:
	Identifier& lhs;
	Expression& rhs;
	Assign(Identifier& lhs, Expression& rhs) : 
		lhs(lhs), rhs(rhs) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Block : public Expression {//Function body
public:
	StatementList statements;
	Block() { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class ArrayElement : public Expression {   //identifier[expression] 表示数组中某个元素
public:
  ArrayElement(Identifier& identifier, Expression &index) :identifier(identifier), index(index) {}
  llvm::Value *codeGen(CodeGenContext& context);
  llvm::Value *GetAddr(CodeGenContext& context);
public:
  Identifier &identifier;
  Expression &index;
};

class ArrayAssign : public Expression {   //identifier[expression] 表示数组中某个元素
public:
  ArrayAssign(Identifier &identifier, Expression &index, Expression &rhs) :identifier(identifier), index(index), rhs(rhs) {}
  llvm::Value *codeGen(CodeGenContext& context);
public:
  Identifier& identifier;
  Expression &index;
  Expression &rhs;
};
class GetAddr : public Expression {  //取地址运算符
public:
  GetAddr(Identifier &rhs) : rhs(rhs) {}
  llvm::Value *codeGen(CodeGenContext& context);
public:
  Identifier& rhs;
};
class GetArrayAddr : public Expression {  //取地址运算符
public:
  GetArrayAddr(Identifier &rhs, Expression &index) :index(index), rhs(rhs) {}
  llvm::Value *codeGen(CodeGenContext& context);
public:
  Expression& index;
  Identifier& rhs;
};


class Declaration : public Statement {
	public:
		Declaration(void) {}
		~Declaration(void) {}
		virtual llvm::Value* codeGen(CodeGenContext& context) = 0;
		
	};
class ExpressionStatement : public Statement {
public:
	Expression& expression;
	ExpressionStatement(Expression& expression) : 
		expression(expression) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Return : public Statement {
public:
	Expression* expression;
	Return(Expression* expression) : 
		expression(expression) { }
	Return() : 
		expression(nullptr) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class VariableDeclaration : public Declaration {
public:
  int size;
	const Identifier& type;
	Identifier& id;
	Expression *assignmentExpr;
	VariableDeclaration(const Identifier& type, Identifier& id) :
		type(type), id(id) { assignmentExpr = nullptr; }
  VariableDeclaration(const Identifier& type, Identifier& id,int size) :
		type(type), id(id) { assignmentExpr = nullptr; }
	VariableDeclaration(const Identifier& type, Identifier& id, Expression *assignmentExpr) :
		type(type), id(id), assignmentExpr(assignmentExpr) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};
class ArrayDeclaration : public VariableDeclaration {
  public:
  int size;
  ArrayDeclaration(const Identifier& type, Identifier& id,int size) :
		VariableDeclaration(type,id),size(size) {}
  virtual llvm::Value* codeGen(CodeGenContext& context);

};
class ExternDeclaration : public Declaration {
public:
    const Identifier& type;
    const Identifier& id;
    VariableList arguments;
    ExternDeclaration(const Identifier& type, const Identifier& id,
            const VariableList& arguments) :
        type(type), id(id), arguments(arguments) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class FunctionDeclaration : public Declaration {
public:
	const Identifier& type;
	const Identifier& id;
	VariableList arguments;
	Block& block;
	FunctionDeclaration(const Identifier& type, const Identifier& id, 
			const VariableList& arguments, Block& block) :
		type(type), id(id), arguments(arguments), block(block) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};
// class NTypeDeclaration : public Declaration {
// public:
//     Statement *initial;
//     Expression *condition;
//     Expression *tail;
//     Statement *body;
//     NTypeDeclaration(Statement *initial,Expression *condition,
//     Expression *tail,Statement *body):
//         initial(initial), condition(condition),tail(tail),body(body){}
//     virtual llvm::Value* codeGen(CodeGenContext& context);
// };
class LoopStatement : public Statement {
	public:
		
		Expression& _Condition;

		LoopStatement(Expression& __Condition) :_Condition(__Condition) {}
		~LoopStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
class ForStatement : public LoopStatement {
	public:
		//待改
		Expression& _Initial;
		Expression& _Tail;
		Block& _LoopBody;

		ForStatement(Expression& __Initial, Expression& __Condition, Expression& __Tail, Block& __LoopBody) :
			_Initial(__Initial), LoopStatement(__Condition), _Tail(__Tail), _LoopBody(__LoopBody) {}
		~ForStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
class WhileStatement : public LoopStatement {
	public:
		//待改

		Block& _LoopBody;

		WhileStatement(Expression& __Condition, Block& __LoopBody) :
			 LoopStatement(__Condition),_LoopBody(__LoopBody) {}
		~WhileStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
class IfStatement : public Statement {
	public:
		//待改

		Expression& condition;
		Block& next;
    Block* else_next;

		IfStatement(Expression& condition, Block& next,Block* else_next) :
			 condition(condition),next(next),else_next(else_next) {}
    IfStatement(Expression& condition, Block& next) :
			 condition(condition),next(next) {else_next=nullptr;}
		~IfStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
  class SwitchStatement : public Statement {
	public:
		//待改

		Expression& matches;
		CaseList& caseList;

		SwitchStatement(Expression& matches, CaseList& caseList) :
			 matches(matches),caseList(caseList) {}
		~SwitchStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
class CaseStatement : public Statement {
	public:
		//待改

		Expression* condition;
		Block& body;

		CaseStatement(Expression* condition, Block& body) :
			 condition(condition),body(body) {}
    CaseStatement(Block& body) :
			 body(body) {condition=nullptr;}
		~CaseStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
class BreakStatement : public Statement {
	public:
		BreakStatement(void) {}
		~BreakStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
	};

#endif