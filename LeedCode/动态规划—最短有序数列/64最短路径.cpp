#include<vector>
#include<iostream>
using namespace std;




class Solution {
public:
	int minPathSum(vector<vector<int> >& grid) {
		/*int row = grid.size(), col = grid[0].size();
		int **net = new int*[row];
		for (int i = 0; i < row; i++) {
			net[i] = new int[col]();
		}
		net[0][0] = grid[0][0];
		for (int i = 1; i < row; i++) {
			net[i][0] = grid[i][0] + net[i - 1][0];
		}
		for (int j = 1; j < col; j++) {
			net[0][j] = grid[0][j] + net[0][j - 1];
		}
		for (int i=1; i < row ; i++)
		{
			for (int j = 1 ; j < col ; j++)
			{
				net[i][j] = grid[i][j] + (net[i - 1][j] > net[i][j - 1] ? net[i][j - 1] : net[i - 1][j]);
			}
		}
		return net[row - 1][col - 1];*/
		int row = grid.size(), col = grid[0].size();
		int *p = new int[col]();
		p[0] = grid[0][0];
		cout << p[0] << " ";
		for (int i = 1; i < col; i++)
		{
			p[i] = p[i - 1] + grid[0][i];
			cout << p[i] << " ";
		}
		cout << endl;
		for (int i = 1; i < row; i++)
		{
			p[0] = grid[i][0] + p[0];
			cout << p[0] << " ";
			for (int j = 1; j < col; j++)
			{
				p[j] = (grid[i][j] + (p[j - 1] > p[j] ? p[j] : p[j - 1]));
				cout << p[i] << " ";
			}
			cout << endl;
		}
		return p[col - 1];
		

	}
};
int main() {

	vector<int> vec1, vec2, vec3;
	vec1.push_back(1); vec1.push_back(3); vec1.push_back(1);
	vec2.push_back(1); vec2.push_back(5); vec2.push_back(1);
	vec3.push_back(4); vec3.push_back(2); vec3.push_back(1);
	vector<vector<int>> vec;
	vec.push_back(vec1); vec.push_back(vec2); vec.push_back(vec3);

	Solution sol;
	cout << sol.minPathSum(vec);
	system("pause");
	return 0;
}
