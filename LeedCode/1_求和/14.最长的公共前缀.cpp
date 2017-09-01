#include <string>
#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int ln = strs.size();
		string result;
		int index = 0 , count = 0;
		while (1) {
			for (int i = 0; i < ln - 1; ++i) {
				if (strs[i][index] == '\0') return result;
				if (strs[i][index] != strs[i + 1][index]) {
					return result;
				}
				if (i == ln - 2) {
					result += strs[i][index];
					++index;
				}
			}
		}
	}
};

int main() {
	vector<string> strs;
	strs.push_back("abcdfe");
	strs.push_back("abcdfegtgsds");
	strs.push_back("abcdfetgwsdas");
	strs.push_back("abcdfesda");
	strs.push_back("abcdfeasddsfa");
	strs.push_back("abcdfegcvx");
	strs.push_back("abcd");
	Solution sol;
	std::cout << sol.longestCommonPrefix(strs);
	system("pause");
	return 0;
}