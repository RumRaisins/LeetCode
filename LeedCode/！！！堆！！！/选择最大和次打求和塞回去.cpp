#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Zombie {
	int num;
	int normal_v;
	int distance;
};

void swap(Zombie *a, Zombie *b) {
	Zombie temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void heap_sort(Zombie *p, int n) {
	for (int i = 1; i < n; ++i) {
		int current = i;
		int father = (current - 1) / 2;
		while (p[current].distance > p[father].distance) {
			swap(&p[current], &p[father]);
			current = father;
			father = (current - 1) / 2;
		}
	}
	for (int i = n - 1; i >= 1; --i) {
		swap(&p[i], &p[0]);
		int l, r, max_index = 0;
		while (true) {
			l = 2 * max_index + 1;
			r = 2 * max_index + 2;
			if (l < i && p[l].distance > p[max_index].distance) {
				max_index = l;
			}
			if (r < i && p[r].distance > p[max_index].distance) {
				max_index = r;
			}
			if (max_index == l || max_index == r) {
				swap(&p[max_index], &p[(max_index - 1) / 2]);
			}
			else {
				break;
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int index = 1;
	while (n--) {
		int m;
		scanf("%d", &m);
		Zombie *zombies = (Zombie*)malloc(sizeof(Zombie) * m);
		for(int i = 0 ; i < m ; ++i){
			scanf("%d %d", &zombies[i].distance, &zombies[i].normal_v);
			zombies[i].num = i + 1;
		}
		printf("Case #%d:\n", index);
		while (m--) {
			heap_sort(zombies, m + 1);
			int last = m;
			while(zombies[last].distance == zombies[last - 1].distance) {
				if (zombies[last].num < zombies[last - 1].num) {
					break;
				}
				--last;
			}
			if (last == m) {
				printf("%d ", zombies[m].num);
			}
			else {
				swap(&zombies[last], &zombies[m]);
				printf("%d ", zombies[m].num);
			}
			for (int i = 0; i < m; i++) {
				zombies[i].distance += zombies[i].normal_v;
			}
		}
		++index;
		free(zombies);
		

	}
	system("pause");
	return 0;
}