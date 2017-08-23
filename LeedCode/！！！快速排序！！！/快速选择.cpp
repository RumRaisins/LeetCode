#include <iostream>
using namespace std;

int quick_select(int *nums, int left, int right, int k) {
	int l, r, piv;
	while (left <= right) {
		l = left, r = right, piv = nums[left];
		while (l < r) {
			while (l < r && nums[r] > piv) --r;
			if (l < r) nums[l++] = nums[r];
			while (l < r && nums[l] < piv) ++l;
			if (l < r) nums[r--] = nums[l];
		}
		nums[l] = piv;
		if (l > k - 1) {
			right = l - 1;
		}
		else if (l < k - 1) {
			left = l + 1;
		}
		else {
			return nums[l];
		}
	}
	return -100;
}
void clear(int *p, int *p1) {
	for (int i = 0; i < 10; ++i) {
		p[i] = p1[i];
	}
}

int main() {
	int p1[10] = { 6 ,10 ,13 ,45 ,2 ,6 ,34 ,76 ,3 ,25 };
	int p[10];
	clear(p, p1);
	cout << quick_select(p, 0, 9 ,1) << endl;
	clear(p, p1);
	cout << quick_select(p, 0, 9, 2) << endl;
	clear(p, p1);
	cout << quick_select(p, 0, 9, 3) << endl;
	clear(p, p1);
	cout << quick_select(p, 0, 9, 4) << endl;
	clear(p, p1);
	cout << quick_select(p, 0, 9, 5) << endl;
	clear(p, p1);
	cout << quick_select(p, 0, 9, 6) << endl;
	clear(p, p1);
	cout << quick_select(p, 0, 9, 7) << endl;
	clear(p, p1);
	cout << quick_select(p, 0, 9, 8) << endl;
	clear(p, p1);
	cout << quick_select(p, 0, 9, 9) << endl;
	clear(p, p1);
	cout << quick_select(p, 0, 9, 10) << endl;
	//cout << p[0] << endl;

	system("pause");
	return 0;

}