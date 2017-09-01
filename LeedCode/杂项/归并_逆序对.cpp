#include <iostream>
#include <stdio.h>



int marge_sort(int *num, int left, int right) {
	if (right - left == 1) return 0;
	int sum = 0;
	int mid = (left + right) >> 1;
	sum += marge_sort(num, left, mid);
	sum += marge_sort(num, mid, right);
	int l = left, r = mid, index = 0;
	int *temp = (int *)malloc((right - left + 1) * sizeof(int));
	/*while (l < mid && r < right) {
		while (l < mid && num[l] <= 3 * num[r]) {
			++l;
		}
		sum += (mid - l);
		++r;
	}*/
	l = left, r = mid;
	while (l < mid || r < right) {
		if (l == mid) {
			temp[index++] = num[r++];
			continue;
		}
		if (r == right) {
			temp[index++] = num[l++];
			continue;
		}
		if (num[l] >  num[r]) {
			printf("%d >  %d\n", num[l], num[r]);
			sum += mid - l;
		}
		temp[index++] = num[l] > num[r] ? num[r++] : num[l++];
	}
	for (int i = 0; i < index; ++i) {
		num[left + i] = temp[i];
	}
	free(temp);
	return sum;
}

int main() {
	int p[10] = { 5 ,8 ,6 ,9 ,1 ,3 ,2 ,10 ,4 ,7 };
	std::cout << marge_sort(p, 0, 10)<<std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << p[i] << " ";
	}
	system("pause");
	return 0;
}