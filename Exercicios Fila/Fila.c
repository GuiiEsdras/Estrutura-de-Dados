#include "Fila.h"
#include <string.h>

Fila* criaFila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if ( fila == NULL ) return NULL;

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanhoDaFila = 0;

    return fila;
}

int enfileirar(Fila* fila, char* nome, int idade) {
    if ( fila == NULL ) return false;
    else if ( idade < 0 ) return false;

    PessoaNaFila* novaPessoa = (PessoaNaFila*) malloc( sizeof(PessoaNaFila) );

    strcpy(novaPessoa->p.nome, nome);
    novaPessoa->p.idade = idade;

    if ( fila->fim == NULL ) {
        fila->inicio = novaPessoa;
        fila->fim = novaPessoa;
    }

    else {
        fila->fim->prox = novaPessoa;
        fila->fim = novaPessoa;
    }

    fila->tamanhoDaFila++;
    printf("> %s (%d anos) entrou na fila!\n", nome, idade);
    return true;
}

int desenfileirar(Fila* fila, Pessoa* p_ret) {
    if ( fila == NULL ) return 0;
    else if ( fila->inicio == NULL ) return 0; 

    *p_ret = (fila->inicio)->p;

    PessoaNaFila* pessoaTemp = fila->inicio;

    fila->inicio = (fila->inicio)->prox;
    if ( fila->inicio == NULL ) fila->fim = NULL;
    fila->tamanhoDaFila--;
    free(pessoaTemp);

    return true;
}

int limpaFila(Fila* fila) {
    if ( fila == NULL ) return 0;
    else if ( fila->inicio == NULL ) return 0;

    do {
        PessoaNaFila* Aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(Aux);
    } while ( fila->inicio != NULL );

    fila->fim = NULL;
    fila->tamanhoDaFila = 0;
    return true;
}


void printaFila(Fila* fila) {
    if ( fila == NULL ) printf("Fila nao iniciada!\n");
    else if ( fila->inicio == NULL ) printf("Fila vazia!\n");
    else {
        printf("|Pessoas na fila|\n");
        PessoaNaFila* pessoaAux = fila->inicio;
        for(register int i = 0; i < tamanhoDaFila(fila); i++) {
            printf("Posicao: %d | Nome: %s - Idade: %d\n", i+1, pessoaAux->p.nome, pessoaAux->p.idade);
            pessoaAux = pessoaAux->prox;
        }
    }
}

int tamanhoDaFila(Fila* f) {
    if ( f != NULL ) return f->tamanhoDaFila;
    else return -1;
}

void terminarFila(Fila* fila) {
    printf("Saindo...\n");
    free(fila);
}


void separador() {
    printf("-----\n");
}