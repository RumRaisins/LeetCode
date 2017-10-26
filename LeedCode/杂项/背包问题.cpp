#include <iostream>
#define max(a , b) ((a) > (b) ? (a) : (b))
using std::cout;
using std::endl;
//怪物类
class Monster {
private:
	//打败花费的时间（分钟）
	int costMinTime;
	//掉落金币数量
	int coinNum;
public:
	Monster(int costMinTime, int coinNum) :costMinTime(costMinTime), coinNum(coinNum) {}
	inline int getCostMinTime()const { return costMinTime; }
	inline int getCoinNum()const { return coinNum; }
	
};
//怪物数组例子
int wonMaxCoin(Monster *monsters, int num,int time = 40) {
	int *f = new int[time + 1]();

	for (int i = 0; i < num; ++i) {
		for (int j = time; j >= 1; j--) {
			if (j >= monsters[i].getCostMinTime()) {
				f[j] = max(f[j], f[j - monsters[i].getCostMinTime()] + monsters[i].getCoinNum());
			}
		}
	}
	int n = f[time];
	delete[]f;
	return n;
	
}


int main() {

	//思路！ 非常非常经典的背包问题，我一读题，就知道了  XD
	//动态规划的问题（DP) 最重要的就是动态转移方程的确定
	//这道题的动态转移方程为 f[i][j] 代表 还剩下i种怪物，还剩下j这么多时间的时候，我能获得的最大金币是多少
	//很显然f[i][j] = max(f[i -1][j] , f[i -1][j - monster[i].getCostMinTime() + monsters[i].getCoinNum())
	// 即 当前最大收益 = max（我不打第i个怪物得到的收益 ， 我打第i个怪物得到的收益）
	//又因为 f[i][j]的状态只和他前一个状态f[i-1][j]有关，我们如果开一个二维数组来存储信息，无疑是对空间的一种极大浪费，
	//所以只需要开一个一维数组就可以满足要求。

	Monster *monsters = new Monster[6]{ {12,24}, {18,20},{19 ,20},{25,30},{10,23},{10,23} };
	cout << wonMaxCoin(monsters, 6, 40) << endl;
	delete[]monsters;
	return 0;
}