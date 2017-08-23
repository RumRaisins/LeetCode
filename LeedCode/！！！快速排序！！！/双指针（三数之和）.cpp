#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int* three_sum(int *nums, int length, int target) {
	int *ans =(int*) malloc(sizeof(int) * 3);
	int l, r;
	for (int i = 0; i < length; ++i) {
		int temp = target - nums[i];
		l = 0;
		r = length - 1;
		while (l < r) {
			if (nums[l] + nums[r] > temp || r == i)--r;
			else if (nums[l] + nums[r] < temp || l == i) ++l;
			else {
				ans[0] = i;
				ans[1] = l;
				ans[2] = r;
				cout << ans[0] << " "<< ans[1] << " " << ans[2] <<endl;
				break;
			}
		}

	}
	return ans;
}

int main() {
	int p[10] = { -43 ,-36 ,-32 ,-32 ,17 ,30 ,32 ,37 ,39 };
	int *a = new int[3]();
	a = three_sum(p, 9, 30);
	


	system("pause");
	return 0;
}