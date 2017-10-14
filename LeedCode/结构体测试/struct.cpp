#include <iostream>
using namespace std;

struct X {
	X() = delete;
	X(const X &) = delete;
	X(int){}
};

struct Y1 {
	X x;
	Y1() = delete;
	Y1(const Y1&) = delete; 
};

struct Y2 {
	X x;
};
struct Y3 {
	X x;
	Y3() = default //因为X不存在默认构造函数，所以这里的default 就是没有 不存在的意思。
	Y3(const Y3 &) = delete;

};
struct Y4 {
	X x;
	Y4() = delete;
	Y4(const Y4&) = default; //因为X不存在默认构造函数，所以这里的default 就是没有 不存在的意思。
	Y4(int) :x{ 0 } {}
};

int main() {

	Y1 y1;
	Y2 y2;
	Y3 y3;


	Y4 y4{0};
	Y4 y5 = y4;


	return 0;
}