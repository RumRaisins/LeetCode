#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef struct {
	char **arr;
	int top, max_len;
} Stack;

int initStack(Stack *);
int pushStack(Stack *, char *);
char *popStack(Stack *);
int emptyStack(Stack *);
int destroyStack(Stack *);

Stack back_stack;
Stack forward_stack;
char nowUrl[1000];
char ignore[7] = "Ignore";

void initData() {
	fflush(stdout);
	static int flag = 1;
	if (flag) {
		initStack(&back_stack);
		initStack(&forward_stack);
		nowUrl[0] = '\0';
		flag = 0;
	}
}

char* visitPage(char *url) {
	initData();
	while (!emptyStack(&forward_stack)) {
		free(popStack(&forward_stack));
	}
	if (nowUrl[0] != '\0') {
		pushStack(&back_stack, nowUrl);
	}
	strcpy(nowUrl, url);
	return url;
}
char* back() {
	initData();
	char *temp = popStack(&back_stack);
	if (temp != NULL) {
		pushStack(&forward_stack, nowUrl);
		strcpy(nowUrl, temp);
	}
	else {
		temp = ignore;
	}
	return temp;
}

char* forward() {
	initData();
	char *temp = popStack(&forward_stack);
	if (temp != NULL) {
		pushStack(&back_stack, nowUrl);
		strcpy(nowUrl, temp);
	}
	else {
		temp = ignore;
	}
	return temp;
}

int initStack(Stack *s) {
	s->arr = (char **)malloc(1 * sizeof(char *));
	s->max_len = 1;
	s->top = 0;
	return 1;
}

int pushStack(Stack *s, char *a) {
	if (s->arr == NULL) return 0;
	if (s->top == s->max_len) {
		s->arr = (char **)realloc(s->arr, s->max_len * 2 * sizeof(char *));
		if (s->arr == NULL) return 0;
		s->max_len *= 2;
	}
	char *temp = (char *)malloc(strlen(a) + 1);
	strcpy(temp, a);
	s->arr[s->top++] = temp;
	return 1;
}

char *popStack(Stack *s) {
	if (!emptyStack(s)) {
		--(s->top);
		return s->arr[s->top];
	}
	return NULL;
}

int emptyStack(Stack *s) {
	return !(s->top);
}