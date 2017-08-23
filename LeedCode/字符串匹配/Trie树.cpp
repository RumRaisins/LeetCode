//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//const int N = 100010;
//const int SIZE = 26;
//const char BASE = 'a';
//
//typedef struct TrieNode {
//	char cdata;
//	int is_terminal;
//	struct TrieNode **data;
//} TrieNode, *Trie;
//
//
//Trie new_node(const char data) {
//	TrieNode* p = (TrieNode *)malloc(sizeof(TrieNode));
//	p->cdata = data;
//	p->data = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
//	for (int i = 0; i < SIZE; ++i) {
//		p->data[i] = NULL;
//	}
//	p->is_terminal = 0;
//	return p;
//}
//
//void clear(Trie root) {
//	if (!root) return;
//	for (int i = 0; i < 26; ++i) {
//		if (!root->data[i])
//			clear(root->data[i]);
//	}
//	free(root->data);
//	free(root);
//
//}
//
//void insert(Trie roots, char *s) {
//	Trie root = roots;
//	for (int i = 0; s[i]; ++i) {
//		if (NULL == root->data[s[i] - BASE]) {
//			root->data[s[i] - BASE] = new_node(s[i]);
//		}
//		root = root->data[s[i] - BASE];
//	}
//	root->is_terminal = 1;
//}
//
//int  col_number_of_childstring(Trie root) {
//	if (!root) return 0;
//	int sum = 0;
//	for (int i = 0; i < SIZE; ++i) {
//		if (NULL == root->data[i]) continue;
//		sum += col_number_of_childstring(root->data[i]);
//	}
//	return sum + 1;
//}
//void output(Trie root) {
//	if (!root) return;
//	printf("%c", root->cdata);
//	for (int i = 0; i < SIZE; ++i) {
//		if (NULL == root->data[i]) continue;
//		output(root->data[i]);
//	}
//}
/*************************************************************************
> File Name: Trie.cpp
> Author:
> Mail:
> Created Time: 2017年08月21日 星期一 09时45分35秒
************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>
using std::stack;



#define SIZE 26
#define MC(T ,n) (T *)malloc(sizeof(T) * n)
#define CC(T ,n) (T *)calloc(n ,sizeof(T))

typedef struct Node {
	int flag;
	struct Node *next[SIZE];
}Node;



Node *get_new_node() {
	Node *p = MC(Node, 1);
	for (int i = 0; i < SIZE; ++i) {
		p->next[i] = NULL;
	}
	p->flag = 0;
	return p;
}

int insert(Node *tree, char *str) {
	int cnt = 0;
	Node *p = tree;
	while (str[0]) {
		if (p->next[str[0] - 'a'] == NULL) {
			p->next[str[0] - 'a'] = get_new_node();
		}
		p = p->next[str[0] - 'a'];
		cnt++;
		++str;
	}
	p->flag = 1;
	return cnt;
}

void output(Node *root, char *str, int loc) {
	if (root->flag) {
		str[loc] = '\0';
		printf("%s\n", str);
	}
	for (int i = 0; i < SIZE; ++i) {
		if (NULL != root->next[i]) {
			str[loc] = i + 'a';
			output(root->next[i], str, loc + 1);
		}
	}
}
typedef struct outNode {
	Node *root;
	char *s;
	int status , loc , i;
}outNode;
outNode *init_outNode(outNode *p ,Node *root, char *str, int loc) {
	p->root = root;
	p->loc = loc;
	p->status = 0;
	p->s = str;
	p->i = 0;
	return p;
}
void outPutStack(Node *root, char *str, int loc) {
	stack<outNode> stack;
	outNode *p = (outNode *)malloc(sizeof(outNode));
	init_outNode(p, root, str, loc);
	stack.push(*p);
	while (!stack.empty()) {
		outNode *temp = &stack.top();
		switch (temp->status) {
		case 0:
			if (!temp->root || temp->root->flag) {
				temp->s[temp->loc] = '\0';
				printf("%s\n", temp->s);
				temp->i = 0;
				temp->status = 1;
			}
			else {
				temp->i = 0;
				temp->status = 1;
			}break;
		case 1:
			if (temp->i < SIZE) {
				temp->status = 2;
			}
			else {
				temp->status = 3;
			}break;
		case 2:
			if (NULL != temp->root->next[temp->i]) {
				temp->s[temp->loc] = temp->i + 'a';
				outNode *p = (outNode *)calloc(1 , sizeof(outNode));
				init_outNode(p, temp->root->next[temp->i], temp->s, temp->loc + 1);
				stack.push(*p);
				temp->i++;
				temp->status = 1;

			}
			else {
				temp->i++;
				temp->status = 1;
			}break;
		case 3:
			stack.pop();
			break;
		}
	}

}

void clear(Node *root) {
	if (!root) return;
	for (int i = 0; i < SIZE; ++i) {
		if (root->next[i]) {
			clear(root->next[i]);
		}
	}
	free(root->next);
	free(root);
}



int main() {
	int n, node_count = 0;
	Node *tree = get_new_node();
	char str[100];
	char str2[100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", str);
		node_count += insert(tree, str);
	}
	printf("\n");
	output(tree, str2, 0);
	printf("\n");
	outPutStack(tree, str2, 0);
	// clear(tree);

	system("pause");
	return 0;
}

