	#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void heap_sort(int *p, int n) {
	for (int i = 1; i < n; ++i) {
		int current = i;
		int father = (current - 1) / 2;
		while (p[current] > p[father]) {
			swap(&p[current], &p[father]);
			current = father;
			father = (current - 1) / 2;
		}
	}
	for (int i = n - 1; i >= 1; --i) {
		swap(&p[i], &p[0]);
		int l, r, max_index = 0;
		while (true) {
			l = 2 * max_index + 1;
			r = 2 * max_index + 2;
			if (l < i && p[l] > p[max_index]) {
				max_index = l;
			}
			if (r < i && p[r] > p[max_index]) {
				max_index = r;
			}
			if (max_index == l || max_index == r) {
				swap(&p[max_index], &p[(max_index - 1) / 2]);
			}
			else {
				break;
			}
 		}
	}
}

int main() {
	int p[10] = { 32,4,21,54,10,78,8,24,6,7 };
	heap_sort(p, 10);
	for (auto c : p) {
		printf("%d ", c);
	}


	system("pause");
	return 0;
}