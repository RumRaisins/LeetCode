

#include "Visitor.h"

void ExprPointer::Visit(NumberExpr* node)
{
	this->result = "";
	int num = node->number;
	do {
		this->result = static_cast<char>(num % 10 + '0') + this->result;
		num /= 10;
	} while (num);

}
void ExprPointer::Visit(IdExpr* node)
{
	this->result = node->name;
}
void ExprPointer::Visit(BinaryExpr* node)
{
	ExprPointer firstV, secondV;
	node->first->Accept(&firstV);
	node->second->Accept(&secondV);
	this->result += GetOp(node->op);
	this->result += " " + firstV.result + " " + secondV.result ;
	this->result = "(" + this->result + ")";
}
void ExprPointer::Visit(InvokeExpr* node)
{
	ExprPointer visitor;
	this->result = node->name;
	for (auto x : node->arguments) {
		x->Accept(&visitor);
		this->result += " " + visitor.result;
	}
	this->result = "(" + this->result + ")";
}

