#include "FilaPrioritaria.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FilaPrioritaria* criaFilaPrioritaria() {
    FilaPrioritaria* fp = (FilaPrioritaria*) malloc( sizeof(FilaPrioritaria) );
    if ( fp == NULL ) return NULL;

    fp->mais65 = criaFila();
    fp->menos65 = criaFila();
    return fp;
}

int enfileirarFP(FilaPrioritaria* fp, char* nome, int idade) {
    if ( fp == NULL ) return false;

    if ( idade >= 65 ) {
        if( !enfileirar(fp->mais65, nome, idade) ) {
            return false;
        }
    }

    else if ( idade < 65) {
        if ( !enfileirar(fp->menos65, nome, idade) ) {
            return false;
        }
    }

    return true;
}

int desenfileirarFP(FilaPrioritaria* fp, Pessoa* p_ret) {
    if ( fp == NULL ) { 
        return false; 
    }

    Pessoa* p_aux = p_ret;
    if ( desenfileirar(fp->mais65, p_aux) ) return true;
    else if ( desenfileirar(fp->menos65, p_aux) ) return true;
    else return false;
}

int limpaFilaFP(FilaPrioritaria* fp) {
    if ( fp == NULL ) return false;
    else if( (fp->mais65->inicio == NULL) && (fp->menos65->inicio == NULL) ) return false;

    if ( limpaFila(fp->mais65) ) {
        if ( limpaFila(fp->menos65) ) {
            return true;
        } else return true;
    }
    else if ( limpaFila(fp->menos65) ) return true;
    return false;
}


void printaFilaFP(FilaPrioritaria* fp) {

    printf("\t---\t\n");

    printf("|Pessoas na Fila > 65|\n");
    
    if ( fp->mais65->inicio == NULL ) {
        printf("------ Vazia ------\n");
    }

    else {
        PessoaNaFila* pessoaAux = fp->mais65->inicio;
        for(register int i = 0; i < fp->mais65->tamanhoDaFila; i++) {
            printf("Posicao: %d | Nome: %s - Idade: %d\n", i+1, pessoaAux->p.nome, pessoaAux->p.idade);
            pessoaAux = pessoaAux->prox;
        }
    }

    printf("\t---\t\n");

    printf("|Pessoas na Fila < 65|\n");

    if ( fp->menos65->inicio == NULL ) {
        printf("------ Vazia ------\n");
    }

    else {
        PessoaNaFila* pessoaAux2 = fp->menos65->inicio;
        for(register int i = 0; i < fp->menos65->tamanhoDaFila; i++) {
            printf("Posicao: %d | Nome: %s - Idade: %d\n", i+1, pessoaAux2->p.nome, pessoaAux2->p.idade);
            pessoaAux2 = pessoaAux2->prox;
        }
    }

    printf("\t---\t\n");
}

void tamanhoDaFilaFP(FilaPrioritaria* fp) {
    if(fp == NULL) {
        printf("Fila Prioritaria nao iniciada!\n");
    } else {
        printf("Fila > 65: %d pessoa(s)!\n", fp->mais65->tamanhoDaFila);
        printf("Fila < 65: %d pessoa(s)!\n", fp->menos65->tamanhoDaFila);
    }
}

void terminarFilaFP(FilaPrioritaria* fp) {
    printf("Saindo...\n");
    free(fp);
}