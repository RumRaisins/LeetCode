#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	int myAtoi(string str) {
		int ls = str.length();
		int a = 0, last = 0, sign = 1, ov = 0;
		int i = str.find_first_not_of(' ');

		if (str[i] == '+') {
			sign = 1;
			i++;
		}
		else if (str[i] == '-') {
			sign = 0;
			i++;
		}
		while ('0' <= str[i] && str[i] <= '9'&& i < ls)
		{
			a = (a * 10 + (str[i++] - '0'));
			if ((a / 10) != last) {
				ov = 1;
				break;
			}
			last = a;
		}
		return ov ? (sign ? INT_MAX : INT_MIN) : (sign ? a : a * -1);
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


