#include <stdio.h>

int foo(int a) {
	int result=0;

	while(a>>=1) 
		result+=1;
	return result;
}

// Solutions
int log2(unsigned a) {
	int result=0;

	while(a>>=1) 
		result+=1;
	return result;
}

int main()
{
	//printf("%d\n", foo(128));
	//printf("%d\n", foo(-1));	// infinite loop
	printf("%d\n", log2(128));
	printf("%d\n", log2(-1));	// infinite loop
	return 0;
}

// 1. What does the foo function do?
// -> It calculates a logarithm (with base 2)

// 2. What's wrong with the foo?
// -> a. the argument should be "unsigned int a" instead of "int a" since the while loop iterates
//   	 infinitely for negative value.
//	  b. The function name is not good. It should be "log2" The function name should describes what the 
//		 function supposed to do.
