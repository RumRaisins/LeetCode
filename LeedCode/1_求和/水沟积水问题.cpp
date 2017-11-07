#include <vector>

using namespace std;



class Solution {
public:
	int trap(vector<int>& height) {
		int l = 0, r = height.size() - 1, ret = 0, tempheight = 0;

		while (l < r) {
			tempheight = min(height[l], height[r]);
			if (tempheight == height[l]) {
				while (l < r && height[l] <= tempheight) {
					ret += tempheight - height[l];
					l++;
				}
			}
			else {
				while (l < r && height[r] <= tempheight) {
					ret += tempheight - height[r];
					r--;
				}

			}
		}
		return ret;

	}
};