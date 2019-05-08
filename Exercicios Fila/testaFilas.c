#include "FilaPrioritaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /********/
    printf("\n|- Testa Fila Normal -|\n");

    Fila* fila;
    fila = criaFila();
    printaFila(fila);

    enfileirar(fila, "Goku", 37);
    enfileirar(fila, "Fulano de Tal", 71);
    enfileirar(fila, "Manolinho", 12);
    enfileirar(fila, "Tony Stark", 58);
    enfileirar(fila, "Derp", 85);
    printaFila(fila);

    
    Pessoa* umaPessoa;
    desenfileirar(fila, umaPessoa);
    printf("%s (%d anos), saiu da fila!\n", umaPessoa->nome, umaPessoa->idade);

    desenfileirar(fila, umaPessoa);
    printf("%s (%d anos), saiu da fila!\n", umaPessoa->nome, umaPessoa->idade);

    printaFila(fila);

    if( limpaFila(fila) ) printf("Fila esvaziada!\n");

    printaFila(fila);

    /********/
    printf("\n|- Testa Fila Prioritaria -|\n");

    FilaPrioritaria* fp;
    fp = criaFilaPrioritaria();

    return 0;
}