#include<iostream>
#include<vector>
using namespace std;
#define max(a,b) (((a)>(b))?(a):(b))
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int lnums = nums.size();
		int *p = new int[lnums]();
		p[0] = nums[0];
		int maxp = p[0];
		for(int i = 1 ; i < lnums; i++)
		{
			p[i] = max(p[i - 1] + nums[i], nums[i]);
			maxp = max(p[i], maxp);
		}
		return maxp;
	}
};
