#include "������.h"

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
	cout << "��ʼѰ��" << endl;
	while (cin >> first) {
		p = hash.find(first);
		if (p == hash.end()) {
			cout << "��\n";
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