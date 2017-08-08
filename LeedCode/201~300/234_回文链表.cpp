#include <iostream>
using namespace std;


struct ListNode {     
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void output(ListNode* head) {
	ListNode *current = head;
	while (current) {
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
}
class Solution {
public:
	ListNode* resver(ListNode* head) {
		ListNode *current_resver = new ListNode(head->val);
		ListNode *temp;
		ListNode *current_old = head->next;
		current_resver->next = NULL;
		while (current_old) {
			temp = new ListNode(current_old->val);
			temp->next = current_resver;
			current_resver = temp;
			current_old = current_old->next;
		}
		return current_resver;


	}
	bool isPalindrome(ListNode* head) {
		if (NULL == head) return true;
		ListNode *resverList = head;
		resverList = resver(resverList);
		while (NULL != head  && NULL != resverList) {
			output(head);
			output(resverList);
			if (head->val != resverList->val) {
				return false;
			}
			head = head->next;
			resverList = resverList->next;
		}
		return true;
	}
};

int main() {
	ListNode* head;
	ListNode* p = new ListNode(1);
	head = p;
	p->next = new ListNode(1);
	p = p->next;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(1);
	//output(head);
	Solution sol;
	/*for (int i = 0; i < 5; ++i) {
		p = new ListNode(i, p);
	}*/
	cout<<sol.isPalindrome(p);
	system("pause");
	return 0;
}