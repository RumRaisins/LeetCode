#include <iostream>

#include <stdio.h>
#define ERROR 1
#define OK 0
#define log printf("%d\n",__LINE__)


typedef struct Tree {
	char data;
	struct Tree* rchild, *lchild;
}Tree, *pTree;

typedef struct Stack {
	pTree *data;
	int top_index, max_size;
} Stack, *pStack;

void init_stack(pStack s, char size) {
	s->data = (pTree*)malloc(sizeof(Tree) * size);
	s->max_size = size;
	s->top_index = -1;
}

int push(pStack s, pTree element) {
	if (s->top_index >= s->max_size - 1)
		return ERROR;
	s->data[++s->top_index] = element;
	return OK;
}

int pop(pStack s) {
	if (s->top_index < 0)
		return ERROR;
	--s->top_index;
	return OK;
}

pTree top(pStack s) {
	return s->data[s->top_index];
}

int empty(pStack s) {
	return s->top_index < 0;
}


pTree init(char data) {
	pTree root = new Tree;
	root->data = data;
	root->lchild = root->rchild = NULL;
	return root;
}

pTree buildTree(char* str) {
	int len = strlen(str);
	pStack stack = (pStack)malloc(sizeof(Stack));
	init_stack(stack, len);
	pTree p, last_p;
	p = init(str[0]);
	last_p = p;
	int rchild_flag = 0;
	++str;
	while (str[0]) {
		switch (str[0]) {
		case '(':
			push(stack, p);
			p = NULL;
			break;
		case ')':
			top(stack)->rchild = p;
			p = top(stack);
			last_p = p;
			pop(stack);
			break;
		case ',':
			top(stack)->lchild = p;
			p = NULL;
			break;
		default:
			p = init(str[0]);
			break;
		}
		++str;
	}
	if (!empty(stack)) {
		last_p = top(stack);
	}
	free(stack->data);
	free(stack);
	return last_p;
}

void Sequencetable(pTree root,char target) {
	if (root->data == target || !root) {
		return;
	}
	if (root->data == 0) {
		return;
	}
	printf("%c", root->data);
	if ((root->lchild == NULL || root->lchild->data == target) &&
		(root->rchild == NULL || root ->rchild->data == target)) {
		return;
	}
	printf("(");
	if (root->lchild && root->lchild->data != target) {
		Sequencetable(root->lchild, target);
	}
	if (root->rchild && root->rchild->data != target) {
		printf(",");
		Sequencetable(root->rchild, target);
	}
	printf(")");
	return;
}


void clear(pTree root) {
	if (root->lchild)
		clear(root->lchild);
	if (root->rchild)
		clear(root->rchild);
	delete root;
}




int main() {
	char p[30],target,temp;
	int index = 0;
	p[0] = '\0';
	while (scanf("%c", &temp)) {
		if (temp == '\n')break;
		p[index++] = temp;
	}
	scanf("%c", &target); 
	pTree root = buildTree(p);
	Sequencetable(root, target);
	


	clear(root);


	system("pause");
	return 0;
}