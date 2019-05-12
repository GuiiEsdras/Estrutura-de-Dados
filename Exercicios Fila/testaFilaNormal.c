#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Programa de teste para Fila normal
// Para compilar: gcc Fila.h Fila.c testaFilaNormal.c -o testaFN

int main() {
    /**** TESTA FILA NORMAL SEM ENTRADAS ****/
    printf("\n|--- Inicio do Programa ---|\n\n");

    Fila* fila;
    fila = criaFila();
    if ( fila != NULL ) printf("Fila criada com sucesso!\n");

    printaFila(fila);
    printf("Tamanho da fila: %d\n", tamanhoDaFila(fila));

    separador();
    enfileirar(fila, "Goku", 37);
    enfileirar(fila, "Fulano de Tal", 71);
    enfileirar(fila, "Manolinho", 12);
    enfileirar(fila, "Tony Stark", 58);
    separador();

    printaFila(fila);
    printf("Tamanho da fila: %d\n", tamanhoDaFila(fila));
    separador();

    Pessoa umaPessoa;
    if ( desenfileirar(fila, &umaPessoa) ) printf("%s, %d anos, saiu da fila!\n", umaPessoa.nome, umaPessoa.idade);
    separador();
    printaFila(fila);

    separador();
    if ( desenfileirar(fila, &umaPessoa) ) printf("%s, %d anos, saiu da fila!\n", umaPessoa.nome, umaPessoa.idade);
    separador();
    printaFila(fila);

    separador();
    if ( limpaFila(fila) ) printf("Fila esvaziada!\n");
    printaFila(fila);
    printf("Tamanho da fila: %d\n", tamanhoDaFila(fila));

    printf("\n|--- Fim do Programa ---|\n");
    return 0;
}