#include <math.h>
#include <stdio.h>

int main(void)
{
  printf("Enter the choice parameter c:\t");
  unsigned c = 0;
  scanf("%u", &c);

  printf("Enter a real number x:\t");
  double x = 0.0;
  scanf("%lf", &x);

  double y = 0.0;
  switch (c) {
    case 1:
      y = x - 5;
      break;
    case 2:
      y = sin(x);
      break;
    case 3:
      y = cos(x);
      break;
    case 4:
      y = exp(x);
      break;
    default:
      printf("Unexpected value for `c`: %u!\n", c);
      return 1;
  }

  printf("y = %lf\n", y);

  return 0;
}
