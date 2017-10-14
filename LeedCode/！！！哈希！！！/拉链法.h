

#include <iostream>
#include <string>
#include <bitset>
#include "23.h"


using std::pair;
using std::string;
using std::bitset;
using haizei::Hash;

#ifdef	_WIN32
#include <windows.h>
#include <winnt.h>
	#define __sync_lock_test_and_set(ap, b) InterlockedExchange((LONG volatile *) (ap), (b))
#endif // 

#define _WIN32


namespace haizei {

	template<typename T>
	struct Node {
		T data;
		struct Node *next;
		int flag = 0;
		Node(const T& data) : data(data) , next(NULL){}
		Node() :next(NULL) {}
		~Node() {
			delete next;
		}
		void insert(const T& a) {
			while (__sync_lock_test_and_set(&flag, 1));
			struct Node *p = this;
			while (p->next) {
				p = p->next;
			}
			p->next = new Node(a);
			flag = 0;
		}
	};


	template <typename KEY_T,typename VALUE_T ,typename HashFunc_T =Hash<KEY_T> >
	class LinkedHashTable {
	public:
		LinkedHashTable(int size = 100) :__size(size) {
			this->__data = new pair<KEY_T, Node<VALUE_T> >[this->__size];
			this->__map = new bool[this->__size]{ 0 };
			//this->__end = nullptr;
			bit = new short[this->__size]{ 0 };
		}
		~LinkedHashTable() {
			delete[] this->__data;
			delete[]this->__map;
			delete[]this->bit;
		}
		Node<VALUE_T> &operator [] (const KEY_T &key) {
			int index = this->__find(key);
			while (__sync_lock_test_and_set(&bit[index], 1)) {}
			this->__data[index].first = key;
			this->__map[index] = true;
			bit[index] = 0;
			return this->__data[index].second;		
		}
		Node<VALUE_T> *end() { return this->__end; }
	
		Node<VALUE_T> *find(const KEY_T &key) {
			int hash_code = this->__hash_func(key);
			int index = hash_code % this->__size;
			while (__sync_lock_test_and_set(&bit[index], 1)) {}
			if (!this->__map[index]) return this->__end;
			bit[index] = 0;
			return &this->__data[index].second;
		}
	private:
		int __size;
		pair<KEY_T, Node<VALUE_T> > *__data;
		bool *__map;
		//bitset<100> bit;
		short *bit;
		HashFunc_T __hash_func;
		Node<VALUE_T> *__end;

		int __find(const KEY_T &key) {
			int hash_code = this->__hash_func(key);
			int index = hash_code %this->__size;
			return index;
		}
	};




}
