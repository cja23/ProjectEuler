/* Euler Problem 4: Find the largest palindromic number formed from the product
   of two 3-digit numbers.

   Language: C
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int largest = 0;

// Function to check if integer is palindrome. Only works for 6 digits or less.
// Used by all implementations below.
bool isPalindrome(int n) {
  char n2str[7];
  int length = sprintf(n2str, "%d", n);
  int left = 0, right = length - 1;
  while(right - left > 0) {
    if(n2str[left] != n2str[right])
      return false;
    left++;
    right--;
  }
  return true;
}

// Straightforward implementation
/*
void main() {
  int x = 100, y = 100;
  while(x < 1000) {
    while(y < 1000) {
      if(isPalindrome(x * y) && x * y > largest)
        largest = x * y;
      y++;
    }
    x++;
    y = 100;
  }
  printf("%d\n", largest);
}
*/

// More efficient implementation using the following improvements:
// 1. Count x and y down from 999 so we hit big palindromes sooner.
// 2. Stop the inner loop when y gets smaller than x since these will be
//    duplicates of cases already found just with x and y reversed.
// 3. Stop the inner loop once we are smaller than the largest palindrome found
//    thus far since the rest of the iterations must be smaller.
/*
void main() {
  int x = 999, y = 999;
  while(x > 99) {
    while(y >= x) {
      if(x * y <= largest)
        break;
      if(isPalindrome(x * y))
        largest = x * y;
      y--;
    }
    x--;
    y = 999;
  }
  printf("%d\n", largest);
}
*/

// Finally, we can be even cleverer. If the digits of our 6-digit palindrome
// "abccba" are a, b, and c satisfying:
// p = 100000a + 10000b + 1000c + 100c + 10b + a, this also can be written as:
// p = 11(9091a + 910b + 100c).
// So we know that one or both of our factors, x and/or y, must be divisible by
// 11. Thus, we can increase efficiency by only checking cases where at least
// one of x or y is divisible by 11.

void main() {
  int x = 999, y = 999, dy = 1;
  while(x > 99) {
    if(x % 11 != 0) {
      y = 990;
      dy = 11;
    }
    while(y >= x) {
      if(x * y <= largest)
        break;
      if(isPalindrome(x * y))
        largest = x * y;
      y -= dy;
    }
    x--;
    y = 999;
    dy = 1;
  }
  printf("%d\n", largest);
}
