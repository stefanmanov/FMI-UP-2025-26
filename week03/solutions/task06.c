#include <math.h>
#include <stdio.h>


int main(void)
{
    const double EPSILON = 0.0001;

    double a = 0.0, b = 0.0, c = 0.0;
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a < 0 || b < 0 || c < 0 || a >= b + c || b >= a + c || c >= a + b) {
        printf("Invalid data!\n");
    }
    else {
        // Пример за сравнения за равенство при определена точност:
        if (fabs(a - b) < EPSILON && fabs(a - c) < EPSILON && fabs(b - c) < EPSILON) {
            printf("Triangle is equilateral\n");
        }
        else if (fabs(a - b) < EPSILON || fabs(a - c) < EPSILON || fabs(b - c) < EPSILON) {
            printf("Triangle is isosceles\n");
        }
        else {
            printf("Triangle is scalene\n");
        }
    }

    return 0;
}
