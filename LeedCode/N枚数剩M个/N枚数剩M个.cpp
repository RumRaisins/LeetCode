#include<iostream>
using namespace std;
int main() {
	int i = 30;
	while (1) {
		if ((i-1) % 7 == 0) {
			cout << i-1 << endl;
			break;
		}
		i *= 2;
	}
	system("pause");
}