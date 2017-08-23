#include<iostream>
#include <stack>
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
	 typedef struct Node {
		 TreeNode *p, *q;
		 int status;
	 }Node;
	 void init_Node(Node *a, TreeNode *p, TreeNode *q) {
		 a->p = p;
		 a->q = q;
		 a->status = 0;
	 }
	 bool isSymmetric(TreeNode* root) {
		 if (!root) return true;
		 stack<Node> s;
		 Node p;
		 init_Node(&p, root->left, root->right);
		 s.push(p);
		 while (!s.empty()) {
			 Node *temp = &s.top();
			 switch (temp->status) {
				case 0:
					if (temp->p == NULL && temp->q == NULL) {
						s.pop();
					}
					else {
						temp->status = 1;
					}
					break;
				case 1:if ((temp->p == NULL && temp->q != NULL) || (temp->p != NULL && temp->q == NULL) ||(temp->p->val^temp->q->val)) 
							return false;
					   else {
						   temp->status = 2;
					   }

				case 2: {
					Node a, b;
					init_Node(&a, temp->p->left, temp->q->right);
					init_Node(&b, temp->p->right, temp->q->left);
					s.pop();
					s.push(a);
					s.push(b);
				}
			 }	
		 }
		 return true;
	 }
 };

 int main() {




	 return 0;
 }