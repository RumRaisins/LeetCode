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
	 bool twoNodeSame(TreeNode* p, TreeNode* q) {
		 if (p == NULL && q == NULL) return true;
		 if (p == NULL && q != NULL) return false;
		 if (p != NULL && q == NULL) return false;
		 if (p->val^q->val) return false;
		 return twoNodeSame(p->left,q->right) && twoNodeSame(p->left,q->right);
	 }

	
		 bool isSameTree(TreeNode* p, TreeNode* q) {
			 if ((!p && p) || (p && !q) || (!p && !q)) return false;
			 return twoNodeSame(p->right, q->right) && (p->left, q->left));
		 }
	 
 };

 int main() {




	 return 0;
 }