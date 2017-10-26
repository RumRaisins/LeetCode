#include <iostream>
#include <memory>
#include <string>
using namespace std;



class BinaryExpr;
class NumberExpr;
enum class BinaryOpt {
	Plus,
	Minus,
	Multiply,
	Divide,
};

class Expr {
public :
	class Visitor {
	public:
		virtual void Visit(BinaryExpr *) = 0;
		virtual void Visit(NumberExpr *) = 0;

	};
	virtual void Accept(Visitor *) = 0;
protected:
	virtual ~Expr() = 0 {};

};

class BinaryExpr : public Expr {
public:
	BinaryExpr(shared_ptr<Expr> first, BinaryOpt op,shared_ptr<Expr> second) :first(first), second(second) , op(op) {

	}
	virtual ~BinaryExpr() {}
	virtual void Accept(Visitor *visitor) {
		visitor->Visit(this);
	}
	shared_ptr<Expr> first;
	shared_ptr<Expr> second;
	BinaryOpt op;

};

class NumberExpr : public Expr {
public:
	NumberExpr(int a) :Value(a){}
	virtual ~NumberExpr() {}
	virtual void Accept(Visitor *visitor) {
		visitor->Visit(this);
	}
	int Value;

};


BinaryOpt CharToOpt(char Read) {
	switch (Read) {
	case '+':
		return BinaryOpt::Plus;
	case '-':
		return  BinaryOpt::Minus;
	case '*':
		return BinaryOpt::Multiply;
	case '/':
		return BinaryOpt::Divide;
	}
}

shared_ptr<Expr> __Parser(const char*&Read) {
	if (Read[0] == '(') {
		Read++;
		BinaryOpt op = CharToOpt(*Read);
		Read++;
		while (Read[0] == ' ')Read++;
		shared_ptr<Expr> first = __Parser(Read);
		while (Read[0] == ' ')Read++;
		shared_ptr<Expr> second = __Parser(Read);
		Read++;
		return make_shared<BinaryExpr>(BinaryExpr(first, op, second));
	}
	else {
		int num = 0;
		while (Read[0] != ' ' && Read[0] != ')') {
			num = num * 10 + (Read[0] - '0');
			Read++;
		}
		return make_shared<NumberExpr>(num);
	}
}


shared_ptr<Expr> Parser(const char* Read) {
	return __Parser(Read);

}


class CalcNumber : public Expr::Visitor {
public:
	int result;
	virtual void Visit(BinaryExpr *node) {
		CalcNumber firstV, secondV;
		node->first->Accept(&firstV);
		node->second->Accept(&secondV);
		switch (node->op)
		{

		case BinaryOpt::Plus:
			this->result = firstV.result + secondV.result;
			break;
		case BinaryOpt::Minus:
			this->result = firstV.result - secondV.result;
			break;
		case BinaryOpt::Multiply:
			this->result = firstV.result * secondV.result;
			break;
		case BinaryOpt::Divide:
			this->result = firstV.result / secondV.result;
			break;
		}




	}
	virtual void Visit(NumberExpr *node) {
		this->result =  node->Value;
	}
};

class RootToString : public Expr::Visitor {
public:
	string result;
	virtual void Visit(BinaryExpr *node) {
		RootToString firstV, secondV;
		this->result = "( " + this->result;
		node->first->Accept(&firstV);
		node->second->Accept(&secondV);
		switch (node->op) {
			case BinaryOpt::Plus:
			this->result += firstV.result + " + " + secondV.result;
			break;
		case BinaryOpt::Minus:
			this->result += firstV.result +" - "+ secondV.result;
			break;
		case BinaryOpt::Multiply:
			this->result += firstV.result +" * "+ secondV.result;
			break;
		case BinaryOpt::Divide:
			this->result += firstV.result +" / " + secondV.result;
			break;
		}
		
		this->result = this->result + " )";

	}
	virtual void Visit(NumberExpr *node) {
		int n = node->Value;
		bool flag = false;
		if (n < 0) {
			flag = true;
			n = -n;
		}
		while (n) {
			this->result = (char)(n % 10 + '0') + this->result;
			n /= 10;
		}
		this->result = (flag ? '-' + this->result : this->result);

	}

};


