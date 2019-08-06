/* GCD (Greatest Common Divisor) of HCF (Highest Common Factor) of two number is
   the largest number that divides both of them
   A. Simple Solutions
     - Find all prime factors of both numbers, then find intersection of all factors
	   presented in both numbers. Finally, return product of elements in the intersection
   B. Efficient solution
     - Use Euclidean algorithm which is the main algorithm used for this purpose.
	   The idea is GCD of two numbers doesn't change if smaller number is subtracted from
	   a bigger number.
*/

// GCD by subtraction
int gcd_s(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd_s(a-b, b); 
    return gcd_s(a, b-a); 
} 

// More efficient one by modulo operation
int gcd(int a, int b) {
	if (b==0)
		return a;
	return gcd(b, a % b);
}

/* Extended Euclidean Algorithm
   - Find integer coefficients x and y such that: ax + by = gcd (a, b)

   Examples:
   	Input: a = 30, b = 20
	Output: gcd = 10
        x = 1, y = -1
	(Note that 30*1 + 20*(-1) = 10)

	Input: a = 35, b = 15
	Output: gcd = 5
        x = 1, y = -2
	(Note that 10*0 + 5*1 = 5)
   
   The extended Euclidean algorithm updates results of gcd(a, b) using the results 
   calculated by recursive call gcd(b%a, a). Let values of x and y calculated by 
   the recursive call be x1 and y1. x and y are updated using below expressions.

   x = y1 - floor[b/a] * x1
   y = x1
*/

int gcdExtended(int a, int b, int &x, int &y) {
	// Base case
	if( a == 0) {
		x=0; 
		y=1;
		return b;
	}

	int x1, y1;	// to store results of recursive call
	int gcd = gcdExtended((b%a), a, x1, y1);

	// Update x and y using results of recursive
	x = y1 - (b/a) * x1;
	y = x1;
	return gcd;
}
