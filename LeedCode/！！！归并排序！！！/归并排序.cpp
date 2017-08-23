#include<iostream>
#include<vector>;
using namespace std;

void mergeSort(vector<int>& vec,int left ,int right,vector<int>& copy) {
	if (right - left <= 1) 
		return;
	if (right - left == 2) {
		if (vec[left] > vec[left+1]) {
			int temp = vec[left];
			vec[left] = vec[left + 1];
			vec[left + 1] = temp;		
		}
		return;
	}
	int mid = (left + right) >> 1;
	int low = left, high = mid, index = 0;
	mergeSort(vec, left, mid , copy);
	mergeSort(vec, mid , right, copy);	
	while (low < mid || high < right) {
		if (low == mid) {
			copy[index++] = vec[high++];
			continue;
		}
		if (high == right) {
			copy[index++] = vec[low++];
			continue;
		}
		vec[low] > vec[high] ? copy[index++] = vec[high++] : copy[index++] = vec[low++];
	}
	for (int k=0 ; k < index; k++)
	{
		vec[left + k] = copy[k];
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