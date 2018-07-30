/*
 * DLList.h
 *
 *  Created on: 2011-11-24
 *      Author: morin
 */

#ifndef DLLIST_H_
#define DLLIST_H_
#include <memory>

namespace mySTL {

template<class T>
class DLList {
protected:
	class Node {
	public:
		T x;
		std::shared_ptr<Node> prev, next;	// two pointers
	};
	std::shared_ptr<Node> dummy;	// acts as a placeholder (no head and tail required)
	//Node dummy;	// acts as a placeholder (no head and tail required)
				// Its next points the first node and its prev points to the last node
				// And the last node points to the dummy node
				// dummy.next = first node
				// dummy.prev = last node
	size_t n;
	void remove(std::shared_ptr<Node> w);
	void addBefore(std::shared_ptr<Node> w, T x);
	std::shared_ptr<Node> getNode(size_t i);
public:
	DLList();
	virtual ~DLList();
	size_t size() { return n; }
	T get(size_t i);
	T& operator[](size_t i) { return getNode(i)->x;	}

	T set(size_t i, T x);
	virtual void add(size_t i, T x);
	void push_back(T x) 	{ add(size(), x); }
	void push_front(T x) 	{ add(0, x); }	
	void remove(size_t i);
	void pop_back() 	{ remove(size()); }
	void pop_front() 	{ remove(size_t(0)); }
	virtual void clear();
};

template<class T>
DLList<T>::DLList() {
//	dummy.next = std::make_shared<Node>(&dummy);
//	dummy.prev = std::make_shared<Node>(&dummy);
	dummy = std::make_shared<Node>();
	dummy->next = dummy;
	dummy->prev = dummy;
	n = 0;
}

template<class T>
void DLList<T>::addBefore(std::shared_ptr<Node> w, T x) {
	std::shared_ptr<Node> u(new Node);
	u->x = x;
	u->prev = w->prev;	
	u->next = w;
    // Modify the previous connection to w
	u->next->prev = u; // w->prev=u
	u->prev->next = u; // previous->next points to u
	n++;
}

template<class T>
std::shared_ptr<typename DLList<T>::Node> DLList<T>::getNode(size_t i) {
	//Node* p;//=&dummy;
	std::shared_ptr<Node> p;
	if (i < n / 2) {	// start from the fist node in forward
		p = dummy->next;	// head node
		for (size_t j = 0; j < i; j++)
			p = p->next;
	} else {  			// start from the lst node in backward
		p = dummy;		//.prev; // tail node
		for (size_t j = n-i; j > 0; j--)
			p = p->prev;
	}
	return (p);
}


template<class T>
DLList<T>::~DLList() {
	clear();
}

template<class T>
void DLList<T>::clear() {
	//Node *u = dummy.next;
	std::shared_ptr<Node> u = dummy->next;
	while (u != dummy) {
		std::shared_ptr<Node> w = u->next;
		//delete u;
		u->prev=nullptr;
		u->next=nullptr;
		u = w;
	}
	n = 0;
}

template<class T>
void DLList<T>::remove(std::shared_ptr<Node> w) {
	w->prev->next = w->next;
	w->next->prev = w->prev;
	//delete w;
	n--;
}


template<class T>
T DLList<T>::get(size_t i) {
    return getNode(i)->x;
}

template<class T>
T DLList<T>::set(size_t i, T x) {
	//Node* u = getNode(i);
	std::shared_ptr<Node> u = getNode(i);
	T y = u->x;
	u->x = x;
	return y;
}

template<class T>
void DLList<T>::add(size_t i, T x) {
    addBefore(getNode(i), x);
}

template<class T>
void DLList<T>::remove(size_t i) {
	std::shared_ptr<Node> w = getNode(i);
	//T x = w->x;
	remove(w);
	//return x;
}


} /* namespace ods */
#endif /* DLLIST_H_ */
