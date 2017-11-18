#pragma once

#include <iostream>
#include <cstdio>
#include <string>


using namespace std;

template<typename T, typename U>
class RBTree;

template<typename T, typename U>
struct RBTNode {
public:

	RBTNode() : lchild(NULL), rchild(NULL), father(NULL), black(0) {}
	RBTNode(T a, U b) :lchild(NULL),rchild(NULL),  data(a, b), father(NULL), black(0) {}
	RBTNode(pair<T ,U > p) : lchild(NULL) , rchild(NULL),data(p), father(NULL),black(0) {}


	inline T getfirst() const {
		return data.first;
	}
	inline U getsecond()const{
		return data.second;
	}
	inline T& setfirst() {
		return data.first;
	}
	inline U& setsecond() {
		return data.second;
	}
	inline RBTNode *getlchild_ptr() const {
		return lchild;
	}
	inline RBTNode*& setlchild_ptr() {
		return lchild;
	}
	inline RBTNode* getrchild_ptr() const {
		return rchild;
	}
	inline RBTNode*& setrchild_ptr() {
		return rchild;
	}
	inline int getblack() const {
		return black;
	}
	inline int& setblack() {
		return black;
	}

private:
	friend class RBTree<T,U>;

	pair<T, U> data;
	int black;
	RBTNode *lchild, *rchild;
	RBTNode *father;

};




template<typename T, typename U>
class RBTree {
public:
	

	RBTree() {
		init_NIL();
		data = NULL;
	}
	~RBTree() {

	}

	inline void insert(pair<T,U> key) {
		data = __insert(data, key);
	}
	inline void erase(pair<T, U> key) {
		data = __erase(data, key);
	}
	inline void inorder() {
		__inorder(data);
	}
	RBTNode<T, U> *& operator[](T first) {
		
	}
	RBTNode<T, U> *find(T target) {
		return __find(data, target);
	}
	RBTNode<T, U> *end()const {
		return NIL;
	}
private:

	RBTNode<T, U> *data;
	RBTNode<T, U> *NIL;

	inline void init_NIL(){
		NIL = new RBTNode<T,U>();
		NIL->lchild = NIL;
		NIL->rchild = NIL;
		NIL->data.first = 0;
	}
	RBTNode<T, U> *init(pair<T, U> key) {
		auto *temp = new RBTNode<T, U>(key);
		temp->lchild = temp->rchild = NIL;
		return temp;
	}


	RBTNode<T, U> *__insert(RBTNode<T, U> *node, pair<T, U> key);
	void __inorder(RBTNode<T, U> *node) {
		if (node == NULL || node == NIL) return;
		__inorder(node->lchild);
		char p[100];
		sprintf(p, "节点(颜色 ， 左孩子， 右孩子)    %d (%d , %d , %d)", node->data.first, node->black,node->lchild->data.first, node->rchild->data.first);
		cout <<  p << endl;
		__inorder(node->rchild);
	}
	RBTNode<T, U> *insert_maintain(RBTNode<T, U> *node);
	inline bool has_red_child(RBTNode<T, U> *node) {
		return node->lchild->black == 0 || node->rchild->black == 0;
	}
	inline RBTNode<T, U> *left_rotate(RBTNode<T, U> *node) {
		auto *temp = node->rchild;
		temp->father = node->father;
		node->father = temp;
		temp->lchild->father = node;
		node->rchild = temp->lchild;
		temp->lchild = node;
		return temp;
	}
	inline RBTNode<T, U> *right_rotate(RBTNode<T, U> *node) {
		auto *temp = node->lchild;
		temp->father = node->father;
		node->father = temp;
		temp->rchild->father = node;
		node->lchild = temp->rchild;
		temp->rchild = node;
		return temp;

	}


	RBTNode<T, U> *__find(RBTNode<T, U> *node, T target);

	RBTNode<T, U> *__erase(RBTNode<T, U> *node, pair<T, U> key);
	RBTNode<T, U> *erase_maintain(RBTNode<T, U>* node);
	inline RBTNode<T, U> *predecessor(RBTNode<T, U> *node) {
		auto *temp = node->lchild;
		while (temp->rchild != NIL) {
			temp = temp->rchild;
		}
		return temp;
	}
};

