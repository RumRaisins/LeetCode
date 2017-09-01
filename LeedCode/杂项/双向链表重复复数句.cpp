
#include <iostream>
#include <bitset>
using namespace std;

typedef struct Node {
     int val;
    struct Node *pre;
     struct Node *next;
} ListNode;

void helpQsort(ListNode* head, ListNode* end) {
	if (head == NULL || head == end)
		return;
	ListNode* fast = head->next;
	ListNode* slow = head;
	int temp;
	while (fast != end) {
		if (fast->val <= head->val) {
			slow = slow->next;
			temp = slow->val;
			slow->val = fast->val;
			fast->val = temp;
		}
		fast = fast->next;
	}
	temp = head->val;
	head->val = slow->val;
	slow->val = temp;
	helpQsort(head, slow);
	helpQsort(slow->next, end);
}
ListNode* twoWayLinkListUnique(ListNode *head) {
	helpQsort(head, NULL);
	ListNode *current = head;
	while (current) {
		if (current->val == current->next->val) {
			ListNode *delete_node = current->next;
			if (delete_node->next != NULL) {
				delete_node->next->pre = current;
				current->next = delete_node->next;
				free(delete_node);
			}
			else {
				current->next = NULL;
				free(delete_node);
				break;
			}
		}
		current = current->next;
	}
	return head;
}