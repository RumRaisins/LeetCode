#include <iostream>
#define max(a , b) ((a) > (b) ? (a) : (b))
using std::cout;
using std::endl;
//������
class Monster {
private:
	//��ܻ��ѵ�ʱ�䣨���ӣ�
	int costMinTime;
	//����������
	int coinNum;
public:
	Monster(int costMinTime, int coinNum) :costMinTime(costMinTime), coinNum(coinNum) {}
	inline int getCostMinTime()const { return costMinTime; }
	inline int getCoinNum()const { return coinNum; }
	
};
//������������
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

	//˼·�� �ǳ��ǳ�����ı������⣬��һ���⣬��֪����  XD
	//��̬�滮�����⣨DP) ����Ҫ�ľ��Ƕ�̬ת�Ʒ��̵�ȷ��
	//�����Ķ�̬ת�Ʒ���Ϊ f[i][j] ���� ��ʣ��i�ֹ����ʣ��j��ô��ʱ���ʱ�����ܻ�õ�������Ƕ���
	//����Ȼf[i][j] = max(f[i -1][j] , f[i -1][j - monster[i].getCostMinTime() + monsters[i].getCoinNum())
	// �� ��ǰ������� = max���Ҳ����i������õ������� �� �Ҵ��i������õ������棩
	//����Ϊ f[i][j]��״ֻ̬����ǰһ��״̬f[i-1][j]�йأ����������һ����ά�������洢��Ϣ�������ǶԿռ��һ�ּ����˷ѣ�
	//����ֻ��Ҫ��һ��һά����Ϳ�������Ҫ��

	Monster *monsters = new Monster[6]{ {12,24}, {18,20},{19 ,20},{25,30},{10,23},{10,23} };
	cout << wonMaxCoin(monsters, 6, 40) << endl;
	delete[]monsters;
	return 0;
}