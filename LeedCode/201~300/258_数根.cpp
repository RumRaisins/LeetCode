

#include <iostream>
using namespace std;

class Solution2 {
public:
	int addDigits(int num) {
		if (!num || (int)log10(num) + 1 == 1) return num;
		int temp, sum = 0;
		while (1) {
			sum = 0;
			while (num) {
				sum += (num % 10);
				num = (num / 10);
			}
			if ((int)log10(sum) + 1 == 1) {
				break;
			}
			else {
				int temp = sum;
				sum = num;
				num = temp;
			}
		}
		return sum;
	}
};

//数根的定理    1 + （n - 1) % 9
class Solution {
public:
	int addDigits(int num) {
		return 1 + (num - 1) % 9;
	}
	
};

int main() {
	int n;
	while (cin >> n) {
		cout << log10(n) << endl;
	}
	system("pause");
	return 0;
}