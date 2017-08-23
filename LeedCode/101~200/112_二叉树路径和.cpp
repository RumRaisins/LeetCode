#include<iostream>
#include<string>
#include <sstream>
#include <stack>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*pTree;


class Solution {
public:
	//bool hasPathSum(TreeNode* root, int sum) {
	//	if (!root) return false;
	//	if (!root->left && !root->right && sum == root->val) {
	//		return true;
	//	}
	//	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	//}
	typedef struct Node {
		TreeNode *root;
		int sum;
		int status;
	}Node;
	void init(Node *p, TreeNode *root, int sum) {
		p->root = root;
		p->sum = sum;
		p->status = 0;
	}
	bool hasPathSum(TreeNode* root, int sum) {
		stack<Node> stack;
		Node p;
		init(&p, root, sum);
		stack.push(p);
		while (!stack.empty()) {
			Node *temp = &stack.top();
			switch (temp->status) {
			case 0:
				if (!temp->root)stack.pop();
				else temp->status = 1;
				break;
			case 1:if (!temp->root->left && !temp->root->right && sum == temp->root->val) {
				return true;
			}
				   else {
					   temp->status = 2;
				   }break;
			case 2: {
				Node a, b;
				init(&a, temp->root->left, sum - temp->root->val);
				init(&b, temp->root->right, sum - temp->root->val);
				stack.pop();
				stack.push(a);
				stack.push(b);
			}break;
			}
		}
		return false;
	}
	bool hasPathSum(TreeNode* root, int sum) {
		stack<Node> stack;
		Node p;
		init(&p, root, sum);
		stack.push(p);
		while (!stack.empty()) {
			Node *temp = &stack.top();
			switch (temp->status) {
			case 0:
				if (!temp->root)stack.pop();
				else temp->status = 1;
				break;
			case 1:if (!temp->root->left && !temp->root->right && sum == temp->root->val) {
				return true;
			}
				   else {
					   temp->status = 2;
				   }break;
			case 2: {
				Node *a, *b;
				sum -= temp->root->val;
				init(a, temp->root->left, sum);
				init(b, temp->root->right, sum);
				stack.pop();
				stack.push(*a);
				stack.push(*b);
			}break;
			case 3: {

			}
			}
		}
		return false;
	}



};