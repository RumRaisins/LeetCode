#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
	int* data;
	int top_index, max_size;
} Stack;

void init(Stack* s, int size) {
	s->data = (int*)malloc(sizeof(int) * size);
	s->max_size = size;
	s->top_index = -1;
}

int push(Stack* s, int element) {
	if (s->top_index >= s->max_size - 1)
		return ERROR;
	s->data[++s->top_index] = element;
	return OK;
}

int pop(Stack* s) {
	if (s->top_index < 0)
		return ERROR;
	--s->top_index;
	return OK;
}

int top(Stack* s) {
	return s->data[s->top_index];
}

int empty(Stack* s) {
	return s->top_index < 0;
}

int precede(char a, char b) {
	//传入符号比栈顶符号优先级高 返回 1
	return (a == '*' || a == '/') && (b == '+' || b == '-');

}
int operate(char operator,char a, char b) {
	switch (operator) {
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a*b;
	case '/':return a / b;
	default:printf("ERROR!\n");
	}
}
void calc(Stack* numbers, Stack* operators) {
	int a = top(numbers);
	pop(numbers);
	int b = top(numbers);
	pop(numbers);
	push(numbers, operate(top(operators), b, a));
	pop(operators);
}

void clear(Stack* s) {
	free(s->data);
	free(s);
}

int main() {
	int n;
	scanf("%d", &n);
	char* buffer = (char*)malloc(sizeof(char) * (n + 1));
	Stack *numbers = (Stack*)malloc(sizeof(Stack));
	init(numbers, n);
	Stack *operators = (Stack*)malloc(sizeof(Stack));
	init(operators, n);
	scanf("%s", buffer);
	int i = 0;
	while (i < n) {
		if (isdigit(buffer[i])) {
			push(numbers, buffer[i++] - '0');
		}
		else {
			if (empty(operators) || precede(buffer[i], top(operators))) {
				push(operators, buffer[i++]);
			}
			else {
				calc(numbers, operators);
			}

		}
	}
	while (!empty(operators)) {
		calc(numbers, operators);
	}
	printf("%d", top(numbers));
	clear(numbers);
	clear(operators);
	free(buffer);
	return 0;
}