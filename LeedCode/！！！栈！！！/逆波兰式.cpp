/*************************************************************************
> File Name: biaodashi.cpp
> Author:
> Mail:
> Created Time: Tue 21 Nov 2017 04:52:28 PM DST
************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;


#define ERROR 0
#define OK 1
typedef struct Node {
	int idata;
	char cdata;
	bool state; //true int  false char
}Node;

typedef struct Stack {
	Node **data;
	int top_index, max_size;
}*pStack;

Node *init_node(char cdata) {
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->state = 0;
	temp->idata = -1;
	temp->cdata = cdata;
	return temp;
}
Node *init_node(int idata) {
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->state = 1;
	temp->idata = idata;
	temp->cdata = '\0';
	return temp;

}
void init_stack(pStack stack, int size) {
	stack->data = (Node**)malloc(sizeof(Node) * size);
	stack->max_size = size;
	stack->top_index = -1;
}
int empty_stack(pStack s) {
	return s->top_index < 0;
}
int push_stack(pStack s, Node* c) {
	if (s->top_index >= s->max_size - 1) {
		return ERROR;
	}
	s->data[++s->top_index] = c;
	return OK;
}
int pop_stack(pStack s, int& c) {
	if (empty_stack(s)) {
		return ERROR;
	}
	c = s->data[s->top_index]->idata;
	--s->top_index;
	return OK;
}

int pop_stack(pStack s) {
	if (empty_stack(s)) {
		return ERROR;
	}
	--s->top_index;
	return OK;
}
Node* top_stack(pStack s) {
	return s->data[s->top_index];
}
void clear(pStack s) {
	while (!empty_stack(s)) {
		Node *node = top_stack(s);
		free(node);
		pop_stack(s);
	}
	free(s->data);
	free(s);
}

int col(int number1, int number2, char operator_) {
	switch (operator_) {
	case '+': return number1 + number2;
	case '-': return number1 - number2;
	case '*': return number1 * number2;
	case '/': return number1 / number2;
	case '^': return pow(number1, number2);
	}
}

int RPNExpression(char* p, int length, int a_num) {
	pStack stack_num = (pStack)malloc(sizeof(Stack));
	init_stack(stack_num, length);
	pStack stack_sign = (pStack)malloc(sizeof(Stack));
	init_stack(stack_sign, length);
	char temp;
	Node* node;
	for (int i = 0; i < length; ++i) {
		switch (p[i]) {
		case '(':
			node = init_node('(');
			push_stack(stack_sign, node);
			break;
		case ')':
			while (!empty_stack(stack_sign) && top_stack(stack_sign)->cdata != '(') {
				node = top_stack(stack_sign);
				push_stack(stack_num, top_stack(stack_sign));
				pop_stack(stack_sign);
			}
			pop_stack(stack_sign);
			break;
		case '^':
			if (empty_stack(stack_sign) || top_stack(stack_sign)->cdata == '+' ||
				top_stack(stack_sign)->cdata == '-' || top_stack(stack_sign)->cdata == '*' ||
				top_stack(stack_sign)->cdata == '/') {
				node = init_node(p[i]);
				push_stack(stack_sign, node);
				break;
			}
			while (!empty_stack(stack_sign) && (top_stack(stack_sign)->cdata != '+' && top_stack(stack_sign)->cdata != '-'&&
				top_stack(stack_sign)->cdata != '*' && top_stack(stack_sign)->cdata != '/') && top_stack(stack_sign)->cdata != '(') {
				node = top_stack(stack_sign);
				push_stack(stack_num, node);
				pop_stack(stack_sign);
			}
			node = init_node(p[i]);
			push_stack(stack_sign, node);
			break;
		case '+':
		case '-':
			while (!empty_stack(stack_sign) && top_stack(stack_sign)->cdata != '(') {
				push_stack(stack_num, top_stack(stack_sign));
				pop_stack(stack_sign);
			}
			node = init_node(p[i]);
			push_stack(stack_sign, node);
			break;
		case '*':
		case '/':
			if (empty_stack(stack_sign) || top_stack(stack_sign)->cdata == '+' ||
				top_stack(stack_sign)->cdata == '-' || top_stack(stack_sign)->cdata == '(') {
				node = init_node(p[i]);
				push_stack(stack_sign, node);
				break;
			}
			while (!empty_stack(stack_sign) && (top_stack(stack_sign)->cdata != '+' && top_stack(stack_sign)->cdata != '-'&&
				top_stack(stack_sign)->cdata != '(')) {
				node = top_stack(stack_sign);
				push_stack(stack_num, node);
				pop_stack(stack_sign);
			}
			node = init_node(p[i]);
			push_stack(stack_sign, node);
			break;
		case ' ':break;
		case 'a':
			node = init_node(a_num);
			push_stack(stack_num, node);
			break;
		default:
			int n = p[i] - '0';
			while (i < length && isdigit(p[i + 1])) {
				n = n * 10 + p[++i] - '0';
			}
			node = init_node(n);
			push_stack(stack_num, node);
		}
	}
	while (!empty_stack(stack_sign)) {
		push_stack(stack_num, top_stack(stack_sign));
		pop_stack(stack_sign);
	}
	while (!empty_stack(stack_num)) {
		push_stack(stack_sign, top_stack(stack_num));
		pop_stack(stack_num);
	}
	int a, b;
	while (!empty_stack(stack_sign)) {
		if (top_stack(stack_sign)->state) {
			push_stack(stack_num, top_stack(stack_sign));
		}
		else {
			int a, b;
			pop_stack(stack_num, a);
			pop_stack(stack_num, b);
			a = col(b, a, top_stack(stack_sign)->cdata);
			//Node* node = init_node(col(a, b, top_stack(stack_sign)->cdata));
			Node* node = init_node(a);
			push_stack(stack_num, node);
		}
		pop_stack(stack_sign);
	}
	a = top_stack(stack_num)->idata;
	clear(stack_sign);
	clear(stack_num);
	return a;

}



int main() {


	char str[100];
	char AA[26][100];
	int n;
	scanf("%[^\n]s", str);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		getchar();
		scanf("%[^\n]s", AA[i]);
	}
	int flag = 1;
	for (int i = 0; i < n; ++i) {
		flag = 1;
		for (int j = 0; j < 5; ++j) {
			if (RPNExpression(str, strlen(str), j) != RPNExpression(AA[i], strlen(AA[i]), j)) {
				flag = 0;
			}
		}
		if (flag) {
			printf("%c", 'A' + i);
		}
	}
	printf("\n");
	return 0;
}