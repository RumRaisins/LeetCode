#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int ui;

typedef struct Bitmap {
	ui* data;
	int count;
}*pBitmap;

void ito2(ui n, int base, int count) {
	if (count >= 32) {
		return;
	}
	//if (n == 0) {
	//	return;
	//}
	ito2(n / base , base,count + 1);
	printf("%d", n % base);
	
}


//×Ö·û´®³¤¶È
pBitmap init_bitmap(int length) {
	pBitmap p = (pBitmap)calloc(1 ,sizeof(Bitmap));
	p->count = (length >> 5) + 1;
	p->data = (ui*)calloc(p->count, sizeof(ui));
	return p;
}

void set_one(pBitmap p, int pos) {
	int temp = pos >> 5;
	p->data[temp] |= (1 << (pos - 32 * temp));
}

int is_one(pBitmap p, int pos) {
	int temp = (pos >> 5);
	return p->data[temp] == (1 << (pos - 32 * (temp - 1) - 1));
}

void move_bitmap(pBitmap p) {
	ui flag = p->data[0] & 0x80000000;
		p->data[0] = (p->data[0] << 1 | 1);
	for (int j = 1; j <= p->count; ++j) {
		p->data[j] = flag ? (p->data[j] << 1 | 1) : (p->data[j] << 1);
		flag = p->data[j] & 0x80000000;
	}
}
void and_bit(pBitmap p1 , pBitmap p2) {
	for (int i = 0; i < p1->count; ++i) {
		p1->data[i] = p1->data[i] & p2->data[i];
	}
}



void clear(pBitmap p) {
	free(p->data);
	free(p);
}

void shift_and(const char *s, const char *t) {
	int lt = strlen(t);
	pBitmap str_code[256];
	pBitmap p = init_bitmap(lt);
	for (int i = 0; i < 256; ++i) {
		str_code[i] = init_bitmap(lt);
	}
	for (int i = 0; t[i]; ++i) {
		set_one(str_code[t[i]], i);
	}
	for (int i = 0; s[i]; ++i) {
		move_bitmap(p);
		p->data[0] |= 1;
		and_bit(p, str_code[s[i]]);
		if (is_one(p, lt)) {
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
	return;
}

//void shift_and(const char *s, const char *t) {
//	int lt = strlen(t);
//	int col = (lt >> 5) + 1;
//	ui **str_code = (ui **)calloc(256 , sizeof(ui *));
//	int *p = (int *)calloc(col , sizeof(int));
//	for (int i = 0; i < 256; ++i) {
//		str_code[i] = (ui*)calloc(col ,sizeof(ui));
//	}
//	for (int i = 0; t[i]; ++i) {
//		int  temp = i >> 5;
//		str_code[t[i]][temp] |= (1 << (i - 32 * temp));
//	}
//	for (int i = 0; s[i]; ++i) {	
//		/*
//		ui flag = p[0] & 0x80000000;
//		p[0] = (p[0] << 1 | 1);
//		p[0] &= str_code[s[i]][0];
//		for (int j = 1; j < col; ++j) {
//			p[j] = flag ? (p[j] << 1 | 1) : (p[j] << 1);
//			flag = p[j] & 0x80000000;
//			p[j] &= str_code[s[i]][j];	
//		}*/
//		
//		
//		for (int j = col - 1; j >= 1; --j) {
//			p[j] = (p[j] << 1) | (!!(p[j - 1] & 0x80000000));
//			p[j] &= str_code[s[i]][j];
//		}
//		p[0] = (p[0] << 1) | 1;
//		p[0] &= str_code[s[i]][0];
//		
//		if (p[col - 1] & (1 << (lt - 32 * (col - 1) - 1))) {
//			printf("Yes\n");
//			return;
//		}
//
//	}
//		printf("No\n");
//		return;
//}


int main() {

	//char n = 1;
	//ito2(n << 7, 2, 0);
	//printf("%d", n << 31);
	shift_and("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaf", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaf");
	//shift_and("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaf", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaf");
	//shift_and("dkfjsdlkfjslkdfjlksjfaaaaaaaaaaaaaaaaaaaaaaaaaaaaadaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaasaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaafaaaaaaaaaaaaaaaaaaaaaaadaaaaaaaaaaaaadaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaafldkfs;ldkflsdkflsdkl;f", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaf");
	//printf("%d", 31 >> 5);
	//unsigned int i = 0;
	//i |= 1 << 31;
	//ito2(i, 2, 0);
	system("pause");
	return 0;
}