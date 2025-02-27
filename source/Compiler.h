#pragma once

#include "Node.h"
#include "Types.h"
#include "AlifNamesTable.h"
#include "AlifMemory.h"
#include "Container.h"
#include "AlifArray.h"
#include "AlifStack.h"
#include "Parser.h"

#define VISIT_(func,node) (visit_ ## func(node)) // -> visit_func(arg) <<-->> VISIT_(func, node)
												 //			^                        ^
												 //			|                        |
												 //			|                        |
												 //    طريقة الاستدعاء           شكل الاستدعاء


// اعلام
static bool isReturnFlag = false;
static bool isAssignFlag = false;
static bool isCallFlag = false;
static bool attrFlag = false;
static bool elseIfFlag = true;
//

class Compiler {
public:
	std::vector<StmtsNode*>* statements_{};
	Container* dataContainer{};
	AlifArray<Container*> containers_{};
	AlifMemory* alifMemory;
	AlifNamesTable* namesTable{};

	Compiler(std::vector<StmtsNode*>* _statements, AlifMemory* _alifMemory, AlifNamesTable* _namesTable);

	void compile_file();

	AlifObject* visit_object(ExprNode*);
	AlifObject* visit_unaryOp(ExprNode*);
	AlifObject* visit_binOp(ExprNode*);
	void visit_assign(ExprNode*);
	void visit_augAssign(ExprNode*);
	AlifObject* visit_access(ExprNode*);
	void visit_expr(ExprNode*);
	void visit_list(ExprNode*);
	void visit_call(ExprNode*);
	AlifObject* visit_attr(ExprNode*);
	AlifObject* visit_return_(ExprNode*);
	void visit_stop(ExprNode*);
	void visit_continue_(ExprNode*);

	void visit_for_(StmtsNode*);
	void visit_while_(StmtsNode*);
	void visit_if_(StmtsNode*);
	void visit_function(StmtsNode*);
	void visit_class_(StmtsNode*);

	AlifObject* visit_exprs(ExprNode* _node);
	AlifObject* visit_stmts(StmtsNode* _node);





	void visit_print();
};


