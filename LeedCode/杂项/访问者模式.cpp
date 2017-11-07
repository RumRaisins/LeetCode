#include <iostream>
#include <string>
using namespace std;

class B;
class C;
class D;
class E;
class A {
public:
	class Visitor {
	public:
		virtual void visitor(B* v) = 0;
		virtual void visitor(C* v) = 0;
		virtual void visitor(D* v) = 0;
		virtual void visitor(E* v) = 0;
		virtual void visitor(D* v) = 0;
	};
	virtual void  Accept(Visitor *v) = 0;
};
class B : public A {
public:
	virtual void Accept(Visitor *v) {
		v->visitor(this);
	}
};
class C : public A {
public:
	virtual void Accept(Visitor *v) {
		v->visitor(this);
	}
};
class D : public A {
public:
	virtual void Accept(Visitor *v) {
		v->visitor(this);
	}
};
class E : public A {
public:
	virtual void Accept(Visitor *v) {
		v->visitor(this);
	}
};

class Vistor_whichchild :public  A::Visitor {
public:
	virtual void visitor(B* ptr) {
		cout << "this is B" << endl;
	}
	virtual void visitor(C* ptr) {
		cout << "this is C" << endl;
	}
	virtual void visitor(D* ptr) {
		cout << "this is D" << endl;
	}
	virtual void visitor(E* ptr) {
		cout << "this is E" << endl;
	}
};

int main() {
	A* a = new C();
	Vistor_whichchild c;
	a->Accept(&c);

	system("pause");
	return 0;
}