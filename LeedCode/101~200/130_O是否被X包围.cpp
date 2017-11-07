#include <stdio.h>
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
}
void clear(UnionSet *u) {
	free(u->father);
	free(u->rank);
	free(u);
}

int find_set(UnionSet *u, int index) {
	if (u->father[index] != index) {
		u->father[index] = find_set(u, u->father[index]);
	}
	return u->father[index];
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
void solve(char** board, int boardRowSize, int boardColSize) {
	if (board == NULL) return;
	UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
	init(u, boardRowSize * boardColSize + 2);
	int index = 0;
	for (int i = 0; i < boardRowSize; ++i) {
		for (int j = 0; j < boardColSize; j++)
		{
			index++;
			if (board[i][j] == 'O') {
				if (i == 0 || j == boardColSize - 1 || j == 0 || i == boardRowSize - 1) {
					merge(u, index, 0);
				}
				if (i > 0 && board[i - 1][j] == 'O') {
					merge(u, index, index - boardColSize);
				}
				if (j > 0 && board[i][j - 1] == 'O') {
					merge(u, index, index - 1);
				}
			}
		}
	}
	index = 0;
	for (int i = 0; i < boardRowSize; ++i) {
		for (int j = 0; j < boardColSize; j++)
		{
			++index;
			if (board[i][j] == 'X') {
				board[i][j] = 'X';
			}
			else {
				int father = u->father[index];
				board[i][j] = (father == 0 ? 'O' : 'X');
			}
		}
	}
	//free(u->father);
	//free(u->rank);
	//free(u);
}

