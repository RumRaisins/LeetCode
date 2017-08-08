#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
} Node;

Node* init(int data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}
Node* build(char pre_str[], char in_str[], int len) {
	Node* p = init(pre_str[0] - '0');
	int pos = strchr(in_str, pre_str[0]) - in_str;
	if (pos > 0) {
		p->lchild = build(pre_str + 1, in_str, pos);
	}
	if (len - pos - 1  > 0) {
		p->rchild = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
	}
	return p;
}