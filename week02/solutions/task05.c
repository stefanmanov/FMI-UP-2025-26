#include <stdio.h>

int main(void)
{
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);

    unsigned hammingDistance = 0u;
    const unsigned largestBit = 1u << (8u * sizeof(int) - 1u);

    for (unsigned currentBit = largestBit; currentBit != 0u; currentBit >>= 1u) {
        if ((x & currentBit) != (y & currentBit)) {
            ++hammingDistance;
        }
    }

    printf("%d\n", hammingDistance);

    return 0;
}
