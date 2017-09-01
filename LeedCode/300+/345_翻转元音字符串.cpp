#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isvowels(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			return true;
		}
		return false;

	}

	string reverseVowels(string s) {
		int ln = s.length();
		if (ln == 0 || ln == 1) return s;
		int l = 0, r = ln - 1;
		char temp;
		while (l < r) {
			while (l < r && !isvowels(s[l])) ++l;
			while (l < r && !isvowels(s[r])) --r;
			temp = s[l];
			s[l] = s[r];
			s[r] = s[l];
			++l, --r;
		}
		return s;
	}
};