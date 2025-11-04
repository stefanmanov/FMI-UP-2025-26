#include <stdio.h>


int main(void)
{
    char op = '\0';
    printf("Enter operation:\t");
    scanf("%c", &op);

    int a = 0, b = 0;
    printf("Enter arguments:\t");
    scanf("%d %d", &a, &b);

    switch (op) {
    case '+':
        printf("%d\n", (a + b));
        break;
    case '-':
        printf("%d\n", (a - b));
        break;
    case '*':
        printf("%d\n", (a * b));
        break;
    case '/':
        if (b == 0) {
            printf("Division by zero!\n");
            break;
        }
        printf("%d\n", (a / b));
        break;
    case '%':
        if (b == 0) {
            printf("Division by zero!\n");
            break;
        }
        printf("%d\n", (a % b));
        break;
    default:
        printf("Invalid operation!\n");
        break;
    }
    return 0;
}
