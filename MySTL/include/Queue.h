/*
 * Deque.h
 *
 *  Created on: 2011-11-23
 *      Author: morin
 */

#ifndef DEQUE
#define DEQUE
#include "Deque.h"

namespace mySTL {

template<class T>
class Queue : public Deque<T> {	// Deque
protected:
	
public:
	Queue() {};
	~Queue() {};
	void push(T x) { Deque<T>::push_front(x); }
	void pop() { Deque<T>::pop_back(); }
	void front() { return Deque<T>::operator[](0); }
	void back() { return Deque<T>::operator[]((this->size()-1)); }
};

} /* namespace ods */
#endif /* DUALARRAYDEQUE_H_ */
