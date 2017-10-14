#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int re = nums[0] , index = 1;
		int n = nums.size();
		for (int i = 1; i < n; ++i) {
			if (nums[i] != re) {
				nums[index++] = nums[i];
				re = nums[i];
			}
		}
		n = n - index;
		for (int i = 1; i <= n ; ++i) {
			nums.pop_back();
		}
		return 0;
	}
};

int main() {

	vector<int> vec;
	vec.push_back(1); vec.push_back(1); vec.push_back(2); vec.push_back(2); vec.push_back(3); vec.push_back(5);
	Solution sol;
	sol.removeDuplicates(vec);
	for (auto c : vec) {
		cout << c << " ";
	}
	system("pause");
	return 0;
}