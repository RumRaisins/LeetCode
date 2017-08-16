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
	if (a.first > b.first) return 1;
	if (a.first == b.first && a.num < b.num)return 1;
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
	if (max_value != pos) {
		swap(&h->data[max_value], &h->data[pos]);
		update(h, max_value, n);
	}
}

void pop(Heap *h) {
	if (!h->size) return;
	swap(&h->data[h->size - 1], &h->data[0]);
	--h->size;
	update(h, 0, h->size);
}

void clear(Heap *h) {
	free(h->data);
	free(h);
}


int main() {
	int n;
	scanf("%d", &n);
	int count = 1;
	Heap** heap = (Heap**)malloc(sizeof(Heap*) * 101);
	for (int i = 0; i <= 100; ++i) {
		heap[i] = (Heap*)malloc(sizeof(Heap));
		init(heap[i], 50000);
	}
	while (n--) {
		printf("Case #%d:\n", count++);	
		int m;
		scanf("%d", &m);
		int index = 1;
		for(int i = 0 ; i < m; ++i){
			Zombie temp;
			scanf("%d %d", &temp.first, &temp.si);
			temp.num = index++;
			push(heap[temp.si], temp);
		}
		//i是第i秒
		for(int i = 0 ; i < m ;++i){
			int max_index = -1;
			Zombie zombie1, zombie2;
			//j里面存的是Si
			for (int j = 1; j <= 100; ++j) {
				if (heap[j]->size == 0)continue;
				if (max_index == -1) {
					max_index = j;
					continue;
				}
				zombie1 = top(heap[j]);
				zombie2 = top(heap[max_index]);
				zombie1.first += i * j;
				zombie2.first += i * max_index;
				if (compare(zombie1, zombie2)) {
					max_index = j;
				}
			}
			printf("%d", top(heap[max_index]).num);
			pop(heap[max_index]);
			if (i != m - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	for (int i = 0; i <= 100; ++i) {
		clear(heap[i]);
	}
	free(heap);

	system("pause");
	return 0;
}
