#include <stdlib.h>
#include <stdio.h>

#include <iostream>
using namespace std;


int find_target(int matrix[3][4], int n, int m, int target) {
	if (target < matrix[0][0] || target > matrix[n][m]) return 0;
	int rowt = 0, rowb = n, coll = 0, colr = m, midr;
	while (rowt < rowb) {
		midr = (rowt + rowb) >> 1;
		if (matrix[midr][m] >= target) {
			rowb = midr;
		}
		else {
			rowt = midr + 1;
		}
	}
	cout << "ROW:" << rowt<<endl;
	cout << "LAST ROW:" << matrix[rowt][m] << endl;
	while (coll <= colr) {
		int midc = (coll + colr) >> 1;
		if (matrix[rowt][midc] == target) {
			return 1;
		}
		else if (matrix[rowt][midc] > target) {
			colr = midc - 1;
		}
		else {
			coll = midc + 1;
		}
	}
	return 0;
}


int main() {

	
	int matrix[3][4] = { 1,  3 , 4 , 7,
						 9 ,10 ,11 ,14,
						16 ,19 ,20 ,22 };
	int n;
	while (cin >> n) {
		if (find_target(matrix, 2, 3, n)) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	system("pause");
	return 0;
}