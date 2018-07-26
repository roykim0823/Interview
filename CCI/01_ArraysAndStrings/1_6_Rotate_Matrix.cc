// Q. Given NxN matrix, write a method to rotate the image by 90 degrees.
// Q+. Can you do this in place?

/* 
Checks:
	1. Moving each layer (top, right, bottom, left) to (right, bottom, left, top) 
	   except for the last element. This requires N-1 size array
	   for i=0 to n
		   temp = top[i];
           top[i]=left[i];
		   left[i]=bottom[i];
		   bottom[i]=right[i];
		   right[i]=top[i];
	2. Instead of using N size array, swap index by index
*/

#include <iostream>
#include <string>
#include <stdlib.h>	// srand
#include <time.h> 	// time
using namespace std;

const int N=5;

void randomMatrix(int matrix[][N], int n) 
{
	srand(time(NULL));

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			matrix[i][j]=rand()%10;
		}
	}
}
            
void printMatrix(int matrix[][N], int n) 
{
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void rotateMatrix(int matrix[][N], int n)
{
	for(int layer=0; layer<n/2; layer++) {
		int first = layer;
		int last = n-1-layer;
		for(int i=first; i<last; i++) {
			int offset= i-first;
			//save top
			int top = matrix[first][i];
			// left -> top
			matrix[first][i] = matrix[last-offset][first];
			// bottom -> left
			matrix[last-offset][first] = matrix[last][last-offset];
			// right -> bottom
			matrix[last][last-offset] = matrix[i][last];
			// top -> right
			matrix[i][last] = top;
		}
	}
}

int main()
{
	int matrix[N][N];
	randomMatrix(matrix, N);
	printMatrix(matrix, N);
	cout << endl;
	rotateMatrix(matrix, N);
	printMatrix(matrix, N);
	cout << endl;
	return 0;
}
