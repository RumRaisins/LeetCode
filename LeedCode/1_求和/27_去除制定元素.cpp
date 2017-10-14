
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (vector<int>::iterator c = nums.begin(); c != nums.end();) {
			if (*c == val) {
				c = nums.erase(c);
				//cout << *c << " ";
			}
			else {
				++c;
			}
		}
		return nums.size();
	}
};


int main() {

	vector<int> vec;
	vec.push_back(1); vec.push_back(1); vec.push_back(2); vec.push_back(2); vec.push_back(3); vec.push_back(5);
	Solution sol;
	sol.removeElement(vec, 1);
	for (auto c : vec) {
		cout << c << " ";
	}
	system("pause");
	return 0;
}