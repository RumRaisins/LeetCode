#include <iostream>

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		while (s[0] == ' ')s++;
		if (s == NULL || s[0] == '\0') return 0;
		const char *begin = s++;
		const char *end = s;
		while (s[0]) {
			while (s[0] == ' ') s++;
			if (s[0] == '\0') break;
			if (s[-1] == ' ')begin = s;
			if (s[1] == ' ' || s[1] == '\0') end = s + 1;
			s++;
		}
		return end - begin;
	}
};