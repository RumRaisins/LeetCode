#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void Sunday(char *s, char *t) {
	int lt = strlen(t);
	int ls = strlen(s);
	int str_code[256];
	for (int i = 0; i < 256; ++i) {
		str_code[i] = lt + 1;
	}
	for (int i = 0; t[i]; ++i) {
		str_code[t[i]] = lt - i;
	}
	int i = 0, j = 0;
	while (i + lt <= ls) {
		if (s[i + j] != t[j]) {
			i += str_code[s[i + lt]];
			j = 0;
		}
		else {
			j++;
		}
		if (t[j] == '\0') {
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
	return;
}

int main() {

	char buffer[100], pattern[100];
	while (scanf("%s\n%s", buffer, pattern)) {
		Sunday(buffer, pattern);
	}
	system("pause");
	return 0;

}