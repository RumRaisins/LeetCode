#include <iostream>
using namespace std;


struct UnionSet {
	int *father;
	int *size;
	int n;
	UnionSet(int n) :n(n) {
		father = new int[n]();
		size = new int[n]();
		for(int i = 0 ; i < n ; ++i){
			father[i] = i;
			size[i] = 1;
		}
	}
	~UnionSet() {
		delete[] father;
		delete[] size;
	}
	int find(int index) const {
		if (father[index] == index)return index;
		int father_index = find(father[index]);
		father[index] = father_index;          //Â·¾¶Ñ¹Ëõ

		return father_index;
	}
	void merge(int p , int q) {
		int father_p = find(p);
		int father_q = find(q);
		if (father_q == father_p) return;
		if (size[father_p] > size[father_q]) {
			father[father_q] = father_p;
			size[father_p] += size[father_q];
		}
		else {
			father[father_p] = father_q;
			size[father_q] += size[father_p];
		}
	}

};



int main() {
	system("pause");
	return 0;
}