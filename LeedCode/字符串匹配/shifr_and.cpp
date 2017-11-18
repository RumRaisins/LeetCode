/*************************************************************************
> File Name: shift-and.cpp
> Author:
> Mail:
> Created Time: 2017年08月15日 星期二 11时38分47秒
************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void shift_and(const char *s, const char *t) {
	//int len = strlen(s);
	int str_encode[256] = { 0 };
	int p = 0, len = 0;
	for (int i = 0; t[i]; ++i) {
		str_encode[t[i]] |= (1 << i);
		++len;
	}
	for (int i = 0; s[i]; ++i) {
		p = (p << 1 | 1) & str_encode[s[i]];
		if (p & (1 << (len - 1))) {
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
	return;
}

int main() {
	shift_and("abcdefgh", "cde");

	system("pause");
	return 0;
}

