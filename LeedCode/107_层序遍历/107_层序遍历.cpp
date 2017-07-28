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
	int Maxdepth(TreeNode* root) {
		if (!root)return 0;
		int L = Maxdepth(root->left) + 1;
		int R = Maxdepth(root->right) + 1;
		return L > R ? L : R;
	}
	int* calclevelNum(TreeNode* root,int* cs,int depth) {
		if (!root) return;
		cs[depth]++;
		calclevelNum(root->right, cs, depth - 1);
		calclevelNum(root->left, cs, depth - 1);
	}
	void sloveOne(TreeNode* root, vector<vector<int>>& vec, int* counts, int depth) {
		if (root == NULL) return;
		vec[depth][counts[depth]++] = root->val;
		sloveOne(root->left, vec, counts, depth);
		sloveOne(root->right, vec, counts, depth);
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		//vector<vector<int>> vec;
		int depth = Maxdepth(root);
		int *cs = new int[depth];
		int *counts = new int[depth];
		memset(cs, 0, depth * sizeof(int));
		memset(counts, 0, depth * sizeof(int));
		calclevelNum(root, cs, depth - 1);

		vector<vector<int>> vec(depth);
		for (int i = 0; i < depth; i++) {
			vec[i].resize(cs[i]);
		}
		sloveOne(root, vec, counts, depth);
		return vec;
	}
};