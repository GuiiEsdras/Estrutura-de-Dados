#include "FilaPrioritaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Programa de teste completo das duas filas
// Para compilar: gcc FilaPrioritaria.h FilaPrioritaria.c Fila.h Fila.c testaFilas.c -o "testaFilas"

int eh_NULL(Fila*, FilaPrioritaria*);
void inicieUmaFila();

int main() {
    printf("\n|- !Programa iniciado! -|\n");

    Fila* fila = NULL;
    FilaPrioritaria* filaPrioritaria = NULL;

    char nome[MAX];
    int idade;
    Pessoa umaPessoa;

    int opcao, opfila;
    bool sair = false;
    while (!sair) {
        separador();
        printf( "O que deseja fazer?\n"
                "   [0] - Iniciar uma fila\n"
                "   [1] - Adicionar uma pessoa na fila\n"
                "   [2] - Chamar a proxima pessoa da fila\n"
                "   [3] - Ver tamanho atual da fila\n"
                "   [4] - Ver dados da fila\n"
                "   [5] - Esvaziar fila\n"
                "   [6] - Sair\n"
                "       Digite sua opcao: "); scanf("%d", &opcao);
        
        switch (opcao) {

            case 0:
                separador();
                if( eh_NULL(fila, filaPrioritaria) ) {

                     while (true) {
                        printf( "Escolha o tipo de fila: \n"
                                "   [1] - Fila Normal\n"
                                "   [2] - Fila Prioritaria\n"
                                "       Digite sua opcao: "); scanf("%d", &opfila);
                        if( opfila == FilaNormal || opfila == FilaPriori ) break;
                        else printf("Opcao invalida! Escolha novamente...\n");
                    }

                    switch (opfila) {
                        case 1:
                            separador();
                            fila = criaFila();
                            if ( fila != NULL ) printf("Fila Normal iniciada!\n");
                            else printf("Erro de alocacao!\n");
                            break;
                        case 2:
                            separador();
                            filaPrioritaria = criaFilaPrioritaria();
                            if ( filaPrioritaria != NULL ) printf("Fila Prioritaria iniciada!\n");
                            else printf("Erro de alocacao!\n");
                            break;
                    }
                }

                else printf("Uma fila ja esta sendo executada! Recomece o programa para escolher outra.\n");
                break;

            case 1:
                separador();
                if ( eh_NULL(fila, filaPrioritaria) ) inicieUmaFila();
                else {
                    printf(" Informe os dados da pessoa:\n");

                    printf("Nome: "); getchar(); scanf("%[^\n]s", nome);
                    while (true) {
                        printf("Idade: "); scanf("%d", &idade);
                        if ( idade < 0 ) printf("Idade menor que 0! Digite novamente...\n");
                        else break;
                    }

                    separador();
                    if ( opfila == FilaNormal ) enfileirar(fila, nome, idade);
                    else if ( opfila == FilaPriori ) {
                        enfileirarFP(filaPrioritaria, nome, idade);
                        printf("  Prioritaria: %s\n", idade >= 65 ? "Sim" : "Nao");
                    } 
                }
                break;
             
            case 2:
                separador();
                if ( eh_NULL(fila, filaPrioritaria) ) inicieUmaFila();
                else {
                    if ( opfila == FilaNormal ) {
                        if ( desenfileirar(fila, &umaPessoa) )
                            printf("%s, %d anos, saiu da fila!\n", umaPessoa.nome, umaPessoa.idade);
                        else printf("Fila Vazia!\n");
                    }

                    else if ( opfila == FilaPriori ) {
                        if ( desenfileirarFP(filaPrioritaria, &umaPessoa) ) {
                            if (umaPessoa.idade < 65) printf("- %s, %d, saiu da fila para menores de 65 anos!\n", umaPessoa.nome, umaPessoa.idade);
                            else printf("- %s, %d, saiu da fila para maiores de 65 anos!\n", umaPessoa.nome, umaPessoa.idade);
                        }
                        else printf("Ambas as filas se encontram vazias!\n"); 
                    }
                }
                break;
            
            case 3:
                separador();
                if ( eh_NULL(fila, filaPrioritaria) ) inicieUmaFila();
                else {
                    if ( opfila == FilaNormal ) {
                        if ( !(tamanhoDaFila(fila) < 0) ) printf("Esta fila tem %d pessoa(s) no momento!\n", tamanhoDaFila(fila));
                        else printf("A fila nao foi iniciada!\n");
                    }
                    else if ( opfila == FilaPriori ) tamanhoDaFilaFP(filaPrioritaria);
                }
                break;
            
            case 4:
                separador();
                if( eh_NULL(fila, filaPrioritaria) ) inicieUmaFila();
                else {
                    if ( opfila == FilaNormal ) printaFila(fila);
                    else if ( opfila == FilaPriori ) printaFilaFP(filaPrioritaria);
                }
                break;
            
            case 5:
                separador();
                if( eh_NULL(fila, filaPrioritaria) ) inicieUmaFila();
                else {
                    if ( opfila == FilaNormal ) {
                        if ( limpaFila(fila) ) printf("Fila esvaziada!\n");
                        else printf("Erro! Lista vazia ou nao iniciada!\n");
                    } 

                    else if ( opfila == FilaPriori ) {
                        if ( limpaFilaFP(filaPrioritaria) ) printf("Filas esvaziadas!\n");
                        else printf("Fila prioritaria vazia!\n");
                    }
                }
                break;
            
            case 6:
                separador();
                if ( eh_NULL(fila, filaPrioritaria) ) printf("Saindo...\n");
                else {
                    if ( opfila == FilaNormal ) terminarFila(fila);
                    else if ( opfila == FilaPriori ) terminarFilaFP(filaPrioritaria);
                }
                sair=true;
                break;
            
            default:
                separador();
                printf("\nOpcao invalida!\n");
                break;
        }

    }

    separador();
    printf("|- Programa encerrado! -|\n");
    return 0;
}


int eh_NULL(Fila* f, FilaPrioritaria* fp) {
    return ( (f == NULL) && (fp == NULL) );
}

void inicieUmaFila() { 
    printf("Inicie um tipo de fila primeiro!\n");
}