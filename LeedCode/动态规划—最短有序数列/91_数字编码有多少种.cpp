#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s.length() == 0 || s[0] == '0')
		{
			return 0;
		}
		int ls = s.length();
		if (ls == 1) return 1;
		int last = 1, current = 1;
		for (int i = 1; i < ls; i++)
		{
			int temp = current;
			if (s[i] == '0') {
				if (s[i - 1] == '1' || s[i - 1] == '2') current = last;
				else return 0;
			}
			else if ( (s[i] <= '6' &&  s[i - 1] == '2' )|| s[ i - 1] == '1') current += last;
			else  current = current;
			last = temp;
		}
		return current;
	}
};
int main() {

	string s = "101";
	while (cin >> s) {
		Solution sol;
		cout << sol.numDecodings(s)<<endl;
	}
	system("pause");
}