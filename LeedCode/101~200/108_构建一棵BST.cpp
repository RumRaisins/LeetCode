
#include <iostream>
#include <vector>
using std::vector;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *__helpbuildTree(vector<int>& nums, int begin, int end) {
		if (begin < end) return NULL;
		int half = (end - begin) >> 1;
		TreeNode *root = new TreeNode(nums[half]);
		root->left = __helpbuildTree(nums, 0, half - 1);
		root->right = __helpbuildTree(nums, half + 1, end);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) return NULL;
		int half = nums.size() >> 1;
		TreeNode *root = new TreeNode(nums[half]);
		root->left = __helpbuildTree(nums, 0, half - 1);
		root->right = __helpbuildTree(nums, half + 1, nums.size() - 1);
		return root;
	}
};