
#include <iostream>
using namespace std;





// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int mini = 1, maxi = n,
		long long int mid;
		while (mini < maxi) {
			mid = mini + ((maxi - mini) >> 2);
			if (isBadVersion(mid)) {
				maxi = mid;
			}
			else {
				mini = (int)mid + 1;
			}
		}
		return mini;
	}
};