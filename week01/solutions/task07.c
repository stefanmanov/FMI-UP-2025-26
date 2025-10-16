#include <stdio.h>

int main(void) {
  int a = 0;
  printf("Enter a three-digit integer:\t");
  scanf("%d", &a);

  unsigned digits_gt_5 = (a % 10 > 5) + ((a / 10) % 10 > 5) + ((a / 100) % 10 > 5);
  printf("The number of digits greater than 5 is %d\n", digits_gt_5);
  // 1) Doesn't work with negative integers: try -666. Modulo (%) returns a
  // negative result when its first parameter is negative.
  // 2) Correctly works with non-integers, which is surprising. `scanf` ignores
  // the decimal point and everything after it when reading integers ("%d").
  // 3) Works for positive integers with more than 3 digits, but only counts their
  // last 3 digits - `% 10` only returns the last digit, and we're never
  // dividing by more than 100, i.e. never discarding more than 2 digits.
  // 4) Of course, doesn't work correctly with integers larger than the type's limit of
  // ~2 billion.
  
  return 0;
}
