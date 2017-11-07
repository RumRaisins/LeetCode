#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) return 0;
		int l = 1, r = x, mid, mid2;
		while (l < r) {
			mid = l + ((r - l) / 2) + 1;
			if (mid <= x / mid) {
				l = mid;
				cout << l << endl;
				//mid2 = mid;
			}
			else {
				r = mid - 1;
			}
		}
		return l;
	}
};

int main() {


	int n;
	Solution sol;
	while (cin >> n) {
		cout << sol.mySqrt(n);
	}
	system("pause");

	return 0;
}