/* Euler Problem 1: Find the sum of all multiples of 3 and 5
   above 0 and below 1000.

   Language: C
*/

#include <stdio.h>

int mult1 = 3, mult2 = 5;
int max = 999;
int sum = 0;

// Straightforward implementation
/*
void main() {
  for(int i = 1; i < max; i++) {
    if(i % mult1 == 0 || i % mult2 == 0)
      sum += i;
  }
  printf("%d\n", sum);
}
*/

// More efficient implementation using the fact that
// sum(1..n) = 0.5 * n * (n+1)
int sum_divisible_by(int n) {
  int p = max / n;
  return n * (p * (p+1)) / 2;
}

void main() {
  sum = sum_divisible_by(mult1) +
        sum_divisible_by(mult2) -
        sum_divisible_by(mult1 * mult2);
  printf("%d\n", sum);
}
