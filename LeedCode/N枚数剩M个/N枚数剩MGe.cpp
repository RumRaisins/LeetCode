#include<iostream>
using namespace std;
int main() {

	int i = 7;
	int temp = 49;
	while (1) {
		if (temp % 2 == 1 && temp % 3 == 2 && temp % 5 ==4 && temp % 6 ==5) {
			cout << temp;
			break;
		}
		i += 10;
		temp = 7 * i;
	}
	system("pause");

}