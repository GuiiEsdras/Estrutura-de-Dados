#include "FilaPrioritaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// gcc FilaPrioritaria.h FilaPrioritaria.c Fila.h Fila.c testaFilas.c -o testaFilas

#define MAX 51
#define FilaNormal 1
#define FilaPriori 2

int eh_NULL(Fila*, FilaPrioritaria*);
void inicieUmaFila();

int main() {
    printf("\n|- !Programa iniciado! -|");

    Fila* fila = NULL;
    FilaPrioritaria* filaPrioritaria = NULL;

    char nome[MAX];
    int idade;
    Pessoa umaPessoa;

    int opcao, opfila, sair=0;
    while(1) {
        separador();
        printf( "O que deseja fazer???\n"
                "   0 - Iniciar uma fila\n"
                "   1 - Adicionar uma pessoa na fila\n"
                "   2 - Chamar a proxima pessoa da fila\n"
                "   3 - Ver tamanho atual da fila\n"
                "   4 - Ver dados da fila\n"
                "   5 - Esvaziar fila\n"
                "   6 - Sair\n"
                "       Digite sua opcao: "); scanf("%d", &opcao);
        
        switch(opcao) {

            case 0:
                separador();
                if( eh_NULL(fila, filaPrioritaria) ) {
                     while(1) {
                        printf( "\nQual tipo de fila vc deseja iniciar? \n"
                                "   1 - Fila Normal\n"
                                "   2 - Fila Prioritaria\n"
                                "       Digite sua opcao: "); scanf("%d", &opfila);
                        if( opfila == FilaNormal || opfila == FilaPriori ) break;
                        else printf("\nOpcao invalida! Escolha novamente...\n");
                    }

                    switch (opfila) {
                        case 1:
                            separador();
                            fila = criaFila();
                            break;
                        case 2:
                            separador();
                            filaPrioritaria = criaFilaPrioritaria();
                            break;
                    }
                }
                else printf("\nUma fila ja foi iniciada!\n");
                break;

            case 1:
                separador();
                if( eh_NULL(fila, filaPrioritaria) ) inicieUmaFila();
                else {
                    printf("\n|Informe os dados da pessoa|\n");
                    getchar();
                    printf("Nome: "); scanf("%[^\n]s", nome);
                    printf("Idade: "); scanf("%d", &idade);
                    if(opfila == FilaNormal) enfileirar(fila, nome, idade);
                    else if(opfila == FilaPriori) enfileirarFP(filaPrioritaria, nome, idade);
                }
                break;
             
            case 2:
                separador();
                if( eh_NULL(fila, filaPrioritaria) ) inicieUmaFila();
                else {
                    if(opfila == FilaNormal) {
                        if(desenfileirar(fila, &umaPessoa))
                            printf("\n%s, %d anos, saiu da fila!\n", umaPessoa.nome, umaPessoa.idade);
                    }
                    else if(opfila == FilaPriori) {
                        if(desenfileirarFP(filaPrioritaria, &umaPessoa) == FilaNormal) {
                            printf("\n%s (%d anos) saiu da fila!\n", umaPessoa.nome, umaPessoa.idade);
                        }
                        else if(desenfileirarFP(filaPrioritaria, &umaPessoa) == FilaPriori) {
                            printf("\n%s (%d anos) saiu da fila prioritaria!\n", umaPessoa.nome, umaPessoa.idade);
                        }
                        else printf("\nAmbas as filas se encontram vazias!\n"); 
                    }
                }
                break;
            
            case 3:
                separador();
                if( eh_NULL(fila, filaPrioritaria) ) inicieUmaFila();
                else {
                    if(opfila == FilaNormal) {
                        if(fila != NULL) printf("\nEsta fila tem %d pessoa(s) no momento!\n", tamanhoDaFila(fila));
                        else printf("\nA fila nao foi iniciada!\n");
                    }
                    else if(opfila == FilaPriori) tamanhoDaFilaFP(filaPrioritaria);
                }
                break;
            
            case 4:
                separador();
                if( eh_NULL(fila, filaPrioritaria) ) inicieUmaFila();
                else {
                    if(opfila == FilaNormal) printaFila(fila);
                    else if(opfila == FilaPriori) printaFilaFP(filaPrioritaria);
                }
                break;
            
            case 5:
                separador();
                if( eh_NULL(fila, filaPrioritaria) ) inicieUmaFila();
                else {
                    if(opfila == FilaNormal) limpaFila(fila);
                    else if(opfila == FilaPriori) limpaFilaFP(filaPrioritaria);
                }
                break;
            
            case 6:
                separador();
                if( eh_NULL(fila, filaPrioritaria) ) printf("Saindo...");
                else {
                    if(opfila == FilaNormal) terminarFila(fila);
                    else if(opfila == FilaPriori) terminarFilaFP(filaPrioritaria);
                }
                sair=1;
                break;
            
            default:
                separador();
                printf("\nOpcao invalida!\n");
                break;
        }

        if(sair) break;
    }

    separador();
    printf("|- Programa encerrado! -|\n");
    return 0;
}


int eh_NULL(Fila* f, FilaPrioritaria* fp) {
    return ( (f == NULL) && (fp == NULL) );
}

void inicieUmaFila() { 
    printf("\nInicie um tipo de fila primeiro!\n");
}
