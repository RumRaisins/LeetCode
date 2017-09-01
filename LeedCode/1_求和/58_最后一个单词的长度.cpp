#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0, tail = s.length();
		while (tail >= 0 && s[tail] == ' ') --tail;
		while (tail >= 0 && s[tail] != ' ') {
			--tail;
			++len;
		}

		return len;
	}
};