/* Euler Problem 5: Find the smallest positive number that is evenly divisible
  by all the numbers 1 to 20.

   Language: C
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int lcm = 1;

// Straightforward implementation. This could be done on a hand calculator or
// even with paper and pencil. I include it here just to show the obvious
// approach of manual prime decomposition.
/*
void main() {
  lcm *= 2;   // 2: prime
  lcm *= 3;   // 3: prime
  lcm *= 2;   // 4=2*2 so only requires a second factor of 2
  lcm *= 5;   // 5: prime
//lcm *= 6;   // 6=2*3 so already present
  lcm *= 7;   // 7: prime
  lcm *= 2;   // 8=2*2*2 so only requires a third factor of 2
  lcm *= 3;   // 9=3*3 so only requires a second factor of 3
//lcm *= 10;  // 10=2*5 so already present
  lcm *= 11;  // 11: prime
//lcm *= 12;  // 12=2*2*3 so already present
  lcm *= 13;  // 13: prime
//lcm *= 14;  // 14=2*7 so already present
//lcm *= 15;  // 15=3*5 so already present
  lcm *= 2;   // 16=2*2*2*2 so only requires a fourth factor of 2
  lcm *= 17;  // 17: prime
//lcm *= 18;  // 18=2*3*3 so already present
  lcm *= 19;  // 19: prime
//lcm *= 20;  // 20=2*2*5 so already present
  printf("%d\n", lcm);
}
*/
// Obviously we would like to do better by creating an algorithm that can work
// for any maximum factor, not just 20. It should be apparent from the above
// manual approach that we will need a list of primes. The following function
// is the basic Sieve of Eratosthenes and sets up an array of booleans that tell
// us which indices are prime. It could be way more efficient but that's not the
// point of this problem.

#define k 20
bool sieve[k+1];
void sieve_of_eratosthenes() {
  for(int i = 0; i <= k; i++)
    sieve[i] = true;
  sieve[0] = sieve[1] = false;
  for(int i = 2; i <= k; i++) {
    if(!sieve[i])
      continue;
    for(int j = i * i; j <= k; j += i)
      sieve[j] = false;
  }
}

// Now we have a list of primes up to our factor k. How many of each prime do we
// need in our least common multiple? For any given prime, we need as many of it
// as we can get without it going over k. So for this problem (k=20), we need 4
// of the prime 2 because 2^4=16, but 2^5=32 which goes over k. Similarly, we
// need 2 of the prime 3 because 3^2=9 but 3^3=27, again over k. So on for all
// of the primes <= k. This exponent is floor(log(k)/log(p)). We can gain some
// additional efficiency by noticing that once we hit primes that are greater
// than sqrt(k), we only need 1 of each.

void main() {
  sieve_of_eratosthenes();
  double sqrtk = sqrt(k);
  for(int i = 2; i <= k; i++) {
    if(!sieve[i])
      continue;
    if(i <= sqrtk)
      lcm *= pow(i, floor(log(k) / log(i)));
    else
      lcm *= i;
  }
  printf("%d\n", lcm);
}
