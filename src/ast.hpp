#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <vector>
#include <string>
#include <llvm/IR/Value.h>

class CodeGenContext;
class NStatement;
class NExpression;
class NVariableDeclaration;
class NCaseStatement;
typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVariableDeclaration*> VariableList;
typedef std::vector<NCaseStatement*> CaseList;
class Node {
public:
	virtual ~Node() {}
	virtual llvm::Value* codeGen(CodeGenContext& context) { return NULL; }
};

class NExpression : public Node {
};

class NStatement : public Node {
};
// class NFuncBody : public Node {//函数体
// 	public:
// 		//Its content
// 		NStatement* Content;

// 		NFuncBody(NStatement* Content) :Content(Content) {}
// 		~NFuncBody(void) {}
// 		llvm::Value* codeGen(CodeGenContext& context);
		
// 	};
class NInteger : public NExpression {
public:
	long long value;
	NInteger(long long value) : value(value) { }
	llvm::Value* codeGen(CodeGenContext& context);
};

class NDouble : public NExpression {
public:
	double value;
	NDouble(double value) : value(value) { }
	llvm::Value* codeGen(CodeGenContext& context);
};
class NChar : public NExpression {
public:
  NChar(char value) : value(value) {}
  llvm::Value* codeGen(CodeGenContext& context);
  
public:
  char value;
};

class NString : public NExpression {
public:
  NString(std::string &value) : value(value) {}
  llvm::Value* codeGen(CodeGenContext& context);
  llvm::Value *getAddr(CodeGenContext& context);
public:
  std::string &value;
};

