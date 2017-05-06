#include<iostream>
#include<vector>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		int sum = 0;
		for (vector<int>::iterator i = prices.begin()+1; i != prices.end() ; i ++)
		{
			sum += max(0, *i-*(i-1));
		}
		return sum;
	}
};
int main() {
	vector<int> vec;
	vec.push_back(7); vec.push_back(1); vec.push_back(5); vec.push_back(3); vec.push_back(6);
	Solution sol;
	cout << sol.maxProfit(vec);

	system("pause");
}
