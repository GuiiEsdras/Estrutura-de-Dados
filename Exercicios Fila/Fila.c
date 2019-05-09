#include "Fila.h"
#include <string.h>
// OBS: Pessoa == No...

Fila* criaFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if( f == NULL ) return NULL;

    f->inicio = NULL;
    f->fim = NULL;
    f->tamanhoDaFila = 0;

    printf("Fila Normal iniciada com sucesso!\n");
    return f;
}

int enfileirar(Fila* fila, char* nome, int idade) {
    if(fila == NULL) {
        printf("Fila normal nao iniciada!\n"); 
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

        if( fila->fim == NULL ) { // Se a fila nao tiver ninguem no final dela quer dizer que esta vazia...
            fila->inicio = novaPessoa; // novaPessoa passa a ser a primeira...
            fila->fim = novaPessoa; // ...e a ultima.
        }

        else { // Caso ja haja alguem na fila...
            fila->fim->prox = novaPessoa; // a ultima "pessoa" passa a apontar para novaPessoa...
            fila->fim = novaPessoa; // ... e novaPessoa passa a ser a ultima "pessoa" da fila.
        }

        fila->tamanhoDaFila++;
        printf("%s (%d anos) entrou na fila!\n", nome, idade);
        return 1;
    }
}

// Lembrete pessoal: Em uma fila, o elemento que esta no inicio e o primeiro a ser removido/desenfileirado.
// "FiFo" - First in, First Out!
int desenfileirar(Fila* fila, Pessoa* p_ret) {
    if(fila == NULL) { 
        printf("Fila normal nao iniciada!\n"); 
        return 0; 
    }

    else if( fila->inicio == NULL ) { 
        printf("Esta fila se encontra vazia!\n"); 
        return 0; 
    }

    else {
        *p_ret = (fila->inicio)->p;
        //PessoaNaFila* pessoaTemp; // Cria uma "pessoa"/No temporaria;
        PessoaNaFila* pessoaTemp = fila->inicio; // "pessoa"/No temp recebe a "pessoa"/No que esta no inicio/primeira posiçao da fila;
        //*p_ret = pessoaTemp->p; // Variavel externa do tipo Pessoa* recebe os dados dessa "pessoa"/No;

        fila->inicio = (fila->inicio)->prox; // A "pessoa"/No que ocupava a segunda posiçao passa a ocupar a primeira posiçao;

        if( fila->inicio == NULL ) { // se por acaso nao havia ninguem na segunda posiçao...
            fila->fim = NULL; // o fim da fila deve ser NULL, pois nao tem mais ninguem na fila e a fila agora esta vazia.
        }

        free(pessoaTemp); // Remove a "pessoa"/No que ocupava a primeira posiçao da fila.
        fila->tamanhoDaFila--;
        return 1;
    }
}

int limpaFila(Fila* fila) {
    if(fila == NULL) {
        printf("Fila normal nao iniciada!\n"); 
        return 0;
    }

    else if( fila->inicio == NULL ) {
        printf("Esta fila se encontra vazia!\n");
        return 0;
    }

    else {

        while( fila->inicio != NULL ) {
            PessoaNaFila* Aux = fila->inicio;
            fila->inicio = fila->inicio->prox;
            free(Aux);
        }

        fila->fim = NULL;
        fila->tamanhoDaFila = 0;
        printf("Fila esvaziada!\n");

        return 1;
    }
}


int printaFila(Fila* fila) {
    if(fila == NULL) {
        printf("Fila normal nao iniciada!\n"); 
        return 0;
    }

    else if( fila->inicio == NULL ) {
        printf("Esta fila se encontra vazia!\n");
        return 0;
    }

    else {
        printf("\n|Pessoas na fila|\n");

        PessoaNaFila* pessoaAux = fila->inicio;
        int cont = 1;
        while(pessoaAux != NULL) {
            printf("Posicao: %d | Nome: %s - Idade: %d\n", cont, pessoaAux->p.nome, pessoaAux->p.idade);
            pessoaAux = pessoaAux->prox;
            cont++;
        } 
        printf("\n");
        return 1;
    }
}

int tamanhoDaFila(Fila* f) { return f->tamanhoDaFila; }

void terminarFila(Fila* fila) {
    printf("Saindo...\n");
    free(fila);
}


void separador() {
    printf("-----\n");
}