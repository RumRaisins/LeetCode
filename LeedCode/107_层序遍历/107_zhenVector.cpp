#include<iostream>
#include<vector>
using namespace  std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	void calclevel(TreeNode* root, vector<vector<int>>& vec, int depth) {
		if (!root) return;
		if (vec.empty() || depth > vec.size() - 1) {
			vec.push_back(vector<int>());
		}
		vec[depth].push_back(root->val);
		calclevel(root->right, vec, depth + 1);
		calclevel(root->left, vec, depth + 1);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> vec;
		calclevel(root, vec, 0);
		reverse(vec.begin(), vec.end());
		return vec;
	}
};