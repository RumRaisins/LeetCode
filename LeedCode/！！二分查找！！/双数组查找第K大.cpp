#include <stdio.h>
#include <stdlib.h>
int __find_kth_number(int *num1, int *num2, int l1, int l2, int k) {
	if (k > l1 + l2) return -1;
	if (l1 == 0) return num1[k - 1];
	if (l2 == 0)  return num2[k - 1];
	if (k == 1) {
		return num1[0] < num2[0] ? num1[0] : num2[0];
	}
	int a1, b1;
	a1 = l1 < (k / 2) ? l1 : (k / 2);
	b1 = k - a1;
	if (num1[a1 - 1] < num2[b1 - 1]) {
		num1 += a1;
		l1 -= a1;
		k -= a1;
	}
	else {
		num2 += b1;
		l2 -= b1;
		k -= b1;
	}
	return __find_kth_number(num1, num2, l1, l2, k);
}

int find_kth_number(int *num1, int *num2, int n, int k) {
	return __find_kth_number(num1, num2, n, n, k);
}
int main() {
	int n;
	scanf("%d", &n);
	int *num1 = (int*)malloc(n * sizeof(int));
	int *num2 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &num1[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &num2[i]);
	}
	int m, tp;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &tp);
		printf("%d\n", find_kth_number(num1, num2, n, tp));
	}
	return 0;
}