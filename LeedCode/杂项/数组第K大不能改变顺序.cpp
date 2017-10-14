#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

int binary_search(int *p, int n, int max , int min, int k) {
	
	if (k == n) return max;
	if (k == 1) return min;
	if (k > n) { cout << "³¬¹ý·¶Î§" << endl; return -1; }
	int tempk = 0, tempn = p[0] , mid;
	while (1) {
		mid = (min + max + 1) >> 1;
		int cha = INT_MAX;
		tempk = 0;
		int same = 0;
		for (int i = 0; i < n; ++i) {
			if (p[i] < mid) {
				++tempk;
			}
			if (mid == p[i]) {
				same++;
				tempn = p[i];
				cha = 0;
			}
			else if (cha && mid  > p[i] &&  mid - p[i] < cha) {
				tempn = p[i];
				cha = mid - p[i];
			}
		}
		printf("%d is di %d da , same is %d\n", tempn, tempk, same);
		if (tempk + same == k || (tempk < k && tempk + same > k)) {
			return tempn;
		}
		else if (tempk + same > k ) {
			max = mid;
		}
		else if(tempk + same <  k){
			min = mid;
		}
	}
}


int main() {
	int p[100];
	int n;
	srand(time(0));
	//cin >> n;
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < 10; ++i) {
		//cin >> p[i];
		p[i] = rand() % 100;
		if (p[i] > max) {
			max = p[i];
		}
		else if(p[i] < min){
			min = p[i];
		}
	}
	p[0] = 2; p[1] = 4; p[2] = 4; p[3] = 6; p[4] = 5; p[5] = 10; p[6] = 4; p[7] = 1; p[8] = 6; p[9] = 4;
	int k;
	for (int i = 0; i < 10; ++i) {
		cout << p[i] << " ";
	}
	cout << endl;
	while (cin >> k) {
		//cout << binary_search(p, 10, max, min, k);
		cout << binary_search(p, 10, 10, 1, k) << endl;
	}


	system("pause");
	return 0;



}