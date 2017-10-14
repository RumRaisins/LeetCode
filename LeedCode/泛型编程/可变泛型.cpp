#include <iostream>
#include <type_traits>
#include <string>
using std::conditional;
using namespace std;


template <typename T,typename ...REST>
struct ARG {
	
	typedef T __type;
	typedef ARG<REST...> __rest;
};
template <typename T>
struct ARG<T> {
	typedef T __type;
	typedef T __last;
};
template<typename T, typename ...ARGS> struct Test;
template<typename T , typename ...ARGS>
struct Test<T(ARGS...)>
{
	T operator () (typename ARG<ARGS...>::__type a, typename ARG<ARGS...>::__rest::__last b) {
		return a + b;
	}

};
template<typename T ,typename U>
typename conditional<(sizeof(T) > sizeof(U)), T, U>::type 
add(T a, U b) {
	return a + b;
}



template<typename T, typename ...ARGS>
void print(T a, ARGS... args) {
	cout << a << " ";
	print(args...);
}
template<typename T>
void print(T a) {
	cout << a << endl;
}
template<typename T>
struct S{
	template<typename U>
	U add(U a, U b) {
		return a + b;
	}
};

int main() {
	
	//Test<int(int,int)> t;
	//cout << t(2, 3);
	//cout << add(1.23, 23);
	print("sdasd", 25, 25.5, 5,"fddfsdf");

	system("pause");
	return 0;
}