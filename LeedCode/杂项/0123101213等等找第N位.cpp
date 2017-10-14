#include<cstdio>
#include <cmath>
#include <iostream>
using namespace std;


int main() {

	int n;
	while (cin >> n) {
		if (n  <= 3) {
			cout << n - 1;
			continue;
		}
		int wei = 3;
		int temp = 2;
		int temp_wei = wei;
		int i = 2;
		for (; ; ++i) {
			temp_wei = wei;
			temp = temp * 3;
			wei += i * temp;
			if (wei > n) {
				--i;
				n -= temp_wei;
				break;
			}
		}
		int number = pow(10, i) + n / i;
		int indexFromright = i - n % i;
		while (indexFromright--) {
			number /= 3;
		}
		printf("%d\n", number % 3);
	}


	return 0;


}