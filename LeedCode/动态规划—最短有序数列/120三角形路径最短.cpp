#include<iostream>
#include<vector>
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

class Solution {
public:
	int insertSort(vector<int>& m) {
		int lm = m.size();
		for (int j = 1 ; j < lm ; j++)
		{
			int key = m.at(j);
			int i = j - 1;
			while (i+1) {
				if (m.at(i) > key) {
					int temp = m.at(i + 1);
					m.at(i + 1) = m.at(i);
					m.at(i) = temp;
				}
				i--;
			}
		}
		return m[0];
	}

	int minimumTotal(vector<vector<int> >& triangle) {
		int row = triangle.size();

		for (int i = 1; i < row; i++)
		{
			for (int j = 0 ; j < triangle[i].size() ; j++)
			{
				if (j == 0) {
					triangle[i][0] += triangle[i - 1][0];
				}
				else if (j == triangle[i].size() - 1) {
					triangle[i][j] += triangle[i - 1][j-1];
				}
				else {
					triangle[i][j] += 
					(triangle[i - 1][j - 1] > triangle[i - 1][j] ? triangle[i - 1][j] : triangle[i - 1][j - 1]);

				}
			}

		}
		insertSort(triangle[triangle[row-1].size() - 1]);
		return triangle[triangle[row-1].size() - 1][0];
	}
	int minimumTotal2(vector<vector<int> >& triangle) {
		int row = triangle.size();
		vector<int> minlen(triangle.back());
		for (int i = row-2; i >= 0 ; i--)
		{
			for (int j =0 ; j <= i; j++ )
			{
				minlen[j] = min(minlen[j], minlen[j+1]) + triangle[i][j];
			}
			cout << endl;
		}
		return minlen[0];
	}
};

int main() {

	vector<vector<int> > num;
	vector<int> num1, num2, num3 ,num4;
	              num1.push_back(-1);
	      num2.push_back(2); num2.push_back(3);
	    num3.push_back(1); num3.push_back(-1); num3.push_back(-3);
	num4.push_back(4); num4.push_back(1); num4.push_back(8); num4.push_back(3);
	num.push_back(num1), num.push_back(num2), num.push_back(num3) , num.push_back(num4);

		//cout << num.size()<<endl;
	/*num.push_back(67);
	num.push_back(25);
	num.push_back(24);
	num.push_back(13);
	num.push_back(31);
	num.push_back(56);
	num.push_back(90);
	num.push_back(67);
	num.push_back(67);
	num.push_back(67);*/
	Solution sol;
	//sol.insertSort(num);
	cout << sol.minimumTotal2(num);
	system("pause");
	return 0;
}