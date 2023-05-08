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
class ConstVal : public Expression {
	public:
	ConstVal() {}
	~ConstVal() {}
	virtual llvm::Value* codeGen(CodeGenContext& context) = 0;
};
class Integer : public ConstVal {
public:
	Integer(long long value) : value(value) { }
	llvm::Value* codeGen(CodeGenContext& context);
public:
	long long value;
};

class Double : public ConstVal {
public:
	Double(double value) : value(value) { }
	llvm::Value* codeGen(CodeGenContext& context);
public:
	double value;
};
class Char : public ConstVal {
public:
  Char(char value) : value(value) {}
  llvm::Value* codeGen(CodeGenContext& context);
public:  
	char value;
};

class String : public ConstVal {
public:
  String(std::string &value) : value(value) {}
  llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value *GetAddr(CodeGenContext& context);
public:
  std::string &value;
};

class Identifier : public Expression {
public:
	Identifier(const std::string& name) : name(name) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
public:
	std::string name;
};

class Call : public Expression {
public:
	Call(const Identifier& id, ExpressionList& arguments) :
		id(id), arguments(arguments) { }
	Call(const Identifier& id) : id(id) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
public:
	const Identifier& id;
	ExpressionList arguments;
};

class BinaryOp : public Expression {
public:
	BinaryOp(Expression& lhs, int op, Expression& rhs) :
		lhs(lhs), op(op) ,rhs(rhs) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
public:
	int op;
	Expression& lhs;
	Expression& rhs;
};

class Assign : public Expression {
public:
	Assign(Identifier& ident, Expression& expr) : 
		ident(ident), expr(expr) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
public:
	Identifier& ident;
	Expression& expr;
};

class Block : public Expression {//Function body
public:
	Block() { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
public:
	StatementList statementList;
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
  Identifier &identifier;
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
		Declaration() {}
		~Declaration() {}
		virtual llvm::Value* codeGen(CodeGenContext& context) = 0;
		
	};
class ExpressionStatement : public Statement {
public:
	ExpressionStatement(Expression& expression) : 
		expression(expression) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
public:
	Expression& expression;
};

class Return : public Statement {
public:
	Return(Expression* expression) : 
		expression(expression) { }
	Return() : 
		expression(nullptr) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
public:
	Expression* expression;
};

class VariableDeclaration : public Declaration {
public:
	VariableDeclaration(const Identifier& type, Identifier& id) :
		type(type), id(id) { assignmentExpr = nullptr; }
  VariableDeclaration(const Identifier& type, Identifier& id,int size) :
		type(type), id(id) { assignmentExpr = nullptr; }
	VariableDeclaration(const Identifier& type, Identifier& id, Expression *assignmentExpr) :
		type(type), id(id), assignmentExpr(assignmentExpr) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
public:
  int size;
	const Identifier& type;
	Identifier& id;
	Expression *assignmentExpr;
};
class ArrayDeclaration : public VariableDeclaration {
public:
  ArrayDeclaration(const Identifier& type, Identifier& id,int size) :
		VariableDeclaration(type,id),size(size) {}
  virtual llvm::Value* codeGen(CodeGenContext& context);
public:
  int size;
};
class ExternDeclaration : public Declaration {
	public:
    ExternDeclaration(const Identifier& type, const Identifier& id,
            const VariableList& arguments) :
        type(type), id(id), arguments(arguments) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
	public:
    const Identifier& type;
    const Identifier& id;
    VariableList arguments;
};

class FunctionDeclaration : public Declaration {
public:
	FunctionDeclaration(const Identifier& type, const Identifier& id, 
		const VariableList& arguments, Block& block) :
		type(type), id(id), arguments(arguments), block(block) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
public:
	const Identifier& type;
	const Identifier& id;
	VariableList arguments;
	Block& block;
};
class LoopStatement : public Statement {
	public:
		LoopStatement(Expression& condition) :condition(condition) {}
		~LoopStatement() {}
		llvm::Value* codeGen(CodeGenContext& context);
	public:
		Expression& condition;
	};
class ForStatement : public LoopStatement {
	public:
		ForStatement(Expression& Initial, Expression& Condition, Expression& Tail, Block& LoopBody) :
			Initial(Initial), LoopStatement(Condition), Tail(Tail), LoopBody(LoopBody) {}
		~ForStatement() {}
		llvm::Value* codeGen(CodeGenContext& context);
	public:
	  Expression& Initial;
		Expression& Tail;
		Block& LoopBody;
		
	};
class WhileStatement : public LoopStatement {
	public:
		WhileStatement(Expression& condition, Block& LoopBody) :
			 LoopStatement(condition),LoopBody(LoopBody) {}
		~WhileStatement() {}
		llvm::Value* codeGen(CodeGenContext& context);
	public:
	Block& LoopBody;
	};
class IfStatement : public Statement {
	public:
		IfStatement(Expression& condition, Block& next,Block* else_next) :
			 condition(condition),next(next),else_next(else_next) {}
    IfStatement(Expression& condition, Block& next) :
			 condition(condition),next(next) {else_next=nullptr;}
		~IfStatement( ) {}
		llvm::Value* codeGen(CodeGenContext& context);
	public:
		Expression& condition;
		Block& next;
    Block* else_next;
	};
  class SwitchStatement : public Statement {
	public:
		SwitchStatement(Expression& matches, CaseList& caseList) :
			 matches(matches),caseList(caseList) {}
		~SwitchStatement( ) {}
		llvm::Value* codeGen(CodeGenContext& context);
	public:
		Expression& matches;
		CaseList& caseList;
	};
class CaseStatement : public Statement {
	public:
		CaseStatement(Expression* condition, Block& body) :
			 condition(condition),body(body) {}
    CaseStatement(Block& body) :
			 body(body) {condition=nullptr;}
		~CaseStatement() {}
		llvm::Value* codeGen(CodeGenContext& context);
	public:
		Expression* condition;
		Block& body;
	};
class BreakStatement : public Statement {
	public:
		BreakStatement() {}
		~BreakStatement() {}
		llvm::Value* codeGen(CodeGenContext& context);
	};

#endif