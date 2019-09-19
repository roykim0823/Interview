#!/usr/bin/pyhton3

import math

def prime_sieve(n):
  """Given n, return a list of all primes up to n."""

  if n < 2:
    return []

  size = math.floor(0.5 * (n-3)) + 1
  prime_list = [2] 

  # is_prime[i] represents whether (2i + 3) is prime or not.
  # Initially, set each to True. Then use sieving to eliminate non-primes.
  is_prime = [True] * size

  for i in range(size):
    if is_prime[i]:
      p = (i *2) + 3
      prime_list.append(p)
      
      # Sieving from p^2, whose value is (4i^2 + 12i + 9).
      # The index in is_prime is (2i^2 + 6i +3) since is_prime[i] represents 2i + 3.
      # Note that we need to use long long for j because p^2 might overflow (for C/C++)
      for j in range(2*i*i + 6*i + 3, size, p):  # range(start, stop, step)
        is_prime[j] = False
  return prime_list


def smallest_multiple(n):
  product = 1
  num_list = list(range(2, n+1))  # 2, 3, 4, ..., n
  primes = {}
  
  for i in range(2, n+1):
    found = False
    max_cnt = 0
    for j in range(i, n+1):
      # print('NUM:', num_list[j-2], i)
      cnt = 1
      while num_list[j-2] % i == 0:
        num_list[j-2] = num_list[j-2] // i
        if cnt > max_cnt:
          max_cnt = cnt
        cnt += 1
        # print(i, j, num_list, product)
    product *= int(math.pow(i, max_cnt))

  return product 
  

def main():
  for i in range(1, 21):
    print(i, smallest_multiple(i))

if __name__ == '__main__':
  main()
