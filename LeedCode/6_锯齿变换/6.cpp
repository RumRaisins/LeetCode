#include<iostream>
#include <string>
using namespace std;
class Solution {
public:
	string reverse(string s, int numRows) {

		if (numRows == 1) return s;
		int ls = s.length();
		string outString = s;
		int **trans = (int**)malloc(sizeof(int*)*numRows);
		for (int i = 0; i < numRows; i++)
		{
			trans[i] = (int*)malloc(sizeof(int) * 2);
		}
		trans[0][0] = trans[0][1] = trans[numRows - 1][0] = trans[numRows - 1][1] = (numRows << 1) - 2;
		for (int i = 1; i < numRows - 1; i++)
		{
			trans[i][0] = trans[i - 1][0] - 2;
			trans[i][1] = trans[0][0] - trans[i][0];
		}
		int i = 0, j = 0, sp = 0;
		for (int line = 0; line < numRows; line++)
		{
			i = line; j = 0;
			while (i < ls) {
				outString[sp++] = s[i];
				i += trans[line][j % 2];
				++j;
			}
		}
		return outString;
	}
};
int main()
{
	Solution solutin;
	string s;
	int numRows;
	cin >> s;
	cin >> numRows;

	cout << solutin.reverse(s, numRows);

	system("pause");
	return 0;
}