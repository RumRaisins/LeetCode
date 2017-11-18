#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tree {
	char data;
	struct  Tree* lchild, *rchild;
}*pTree;
typedef struct Stack {
	pTree *data;
	int top_index, max_size;
}*pStack;
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
pStack init_stack(int size) {
	pStack stack = new Stack;
	if (stack == NULL) printf("is NULL");
	stack->data = new pTree[size];
	stack->max_size = size;
	stack->top_index = -1;
	return stack;
}
pTree init_Tree(char data) {
	pTree root = new Tree;
	root->data = data;
	root->lchild = root->rchild = NULL;
	return root;
}
void push_stack(pStack stack,pTree node) {
	stack->data[++stack->top_index] = node;
}
void push_queue(pQueue queue, pTree node) {
	queue->data[++queue->tail] = node;
}
void  pop_stack(pStack stack) {
	--stack->top_index;
}
void pop_queue(pQueue queue) {
	++queue->head;
}
bool empty_stack(pStack stack) {
	return stack->top_index < 0;
}
bool empty_queue(pQueue queue) {
	return queue->head > queue->tail;
}
pTree top_stack(pStack stack) {
	if (empty_stack(stack))return NULL;
	return stack->data[stack->top_index];
}
pTree top_queue(pQueue queue) {
	return queue->data[queue->head];
}


pTree build_Tree(char* str) {
	int ln = strlen(str);
	pStack stack = init_stack(ln);
	pTree p, last_p;
	p = init_Tree(str[0]);
	last_p = p;
	int rchild_flag = 0;
	++str;
	while (str[0]) {
		switch (str[0]) {
		case '(':
			push_stack(stack, p);
			p = NULL;
			break;
		case ')':
			top_stack(stack)->rchild = p;
			p = top_stack(stack);
			last_p = p;
			pop_stack(stack);
			break;
		case ',':
			top_stack(stack)->lchild = p;
			p = NULL;
			break;
		default:
			p = init_Tree(str[0]);
			break;
		}
		++str;
	}
	if (!empty_stack(stack)) {
		last_p = top_stack(stack);
	}
	free(stack->data);
	free(stack);
	return last_p;
}
void Hierarchytraversal(pTree root,int n) {
	pQueue queue = init_queue(n);
	push_queue(queue, root);
	bool first = true;
	while (!empty_queue(queue)) {
		pTree temp = top_queue(queue);
		if (first) {
			printf("%c", temp->data);
			first = false;
		}
		else {
			printf(" %c", temp->data);
		}
		if (temp->lchild) {
			push_queue(queue,temp->lchild);
		}
		if (temp->rchild) {
			push_queue(queue, temp->rchild);
		}
		pop_queue(queue);
	}

	free(queue->data);
	free(queue);
}


int main() {
	char *p = new char[10];
	scanf("%s", p);
	int l = strlen(p);
	pTree root;
	root = build_Tree(p);
	Hierarchytraversal(root, l);

	system("pause");
	return 0;
}