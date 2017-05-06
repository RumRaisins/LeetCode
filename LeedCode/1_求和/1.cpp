#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>  
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		vector<int> vec;
		int u;
		for (int i : nums) {
			u = target - nums[i];
			if (map.find(u) != map.end()) {
				vec.push_back(map[u]);
				vec.push_back(i + 1);
				return vec;
			}
			map[nums[i]] = i;
		}
		return vec;
	}
};
