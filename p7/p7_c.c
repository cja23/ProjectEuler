/* Euler Problem 7: Find the 10,001st prime number.
   Language: C
*/


#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int prime_n = 10001;

// A function to determine primality.
bool isPrime(int n) {
  if(n == 1) return false;      // 1 is not prime
  if(n < 4) return true;        // 2 and 3 are prime
  if(n % 2 == 0) return false;  // all higher even numbers are not prime
  if(n < 9) return true;        // 5 and 7 are prime
  if(n % 3 == 0) return false;  // all higher multiples of 3 are not prime
  int sqrtN = floor(sqrt(n));   // the highest we must search for primes < n
  int f = 5;
  while(f <= sqrtN) {           // loop to check for primes of form 6k +/- 1
    if(n % f == 0) return false;
    if(n % (f+2) == 0) return false;
    f += 6;
  }
  return true;
}

// Straightforward implementation using the above test function.

void main() {
  int count = 1, candidate = 1;
  while(count != prime_n) {
    candidate += 2;
    if(isPrime(candidate))
      count++;
  }
  printf("%d\n", candidate);
}
