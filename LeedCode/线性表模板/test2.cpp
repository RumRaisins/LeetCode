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
	cout << "�������һ��vector������������" << endl;
	cin >> n;
	while (n--) {
		cin >> temp;
		vec1.push_back(temp);
	}
	cout << "������ڶ���vector������������" << endl;
	cin >> n;
	while (n--) {
		cin >> temp;
		vec2.push_back(temp);
	}
	if (vec1 == vec2) {
		cout << "�����������" << endl;
	}
	else {
		cout << "�������鲻���" << endl;
	}
	cout <<"vec3 = vec1 + vec2  , ���vec3" <<endl;
	vec3 = vec1 + vec2;
	vec3.out();

	cout << "չʾ�ſ�Ч��" << endl;
	


	system("pause");
	return 0;

}