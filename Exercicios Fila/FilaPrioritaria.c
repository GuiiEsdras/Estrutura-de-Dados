#include "FilaPrioritaria.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FilaPrioritaria* criaFilaPrioritaria() {
    FilaPrioritaria* fp = (FilaPrioritaria*) malloc(sizeof(criaFilaPrioritaria()));
    if( fp == NULL ) return NULL;

    fp->mais65->inicio = NULL;
    fp->mais65->fim = NULL;

    fp->menos65->inicio = NULL;
    fp->menos65->fim = NULL;

    printf("Fila Prioritaria iniciada!\n");
    return fp;
}

void enfileirarFP(FilaPrioritaria* fp, char* nome, int idade) {
    PessoaNaFila* novaPessoa = (PessoaNaFila*) malloc(sizeof(PessoaNaFila));
  
    strcpy(novaPessoa->p.nome, nome);
    novaPessoa->p.idade = idade;

    if( idade >= 65) { // caso a idade fornecida seja maior ou igual a 65 anos, insere esta pessoa na fila de maiores de 65;
        if( fp->mais65->fim != NULL ) { // ou seja, se já existir 'alguém' no fim da fila...
            fp->mais65->fim->prox = novaPessoa; // ...a antiga última "pessoa" vai passar a apontar para esta novaPessoa;
            fp->mais65->fim = novaPessoa; // novaPessoa vai passar a ser a última "pessoa" da fila.
        } 
        else { // caso contrário, ou seja, se não existir 'ninguém' no fim da fila, quer dizer que a fila está vazia...
            fp->mais65->inicio = novaPessoa; // ...e novaPessoa vai passar a ser a primeira...
            fp->mais65->fim = novaPessoa; // ...e, também, a última "pessoa" da fila.
        }
    }

    else { // caso seja menor de 65 anos, faz o mesmo processo para a fila de menores de 65;
        if( fp->menos65->fim != NULL ) {
        fp->menos65->fim->prox = novaPessoa;
        fp->menos65->fim = novaPessoa;
        }
        else {
        fp->menos65->inicio = novaPessoa;
        fp->menos65->fim = novaPessoa;
        }
    }
}

int desenfileirarFP(FilaPrioritaria* fp, Pessoa* p_ret) {
    PessoaNaFila* pessoaTemp;

    if( fp->mais65->inicio != NULL ) { // ou seja, se a fila para maiores de 65 tiver alguém...
        // ...inicia o processo de desenfileiramento por esta fila, pois ela tem prioridade.
        pessoaTemp = fp->mais65->inicio;
        *p_ret = pessoaTemp->p;

        fp->mais65->inicio = fp->mais65->inicio->prox;

        if( fp->mais65->inicio == NULL ) {
            fp->mais65->fim = NULL;
        }

        free(pessoaTemp);
        return 0;
    }

    else if( fp->menos65->inicio != NULL ) { // caso a fila para maiores de 65 esteja vazia...
        // ...inicia o processo de desenfileiramento pela fila para menores.
        pessoaTemp = fp->menos65->inicio;
        *p_ret = pessoaTemp->p;

        fp->menos65->inicio = fp->menos65->inicio->prox;

        if( fp->menos65->inicio == NULL ) {
            fp->menos65->fim = NULL;
        }

        free(pessoaTemp);
        return 0;
    }

    else return -1; // caso ambas estejam vazias, retorna -1.
}