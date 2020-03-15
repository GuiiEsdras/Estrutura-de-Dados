#include "FilaPrioritaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Programa de teste para Fila Prioritaria
// Para compilar: gcc FilaPrioritaria.h FilaPrioritaria.c Fila.h Fila.c testaFilas.c -o testaFP

int main() {
    /**** TESTA FILA PRIORITARIA SEM ENTRADAS ****/
    printf("\n|--- Inicio do Programa ---|\n\n");

    FilaPrioritaria* filaPriori;
    filaPriori = criaFilaPrioritaria();
    if ( filaPriori != NULL ) printf("Filas criadas com sucesso!\n");
    printaFilaFP(filaPriori);

    enfileirarFP(filaPriori, "Goku", 47);
    enfileirarFP(filaPriori, "Fulana de Tal", 81);
    enfileirarFP(filaPriori, "Manolinho", 22);
    enfileirarFP(filaPriori, "Exe", 65);
    enfileirarFP(filaPriori, "Tony Stark", 18);
    enfileirarFP(filaPriori, "Derpina", 58);
    enfileirarFP(filaPriori, "Derp", 92);
    printaFilaFP(filaPriori);
    
    Pessoa umaPessoa;
    for(register int i=0; i < 5; i++) {
        desenfileirarFP(filaPriori, &umaPessoa);
        if (umaPessoa.idade < 65) printf("%s, %d, saiu da fila para menores de 65 anos!\n", umaPessoa.nome, umaPessoa.idade);
        else if (umaPessoa.idade >= 65) printf("%s, %d, saiu da fila para maiores de 65 anos!\n", umaPessoa.nome, umaPessoa.idade);
    }
    printaFilaFP(filaPriori);

    if(limpaFilaFP(filaPriori)) printf("Filas esvaziadas!\n");
    printaFilaFP(filaPriori);

    printf("\n|--- Fim do Programa ---|\n");
    return 0;
}