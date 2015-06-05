/* Euler Problem 6: Find the difference between sum-of-squares and square-of-sum
   of first 100 naturals.

   Language: C
*/

#include <math.h>
#include <stdio.h>

int max = 100, sum = 0, sumsq = 0, sqsum = 0;

// Straightforward implementation.
/*
void main() {
  for(int i = 1; i <= max; i++) {
    sum += i;
    sumsq += pow(i, 2);
  }
  sqsum = pow(sum, 2);
  printf("%d\n", sqsum - sumsq);
}
*/

// The above can be made much more efficient, eliminating all the loops, by
// using the formulas:
// 1. sum(n) = 0.5 * n * (n+1)
// 2. sum(n^2) = n/6 * (2*n+1) * (n+1)

void main() {
  sum = max * (max + 1) / 2;
  sqsum = pow(sum, 2);
  sumsq = max * (2 * max + 1) * (max + 1) / 6;
  printf("%d\n", sqsum - sumsq);
}
