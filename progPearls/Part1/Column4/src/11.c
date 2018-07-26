#include <stdio.h>
typedef int DataType;

int binarysearch(DataType x[], int n, int t);

int main() {
	DataType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("%d %d %d %d\n", binarysearch(v, 10, -1), binarysearch(v, 10, 11), binarysearch(v, 10, 2), binarysearch(v, 10, 9));
	return 0;
}

int binarysearch(DataType x[], int n, int t) {
	int m = n/2, p;
	if (n == 0)
		return -1;
	else if (x[m] < t) {
		p = binarysearch(x+m+1, n-m-1, t);
		return p == -1 ? -1 : p+m+1;
	}
	else if (x[m] > t)
		return binarysearch(x, m, t);
	else
		return m;
}
4.6.11
Write and prove the correctness of a recursive binary search function in C or C++ with this declaration:
	int binarysearch(DataType x[], int n)
Use this function alone; do not call any other recursive functions
--
There's a problem with such declaration: it is missing the element to search for. x is the array, and n must be the size of the array, since there's no way to know in C the array size. So I added a third parameter, t, which
is the element to search for.
My recursive implementation uses n as the array length; if the array's middle position is less than t, then the function is recursively called with a shifted array, x+m+1 (where m is the middle position).
This is the equivalent of upsizing the lower range bound value (l). The new array, x', is shifted m+1 positions, so that x'[0] is the same as x[m+1]. This means that we must add m+1 to this recursive call return value in 
order to get the true position from the original array. We also have to be careful with n's value. In this case, x' will have n-(m+1) = n-m-1 elements, because x[0..m] has m+1 elements. Another key point to keep in mind is
that if the recursive call returns -1, then we must return -1 in the current call as well, instead of adding m+1 to -1. 
Passing a shifted array and a new value for n in the recursive call is the secret not to use an explicit u and l as we did before.
An easier case is when x[m] > t; because we don't need to shift the array to the right, in this case, we just have to recursively call binarysearch() with n = m and return the same value that the recursion gives us.
This is the equivalent to downsizing the value for u.
The two cases in which the recursion stops is when either we reach a value of n = 0, meaning that we got to the end of every possible range without finding t, or when x[m] == t.
