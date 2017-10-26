#include "visitor.h"
//TODO
void ExpressionPointer::Visit(NumberExpression* node)
{
	int flag = 0;
	if (node->Value < 0) {
		flag = 1;
		node->Value = -node->Value;
	}
	do {
		this->result = (char)(node->Value % 10 + '0') + this->result;
		node->Value /= 10;
	} while (node->Value);
	if (flag) {
		this->result = '-' + this->result;
	}
	this->level = 2;
	return;
}


void ExpressionPointer::Visit(BinaryExpression* node)
{
	if (node->Op == BinaryOperator::Multiply ||
		node->Op == BinaryOperator::Divide) {
		this->level = 1;
	}
	else {
		this->level = 0;
	}
	ExpressionPointer FirstVisitor, SecondVisitor;
	node->First->Accept(&FirstVisitor);
	node->Second->Accept(&SecondVisitor);
	if (FirstVisitor.level < this->level) {
		FirstVisitor.result = "(" + FirstVisitor.result + ")";
	}
	if (SecondVisitor.level < this->level) {
		SecondVisitor.result = "(" + SecondVisitor.result + ")";
	}
	if (node->Op == BinaryOperator::Minus ||
		node->Op == BinaryOperator::Divide) {
		if (SecondVisitor.level == this->level) {
			SecondVisitor.result = "(" + SecondVisitor.result + ")";
		}
	}
	this->result = FirstVisitor.result + GetOp(node->Op) +
		SecondVisitor.result;
}


