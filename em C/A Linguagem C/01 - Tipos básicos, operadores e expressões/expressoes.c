#include <stdio.h>

int main(int argc, char *argv[]) {

    // .::Operadores Aritméticos::. //
    int a = 100, b = 2, c = 25, d = 4;
    int resultado1, resultado2, resultado3;
    resultado1 = a * b + c * d;
    resultado2 = (a * b) + (c * d);
    resultado3 = a * (b + c) * d;
    printf("resultado1 = %d, resultado2 = %d, resultado3 = %d\n", resultado1, resultado2, resultado3);

    // .::Operadores Relactionais: > (maior), >= (maior ou igual), < (menor), <= (menor ou igual), != (diferente), == (igual)
    // .::Operadores Lógicos: && (AND / e), || (OR / ou)

    if (resultado1 >= resultado2) {
        printf("resultado1 é maior ou igual ao resultado2\n");
    } else if ((resultado3 < resultado1) || (resultado3 > resultado2)) {
        printf("resultado3 menor que resultado1 ou é maior que resultado2\n");
    } else if ((resultado3 == resultado2) && (resultado1 == resultado3)) {
        printf("todos iguais\n");
    }

    return 0;
}