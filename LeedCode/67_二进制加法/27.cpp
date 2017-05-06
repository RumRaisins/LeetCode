#include<iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b,int jinzhi) {
		int sizea = a.length();
		int sizeb = b.length();
		
		if (sizea < sizeb)
			return addBinary(b, a,jinzhi);
		int *p = new int[sizea+1];
		string zeros(sizea - sizeb, '0');
		b = zeros + b;
		int carry = 0;
		for (int i = sizea-1 ; i >= 0 ;i --)
		{
			 p[i] = (a[i] - '0') + (b[i] - '0') + carry;
			 if (p[i] >= jinzhi) {
				 carry = p[i] % jinzhi;
				 p[i] = p[i] / jinzhi;
			 }
			 cout << i << endl;
		}
		cout << endl;
		for (int i = 0 ; i < sizea ; i++)
		{
			cout << p[i];
		}
	}
};

int main() {
	string a, b;

	Solution solution;
	cin >> a>>b;
	 solution.addBinary(a, b,10);
	system("pause");
	return 0;
}