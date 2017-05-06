#include<iostream>
#include<vector>;
using namespace std;

void mergeSort(vector<int>& vec,int i ,int j,vector<int>& copy) {
	if (j - i <= 1) 
		return;
	if (j - i == 2) {
		if (vec[i] > vec[i+1]) {
			int temp = vec[i];
			vec[i] = vec[i+1];
			vec[i+1] = temp;		
		}
		return;
	}
	int p2 = (i + j) >> 1;
	int p1 = i, p3 = p2, p4 = 0;
	mergeSort(vec, i, p2 , copy);
	mergeSort(vec, p2 , j, copy);	
	while (p1 < p2 || p3 < j) {
		if (p1 == p2) {
			copy[p4++] = vec[p3++];
			continue;
		}
		if (p3 == j) {
			copy[p4++] = vec[p1++];
			continue;
		}
		vec[p1] > vec[p3] ? copy[p4++] = vec[p3++] : copy[p4++] = vec[p1++];
	}
	for (int k=0 ; k < p4; k++)
	{
		vec[i+k] = copy[k];
	}
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
	vector<int> copy;
	copy.resize(10);
	mergeSort(vec, 0, 10, copy);

	for (int i : vec) {
		cout << i << " ";
	}

	system("pause");

	return 0;

}