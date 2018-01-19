#include<iostream>
using namespace std;



double  qmi(double a, int k) {
	double ans = 1;
	while (k) {
		if (k & 1)  ans = ans * a;
		k >>= 1;
		a = a * a;
	}
	return ans;
}

int main() {
	double a;
	int k;
	while (cin >> a >> k) {
		cout << qmi(a, k) << endl;
	}
	return 0;
}

