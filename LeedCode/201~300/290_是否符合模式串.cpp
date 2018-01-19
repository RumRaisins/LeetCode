#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;
/*
class Solution {
public:
	string StringToMark(string& s) {
		int *mark = (int *)calloc(256, sizeof(int));
		for (int i = 0; s[i]; ++i) {
			if (mark[s[i]] == 0) {
				mark[s[i]] = i + 1;
			}
			s[i] = mark[s[i]] + '0';
		}
		delete[]mark;
		return s;
	}
	bool wordPattern(string pattern, string str) {
		string temp;
		vector<string> vec;
		int index;
		while (1) {
			temp = str.substr(0, str.find_first_of(" "));
			index = str.find_first_of(" ");
			if (index == -1) {
				vec.push_back(str);
				break;
			}
			vec.push_back(temp);
			str = str.substr(index + 1, str.find_last_not_of(" "));
		}
		if (pattern.length() != vec.size()) return false;
		unordered_map<char, string> map1;
		unordered_map<string, char> map2;
		
		int count = 0;
		for (int i = 0; pattern[i]; ++i) {
		
			if (map1.find(pattern[i]) == map1.end() && map2.find(vec[i]) != map2.end()) {
				map1[pattern[i]] = vec[i];
				map2[vec[i]] = pattern[i];
			}
			else if (map1[pattern[i]] != vec[i] || map2[vec[i]] != pattern[i]) {
				cout << map1[pattern[i]] << endl;
				cout << map2[vec[i]] << endl;
				cout << 2 << endl;
				return false;
			}

		}
		return true;
	}
};
*/
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<string, int > ss;
		unordered_map<char, int> ps;
		istringstream  in(str);
		int n = pattern.length(), i = 0;
		for (string temp; in >> temp; ++i) {
			//i == n , str ÖÐ ±Èpattern ¶à
			if (i == n || ps[pattern[i]] != ss[temp]) {
				return false;
			}
			ps[pattern[i]] = ss[temp] = i + 1;
		}
		return i == n;
	}
};
