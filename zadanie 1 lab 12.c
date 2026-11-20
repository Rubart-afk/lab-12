#include <stdio.h>

int main(void)
{
    FILE *out = fopen("number.txt", "a");

    if (out == NULL) {
        printf("Ошибка открытия файла для записи\n");
        return 1;
    }

    fprintf(out, "12,56\n");

    fclose(out);

    return 0;
}