#include<iostream>
#include<vector>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (__builtin_expect(!!(prices.empty()),0))return 0;
		int l = prices.size();
		int *p = new int[l]();
		p[0] = 0;
		int minPrices = prices[0];
		int prefect = 0;
		for (int i = 1; i < l; i++)
		{
				minPrices = min(prices[i],minPrices);
				int temp = prices[i] - minPrices;
				prefect = max(temp, prefect);
		}
		return prefect;
	}
};
int main() {
	vector<int> vec;
	vec.push_back(7); vec.push_back(1); vec.push_back(5); vec.push_back(3); vec.push_back(6);
	Solution sol;
	cout << sol.maxProfit(vec);

	system("pause");
}