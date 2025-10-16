#include <stdio.h>

int main(void)
{
  // int a, b, c;
  // scanf("%d %d %d", &a, &b, &c);

  // int perimeter = a + b + c;
  // printf("The perimeter is %d\n", perimeter);

  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);

  double perimeter = a + b + c;
  printf("The perimeter is %lf\n", perimeter);

  return 0;
}
