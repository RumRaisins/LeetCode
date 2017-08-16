#include <iostream>
#include <stdio.h>
using namespace std;


int binary_search(int *data, int n, int target) {
	int l = 0, r = n - 1, mid;
	while (l < r) {
		mid = (l + r + 1) >> 1;
		printf(" l:%d(%d)  mid%d:(%d) r:%d(%d)\n", data[l], l,data[mid] ,mid, data[r], r);
		if (data[mid] == target) {
			l = mid;
			//��ֻ����mid�ǲ�������Ҫ��
			//mid����������Ҫ�ģ�����Ҫ����mid�����1
			//������ͷ =mid
			//����(l + r) >> 1 ��ָ��ǰ������֣������ѭ��������mid = ��l + r  + 1) >> 2; �����l == r 
		}
		else if (data[mid] < target) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return data[l] == target ? l : -1;
}



int main() {
	int p[10] = { 1, 1, 1, 1 ,1 ,0 ,0 ,0 ,0 ,0 };
	for (int i = 0; i < 10; i++) {
		printf("%d(%d) ", p[i], i);
	}
	printf("\n");
	int loc = binary_search(p, 10, 1);
	printf("%d(%d)", p[loc], loc);


	system("pause");
	return 0;

}