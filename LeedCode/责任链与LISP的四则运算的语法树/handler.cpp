#include "handler.h"
#include <cstdlib>

auto in_range = [](int b, int e) {
	return [=](int x) {
		return x <= e && x >= b;
	};
};

auto combin = [](auto a, auto b) {
	return [=](int x) {
		return a(x) || b(x);
	};
};
auto is_digit = in_range('0', '9');
auto is_alpha = combin(in_range('a', 'z'), in_range('A', 'Z'));


bool IdHandler::Test(string token, bool forInvoke)
{
	if (forInvoke || token.length() <= 0) return false;
	if (is_digit(token[0])) return false;
	for (auto x : token) {
		if (!is_digit(x) && !is_alpha(x)) {
			return false;
		}
	}
	return true;
}
shared_ptr<Expr> IdHandler::IdFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<IdExpr> obj = make_shared<IdExpr>();
	obj->name = token;
	return obj;
}

shared_ptr<Expr> NumberHandler::NumberFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<NumberExpr> obj = make_shared<NumberExpr>();
	obj->number = 0;
	int num = 0;
	for (auto x : token) {
		num = num * 10 + (x - '0');
	}
	obj->number = num;
	return obj;

}
bool NumberHandler::Test(string token, bool forInvoke)
{
	//TODO
	if (forInvoke || token.length() == 0) return false;
	for (auto x : token) {
		if (!is_digit(x)) {
			return false;
		}
	}
	return true;
}

bool BinaryHandler::Test(string token, bool forInvoke)
{
	if (forInvoke || token.length() != 1) return false;
	switch (token[0]) {
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}
shared_ptr<Expr>BinaryHandler::BinaryFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<BinaryExpr> obj = make_shared<BinaryExpr>();
	switch (token[0]) {
	case '+':
		obj->op = BinaryOperator::Plus;
		break;
	case '-':
		obj->op = BinaryOperator::Minus;
		break;
	case '*':
		obj->op = BinaryOperator::Multiply;
		break;
	case '/':
		obj->op = BinaryOperator::Divide;
		break;
	}
	obj->first = arguments[0];
	obj->second = arguments[1];
	arguments.erase(arguments.begin());
	arguments[0] = obj;
	if (arguments.size() == 1) {
		return obj;
	}
	else {
		return this->CreateExpr(token, arguments);
	}
}

shared_ptr<Expr> InvokeHandler::InvokeFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<InvokeExpr> obj = make_shared<InvokeExpr>();
	obj->name = token;
	for (auto x : arguments) {
		obj->arguments.push_back(x);
	}
	return obj;
}
bool InvokeHandler::Test(string token, bool forInvoke)
{
	if (!forInvoke || token.length() <= 0) return false;
	if (is_digit(token[0])) return false;
	for (auto x : token) {
		if (!is_digit(x) && !is_alpha(x)) {
			return false;
		}
	}
	return true;
}

