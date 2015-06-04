/* Euler Problem 2: Find the sum of all even members of the Fibonacci sequence
   below 4 million.

   Language: C
*/

#include <stdio.h>

int f1 = 1, f2 = 2;
unsigned int max = 4000000;
unsigned int sum = 0;
unsigned int temp;

// Straightforward implementation
/*
void main() {
  while(f2 < max) {
    if(f2 % 2 == 0)
      sum += f2;
    temp = f1 + f2;
    f1 = f2;
    f2 = temp;
  }
  printf("%u\n", sum);
}
*/

// More efficient implementation using the facts that only every 3rd Fibonacci
// number is even and that f(n) = 4 * f(n-3) + f(n-6).

int sum_divisible_by(int n) {
  int p = max / n;
  return n * (p * (p+1)) / 2;
}

void main() {
  sum = f1 = 2, f2 = 8;
  while(f2 < max) {
    sum += f2;
    temp = 4 * f2 + f1;
    f1 = f2;
    f2 = temp;
  }
  printf("%d\n", sum);
}
