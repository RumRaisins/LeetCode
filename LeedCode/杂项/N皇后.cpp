#include<iostream>
#include <stdlib.h>
using namespace std;


#define MAX_N 20

int col_valid[MAX_N] = { 0 };
int v1_valid[MAX_N] = { 0 };
int v2_valid[MAX_N] = { 0 };
int n;
// 正斜列 
//安排第i个皇后 的方法。
int queen(int i) {
	if (i == n) return 1;
	int ans = 0;
	for (int j = 0; j < n; ++j) {
		if (col_valid[j]) continue;
		if (v1_valid[i + j]) continue;
		if (v2_valid[n - i + j])continue;
		col_valid[j] = 1;
		v1_valid[i + j] = 1;
		v2_valid[n - i + j] = 1;
		ans += queen(i + 1);
		col_valid[j] = 0;
		v1_valid[i + j] = 0;
		v2_valid[n - i + j] = 0;
	}
	return ans;
}




int main() {
	int ans[11] = { 0 };
	for (int i = 1; i <= 10; ++i) {
		n = i;
		ans[i] = queen(0);
	}
	while (cin >> n) {
		if (!n) break;
		cout << ans[n] << endl;
	}
	return 0;
}