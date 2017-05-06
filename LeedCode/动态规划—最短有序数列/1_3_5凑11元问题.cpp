#include<iostream>
#define min(a,b) (((a)>(b))?(b):(a))
#define Money 100
using namespace std;

int main() {

	int *d = new int[Money + 1]();
	d[0] = 0;
	d[1] = 1;
	d[2] = 2;
	d[3] = 1;
	d[4] = 2;
	d[5] = 1;
	for (int i = 5; i <= Money; i++)
	{
		
		d[i] = min(min(d[i - 1] + 1, d[i - 3] + 1), min(d[i - 3] + 1, d[i - 5] + 1));
	}
	cout << d[Money] << endl;
	delete[] d;
	system("pause");
	return 0;
}