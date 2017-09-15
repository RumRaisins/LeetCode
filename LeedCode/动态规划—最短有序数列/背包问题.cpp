#include <stdio.h>
#include <vector>
using std::vector;
using std::pair;



int Bag(vector<pair<int, int> >& vec, int sum, int n) {
	if (n == 0) return 0;
	int max = 0 , temp = 0;
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i].first > sum) continue;
		temp = 0;
		temp += vec[i].first * vec[i].second;
		temp += Bag(vec, sum - vec[1].first, n - 1);
		if (temp > max) {
			max = temp;
		}
	}
	return max;
}

int main() {
	int sum, m;
	scanf_s("%d %d", &sum , &m);
	int i = m;
	vector<pair<int, int> > vec;
	while (i--) {
		pair<int, int> p;
		scanf_s("%d %d", &p.first, &p.second);
		vec.push_back(p);
	}
	printf("%d\n", Bag(vec, sum, m));
	system("pause");
	return 0;
}