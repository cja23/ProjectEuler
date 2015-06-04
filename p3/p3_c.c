/* Euler Problem 3: Find the largest prime factor of 600,851,475,143.

   Language: C
*/

#include <stdio.h>
#include <math.h>

unsigned long long composite = 600851475143LLU;
unsigned long long prevFactor = 1, factor = 2;

// Straightforward implementation
/*
void main() {
  while(composite > 1) {
    if(composite % factor == 0) {
      prevFactor = factor;
      composite /= factor;
      while(composite % factor == 0)
        composite /= factor;
    }
    factor++;
  }
  printf("%d\n", prevFactor);
}
*/

// More efficient implementation using the following facts:
// 1. 2 is the only even prime.  Pull out all the 2's and then only check odds.
// 2. Any number can only have 1 prime factor larger than its square root.  So,
//    use the square root of the composite as an upper bound.

void main() {
  // Remove all factors of 2
  if(composite % 2 == 0) {
    composite /= 2;
    prevFactor = 2;
    while(composite % 2 == 0)
      composite /= 2;
  }
  // Start with 3 and only test odd factors less than sqrt of composite number
  factor = 3;
  double maxFactor = sqrt(composite);
  while(composite > 1 && factor <= maxFactor) {
    if(composite % factor == 0) {
      prevFactor = factor;
      composite /= factor;
      while(composite % factor == 0)
        composite /= factor;
      maxFactor = sqrt(composite);
    }
    factor = factor + 2;
  }
  printf("%d\n", composite == 1 ? prevFactor : composite);
}
