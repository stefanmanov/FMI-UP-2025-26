#include <stdio.h>

int main(void)
{
    printf("Enter a natural number <= 255:\t");
    unsigned n = 0;
    scanf("%u", &n);

    const unsigned nTrueBits = (
        (n & 1) + ((n >> 1) & 1) + ((n >> 2) & 1) + ((n >> 3) & 1) +
        ((n >> 4) & 1) + ((n >> 5) & 1) + ((n >> 6) & 1) + ((n >> 7) & 1));
    printf("The number of 1 bits in %u is %u\n", n, nTrueBits);

    return 0;
}
