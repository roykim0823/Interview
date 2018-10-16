
#include <iostream> 
using namespace std; 
  
class Base 
{ 
protected: 
    int i; 
public: 
    Base(int a)     { i = a; } 
    virtual void display() 
    { cout << "I am Base class object, i = " << i << endl; } 
}; 
  
class Derived : public Base 
{ 
    int j; 
public: 
    Derived(int a, int b) : Base(a) { j = b; } 
    virtual void display() 
    { cout << "I am Derived class object, i = "
           << i << ", j = " << j << endl;  } 
}; 
  
// Global method, Base class object is passed by value 
void somefunc (Base obj) 	// object slicing
{ 
    obj.display(); 
} 

// No object slicing with a pointer or a reference
void somefunc_ref(Base &obj)	// no object slicing  	
{ 
    obj.display(); 
}            

void somefunc_ptr(Base *objp)	// no object slicing 
{ 
    objp->display(); 
} 
  
int main() 
{ 
    Base b(33); 
    Derived d(45, 54); 
    somefunc(b); 
    somefunc(d);  // Object Slicing, the member j of d is sliced off 
    somefunc_ref(b); 
    somefunc_ref(d);  // No Object Slicing
    somefunc_ptr(&b); 
    somefunc_ptr(&d);  // No Object Slicing
    return 0; 
} 


