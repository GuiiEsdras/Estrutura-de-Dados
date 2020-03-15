#include <stdio.h>

int main() {

    // .::Constantes numéricas::. //
    
    int n = 1234; // Constante do tipo int
    double d = 123.4, c = 1e-2; // Constantes do tipo double

    // Podemos escrever números em octal ou hexadecimal em vez de decimal:

    int ano = 1984; // constante inteira 1984

    // Para Octal, adiciona-se um 0 no inicio do número
    int anoOctal = 03700; // 1984 em octal

    // Para Hexadecimal, adiciona-se um 0x no inicio do número
    int anoHex = 0x7c0; // 1984 em hexadecimal

    printf("1984 em decimal é %d \n", 1984);
    printf("1984 em octal é 0%o \n", 1984);
    printf("1984 em hexadecimal é 0x%x \n", 1984);
    printf("0123 em decimal é %d \n", 0123);
    printf("0x12f em decimal é %d \n", 0x12f);
}