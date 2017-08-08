#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
	int IsEquqal(const string& s,int i,int j,int ls) {
		if (i < 0 || j == ls) return 0;
		return s[i] == s[j] ? IsEquqal(s, i - 1, j + 1, ls) + 1 : 0;
	}
	string longestPalindrome(const string& s) {
		int ls = s.length();
		if (ls == 1) return s.substr(0,1);
		int maxlength[2] = { 0,0 };
		bool choose = false;
		int temp;
		for (int i = 1 ; i < ls ; i++)
		{
		   if (s[i - 1] == s[i + 1]) {
				temp = 1;
				temp += IsEquqal(s, i - 2, i + 2, ls);
				if (maxlength[0] < 2 * temp + 1) {
					maxlength[0] = 2 * temp + 1;
					maxlength[1] = i;
					choose = false;
				}	
			}
		   if (s[i] == s[i - 1]) {
			   temp = 1;
			   temp += IsEquqal(s, i - 2, i + 1, ls);
			   if (maxlength[0] < 2 * temp) {
				   maxlength[0] = 2 * temp;
				   maxlength[1] = i;
				   choose = true;
			   }

		   }
		}
		if (maxlength[1] == 0 && maxlength[0] == 0) {
			return s.substr(0,1);
		}
		return choose ? s.substr(maxlength[1] - (maxlength[0] / 2), maxlength[0]) : s.substr(maxlength[1] - (maxlength[0] - 1) / 2, maxlength[0]);
	}
};

int main() {

	//string s = "xabcddcbaxxxxabcdeffedcba";
	//string s = "cccc";
	string s = "a";
	//cout << s.substr(0, 1);
	Solution sol;
	//cout << s[5-sol.IsEquqal(s, 5 - 1,5, 9)];
	cout << sol.longestPalindrome(s);
	system("pause");
}