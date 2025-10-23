#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int result = 0;

    int targetOffset = 8 * sizeof(int) - 1;
    while (n != 0) {
        result |= (n & 1) << targetOffset;

        n >>= 1;
        --targetOffset;
    }

    printf("%d\n", result);

    return 0;
}
