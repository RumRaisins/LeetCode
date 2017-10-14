#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size() - 1;
		for (; n >= 0 ;n--) {
			if (digits[n] == 9) {
				digits[n] = 0;
			}
			else {
				++digits[n];
				return digits;
			}
		}
		digits[0] = 1;
		digits.push_back(0);
		return digits;
	}
};