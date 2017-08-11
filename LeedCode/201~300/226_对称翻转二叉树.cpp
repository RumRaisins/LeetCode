#include <iostream>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		helpInvertTree(root);
	}
	void helpInvertTree(TreeNode* root) {
		if (NULL == root) return;
		helpInvertTree(root->left);
		helpInvertTree(root->right);
		std::swap(root->left, root->right);
	}
};