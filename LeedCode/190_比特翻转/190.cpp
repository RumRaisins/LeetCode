#include<iostream>
using namespace std;


class Solution {
public:
	char g_convert[16] = { 0 ,8,4,12,2,10,6,14,1,9,5,13,3,11,7,5 };
	char convert(char c) {
		return (g_convert[c & 0x0f] << 4 | g_convert[c & 0xf0] >> 4);
	}
	void my_swap(char* a,char* b) {
		char c = *a;
		*a = *b;
		*b = c;
	}
	uint32_t reverseBits(uint32_t n) {
		char *ret = &n;
		my_swap(&ret[0], &ret[3]);
		my_swap(&ret[1], &ret[2]);
		ret[0] = convert(ret[0]);
		ret[1] = convert(ret[1]);
		ret[2] = convert(ret[2]);
		ret[3] = convert(ret[3]);
		return *((uint32_t *)ret);
	}
};