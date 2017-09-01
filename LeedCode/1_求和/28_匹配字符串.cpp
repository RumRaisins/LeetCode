#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		int ln = needle.length();
		int lh = haystack.length();
		int next[256];
		for (int i = 0; i < 256; ++i) {
			next[i] = ln + 1;
		}
		for (int i = 0; needle[i]; ++i) {
			next[needle[i]] = ln - i;
		}
		int i = 0, j = 0;
		while (i + ln <= lh) {
			if (haystack[i + j] != needle[j]) {
				i += next[haystack[i + ln]];
				j = 0;
			}
			else {
				++j;
			}
			if (needle[j] == '\0') {
				return i;
			}
		}
		return -1;
	}
};