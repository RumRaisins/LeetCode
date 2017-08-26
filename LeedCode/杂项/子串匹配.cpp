#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BASE 'a'

int Sunday(char *buffer, int lb, char *pattern, int lp) {
	int next[256];
	int count = 0;
	for (int i = 0; i < 256; ++i) {
		next[i] = lp + 1;
	}
	for (int i = 0; pattern[i]; ++i) {
		next[pattern[i]] = lp - i;
	}
	int i = 0, j = 0;
	while (i + lp <= lb) {
		if (buffer[i + j] != pattern[j]) {
			i += next[buffer[i + lp]];
			j = 0;
		}
		else {
			++j;
		}
		if (pattern[j] == '\0') {
			++count;
			++i;
			j = 0;
		}
	}
	return count;
}

char *str2str() {
	char temp[100000];
	char buffer[1000];
	char c;
	scanf("%c", &c);
	int index_t = 0, index_b = 0, num = 0, state = 0, flag = 0;
	state = (c == '[' ? 1 : 0);
	if (state)scanf("%c", &c);
	while (true) {
		if (c == '\n') break;
		switch (state) {
		case 0: {
			temp[index_t++] = c;
			scanf("%c", &c);
			state = (c == '[' ? 1 : 0);
			if (state) scanf("%c", &c);
		}break;
		case 1: {
			buffer[index_b++] = c;
			scanf("%c", &c);
			state = (c == ']' ? 2 : 1);
			if (state == 2) scanf("%c", &c);
		}break;
		case 2: {
			if ('0' <= c && c <= '9') {
				num = num * 10 + c - '0';
				scanf("%c", &c);
				if (c == '\n') {
					flag = 1;
				}
			}
			else {
				flag = 1;
			}
			if (flag) {
				for (int i = 0; i < num; ++i) {
					for (int j = 0; j < index_b; ++j) {
						temp[index_t++] = buffer[j];
					}
				}
				index_b = 0;
				num = 0;
				state = (c == '[' ? 1 : 0);
				if (state) scanf("%c", &c);
				flag = 0;
			}
		}break;
		default: {
			printf("WTF\n");
			break;
		}
		}
	}
	temp[index_t] = '\0';
	return temp;
}


int main() {
	char *temp;
	temp = str2str();
	printf("%s\n", temp);
	char pattern[100];
	scanf("%s", pattern);
	//printf("%d", Sunday(temp, strlen(temp), pattern, strlen(pattern)));

	system("pause");
	return 0;
}