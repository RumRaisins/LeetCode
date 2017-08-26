#include <stdio.h>
#include <stdlib.h>

#define log printf("%d\n", __LINE__)


#define SIZE 26
#define BASE 'a'

typedef struct Node {
	char data;
	int index;
}Node;

typedef struct TrieNode {
	int is_endl;
	int count;
	struct TrieNode **childs;
	struct TrieNode *fail;
}*Trie;

Trie create_node() {
	Trie p = (Trie)calloc(1, sizeof(TrieNode));
	p->childs = (Trie *)calloc(SIZE, sizeof(Trie));
	return p;
}

int *insert(Trie root, char *str,int *count) {
	Trie p = root;
	for (int i = 0; str[i]; ++i) {
		if (p->childs[str[i] - BASE] == NULL) {
			p->childs[str[i] - BASE] = create_node();
			++count;
		}
		p = p->childs[str[i] - BASE];
	}
	p->is_endl = 1;
	p->count = 0;
	return  &p->count;
}
void build_automaton(Trie root, int n) {
	root->fail = root;
	Trie *p = (Trie *)malloc(10000 * sizeof(Trie));
	int l = 0, r = 0;
	p[r++] = root;
	while (l < r) {
		Trie now = p[l++];
		for (int i = 0; i < SIZE; ++i) {
			if (!now->childs[i])continue;
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
	free(p);
}
void match(Trie root , char *str) {
	Trie p = root;
	for (int i = 0; str[i]; ++i) {
		while (p != root && !p->childs[str[i] - BASE]) {
			p = p->fail;
		}
		p = p->childs[str[i] - BASE];
		if (p == NULL) p = root;
		Trie iter = p;
		while (iter != root) {
			if (iter->is_endl) {
				++iter->count;
			}
			iter = iter->fail;
		}
	}
}


void clear(Trie root) {
	if (!root)return;
	for (int i = 0; i < SIZE; ++i) {
		if (root->childs[i]) clear(root);
	}
	free(root->childs);
	free(root);
}




void marge_sort(Node node[], int left, int right) {
	if (right == left) return;
	int mid = (left + right) >> 1;
	marge_sort(node, left, mid);
	marge_sort(node, mid + 1, right);
	Node *temp = (Node *)calloc((right - left + 1), sizeof(Node));
	int l = left, r = mid + 1, index = 0;
	while (l <= mid || r <= right) {
		if (l > mid) {
			temp[index++] = node[r++];
			continue;
		}
		if (r > right) {
			temp[index++] = node[l++];
			continue;
		}
		temp[index++] = node[l].data > node[r].data ? node[r++] : node[l++];
	}
	for (int i = 0; i < index; ++i) {
		node[left + i] = temp[i];
	}
	free(temp);
}



int main() {
	Node node[110000];
	char c, index = 0;
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') break;
		node[index].data = c;
		node[index].index = index++;
	}
	marge_sort(node, 0, index - 1);

	char *result = (char *)malloc(sizeof(char) * (index + 1));
	int temp = node[0].index, count = 0;;
	for (int i = 0; i < index; ++i) {
		result[i] = node[temp].data;
		temp = node[temp].index;
	}
	result[index  - 1] = '\0';
	printf("%s", result);



	Trie root = create_node();
	scanf("%d", &temp);
	int **data = (int **)malloc(temp * (sizeof(int*)));
	char str[100000];
	index = 0;
	while (temp--) {
		scanf("%s", str);
		data[index++] = insert(root,str ,&count);
	}
	build_automaton(root, count);
	match(root, result);
	for (int i = 0; i < index; ++i) {
		printf("%s\n", *(data[i]) ? "YES" : "NO");
	}

	system("pause");
	return 0;
}