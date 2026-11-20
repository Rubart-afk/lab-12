#include <stdio.h>

int main(void)
{
    int N, i;
    double factorial = 1.0;

    printf("Введите N: ");
    scanf("%d", &N);

    if (N < 0) {
        printf("N должно быть неотрицательным\n");
        return 1;
    }

    for (i = 1; i <= N; i++)
        factorial *= i;

    printf("%d! = %.0f\n", N, factorial);

    return 0;
}