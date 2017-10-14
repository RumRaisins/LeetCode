#include<iostream>
using namespace std;

class test {
public:
	test() {
		a = 0;
	}
	int &func() {
		return a;
	}
	void out() {
		cout << a << endl;
	}

private:
	int a;

};

int main()
{
	test t;
	int b = t.func();
	b += 10;
	t.out();
	int &c = t.func();
	c += 3;
	t.out();


	system("pause");
	return 0;
}