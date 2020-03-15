#include "pilhaseq.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sair = 0;
    int cont = 0, cont2 = 0, cont3 = 0;
    int pilha_atual = 1;
    TPilha *p, *p2, *p3;

    while(sair == 0) {
            printf( "Editor de Pilha v1.0\n"
                        "================\n"
                        "1- Inicializar \n"
                        "2- Empilhar \n"
                        "3- Desempilhar \n"
                        "4- Elemento do topo \n"
                        "5- Imprimir pilha \n"
                        "6- Inverter elementos da pilha \n"
                        "7- Esvaziar a pilha \n"
                        "8- Mudar de pilha \n"
                        "0- Sair \n"
                        "\n"
                        "Digite sua opcao: ");
        int opcao; scanf("%d", &opcao);
        printf("-------------------\n");

        switch ( opcao )
        {
            case 1 :
                // Inicializar

                if( pilha_atual == 1 ) {
                    if( cont == 0 ) {
                        p = criaPilha();
                        cont++;
                        printf("Pilha 1 inicializada! \n");
                    } else printf("A pilha 1 ja foi inicializada! \n");
                } else if( pilha_atual == 2 ) {
                    if( cont2 == 0 ) {
                        p2 = criaPilha();
                        cont2++;
                        printf("Pilha 2 inicializada! \n");
                    } else printf("A pilha 2 ja foi inicializada! \n");
                } else if( pilha_atual == 3 ) {
                    if( cont3 == 0 ) {
                        p3 = criaPilha();
                        cont3++;
                        printf("Pilha 3 inicializada! \n");
                    } else printf("A pilha 3 ja foi inicializada! \n");
                }

                break;

            case 2 :
                // Empilhar
                printf("Digite o elemento a ser empilhado: ");
                tipo_pilha elemento; scanf("%d", &elemento);
                empilhar(p, elemento);
                break;

            case 3 :
                // Desempilhar
                desempilhar(p);
                break;

            case 4 :
                // Exibir elemento do topo
                elementoTopo(p);
                break;

            case 5 :
                // Imprimir a pilha
                imprimePilha(p);
                break;

            case 6 :
                // Inverter elementos da pilha
                break;

            case 7 :
                // Esvaziar a pilha
                esvaziaPilha(p);
                break;

            case 8 :
                // Mudar de pilha
                printf("Informe a pilha a ser modificada (1, 2 ou 3): ");
                int aux; scanf("%d", &aux);
                if( aux > 3 || aux < 0 ) printf("Opcao invalida. \n");
                else {
                        pilha_atual = aux;
                        printf("Trabalhando com a pilha %d! \n", pilha_atual);
                }
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
