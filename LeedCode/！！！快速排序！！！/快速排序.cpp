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
#define swap(a,b) a^=b^=a^=b
void insert_sort(int *data, int length) {
	int min = 0;
	for (int i = 1; i < length; ++i) {
		if (data[i] < data[min]) {
			min = i;
		}
	}
	swap(data[min], data[0]);
	for (int i = 0; i < length; ++i) {
		int j = i - 1;
		while (data[j] > data[j + 1]) {
			if (data[j] > data[j + 1]) {
				swap(data[j], data[j + 1]);
			}
			else {
				break;
			}
			--j;
		}
	}
}



int quick_select(int *num, int n) {
	int x = 0, y = n - 1;
	int z = num[rand() % n];
	do {
		while (num[x] < z) x++;
		while (num[y] > z) y--;
		if (x <= y) {
			if (x != y) {
				num[x] ^= num[y];
				num[y] ^= num[x];
				num[x] ^= num[y];
			}
			x++, y--;
		}
	} while (x <= y);
	return y;
}

void quick_sort2(int *num, int left, int right) {
	while (right - left >= 1) {
		int x;
		x = quick_select(num + left, right - left + 1) + left;
		quick_sort2(num, x + 1, right);
		right = x;
	}
	return;
}




void quick_sort(int *num, int left, int right) {
	while (right - left >= 1) {
		int x, y, z;
		x = left, y = right;
		z = num[left + rand() % (right - left + 1)];
		do {
			while (num[x] < z) x++;
			while (num[y] > z) y--;
			if (x <= y) {
				if (x != y) {
					num[x] ^= num[y];
					num[y] ^= num[x];
					num[x] ^= num[y];
				}
				++x, --y;
			}
		} while (x <= y);
		quick_sort(num, x + 1, right);
		right = x - 1;
	}
}



int main() {
	

	int p[10] = { 85,34,4,231,43,23,67,8,0,6 };

	//qSort(p, 0, 9);
	//insert_sort(p, 10);
	quick_sort(p, 0, 9);
	for (int i = 0; i < 10; ++i) {
		cout << p[i] << " ";
	}
	//qsort(p, 9, sizeof(int), cmp);
	system("pause");
	return 0;
}