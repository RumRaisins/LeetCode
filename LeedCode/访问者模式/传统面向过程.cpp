#include <iostream>
#include <string>
using namespace std;

class B;
class C;
class D;
class E;
class A {
public:
	virtual ~A() {

	}
	
};
class B : public A {
public:
	
};
class C : public A {
public:
	
};
class D : public A {
public:

};
class E : public A {
public:

};

void test(A *a) {
	dynamic_cast<B *>(a) != NULL && cout << "����Bָ��" << endl;
	dynamic_cast<C *>(a) != NULL && cout << "����Cָ��" << endl;
	dynamic_cast<D *>(a) != NULL && cout << "����Dָ��" << endl;
	dynamic_cast<E *>(a) != NULL && cout << "����Eָ��" << endl;
	if (dynamic_cast<E *>(a) != NULL) {

	}
	else if (dynamic_cast<D *>(a) != NULL) {


	}
}
int main() {
	A* a = new C();

	test(a);

	system("pause");
	return 0;
}