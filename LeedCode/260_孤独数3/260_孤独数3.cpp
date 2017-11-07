#include<iostream>
#include<vector>
#include<numeric>
#include<functional>
using namespace  std;;


class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int r = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
		vector<int> s = { 0,0 };
		int num = 0, num2 = r;
		r = ((r ^ r - 1) / 2) + 1;
		for (int c : nums) {
			if (r&c)
				s[0] ^= c;
		}
		s[1] = s[0] ^ num2;
		return s;
	}
};

int main() {
	vector<int> t;
	t.push_back(1);
	t.push_back(2);
	t.push_back(1);
	t.push_back(3);
	t.push_back(2);
	t.push_back(5);
	Solution sol;
	t = sol.singleNumber(t);
	for (int c:t)
	{
		cout << c<<" ";
	}
	system("pause");
	return 0;


}

