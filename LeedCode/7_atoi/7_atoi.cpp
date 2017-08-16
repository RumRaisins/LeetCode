#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	int myAtoi(string str) {
		int ls = str.length();
		int a = 0,sign =1;
		int i = str.find_first_not_of(' ');

		if (str[i] == '+') {
			sign = 1;
			i++;
		}
		else if (str[i] == '-') {
			sign = -1;
			i++;
		}
		while('0' <= str[i] && str[i] <= '9'&& i < ls)
		{
			a = (a * 10 + (str[i++] - '0'));
			if (a*sign >= INT_MAX) return INT_MAX;
			if (a*sign <= INT_MIN) return INT_MIN;
		}
		return a*sign;
	}
};

int main() {
	string s;
	while (cin >> s) {
		Solution sol;
		cout << sol.myAtoi(s);
	}
	system("pause");

}


