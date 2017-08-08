#include<iostream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		int y = 0, lasty = 0, z = 0;
		x < 0 ? x = -x : z = 1;
		while (x)
		{
			y = y * 10 + x % 10;
			if ((y / 10) != lasty) {
				return 0;
			}
			x = x / 10;
			lasty = y;
		}
		z == 1 ? y = y : y = -y;
		return y;
	}
};
int main() {
	Solution solution;
	int x;
	cin >> x;
	cout << solution.reverse(x) << endl;
	system("pause");
	return 0;
}