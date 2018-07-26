/* Adapted from: */
/* sort.cpp -- test and time sorting algorithms */
/* http://www.cs.bell-labs.com/cm/cs/pearls/sort.cpp */
/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */

#include <stdio.h>

#define MAXN 10000000

typedef int DType;

DType realx[MAXN];
int *x = realx;	/* allow x to shift for heaps */
int n;

void print_x() {
    int i;
    printf("          ");
    for (i = 1; i <= n; i++) printf("%3d", x[i]);
    printf("\n");
}

void swap(int i, int j) {
   DType t = x[i];
   x[i] = x[j];
   x[j] = t;
   printf("swap(%2d,%2d ):         ",i,j);
   print_x();
}

int randint(int l, int u) {
    int i, ignore; for (i=1; i<5000; i++) ignore = rand();
    return l + (rand()) % (u-l+1);
}


void heapify_up(int u) {  int i, p; i = u;
    for (;;) {
        if (i == 1) break;
        p = i / 2;
        if (x[p] >= x[i]) break;
        swap(p, i); i = p;
    }
    printf("heapify_up(%2d ):      ",u);
    print_x();
}
void heapify_down(int l, int u) {  int i, c; i = l;
    for (;;) {
        c = 2*i;
        if (c > u) break;
        if (c+1 <= u && x[c+1] > x[c]) c++;
        if (x[i] > x[c]) break;
        swap(i, c); i = c;
    }
    printf("heapify_down(%2d,%2d ): ",l,u);
    print_x();
}
void hsort() { int i;
    for (i = 2; i <= n; i++) heapify_up(i);
    for (i = n; i >= 2; i--) { swap(1, i); heapify_down(1, i-1); }
}


int main(int argc, char *argv[]) {
    int i, mod;
    if (argc>1 && (*argv[1] == '0')) {
       n = 8;
       /* use the example shown in the Wikipedia page */
       x[0] = 6;
       x[1] = 5;
       x[2] = 3;
       x[3] = 1;
       x[4] = 8;
       x[5] = 7;
       x[6] = 2;
       x[7] = 4;
   } else {
       n = 6;
       mod = 3 * n;
       for (i = 0; i < n; i++) x[i] = randint(1, mod-1);  /* initialize the array with random values */
    }
    x--;   /* sneaky way of resetting starting index to be 1, instead of 0 */
    printf("initial value of x:   ");
    print_x();
    hsort();
    for (i = 1; i < n; i++) if (x[i] > x[i+1]) printf("  SORT BUG i=%d\n", i);
    x++;
    return 0;
}
