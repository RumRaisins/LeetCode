
#include <iostream>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		bool yes = true;
		help(root, yes);
		return yes;
	}
	int help(TreeNode* root, bool& yes) {
		if (!root || !yes) return 0;
		int lnum, rnum;
		lnum = help(root->right, yes);
		rnum = help(root->left, yes);
		if (abs(lnum - rnum) > 1) {
			yes = false;
		}
		return max(lnum, rnum) + 1;
	}
};