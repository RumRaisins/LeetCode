#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root) return;
		string s;
		vector<string> result;
		s = intTostr(root->val);
		if (NULL != root->left) {
			help(root->left, result, s);

		}
		if (NULL != root->right) {
			help(root->right, result, s);
		}
		return result;

	}
	void help(TreeNode* root,vector<string>& vec, string path) {
		if (!root->left && !root->right) {
			vec.push_back(path = path + "->" + intTostr(root->val));
			return;
		}
		if (NULL != root->left) {
			help(root->left, vec, path);

		}
		if (NULL != root->right) {
			help(root->right, vec, path);
		}

	}
	string intTostr(int n) {
		char temp ;
		string result;
		while (n) {
			temp = n % 10 + '0';
			result = temp + result;
			n /= 10;
		}
		return result;
	}
};

int main() {
	Solution sol;
	int n = 10234;
	cout << sol.intTostr(n);

	system("pause");
	return 0;
}