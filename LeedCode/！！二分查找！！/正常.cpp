#include <iostream>
#include <stdio.h>
using namespace std;


int binary_search(int *data, int n , int target) {
	int l = 0, r = n - 1, mid;
	while (l <= n) {
		mid = (l + r) >> 1;
		if (data[mid] == target) {
			return mid;
		}
		else if (data[mid] > target) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}



int main() {
	int p[10] = { 1, 2, 3, 3 ,5 ,6 ,7 ,7 ,8 ,9 };
	for (int i = 0; i < 10; i++) {
		printf("%d(%d) ", p[i], i);
	}
	printf("\n");
	int loc = binary_search(p, 10, 3);
	printf("%d(%d)", p[loc] , loc);


	system("pause");
	return 0;

}