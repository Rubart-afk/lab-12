#include <stdio.h>
#include <math.h>

int main(void)
{
    FILE *out;
    double a, b, h, x, y;
    int choice, i;

    printf("Функция: y = x^2 + sin(5*x)\n");

    printf("Введите начало и конец интервала: ");
    scanf("%lf %lf", &a, &b);

    printf("Введите шаг табуляции: ");
    scanf("%lf", &h);

    if (h <= 0 || a > b) {
        printf("Неверный интервал или шаг\n");
        return 1;
    }

    printf("1. Запись в новый файл\n");
    printf("2. Дозапись в существующий файл\n");
    scanf("%d", &choice);

    if (choice == 1)
        out = fopen("temp.txt", "w");
    else if (choice == 2)
        out = fopen("temp.txt", "a");
    else
        return 1;

    if (out == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fprintf(out, "|     x      |    f(x)    |\n");

    for (i = 0; ; i++) {
        x = a + i * h;

        if (x > b + 1e-9)
            break;

        y = x * x + sin(5 * x);

        fprintf(out, "| %10.4f | %10.4f |\n", x, y);
    }

    fclose(out);

    return 0;
}