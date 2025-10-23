#include <stdio.h>

int main(void)
{
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);

    int hammingDistance = 0;
    const int largestBit = 1 << (8 * sizeof(int) - 2);

    for (int currentBit = largestBit; currentBit > 0; currentBit >>= 1) {
        if ((x & currentBit) != (y & currentBit)) {
            ++hammingDistance;
        }
    }

    printf("%d\n", hammingDistance);

    return 0;
}
