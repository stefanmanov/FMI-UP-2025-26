#include <stdio.h>

int main(void)
{
  // int up, dis1, la, ag;
  // scanf("%d %d %d %d", &up, &dis1, &la, &ag);
  
  double up, dis1, la, ag;
  scanf("%lf %lf %lf %lf", &up, &dis1, &la, &ag);

  double avg = (up + dis1 + la + ag) / 4.0;
  printf("GPA: %lf\n", avg);

  return 0;
}
