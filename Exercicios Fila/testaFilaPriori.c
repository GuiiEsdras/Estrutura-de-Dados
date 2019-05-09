#include "FilaPrioritaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// gcc FilaPrioritaria.h FilaPrioritaria.c Fila.h Fila.c testaFilas.c -o testaFP

int main() {
    /**** TESTA FILA PRIORITARIA SEM ENTRADAS ****/

    //printf("Inicio\n");

    FilaPrioritaria* filaPriori;
    filaPriori = criaFilaPrioritaria();

    printaFilaFP(filaPriori);

    enfileirarFP(filaPriori, "Goku", 47);
    enfileirarFP(filaPriori, "Fulana de Tal", 81);
    enfileirarFP(filaPriori, "Manolinho", 22);
    enfileirarFP(filaPriori, "Tony Stark", 18);
    enfileirarFP(filaPriori, "Derpina", 58);
    enfileirarFP(filaPriori, "Derp", 92);
    printaFilaFP(filaPriori);


    Pessoa umaPessoa;
    desenfileirarFP(filaPriori, &umaPessoa);
    printf("%s (%d anos), saiu!\n", umaPessoa.nome, umaPessoa.idade);

    desenfileirarFP(filaPriori, &umaPessoa);
    printf("%s (%d anos), saiu!\n", umaPessoa.nome, umaPessoa.idade);

    desenfileirarFP(filaPriori, &umaPessoa);
    printf("%s (%d anos), saiu!\n", umaPessoa.nome, umaPessoa.idade);

    printaFilaFP(filaPriori);


    limpaFilaFP(filaPriori);
    printaFilaFP(filaPriori);

    return 0;
}