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
		ListNode *head ,*list = new ListNode(0);
		head = list;
		int acc = 0, x, y ,sum;
		while (l1 != NULL || l2 != NULL) {
			x = (l1 == NULL) ? 0 : l1->val;
			y = (l2 == NULL) ? 0 : l2->val;
			sum = x + y + acc;
			acc = (sum >= 10 ? 1 : 0);
			list->next = new ListNode(sum - 10);
			list = list->next;
			if (NULL != l1)l1 = l1->next;
			if (NULL != l2)l2 = l2->next;
		}
		if (acc) {
			list->next = new ListNode(1);
		}
		return head->next;
	}
};
int main() {
	int n;
	ListNode *l1 = new ListNode(5);
	ListNode *l2 = new ListNode(5);
	Solution sol;
	ListNode *result = sol.addTwoNumbers(l1, l2);
	while (result) {
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}