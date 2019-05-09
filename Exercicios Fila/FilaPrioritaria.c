#include "FilaPrioritaria.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FilaPrioritaria* criaFilaPrioritaria() {
    FilaPrioritaria* fp = (FilaPrioritaria*) malloc(sizeof(criaFilaPrioritaria()));
    if( fp == NULL ) return NULL;

    fp->mais65->inicio = NULL;
    fp->mais65->fim = NULL;
    fp->mais65->tamanhoDaFila = 0;

    fp->menos65->inicio = NULL;
    fp->menos65->fim = NULL;
    fp->menos65->tamanhoDaFila = 0;

    printf("Fila Prioritaria iniciada com sucesso!\n");
    return fp;
}

int enfileirarFP(FilaPrioritaria* fp, char* nome, int idade) {
    if(fp == NULL) {
        printf("Fila Prioritaria nao iniciada!\n");
        return 0;
    }

    else if( idade < 0 ) {
        printf("Idade fora dos limites!\n");
        return 0;
    }

    else {
        PessoaNaFila* novaPessoa = (PessoaNaFila*) malloc(sizeof(PessoaNaFila));
    
        strcpy(novaPessoa->p.nome, nome);
        novaPessoa->p.idade = idade;

        if( idade >= 65) {
            if( fp->mais65->fim != NULL ) {
                fp->mais65->fim->prox = novaPessoa;
                fp->mais65->fim = novaPessoa;
            } 
            else {
                fp->mais65->inicio = novaPessoa;
                fp->mais65->fim = novaPessoa;
            }

            fp->mais65->tamanhoDaFila++;
            printf("%s (%d anos) entrou na fila para maiores de 65 anos!\n", nome, idade);
        }

        else {
            if( fp->menos65->fim != NULL ) {
                fp->menos65->fim->prox = novaPessoa;
                fp->menos65->fim = novaPessoa;
            }
            else {
                fp->menos65->inicio = novaPessoa;
                fp->menos65->fim = novaPessoa;
            }

            fp->menos65->tamanhoDaFila++;
            printf("%s (%d anos) entrou na fila para menores de 65 anos!\n", nome, idade);
        }

        return 1;
    }
}

int desenfileirarFP(FilaPrioritaria* fp, Pessoa* p_ret) {
    if(fp == NULL) { 
        printf("Fila Prioritaria nao iniciada!\n");
        return 0; 
    }

    else {
        PessoaNaFila* pessoaTemp;

        if( fp->mais65->inicio != NULL ) {
            pessoaTemp = fp->mais65->inicio;
            *p_ret = pessoaTemp->p;

            fp->mais65->inicio = fp->mais65->inicio->prox;

            if( fp->mais65->inicio == NULL ) {
                fp->mais65->fim = NULL;
            }

            free(pessoaTemp);
            fp->mais65->tamanhoDaFila--;
            return 1;
        }

        else if( fp->menos65->inicio != NULL ) {
            pessoaTemp = fp->menos65->inicio;
            *p_ret = pessoaTemp->p;

            fp->menos65->inicio = fp->menos65->inicio->prox;

            if( fp->menos65->inicio == NULL ) {
                fp->menos65->fim = NULL;
            }

            free(pessoaTemp);
            fp->menos65->tamanhoDaFila--;
            return 1;
        }

        else return -1;
    }
}

int limpaFilaFP(FilaPrioritaria* fp) {
    if(fp == NULL) {
        printf("Fila Prioritaria nao iniciada!\n");
        return 0;
    }

    else if( (fp->mais65->inicio == NULL) && (fp->menos65->inicio == NULL) ) {
        printf("Ambas as filas se encontram vazias!\n");
    }

    else {

        while( fp->mais65->inicio != NULL ) {
            PessoaNaFila* Aux = fp->mais65->inicio;
            fp->mais65->inicio = fp->mais65->inicio->prox;
            free(Aux);
        }
        fp->mais65->fim = NULL;
        fp->mais65->tamanhoDaFila = 0;
        
        while( fp->menos65->inicio != NULL ) {
            PessoaNaFila* Aux2 = fp->menos65->inicio;
            fp->menos65->inicio = fp->menos65->inicio->prox;
            free(Aux2);
        }
        fp->menos65->fim = NULL;
        fp->menos65->tamanhoDaFila = 0;

        printf("Filas esvaziadas!\n");
        return 1;
    }
}


int printaFilaFP(FilaPrioritaria* fp) {
    if(fp == NULL) {
        printf("Fila Prioritaria nao iniciada!\n");
        return 0;
    }

    else if( (fp->mais65->inicio == NULL) && (fp->menos65->inicio == NULL) ) {
        printf("Ambas as filas se encontram vazias!\n");
    }

    else {

        if( fp->mais65->inicio == NULL ) {
            printf("\n Fila para maiores de 65 anos vazia!\n");
        }
        else {
            printf("\n|Pessoas na Fila >= 65|\n");

            PessoaNaFila* pessoaAux = fp->mais65->inicio;
            int cont = 1;
            while(pessoaAux != NULL) {
                printf("Posicao: %d | Nome: %s - Idade: %d\n", cont, pessoaAux->p.nome, pessoaAux->p.idade);
                pessoaAux = pessoaAux->prox;
                cont++;
            }
        }

        if( fp->menos65->inicio == NULL ) {
            printf("\n Fila para menores de 65 anos vazia!\n");
        }
        else {
            printf("\n|Pessoas na Fila <= 65|\n");

            PessoaNaFila* pessoaAux2 = fp->mais65->inicio;
            int cont2 = 1;
            while(pessoaAux2 != NULL) {
                printf("Posicao: %d | Nome: %s - Idade: %d\n", cont2, pessoaAux2->p.nome, pessoaAux2->p.idade);
                pessoaAux2 = pessoaAux2->prox;
                cont2++;
            }
        }

    }
}

void tamanhoDaFilaFP(FilaPrioritaria* fp) {
    if(fp == NULL) {
        printf("Fila Prioritaria nao iniciada!\n");
    } else {
        printf("\n");
        printf("A Fila para maiores de 65 anos tem %d pessoa(s)!\n", fp->mais65->tamanhoDaFila);
        printf("A Fila para menores de 65 anos tem %d pessoa(s)!\n", fp->menos65->tamanhoDaFila);
    }
}

void terminarFilaFP(FilaPrioritaria* fp) {
    printf("Saindo...\n");
    free(fp);
}