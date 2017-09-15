#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maxlengthCommon(char *str1, int len1, char *str2, int len2) {
	int *dp[2];
	dp[0] = (int *)calloc(len2 + 2, sizeof(int));
	dp[1] = (int *)calloc(len2 + 2, sizeof(int));

	for (int i = 0; str1[i]; ++i) {
		for (int j = 0; str2[j]; ++j) {
			dp[i & 1][j + 1] = dp[i & 1][j];
			if (dp[i & 1][j + 1] < dp[!(i & 1)][j + 1]) {
				dp[i & 1][j + 1] = dp[!(i & 1)][j + 1];
			}
			if (str1[i] == str2[j]) {
				if (dp[i & 1][j + 1] < dp[!(i & 1)][j] + 1)
					dp[i & 1][j + 1] = dp[!(i & 1)][j] + 1;
			}
		}
	}
	return dp[!(len1 & 1)][len2];
}


int shortestPalindrome(char *str) {
	int len = strlen(str);
	char *str2 = (char *)calloc(len, sizeof(char));
	for (int i = 0; str[i]; ++i) {
		str2[i] = str[len - i - 1];
	}
	return len - maxlengthCommon(str, len, str2, len);

}
int main() {
	char a[3000 + 10];
	scanf("%s", a);
	printf("%d\n", shortestPalindrome(a));
}