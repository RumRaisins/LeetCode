/*************************************************************************
> File Name: 【主程序】模板实现的哈希表
> Author: hug
> Mail:   hug@haizeix.com
> Created Time: 日  9/17 08:36:32 2017
************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>
#include "23.h"
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using haizei::HashTable;
using std::unordered_map;

struct Point {
	int a, b;
};

template<>
struct std::hash<Point> {
	int operator()(const Point &p) {
		return p.a * p.b;
	}
};

struct HashPoint {
	int operator()(const Point &p) {
		return p.a * p.b;
	}
};

int main() {
	unordered_map<Point, int> umht;
	HashTable<Point, int, HashPoint> ht2;
	HashTable<string, int> ht;
	if (ht.find("world") == ht.end()) {
		cout << "there is no key named : world" << endl;
	}
	if (ht["world"] == 0) {
		cout << "there is no key named : world" << endl;
	}
	if (ht.find("world") == ht.end()) {
		cout << "there is no key named : world" << endl;
	}
	ht["hello"] = 1;
	ht["hello"]++;
	cout << ht["world"] << " " << ht["hello"] << endl;
	if (ht.find("world") == ht.end()) {
		cout << "there is no key named : world" << endl;
	}
	else {
		cout << "there is world key" << endl;
	}
	system("pause");
	return 0;
}