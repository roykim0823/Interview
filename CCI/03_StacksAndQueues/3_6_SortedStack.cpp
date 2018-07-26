// Q. Implement sort a stack in asending order (top is the biggest iteM
//    You might you an additional stack, but not other data structure
#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

void Qsort(stack<int> &s){
    priority_queue< int,vector<int>,greater<int> > q;
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(!q.empty()){
        s.push(q.top());
        q.pop();
    }
}

// O(n^2) time, O(n) space
stack<int> Ssort(stack<int> s){
    stack<int> t;
    while(!s.empty()){
        int data = s.top();	// step 1
        s.pop();
		// step 2: t.pop() and push it in s until t.top()<= data
        while(!t.empty() && t.top()>data){
            s.push(t.top());
            t.pop();
        }
        t.push(data);
    }
    return t;
}

int main(){
    srand((unsigned)time(0));
    stack<int> s;
    
    for(int i=0; i<10; ++i) 
        s.push((rand()%100));
    s = Ssort(s);
    //Qsort(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
