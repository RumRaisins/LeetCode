#include <iostream>
using namespace std;

int findn(int n ,int twon) {
	if (n < 0) return 0;
	if (n == 0) {
		printf("0\n");
		return 1;
	}
	int ans = 0;
	ans += findn(n - twon , twon * 2);
	ans += findn(n - twon * 2 , twon * 2);
	return ans;
}

int main() {

	int n;
	cin >> n;
	int ans = 1;
	printf("%d" , findn(n, 1));

	system("pause");
	return 0;
}