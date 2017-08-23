#include<iostream>
using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		if (p == NULL && q != NULL) return false;
		if (p != NULL && q == NULL) return false;
		if (p->val^q->val) return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
int test(int a) {
	typeof(a) a
}
int main() {
	TreeNode T1(0), T2(0);
	Solution solution;
	cout << solution.isSameTree(&T1, &T2);
	system("pause");
}