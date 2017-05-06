#include<iostream>

class Solution {
public:
	int countPrimes(int n) {
		/*uint32_t *p = (uint32_t *)malloc(sizeof(uint32_t)*(n + 1));
		memset(p, 0, sizeof(uint32_t) * (n + 1));*/
		int *p = (int *)malloc(sizeof(int)*(n + 1));
		memset(p, 0, sizeof(int) * (n + 1));
		for (int i = 2; i < n; i++)
		{
			if (!p[i]) {
				p[++p[0]] = i;
			}
			for (int j =1; j <= p[0] && p[j]  * i <= n ; j++) {
				p[ i * p[j]] = 1;
				if(i % p[j] == 0)
					break;
			}
		}
		for (int i= 1; i <= n ;++i)
		{
		//if (p[i] == 0 || p[i] == 1)continue;
		std::cout <<i<< ":"<<p[i] << " ";
		}
		std::cout << std::endl;
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