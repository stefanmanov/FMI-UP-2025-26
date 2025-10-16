#include <math.h>
#include <stdio.h>

int main(void)
{
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);

  double p = (a + b + c) / 2;
  printf("The area is %lf\n", sqrt(p * (p - a) * (p - b) * (p - c)));

  return 0;
}
