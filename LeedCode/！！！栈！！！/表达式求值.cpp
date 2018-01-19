#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long long col(char *str, int left, int right, int a) {
	int basics = 0;
	int min = 100000, ind = -1;
	for (int i = left; i < right; ++i) {
		if (str[i] == '(') { basics += 100; continue; }
		if (str[i] == ')') { basics -= 100; continue; }
		int thiss = 200000;
		if (str[i] == '+')thiss = basics + 1;
		if (str[i] == '-')thiss = basics + 1;
		if (str[i] == '*')thiss = basics + 2;
		if (str[i] == '/')thiss = basics + 2;
		if (str[i] == '^')thiss = basics + 3;
		if (min >= thiss) {
			min = thiss;
			ind = i;
		}
	}
	if (ind == -1) {
		int x = 0;
		for (int i = left; i < right; ++i) {
			if (str[i] == 'a') return a;
			if (str[i] < '0' || str[i] > '9')continue;
			x = x * 10 + (str[i] - '0');
		}
		return x;
	}
	long long mi = col(str , left , ind , a);
	long long mj = col(str, ind + 1, right, a);
	switch (str[ind]) {
		case '+':
			return (mi + mj);
			break;
		case '-':
			return (mi - mj);
			break;
		case '*':
			return (mi * mj);
			break;
		case '^':
			return (long long)(powl(mi, mj));
			break;
	}
	return 0;
}

int main() {
	char str[100];
	char str2[26][100];
	int n;
	scanf("%[^\n]s", str);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		//getchar();
		scanf("%[^\n]s", str2[i]);
	}

	for (int i = 0; i < n; ++i) {
		int flag = 1;
		for (int j = 0; j < 5; ++j) {
			if (col(str, 0, strlen(str), j) != col(str2[i], 0, strlen(str2[i]), j)) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("%c", i + 'A');
		}
	}
	printf("\n");
	return 0;
}