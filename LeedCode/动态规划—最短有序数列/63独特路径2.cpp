#include <iostream>
#include<vector>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid[0][0] == 1)return 0;
		int row = obstacleGrid.size(), col = obstacleGrid[0].size();
		if (obstacleGrid[row - 1][col - 1] == 1)return 0;
		int *p = new int[col]();
		for (int i = 0; i < col; i++) {
			if (!obstacleGrid[0][i])
				p[i] = 1;
			else break;
		}
		bool flag = false;
		for (int i = 1; i < row; i++) {
			if (obstacleGrid[i][0]) p[0] = 0,flag = false;
			flag = true;
			for (int j =1 ; j <col ; j++)
			{
				if (!obstacleGrid[i][j]) {
					p[j] += p[j - 1];
					if (p[j])flag = true;
				}
				else
					p[j] = 0;
			}	
			if (!flag)
				return 0;
		}
		return p[col - 1];
	}
};
int main() {

	vector<int> vec1, vec2, vec3;
	vec1.push_back(0); vec1.push_back(0); //vec1.push_back(0);
	vec2.push_back(1); vec2.push_back(1);// vec2.push_back(1);
	vec3.push_back(0); vec3.push_back(0); //vec3.push_back(0);
	vector<vector<int>> vec;
	vec.push_back(vec1); vec.push_back(vec2); vec.push_back(vec3);

	Solution sol;
	cout<<sol.uniquePathsWithObstacles(vec);
	system("pause");
	return 0;
}
