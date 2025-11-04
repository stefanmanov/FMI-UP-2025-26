#include <stdbool.h>
#include <stdio.h>


int main(void)
{
  printf("Enter a natural number:\t");
  unsigned n = 0u;
  scanf("%u", &n);

  const unsigned MAX_BIT = 1u << (8 * sizeof(unsigned) - 1);
  bool upBitEncountered = false;

  for (unsigned currentBit = MAX_BIT; currentBit != 0; currentBit >>= 1) {
    bool currentBitUp = ((n & currentBit) == currentBit);
    if (currentBitUp) {
      upBitEncountered = true;
    }

    if (upBitEncountered) { // Start printing on first 1 => skip leading 0s.
      printf("%c", (currentBitUp ? '1' : '0'));
    }
  }

  printf("\n");
  return 0;
}
