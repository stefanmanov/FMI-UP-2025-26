#include <math.h>
#include <stdio.h>

int main(void)
{
    const double PI = 3.141592;

    double radius = 0.0;
    scanf("%lf", &radius);

    double volume = pow(radius, 3) * PI * 4/3;
    printf("%lf\n", volume);

    return 0;
}
