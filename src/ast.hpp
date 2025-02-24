#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <vector>
#include <string>

#include <llvm/IR/Value.h>

class CodeGenerator;
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
	Node(void) {}
	virtual ~Node() {} 
	virtual llvm::Value* codeGen(CodeGenerator& context) { return NULL; }
};

class Expression : public Node {
};

class Statement : public Node {
};

class ConstVal : public Expression {
public:
	ConstVal(){}
	~ConstVal(){}
	virtual llvm::Value* codeGen(CodeGenerator& context) = 0;
};

// no need to codeGen?
class VarType : public Node {
public:
	enum TypeID {
		_Int,
		_Char,
		_Double,
		_Void
	};
	VarType(TypeID __Type) : type(__Type) { size = 0; }
	VarType(TypeID __Type, int size) : type(__Type), size(size) {}
	~VarType(void) {}
	// llvm::Value* codeGen(CodeGenerator& context);
	virtual llvm::Type* getLLVMType(void);
	VarType *changeSize(int size){
		this->size = size;
		return this;
	}
public:
	TypeID type;
	int size;
};

class Integer : public ConstVal {
public:
	Integer(long long value) : value(value) { }
	llvm::Value* codeGen(CodeGenerator& context);
public:
	long long value;
};

class Double : public ConstVal {
public:
	Double(double value) : value(value) { }
	llvm::Value* codeGen(CodeGenerator& context);
public:
	double value;
};

class Char : public ConstVal {
public:
	Char(char value) : value(value) {}
	llvm::Value* codeGen(CodeGenerator& context);
public:  
	char value;
};

class String : public ConstVal {
public:
	String(std::string &value) : value(value) {}
	llvm::Value* codeGen(CodeGenerator& context);
	llvm::Value* getAddr(CodeGenerator& context);
public:
	std::string &value;
};

class Identifier : public Expression {
public:
	Identifier(const std::string& name) : name(name) { }
	virtual llvm::Value* codeGen(CodeGenerator& context);
public:
	std::string name;
};

class Call : public Expression {
public:
	Call(const Identifier& id, ExpressionList& arguments) :
		id(id), arguments(arguments) { }
	Call(const Identifier& id) : id(id) { }
	llvm::Value* generatePrintfCall(CodeGenerator& context, std::vector<Expression*>& args);
	llvm::Value* generateScanfCall(CodeGenerator& context, std::vector<Expression*>& args);
	virtual llvm::Value* codeGen(CodeGenerator& context);
public:
	const Identifier& id;
	ExpressionList arguments;
};

class BinaryOp : public Expression {
public:
	BinaryOp(Expression& lhs, int op, Expression& rhs) :
		lhs(lhs), op(op) ,rhs(rhs) { }
	virtual llvm::Value* codeGen(CodeGenerator& context);
public:
	// here why op int ? maybe it is micro
	int op;
	Expression& lhs;
	Expression& rhs;
};

class Assign : public Expression {
public:
	Assign(Identifier& ident, Expression& expr) : 
		ident(ident), expr(expr) { }
	virtual llvm::Value* codeGen(CodeGenerator& context);
public:
	Identifier& ident;
	Expression& expr;
};


class ArrayElement : public Expression {   //identifier[expression] 表示数组中某个元素
public:
	ArrayElement(Identifier& identifier, Expression &index) :identifier(identifier), index(index) {}
	llvm::Value *codeGen(CodeGenerator& context);
	llvm::Value *getAddr(CodeGenerator& context);
public:
	Identifier &identifier;
	Expression &index;
};

class ArrayAssign : public Expression {   //identifier[expression] 表示数组中某个元素
public:
	ArrayAssign(Identifier &identifier, Expression &index, Expression &rhs) :identifier(identifier), index(index), rhs(rhs) {}
	llvm::Value *codeGen(CodeGenerator& context);
public:
	Identifier &identifier;
	Expression &index;
	Expression &rhs;
};
	
class GetAddr : public Expression {  //取地址运算符
public:
	GetAddr(Identifier &rhs) : rhs(rhs) {}
	llvm::Value *codeGen(CodeGenerator& context);
public:
	Identifier& rhs;
};

