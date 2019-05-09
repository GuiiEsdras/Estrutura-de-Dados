#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// gcc Fila.h Fila.c testaFilaNormal.c -o testaFN

int main() {
    /**** TESTA FILA NORMAL SEM ENTRADAS ****/
    Fila* fila;
    fila = criaFila();

    separador();
    printaFila(fila);

    separador();
    enfileirar(fila, "Goku", 37);
    enfileirar(fila, "Fulano de Tal", 71);
    enfileirar(fila, "Manolinho", 12);
    enfileirar(fila, "Tony Stark", 58);
    printaFila(fila);

    Pessoa umaPessoa;
    desenfileirar(fila, &umaPessoa);
    printf("%s (%d anos), era o primeiro da fila e saiu!\n", umaPessoa.nome, umaPessoa.idade);

    printaFila(fila);

    limpaFila(fila);
    printaFila(fila);

    return 0;
}