#include <stdio.h>

int main(void)
{
    printf("Enter three numbers:\t");
    float a = 0.0f, b = 0.0f, c = 0.0f;
    scanf("%f %f %f", &a, &b, &c);

    printf("The numbers sorted in increasing order are:\t");
    if (a < b) {
        if (b < c) {
            printf("%f %f %f\n", a, b, c);
        }
        else if (a < c) {
            printf("%f %f %f\n", a, c, b);
        }
        else {
            printf("%f %f %f\n", c, a, b);
        }
    }
    else if (b < c) {
        if (a < c) {
            printf("%f %f %f\n", b, a, c);
        }
        else {
            printf("%f %f %f\n", b, c, a);
        }
    }
    else {
        printf("%f %f %f\n", c, b, a);
    }

    return 0;
}
