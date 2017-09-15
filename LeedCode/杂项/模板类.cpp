#include <cstdio>
#include <iostream>
using std::cout;
template <typename T>
void swap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}


template <typename T>
struct arry {
	void reverse() {
		int l = 0, r = size - 1;
		while (l < r) {
			swap(data[l++], data[r--]);
		}
	}
	int size;
	T *data;
	T temp;
	arry(int n) :size(n) {
		data = new T[size];
	};
	T & operator [](int index) {
		if (index < 0 || index >= size) {
			printf("Arry out of index\n");
			return temp;
		}
		return data[index];
	}
	void output() {
		for (int i = 0; i < size; ++i) {
			cout << data[i] << " ";
		}
	}
};




int main() {
	int i = 0;
	arry<int> ar(10);
	for (; i < 10; ++i) {
		ar[i] = i;
	}
	ar.reverse();
	ar.output();

	system("pause");
	return 0;
}