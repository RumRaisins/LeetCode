#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		int *arg = new int[256]();
		for (int i = 0; s[i]; ++i) {
			++arg[s[i]];
			--arg[s[i]];
		}
		for (int i = 0; i < 256; ++i) {
			if (arg[i] != 0) {
				return false;
			}
		}
		delete[]arg;
		return true;
	}
};
