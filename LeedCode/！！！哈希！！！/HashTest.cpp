#include "À­Á´·¨.h"
#include <Windows.h>
#include <ctime>
#include <cstdlib>

using haizei::LinkedHashTable;
using haizei::Node;

static LinkedHashTable<int, int> hash;


DWORD WINAPI insert(LPVOID pM) {
	hash[rand()%5].insert(rand() % 100);
	cout << "insert" << endl;
	return 0;
}
DWORD WINAPI out(LPVOID pM) {
	cout << "find" << endl;
	Node<int> *p;
	p = hash.find(rand() % 5);
	if (p == hash.end()) {
		cout << "NULL" << endl;
		return 0;
	}
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}

int main() {
	srand(time(0));
	for (int i = 0; i < 100; i++) {
		HANDLE handle = CreateThread(NULL, 0, insert, NULL, 0, NULL);
	}
	//for (int i = 0; i < 100; i++) {
	//	HANDLE handle = CreateThread(NULL, 0, out, NULL, 0, NULL);
	//}
	//WaitForSingleObject(handle, INFINITE);
	Node<int> *p;
	Sleep(3000);
	for (int i = 0; i < 5; ++i) {
		if (hash.find(i) == hash.end()) {
			printf("NULL\n");
			continue;
		}
		p = hash.find(i);
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
	}
	system("pause");
	return 0;
}