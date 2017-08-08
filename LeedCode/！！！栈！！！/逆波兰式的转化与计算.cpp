#include <stdlib.h>
#include <stdio.h>

#define ERROR 0
#define OK 1
typedef struct Node {
	int idata;
	char cdata;
	bool state; //true int  false char
};

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
	if (s->top_index >= s->max_size - 1 ) {
		return ERROR;
	}
	s->data[++s->top_index] = c;
	return OK;
}
int pop_stack(pStack s,int& c ) {
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
int col(int number1, int number2, char operator_) {
	switch (operator_) {
	case '+': return number1 + number2;
	case '-': return number1 - number2;
	case '*': return number1 * number2;
	case '/': return number1 / number2;
	}
}

int RPNExpression(char* p,int length) {
	pStack stack_num = (pStack)malloc(sizeof(Stack));
	init_stack(stack_num, length);
	pStack stack_sign = (pStack)malloc(sizeof(Stack));
	init_stack(stack_sign, length);
	char temp;
	Node* node;
	for (int i = 0; i < length; ++i) {
		switch (p[i]) {
		//case '(':
		//case ')':
		case '+':
		case '-':
			while (!empty_stack(stack_sign)){
				push_stack(stack_num, top_stack(stack_sign));
				pop_stack(stack_sign);
			}
			node = init_node(p[i]);
			push_stack(stack_sign,node);
			break;
		case '*':
		case '/':
			if (empty_stack(stack_sign) ||top_stack(stack_sign)->cdata == '+' || 
				top_stack(stack_sign)->cdata == '-') {
				node = init_node(p[i]);
				push_stack(stack_sign, node);
				break;
			}
			while (!empty_stack(stack_sign) &&(top_stack(stack_sign)->cdata != '+' && top_stack(stack_sign)->cdata != '-')) {
				node =top_stack(stack_sign);
				push_stack(stack_num, node);
				pop_stack(stack_sign);
			}
			node = init_node(p[i]);
			push_stack(stack_sign, node);
			break;
		default:
			node = init_node(p[i] - '0');
			push_stack(stack_num, node);
		}
	}
	// Çå¿Õ·ûºÅÕ»
	while (!empty_stack(stack_sign)) {
		push_stack(stack_num, top_stack(stack_sign));
		pop_stack(stack_sign);
	}
	//ÄæÖÃ£¬µÃµ½Äæ²¨À¼Ê½
	while (!empty_stack(stack_num)) {
		push_stack(stack_sign, top_stack(stack_num));
		pop_stack(stack_num);
	}
	/*while (!empty_stack(stack_sign)) {
		if (top_stack(stack_sign)->state) {
			printf("%d", top_stack(stack_sign)->idata);
		}
		else {
			printf("%c", top_stack(stack_sign)->cdata);
		}
		pop_stack(stack_sign);
	}*/
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
			printf("%d\n", a);
			//Node* node = init_node(col(a, b, top_stack(stack_sign)->cdata));
			Node* node = init_node(a);
			push_stack(stack_num, node);
		}
		pop_stack(stack_sign);
	}
	return top_stack(stack_num)->idata;
}


int main() {

	char p[30];
	int index = 0;
	char temp;
	while (scanf("%c", &temp) != EOF) {
		if (temp == '\n') {
			p[index] = '\0';
			break;
		}
		p[index++] = temp;
	}
	printf("%d",RPNExpression(p, index));


	system("pause");
	return 0;
}

