#include <stdio.h>

int main(int argc, char *argv[]) {
    int a = 2;
    int b = 3;
    printf("a / b = %.3f\n", a/b); // causa um Warning. Tipo de resposta incompatível. Resultado inesperado.
    printf("a / b = %.3f\n", (double) a/b);
    return 0;
}