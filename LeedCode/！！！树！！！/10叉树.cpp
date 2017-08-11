#include <iostream>

#include <stdio.h>
#define ERROR 1
#define OK 0
#define log printf("%d\n",__LINE__)


typedef struct Tree {
	char data;
	struct Tree **child;
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
	pTree root = (pTree)malloc(sizeof(Tree));
	root->data = data;
	root->child = (pTree*)malloc(sizeof(pTree) * 10);
	for (int i = 0; i < 10; ++i) {
		root->child[i] = NULL;
	}
	return root;
}

pTree buildTree(char* str) {
	pTree p = NULL;
	Stack *stack =(pStack)malloc(sizeof(Stack));
	init_stack(stack, strlen(str));
	int k = 0; 
	while (str[0]) {
		switch (str[0])
		{
		case '(':
			k = 0;
			p = NULL;
			break;

		case ')':
			if (NULL != p) {
				pop(stack);
			}
			break;
		case ',':
			k++;
			if (NULL != p) {
				pop(stack);
				p = NULL;
			}
			break;
		default:
			p = init(str[0]);
			if (!empty(stack) ) {
				top(stack)->child[k] = p;
			}
			push(stack, p);
			break;
		}
		++str;
	}
	if (!empty(stack)) {
		p = top(stack);
	}
	return p;
}

void Sequencetable(pTree root) {
	if (!root) {
		return;
	}
	printf("%c", root->data);
	//if (root->child == NULL ) {
	//	return;
	//}
	printf("(");
	if (NULL != root->child[0]) {
		Sequencetable(root->child[0]);
	}
	for (int i = 1; i < 10; ++i) {
		if (NULL != root->child[i]) {
			printf(",");
			Sequencetable(root->child[i]);
		}
	}
	printf(")");
	return;
}


void clear(pTree root) {
	if (!root) return;
	for (int i = 0; i < 10; ++i) {
		if (&root->child[i]) {
			clear(root->child[i]);
		}
	}
	delete root;
}




int main() {
	char p[30], target, temp;
	int index = 0;
	p[0] = '\0';
	while (scanf("%c", &temp)) {
		if (temp == '\n')break;
		p[index++] = temp;
	}
	p[index] = '\0';
	pTree root = buildTree(p);
	Sequencetable(root);
	clear(root);
	system("pause");
	return 0;
}