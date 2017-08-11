/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int minDepth(TreeNode* root) {
		/*if (__builtin_expect(!!(!root), 0)) return 0;
		if (__builtin_expect(!!(!root->left && !root->right), 0)) return 1;
		int L = minDepth(root->left), R = minDepth(root->right);
		return L < R && L || !R ? 1 + L : 1 + R;*/
		if (!root) return 0;
		if (!root->left) return 1 + minDepth(root->right);
		if (!root->right) return 1 + minDepth(root->left);
		return 1 + min(minDepth(root->left), minDepth(root->right));


	}
};