class Nobrackets : public Expr::Visitor {
public:
	string result;
	int level;
	virtual void Visit(BinaryExpr *node) {
		Nobrackets firstV, secondV;
		node->first->Accept(&firstV);
		node->second->Accept(&secondV);
		switch (node->op) {
		case BinaryOpt::Plus:
			this->level = 1;
			if (firstV.level > this->level || secondV.level > this->level) {
				this->result = "( " + firstV.result + " + " + secondV.result + " )";
			}
			else {
				this->result = firstV.result +" + "+secondV.result;
			}
			break;
		case BinaryOpt::Minus:
			this->level = 1;
			if (firstV.level > this->level || secondV.level > this->level || this->level == secondV.level) {
				this->result = "( " + firstV.result + " - " + secondV.result + " )";
			}
			else {
				this->result = firstV.result + " - " + secondV.result;
			}
			
			break;
		case BinaryOpt::Multiply:
			this->level = 2;
			if (firstV.level > this->level || secondV.level > this->level) {
				this->result = "( " + firstV.result + " * " + secondV.result + " )";
			}
			else {
				this->result = firstV.result + " * " + secondV.result;
			}
			
			break;
		case BinaryOpt::Divide:
			this->level = 2;
			if (firstV.level > this->level || secondV.level > this->level || this->level == secondV.level) {
				this->result = "( " + firstV.result + " / " + secondV.result + " )";
			}
			else {
				this->result = firstV.result + "  " + secondV.result;
			}
		}


	}
	virtual void Visit(NumberExpr *node) {
		int n = node->Value;
		bool flag = false;
		if (n < 0) {
			flag = true;
			n = -n;
		}
		while (n) {
			this->result = (char)(n % 10 + '0') + this->result;
			n /= 10;
		}
		this->result = (flag ? '-' + this->result : this->result);
		this->level = 3;

	}

};
class Vack : public Expr::Visitor {
public:
	string result;
	int level;
	virtual void Visit(BinaryExpr *node) {
		Nobrackets firstV, secondV;
		node->first->Accept(&firstV);
		node->second->Accept(&secondV);
		switch (node->op) {
		case BinaryOpt::Plus:
			this->level = 1;
			if (firstV.level > this->level || secondV.level > this->level) {
				this->result = "( " + firstV.result + " + " + secondV.result + " )";
			}
			else {
				this->result = firstV.result + " + " + secondV.result;
			}
			break;
		case BinaryOpt::Minus:
			this->level = 1;
			if (firstV.level > this->level || secondV.level > this->level || this->level == secondV.level) {
				this->result = "( " + firstV.result + " - " + secondV.result + " )";
			}
			else {
				this->result = firstV.result + " - " + secondV.result;
			}

			break;
		case BinaryOpt::Multiply:
			this->level = 2;
			if (firstV.level > this->level || secondV.level > this->level) {
				this->result = "( " + firstV.result + " * " + secondV.result + " )";
			}
			else {
				this->result = firstV.result + " * " + secondV.result;
			}

			break;
		case BinaryOpt::Divide:
			this->level = 2;
			if (firstV.level > this->level || secondV.level > this->level || this->level == secondV.level) {
				this->result = "( " + firstV.result + " / " + secondV.result + " )";
			}
			else {
				this->result = firstV.result + "  " + secondV.result;
			}
		}


	}
	virtual void Visit(NumberExpr *node) {
		int n = node->Value;
		bool flag = false;
		if (n < 0) {
			flag = true;
			n = -n;
		}
		while (n) {
			this->result = (char)(n % 10 + '0') + this->result;
			n /= 10;
		}
		this->result = (flag ? '-' + this->result : this->result);
		this->level = 3;

	}

};
class Speak: public Expr::Visitor {
public:
	string result;
	int level;
	virtual void Visit(BinaryExpr *node) {
		Speak firstV, secondV;
		node->first->Accept(&firstV);
		node->second->Accept(&secondV);
		switch (node->op) {
		case BinaryOpt::Plus:
			this->level = 1;
			if (firstV.level > this->level || secondV.level > this->level) {
				this->result = "" + firstV.result + " 加 " + secondV.result + " 的和";
			}
			else {
				this->result = firstV.result + " 加 " + secondV.result;
			}
			break;
		case BinaryOpt::Minus:
			this->level = 1;
			if (firstV.level > this->level || secondV.level > this->level || this->level == secondV.level) {
				this->result =  firstV.result + " 减 " + secondV.result + " 的差";
			}
			else {
				this->result = firstV.result + " 减 " + secondV.result;
			}

			break;
		case BinaryOpt::Multiply:
			this->level = 2;
			if (firstV.level > this->level || secondV.level > this->level) {
				this->result =   firstV.result + " 乘 " + secondV.result + " 的积";
			}
			else {
				this->result = firstV.result + " 乘 " + secondV.result;
			}

			break;
		case BinaryOpt::Divide:
			this->level = 2;
			if (firstV.level > this->level || secondV.level > this->level || this->level == secondV.level) {
				this->result =   firstV.result + " 除 " + secondV.result + " 的商";
			}
			else {
				this->result = firstV.result + " 除" + secondV.result;
			}
		}


	}
	virtual void Visit(NumberExpr *node) {
		int n = node->Value;
		bool flag = false;
		if (n < 0) {
			flag = true;
			n = -n;
		}
		while (n) {
			this->result = (char)(n % 10 + '0') + this->result;
			n /= 10;
		}
		this->result = (flag ? '-' + this->result : this->result);
		this->level = 3;

	}

};


