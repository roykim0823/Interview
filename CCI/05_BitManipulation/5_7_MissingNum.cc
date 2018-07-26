// Q. An array A contains all the integer from 0 through n, except for one number which is missing.
//    But, we cannot access an entire integer in A with a single operation. Just 1 bit at a time.
//	  Can you find the missing number in O(n)?

#include <iostream>
#include <cstring>
using namespace std;

// Naive: O(nlogn) since length(n) = log2(n)
int missingNum(int a[], int n) {
	int sum=0;
	for(int i=0; i<n; i++) 
		sum+=a[i];
	
	return n*(n+1)/2 - sum;
}

// O(n) version
int missingNum2(int a[], int n) {
	int missing_num=0;
	bool flag_even=true;
	for(int i=0; i<n; i++) 
	{
		if(flag_even && a[i]%2==1)	// Error
			break;
		if(flag_even==false && a[i]%2==0)	// Error
			break;
		if(flag_even && a[i]%2==0) {
			missing_num++;
			flag_even=false;
		}
		if(flag_even==false && a[i]%2==1) {
			missing_num++;
			flag_even=true;
		}
	}

	return missing_num;
}

int main(){
    int a[] = {
        0, 1, 2, 3, 4, 5, 7, 8, 9, 10
    };
    cout<<missingNum(a, 10)<<endl;
    cout<<missingNum2(a, 10)<<endl;
    return 0;
}
