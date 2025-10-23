#include <stdio.h>

int main(void)
{
    double a = 0.0, b = 0.0, c = 0.0;
    scanf("%lf %lf %lf", &a, &b, &c);

    int isValidTriangle = a > 0 && b > 0 && c > 0;
    isValidTriangle = isValidTriangle && a < b + c && b < a + c && c < a + b;
    printf("%s\n", isValidTriangle? "YES" : "NO");

    return 0;
}
