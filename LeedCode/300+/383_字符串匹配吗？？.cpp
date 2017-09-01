#include <string>
using namespace std;



class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int *hash = new int[26]();
		for (int i = 0; magazine[i]; ++i) {
			++hash[magazine[i] - 'a'];
		}
		for (int i = 0; ransomNote[i]; ++i) {
			if (--hash[ransomNote[i] - 'a'] < 0) return false;
		}
		return true;
	}
};