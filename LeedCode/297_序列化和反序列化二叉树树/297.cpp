#include<iostream>
#include<string>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == nullptr) return "#";
		return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);

	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		return Mydesetialize(data);
	}
	TreeNode* Mydesetialize(string& data) {
		if (data[0] == '#') {
			if (data.size() > 1)data = data.substr(2);
			return nullptr;
		}
		else {
			TreeNode* root = new TreeNode(findcomma(data));
			root->left = Mydesetialize(data);
			root->right = Mydesetialize(data);
			return root;
		}
	}
private:
	int findcomma(string& data) {
		int pos = data.find(',');
		int val = stoi(data.substr(0, pos));
		data = data.substr(pos+1);
		return val;
	}
};

