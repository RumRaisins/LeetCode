#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int calculateMinimumHP(vector<vector<int> >& dungeon) {
		int row = dungeon.size() ,col = dungeon[0].size();
		if (row == 1 && col == 1) return abs(dungeon[0][0]) + 1;
		//最后一列 把数组扩大一位，减少判断
		vector<int> result(col + 1, INT_MAX);
		result[col - 1] = 1;
		for (int i = row - 1; i >= 0; --i) {
			for (int j = col - 1; j >= 0; --j) {
				result[j] = min(result[j], result[j + 1]) - dungeon[i][j];
				result[j] = result[j] > 1 ? result[j] : 1;
			}
		}
		return result[0];
	}
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size(), n = dungeon[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
		dp[m - 1][n] = 1;
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				int val = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
				dp[i][j] = max(val, 1);
			}
		}
		return dp[0][0];
	}
};