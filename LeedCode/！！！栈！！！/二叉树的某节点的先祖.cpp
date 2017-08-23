#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR 0
#define OK 1

typedef struct TreeNode{
	char data;
	struct TreeNode *lchild, *rchlid;
}*Tree;

typedef struct Stack {
	Tree *data;
	int top ,size ;
}*pStack;

Tree init_tree(char data) {
	Tree root = (Tree)malloc(sizeof(TreeNode));
	root->data = data;
	root->rchlid = root->lchild = NULL;
	return root;
}
pStack init_stack(int size) {
	pStack p = (pStack)malloc(sizeof(Stack));
	p->data = (TreeNode **)malloc(sizeof(TreeNode *) * size);
	p->size = size;
	p->top = -1;
	return p;
}
int push(pStack p , Tree root) {
	if (p->top + 1 == p->size) {
		return ERROR;
	}
	p->data[++p->top] = root;
	return OK;
}
int empty(pStack stack) {
	return stack->top < 0;
}
int pop(pStack p) {
	if (empty(p)) {
		return ERROR;
	}
	--p->top;
	return OK;
}

Tree top(pStack p) {
	return p->data[p->top];
}



void clear(pStack stack) {
	if (!empty(stack)) {
		for (int i = 0; i <= stack->top; ++i) {
			free(stack->data[i]);
		}
	}
	free(stack);
	return;
}


void clearAndput(pStack p) {
	while (!empty(p)) {
		printf("%c ", top(p)->data);
		pop(p);
	}
	clear(p);
}
Tree buildTree(char* str) {
	Tree p = NULL;
	pStack stack = init_stack(strlen(str));
	int k = 0; //0为左孩子，1为右孩子
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
			k = 1;
			if (NULL != p) {
				pop(stack);
				p = NULL;
			}
			break;
		default:
			p = init_tree(str[0]);
			if (!empty(stack) && k == 1) {
				top(stack)->rchlid = p;
			}
			else if (!empty(stack) && k == 0) {
				top(stack)->lchild = p;
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
void outtest(Tree root) {
	if (!root) return;
	outtest(root->lchild);
	printf("%c ", root->data);
	outtest(root->rchlid);
}
void putTreeAncestors(Tree root, char target) {
	pStack p = init_stack(100);
	if (root->data == target) {
		printf("无祖先节点");
		return;
	}
	Tree temp = root, re = NULL;
	while (!empty(p) || temp != NULL) {
		while (NULL != temp) {
			if (temp->data == target) {
				clearAndput(p);
				return;
			}
			push(p, temp);
			temp = temp->lchild;
		}
		temp = top(p);
		if (temp->rchlid != NULL && temp->rchlid != re) {
			temp = temp->rchlid;
			push(p, temp);
			temp = temp->lchild;
		}
		else {
			temp = top(p);
			pop(p);
			if (temp->data == target) {
				clearAndput(p);
				return;
			}
			re = temp;
			temp = NULL;

		}

	}
}
void inorder(Tree root) {
	pStack p = init_stack(100);
	Tree temp = root;
	while (!empty(p) || temp != NULL) {
		while (NULL != temp) {
			push(p, temp);
			temp = temp->lchild;
		}
		if (!empty(p)) {
			temp = top(p);
			pop(p);
			printf("%c ",temp->data);
			temp = temp->rchlid;
		}
	}
}
void preorder(Tree root) {
	pStack p = init_stack(100);
	Tree temp = root;
	while (!empty(p) || temp) {
		while (temp != NULL) {
			printf("%c", temp->data);
			push(p, temp);
			temp = temp->lchild;
		}
		if (!empty(p)) {
			temp = top(p)->rchlid;
			pop(p);		
		}
	}
}

void postorder(Tree root) {
	pStack p = init_stack(100);
	Tree temp = root;
	while (!empty(p) || NULL != temp) {
		while (NULL != temp) {
			push(p, temp);
			temp = temp->lchild;
		}

	}
}

int main() {
	char *s = "A(B(D(H,I),E(,G)),C(F,G))";
	//scanf("%s", s);
	Tree root = buildTree(s);
	outtest(root);
	printf("\n");
	char temp;
	while (scanf("%c", &temp) != EOF) {
		putTreeAncestors(root, temp);
	}
	//inorder(root);
	//preorder(root);
	system("pause");
	return 0;

}