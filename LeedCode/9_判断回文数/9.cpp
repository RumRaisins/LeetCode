#include <iostream>

class Solution {
public:
	bool isPalindrome(int x) {
		int y = 0, lasty = 0, c = x;
		if (x < 0) return false;
		while (x)
		{
			y = y * 10 + x % 10;
			if ((y / 10) != lasty) {
				return false;
			}
			x = x / 10;
			lasty = y;
		}
		return c == y;
	}
};

int main() {
	int x;
	std::cin >> x;

	Solution solutin;
	std::cout<<solutin.isPalindrome(x)<<std::endl;
	system("pause");
	return 0;

}