/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* sets.cpp -- exercise set implementations on random numbers */
#include "intSet.h"

void genfloyd(int m, int maxval)
{
	int *v = new int[m];
	IntSetSTL S(m, maxval);
	for (int j = maxval-m; j < maxval; j++) {
		int t = bigrand() % (j+1);
		int oldsize = S.size();
		S.insert(t);
		if (S.size() == oldsize) // t already in S
			S.insert(j);
	}
	S.report(v);
	for (int i = 0; i < m; i++)
		cout << v[i] << "\n";
}
void memaccesstest(int m, int n)
{
	IntSetList S(m, n);
	// change among Arr, List and List2
	for (int i = 0; i < m; i++)
		S.insert(i);
}
void overheadonly(int m, int n)
{
	int i, *v = new int[m];
	for (i = 0; i < m; i++)
		v[i] = bigrand() % n;
		for (i = 0; i < m; i++)
			cout << v[i] << "\n";
}
int main(int argc, char *argv[])
{
	int m = atoi(argv[1]);
	int maxval = atoi(argv[2]);
	gensets(m, maxval);
	// overheadonly(m, n);
	// memaccesstest(m, n);
	return 0;
}
