//#include <iostream>
//int a = 0;
//int main() {
//
//	
//	auto c = [a]() {a++; }
//	return 0;
//}
#include <iostream>
#include <functional>

using namespace std;



int main()
{
	//->int 代表返回值为int
	function<int(int)> fib = [&fib](int i) ->int {
		if (i < 2) {
			return 1;
		}
		else {
			return fib(i - 1) + fib(i - 2);
		}
	};
	for (int i = 0; i < 10; i++)
	{
		cout << fib(i) << endl;
	}


	function<double(double)> inc = [](int x) {return 1 + x; };
	int(*square)(int) = [](int x) {return x * x; };
	return 0;
}
