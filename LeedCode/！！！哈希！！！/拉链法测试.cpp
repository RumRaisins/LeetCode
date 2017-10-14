#include "拉链法.h"

using haizei::LinkedHashTable;
using haizei::Node;
int main() {
	string first,second;
	Node<string> *p;
	LinkedHashTable<string, string> hash;
	while (cin >> first) {
		if (first == "end") break;
		cin >> second;
		hash[first].insert(second);
	}
	cout << "开始寻找" << endl;
	while (cin >> first) {
		p = hash.find(first);
		if (p == hash.end()) {
			cout << "无\n";
		}
		else {
			while (p) {
				cout << p->data << " ";
				p = p->next;
			}
		}
	}
	return 0;

	

}