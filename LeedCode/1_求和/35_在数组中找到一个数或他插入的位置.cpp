#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (target < nums[0]) return 0;
		if (target > nums[nums.size() - 1]) return nums.size();
		int head = 0, tail = nums.size() - 1, mid;
		while (head < tail) {
			mid = (head + tail + 1) >> 1;
			if (nums[mid] == target) {
				return mid;
			}
			else if (nums[mid] > target) {
				tail = mid - 1;
			}
			else {
				head = mid;
			}
		}
		return head + 1;

	}
};

int main() {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);
	std::cout << vec.size() << std::endl;
	Solution sol;
	std::cout<<sol.searchInsert(vec, 6);

	system("pause");
	return 0;

}