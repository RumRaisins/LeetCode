#include <iostream>
#include <stack>
using std::stack;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//int maxDepth(TreeNode* root) {
	//	//if (__builtin_expect(!!(root == NULL),0)) return  0;
	//	//int numR = maxDepth(root ->right) + 1;
	//	//int numL = maxDepth(root->left) + 1;
	//	//return numR > numL ? numR:numL;
	//	//上面更快
	//	return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;

	//}
	typedef struct Node {
		TreeNode *root;
		int status;
		int max_depth;
	}Node;
	void init_node(Node *a, TreeNode *root , int depth) {
		a->root = root;
		a->status = 0;
		a->max_depth = depth;
	}
	int maxDepth(TreeNode* root) {
		stack<Node> stack;
		Node p;
		init_node(&p, root , 0);
		stack.push(p);
		int max_depth = 0, temp_depth = 0;
		while (!stack.empty()) {
			Node *temp = &stack.top();
			switch (temp->status) {
			case 0: if (!root)
						temp->status = 2;
					else {
						temp->status = 1;
						++temp->max_depth;
					}
				break;
			case 1: {
				Node a , b;
				init_node(&a, temp->root->left ,temp->max_depth);
				init_node(&b, temp->root->right ,temp->max_depth);
				stack.push(a);
				temp->status = 2;
			}
			case 2:
				if (max_depth < temp->max_depth) {
					max_depth = temp->max_depth;
				}
				stack.pop();
			}
		}
	}

};