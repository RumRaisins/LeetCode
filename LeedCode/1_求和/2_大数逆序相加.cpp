#include"Head.h"
using namespace std;


struct ListNode {
    int val;   
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1&&l2) return nullptr;
		ListNode *result = new ListNode(0);
		ListNode *head = result;
		int acc = 0;
		while (l1->next && l2->next) {
			int temp = l1->val + l2->val + acc;
			if (temp >= 10) {
				acc = 1;
				temp %= 10;
			}
			else
				acc = 0;
			ListNode newNode(temp);
			result -> next = &newNode;
			result = result->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1->next) {
			l1->next->val += acc;
			result = l1->next;
		}
		if (l2->next) {
			l2->next->val += acc;
			result = l2->next;
		}
		return head;
		
	}
};
int main() {
	int n;
	cin >> n;
	ListNode *l1 = new ListNode(n);
	ListNode *head = l1;
	while (cin >> n) {
		ListNode newNode(n);
		l1->next = &newNode;
		l1 = l1->next;
	}
	while (head->next != nullptr) {
		cout << head->val << " ";
		head = head->next;
	}


	system("pause");
	return 0;
}