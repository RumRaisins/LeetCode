#include <iostream>
#include <vector>

#define max(a , b) ((a) > (b) ? (a) : (b))
using std::cout;
using std::cin;
using std::endl;
using std::vector;


int findmaxmul(const vector<int>& nums) {
	//�ٶ���õ����� ����2����������1����0�������
	if (nums.size() == 2) return nums.at(0) * nums.at(1);
	int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX; //�ֱ������ֵ���δ�ֵ �� ��Сֵ �� ��Сֵ
	for (auto it : nums) {
		if (it > max1) {
			max1 = it;
			
		}
		else if (it > max2) {
			max2 = it;
		}
		//Ѱ�Ҵ�Сֵ��ʱ�����Щ����
		if( it < min1) {
			min1 = it;
		}
		else if(it < min2){
			min2 = it;
		}
	}
	return max(max1 * max2, min1 * min2);

}

int main() {
	//˼·
	//Ѱ�����ֵ���δ�ֵ �� ��Сֵ �� ��Сֵ
	//�� max�����ֵ*�δ�ֵ �� ��Сֵ * ��Сֵ��
	//Ѱ����O��n����ʱ�临�Ӷȣ�O��1���Ŀռ临�����

	int n;
	vector<int> nums; 
	while (cin >> n) {
		nums.push_back(n);
	}
	cout << findmaxmul(nums) << endl;
	return 0;
}