#include <iostream>
#include <stdio.h>
using namespace std;


int binary_search(int *data, int n, int target) {
	int l = 0, r = n - 1, mid;
	while (l < r) {
		mid = (l + r ) >> 1;
		printf(" l:%d(%d)  mid%d:(%d) r:%d(%d)\n", data[l], l, data[mid], mid, data[r], r);
		//if (data[mid] == target) {
		//	r = mid;   
		//	//我只关心找到的Mid是不是我想要的
		//	//此种情况可能是我想要的，我想要的前面的1，所以让尾 = mid
		//}
		if (data[mid] >= target) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return data[l] == target ? l : -1;
}



int main() {
	int p[10] = { 0, 0, 0, 0 ,0 ,1 ,1 ,1 ,1 ,1 };
	for (int i = 0; i < 10; i++) {
		printf("%d(%d) ", p[i], i);
	}
	printf("\n");
	int loc = binary_search(p, 10, 1);
	printf("%d(%d)", p[loc], loc);


	system("pause");
	return 0;

}