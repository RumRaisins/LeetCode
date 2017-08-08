#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Tree {
	char data;
	struct Tree *rchild, *lchild;
}*pTree;
typedef struct Queue {
	pTree* data;
	int head, tail;
	int length;
}*pQueue;
void init_queue(pQueue q, int length) {
	q->data = (pTree*)malloc(sizeof(pTree) * length);
	q->length = length;
	q->head = 0;
	q->tail = -1;
}
int empty_queue(pQueue q) {
	return q->tail < 0;
}
int push_queue(pQueue q, pTree tree) {
	if (q->tail >= q->length - 1) {
		return 0;
	}
	q->data[++q->tail] = tree;
	return 1;
}
int pop_queue(pQueue q) {
	if (empty_queue(q))
		return 0;
	++q->head;
	return 1;
}
pTree front_queue(pQueue q) {
	return q->data[q->head];
}

void init_tree(pTree root,char p) {
	root->data = p;
	root->lchild = root->rchild = NULL;
}
void clear(pQueue q) {
	free(q->data);
	free(q);
}
pTree build_Tree(char* p) {
	pQueue q = (pQueue)malloc(sizeof(Queue));
	init_queue(q ,strlen(p) + 1);
	pTree root = (pTree)malloc(sizeof(Tree));
	int index = 0;
	init_tree(root, p[index++]);
	push_queue(q, root);
	while (p[index] != '$') {
		pTree temp = front_queue(q);
		if (p[index] == '$') {
			pop_queue(q);
			break;
		}
		temp->lchild = (pTree)malloc(sizeof(Tree));
		init_tree(temp->lchild, p[index++]);
		push_queue(q,temp->lchild);
		if (p[index] == '$') {
			pop_queue(q);
			break;
		}
		temp->rchild = (pTree)malloc(sizeof(Tree));
		init_tree(temp->rchild, p[index++]);
		push_queue(q, temp->rchild);
		pop_queue(q);

	}
	clear(q);
	return root;
}
void Sequencetable(pTree root) {
	if (NULL == root) {
		return;
	}
	printf("%c", root->data);
	if (NULL == root->lchild &&NULL == root->rchild) {
		return;
	}
	printf("(");
	if (root->lchild) {
		Sequencetable(root->lchild);
	}
	if (root->rchild) {
		printf(",");
		Sequencetable(root->rchild);
	}
	printf(")");
}

int main() {
	char p[100];
	char temp;
	int index = 0;
	while (scanf("%c", &temp) != EOF) {
		if (temp == '$') {
			p[index++] = '$';
			break;
		}
		if (temp == ' ') {
			continue;
		}
		if (temp == '\n') {
			break;
		}
		p[index++] = temp;
	}
	pTree root = build_Tree(p);
	Sequencetable(root);
	system("pause");
	return 0;
}