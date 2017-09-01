#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
	string reverseString(string s) {
		int ls = s.length();
		int l = 0, r = ls - 1;
		char temp;
		while (l < r) {
			temp = s[l];
			s[l] = s[r];
			s[r] = temp;
			++l;
			--r;
		}
		return s;
	}
};
int main() {
	string s = "hello";
	Solution sol;
	std::cout <<sol.reverseString(s);


	system("pause");
	return 0;
}