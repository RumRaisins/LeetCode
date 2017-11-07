#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


int binary_search(const vector<int> &nums, int target) {
	int head, tail, mid;
	head = 0, tail = nums.size() - 1;
	while (head < tail) {
		mid = (head + tail) / 2;
		if (nums[mid]  < target) {
			tail = mid;
		}
		else {
			head = mid + 1;
		}
	}
	return head;
}


int lengthOfLNIS(vector<int> &nums) {
	vector<int> len(nums.size() + 1, INT_MIN);
	len[0] = INT_MAX;
	int max_ = 0;
	for (int i = 0; i < nums.size(); ++i) {
		int index = binary_search(len, nums[i]);
		len[index] = nums[i];
		if (index > max_) max_ = index;
	}

	return max_;

}
int main() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		int d;
		cin >> d;
		a.push_back(d);
	}
	cout << lengthOfLNIS(a) << endl;
	return 0;
}