#include <algorithm>
#include <vector>


using std::vector;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& num) {
		sort(num.begin(), num.end());
		vector<vector<int> > ret;
		if (num.size() < 2) return ret;
		for (int i = 0; i < num.size() - 2; ++i) {
			int target = 0 - num[i];

			int head = i + 1, tail = num.size() - 1;
			while (head < tail) {
				if (num[head] + num[tail] == target) {
					ret.push_back({ num[i], num[head] , num[tail] });
					head++, tail--;
					while (head < tail && num[head] == num[head - 1]) ++head;
					while (head < tail && num[tail] == num[tail + 1]) --tail;
				}
				else if (num[head] + num[tail] > target) {
					tail--;
				}
				else {
					++head;
				}
			}

			while (i < num.size() && num[i] == num[i + 1]) ++i;
		}
		return ret;
	}
};