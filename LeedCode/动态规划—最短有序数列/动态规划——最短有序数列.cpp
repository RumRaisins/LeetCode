#include<iostream>
using namespace std;

const int returnNums(const int* p,const int num){

	int counter = 0;

	return counter;
}


int main() {
	int *p = new int[10]();
	p[0] = 5;
	p[1] = 0;
	p[2] = 9;
	p[3] = 1;
	p[4] = 3;
	p[5] = 4;
	p[6] = 5;
	p[7] = 8;
	p[8] = 1;
	p[9] = 3;
	int *d = new int[10]();
	for (int i=0;i<10;i++)
	{
		d[i] = 1;
	}
	int temp = 0;

	for (int i = 1 ; i < 10 ;i++)
	{ 
		if (p[i - 1] <= p[i] && d[i - 1] + 1 > d[i])
			d[i] = d[i - 1] + 1;
		if (d[i] > temp)
			temp = d[i];
	}
	cout << temp << endl;
	for (int i = 0 ; i < 10 ; i++)
	{
		cout << d[i] << ""<<endl;
	}
	


	delete[] d;
	delete[] p;
	
	system("pause");
	return 0;

}