#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int ui;

void ito2(char n, int base, int count) {
	//if (count >= 32) {
	//return;
	//}
	if (n == 0) {
		return;
	}
	ito2(n / base , base,count + 1);
	printf("%d", n % base);
	
}

void shift_and(const char *s, const char *t) {
	int lt = strlen(t);
	int col = (lt >> 5) + 1;
	ui **str_code = (ui **)calloc(256 , sizeof(ui *));
	int *p = (int *)calloc(col , sizeof(int));
	for (int i = 0; i < 256; ++i) {
		str_code[i] = (ui*)calloc(col ,sizeof(ui));
	}
	for (int i = 0; t[i]; ++i) {
		int  temp = i >> 5;
		str_code[t[i]][temp] |= (1 << (i - 32 * temp));
	}
	for (int i = 0; s[i]; ++i) {	
		/*
		ui flag = p[0] & 0x80000000;
		p[0] = (p[0] << 1 | 1);
		p[0] &= str_code[s[i]][0];
		for (int j = 1; j < col; ++j) {
			p[j] = flag ? (p[j] << 1 | 1) : (p[j] << 1);
			flag = p[j] & 0x80000000;
			p[j] &= str_code[s[i]][j];	
		}*/
		
		
		for (int j = col - 1; j >= 1; --j) {
			p[j] = (p[j] << 1) | (!!(p[j - 1] & 0x80000000));
			p[j] &= str_code[s[i]][j];
		}
		p[0] = (p[0] << 1) | 1;
		
		
		if (p[col - 1] & (1 << (lt - 32 * (col - 1) - 1))) {
			printf("Yes\n");
			return;
		}

	}
		printf("No\n");
		return;
}
int main() {

	//char n = 1;
	//ito2(n << 7, 2, 0);
	//printf("%d", n << 31);
	shift_and("dkfjsdlkfjslkdfjlksjfaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaafldkfs;ldkflsdkflsdkl;f", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaf");
	//shift_and("dkfjsdlkfjslkdfjlksjfaaaaaaaaaaaaaaaaaaaaaaaaaaaaadaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaafaaaaaaaaaaaaaaaaaaaaaaadaaaaaaaaaaaaadaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaafldkfs;ldkflsdkflsdkl;f", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaf");
	//printf("%d", 31 >> 5);
	//unsigned int i = 0;
	//i |= 1 << 31;
	//ito2(i, 2, 0);
	system("pause");
	return 0;
}