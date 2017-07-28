#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

LARGE_INTEGER BegainTime;

LARGE_INTEGER EndTime;

LARGE_INTEGER Frequency;

class Solution {
public:
	string countAndSay1(int n) {
		if (n == 0) return "";
		string now = "1";
		while (--n) {		
			string temp = "";
			for (int i = 0; i < now.length(); ++i)
			{
				int counter = 1;
				while ((i + 1 < now.length()) && (now[i] == now[i + 1])) {
					++counter; ++i;
				}
				temp += to_string(counter) + now[i];
			}
			now = temp;
		}
		return now;
	}
	string countAndSay2(int n) {
		if (n == 0)return "";
		if (n == 1) return "1";
		string now = countAndSay2(n - 1);
		string temp;
		for (int i = 0; i < now.length(); ++i)
		{
			int counter = 1;
			while ((i + 1 < now.length()) && (now[i] == now[i + 1])) {
				++counter; ++i;
			}
			temp += to_string(counter) + now[i];
		}
		return temp;
	}
};

int main() {

	Solution sol;

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&BegainTime);
	sol.countAndSay1(6);
	QueryPerformanceCounter(&EndTime);
	double runtime = (double)(EndTime.QuadPart - BegainTime.QuadPart);
	cout << "循环用时:"<<runtime<<endl;

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&BegainTime);
	sol.countAndSay2(6);
	QueryPerformanceCounter(&EndTime);
	runtime = (double)(EndTime.QuadPart - BegainTime.QuadPart);
	cout << "递归用时:" << runtime << endl;


	system("pause");
	return 0;
}