
#include <cstdio>
#include <functional>
#include <ctime>
#include <iostream>

using namespace std;


auto insert_sort = [](int *num, int n) {
	if (n <= 1)return;
	for (int i = 1; i < n; ++i) {
		if (num[i]< num[0]) {
			swap(num[i], num[0]);
		}
	}
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (num[j] < num[j - 1]) {
			swap(num[j], num[j - 1]);
			j--;
		}

	}
};

auto my__sort = [](int threthold) {
	function<void(int *, int, int)> quick_sort = [=, &quick_sort](int *num, int left, int right) {
		while (left < right) {
			if (right - left < threthold) {
				insert_sort(num + left, right - left + 1);
				return;
			}
			int l, r, x;
			l = left, r = right ,x = num[left];
			while (l < r) {
				while (l < r && num[r] >= x) --r;
				if (l < r)num[l++] = num[r];
				while (l < r && num[l] <= x) ++l;
				if (l < r)num[r--] = num[l];
			}
			num[l] = x;
			quick_sort(num, l + 1, right);
			right = l - 1;
		}
	};
	return quick_sort;
};

auto sort1 = my__sort(1);
auto sort16 = my__sort(16);

void randArry(int arry[] , int n) {
	for (int i = 0; i < n; ++i) {
		arry[i] = rand() % 100;
	}
	return;
}
void output(int arry[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << arry[i]<<" ";
	}
}

int main() {
	//srand(time(0));
	int arry[20];
	randArry(arry, 20);
	sort16(arry , 0 ,19);
	output(arry, 20);


	system("pause");
	return 0;
}