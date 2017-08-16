#include <vector>
#include <set>
using std::vector;
using std::set;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> set;
		for (int c : nums) {
			set.insert(c);
		}
		return set.size() < nums.size();
	}
};