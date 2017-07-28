
#include<vector>
#include<unordered_map>
using namespace std;



class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int>map;
		int lnums = nums.size();
		for (int i = 0; i < lnums; i++)
		{
			if (i > k) map.erase(nums[i - k - 1]);
			if (map.find(nums[i])!=map.end()) {
				if(map[nums[i]] - i <=  k )
				return true;
			}
			map[nums[i]] = i;
		}
		return false;
	}
};