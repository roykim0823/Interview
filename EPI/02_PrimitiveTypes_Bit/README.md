# Sieve of Eratosthenes
Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.

Example:

Input : n =10
Output : 2 3 5 7 

Input : n = 20 
Output: 2 3 5 7 11 13 17 19
The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so (Ref Wiki).

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
Following is the algorithm to find all the prime numbers less than or equal to a given integer n by Eratosthenes’ method:

Create a list of consecutive integers from 2 to n: (2, 3, 4, …, n).
Initially, let p equal 2, the first prime number.
Starting from p2, count up in increments of p and mark each of these numbers greater than or equal to p2 itself in the list. These numbers will be p(p+1), p(p+2), p(p+3), etc..
Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this number (which is the next prime), and repeat from step 3.

# O(n) Improved Sieve of Eratosthenes algorithm works as following:

For every number i where i varies from 2 to N-1:
    Check if the number is prime. If the number
    is prime, store it in prime array.

For every prime numbers j less than or equal to the smallest  
prime factor p of i:
    Mark all numbers j*p as non_prime.
    Mark smallest prime factor of j*p as j
