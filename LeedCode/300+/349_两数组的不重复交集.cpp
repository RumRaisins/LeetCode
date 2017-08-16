#include "ch.h"

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> set_nums, result;
		vector<int>result_vec;
		for (int c : nums1) {
			set_nums.insert(c);
		}
		for (int c : nums2) {
			if (set_nums.find(c) != set_nums.end()) {
				result.insert(c);
			}
		}
		for (int c : result) {
			result_vec.push_back(c);
		}
		return result_vec;

	}
};