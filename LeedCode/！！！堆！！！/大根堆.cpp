#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	int *data, size;
} Heap;

void init(Heap *h, int length_input) {
	h->data = (int*)malloc(sizeof(int) * length_input);
	h->size = 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(Heap *h, int value) {
	h->data[h->size] = value;
	printf("%d ", value);
	int current = h->size;
	int father = (current - 1) / 2;
	while (h->data[current] > h->data[father]) {
		swap(&h->data[current], &h->data[father]);
		current = father;
		father = (current - 1) / 2;
	}
	++h->size;
}

void output(Heap *h) {
	for (int i = 0; i < h->size; ++i) {
		printf("%d ", h->data[i]);
	}
	printf("\n");
}

int top(Heap *h) {
	return h->data[0];
}

void update(Heap *h, int pos, int n) {
	int max_value = pos, lchild = pos * 2 + 1, rchild = pos * 2 + 2;
	if (lchild < n && h->data[lchild] > h->data[max_value]) {
		max_value = lchild;
	}
	if (rchild < n && h->data[rchild] > h->data[max_value]) {
		max_value = rchild;
	}
	if (max_value ^ pos) {
		swap(&h->data[max_value], &h->data[pos]);
		update(h, max_value, n);
	}
}

void pop(Heap *h) {
	swap(&h->data[h->size - 1], &h->data[0]);
	--h->size;
	update(h, 0, h->size);
}

void heap_sort(Heap *h) {
	for (int i = h->size - 1; i > 0; --i) {
		swap(&h->data[i], &h->data[0]);
		update(h, 0, i);
	}
}

void clear(Heap *h) {
	free(h->data);
	free(h);
}




int main() {
	int n, temp;
	Heap *h = (Heap*)malloc(sizeof(Heap));
	scanf("%d", &n);
	init(h, n);
	while (n--) {
		scanf("%d", &temp);
		push(h, temp);
	}
	scanf("%d", &n);
	while (n--) {
		pop(h);
	}
	output(h);
	heap_sort(h);
	output(h);



	system("pause");
	return 0;
}