class GetArrayAddr : public Expression {  //取地址运算符
public:
	GetArrayAddr(Identifier &rhs, Expression &index) :index(index), rhs(rhs) {}
	llvm::Value *codeGen(CodeGenerator& context);
public:
	Expression& index;
	Identifier& rhs;
};

// Function body
class Block : public Expression {
public:
	Block() { }
	virtual llvm::Value* codeGen(CodeGenerator& context);
public:
	StatementList statementList;
};



class Declaration : public Statement {
public:
	Declaration() {}
	~Declaration() {}
	virtual llvm::Value* codeGen(CodeGenerator& context) = 0;
};

class VariableDeclaration : public Declaration {
public:
	VariableDeclaration( VarType& type, Identifier& id) :
		type(type), id(id) { assignmentExpr = nullptr; Customtype=nullptr;}
	VariableDeclaration( VarType& type, Identifier& id, Expression *assignmentExpr) :
		type(type), id(id), assignmentExpr(assignmentExpr) {  Customtype=nullptr;}
	// 创建数组的初始化常量
	llvm::Constant* createArrayInitializer(llvm::Type* VarType);

	// 创建变量的初始化常量
	llvm::Constant* createVariableInitializer(llvm::Type* VarType, CodeGenerator& context, Expression* assignmentExpr);

	virtual llvm::Value* codeGen(CodeGenerator& context);
public:
	VarType& type;//内置类型，为null时表示这个变量为自定义类型
	Identifier* Customtype;//自定义类型，为null时表示这个变量为内置类型 未实现
	Identifier& id;
	Expression *assignmentExpr;
};

class FunctionDeclaration : public Declaration {
public:
	FunctionDeclaration(VarType& type, Identifier& id, 
		const VariableList& arguments, Block& block) :
		type(type), id(id), arguments(arguments), block(block) { }
	virtual llvm::Value* codeGen(CodeGenerator& context);
	std::vector<llvm::Type*> getArgTypes(CodeGenerator& context) ;
	void createArgAllocs(CodeGenerator& context, llvm::Function* Func, std::vector<llvm::Type*>& ArgTypes) ;
	void generateFuncBody(CodeGenerator& context, llvm::Function* Func) ;

public:
	VarType& type;
	Identifier& id;
	VariableList arguments;
	Block& block;
};

class ExpressionStatement : public Statement {
public:
	ExpressionStatement(Expression& expression) : 
		expression(expression) { }
	virtual llvm::Value* codeGen(CodeGenerator& context);
public:
	Expression& expression;
};

class ReturnStatement : public Statement {
public:
	ReturnStatement(Expression* expression) : 
		expression(expression) { }
	ReturnStatement() : 
		expression(nullptr) { }
	virtual llvm::Value* codeGen(CodeGenerator& context);
public:
	Expression* expression;
};

class LoopStatement : public Statement {
public:
	LoopStatement(Expression& condition) :condition(condition) {}
	~LoopStatement() {}
	virtual llvm::Value* codeGen(CodeGenerator& context) = 0;
public:
	Expression& condition;
};

class ForStatement : public LoopStatement {
public:
	ForStatement(Expression& Initial, Expression& Condition, Expression& Tail, Block& LoopBody) :
		Initial(Initial), LoopStatement(Condition), Tail(Tail), LoopBody(LoopBody) {}
	~ForStatement() {}
	llvm::Value* codeGen(CodeGenerator& context);
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
	llvm::Value* codeGen(CodeGenerator& context);
public:
	Block& LoopBody;
};

class IfStatement : public Statement {
public:
	//待改
	IfStatement(Expression& condition, Block& next,Block* else_next) :
			condition(condition),next(next),else_next(else_next) {}
	IfStatement(Expression& condition, Block& next) :
			condition(condition),next(next) {else_next=nullptr;}
	~IfStatement( ) {}
	llvm::Value* codeGen(CodeGenerator& context);
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
	llvm::Value* codeGen(CodeGenerator& context);
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
	llvm::Value* codeGen(CodeGenerator& context);
public:
	Expression* condition;
	Block& body;
};

class BreakStatement : public Statement {
public:
	BreakStatement() {}
	~BreakStatement() {}
	llvm::Value* codeGen(CodeGenerator& context);
};

class ContinueStatement : public Statement {
public:
	ContinueStatement() {}
	~ContinueStatement() {}
	llvm::Value* codeGen(CodeGenerator& context);
};

#endif