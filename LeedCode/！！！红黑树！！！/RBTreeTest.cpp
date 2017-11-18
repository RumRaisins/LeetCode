#include "RBTree.h"
#include <string>

using namespace std;

int main() {
	RBTree<int, int> *temp = new RBTree<int, int>();
	temp->insert(make_pair(50, 0));
	temp->insert(make_pair(54, 0));
	temp->insert(make_pair(31, 0));
	temp->insert(make_pair(4, 2154));
	temp->insert(make_pair(6, 0));
	temp->insert(make_pair(9, 0));
	temp->insert(make_pair(8, 0));
	temp->insert(make_pair(2, 0));
	temp->inorder();


	auto *result = temp->find(4);
	if (result != temp->end()) {
		cout << "not fond" << endl;
	}
	else {
		cout << "find success!" << endl;
		cout << result->getsecond() << endl;
	}
	result = temp->find(25);
	if (result != temp->end()) {
		cout << "not fond" << endl;
	}
	else {
		cout << "find success!" << endl;
		cout << result->getsecond() << endl;
	}


	cout << "----------------------" << endl;
	temp->erase(make_pair(2, 0));
	temp->erase(make_pair(31, 0));
	temp->inorder();

	system("pause");
	return 0;
}