#include <iostream>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//********** MY Code ****/
	void __help(TreeNode* root, int k, int& num, int& ans) {
		if (root->left) {
			__help(root->left, k, num, ans);
		}
		if (++num > k) return;
		if (num == k) ans = root->val;

		if (root->right) {
			__help(root->right, k, num, ans);
		}
		return;

	}
	int kthSmallest(TreeNode* root, int k) {
		if (root == nullptr) return 0;
		int ans = 0, num = 0;
		__help(root, k, num, ans);
		return ans;
	}
};