#include "pilhaenc.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int sair = 0;
    TPilhaEnc* pi;

    while(sair == 0) {
            printf( "Editor de Pilha v2.0\n"
                        "================\n"
                        "1- Inicializar \n"
                        "2- Empilhar \n"
                        "3- Desempilhar \n"
                        "4- Elemento do topo \n"
                        "5- Imprimir pilha \n"
                        "6- Esvaziar a pilha \n"
                        "7- Base da pilha\n"
                        "8- Tamanho da pilha \n"
                        "9- Desempilha N elementos"
                        "10-Mostrar sub-topo"
                        "0- Sair \n"
                        "\n"
                        "Digite sua opcao: ");
        int opcao; scanf("%d", &opcao);
        printf("-------------------\n");

        switch ( opcao )
        {
            case 1 :
                // Inicializar
                break;

            case 2 :
                // Empilhar
                break;

            case 3 :
                // Desempilhar
                break;

            case 4 :
                // Exibir elemento do topo
                break;

            case 5 :
                // Imprimir a pilha
                break;

            case 6 :
                // Esvaziar a pilha
                break;

            case 7 :
                // Base da pilha
                break;

            case 8 :
                // Tamanho da pilha
                break;

            case 9 :
                // Desempilha N elementos
                break;

            case 10 :
                // Mostra sub-topo
                break;

            case 0 :
                // Sair
                sair++;
                printf("Saindo... \n");
                break;
        }

        printf("-------------------\n");
    }

    return 0;
}
