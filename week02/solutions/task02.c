#include <stdio.h>

int main(void)
{
    double x = 0.0, y = 0.0;
    scanf("%lf %lf", &x, &y);

    int circle1 = ((x * x + y * y) <= 4) && y >= 0;
    int circle2 = (x + 1) * (x + 1) + y * y <= 1;
    int circle3 = (x - 1) * (x - 1) + y * y <= 1;

    int result = (circle1 || circle2) && !circle3;
    printf("%s\n", result? "YES" : "NO");

    return 0;
}
