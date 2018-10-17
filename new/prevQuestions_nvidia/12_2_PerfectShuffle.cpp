// Implement Perfect Shuffle assuming having a perfect random generator
// When a randon number is picked, then swapped it to the current index
#include <iostream>
#include <cstdlib>
using namespace std;

void Swap(int &a, int &b){	
    int t = a;
    a = b;
    b = t;
}
void RandomShuffle(int a[], int n){
    for(int i=0; i<n; ++i){
        int j = rand() % (n-i) + i;	// Generate Random index 	
        Swap(a[i], a[j]);           // Swap it to the increasing index
    }
}
int main(){
    srand((unsigned)time(0));
    int n = 10;
    int a[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    RandomShuffle(a, n);
    for(int i=0; i<n; ++i)
        cout<<a[i]<<endl;
    return 0;
}
