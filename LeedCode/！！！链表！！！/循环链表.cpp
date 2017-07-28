
#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
#define log printf("%d\n",__LINE__);
#else
#define log
#endif // DEBUG


typedef struct Node {
	int data;
	struct Node* next;
}Linkedlist, *pLinkedlist;

pLinkedlist create_node(int data) {
	pLinkedlist node = (pLinkedlist)malloc(sizeof(Linkedlist));
	node->next = NULL;
	node->data = data;
	return node;
}

pLinkedlist insert(pLinkedlist head, pLinkedlist node, int index) {
	if (NULL == head) {
		if (index != 0) {
			return head;
		}
		head = node;
		head->next = head;
		return head;
	}
	if (index == 0) {
		node->next = head->next;
		head->next = node;
		return head;
	}
	pLinkedlist current_node = head->next;
	int count = 0;
	while (current_node != head && count < index - 1) {
		current_node = current_node->next;
		++count;
	}
	if (count == index - 1) {
		node->next = current_node->next;
		current_node->next = node;
	}
	if (node == head->next) {
		head = node;
	}
	return head;
}

void output(pLinkedlist head) {
	if (head->next == head) {
		printf("%d\n", head->data);
		return;
	}
	pLinkedlist current_node = head->next;
	while (current_node != head) {
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	printf("%d", current_node->data);
	printf("\n");
}


int main() {
	pLinkedlist head = NULL, p;
	int m, n;
	scanf("%d %d", &m, &n);
	int temp;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &temp);
		p = create_node(temp);
		head = insert(head, p, i);
	}
	pLinkedlist current = head;
	while (--n) {
		current = current->next;
	}
	output(current);

	system("pause");
	return 0;
}
