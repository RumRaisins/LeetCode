#include<iostream>
#include<vector>
using namespace std;




class Solution {
public:
	void Qsort(vector<int>& nums, int i, int j) {
		if (j - i <= 1) {
			return;
		}
		if (j - i == 2) {
			if (nums[i] > nums[i + 1]) {
				swap(nums[i], nums[i + 1]);
				return;
			}
		}
		int s = i, e = j, temp = nums[i];
		j--; 
		while (i < j) {
			while (i < j && nums[j] >= temp) j--;
			if (i < j) nums[i] = nums[j], i++;
			while (i < j && nums[i] < temp)i++;
			if (i < j)nums[j] = nums[i], j--;
		}
		nums[i] = temp;
		Qsort(nums, s, i );
		Qsort(nums, i + 1, e);
		return;
	}

	bool containsDuplicate(vector<int>& nums) {
		if (nums.empty())
			return false;
		Qsort(nums, 0, nums.size());
		for (int i = 0; i < nums.size() - 1 ; i++)
		{
			if (nums[i] == nums[i + 1])
				return true;
		}
		return false;

	}
};

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		return nums.size() > set<int>(nums.begin(), nums.end()).size();
	}
};
int main() {
	vector<int> vec;
	Solution sol;
	vec.push_back(9);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(7);
	vec.push_back(5);
	//sol.Qsort(vec, 0, 10);
	cout<<sol.containsDuplicate(vec);
	for (int i : vec) {
		cout << i << " ";
	}
	system("pause");
	return 0;
}