class NIdentifier : public NExpression {
public:
	std::string name;
	NIdentifier(const std::string& name) : name(name) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NMethodCall : public NExpression {
public:
	const NIdentifier& id;
	ExpressionList arguments;
	NMethodCall(const NIdentifier& id, ExpressionList& arguments) :
		id(id), arguments(arguments) { }
	NMethodCall(const NIdentifier& id) : id(id) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBinaryOperator : public NExpression {
public:
	int op;
	NExpression& lhs;
	NExpression& rhs;
	NBinaryOperator(NExpression& lhs, int op, NExpression& rhs) :
		lhs(lhs), rhs(rhs), op(op) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NAssignment : public NExpression {
public:
	NIdentifier& lhs;
	NExpression& rhs;
	NAssignment(NIdentifier& lhs, NExpression& rhs) : 
		lhs(lhs), rhs(rhs) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBlock : public NExpression {//Function body
public:
	StatementList statements;
	NBlock() { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class ArrayElement : public NExpression {   //identifier[expression] 表示数组中某个元素
public:
  ArrayElement(NIdentifier& identifier, NExpression &index) :identifier(identifier), index(index) {}
  llvm::Value *codeGen(CodeGenContext& context);
  llvm::Value *getAddr(CodeGenContext& context);
public:
  NIdentifier &identifier;
  NExpression &index;
};

class ArrayElementAssign : public NExpression {   //identifier[expression] 表示数组中某个元素
public:
  ArrayElementAssign(NIdentifier &identifier, NExpression &index, NExpression &rhs) :identifier(identifier), index(index), rhs(rhs) {}
  llvm::Value *codeGen(CodeGenContext& context);
public:
  NIdentifier& identifier;
  NExpression &index;
  NExpression &rhs;
};
class getAddr : public NExpression {  //取地址运算符
public:
  getAddr(NIdentifier &rhs) : rhs(rhs) {}
  llvm::Value *codeGen(CodeGenContext& context);
public:
  NIdentifier& rhs;
};
class getArrayAddr : public NExpression {  //取地址运算符
public:
  getArrayAddr(NIdentifier &rhs, NExpression &index) :index(index), rhs(rhs) {}
  llvm::Value *codeGen(CodeGenContext& context);
public:
  NExpression& index;
  NIdentifier& rhs;
};


class NDeclaration : public NStatement {
	public:
		NDeclaration(void) {}
		~NDeclaration(void) {}
		virtual llvm::Value* codeGen(CodeGenContext& context) = 0;
		
	};
class NExpressionStatement : public NStatement {
public:
	NExpression& expression;
	NExpressionStatement(NExpression& expression) : 
		expression(expression) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NReturnStatement : public NStatement {
public:
	NExpression& expression;
	NReturnStatement(NExpression& expression) : 
		expression(expression) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NVariableDeclaration : public NDeclaration {
public:
  int size;
	const NIdentifier& type;
	NIdentifier& id;
	NExpression *assignmentExpr;
	NVariableDeclaration(const NIdentifier& type, NIdentifier& id) :
		type(type), id(id) { assignmentExpr = nullptr; }
  NVariableDeclaration(const NIdentifier& type, NIdentifier& id,int size) :
		type(type), id(id) { assignmentExpr = nullptr; }
	NVariableDeclaration(const NIdentifier& type, NIdentifier& id, NExpression *assignmentExpr) :
		type(type), id(id), assignmentExpr(assignmentExpr) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};
class NArrayDeclaration : public NVariableDeclaration {
  public:
  int size;
  NArrayDeclaration(const NIdentifier& type, NIdentifier& id,int size) :
		NVariableDeclaration(type,id),size(size) {}
  virtual llvm::Value* codeGen(CodeGenContext& context);

};
class NExternDeclaration : public NDeclaration {
public:
    const NIdentifier& type;
    const NIdentifier& id;
    VariableList arguments;
    NExternDeclaration(const NIdentifier& type, const NIdentifier& id,
            const VariableList& arguments) :
        type(type), id(id), arguments(arguments) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NFunctionDeclaration : public NDeclaration {
public:
	const NIdentifier& type;
	const NIdentifier& id;
	VariableList arguments;
	NBlock& block;
	NFunctionDeclaration(const NIdentifier& type, const NIdentifier& id, 
			const VariableList& arguments, NBlock& block) :
		type(type), id(id), arguments(arguments), block(block) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};
// class NTypeDeclaration : public NDeclaration {
// public:
//     NStatement *initial;
//     NExpression *condition;
//     NExpression *tail;
//     NStatement *body;
//     NTypeDeclaration(NStatement *initial,NExpression *condition,
//     NExpression *tail,NStatement *body):
//         initial(initial), condition(condition),tail(tail),body(body){}
//     virtual llvm::Value* codeGen(CodeGenContext& context);
// };
class NLoopStatement : public NStatement {
	public:
		
		NExpression& _Condition;

		NLoopStatement(NExpression& __Condition) :_Condition(__Condition) {}
		~NLoopStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
class NForStatement : public NLoopStatement {
	public:
		//待改
		NExpression& _Initial;
		NExpression& _Tail;
		NBlock& _LoopBody;

		NForStatement(NExpression& __Initial, NExpression& __Condition, NExpression& __Tail, NBlock& __LoopBody) :
			_Initial(__Initial), NLoopStatement(__Condition), _Tail(__Tail), _LoopBody(__LoopBody) {}
		~NForStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
class NWhileStatement : public NLoopStatement {
	public:
		//待改

		NBlock& _LoopBody;

		NWhileStatement(NExpression& __Condition, NBlock& __LoopBody) :
			 NLoopStatement(__Condition),_LoopBody(__LoopBody) {}
		~NWhileStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
class NIfStatement : public NStatement {
	public:
		//待改

		NExpression& condition;
		NBlock& next;
    	NBlock* else_next;

		NIfStatement(NExpression& condition, NBlock& next,NBlock* else_next) :
			 condition(condition),next(next),else_next(else_next) {}
    NIfStatement(NExpression& condition, NBlock& next) :
			 condition(condition),next(next) {else_next=nullptr;}
		~NIfStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
  class NSwitchStatement : public NStatement {
	public:
		//待改

		NExpression* matches;
		CaseList* caseList;

		NSwitchStatement(NExpression* matches, CaseList* caseList) :
			 matches(matches),caseList(caseList) {}
		~NSwitchStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
class NCaseStatement : public NStatement {
	public:
		//待改

		NExpression* condition;
		NBlock* body;

		NCaseStatement(NExpression* condition, NBlock* body) :
			 condition(condition),body(body) {}
    NCaseStatement(NBlock* body) :
			 body(body) {}
		~NCaseStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
		
	};
class NBreakStatement : public NStatement {
	public:
		NBreakStatement(void) {}
		~NBreakStatement(void) {}
		llvm::Value* codeGen(CodeGenContext& context);
	};

#endif