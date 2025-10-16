#include <math.h>
#include <stdio.h>

int main(void)
{
  double x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

  double dx = x1 - x2;
  double dy = y1 - y2;

  double distance = sqrt(dx * dx + dy * dy);
  printf("The distance is: %lf\n", distance);

  return 0;
}
