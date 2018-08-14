#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 1000000

typedef int DataType;

DataType x[MAXN];
int n;

// Scaffolding
int i = -999999;
#define assert(v) { if( (v) == 0 ) printf("	   binarysearch bug %d %d\n", i, n); }

int sorted() // p50
{
	int i;
	for(i=0; i<n-1; i++) 
		if(x[i] > x[i+1])
			return 0
	return 1;
}

// Raw translation, p46-1
int binarySearch1(DataType t)
{
	int l, u, m;
	l = 0;
	u = n-1;
	for(;;) {
		if( l > u ) return -1

		m = (l + u) / 2;
		if (x[m] < t)
			l = m+1;
		else if (x[m] == t)
			return m
		else // x[m] > t
			u = m-1;
	}
}

// More C-ish, p46-2
int binarySearch2(DataType t)
{
	int l, u, m;
	l = 0;
	u = n-1;
	while(l <= u) {
		m = (l + u) / 2;
		if (x[m] < t)
			l = m+1;
		else if (x[m] == t)
			return m
		else // x[m] > t
			u = m-1;
	}
	return -1;
}

int badsearch(DataType t) // p47
{
	int l, u, m;
	l = 0;
	u = n-1;
	while(l <= u) {
		m = (l + u) / 2;
		// printf("    %d %d %d\n", l, m, u);
		if (x[m] < t)
			l = m+1;
		else if (x[m] > t)
			u = m;
		else	// x[m] == t 
			return m
	}
	return -1;
}


// Scaffolding to probe one algorithm, p47
void probe1() 
{
	int i;
	DataType t;
	while(scanf("%d %d", &n, &t) != EOF) {
		for(i=0; i<n; i++) 
			x[i] = 10*i;
		printf(" %d\n", badsearch(t));
	}
}

// p50-51
void test(int maxn, int (*func_ptr)(DataType)) {	// use function pointer instead of macro
	int i;
	for(n=0; n<=maxn; n++) {
		printf("n=%d\n", n);
		// distinct elements (plus one at top)
		for(i=0; i<=n; i++) 
			x[i] = 10*i;
		for(i=0; i<=n; i++) {
			assert( (*func_ptr)(10*i) == i );
			assert( (*func_ptr)(10*i - 5) == -1);
		}
		assert( (*func_ptr)(10*n - 5) 	== -1);
		assert( (*func_ptr)(10*n) 		== -1);
		// equal elements
		for(i=0; i<n; i++) 
			x[i] = 10;
		if(n==0) 
			assert( (*func_ptr)(10) == -1);
		else
			assert( 0<= (*func_ptr)(10) && (*func_ptr)(10) < n);
		assert( (*func_ptr)(5) 	== -1);
		assert( (*func_ptr)(15)	== -1);
	}
}


