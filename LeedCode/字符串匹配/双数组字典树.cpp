/*************************************************************************
> File Name: ×ÖµäÊ÷×ªË«Êý×é×ÖµäÊ÷
> Author:    hug
> Mail:      hug@haizeix.com
> Created Time: Ò»  8/21 09:43:44 2017
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 26

#define MC(T, n) (T *)malloc(sizeof(T) * n)
#define CC(T, n) (T *)calloc(n, sizeof(T));

typedef struct Node {
	int flag;
	struct Node *next[26];
	struct Node *fail;
	struct Node *father;
	int index;
} Node;

typedef struct DANode {
	int base, check, fail;
} DANode;

Node *get_new_node() {
	Node *p = CC(Node, 1);
	return p;
};

void insert(Node *tree, char *str) {
	Node *p = tree;

	while (str[0]) {
		if (p->next[str[0] - 'a'] == NULL) {
			p->next[str[0] - 'a'] = get_new_node();
		}
		p = p->next[str[0] - 'a'];
		str++;
	}
	p->flag = 1;
}

void output(Node *tree, int ind, char *str) {
	for (int i = 25; i >= 0; i--) {
		if (tree->next[i] == NULL) continue;
		str[ind] = 'a' + i;
		output(tree->next[i], ind + 1, str);
	}
	str[ind] = '\0';
	if (tree->flag) {
		printf("%s\n", str);
	}
	return;
}

void clear(Node *tree) {
	if (tree == NULL) return;
	for (int i = 0; i < 26; i++) {
		clear(tree->next[i]);
	}
	free(tree);
	return;
}

int get_base_value(Node *tree, DANode *da_tree) {
	int base = 1;
	int flag = 1;
	while (flag) {
		flag = 0;
		base++;
		for (int i = 0; i < 26; i++) {
			if (tree->next[i] == NULL) continue;
			if (da_tree[base + i].check == 0) continue;
			flag = 1;
			break;
		}
	}
	return base;
}
int trie_transfer_da(Node *tree, int index, DANode *da_tree) {
	int base = da_tree[index].base;
	for (int i = 0; i < 26; i++) {
		if (tree->next[i] == NULL) continue;
		da_tree[base + i].check = tree->next[i]->flag ? -index : index;
	}
	int temp, max_index = index;
	for (int i = 0; i < 26; i++) {
		if (tree->next[i] == NULL) continue;
		da_tree[base + i].base = get_base_value(tree->next[i], da_tree);
		temp = trie_transfer_da(tree->next[i], base + i, da_tree);
		if (temp > max_index) max_index =	temp;
	}
	return max_index;
}
Node *__get_automaton_fail(Node *father, int index, Node *root) {
	if (father == root) return root;
	if (father->fail == NULL) {
		father->fail = __get_automaton_fail(father->father, father->index, root);
	}
	if (father->fail->next[index] != NULL) {
		return father->fail->next[index];
	}
	return __get_automaton_fail(father->fail, index, root);
}

void __build_automaton(Node *node, Node *root) {
	for (int i = 0; i < 26; i++) {
		if (node->next[i] == NULL) continue;
		node->next[i]->fail = __get_automaton_fail(node, i, root);
		__build_automaton(node->next[i], root);
	}
	return;
}

int main() {
	Node *tree = get_new_node();
	int n;
	char str[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		insert(tree, str);
	}

	DANode *da_tree = CC(DANode, 1000 * 26);


	da_tree[1].base = 2;
	int max_index = trie_transfer_da(tree, 1, da_tree);
	//printf("trie : %lu Byte\n", node_cnt * sizeof(Node));
	//printf("double array trie : %lu Byte\n", max_index * sizeof(DANode));
	//for (int i = 1; i <= max_index; i++) {
	//	printf("(%3d %3d %3d) ", i, da_tree[i].base, da_tree[i].check);
	//	if (i % 4 == 0) {
	//			printf("\n");
	//	}
	//}
	output(tree, 0, str);
	//clear(tree);
	return 0;
}
