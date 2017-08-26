#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;


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

int quick_sort(vector<int>& vec, int left, int right, int k) {
	for (int c : vec) {
		cout << c << " ";
	}
	int l, r, piv;
	while (left <= right) {
		l = left, r = right, piv = vec.at(left);
		while (l < r) {
			while (l < r && vec.at(r) > piv) --r;
			if (l < r) vec.at(l++) = vec.at(r);
			while (l < r && vec.at(l) < piv) ++l;
			if (l < r) vec.at(r--) = vec.at(l);
		}
		vec.at(l) = piv;
		if (l > k - 1) {
			right = l - 1;
		}
		else if (l < k - 1) {
			left = l + 1;
		}
		else {
			return vec[l];
		}
	}
}
int main() {
	vector<int> vec;
	int n;
	char enter;
	while (cin >> n) {
		vec.push_back(n);
	
	}
	
	//int k;
	//cin >> k;
	cout << quick_sort(vec, 0, vec.size() - 2 , vec.size() - n) << endl;
	system("pause");
	return 0;

}