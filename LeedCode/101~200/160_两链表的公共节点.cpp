#include <iostream>



struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA || headB) return NULL;
		ListNode* a = headA, *b = headB;
		int la = 0, lb = 0;
		while (a->next) {
			a = a->next;
			++la;
		}
		while (b->next) {
			b = b->next;
			++lb;
		}
		if (a != b) return NULL;
		a = headA, b = headB;
		if (la >= lb) {
			int cha = la - lb;
			while (cha--) {
				a = a->next;
			}
		}
		else {
			int cha = lb - la;
			while (cha--) {
				b = b->next;
			}
		}
		while (a || b) {
			if (a->val == b->val)
				return a;
			a = a->next;
			b = b->next;
		}
		return NULL;
	}
};