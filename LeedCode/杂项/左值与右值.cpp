#include<iostream>
using namespace std;


void func(int &&a) {
	cout << "Right value" << endl;
}

void func(int &a) {
	cout << "Left value" << endl;
}


void test(int &&a) {
	func(a);
	cout << "---------" << endl;
	func(forward<int>(a));
}
void test(int &a) {
	func(std::move(a));
}

int main() {
	int a = 10;
	test(a);
	system("pause");
	return 0;
}