class backsign : public Expr::Visitor {
public:
	string result;
	virtual void Visit(BinaryExpr *node) {
		backsign firstV, secondV;
		node->first->Accept(&firstV);
		node->second->Accept(&secondV);
		switch (node->op) {
		case BinaryOpt::Plus:
				this->result = firstV.result + " " + secondV.result + " +";
				break;
		case BinaryOpt::Minus:
				this->result =  firstV.result + " "+secondV.result + " -";
			break;
		case BinaryOpt::Multiply:
			this->result =  firstV.result + " " + secondV.result + " *";
			break;
		case BinaryOpt::Divide:
				this->result =   firstV.result + " " + secondV.result + " /";
		}

	}
	virtual void Visit(NumberExpr *node) {
		int n = node->Value;
		bool flag = false;
		if (n < 0) {
			flag = true;
			n = -n;
		}
		while (n) {
			this->result = (char)(n % 10 + '0') + this->result;
			n /= 10;
		}
		this->result = (flag ? '-' + this->result : this->result);
	}
};


const string format = "\t";

class drawData : public Expr::Visitor {
public:
	string result;
	int formatnum = 1;
	virtual void Visit(BinaryExpr *node) {
		drawData firstV, secondV;
		
		firstV.formatnum = this->formatnum + 1;
		secondV.formatnum = this->formatnum + 1;
		int n = this->formatnum;
		string tempformat ;
		while (n--) {
			tempformat += format;
		}
		node->first->Accept(&firstV);
		node->second->Accept(&secondV);
		
		switch (node->op) {
		case BinaryOpt::Plus:
			this->result +=   "{\n" + tempformat + firstV.result +"\n" +  tempformat + " + \n" + tempformat + secondV.result + " \n" + tempformat.substr(0,tempformat.length() - 1) + "}";
			break;
		case BinaryOpt::Minus:
			this->result +=   "{\n" + tempformat + firstV.result + "\n" + tempformat + " - \n" + tempformat + secondV.result + " \n" + tempformat.substr(0, tempformat.length() - 1) + "}";
			break;
		case BinaryOpt::Multiply:
			this->result +=  "{\n" + tempformat + firstV.result + "\n" + tempformat + " * \n" + tempformat + secondV.result + " \n" + tempformat.substr(0, tempformat.length() - 1) + "}";
			break;
		case BinaryOpt::Divide:
			this->result +=  "{\n" + tempformat + firstV.result + "\n" + tempformat + " / \n" + tempformat + secondV.result + " \n" + tempformat.substr(0, tempformat.length() - 1) + "}";
		}

	}
	virtual void Visit(NumberExpr *node) {
		int n = node->Value;
		bool flag = false;
		if (n < 0) {
			flag = true;
			n = -n;
		}
		while (n) {
			this->result = (char)(n % 10 + '0') + this->result;
			n /= 10;
		}
		this->result = (flag ? '-' + this->result : this->result);
	}
};


class drawData2 : public Expr::Visitor {
public:

	string result;
	int formatnum = 1;
	virtual void Visit(BinaryExpr *node) {
		drawData2 firstV, secondV;

		firstV.formatnum = this->formatnum + 1;
		secondV.formatnum = this->formatnum + 1;
		int n = this->formatnum;
		string tempformat;
		while (n--) {
			tempformat += format;
		}
		node->first->Accept(&firstV);
		node->second->Accept(&secondV);

		switch (node->op) {
		case BinaryOpt::Plus:
			this->result += "+{\n" + tempformat + firstV.result + "\n" + tempformat + " , \n" + tempformat + secondV.result + " \n" + tempformat.substr(0, tempformat.length() - 1) + "}";
			break;
		case BinaryOpt::Minus:
			this->result += "-{\n" + tempformat + firstV.result + "\n" + tempformat + " , \n" + tempformat + secondV.result + " \n" + tempformat.substr(0, tempformat.length() - 1) + "}";
			break;
		case BinaryOpt::Multiply:
			this->result += "*{\n" + tempformat + firstV.result + "\n" + tempformat + " , \n" + tempformat + secondV.result + " \n" + tempformat.substr(0, tempformat.length() - 1) + "}";
			break;
		case BinaryOpt::Divide:
			this->result += "/{\n" + tempformat + firstV.result + "\n" + tempformat + " , \n" + tempformat + secondV.result + " \n" + tempformat.substr(0, tempformat.length() - 1) + "}";
		}

	}

	virtual void Visit(NumberExpr *node) {
		int n = node->Value;
		bool flag = false;
		if (n < 0) {
			flag = true;
			n = -n;
		}
		while (n) {
			this->result = (char)(n % 10 + '0') + this->result;
			n /= 10;
		}
		this->result = (flag ? '-' + this->result : this->result);
	}
};



int main() {
	shared_ptr<Expr> root = Parser("(* (+(- 1 3) (* 2 4))(-4 5)");
	CalcNumber cal;
	root->Accept(&cal);
	cout << cal.result << endl;

	RootToString rts;
	root->Accept(&rts);
	cout << rts.result << endl;
	

	Nobrackets nb;
	root->Accept(&nb);
	cout << nb.result << endl;

	Speak speak;
	root->Accept(&speak);
	cout << speak.result << endl;


	backsign backsign;
	root->Accept(&backsign);
	cout << backsign.result << endl;

	drawData drawdata;
	root->Accept(&drawdata);
	cout << drawdata.result << endl;

	drawData2 drawdata2;
	root->Accept(&drawdata2);
	cout << drawdata2.result << endl;

	system("pause");
	return 0;

}


