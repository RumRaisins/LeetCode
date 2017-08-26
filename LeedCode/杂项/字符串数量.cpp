#include <stdlib.h>
#include <stdio.h>

#define SIZE 26
#define BASE 'a'

typedef struct Node {
	int is_end;
	struct Node **childs;
	struct Node *fail;
}Node, *Trie;

Trie new_node() {
	Trie p = (Trie)calloc(1, sizeof(Node));
	p->childs = (Trie *)calloc(SIZE, sizeof(Trie));
	return p;
}
int *insert(Trie root, char *buffer) {
	Trie p = root;
	for (int i = 0; buffer[i]; ++i) {
		if (p->childs[buffer[i] - BASE] == NULL) {
			p->childs[buffer[i] - BASE] = new_node();
		}
		p = p->childs[buffer[i] - BASE];
	}
	p->is_end = 1;
	return &p->is_end;
}

void build_automaton(Trie root) {
	root->fail = root;
	Trie p[1000];
	int l = 0, r = 0;
	p[r++] = root;
	while (l < r) {
		Trie now = p[l++];
			for (int i = 0; i < SIZE; ++i) {
				if (!now->childs[i]) {
					continue;
				}
				Trie child = now->childs[i];
				if (now == root) {
					child->fail = root;
				}
				else {
					Trie iter = now;
					while (iter != root && iter->fail->childs[i] == NULL) {
						iter = iter->fail;
					}
					if (iter->fail->childs[i] != NULL) {
						child->fail = iter->fail->childs[i];
					}
					else {
						child->fail = root;
					}
				}
				p[r++] = child;
			}
	}
}

void match(Trie root, char *buffer) {
	Trie p = root;
	for (int i = 0; buffer[i]; ++i) {
		while (p != root  && p->childs[buffer[i] - BASE] == NULL) {
			p = p->fail;
		}
		p = p->childs[buffer[i] - BASE];
		if(p == NULL) p = root;
		Trie iter = p;
		while (iter != root) {
			if (iter->is_end) {
				++iter->is_end;
			}
			iter = iter->fail;
		}

	}
}



void clear(Trie root) {
	if (!root) {
		return;
	}
	for (int i = 0; i < SIZE; ++i) {
		if (root->childs[i]) {
			clear(root->childs[i]);
		}
	}
	free(root->childs);
	free(root);
}

int main() {
	int n;
	scanf("%d", &n);
	char temp[100006];
	int **p = (int **)calloc(n , sizeof(int *));
	Trie root = new_node();
	for (int i = 0; i < n; ++i) {
		scanf("%s", temp);
		p[i] = insert(root, temp);
	}
	build_automaton(root);
	scanf("%s", temp);
	match(root, temp);
	for (int i = 0; i < n; ++i) {
		printf("%d: %d", i, *(p[i]));
		p[i] = insert(root, temp);
	}


	free(p);
	return 0;
}
