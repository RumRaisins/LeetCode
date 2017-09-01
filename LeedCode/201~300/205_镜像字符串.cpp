#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string StringToMark(string& s) {
		int *mark = (int *)calloc(256, sizeof(int));
		for (int i = 0; s[i]; ++i) {
			if (mark[s[i]] == 0) {
				mark[s[i]] = i + 1;
			}
			s[i] = mark[s[i]]   + '0';
		}
		delete[]mark;
		return s;
	}
	bool isIsomorphic(string s, string t) {
		size_t ls = s.length();
		int lt = t.length();
		if (lt != ls) return false;
		return StringToMark(s) == StringToMark(t) ? true : false;
	}
};
int main() {
	string s = "fg";
	string t = "gg";

	Solution sol;
	cout << sol.isIsomorphic(s, t);
	system("pause");
	return 0;
}