#include "Head.h"
#include <map>

#define max(a , b) a > b ? a : b
 

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> hash(256, -1);
		int max_length = 0, temp = -1;
		for (int i = 0; s[i]; ++i) {
			if (hash[s[i]] > temp) {
				temp = hash[s[i]];
			}
			hash[s[i]] = i;
			max_length = max(max_length, i - temp);
		}
		return max_length;
	}
};



int main() {

}
