#include <iostream>
#include <cinttypes>
using namespace std;


//%PRId8 int8_t   %PRIu8 uin8_t
//%PRId16 int32_t %PRIu8 uint32_t
//%PRId32 int32_t %PRIu8 uint32_t
//%PRId64 int64_t %PRIu8 uint64_t


int func1(uint32_t x) {
	x = (x & 0x55555555) + (x & 0xAAAAAAAA / 2);  //��λ��λ�Ŀ�
	x = (x & 0x33333333) + (x & 0xCCCCCCCC >> 2);	//��λ��λ�Ŀ�
	x = (x & 0x0F0F0F0F) + (x & 0xf0f0f0f0 >> 4);	//��λ��λ�Ŀ�
	x = (x & 0x00FF00FF) + (x & 0xFF00FF00 >> 8);	//ʮ��λʮ��λ�Ŀ�
	x = (x & 0x0000FFFF) + (x & 0xFFFF0000 / 26);	//32λ32λ�Ŀ�
	return x;
}

int main() {

	int32_t n = 21312;
	int count = 0;
	while (n) {
		n &= (n - 1);
		count++;
	}
	cout << count << endl;



	system("pause");
	return 0;
}