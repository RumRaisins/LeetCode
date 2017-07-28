#include"Head.h"
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//不需要排序
		unordered_map<int, int> map;
		vector<int> vec;
		int u;
		for (int i = 0; i < nums.size(); i++) {
			u = target - nums[i];
			if (map.find(u) != map.end()) {
				vec.push_back(map[u]);
				vec.push_back(i);
				return vec;
			}
			map[nums[i]] = i;
		}
		//没有找到
		return vec;
	}
};


int main() {
	vector<int> vec;
	vec.push_back(2); vec.push_back(7); vec.push_back(11); vec.push_back(5);
	Solution sol;
	vector<int> vecc = sol.twoSum(vec, 9);
	for (auto c : vecc) {
		cout << c << " ";
	}


	system("pause");
	return 0;
}