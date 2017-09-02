#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
int escape(int **maze, int n, int m,
	int initialHP, int maximumHP) {

	maze[1][1] += initialHP;
	if (maze[1][1] <= 0) return -1;
	int left, top;
	for (int i = 1; i <= n; ++i) {
		for (int j = (i == 1 ? 2 : 1); j <= m; ++j) {
			top = left = 0;
			if (i > 1 && maze[i - 1][j] != 0) {
				top = maze[i][j] + maze[i - 1][j];
				top = top < 0 ? 0 : top;
				top = top > maximumHP ? maximumHP : top;
			}
			if (j > 1 && maze[i][j - 1] != 0) {
				left = maze[i][j] + maze[i][j - 1];
				left = left < 0 ? 0 : left;
				left = left > maximumHP ? maximumHP : left;
			}
			maze[i][j] = max(left, top);
		}
	}
	return maze[n][m] == 0 ? -1 : maze[n][m];
}
int main() {
	int n, m, v, c;
	scanf("%d %d %d %d", &n, &m, &v, &c);
	int  **a = (int **)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; ++i) {
		a[i] = (int *)malloc(sizeof(int) * (m + 1));
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d\n", escape(a, n, m, v, c));
	return 0;
}