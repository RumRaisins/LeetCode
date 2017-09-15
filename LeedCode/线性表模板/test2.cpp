#include <iostream>
#include <string>

#include "Array.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;




int main() {
	string oper;
	int n, temp;
	my_vector<int> vec1, vec2, vec3;
	cout << "请输入第一个vector的数据数量：" << endl;
	cin >> n;
	while (n--) {
		cin >> temp;
		vec1.push_back(temp);
	}
	cout << "请输入第二个vector的数据数量：" << endl;
	cin >> n;
	while (n--) {
		cin >> temp;
		vec2.push_back(temp);
	}
	if (vec1 == vec2) {
		cout << "两个数组相等" << endl;
	}
	else {
		cout << "两个数组不相等" << endl;
	}
	cout <<"vec3 = vec1 + vec2  , 输出vec3" <<endl;
	vec3 = vec1 + vec2;
	vec3.out();

	cout << "展示炫酷效果" << endl;
	


	system("pause");
	return 0;

}