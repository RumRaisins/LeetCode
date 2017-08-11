#include <iostream>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		//if (__builtin_expect(!!(root == NULL),0)) return  0;
		//int numR = maxDepth(root ->right) + 1;
		//int numL = maxDepth(root->left) + 1;
		//return numR > numL ? numR:numL;
		//上面更快
		return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;

	}
};