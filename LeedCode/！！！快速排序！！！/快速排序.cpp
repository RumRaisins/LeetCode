#include<iostream>
#include<vector>
#include <time.h>

using namespace std;
void qSort(vector<int>& vec,int i,int j) {
	if (j - i <= 1)return;
	if (j - i == 2) {
		if (vec[i] > vec[i + 1]) {
			swap(vec[i], vec[i + 1]);
			return;
		}
	} 
	int x = i, y = j;
	--j;
	int temp = vec[i];
	while (i < j) {
		while (i < j && vec[j] >= temp) --j;
		if (i < j) vec[i] = vec[j], ++i;
		while (i < j && vec[i] < temp) i++;
		if (i < j) vec[j] = vec[i],--j;
	}
	vec[i] = temp;
	qSort(vec, x, i);
	qSort(vec, i + 1, y);
	return;
}

void qSort(int* data, int left, int right) {
	int low, high;
	while (left < right) {
		int piv = data[left];
		low = left, high = right;
		while (low < high) {
			while (low < high && data[high] > piv) --high;
			if(low < high) data[low++] = data[high];
			while (low < high && data[low] < piv)++low;
			if (low < high) data[high--] = data[low];
		}
		data[low] = piv;
		qSort(data, low + 1, right);
		right = low  - 1;
	}
}
int cmp(const void *a, const void *b)

{

	return *(int *)b - *(int *)a;  //��������

								   //return *(int *)b - *(int *)a; //��������

								   /*�ɼ��������б���������ָ�룬������Ҫȥָ���������Ԫ�ء�����ת��Ϊ�㵱ǰ�����ͣ�Ȼ��ȡֵ��

								   ��������ʱ������һ������ָ��ָ��ġ�ֵ�����ڵڶ�������ָ��ָ��ġ�ֵ�����򷵻���������һ������ָ��ָ��ġ�ֵ�����ڵڶ�������ָ��ָ��ġ�ֵ�����򷵻��㣻����һ������ָ��ָ��ġ�ֵ��С�ڵڶ�������ָ��ָ��ġ�ֵ�����򷵻ظ���

								   ��������ʱ����պ��෴��

								   */

}


int main() {
	

	int p[10] = { 32, 1,23,45,2,3,56, 56,65,4 };

	qSort(p, 0, 9);
	for (int i = 0; i < 10; ++i) {
		cout << p[i] << " ";
	}
	//qsort(p, 9, sizeof(int), cmp);
	system("pause");
	return 0;
}