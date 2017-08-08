#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int *p = new int[100]();
		p[0] = 1;
		return help(nums, target, p);
	}
	int help(vector<int>& nums, int target, int *p) {
		if (target == 0) {
			return 1;
		}
		int index = 0;
		int ans = 0;
		while (index < nums.size()) {
			if (target < nums[index]) {
				++index;
				continue;
			}
			if (p[target - nums[index]]) {
				ans += p[target - nums[index]];
			}
			else {
				int temp = help(nums, target - nums[index], p);
				p[target - nums[index]] = temp;
				ans += temp;
			}
			++index;
		}
		return ans;
	}
};

int main() {
	vector<int> vec;
	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	cin >> n;
	Solution sol;
	cout << sol.combinationSum4(vec, n)<<endl;

	system("pause");
	return 0;

}