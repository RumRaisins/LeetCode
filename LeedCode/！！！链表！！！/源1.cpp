#include <stdio.h>
#include <stdlib.h>

#define log printf("%d",__LINE__)

typedef struct Node {
	int data;
	struct Node* next, *prior;
}Linkedlist, *pLinkedlist;

pLinkedlist create_node(int data) {
	pLinkedlist node = (pLinkedlist)malloc(sizeof(Linkedlist));
	node->next = NULL;
	node->prior = NULL;
	node->data = data;
	return node;
}

pLinkedlist insert(pLinkedlist head, pLinkedlist node, int index) {
	Linkedlist ret;
	ret.next = head;
	pLinkedlist p = &ret;
	while (index > 0 && NULL != p) {
		p = p->next;
		--index;
	}
	if (NULL == p) {
		return ret.next;
	}
	node->next = p->next;
	p->next = node;
	return ret.next;
}

pLinkedlist singleToDouble(pLinkedlist head) {
	pLinkedlist front, last;
	front = head->next;
	last = head;
	while (front) {
		front->prior = last;
		front = front->next;
		last = last->next;
	}
	head->prior = last;
	last->next = head;
	head = last;
	return head;
}


void output(pLinkedlist head) {
	pLinkedlist current = head;
	while (current != head->next) {
		printf("%d ", current->data);
		current = current->prior;
	}
	printf("%d\n", current->data);
}
pLinkedlist search(pLinkedlist head, int target) {
	pLinkedlist p = head->next;
	while (p != head) {
		if (p->data == target)
			return p;
		p = p->next;
	}
	if (p->data == target) {
		return p;
	}
	printf("No data node\n");
	return NULL;

}

int main() {
	pLinkedlist head = NULL, p;
	int n, temp;
	/*scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &temp);
		p = create_node(temp);
		head = insert(head, p, i);
	}*/
	for (int i = 1; i < 150; ++i) {
		p = create_node(i);
		printf("%d ", p->data);
		head = insert(head, p, i - 1);
	}
	head = singleToDouble(head);
	while (~scanf("%d", &n)) {
		pLinkedlist current = search(head, n);
		output(current);
	}
	system("pause");
	return 0;
}