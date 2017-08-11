#include<iostream>
#include<string>
#include <sstream>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*pTree;


class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (!root->left && !root->right && sum == root->val) {
			return true;
		}
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};