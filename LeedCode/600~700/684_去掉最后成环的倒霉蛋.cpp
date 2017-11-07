#include <stdlib.h>

typedef struct UnionSet {
	int *father, *rank;
	int size;
}UnionSet;

void init(UnionSet *u, int size) {
	u->father = (int *)malloc(sizeof(int) * size);
	u->rank = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i) {
		u->father[i] = i;
		u->rank[i] = 1;
	}
	u->size = 0;
}

int find_set(UnionSet *u, int index) {
	if (u->father[index] == index) return index;
	return u->father[index] = find_set(u, u->father[index]);
}

int merge(UnionSet *u, int node1, int node2) {
	int f1 = find_set(u, node1);
	int f2 = find_set(u, node2);
	if (f1 == f2) return 1;
	if (u->rank[f1] > u->rank[f2]) {
		f1 ^= f2 ^= f1 ^= f2;
	}
	u->father[f1] = f2;
	u->rank[f2] = u->rank[f1] + 1 > u->rank[f2] ? u->rank[f1] + 1 : u->rank[f2];
	return 0;
}

int* findRedundantConnection(int** edges, int edgesRowSize, int edgesColSize, int* returnSize) {
	*returnSize = 2;
	int *retsult = (int *)malloc(sizeof(int) * 2);
	UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
	init(u, edgesColSize * edgesRowSize);
	for (int i = 0; i < edgesRowSize; ++i) {
		if (merge(u, edges[i][0] - 1, edges[i][1] - 1)) {
			retsult[0] = edges[i][0];
			retsult[1] = edges[i][1];
		}
	}
	return retsult;
}
int main() {

	system("pause");
	return 0;
}