#include <iostream>
using namespace std;

struct Node;

struct UnionSet {
	int  *color;
	int n;

	UnionSet(int n) : n(n) {
		this->color = (int *)malloc(n * sizeof(int));
		for (int i = 0; i < n; ++i) {
			this->color[i] = i;
		}
	}
	~UnionSet() {
		free(this->color);
	}


	int find(int index) const {
		return this->color[index];
	}
	void merge(int p , int q) {
		int color_p, color_q;
		color_p = find(p);
		color_q = find(q);
		if (color_q == color_q) {
			cout << "无效的操作" << endl;
			return;
		}
		for (int i = 0; i < n; ++i) {
			if (find(i) != color_q) continue;
			this->color[i] = color_q;
		}
	}
};


int main() {

	return 0;
}