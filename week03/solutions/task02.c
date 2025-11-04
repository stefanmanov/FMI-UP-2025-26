#include <stdio.h>


int main(void)
{
    unsigned n = 0u;
    scanf("%u", &n);

    unsigned hammingWeight = 0u;
    const unsigned largestBit = 1u << (8u * sizeof(unsigned) - 1u);

    for (unsigned currentBit = largestBit; currentBit != 0u; currentBit >>= 1u) {
        if ((n & currentBit) != 0) {
            ++hammingWeight;
        }
    }

    int nIsPowerOf2 = (hammingWeight == 1);
    if (nIsPowerOf2) {
        printf("%u is a power of 2\n", n);
    }
    else {
        printf("%u is NOT a power of 2\n", n);
    }

    return 0;
}
