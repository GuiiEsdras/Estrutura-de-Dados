#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main(void) {
    int x[3] = {10,20,30};
    int *pt;

    system("cls");              // essa função limpa a tela, nas minhas IDEs o clrscr() não funcionou
    pt = x;                     // pt aponta para o primeiro elemento do vetor x, ou seja, 10
    pt++;                       // agora pt aponta para o segundo elemento do vetor x, ou seja, 20
    printf("\n%d ", *(--pt));   // irá retroceder uma posição e imprimir o valor, ou seja, 10
    printf("\n%d ", *pt);       // pt aponta para 10, imprime 10
    pt = &x[0];                 // pt agora aponta para o primeiro valor de x, ou seja, 10
    printf("\n%d ", *(pt++));   // irá imprimir o valor da posição atual (10) e DEPOIS do print avançar uma posição e apontar para 20
    printf("\n%d ", *pt);       // agora pt está apontando para 20

}