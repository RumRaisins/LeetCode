#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;


void swap(int &a, int &b) {
	if (a != b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return;
}


void heap_sort(int *nums, int length) {
	//堆得建立
	for (int i = 1; i < length; ++i) {
		int current = i;
		int father = (current - 1)  >> 1;
		while (nums[current] > nums[father]) {
			swap(nums[current], nums[father]);
			current = father;
			father = (current - 1) / 2;
		}
	}
	//出堆
	for (int i = length - 1; i >= 1; --i) {
		swap(nums[0], nums[i]);
		int current = 0  , l , r;
		while (true) {
			l = current * 2 + 1;
			r = current * 2 + 2;
			if (l < i && nums[l] > nums[current]) {
				current = l;
			}
			if (r < i && nums[r] > nums[current]) {
				current = r;
			}
			if (current == l || current == r) {
				swap(nums[current], nums[(current - 1) >> 1]);
			}
			else {
				break;
			}

		}
	}
}

int main() {
	int p[10] = { 45 ,23, 21, 5, 3 ,67,23,21,6,3 };
	heap_sort(p, 10);
	for (auto c : p) {
		printf("%d ", c);
	}

	priority_queue<int, vector<int>, less<int> > XXX;


	system("pause");
	return 0;
}