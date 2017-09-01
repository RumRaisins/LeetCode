#include <stdio.h>
#include <stdlib.h>
#include <string>


#define CL(a , b) (a *)calloc(b , sizeof(a))

typedef struct Stack {
	int *data;
	int top, max_size;
}Stack;
typedef struct TwoStack {
	Stack *data;
	Stack *min;
};

TwoStack *init(int length) {
	TwoStack *p = (TwoStack *)malloc(sizeof(TwoStack));
	p->data = CL(Stack, 1);
	p->data->data = CL(int, length);
	p->data->top = -1;
	p->data->max_size = length;
	p->min = CL(Stack, 1);
	p->min->data = CL(int, length);
	p->min->top = -1;
	p->min->max_size = length;
	return p;
}
int emptyMin(TwoStack *s) {
	return s->min->top < 0;
}
int emptydata(TwoStack *s) {
	return s->data->top < 0;
}
int getMin(TwoStack *s) {
	return s->min->data[s->min->top];
}
int gettop(TwoStack *s) {
	return s->data->data[s->data->top];
}
int push(TwoStack *s, int n) {
	if (s->data->top + 1 == s->data->max_size) {
		return -1;
	}
	s->data->data[++(s->data->top)] = n;
	if (emptyMin(s) || n <= getMin(s)) {
		s->min->data[++(s->min->top)] = n;
	}
	return 1;
}
int pop(TwoStack *s) {
	if (emptydata(s)) {
		return -1;
	}
	if (gettop(s) == getMin(s)) {
		--s->min->top;
	}
	--s->data->top;
}




int* stackMinimumValues(char **operation, int *value, int length) {
	int *ans = (int *)malloc(sizeof(int) * length);
	int index = 0;
	TwoStack *s = init(length);
	for (int i = 0; i < length; ++i) {
		if (strcmp(operation[i], "push") == 0) {
			push(s, value[i]);
			ans[i] = getMin(s);
		}
		else if(strcmp(operation[i] , "pop") == 0){
			pop(s);
			ans[i] = getMin(s);
		}

	}
	return ans;
}