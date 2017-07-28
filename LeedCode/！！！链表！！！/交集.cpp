#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#ifdef DEBUG
#define log printf("%d\n",__LINE__)
#else
#define log 
#endif


typedef struct Node {
	int data;
	struct Node *next;
}Node, *LinkedList;

LinkedList create_Node(int data) {
	LinkedList p = (LinkedList)malloc(sizeof(Node));
	p->next = NULL;
	p->data = data;
	return p;
}
LinkedList insert(LinkedList head, Node *node, int index) {
	Node ret;
	ret.next = head;
	LinkedList p = &ret;
	while (NULL != p && index > 0) {
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
LinkedList SameNumber2list3(LinkedList list1, LinkedList list2) {
	LinkedList temp, list3 = NULL;
	int i = 0;
	while (NULL != list1 && NULL != list2) {
		if (list1->data > list2->data) {
			list2 = list2->next;
		}
		else if (list1->data < list2->data) {
			list1 = list1->next;
		}
		else {
			temp = create_Node(list1->data);
			list3 = insert(list3, temp, i++);
			list1 = list1->next;
			list2 = list2->next;
			log;
		}
	}
	return list3;
}
void output(LinkedList head2){
	LinkedList head = head2;
    while(NULL != head){
      printf("%d",head->data);  
      head = head->next;
	  if (head)
		  printf(" ");
    }
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
	int m, n, temp_num;
	LinkedList list1 = NULL, list2 = NULL, temp_list, list3 = NULL;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &temp_num);
		temp_list = create_Node(temp_num);
		list1 = insert(list1, temp_list, i);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &temp_num);
		temp_list = create_Node(temp_num);
		list2 = insert(list2, temp_list, i);
	}
	list3 = SameNumber2list3(list1, list2);
	clear(list1);
	clear(list2);
	output(list3);

	system("pause");
	return 0;


}