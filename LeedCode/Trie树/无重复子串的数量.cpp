#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 100010;
const int SIZE = 26;
const char BASE = 'a';

typedef struct TrieNode {
	char cdata;
	int is_terminal;
	struct TrieNode **data;
} TrieNode, *Trie;


TrieNode* new_node(const char data) {
	TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
	p->data = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
	p->cdata = data;
	for (int i = 0; i < SIZE; i++) {
		p->data[i] = NULL;
	}
	p->is_terminal = 0;
	return p;
}

void clear(Trie root) {
	for (int i = 0; i < 26; ++i) {
		if (!root->data[i])
			free(root->data[i]);
	}
	free(root);

}

void insert(Trie roots, char *s) {
	Trie root = roots;
	for (int i = 0; s[i]; ++i) {
		if (NULL == root->data[s[i] - BASE]) {
			root->data[s[i] - BASE] = new_node(s[i]);
		}
		root = root->data[s[i] - BASE];
	}
	root->is_terminal = 1;
}

void output(Trie root) {

}

void  col_number_of_childstring(char *s, Trie root, int* sum, int i) {
	printf("%d  %c  %d\n", *sum ,s[i] , i);
	if (s[i] == '\0') {
		printf("break\n");
		return;
	}
	if (root->data[s[i] - BASE]->cdata == root->cdata) {
		col_number_of_childstring(s, root->data[s[i] - BASE], sum , ++i);
	}
	else {
		++(*sum);
		col_number_of_childstring(s, root->data[s[i] - BASE], sum ,++i);
	}
}


int main() {
	char p[N];
	scanf("%s", p);
	Trie root;
	root = new_node('#');
	insert(root, p);
	int *sum = (int *)malloc(sizeof(int));
	*sum = 0;
	int i = 0;
	col_number_of_childstring(p, root, sum , i);
	printf("%d", *sum);
	clear(root);

	system("pause");
	return 0;
}