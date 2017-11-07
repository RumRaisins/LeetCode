#include <iostream>

typedef struct Node {
    int val;
    struct Node *next;
} ListNode;



int linkedListCycleLength(ListNode *head) {
	ListNode *slow = head;
	ListNode *first = head;
	int count = 0, flag = 0;
	while (first && first->next) {
		first = first->next->next;
		slow = slow->next;
		if (first == slow){
			if (flag) return count - 1;
			flag = 1;
			++count;
		}
		if (count)++count;
	}
	return -1;
}
ListNode* linkedListCycleLinkedNode(ListNode *head) {
	int count = linkedListCycleLength(head);
	if (count < 0) return NULL;
	ListNode *first = head, *slow = head;
	while (count--) {
		first = first->next;
	}
	while (first != slow) {
		first = first->next;
		slow = slow->next;
		if (first == slow) {
			return first;
		}
	}
	return first;
}