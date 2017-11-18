#include <iostream>

typedef struct Node {
	int data;
	struct Node *next;
}Node, *LinkedList;


void helpQsort(Node* head, Node* end) {
	if (head == NULL || head == end)
		return;
	Node* fast = head->next;
	Node* slow = head;
	int temp;
	while (fast != end) {
		if (fast->data < head->data) {
			slow = slow->next;
			temp = slow->data;
			slow->data = fast->data;
			fast->data = temp;
		}
		fast = fast->next;
	}
	temp = head->data;
	head->data = slow->data;
	slow->data = temp;
	helpQsort(head, slow);
	helpQsort(slow->next, end);
}
