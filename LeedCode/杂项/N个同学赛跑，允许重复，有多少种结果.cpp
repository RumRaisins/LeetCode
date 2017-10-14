#include <iostream>
using namespace std;

int howmany(int n) {
	if (n == 0) return 1;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ans += howmany(n - j);
		}
	}
	return ans;
}
int main() {

	int n;
	cin >> n;
	cout << howmany(n) << endl;
	system("pause");
	return 0;
}