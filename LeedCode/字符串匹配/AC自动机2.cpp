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
	int flag , index;
	struct Node *next[SIZE];
	struct Node *fail;
	struct Node *father;

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
			p->next[str[0] - 'a']->father = p;
			p->next[str[0] - 'a']->index = str[0] - 'a';
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

Node *__get_automaton_fail(Node *father, int index, Node *root) {
	if (father == root) return root;
	if (father == NULL) {
		father->fail = __get_automaton_fail(father->father, father->index, root);
	}
	if (NULL != father->fail->next[index]) {
		return father->fail->next[index];
	}
	return __get_automaton_fail(father->fail, index, root);
}

void __build_automaton(Node *tree ,Node *root) {
	for (int i = 0; i < SIZE; ++i) {
		if (tree->next[i] == NULL) continue;
		tree->next[i]->fail = __get_automaton_fail(tree, i, root);
		__build_automaton(tree->next[i], root);
	}
}
void build_automaton(Node *tree) {
	__build_automaton(tree, tree);
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
	


	build_automaton(tree);

	system("pause");
	return 0;
}
