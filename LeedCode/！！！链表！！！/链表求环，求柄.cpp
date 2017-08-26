#include <iostream>

typedef struct Node {
    int val;
    struct Node *next;
} ListNode;



int linkedListCycleLength(ListNode *head) {
	if (!head) return 0;
	ListNode *slow = head;
	ListNode *first = head->next;
	if (!first) return 0;
	first = first->next;
	int count = 0, flag = 0;
	while (first != NULL) {
		if (first == slow) {
			if (flag) return count - 1;
			flag = 1;
			++count;
		}
		first = first->next;
		if (!first) return 0;
		first = first->next;
		slow = slow->next;
		if (count)++count;
	}
	return 0;
}
ListNode* linkedListCycleLinkedNode(ListNode *head) {
	int count = linkedListCycleLength(head);
	if (!count) return NULL;
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