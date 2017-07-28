#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		/*int **net = new int*[m];
		for (int i = 0; i < m; i++) {
			net[i] = new int[n]();
		}
		int i = 0, j = 0;
		while (i < m)net[i++][0] = 1;
		while (j < n)net[0][j++] = 1;
		for (i = 1; i < m; i++)
		{
			for (j = 1; j < n; j++)
			{
				net[i][j] = net[i - 1][j] + net[i][j - 1];
			}
		}
		return net[m - 1][n - 1];*/

		if (m > n)return uniquePaths(n, m);
		vector<int> col(m, 1);
		for (int i = 1 ; i < n ; i ++)
		{
			for (int j = 1 ; j < m ; j ++)
			{
				col[j] += col[j - 1];
			}
		}
		return col[m - 1];


	}
};
int main() {
	/*int m, n;
	cin >> m >> n;
	int **net = new int*[m];
	for (int i = 0; i < m; i++) {
		net[i] = new int[n]();
	}
	int i = 0, j = 0;
	while (i < m)net[i++][0] = 1;
	while (j < n)net[0][j++] = 1;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << net[i][j] << " ";
		}
		cout << endl;
	}*/
	Solution sol;
	cout<<sol.uniquePaths(20, 20)<<endl;

	system("pause");
	//delete[] net;
}
