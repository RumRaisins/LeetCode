#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
	int *father, *rank;
	int max_size;
}UnionSet;


void init(UnionSet *u, int size) {
	u->father = (int *)malloc(sizeof(int) * size);
	u->rank = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i) {
		u->father[i] = i;
		u->rank[i] = 1;
	}
	u->max_size = size > 0 ? 1 : 0;
}

int find_set(UnionSet *u, int node) {
	if (u->father[node] != node) {
		u->father[node] = find_set(u, u->father[node]);
	}
	return u->father[node];
}

int merge(UnionSet *u, int node1, int node2) {
	int f1 = find_set(u, node1);
	int f2 = find_set(u, node2);
	if (f1 == f2) return 0;
	if (u->rank[f1] > u->rank[f2]) {
		f1 ^= f2;
		f2 ^= f1;
		f1 ^= f2;
	}
	u->father[f1] = f2;
	u->rank[f2] += u->rank[f1];
	if (u->rank[f2] > u->max_size) {
		u->max_size = u->rank[f2];
	}

	return 1;
}
void clear(UnionSet *u) {
	free(u->father);
	free(u->rank);
	free(u);
}

typedef struct hashData {
	int num;
	int index;
	int flag;
}hashData;
typedef struct hash {
	hashData *data;
	int size;
}hash;
void init_hash(hash* h, int size) {
	h->data = (hashData *)calloc(size, sizeof(hashData));
	h->size = size;
}

int hash_func(int n) {
	return n & 0x7fffffff;
}
int search(hash *h, int n) {
	int index = hash_func(n) % h->size;
	int times = 1;
	while (h->data[index].flag && h->data[index].num != n) {
		index += times * times;
		index %= h->size;
		++times;
	}
	if (h->data[index].flag == 0) return -1;
	return h->data[index].index;
}

int insert(hash *h, hashData n) {
	int index = hash_func(n.num) % h->size;
	int times = 1;
	while (h->data[index].flag && h->data[index].num != n.num) {
		index += (times * times);
		index %= h->size;
		++times;
	}
	if (h->data[index].flag) return 0;
	h->data[index] = n;
	return 1;
}
void clear_hash(hash *h) {
	free(h->data);
	free(h);
}


int longestConsecutive(int *nums, int length) {
	hash *h = (hash *)malloc(sizeof(hash));
	init_hash(h, length * 3);
	UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
	init(u, length);
	for (int i = 0; i < length; ++i) {
		hashData data = { nums[i] , i , 1 };
		if (insert(h, data) == 0) continue;
		int temp1 = search(h, nums[i] + 1);
		int temp2 = search(h, nums[i] - 1);
		if (temp1 != -1) {
			printf("num : %d ,i : %d  ,i + 1 :%d\n",nums[i], i, i + 1);
			merge(u, temp1, i);
		}
		if (temp2 != -1) {
			printf("num: %d ,i : %d  i + 1 :%d\n", nums[i] , i, i - 1);
			merge(u, temp2, i);
		}
	}
	for (int i = 0; i < length; ++i) {
		printf("i :%d  , father : %d  \n", i,u->father[i]);
	}
	int n = u->max_size;
	clear(u);
	clear_hash(h);
	return n;
}




int main() {
	int p[] = {100, 4, 200, 1, 3, 2};
	printf("%d", longestConsecutive(p, 6));


	system("pause");
	return 0;

}