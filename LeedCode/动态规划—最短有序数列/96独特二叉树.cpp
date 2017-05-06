#include <iostream>
using namespace std;
class Solution {
public:
	int numTrees2(int n) {
		if (n == 1 || n == 0) {
			return 1;
			
		}
		int num = 0;
		for (int i = 1; i <= n; i++)
		{
			num += numTrees2(i-1)*numTrees2(n - i);
		}
		return num;
	}
	int numTrees(int n) {
		int *p = new int[n + 1]();
		p[0] = 1; p[1] = 1;
		//cout << "第1为根，左子树有0个，右子树有" << n - 1 << "个" << endl;
		for (int i = 2; i <=n; i++) {
			for (int j = 1; j <= i; j++) {
				//cout << "第" << i << "为根,左子树有" << j << "个，右子树有" << i - j << "个" << endl;
				p[i] += p[j - 1] * p[i - j];
			}
		}
		return p[n];
	}
};

int main() {
	int n;
	while (cin >> n) {
		Solution sol;
		cout << sol.numTrees(n) << endl;
		cout << sol.numTrees2(n);
	}
	system("pause");
	return 0;
}