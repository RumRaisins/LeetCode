#include <vector>
using std::vector;


class Solution {
public:
	void __combine(int start, int n, int k, vector<vector<int> > & result, vector<int> temp) {
		if (k == 0) {
			result.push_back(temp);
			return;
		}
		for (int i = start; i <= n; ++i) {
			temp.push_back(i);
			__combine(i + 1, n, k - 1, result, temp);
			temp.pop_back();
		}
	}
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		for (int i = 1; i <= n; ++i) {
			vector<int> temp;
			temp.push_back(i);
			__combine(i + 1, n, k - 1, result, temp);
		}
		return result;

	}
};


class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		if (k == 0) return result;
		if (k == 1) {
			for (int i = 1; i <= n; ++i) {
				result.push_back({ i });
			}
			return result;
		}

		for (int i = 1; i < n - k + 1; ++i) {
			vector<vector<int> > temp = combine(n - i, k - 1);
			for (int j = 0; j < temp.size(); ++j) {
				result[j].push_back(n - i + 1);
			}
		}
		return result;
	}

};