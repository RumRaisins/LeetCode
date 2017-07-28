#include<iostream>
#include <vector>
#include<numeric>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int r;
	
		return accumulate(nums.begin(), nums.end(), 0,[](int a, int b) {return a^b; });
		       accumulate(nums.begin(), nums.end(), 0,[](int a, int b) { return a^b; });
	}
};
