
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
	/*bool isBalanced(TreeNode* root) {
		bool yes = true;
		help(root, yes);
		return yes;
	}*/
	/*int help(TreeNode* root, bool& yes) {
		if (!root || !yes) return 0;
		int lnum, rnum;
		lnum = help(root->right, yes);
		rnum = help(root->left, yes);
		if (abs(lnum - rnum) > 1) {
			yes = false;
		}
		return max(lnum, rnum) + 1;
	}*/
	typedef struct Node {
		TreeNode *root;
		int depth;
		int status;
	}Node;
	void init(Node *a, TreeNode *root, int depth) {
		a->root = root;
		a->depth = depth;
		a->status = 0;
	}
	bool isBalanced(TreeNode *root) {
		bool yes = true;
		stack<Node> stack;
		Node p;
		init(&p, root, 0);
		stack.push(p);
		int depth = 0;
		while (!stack.empty()) {
			Node *temp = &stack.top();
			switch (temp->status)
			{
			case 0: 
				if (!yes && !root) {
					temp->status = 3;
				}
				else {
					++temp->depth;
					temp->status = 1;
				}break;
			case 1: {
				Node a;
				init(&a,temp->root->left, temp->depth + 1);
				stack.push(a);
				temp->status = 2;
			}break;
			case 2: {
				Node a;
				init(&a, temp->root->right, temp->depth + 1);
				stack.push(a);
				temp->status = 3;
			}break;
			case 3:
				if (abs(depth - temp->depth) > 1) {
					return false;
				}
				depth = temp->depth;
				stack.pop();
			}
		}
		return true;

	}

};