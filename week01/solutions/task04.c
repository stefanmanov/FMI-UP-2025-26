#include <stdio.h>

int main(void)
{
  int a, b;
  scanf("%d %d", &a, &b);

  // С помощна променлива:
  int buffer = a;
  a = b;
  b = buffer;
  
  printf("a = %d b = %d\n", a, b);

  // С аритметични операции:
  a = a + b;
  b = a - b;
  a = a - b;

  printf("a = %d b = %d\n", a, b);

  return 0;
}
