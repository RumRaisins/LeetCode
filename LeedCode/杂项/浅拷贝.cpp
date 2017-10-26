#include <iostream>
#include <cstdlib>
using namespace std;

class A {
public:
	A(int size = 10) : size(size) {
		data = (int *)malloc(size * sizeof(int));
	}
	A (const A& other){
		cout << "copy" << endl;
		this->data = other.data;
	}
	~A() {
		free(data);
		data = nullptr;
	}
private:
	int *data;
	int size = 10;
};


int main() {
	A a;
	A b = a;
	a.~A();
	b.~A();

	system("pause");
	return 0;

}