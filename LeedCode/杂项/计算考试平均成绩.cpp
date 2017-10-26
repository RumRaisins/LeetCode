#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;


int main() {
	int grade;
	string name;
	int n;
	cin >> n;
	map < string, priority_queue<int, vector<int>, less<int> > ,less<string> > list;
	map < string, float > list2;
	while (n--) {
		cin >> name >> grade;
		list[name].push(grade);
	}
	for (auto it : list) {
		int count = it.second.size() > 5 ? 5 : it.second.size();
		int sum = 0;
		for (int i = 0; i < count; ++i) {
			sum += it.second.top();
			it.second.pop();
		}

		list2[it.first] = sum / (float)count;
	}
	vector<pair<string, float> >vec(list2.begin(), list2.end());
	sort(begin(vec), end(vec), [=](pair<string, float> p1, pair<string, float>p2) {
		 if(p1.second > p2.second) return true;
		 if (p1.second == p2.second && p1.first < p2.first) return true;
		 return false;
	});
	for (auto it : vec) {
		cout << it.first << " " << fixed << setprecision(2) << it.second<< endl;
	}
	system("pause");
	return 0;
}