
#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//p,q������
		int status = (root->val - p->val) * (root->val - q->val);
		//����һ���ڵ��Ǹ��ڵ�
		if (status == 0) {
			if (p->val == root->val) {
				return p;
			}
			else {
				return q;
			}
		}
		else if (status > 0) {
			//�����㶼�������Ҳ�
			if ((root->val - p->val) > 0) {
				return lowestCommonAncestor(root->left, p, q);
			}
			else {
				return lowestCommonAncestor(root->right, p, q);
			}

		}
		else {
			//������ һ����� һ���ұ�
			return root;
		}
	}
};