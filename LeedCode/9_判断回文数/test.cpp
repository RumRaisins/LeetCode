#include <iostream>
#include<string>
using namespace  std;

int main() {
	string a,b;
	while (cin >> a >> b) {
		int la = a.length();
		int lb = b.length();
		if (la < lb) {

		}//Bสýะก

		int* p = new int[lb];
		for (int i=0;i<lb;i++)
		{
			p[i] = 0;
		}
		for (int i = lb-1; i >=0; i--)
		{
			  
			 a[la-1] = (a[i] - ('0')) + (b[i] - '0')+'0';
			
			
		}
		/*for (int i = lb-1; i >=0; i--)
		{
			cout << p[i];
		}*/
		cout << a;
	}
	system("pause");
	return 0;

}