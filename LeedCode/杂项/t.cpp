#include <iostream>
#include <vector>

#define max(a , b) ((a) > (b) ? (a) : (b))
using std::cout;
using std::cin;
using std::endl;
using std::vector;


int findmaxmul(const vector<int>& nums) {
	//假定获得的数组 最少2个，不考虑1个或0个的情况
	if (nums.size() == 2) return nums.at(0) * nums.at(1);
	int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX; //分别是最大值，次大值 ， 最小值 和 次小值
	for (auto it : nums) {
		if (it > max1) {
			max1 = it;
			
		}
		else if (it > max2) {
			max2 = it;
		}
		//寻找次小值得时候后有些特殊
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
	//思路
	//寻找最大值，次大值 ， 最小值 和 次小值
	//求 max（最大值*次大值 ， 最小值 * 次小值）
	//寻找是O（n）的时间复杂度，O（1）的空间复杂深度

	int n;
	vector<int> nums; 
	while (cin >> n) {
		nums.push_back(n);
	}
	cout << findmaxmul(nums) << endl;
	return 0;
}