template<typename T, typename U>
RBTNode<T, U>* RBTree<T, U>::erase_maintain(RBTNode<T, U>* node) {
	//删除站在父亲节点想下看
	if (node->lchild->black != 2 && node->rchild->black != 2) return node;
	auto *lchild = node->lchild;
	auto *rchild = node->rchild;
	//双重黑 在父节点 ,叔节点为红色
	if (lchild->black == 2 && rchild->black == 0) {
		node = left_rotate(node);
		node->black = 1;
		node->lchild->black = 0;
		node->lchild = erase_maintain(node->lchild);
	}
	else if (rchild->black == 2 && node->lchild == 0) {
		node = right_rotate(node);
		node->black = 1;
		node->rchild->black = 0;
		node->rchild = erase_maintain(node->rchild);
	}
	else if (lchild->black == 2 && rchild->black == 1) {
		if (!has_red_child(rchild)) {
			rchild->black = 0;
			lchild->black = 1;
			node->black++;
			return node;
		}
		else if (rchild->rchild->black != 0) {
			node->rchild = right_rotate(node->rchild);
			node->rchild->black = 1;
			node->rchild->rchild->black = 0;
		}
		node = left_rotate(node);
		node->black = node->lchild->black;
		node->lchild->black = node->rchild->black = 1;
		node->lchild->lchild->black = 1;
	}
	else if (rchild->black == 2 && lchild->black == 1) {
		if (!has_red_child(lchild)) {
			lchild->black = 0;
			rchild->black = 1;
			node->black++;
			return node;
		}
		else if (lchild->lchild->black != 0) {
			node->lchild = left_rotate(node->lchild);
			node->lchild->black = 1;
			node->lchild->lchild->black = 0;
		}
		node = right_rotate(node);
		node->black = node->rchild->black;
		node->lchild->black = node->rchild->black = 1;
		node->rchild->rchild->black = 1;
	}
	return node;

}
template<typename T, typename U>
inline RBTNode<T, U>* RBTree<T, U>::__find(RBTNode<T, U>* node, T target)
{
	if (node == NIL || target == node->data.first) return node;
	if (node->data.first > target) {
		return __find(node->lchild, target);
	}
	else if (node->data.first < target) {
		return __find(node->rchild, target);
	}
	return node;

}
template<typename T, typename U>
RBTNode<T, U> *RBTree<T, U>::__erase(RBTNode<T, U> *node ,pair<T, U> key)
{
	if (node == NULL || node == NIL) return node;
	if (key.first > node->data.first) {
		node->rchild = __erase(node->rchild, key);
		node = erase_maintain(node);
	}
	else if (key.first < node->data.first) {
		node->lchild = __erase(node->lchild, key);
	}
	else {
		if (node->lchild == NIL && node->rchild == NIL) {
			NIL->black += node->black;
			delete node;
			return NIL;
		}
		else if (node->lchild == NIL || node->rchild == NIL) {
			auto *temp = (node->lchild != NIL) ? node->lchild : node->rchild;
			temp->black += node->black;
			temp->father = node->father;
			delete node;
			return temp;
		}
		else {
			auto *temp = predecessor(node);
			auto temp_pair = node->data;
			node->data = temp->data;
			temp->data = temp_pair;
			node->lchild = __erase(node->lchild, key);
			node = erase_maintain(node);
		}
	}
	if (node->father == NULL) {
		node->black = 1;
	}
	return node;
}



template<typename T, typename U>
RBTNode<T, U> *RBTree<T, U>::__insert(RBTNode<T, U> *node, pair<T, U> key)
{
	/*
	if (node == NULL || node == NIL) {
		RBTNode<T,U> *temp = init(key);
		temp->black = (node == NULL);
		return temp;
	}
	if (node->data == key) return node;
	if (node->data.first < key.first) {
		node->rchild = __insert(node->rchild, key);
		node->rchild->father = node;
		node = insert_maintain(node);
	}
	else {
		node->lchild = __insert(node->lchild, key);
		node->lchild->father = node;
		node = insert_maintain(node);
	}
	if (node->father == NULL) {
		node->black = 1;
	}
	return node;
	*/
	if (node == NULL || node == NIL) {
		RBTNode<T,U> *temp = init(key);
		temp->black = (node == NULL);
		return temp;
	}
	
	if (node->data.first == key.first) return node;
	if (node->data.first < key.first) {
		node->rchild = __insert(node->rchild, key);
		node->rchild->father = node;
		node = insert_maintain(node);
	}
	else {
		node->lchild = __insert(node->lchild, key);
		node->lchild->father = node;
		node = insert_maintain(node);
	}
	if (node->father == NULL) {
		node->black = 1;
	}
	return node;
}
template<typename T, typename U>
RBTNode<T, U>* RBTree<T, U>::insert_maintain(RBTNode<T, U>* node)
{
	/*
	//插入的调整站在祖父节点向下可能
	if (node->black == 0) return node;
	auto *lchild = node->lchild;
	auto *rchild = node->rchild;
	if (lchild->black && rchild->black) return node;
	if (!has_red_child(lchild) && !has_red_child(rchild)) return node;
	if (lchild->black == 0 && rchild->black == 0) {
		lchild->black = rchild->black = 1;
		node->black = 0;
		return node;
	}
	if (lchild->black == 0 && lchild->lchild->black == 0) {
		// LL
		node = right_rotate(node);
		node->lchild->black = 1;
	}
	else if (lchild->black == 0 && lchild->rchild->black == 0) {
		// LR
		node->lchild = left_rotate(node->lchild);
		node = right_rotate(node);
		node->lchild->black = 1;
	}
	else if (rchild->black == 0 && rchild->rchild->black == 0) {
		// RR
		node = left_rotate(node);
		node->rchild->black = 1;
	}
	else if (rchild->black == 0 && rchild->lchild->black == 0) {
		// RL
		node->rchild = right_rotate(node->rchild);
		node = left_rotate(node);
		node->rchild->black = 1;
	}
	return node;
	*/
	if (node->black == 0) return node;
	auto *lchild = node->lchild;
	auto *rchild = node->rchild;
	if (lchild->black && rchild->black) return node;
	if (!has_red_child(lchild) && !has_red_child(rchild)) return node;
	if (lchild->black == 0 && rchild->black == 0) {
		lchild->black = rchild->black = 1;
		node->black = 0;
		return node;
	}
	if (lchild->black == 0 && lchild->lchild->black == 0) {
		// LL
		node = right_rotate(node);
		node->lchild->black = 1;
	}
	else if (lchild->black == 0 && lchild->rchild->black == 0) {
		// LR
		node->lchild = left_rotate(node->lchild);
		node = right_rotate(node);
		node->lchild->black = 1;
	}
	else if (rchild->black == 0 && rchild->rchild->black == 0) {
		// RR
		node = left_rotate(node);
		node->rchild->black = 1;
	}
	else if (rchild->black == 0 && rchild->lchild->black == 0) {
		// RL
		node->rchild = right_rotate(node->rchild);
		node = left_rotate(node);
		node->rchild->black = 1;
	}
	return node;
}


