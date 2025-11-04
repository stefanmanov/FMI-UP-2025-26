#include <stdio.h>


int main(void)
{
  printf("Enter a natural number:\t");
  unsigned n = 0u;
  scanf("%u", &n);

  unsigned sum = 0u;
  const unsigned fourBitMask = 0b1111;

  for (unsigned i = 0u; i < 2 * sizeof(unsigned); ++i) {
    const unsigned currentMask = fourBitMask << (i * 4);
    const unsigned currentNumber = (n & currentMask) >> (i * 4);
    sum += currentNumber;
  }

  printf("%u\n", sum);
  return 0;
}
