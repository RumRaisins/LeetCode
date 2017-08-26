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

	return *(int *)b - *(int *)a;  //升序排序

								   //return *(int *)b - *(int *)a; //降序排序

								   /*可见：参数列表是两个空指针，现在他要去指向你的数组元素。所以转型为你当前的类型，然后取值。

								   升序排列时，若第一个参数指针指向的“值”大于第二个参数指针指向的“值”，则返回正；若第一个参数指针指向的“值”等于第二个参数指针指向的“值”，则返回零；若第一个参数指针指向的“值”小于第二个参数指针指向的“值”，则返回负。

								   降序排列时，则刚好相反。

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