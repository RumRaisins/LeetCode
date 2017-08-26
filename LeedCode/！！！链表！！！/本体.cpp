#include <stdio.h>
#include <stdlib.h>


#ifdef DEBUG

#endif // DEBUG



typedef struct Node {
	int data;
	struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
	if (head == NULL) {
		if (index != 0) {
			printf("failed\n");
			return head;
		}
		head = node;
		printf("success\n");
		return head;
	}
	if (index == 0) {
		node->next = head;
		head = node;
		printf("success\n");
		return head;
	}
	Node *current_node = head;
	int count = 0;
	while (current_node->next != NULL && count < index - 1) {
		current_node = current_node->next;
		count++;
	}
	if (count == index - 1) {
		node->next = current_node->next;
		current_node->next = node;
		printf("success\n");
		return head;
	}
	printf("failed\n");
	return head;
}

void output(LinkedList head) {
	if (head == NULL) {
		return;
	}
	Node *current_node = head;
	while (current_node != NULL) {
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	printf("\n");
}

LinkedList delete_node(LinkedList head, int index) {
	if (head == NULL) {
		printf("success\n");
		return head;
	}
	Node* current_node = head;
	if (index == 0) {
		head = head->next;
		free(current_node);
		printf("success\n");
		return head;
	}
	int count = 0;
	while (current_node && count < index - 1) {
		current_node = current_node->next;
		count++;
	}
	if (count == index - 1 && current_node->next) {
		Node* delete_node = current_node->next;
		current_node->next = delete_node->next;
		free(delete_node);
		printf("success\n");
		return head;
	}
	printf("failed\n");
	return head;
}

LinkedList reverse(LinkedList head) {
	if (head == NULL)
		return head;
	Node* current_node, *next_node;
	current_node = head->next;
	head->next = NULL;
	while (current_node) {
		next_node = current_node->next;
		current_node->next = head;
		head = current_node;
		current_node = next_node;
	}
	return head;
}

void clear(LinkedList head) {
	Node *current_node = head;
	while (current_node != NULL) {
		Node *delete_node = current_node;
		current_node = current_node->next;
		free(delete_node);
	}
}

int main() {
	LinkedList linkedlist = NULL;
	int n;
	scanf("%d", &n);
	while (n--) {
		int m;
		scanf("%d", &m);
		switch (m) {
		case 1: {
			int m, n;
			scanf("%d %d", &m, &n);
			Node *node = (Node*)malloc(sizeof(Node));
			node->data = n;
			node->next = NULL;
			linkedlist = insert(linkedlist, node, m);
			break;
		}
		case 2: {
			output(linkedlist);
			break;
		}
		case 3: {
			int loc;
			scanf("%d", &loc);
			linkedlist = delete_node(linkedlist, loc);
			break;
		}
		case 4: {
			linkedlist = reverse(linkedlist);
			break;
		}

		}
	}
	return 0;
}