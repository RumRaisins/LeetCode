#include <unordered_map> 
#include <string>
using namespace std;

class Solution {
public:
	typedef struct Node {
		int index, count;
		Node() :index(0),count(0){}
	}Node;
	int firstUniqChar(string s) {
		Node *node = new Node[26]();
		for (int i = 0; s[i]; ++i) {
			node[s[i] - 'a'].count++;
			node[s[i] - 'a'].index = i;
		}
		for (int i = 0; s[i]; ++i) {
			if (node[s[i]].count == 1)
				return node[s[i]].index;
		}
	}
};