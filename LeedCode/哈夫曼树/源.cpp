#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Pair {
	char data;
	float rate;
	int sign; //1为真节点，0为过渡节点
}pair, *pPair;

typedef struct Tree {
	pPair data;
	struct Tree *lchild, *rchild;
}*pTree;

void init(pTree p, float rate, int sign) {
	p = (pTree)malloc(sizeof(Tree));
	p->lchild = NULL;
	p->rchild = NULL;
	p->data = (pPair)malloc(sizeof(Pair));
	p->data->rate = rate;
	p->data->sign = sign;
}
void init(pTree p, pPair pair) {
	p = (pTree)malloc(sizeof(Tree));
	p->lchild = NULL;
	p->rchild = NULL;
	p->data = pair;
}

void qSort(pTree p, int left, int right) {
	int low, high;
	while (left < right) {
		Tree piv = p[left];
		low = left, high = right;
		while (low < high) {
			while (low < high && p[high].data->rate > piv.data->rate) --high;
			if (low < high) p[low++] = p[high];
			while (low < high && p[low].data->rate < piv.data->rate) ++low;
			if (low < high) p[high--] = p[low];
		}
		p[low] = piv;
		qSort(p, low + 1, right);
		right = low - 1;	
	}
}

int char2int(char target) {
	if (target == '#')return -1;
	return target - 'a';
}

pTree build(pTree p,int start ,int  index) {
	//printf("start:%d index:%d", start, index);
	if (start == index) {
		return p +start;
	}
	pTree left,right,root;
	
	root = (pTree)malloc(sizeof(Tree));
	root->data = (pPair)malloc(sizeof(Pair));
	left = (pTree)malloc(sizeof(Tree));
	right = (pTree)malloc(sizeof(Tree));
	*left = p [start];
	*right = p [start + 1];
	printf("L data:%c rate:%f    ", left->data->data, left->data->rate);
	printf("R data:%c rate:%f\n", right->data->data, right->data->rate);
	root->lchild = left;
	root->rchild = right;
	root->data->data = '#';

	root->data->rate = (left->data->rate + right->data->rate);
	root->data->sign = 0;
	for (int i = start + 1; i <= index; ++i) {
		if (i == index) {
			p[index] = *root;
			break;
		}
		if(root->data->rate  <= p[i + 1].data->rate){
			*(p + i) = *root;
			break;
		}
		else {
			p[i] = p[i + 1];
		}
	}
	build(p, start + 1 ,index);
}
//pTree build(pTree p, int start, int  index) {
//	if (start == index) {
//		return p + start;
//	}
//	pTree left = p +start, right = p + start + 1, root;
//
//	root = (pTree)malloc(sizeof(Tree));
//	root->data = (pPair)malloc(sizeof(Pair));
//	//left = (pTree)malloc(sizeof(Tree));
//	//right = (pTree)malloc(sizeof(Tree));
//	//*left = p[start];
//	//*right = p[start + 1];
//	printf("L data:%c rate:%f    ", left->data->data, left->data->rate);
//	printf("R data:%c rate:%f\n", right->data->data, right->data->rate);
//	root->lchild = left;
//	root->rchild = right;
//	root->data->data = '#';
//
//	root->data->rate = (left->data->rate + right->data->rate);
//	root->data->sign = 0;
//	for (int i = start + 1; i <= index; ++i) {
//		if (i == index) {
//			p[index] = *root;
//			break;
//		}
//		if (root->data->rate <= p[i + 1].data->rate) {
//			*(p + i) = *root;
//			break;
//		}
//		else {
//			p[i] = p[i + 1];
//		}
//	}
//	build(p, start + 1, index);
//}

void Hafuman(pTree root, char** temp, char buffer[], int depth) {
	if (!root) return;
	buffer[depth] = '0';
	Hafuman(root->lchild, temp, buffer, depth + 1);
	buffer[depth] = '1';
	Hafuman(root->rchild, temp, buffer, depth + 1);
	buffer[0] = depth;
	if (root->data->data != '#') {
		temp[root->data->data - 'a'] = (char*)malloc(sizeof(char) * 10);
		buffer[depth + 1] = '\0';
		for (int i = 0; i <= depth + 1; ++i) {
			temp[root->data->data - 'a'][i] = buffer[i];
		}
		printf("%c ,%d,code = %s\n",root->data->data,buffer[0], buffer + 1);
	}
	//if (!root) return;
	//buffer[buffer[0]++] = '0';
	//Hafuman(root->lchild, temp, buffer, depth + 1);
	//buffer[buffer[0] - 1] = '1';
	//Hafuman(root->rchild, temp, buffer, depth + 1);
	////buffer[0] = depth  + 1;
	//if (root->data->data != '#') {
	//	temp[root->data->data - 'a'] = (char*)malloc(sizeof(char) * 10);
	//	buffer[depth + 1] = '\0';
	//	for (int i = 0; i <= depth + 1; ++i) {
	//		temp[root->data->data - 'a'][i] = buffer[i];
	//	}
	//	printf("%c ,code = %s\n",root->data->data, buffer + 1);
	//}
	

}
void output(pTree p) {
	if (NULL == p) return;
	printf("%c %f\n", p->data->data, p->data->rate);
	output(p->lchild);
	output(p->rchild);
}



int main() {
	srand(time(0));
	pTree pair = (pTree)malloc(sizeof(Tree) * 27);
	//float rate;
	//int index = 0;
	/*while (scanf("%f", &rate) != EOF) {
		pair[index].data->data = 'a' + index;
		pair[index].data->rate= rate;
		pair[index++].data->sign = 1;

	}*/
	//printf("finish");
	//qSort(pair , 0, --index);
	for (int i = 0; i < 26; i++) {
		pair[i].data = (pPair)malloc(sizeof(Pair));
		pair[i].data->data = 'a' + i;

		pair[i].data->rate = rand() % 100;
		pair[i].data->sign = 1;
		pair[i].lchild = pair[i].rchild = NULL;
	}
	qSort(pair, 0, 25);
	pTree p = build(pair, 0 ,25);;
	output(p);
	char **temp = (char**)malloc(sizeof(char*) * 26);
	char *buffer = (char*)malloc(sizeof(char) * 20);
	buffer[0] = 0;
	Hafuman(p, temp, buffer, 0);

	for (int i = 0; i < 25; ++i) {
		char c = 'a' + i;
		printf("%c : %d, %s\n", c,temp[i][0], temp[i] + 1);
	}




	system("pause");
	return 0;
}