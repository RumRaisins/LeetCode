#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int change(char s) {
		switch (s)
		{
		case 'I':  return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L':return 50;
		case 'C':return 100;
		case'D':return 500;
		case'M':return 1000;
		default: return 0;
			break;
		}
		
	}
	int romanToInt(string s) {
		int ls = s.length();
		int num = 0;
		int lastnum = 0 , nnum = 0;
		for (int i = 0; i < ls; i++)
		{
			nnum = change(s[i]);
			cout << nnum << " ";
			num += nnum;
			if (nnum > lastnum) {
				num -= 2 * lastnum;
			}
			lastnum = nnum;
		}
		return num;
	}
};

int main() {

	string s;
	cin >> s;
	Solution ss;
	ss.romanToInt(s);

	system("pause");

}