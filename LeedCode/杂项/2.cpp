#include <iostream>
#include <vector>
#include <queue>
using std::queue;
using std::cout;
using std::cin;
using std::vector;
int GetMaxActionValue(vector<vector<int>> bourdMap) {
	int row = bourdMap.size();
	int col = bourdMap[0].size();
	int** dp = new int*[row];
	for (int i = 0; i<row; i++) {
		dp[i] = new int[col];
		memset(dp[i], 0, sizeof(int)*col);
	}
	dp[0][0] = bourdMap[0][0];
	for (int i = 1; i<col; i++) dp[0][i] = dp[0][i - 1] + bourdMap[0][i];
	for (int i = 1; i<row; i++) {
		for (int j = 0; j<col; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][0] + bourdMap[i][j];
				continue;
			}
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + bourdMap[i][j];
		}
	}
	int res = dp[row - 1][col - 1];
	int i = row - 1, j = col - 1;
	int minVal = dp[i][j];
	while (i || j) {
		int cur = dp[i][j] - bourdMap[i][j];
		int it = !i ? 0 : i - 1;
		if (cur == dp[it][j]) {
			i = it;
		}
		else j = j - 1;
		minVal = min(minVal, dp[i][j]);
	}
	for (int i = 0; i<row; i++) delete[] dp[i];
	delete[] dp;
	if (minVal >= 0) minVal = 0;
	return abs(minVal) + 1;
}

int minPathSum(vector<vector<int> >& grid) {

	int row = grid.size(), col = grid[0].size();
	int *p = new int[col]();
	p[0] = grid[0][0];
	for (int i = 1; i < row; i++)
	{
		p[0] = grid[i][0] + p[0];
		for (int j = 1; j < col; j++)
		{
			p[j] = (grid[i][j] + (p[j - 1] > p[j] ? p[j] : p[j - 1]));
		}
	}
	return p[col - 1];
}

int main() {
	int n, m , temp;
	cin >> n >> m;
	vector<vector<int> >vec;
	queue<int> q;
	q.pop

	/*for (int i = 0; i < n; ++i) {
		vector<int> vv;
		vec.push_back(vv);
		for (int j = 0; j < m; ++j) {
			cin >> temp;
			vec[i].push_back(temp);
		}
	}*/
	cout << minPathSum(vec);
	
	return 0;
}