/* Dynamic Programming C++ implementation of LIS problem */
#include<bits/stdc++.h> 
using namespace std; 
	
/* lis() returns the length of the longest increasing 
subsequence in arr[] of size n */
int lis1( int arr[], int n ) 
{ 
	int lis[n]; 

	lis[0] = 1; 

	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	} 

	// Return maximum value in lis[] 
	return *max_element(lis, lis+n); 
} 
	

// Binary search (note boundaries in the caller) 
int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
	while (r - l > 1) { 
		int m = l + (r - l) / 2; 
		if (v[m] >= key) 
			r = m; 
		else
			l = m; 
	} 

	return r; 
} 

int LongestIncreasingSubsequenceLength1(std::vector<int>& v) 
{ 
	if (v.size() == 0) 
		return 0; 

	std::vector<int> tail(v.size(), 0); 
	int length = 1; // always points empty slot in tail 

	tail[0] = v[0]; 
	for (size_t i = 1; i < v.size(); i++) { 

		// new smallest value 
		if (v[i] < tail[0]) 
			tail[0] = v[i]; 

		// v[i] extends largest subsequence 
		else if (v[i] > tail[length - 1]) 
			tail[length++] = v[i]; 

		// v[i] will become end candidate of an existing 
		// subsequence or Throw away larger elements in all 
		// LIS, to make room for upcoming grater elements 
		// than v[i] (and also, v[i] would have already 
		// appeared in one of LIS, identify the location 
		// and replace it) 
		else
			tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
	} 

	return length; 
} 

// Using upper_bound() in C++
int LongestIncreasingSubsequenceLength2(std::vector<int>& v) 
{ 
	if (v.size() == 0) 
		return 0; 

	std::vector<int> tail(v.size(), 0); 
	int length = 1; // always points empty slot in tail 

	tail[0] = v[0]; 
	for (size_t i = 1; i < v.size(); i++) { 
		if (v[i] > tail[length - 1]) 
			tail[length++] = v[i]; 
		else { 
			// TO check whether the element is not present before hand 
			auto it = find(tail.begin(), tail.begin() + length, v[i]); 
			if (it != tail.begin() + length) { 
				continue; 
			} 
			// If not present change the tail element to v[i] 
			it = upper_bound(tail.begin(), tail.begin() + length, v[i]); 
			*it = v[i]; 
		} 
	} 

	return length; 
} 

int main() 
{ 
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
    	int n = sizeof(arr)/sizeof(arr[0]);  
    	printf("Length of lis is %d\n", lis( arr, n ) );  

	std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; 
	std::cout << "Length of Longest Increasing Subsequence is "
			<< LongestIncreasingSubsequenceLength1(v) << " "
			<< LongestIncreasingSubsequenceLength2(v) << std::endl; 
	return 0; 
} 



