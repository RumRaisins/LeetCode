#include <iostream>
#include <string.h>
using namespace std;

typedef struct Tree {
	int data;
	struct Tree* rchild, *lchild;
}Tree, *pTree;

pTree init(int data) {
	pTree root = new Tree;
	root->data = data;
	root->lchild = root->rchild = NULL;
	return root;
}
pTree preAndinQpostorder(char* pre_str, char* in_str, int length) {
	pTree root = init(pre_str[0] - '0');
	int pos = strchr(in_str, pre_str[0]) - in_str;
	if (pos > 0) {
		root->lchild = preAndinQpostorder(pre_str + 1, in_str, pos);
	}
	if (length - pos - 1 > 0) {
		root->rchild = preAndinQpostorder(pre_str + pos + 1, in_str + pos + 1, length - pos - 1);
	}
	return root;
}

void postorder(pTree node) {
	if (node->lchild != NULL) {
		postorder(node->lchild);
	}
	if (node->rchild != NULL) {
		postorder(node->rchild);
	}
	printf("%d ", node->data);
}
void clear(pTree root) {
	if (root->lchild)
		clear(root->lchild);
	if (root->rchild)
		clear(root->rchild);
	delete root;
}




int main() {
	char pre_str[] = "136945827";
	char in_str[] = "963548127";
	Tree* root = preAndinQpostorder(pre_str, in_str, strlen(pre_str));
	postorder(root);
	printf("\n");
	clear(root);
	system("pause");
	return 0;
}