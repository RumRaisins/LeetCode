#include <stdio.h>
#include <stdlib.h>

typedef struct Zombie {
	int num;
	int first;
	int si;
}Zombie;
typedef struct Heap {
	Zombie *data;
	int size;
} Heap;

void init(Heap *h, int length_input) {
	h->data = (Zombie*)malloc(sizeof(Zombie) * length_input);
	h->size = 0;
}

void swap(Zombie *a, Zombie *b) {
	Zombie temp = *a;
	*a = *b;
	*b = temp;
}
int compare(Zombie a, Zombie b) {
	if (a.si > b.si) return 1;
	if (a.si == b.si && a.num > b.num)return 1;
	return 0;
}


void push(Heap *h, Zombie value) {
	h->data[h->size] = value;
	int current = h->size;
	int father = (current - 1) / 2;
	while (compare(h->data[current] , h->data[father])) {
		swap(&h->data[current], &h->data[father]);
			current = father;
			father = (current - 1) / 2;
	}
	++h->size;
}

Zombie top(Heap *h) {
	return h->data[0];
}

void update(Heap *h, int pos, int n) {
	int max_value = pos, lchild = pos * 2 + 1, rchild = pos * 2 + 2;
	if (lchild < n && compare(h->data[lchild] , h->data[max_value])) {
		max_value = lchild;
	}
	if (rchild < n &&  compare(h->data[rchild], h->data[max_value])) {
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
	int n;
	scanf("%d", &n);
	Heap** heap = (Heap**)malloc(sizeof(Heap*) * 100);
	while (n--) {
		for (int i = 0; i < 100; ++i) {
			heap[i] = NULL;
		}
		int m;
		scanf("%d", &m);
		int index = 1;
		while (m--) {
			Zombie temp;
			scanf("%d %d", &temp.first, &temp.si);
			temp.num = index++;
			heap[temp.si] = (Heap*)malloc(sizeof(Heap));
			init(heap[temp.si], 100);
			push(heap[temp.si], temp);
		}
		index--;
		while (index--) {
			int max = 0 , max_first = 0;
			for (int i = 0; i < 100 && heap[i] != NULL; ++i) {
				if (top(heap[i]).first > max_first) {
					max = i;
					max_first = top(heap[i]).first;
				}
			}
			printf("%d ", top(heap[max]).num);
			pop(heap[max]);
		}
		printf("\n");
		for (int i = 0; i < 100; ++i) {
			clear(heap[i]);
		}
	}

	system("pause");
	return 0;
}
