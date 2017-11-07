


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct DisjointSet {
	int *father;
	int *rank;
	int cnt;
} DisjointSet;

void init(DisjointSet *s, int size) {
	s->father = (int *)malloc(sizeof(int) * size);
	s->rank = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i) {
		s->father[i] = i;
		s->rank[i] = 1;
	}
	s->cnt = 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int find_set(DisjointSet *s, int node) {
	if (s->father[node] != node) {
		s->father[node] = find_set(s, s->father[node]);
	}
	return s->father[node];
}

int merge(DisjointSet *s, int node1, int node2) {
	int f1 = find_set(s, node1);
	int f2 = find_set(s, node2);
	if (f1 != f2) {
		if (s->rank[f1] > s->rank[f2]) {
			swap(&f1, &f2);
		}
		s->father[f1] = f2;
		s->rank[f2] = max(s->rank[f1] + 1, s->rank[f2]);
		return 1;
	}
	return 0;
}

void clear(DisjointSet *s) {
	if (!s) return;
	free(s->father);
	free(s->rank);
	free(s);
}
int numIslands(char** grid, int gridRowSize, int gridColSize) {
	for (int i = 0; i < gridRowSize; ++i) {
		for (int j = 0; j < gridColSize; ++j) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	DisjointSet *p = (DisjointSet *)malloc(sizeof(DisjointSet));
	int temp = gridRowSize * gridColSize;
	init(p, temp);
	int index = 0;
	for (int i = 0; i < gridRowSize; ++i) {
		for (int j = 0; j < gridColSize; ++j) {
			++index;
			if (grid[i][j] == '0') continue;
			p->cnt++;
			if (i - 1 >= 0 && grid[i - 1][j] == '1') {
				merge(p, index - 1, index - gridColSize);
			}
			if (j - 1 >= 0 && grid[i][j - 1] == '1') {
				merge(p, index - 1, index - 1);
			}
		}
	}
	temp = p->cnt;
	clear(p);

	return temp;
}



int main() {

	char **grid = (char **)malloc(sizeof(char *));
	grid[0] = (char *)malloc(2 * sizeof(char));
	grid[0][0] = '1';
	grid[0][1] = '1';
	cout << numIslands(grid, 1, 2) << endl;


	system("pause");
	return 0;
}

