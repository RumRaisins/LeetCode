/*************************************************************************
> File Name: TypeofStack.cpp
> Author:
> Mail:
> Created Time: 2017年08月18日 星期五 08时45分34秒
************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>
using std::stack;

#define OK 1
#define ERROR 0



#define init_stack(s,n,T) (__init_stack(s ,n ,sizeof(T)))
#define push_stack(s ,value) ({\
    __typeof(value) __temp = value;\
    __push_stack(s, (const char *)(&(__temp)));\
})
#define empty_stack(s)(__empty_stack(s))
#define pop_stack(s)(__pop_stack(s))
#define top_stack(s,T) (*((T *)__top_stack(s)))
#define clear_stack(s)(__clear_stack(s))

typedef struct Stack {
	char *data;
	int top, size;
	int value_size;
}Stack;

typedef struct Node {
	int val;
	struct Node *lchild, *rchild;
}Node;
void __init_stack(Stack *s, int n, int value_size);
int __push_stack(Stack *s, const char *value);
int __empty_stack(Stack *s);
int __pop_stack(Stack *s);
char *__top_stack(Stack *s);
void __clear(Stack *s);




int __preorder(Node *root){
// if(!root) return 1;
printf("%d " , root->val);
// root->lchild && __preorder(root->lchild);
// root->rchild && __preorder(root->rchild);
return 1;
}
//树的非递归遍历
typedef struct PreorderArgs{
	Node *root;
	int status;
}PreorderArgs;
int preorder(Node *root) {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	init_stack(s, 1000, PreorderArgs);
	PreorderArgs pa;
	pa.root = root;
	pa.status = 0;
	push_stack(s, pa);
	while (!empty_stack(s)) {
		PreorderArgs* tpa = &top_stack(s, PreorderArgs);
		switch (tpa->status) {
		case 0:
			if (tpa->root == NULL) {
				tpa->status = 4;
			}
			else {
				tpa->status = 1;
			}
			break;
		case 1:
			__preorder(tpa->root);
			tpa->status = 2;
			break;
		case 2:
			if (tpa->root->lchild) {
				pa.root = tpa->root->lchild;
				pa.status = 0;
				push_stack(s, pa);
			}
			tpa->status = 3;
			break;
		case 3:
			if (tpa->root->rchild) {
				pa.root = tpa->root->rchild;
				pa.status = 0;
				push_stack(s, pa);
			}
			tpa->status = 4;
			break;
		case 4:
			pop_stack(s);
			break;
		default:
			printf("ERROR\n");
		}
	}
	return 1;
}

//快速排序的非递归
int qsort(int *data, int l, int r) {
	int low = 0, high = l - 1;
	while (l < r) {
		int piv = data[low];
		while (low < high) {
			while (low < high && data[high] > piv) --high;
			if (low < high) data[low++] = data[high];
			while (low < high && data[low] < piv) ++low;
			if (low < high) data[high--] = data[low];
		}
		data[low] = piv;
		qsort(data, low + 1, l);
		r = low - 1;
	}
}
int qsort_low(int *data, int l, int r) {
	//0 : if(l >= r)return;
	int low = l, high = l - 1, piv;
	while (low < high) {
		piv = data[low];
		while (low < high && data[high] >= piv) --high;
		if (low < high) data[low++] = data[high];
		while (low < high && data[low] <= piv) ++low;
		if (low < high)data[high--] = data[low];
	}
	data[low] = piv;
	return low;
	//2: qsort_low(data,l ,low - 1);
	//3: qsort_low(data ,low + 1, r);
	// return;
}
typedef struct qsortNode {
	int *data;
	int l, r, x;
	int status;
}qsortNode;
int qsort2(int *data, int l, int r) {
	Stack* s = (Stack *)malloc(sizeof(Stack));
	init_stack(s, 1000, qsortNode);
	qsortNode pa;
	pa.data = data;
	pa.l = l, pa.r = r - 1;
	pa.status = 0;
	push_stack(s, pa);
	while (!empty_stack(s)) {
		qsortNode *temp = &top_stack(s, qsortNode);
		switch (temp->status) {
		case 0:
			if (temp->l >= temp->r) {
				temp->status = 4;
			}
			else {
				temp->status = 1;
			}
			break;
		case 1:
			pa.x = qsort_low(temp->data, temp->l, temp->r) - 1;
			pa.status = 2;
			break;
		case 2:
			qsortNode a;
			a.data = temp->data;
			a.l = temp->l;
			a.r = temp->x - 1;
			push_stack(s, a);
			pa.status = 3;
			break;
		case 3:
			qsortNode a;
			a.data = temp->data;
			a.l = temp->x + 1;
			a.r = temp->r;
			push_stack(s, a);
			pa.status = 4;
			break;
		case 4:
			pop_stack(s);
		}
	}
}

//归并排序的非递归
void merge_sort(int *data, int left, int right, int *temp) {
	if( right < left ) return ;
	int mid = (left + right) >> 1, index = 0;
	int low = left, high = mid;
	merge_sort(data ,  left , mid ,temp);
	merge_sort(data , mid ,right ,temp);
	while (low < mid || high < right) {
		if (low < mid && (high >= right || data[low] <= data[high])) {
			temp[index++] = data[low++];
			continue;
		}
		else {
			temp[index++] = data[high++];
		}
	}
	for (int i = 0; i < index; i++) {
		data[left + i] = temp[i];
	}
	return;
}
void merge_sort2(int *data, int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	merge_sort2(data, l, mid);
	merge_sort2(data, mid + 1, r);
	int *temp = (int*)malloc(sizeof(int) * (r - l + 1));
	int x = l, y = mid + 1, loc = 0;
	while (x <= mid || y <= r) {
		if (x <= mid && (y > r || data[x] <= data[y])) {
			temp[loc++] = data[x++];
		}
		else {
			temp[loc++] = data[y++];
		}
	}
	for (int i = l; i <= r; ++i) {
		data[i] = temp[i - l];
	}
}
typedef struct MergeNode {
	int *data, *temp;
	int l, r, mid;
	int status;
}MergeNode;
void init_MergeNode(MergeNode *p, int *data, int l, int r, int *temp) {
	p->data = data;
	p->temp = temp;
	p->l = l;
	p->r = r;
	p->mid = (l + r) >> 1;
	p->status = 0;
}
void noStackMergeSort(int *data, int l, int r, int*temp) {
	Stack* s = (Stack *)malloc(sizeof(Stack));
	init_stack(s, 1000, MergeNode);
	MergeNode pa;
	init_MergeNode(&pa, data, l, r, temp);
	push_stack(s, pa);
	while (!empty_stack(s)) {
		MergeNode *temp = &top_stack(s, MergeNode);
		switch (temp->status) {
		case 0:
			if (temp->l >= temp->r) {
				temp->status = 4;
			}
			else {
				temp->status = 1;
			}
			break;
		case 1:
			MergeNode temp_MergeNode;
			init_MergeNode(&temp_MergeNode, temp->data, temp->l, temp->mid, temp->temp);
			push_stack(s, temp_MergeNode);
			temp->status = 2;
			break;
		case 2:
			MergeNode a;
			init_MergeNode(&a, temp->data, temp->mid, temp->r, temp->temp);
			push_stack(s, a);
			temp->status = 3;
			break;
		case 3:
			merge_sort(temp->data, temp->l, temp->r, temp->temp);
			temp->status = 4;
			break;
		case 4:
			pop_stack(s);
			break;

		}
	}
}



//
class Solution {
public:

	bool isSameTree1(TreeNode* p, TreeNode* q) {
		//0 ：if (p == NULL && q == NULL) return true;
		//1 :if (p == NULL && q != NULL) return false;
		//   if (p != NULL && q == NULL) return false;
		//   if (p->val^q->val) return false;
		//2 ：return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
	typedef struct SameTree {
		TreeNode *p, *q;
		int state;
	}SameTree;
	bool isSameTree(TreeNode* p, TreeNode* q) {
		Stack s;
		init_stack(s, 1000, SameTree);
		SameTree temp;
		temp.p = p, temp.q = q;
		temp.state = 0;
		push_stack(s ,temp);
		bool result = true;
		while (!empty_stack(s)) {
			SameTree *t = &top_stack(s,SameTree);
			switch (t->state) {
				case 0:
					if (t->p == NULL && t->q == NULL) {
						result = result && true;
						pop_stack(s);
					}
					else {
						t->state = 1;
					}break;
				case 1:
					if ((p == NULL && q != NULL) || (p != NULL && q == NULL) || (p->val^q->val)) {
						result = result && false;
						return false;
						pop_stack(s);
					}
					else {
						t->state = 2;
					}break;
				case 2:
					SameTree a , b;
					a.p = t->p->left;
					a.q = t->q->left;
					a.state = 0;
					b.p = t->p->right;
					b.q = t->q->right;
					b.state = 0;
					push_stack(s, a);
					push_stack(s, b);
					break;

			}
		}
	}

};




int main() {
	/*
	Stack *s = (Stack *)malloc(sizeof(Stack));
	init_stack(s, 100 ,double);
	push_stack(s, 1.256321);
	push_stack(s, 1.34631);
	push_stack(s, 1.524653);
	while(!empty_stack(s)){
	printf("%lf\n" , top_stack(s,double));
	pop_stack(s);
	}
	*/
	int data[10] = { 5,8,3,1,2,4,9,0,6,7 };
	int temp[10];
	noStackMergeSort(data, 0, 10, temp);
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	return 0;

}








void __init_stack(Stack *s, int n, int value_size) {
	s->data = (char *)malloc(value_size * n);
	s->top = -1;
	s->size = n;
	s->value_size = value_size;

}
int __push_stack(Stack *s, const char *value) {
	if (s->top + 1 == s->size) {
		return ERROR;
	}
	++(s->top);
	memcpy(s->data + s->top * s->value_size, value, s->value_size);
	return OK;
}
int __empty_stack(Stack *s) {
	return s->top == -1;
}
int __pop_stack(Stack *s) {
	if (__empty_stack(s)) {
		return ERROR;
	}
	--(s->top);
}
char *__top_stack(Stack *s) {
	if (__empty_stack(s)) {
		return NULL;
	}
	return s->data + s->top * s->value_size;
}

void __clear(Stack *s) {
	free(s->data);
	free(s);
}
