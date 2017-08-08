#include <map>
#include <iostream>
class Solution {
public:
	int numberAdd(int n) {
		if (n < 10) {
			return  n * n;
		}
		return  numberAdd(n / 10) + (n % 10) * (n % 10);		
	}
	bool isHappy(int n) {
		std::map<int, int> map;
		std::map<int, int>::iterator mapIterator;
		map[n] = n;
		int temp;
		while (1) {
			temp = numberAdd(n);
			std::cout << temp<<std::endl;
			if (temp == 1) {
				return true;
			}
			mapIterator = map.find(temp);
			if (mapIterator != map.end()) {
				map[temp] = temp;
			}
			else
				return false;
		}
	}
	bool isHappy2(int n) {
		int slow, fast;
		slow = fast = n;
		do {
			slow = numberAdd(slow);
			fast = numberAdd(fast);
			fast = numberAdd(fast);
		} while (slow != fast);
		if (slow == 1) return 1;
		else return 0;
	}
};
int main() {
	Solution sol;
	std::cout<<sol.isHappy(19);


	system("pause");
	return 0;
}