#include<iostream>

class Solution {
public:
	int countPrimes(int n) {
		int *p = (int*)malloc(sizeof(int)*(n + 1));
		memset(p, 0, sizeof(int) * (n + 1));
		for (int i = 2; i * i <= n; ++i)
		{
			if (p[i])continue;
			for (int j = i * i;j <= n; j += i)
				p[j] = 1;
		}
		for (int i =2 ; i <= n; ++i)
		{
			if (p[i])continue;
			p[++p[0]] = i;
		}
		/*for (int i= 1; i <= n ;++i)
		{
			if (p[i] == 0 || p[i] == 1)continue;
			std::cout << p[i] << " ";
		}
		std::cout << std::endl;*/
		return p[0];
	}
};


int main() {

	int n;
	std::cin >> n;
	Solution solution;
	std::cout << solution.countPrimes(n) << std::endl;

	system("pause");
	return 0;
}