#include <iostream>
using namespace std;



struct UnionSet {
	int *father;
	int n;
	UnionSet(int n) : n(n) {
		int *p = new int[n]();
		for (int i = 0; i < n; ++i) {
			this->father[i] = i;
		}
	}

	~UnionSet(){
		free(father);
	}

	int find(int index) {
		if (father[index] == index) return index;
		find(father[index]);
	}
	int merge(int p, int q) {
		int father_q = find(q);
		int father_p = find(p);
		if (father_p == father_q) return;
		father[father_p] = father[father_q];
		return;
	}

};




int main() {



	return 0;
}