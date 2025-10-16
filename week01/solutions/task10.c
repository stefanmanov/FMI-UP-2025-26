#include <math.h>
#include <stdio.h>

int main(void)
{
  printf("Enter a number between 1 and 26:\t");
  int n = 0;
  scanf("%d", &n);

  // За да не помним ASCII таблицата и да няма магически числа:
  const char firstLowercase = 'a';
  char nthLowercase = firstLowercase + n - 1;
  printf("The %d. lowercase letter of the Latin alphabet is %c.\n", n, nthLowercase);

  const char firstUppercase = 'A';
  char nthUppercase = nthLowercase + firstUppercase - firstLowercase;
  printf("The %d. uppercase letter of the Latin alphabet is %c.\n", n, nthUppercase);

  printf("Enter a lowercase Latin character:\t");
  char ch = 'a';
  scanf(" %c", &ch);

  char chUppercase = ch + firstUppercase - firstLowercase;
  printf("The uppercase version of %c is %c.\n", ch, chUppercase);

  return 0;
}
