#include<iostream>
#include<string>
#include<numeric>
#include<functional>
using namespace  std;;


class Solution {
public:
	char findTheDifference(string s, string t) {
		/*int ret = 0;
		int i = 0;
		while (s[i]) {
			ret ^= s[i++];
			ret ^= t[i++];
		}
		ret ^= t[i];
		return ret;*/
		string c = s + t;
		return accumulate(begin(c), end(c), 0, bit_xor<int>());
	}
	
};

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	Solution solution;
	cout << solution.findTheDifference(s1, s2);
	system("pause");
	return 0;
}