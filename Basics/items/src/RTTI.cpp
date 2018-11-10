#include<iostream> 
using namespace std; 

class B { }; 
class D: public B {}; 

// Adding a virtual function to the base class B makes it working.
class Bv { virtual void fun() {} }; 
class Dv: public Bv { }; 
  
int main() 
{ 
	/*
    B *b = new D; 
    D *d = dynamic_cast<D*>(b);		// compilation error 
    if(d != NULL) 
        cout<<"works"; 
    else
        cout<<"cannot cast B* to D*"; 
    */

	Bv *bv = new Dv; 
    Dv *dv = dynamic_cast<Dv*>(bv); 
    if(dv != NULL) 
        cout<<"works" << endl; 
    else
        cout<<"cannot cast Bv* to Dv*" << endl; 
    
	return 0; 
} 

