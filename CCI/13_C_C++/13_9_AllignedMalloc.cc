// Q. Write an aligned malloc and free function that supports allocating memory such that the memory
//    address returned is divisible by a specific power of two.

/* 
Checks:
	Typically, with malloc, we do not have control over where the memory is allocated within the heap.
	We just get a pointer to a block of memory which could start at any memory address within the heap.
	
	We need to work with these contraints by requesting enough memory that we can return a memory address
	which is divisible by the desired value.

	Ex) 100-byte chunk of memory, starting at an address that is multiple of 16. 
	    -> Allocate extra 15 bytes
*/

/*
// Pseducode
void *aligned_malloc_ps(size_t n_bytes, size_t alignment) {
	int offset = alignment -1;
	void *p = (void *) malloc(n_bytes+offset);
	void *q = (void *) malloc(( (size_t)(p) + offset) & ~(alignment -1));
	return q;
}
// -> how to free p?
*/

#include <stdio.h>
#include <stdlib.h>


void *aligned_malloc(size_t n_bytes, size_t alignment) {
	void* p1;	// original block
	void** p2;	// aligned block
	size_t offset = alignment -1 + sizeof(void*); 	// sizeof(void*) to store p1's address
	
	if((p1 = (void *) malloc(n_bytes+offset))== NULL) {
		return NULL;
	}

	// p2 as a void** (or an array of void*'s), we can just look at the index-1 to retrieve p1
	p2=(void**)(( (size_t)(p1)+offset) & ~(alignment-1));
	printf("(size_t)(p1)=%lu\n", (size_t)(p1));
	p2[-1]=p1;
	return p2;
}

void aligned_free(void *p2) {
	// for consistency, we use the same names as aligned_malloc
	// p2 as a void** (or an array of void*'s), we can just look at the index-1 to retrieve p1
	void *p1 = ((void**)p2)[-1];
	free(p1);
}

int main() {
	int *p=(int*)aligned_malloc(100*sizeof(int), 16);
	
	for(int i=0; i<100; i++) {
		p[i]=i;
	}
	for(int i=0; i<100; i++) {
		//;
		printf("p[%d]=%d\n", i, p[i]);
		//if(i>0 && i%16==0) printf("\n");
	}

	aligned_free(p);
}
