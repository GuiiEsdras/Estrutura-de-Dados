#include "Fila.h"
#include <string.h>
// OBS: Pessoa == Nó...

Fila* criaFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if( f == NULL ) return NULL;

    f->inicio = NULL;
    f->fim = NULL;

    printf("Fila iniciada!\n");
    return f;
}

void enfileirar(Fila* fila, char* nome, int idade) {
    PessoaNaFila* novaPessoa = (PessoaNaFila*) malloc(sizeof(PessoaNaFila));

    strcpy(novaPessoa->p.nome, nome);
    novaPessoa->p.idade = idade;

    if( fila->fim == NULL ) { // Se a fila não tiver ninguém no final dela quer dizer que está vazia...
        fila->inicio = novaPessoa; // novaPessoa passa a ser a primeira...
        fila->fim = novaPessoa; // ...e a última.
    }

    else { // Caso já haja alguém na fila...
        fila->fim->prox = novaPessoa; // a última "pessoa" passa a apontar para novaPessoa...
        fila->fim = novaPessoa; // ... e novaPessoa passa a ser a última "pessoa" da fila.
    }

    printf("%s (%d anos) entrou na fila!\n", nome, idade);
}

// Lembrete pessoal: Em uma fila, o elemento que está no inicio é o primeiro a ser removido/desenfileirado.
// "FiFo" - First in, First Out!
int desenfileirar(Fila* fila, Pessoa* p_ret) {
    if( fila->inicio == NULL ) return -1; // Verifica se a fila está vazia;
    else {
        *p_ret = (fila->inicio)->p;
        //PessoaNaFila* pessoaTemp; // Cria uma "pessoa"/Nó temporaria;
        PessoaNaFila* pessoaTemp = fila->inicio; // "pessoa"/Nó temp recebe a "pessoa"/Nó que está no inicio/primeira posição da fila;
        //*p_ret = pessoaTemp->p; // Variável externa do tipo Pessoa* recebe os dados dessa "pessoa"/Nó;

        fila->inicio = (fila->inicio)->prox; // A "pessoa"/Nó que ocupava a segunda posição passa a ocupar a primeira posição;

        if( fila->inicio == NULL ) { // se por acaso não havia ninguém na segunda posição...
            fila->fim = NULL; // o fim da fila deve ser NULL, pois não tem mais ninguém na fila e a fila agora está vazia.
        }

        free(pessoaTemp); // Remove a "pessoa"/Nó que ocupava a primeira posição da fila.
        return 0;
    }
}

void printaFila(Fila* fila) {
    if( fila->inicio == NULL ) {
        printf("Esta fila esta vazia!\n");
    }
    else {
        printf("|Pessoas na fila|\n");
        register int i;
        for( i = 1; fila->inicio != NULL; fila->inicio = fila->inicio->prox, i++ ) {
            printf("Posicao: %d | Nome: %s - Idade: %d \n", 
                                    i, fila->inicio->p.nome, fila->inicio->p.idade);
        }
    }
}

int limpaFila(Fila* fila) {
    if( fila->inicio == NULL ) return -1;

    while( fila->inicio != NULL ) {
        PessoaNaFila* pessoaTemp;
        pessoaTemp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(pessoaTemp);
    }
    fila->fim = NULL;
    return 1;
}