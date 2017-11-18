#include <stdio.h>
#include <stdlib.h>

#define max(a , b) ((a) > (b) ? (a) : (b))

typedef struct AVLNode {
	int key, height;
	struct AVLNode *lchild, *rchild;
}AVLNode;


AVLNode *init(int key) {
	AVLNode *p = (AVLNode *)malloc(sizeof(AVLNode));
	p->key = key;
	p->height = 1;
	p->lchild = p->rchild = NULL;
	return p;
}

void clear(AVLNode *node) {
	if (NULL == node) return;
	clear(node->lchild);
	clear(node->rchild);
	free(node);
}

int  tree_height(AVLNode *node) {
	if (node == NULL) return 0;
	return node->height;
}
AVLNode *right_rotate(AVLNode *node) {
	AVLNode *temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;
	node->height = max(tree_height(node->lchild), tree_height(node->rchild)) + 1;
	temp->height = max(tree_height(temp->lchild), tree_height(temp->rchild)) + 1;
	return temp;
}
AVLNode *left_rotate(AVLNode *node) {
	AVLNode *temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	node->height = max(tree_height(node->lchild), tree_height(node->rchild)) + 1;
	temp->height = max(tree_height(temp->lchild), tree_height(temp->rchild)) + 1;
	return temp;
}

AVLNode *maintain(AVLNode *node , bool flag){
	node->height = max(tree_height(node->lchild), tree_height(node->rchild)) + 1;
	//×ó×ÓÊ÷²åÈëÊ§ºâ
	if (flag) {
		if (tree_height(node->lchild) < tree_height(node->rchild)) {
			node->lchild = left_rotate(node->lchild);
		node = right_rotate(node);
		}
	}
	else {
		if (tree_height(node->rchild) < tree_height(node->lchild)) {
			node->rchild = right_rotate(node->rchild);
		}
		node = left_rotate(node);
	}
}

AVLNode *insert(AVLNode *node, int key) {
	if (NULL == node) return init(key);
	else if( key == node->key) {
		return node;
	}
	else if (key > node->key) {
		node->lchild = insert(node->lchild ,key );
	}
	else {
		node->rchild = insert(node->rchild, key);
	}
	if (abs(tree_height(node->lchild) - tree_height(node->rchild)) <= 1) {
		node->height = max(tree_height(node->lchild), tree_height(node->rchild)) + 1;
		return node;
	}
	else {
		return node = maintain(node , key < node->key);
	}

}
AVLNode *predecessor(AVLNode *node) {
	AVLNode *temp = node->lchild;
	while (temp->rchild) {
		temp = temp->rchild;
	}
	return temp;
}
AVLNode *delete_node(AVLNode *node, int key) {
	if (node == NULL) return NULL;
	if (node->key < key) {
		node->rchild = delete_node(node->rchild, key);
		node = maintain(node, 1);
	}
	else if (node->key > key) {
		node->lchild = delete_node(node->lchild , key);
		node = maintain(node, 0);
	}
	else {
		if (NULL == node->lchild && NULL == node->rchild) {
			free(node);
			return NULL;
		}
		else if (NULL == node->lchild || NULL == node->rchild) {
			AVLNode *temp = node->lchild ? node->lchild : node->rchild;
			free(node);
			return temp;
		}
		else {
			AVLNode *temp = predecessor(node);
			temp->key ^= node->key ^= temp->key ^= node->key;
			node->lchild = delete_node(node->lchild, key);
			node = maintain(node, 0);
		}
	}
	return node;
}

void inorder(AVLNode *root) {
	if (root == NULL) return;
}

int main() {
	int opr , n;
	AVLNode *root = NULL;
	while (scanf("%d%d",&opr, &n) != EOF) {
		switch (opr) {
		case 1:
			root = insert(root, n);
			break;
		case 2:
			root = delete_node(root, n);
		}
	}
	system("pasue");
	return 0;
}