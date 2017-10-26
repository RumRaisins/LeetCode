#include <iostream>
#include <stack>
using namespace std;


template<typename T>
void __help(stack<T>& s,int n) {
	if (n == 0) return;
	T buttom = s.top();
	s.pop();
	T temp = s.top();
	s.pop();
	s.push(buttom);
	__help(s, n - 1);
	s.push(temp);
	
}
template<typename T>
void reversestack(stack<T>& s) {
	int n = s.size() ;
	while (n--) {
		__help(s, n);
	}
}


int main() {

	stack<int> s;
	for (int i = 0; i < 10; ++i) {
		s.push(i);
	}
	/*
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	*/
	cout << "\n---------" << endl;
	reversestack<int>(s);

	if (s.empty()) { cout << "s is null \n"; }
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	system("pause");
	return 0;

}