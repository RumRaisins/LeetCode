#include <iostream>
using namespace std;


class B;
class C;
class D;
class E;
class A {
public:
	class Visitor {
	public:
		virtual  void sayyourname(B *a) = 0;
		virtual  void sayyourname(C *a) = 0;
		virtual  void sayyourname(D *a) = 0;
		virtual  void sayyourname(E *a) = 0;

	};

	virtual void Accept(Visitor *visitor) = 0;


	virtual ~A() {

	}

};
class B : public A {
public:


	virtual void Accept(Visitor* visitor) {
		visitor->sayyourname(this);
	}
};

class C : public A {
public:
	virtual void Accept(Visitor* visitor) {
		visitor->sayyourname(this);
	}
};

class D : public A {
public:
	virtual void Accept(Visitor* visitor) {
		visitor->sayyourname(this);
	}
};

class E : public A {
public:
	virtual void Accept(Visitor* visitor) {
		visitor->sayyourname(this);
	}

};


class sayname : public A::Visitor {
	virtual void sayyourname(B *a) {
		cout << "this is B" << endl;
	}
	virtual void sayyourname(C *a) {
		cout << "this is C" << endl;
	}
	virtual void sayyourname(D *a) {
		cout << "this is D" << endl;
	}
	virtual void sayyourname(E *a) {
		cout << "this is E" << endl;
	}



};

class sayB : public A::Visitor {
	virtual void sayyourname(B *b) {
		cout << "this is B" << endl;
	}
	virtual void sayyourname(C *a) {
	
	}
	virtual void sayyourname(D *a) {

	}
	virtual void sayyourname(E *a) {

	}
};



int main() {

	A *a = new C();

	sayname say;
	a->Accept(&say);


	A *b = new B();
	sayB sayb;
	a->Accept(&sayb);
	b->Accept(&sayb);
	system("pause");
	return 0;

}