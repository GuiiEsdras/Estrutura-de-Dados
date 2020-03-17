#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;
    for (i = 0; i <= 10; i++) {
        if (i == 0) {
            printf("%d é igual a zero\n", i);
        } else if (i > 0 && i < 10) {
            printf("%d é maior que zero e menor que 10\n", i);
        } else {
            printf("%d é maior ou igual a 10\n", i);
        }
    }

    printf("\n");

    // .::Operador Condicional ou Operador Ternário::.
    for (i = 1; i <= 10; i++) {
        (i % 2) ? printf("%d é ímpar\n", i) : printf("%d é par\n", i);
    }
    return 0;
}