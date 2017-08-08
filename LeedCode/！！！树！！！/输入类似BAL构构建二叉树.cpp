#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tree {
	char data;
	struct  Tree* lchild, *rchild;
}*pTree;

typedef struct Queue {
	pTree *data;
	int head, tail, size;
}*pQueue;

pQueue init_queue(int size) {
	pQueue queue = new Queue;
	queue->data = new pTree[size];
	queue->size = size;
	queue->head = 0;
	queue->tail = -1;
	return queue;
}

pTree init_Tree(char data) {
	pTree root = new Tree;
	root->data = data;
	root->lchild = root->rchild = NULL;
	return root;
}

void push_queue(pQueue queue, pTree node) {
	queue->data[++queue->tail] = node;
}

void pop_queue(pQueue queue) {
	++queue->head;
}

bool empty_queue(pQueue queue) {
	return queue->head > queue->tail;
}

pTree top_queue(pQueue queue) {
	return queue->data[queue->head];
}
void clearTree(pTree root) {
	if (root->lchild) {
		clearTree(root->lchild);
	}
	if (root->rchild) {
		clearTree(root->rchild);
	}
	free(root);
}
void Sequencetable(pTree root) {
	if (!root) {
		return;
	}
	printf("%c", root->data);
	if (root->lchild == NULL  && root->rchild == NULL ) {
		return;
	}
	printf("(");
	if (root->lchild ) {
		Sequencetable(root->lchild);
	}
	if (root->rchild ) {
		printf(",");
		Sequencetable(root->rchild);
	}
	printf(")");
	return;
}

int main() {
	char p[3];
	scanf("%s", p);
	if ('^' == p[0] && '^' == p[1]) {
		return 0;
	}
	pTree root = init_Tree(p[1]);
	pQueue queue = init_queue(100);
	push_queue(queue, root);
	while (scanf("%s",p) != EOF ) {
		if ('^' == p[0] && '^' == p[1]) {
			break;
		}
		pTree temp = top_queue(queue);
		//输入为当前节点的孩子
		if (p[0] == temp->data) {
			if ('L' == p[2]) {
				temp->lchild = init_Tree(p[1]);
				push_queue(queue,temp->lchild);
			}
			else if('R' == p[2]) {
				temp->rchild = init_Tree(p[1]);
				push_queue(queue, temp->rchild);
			}
		}
		//输入的已经不是孩子了
		else {
			while (p[0] != top_queue(queue)->data) {
				pop_queue(queue);
			}
			temp = top_queue(queue);
			if ('L' == p[2]) {
				temp->lchild = init_Tree(p[1]);
				push_queue(queue, temp->lchild);
			}
			else if ('R' == p[2]) {
				temp->rchild = init_Tree(p[1]);
				push_queue(queue, temp->rchild);
			}
		}
	}
	free(queue->data);
	free(queue);
	Sequencetable(root);
	clearTree(root);

	system("pause");
	return 0;
}


