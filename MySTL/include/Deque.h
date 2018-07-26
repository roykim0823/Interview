/*
 * Deque.h
 *
 *  Created on: 2011-11-23
 *      Author: morin
 */

#ifndef VECTOR
#define VECTOR
#include <vector>

namespace mySTL {
using std::vector; 

template<class T>
class Deque {	// ArrayDeque with two ArrayStacks
protected:
	vector<T> front; 	// reverse
	vector<T> back;
	void balance();
public:
	Deque() {};
	virtual ~Deque() {};
	bool empty() { return this->size()==0; }
	int size();
	T get(int i);
	void set(int i, T x);
	void push_front(T x) 	{ front.push_back(x);  }
	void push_back(T x) 	{ back.push_back(x);   }
	void pop_front();
	void pop_back(); 
	virtual void clear();

	// Index Operator Overloading
	T& operator[](int i) {
		assert(i>=0 && i <this->size());
		if(i<front.size()) 
			return front[front.size()-1-i];
		else
			return back[i-front.size()];
	}
};

template<class T> inline
T Deque<T>::get(int i) { 	// Dequq[i]
	if (i < front.size()) {
		return front[front.size()-1-i];
	} else {
		return back[i-front.size()];
	}
}

template<class T> inline
void Deque<T>::set(int i, T x) {
	if (i < front.size()) 
		front[front.size()-1-i]=x;
	else
		back[i-front.size()]=x;
}

template<class T>
int Deque<T>::size() {
	return front.size() + back.size();
}

template<class T>
void Deque<T>::pop_front() {
	assert(this->size()>0);
	if(front.empty()==false)
		front.pop_back();
	else if(back.size()==1)	// only one item
		back.pop_back();
	else {
		// move back item to front
		balance();
		front.pop_back();
	}
}


template<class T>
void Deque<T>::pop_back() {
	assert(this->size()>0);
	if(back.empty()==false)
		back.pop_back();
	else if(front.size()==1)	// only one item
		front.pop_back();
	else {
		// move back item to front
		balance();
		back.pop_back();
	}
}

template<class T>
void Deque<T>::balance() { 	// make balace on pop_front() or pop_back()
	if(front.size()==0) // pop_front (front.size()==0 and back.size()>1) 
	{
		int back_size=back.size();
		int n=back_size/2;  	// number of moving items
		front.resize(n);
		for(int i=0; i<n; i++)
			front[n-1-i] = back[i];
		//typename vector<T>::iterator begin=back.begin();
		//typename vector<T>::iterator end=back.end();
		//vector<T> temp(begin+n, end);
		vector<T> temp(back.begin()+n, back.end());
		back=temp;
	} else { 			// pop_back (back.size()==0 and fron.size()>1)
		int front_size=front.size();
		int n=front_size/2;  	// number of moving items
		back.resize(n);
		for(int i=0; i<n; i++)
			back[i] = front[n-1-i];
		//typename vector<T>::iterator begin=front.begin();
		//typename vector<T>::iterator end=front.end();
		//vector<T> temp(begin+n, end);
		vector<T> temp(front.begin()+n, front.end());
		front=temp;
	}
}
		
template<class T>
void Deque<T>::clear() {
	front.clear();
	back.clear();
}

} /* namespace ods */
#endif /* DUALARRAYDEQUE_H_ */
