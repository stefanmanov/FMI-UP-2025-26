#include <stdio.h>


int main(void)
{
  {
    printf("Enter a rational number `r`:\t");
    double r = 0.0;
    scanf("%lf", &r);

    printf("Enter a natural number `n`:\t");
    unsigned n = 0u;
    scanf("%u", &n);

    double r_to_the_n = r;
    for (unsigned i = 1u; i < n; ++i) {
      r_to_the_n *= r;
    }

    printf("%lf to the power of %u is %lf\n", r, n, r_to_the_n);
  }

  /* --------------------------------------------------------------------------*/

  {
    printf("Enter a rational number `r`:\t");
    double r = 0.0;
    scanf("%lf", &r);

    printf("Enter a natural number `n`:\t");
    unsigned n = 0u; // The previous `n` is out of scope here.
    scanf("%u", &n);

    double r_to_the_n = 1.0;
    do {
      r_to_the_n *= r;
      --n;
    } while (n > 0);

    printf("%lf to the power of %u is %lf\n", r, n, r_to_the_n);
  }

  return 0;
}
