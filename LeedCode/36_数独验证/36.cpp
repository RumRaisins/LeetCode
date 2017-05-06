#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int rrow = board[0].size();
		int ccol = board.size();
		int *row = new int[rrow];
		int *col = new int[ccol];
		int *gong = new int[9];
		memset(row, 0, rrow*sizeof(int));
		memset(col, 0, ccol*sizeof(int));
		memset(gong, 0, 9*sizeof(int));
		int mask;
		for (int i = 0; i < rrow; i++)
		{
			for (int j = 0; j < ccol; j++)
			{
				if (board[i][j] == '.') continue;
				mask = 1 << (board[i][j] - '0');              
				int mid = j / 3 + i % 3 / 3;
				if ((mask & row[i]) || (mask &col[j]) || (mask & gong[mid]))
					return false;
				row[i] |= mask;
				col[j] |= mask;
				gong[mid ] |= mask;
			}
		}
		return true;
	}
};