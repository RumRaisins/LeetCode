
#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//p,q在两侧
		int status = (root->val - p->val) * (root->val - q->val);
		//其中一个节点是父节点
		if (status == 0) {
			if (p->val == root->val) {
				return p;
			}
			else {
				return q;
			}
		}
		else if (status > 0) {
			//两个点都在左侧或右侧
			if ((root->val - p->val) > 0) {
				return lowestCommonAncestor(root->left, p, q);
			}
			else {
				return lowestCommonAncestor(root->right, p, q);
			}

		}
		else {
			//两个点 一个左边 一个右边
			return root;
		}
	}
};