#include <iostream>
struct ListNode {
     int val;
     ListNode *next;     
ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (NULL == head) return head;
		ListNode ret(0);
		ret.next = head;
		ListNode *first = &ret, *last = &ret;
		while (n--) {
			first = first->next;
		}
		while (first->next) {
			first = first->next;
			last = last->next;
		}
		ListNode* delete_node = last->next;
		last->next = last->next->next;
		delete delete_node;
		return ret.next;
	}
};