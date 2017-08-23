#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 256
#define BASE 'a'
#define MAX_LEN 10000


typedef struct TrieNode {
	int is_end;
	struct TrieNode **childs;
	struct TrieNode *fail;

}TrieNode,*Trie;

Trie new_node() {
	Trie p = (Trie)malloc(sizeof(TrieNode));
	p->fail = NULL;
	p->childs = (Trie *)malloc(sizeof(Trie) * SIZE);
	for (int i = 0; i < SIZE; ++i) {
		p->childs[i] = NULL;
	}
	p->is_end = 0;
	return p;
}
		
void insert(Trie root, char *pattern){
	Trie p = root;
	for (int i = 0; pattern[i]; ++i) {
		if (p->childs[pattern[i] - BASE] == NULL) {
			p->childs[pattern[i] - BASE] = new_node();
		}
		p = p->childs[pattern[i] - BASE];
	}
	++p->is_end;
}

void match_build(Trie root ) {
	root->fail = root;
	Trie p[MAX_LEN];
	int l = 0, r = 0;
	p[r++] = root;
	while (l < r) {
		Trie now = p[l++];
		for (int i = 0; i < SIZE; ++i) {
			if (now->childs[i] != NULL) {
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
}

void match(Trie root, char *buffer ) {
	Trie p = root;
	for (int i = 0; buffer[i]; ++i) {
		while (p != root && p->childs[buffer[i] - BASE] == NULL) {
			p = p->fail;
		}
		p = p->childs[buffer[i] - BASE];
		if (p == NULL) p = root;
		Trie iter = p;
		while (iter != root) {
			if (iter->is_end) {
				printf("Yes\n");
				return;
			}
			//找到之后的操作
			iter = iter->fail;
		}
	}
	printf("No\n");
	return;
}
int match2(Trie root, char *buffer1, char *buffer2) {
	int *match = (int *)calloc(999002, sizeof(int));
	Trie p = root;
	for (int i = 0; buffer1[i]; ++i) {
		while (p != root && p->childs[buffer1[i] - BASE] == NULL) {
			p = p->fail;
		}
		p = p->childs[buffer1[i] - BASE];
		if (p == NULL) {
			p = root;
		}
		Trie iter = p;
		while (iter != root && iter != NULL) {
			if (iter->is_end) {
				match[i] = 1;
				printf("%d ", i);
			}
			iter = iter->fail;
		}
	}
	for (int i = 0; buffer2[i]; ++i) {
		while (p != root && p->childs[buffer2[i] - BASE] == NULL) {
			p = p->fail;
		}
		p = p->childs[buffer2[i] - BASE];
		if (p == NULL) p = root;
		Trie iter = p;
		while (iter != root) {
			if (iter->is_end && match[i]) {
				return i - 1;
			}
			iter = iter->fail;
		}
	}
	return 0;
}
void build_automaton(Trie root) {
	root->fail = root;
	TrieNode *q[MAX_LEN];
	int l = 0, r = 0;
	q[r++] = root;
	while (l < r) {
		TrieNode *now = q[l++];
		for (int i = 0; i < SIZE; ++i) {
			if (now->childs[i] != NULL) {
				TrieNode *child = now->childs[i];
				if (now == root) {
					child->fail = root;
				}
				else {
					TrieNode *iter = now;
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
				q[r++] = child;
			}
		}

	}
}

void clear(Trie root) {
	if (!root)return;
	for (int i = 0; i < SIZE; ++i) {
		if (root->childs[i])
			clear(root->childs[i]);
	}
	free(root->childs);
	free(root);
}

int main() {
	
	char buffer1[MAX_LEN], buffer2[MAX_LEN], pattern[1009];
	char temp;
	int index1 = 0, index2 = 0, index3 = 0;
	while (scanf("%c", &temp) != EOF) {
		if (temp == '\n') {
			buffer1[index1] = '\0';
			break;
		}
		buffer1[index1++] = temp;
	}
	while (scanf("%c", &temp) != EOF) {
		if (temp == '\n') {
			buffer2[index2] = '\0';
			break;
		}
		buffer2[index2++] = temp;
	}
	while (scanf("%c", &temp) != EOF) {
		if (temp == '\n') {
			pattern[index3] = '\0';
			break;
		}
		pattern[index3++] = temp;
	}
	Trie root = new_node();
	insert(root, pattern);
	match_build(root);
	//match(root, buffer1);
	printf("%d", match2(root,buffer1,buffer2));
	system("pause");
	return 0;

}