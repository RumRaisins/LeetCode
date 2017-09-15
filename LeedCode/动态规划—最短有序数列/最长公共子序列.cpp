#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a ,b) ((a) > (b) ? (a) : (b))
int lengthOfLCS(char *str1, char *str2) {
	int l1 = strlen(str1);
	int l2 = strlen(str2);
	int *dp[2];
	dp[0] = (int *)calloc(l2 + 2, sizeof(int));
	dp[1] = (int *)calloc(l2 + 2, sizeof(int));
	for (int i = 0; i < l2; ++i) {
		dp[0][i] = dp[1][i] = 0;
	}

	for (int i = 0; i < l1; ++i) {
		for (int j = 0; j < l2; ++j) {
			dp[i & 1][j + 1] = max(dp[!(i & 1)][j + 1], dp[i & 1][j]);
			if (str1[i] == str2[j] && dp[i & 1][j + 1] < (dp[!(i & 1)][j] + 1)) {
				dp[i & 1][j + 1] = dp[!(i & 1)][j] + 1;
			}
		}
	}
	return dp[!(l1 & 1)][l2];
}
int main() {
	char a[1000 + 10];
	char b[1000 + 10];
	scanf("%s %s", a, b);
	printf("%d\n", lengthOfLCS(a, b));
}