#include<iostream>
#include<list>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode* temp = NULL,*head;
		if (l1->val <= l2->val) {
			temp = l1;
			l1 = l1->next;
		}
		else {
			temp = l2;
			l2 = l2->next;
		}
		head = temp;
		while (l1 && l2) {
			if (l1->val >= l2->val) {
				temp->next = l2;
				l2 = l2->next;
			}
			else {
				temp->next = l1;
				l1 = l1->next;
			}
			temp = temp->next;
		}
		if (l1) {
			while (l1)
			{
				temp->next = l1;
				l1 = l1->next;
				temp = temp->next;
			}			
		}
		else {
			while (l2) {
				temp->next = l2;
				l2 = l2->next;
				temp = temp->next;
			}
		}	
		temp->next = NULL;
		return head;
	}
	ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
	ListNode* mergeTwoLists3(ListNode* l1, ListNode* l2) {
		if (!l1 || l2 && l1->val > l2->val) l1 += l2 - (l2 = l1);
		if (!l1) {
			l1->next = mergeTwoLists3(l1->next, l2);
		}
		return l1;
	}
};