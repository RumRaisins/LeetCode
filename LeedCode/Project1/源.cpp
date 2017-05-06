#include<iostream>
using namespace std;
int main() {


	int i;
	cin >> i;
	while (1) {
		if (i % 7 == 0) {
			cout << i << endl;
			//break;
		}
		i = i*2;
	}
	system("pause");
}