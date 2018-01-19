#include<vector>
using std::vector;

class Solution {
public:
	int candy(vector<int> &ratings) {
		std::vector<int> &v = ratings;
		int sum = 0, l = 0, r = 0, mid;
		while (r < v.size()) {
			while (r + 1< v.size() && v[r + 1] > v[r]) r++;
			mid = r;
			while (r + 1 < v.size() && v[r + 1] < v[r]) r++;
			int numl = mid - l + (l > 0 && v[l] > v[l - 1]);
			int numr = r - mid;
			sum += (1 + numl) * numl / 2;
			sum += (1 + numr) * numr / 2;
			sum += (numl > numr ? numl : numr) + !(l > 0 && v[l] > v[l - 1]);
			l = r + 1;
			r = l;
		}
		return sum;
	}
};