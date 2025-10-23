#include <stdio.h>

int singleNumber(const int* nums, int numsSize)
{
    int result = 0;
    for (int i = 0; i < numsSize; ++i) {
        result ^= nums[i];
    }
    return result;
}

int main(void)
{
    const int numbers[] = {4,1,2,1,2};
    int found = singleNumber(numbers, sizeof(numbers) / sizeof(int));
    printf("%d\n", found);

    return 0;
}
