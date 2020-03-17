#include <stdio.h>

int main(int argc, char *argv[]) {
    int acumulador;
    register int i;

    // Digamos que queremos calcular a soma acumulada de números inteiros entre 1 e 100...


    // usando o loop 'for':
    acumulador = 0;
    for (i = 1; i <= 100; i++) {
        acumulador = acumulador + i;
    }
    printf("Soma acumulada (for): %d\n", acumulador);


    // usando o loop 'while':
    acumulador = 0;
    i = 0;
    while (i <= 100) {
        acumulador = acumulador + i;
        i++;
    }
    printf("Soma acumulada (while): %d\n", acumulador);


    // usando o loop 'do while';
    acumulador = 0;
    i = 0;
    do {
        acumulador = acumulador + i;
        i++;
    } while (i <= 100);
    printf("Soma acumulada (do while): %d\n", acumulador);

    return 0;
}