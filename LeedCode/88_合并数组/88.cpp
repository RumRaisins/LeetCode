#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void mergeFail(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) return;
		if (m == 0 && n == 0) return;
		if (m == 0 && n != 0)m = 1;
		if (nums1[m - 1] > nums2[n - 1]) {
			nums1[m + n - 1] = nums1[m - 1];
			nums1[m - 1] = 0;
			merge(nums1, m - 1, nums2, n);
		}
		else {
			nums1[m + n - 1] = nums2[n - 1];
			if (m != 0)nums2[n - 1] = 0;
			merge(nums1, m, nums2, n - 1);
		}
		//Ê§°Ü£¡
	}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int lastm = m - 1, lastn = n - 1, tar = m + n -1;
		while (lastn >= 0 ) {
			nums1[tar--] = m >= 0 && nums1[lastm] > nums2[lastn] ? nums1[lastm--] : nums2[lastn--];
		}
	}
};