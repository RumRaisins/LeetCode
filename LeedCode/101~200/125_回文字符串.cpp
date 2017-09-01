#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool iscase(char c) {
		if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) return false;
		return true;
	}
	char toLow(char c) {
		if ('A' <= c && c <= 'Z') {
			return c + 32;
		}
		return c;
	}
	bool isPalindrome(string s) {
		int ls = s.length();
		if (ls == 0 || ls == 1) return true;
		int l = 0, r = ls - 1;
		while (l < r) {
			while (iscase(s[l]))l++;
			while (iscase(s[r]))r++;
			if (toLow(s[l++]) != toLow(s[--r])) {
				cout << s[l] << "!=" << s[r] << endl;
				return false;
			}
		}
		return true;
	}
};

int main() {
	string s = "    abba abba   ";
	Solution sol;
	cout << sol.isPalindrome(s);

	system("pause");
	return 0;
}