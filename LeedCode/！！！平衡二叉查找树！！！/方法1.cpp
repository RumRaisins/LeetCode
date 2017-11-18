#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
	int key;
	struct BSTNode *lchild, *rchild, *father;
};

BSTNode *init(int key, BSTNode *father) {
	BSTNode *p = new BSTNode;
	p->lchild = p->rchild = NULL;
	p->father = father;
	p->key = key;
	return p;
}

void clear(BSTNode *node) {
	if (NULL == node) return;
	clear(node->lchild);
	clear(node->rchild);
	delete node;
	return;
}


BSTNode *insert(BSTNode *node, int value) {
	if (NULL == node) return init(value, NULL);
	if (value == node->key)  return node;
	if (value > node->key) {
		if (NULL == node->rchild) {
			node->rchild = init(value, node);
		}
		else 
			node->rchild = insert(node->rchild, value);
	}
	else if (value < node->key) {
		if (NULL == node->lchild) {
			node->lchild = init(value, node);
		}
		else
			node->lchild = insert(node->lchild, value);
	}
	return node;
}
BSTNode *predecessor(BSTNode *node) {
	if (NULL == node->lchild) return NULL;
	BSTNode *temp = node->lchild;
	while (temp->rchild) {
		temp = temp->rchild;
	}
	return temp;
}
BSTNode *delete_node(BSTNode *node, int value) {
	if (NULL == node) return NULL;
	if (value > node->key)
		node->rchild = delete_node(node->rchild, value);
	else if (value < node->key)
		node->lchild = delete_node(node->lchild, value);
	else{
		if (node->lchild == NULL &&node->rchild == NULL) {
			delete node;
			return NULL;
		}
		else if (node->lchild == NULL || node->rchild == NULL) {
			BSTNode *temp = node->lchild ? node->lchild : node->rchild;
			temp->father = node->father;
			delete node;
			return temp;
		}
		else {
			BSTNode *temp = predecessor(node);
			node->key ^= temp->key ^= node->key ^= temp->key;
			node->lchild = delete_node(node->lchild, value);
			return node;
		}
	}
	return node;
}
void inorder(BSTNode *root) {
	if (root == NULL) {
		return;
	}
	inorder(root->lchild);
	printf("%d ", root->key);
	inorder(root->rchild);
	return;
}

int main() {
	int opr, n;
	BSTNode *root = NULL;
	while (scanf("%d%d", &opr, &n) != EOF) {
		switch (opr) {
		case 1:
			root = insert(root, n);
			break;
		case 2:
			root = delete_node(root, n);
			break;
		}
		inorder(root);
		printf("\n");
	}
	return 0;
}