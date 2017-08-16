#include <iostream>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		int xor = a ^b;
		int in = (a & b) << 1;
		while (in) {
			a = xor;
			b = in;
			xor = a ^ b;
			in = (a & b) << 1;
		}
		return xor;
	}
};