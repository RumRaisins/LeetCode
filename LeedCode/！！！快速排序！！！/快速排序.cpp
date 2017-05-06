#include<iostream>
#include<vector>
using namespace std;
void qSort(vector<int>& vec,int i,int j) {
	if (j - i <= 1)return;
	if (j - i == 2) {
		if (vec[i] > vec[i + 1]) {
			swap(vec[i], vec[i + 1]);
			return;
		}
	} 
	int x = i, y = j;
	--j;
	int temp = vec[i];
	while (i < j) {
		while (i < j && vec[j] >= temp) --j;
		if (i < j) vec[i] = vec[j], ++i;
		while (i < j && vec[i] < temp) i++;
		if (i < j) vec[j] = vec[i],--j;
	}
	vec[i] = temp;
	qSort(vec, x, i);
	qSort(vec, i + 1, y);
	return;
}

int main() {
	vector<int> vec;
	vec.push_back(9);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(7);
	vec.push_back(5);
	qSort(vec, 0, 10);
	for (int i : vec) {
		cout << i << " ";
	}
	system("pause");
	return 0;
}