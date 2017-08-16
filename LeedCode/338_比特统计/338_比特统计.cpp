#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> reverse(int num) {
		vector<int> count;
		count.push_back(0);
		for (int i=1;i<=num;i++)
		{
			count.push_back(count.at(i&(i - 1)) + 1);
		}
		return count;
	}
};
int main() {
	int x;
	cin >> x;

	Solution solution;
	vector<int> s=solution.reverse(x);
	for (vector<int>::iterator i = s.begin(); i != s.end(); ++i)
	{
		cout << *i << " ";
	}
	system("pause");
	return 0;
}

