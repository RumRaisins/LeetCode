#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable {
	char **elem;
	int size;
} HashTable ,*pHash;


int charControl(char a) {
	if ('A' <= a && a <= 'Z') {
		return  a + 32;
	}
	return a;
}
void init(pHash h) {
	h->size = 100001;
	h->elem = (char **)malloc(h->size * sizeof(char *));
	for (int i = 0; i < h->size; ++i) {
		h->elem[i] = NULL;
	}
}

int hash(pHash h, char *value) {
	int code = 0;
	for (int i = 0; i < strlen(value); ++i) {
		code = (code * 256 + charControl(value[i]) + 128) % h->size;
	}
	return code;
}

int search(pHash h, char *value, int *pos, int *times) {
	*pos = hash(h, value);
	*times = 0;
	while (h->elem[*pos] != NULL && strcmp(h->elem[*pos], value) != 0) {
		++(*times);
		if (*times < h->size) {
			*pos = (*pos + 1) % h->size;
		}
		else {
			return 0;
		}
	}
	if (h->elem[*pos] != NULL && strcmp(h->elem[*pos], value) == 0) {
		return 1;
	}
	return 0;
}

int insert(pHash h, char *value) {
	int pos, times;
	if (search(h, value, &pos, &times)) {
		return 2;
	}
	else if (times < h->size / 2) {
		h->elem[pos] = (char *)malloc(strlen(value) + 1);
		strcpy(h->elem[pos], value);
		return 1;
	}
	else {
		return 0;
	}
}



void clear(pHash h) {
	for (int i = 0; i < h->size; ++i) {
		if (!h->elem[i]) {
			free(h->elem[i]);
		}
	}
	free(h->elem);
	free(h);
}

int main() {

	int n;
	scanf("%d", &n);
	char *p = (char*)malloc(sizeof(char) * 100);
	pHash hash = (pHash)malloc(sizeof(HashTable));
	init(hash);
	while (n--) {
		scanf("%s", p);
		int state = insert(hash, p);
		if (state == 2) {
			printf("Yes\n");
		}
		else if (state == 1) {
			printf("No\n");
		}

	}
	clear(hash);
	return 0;

}