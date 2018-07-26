/*
 * array.h
 *
 *  Created on: 2011-11-24
 *      Author: morin
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>
#include <new>

namespace mySTL {
/**
 * A simple array class that simulates Java's arrays implementation - kind of
 * TODO: Make a reference-counted version so that the = operator doesn't have
 * to destroy its right-hand side.
 */
template<class T>
class Stack {
protected:
	T *a;  	// pointer to array
	// std::unique_ptr<T> a; 	// for exception handling (no need for delete a)
	
	int m_size; 	  	// the stack size
	int m_max_size;		// the array size, used internally
	void resize();	  	// used in push()
	void swap(int i, int j) {
		T x = a[i];
		a[i] = a[j];
		a[j] = x;
	}
public:
	// exception class for pop() and top() with empty stack
	class ReadEmptyStack : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Read empty stack.";
			}
	};

	Stack(); 	               	
	Stack(int len, T x); 	               	
	virtual ~Stack(); 
	
	// Assign Operator Overloading
	Stack<T>& operator=(Stack<T> &b) { if (a != NULL) delete[] a; a = b.a;
		b.a = NULL;
		m_size = b.m_size;
		m_max_size = b.m_max_size;
		return *this;
	}

	bool empty() { return m_size==0; }
	int size() { return m_size; }	// Add size() function

	static void copyOfRange(Stack<T> &a0, Stack<T> &a, int i, int j);
	virtual void reverse();
	// basic operations
	T& top();
	void push(T x);
	void pop();
	void pop2();
	void clear();

};

// Constructor with a length template<class T>
template<class T>
Stack<T>::Stack() {
	m_size=0;
	m_max_size=1;
	a = new T[m_max_size];
}

// Constructor with a length and initial value
template<class T>
Stack<T>::Stack(int len, T init) {
	m_size=len;
	m_max_size=len;
	a = new T[len];
	for (int i = 0; i < len; i++)
		a[i] = init;
}

// Default Destructor 
template<class T>
Stack<T>::~Stack() {
	if (a != NULL) delete[] a;
}

template<class T>
void Stack<T>::reverse() {
	for (int i = 0; i < m_size/2; i++) {
		swap(i, m_size-i-1);
	}
}

template<class T>
void Stack<T>::copyOfRange(Stack<T> &a0, Stack<T> &a, int i, int j) {
	Stack<T> b(j-i);
	std::copy(a.a, a.a+j-i, b.a);
	a0 = b;
}

template<class T>
T& Stack<T>::top() {	
	// assert(m_size>0);  
    if(m_size==0)
		throw ReadEmptyStack();	// throw an exception
	return a[m_size-1];		// return the last element (reference)
}

template<class T>
void Stack<T>::push(T x) {	// add an item at the last index+1
	if(m_size+1>m_max_size) resize();   // the array is full, then resize() -> increase 2x size
	a[m_size] = x;					// a[size] is the next index of the last one
	m_size++;
}
	
// Dynamically mange the size of array 
template<class T>
void Stack<T>::resize() {
    int resize=2*m_size;
	if(resize==0)	// if m_size==0, maybe not necessary since the min size of array is 1
		resize=1;
	T *b = new T[resize];
	for(int i=0; i<m_size; i++)
		b[i] = a[i];
	// Faster array copy
	// std::copy(a+0, a+m_size, b+0);
	delete []a;
	a=b;
}
		
template<class T>
void Stack<T>::pop() {	// remove an item at the last index
    if(m_size==0)
		throw ReadEmptyStack();	// throw an exception
	m_size--;             		// just reduce the size value
}

template<class T>
void Stack<T>::pop2() {	// remove an item at the last index and resize()
	m_size--;             		// just reduce the size value
	assert(m_size>=0);
	if(m_max_size>=3*m_size) resize();	// resize if the max_size is too big for the size
}

template<class T>
void Stack<T>::clear() {	// remove all items
	m_size=0;
	m_max_size=1;
	T *b = new T[1];
	delete []a;
	a=b;
}
} /* namespace ods */
#endif /* ARRAY_H_ */
