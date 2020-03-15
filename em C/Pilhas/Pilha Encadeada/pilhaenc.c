#include "pilhaenc.h"
#include <stdio.h>
#include <stdlib.h>

/*
TPilhaEnc* criaPilha() {
    TPilhaEnc* pi = (TPilhaEnc*) malloc(sizeof(TPilhaEnc));
    if( pi != NULL ) {
        *pi = NULL;
        return pi;
    }
}
*/

void criarPilha( TPilhaEnc *pilha ) {
	*pilha = NULL;
}

int pilhaVazia( TPilhaEnc pilha ) {
	return pilha == NULL;
}

int tamanhoPilha( TPilhaEnc pilha ) {
	int tamanho = 0;
	while( pilha != NULL ) {
		pilha = pilha->prox;
		tamanho++;
	}
	return tamanho;
}

int empilhar( TPilhaEnc *pilha, tipo_dado dado ) {
	TPilhaEnc novo_no;

	novo_no = (no*) malloc(sizeof(no) );
	if( novo_no == NULL ) return 0;

	novo_no->dado = dado;
	novo_no->prox = (*pilha);
	*pilha = novo_no;
	return 1;
}

int desempilhar(TPilhaEnc* pilha, tipo_dado* dado) {
    if( pilhaVazia(*pilha) ) return 0;

    TPilhaEnc aux;
    aux = *pilha;

    *dado = aux->dado;
    *pilha = aux->prox;

    free(aux);

    return 1;
}

int elementoTopo(TPilhaEnc pilha, tipo_dado* dado) {
    if( pilhaVazia(pilha) ) return 0;

    *dado = pilha->dado;
    return 0;
}

int imprimir(TPilhaEnc pilha) {
    if( pilhaVazia(pilha) ) return 0;

    printf("Pilha: [ ");

    while( pilha != NULL ) {
        printf("%d ", pilha->dado);
        pilha = pilha->prox;
    }

    printf("]");

    return 1;
}


int esvaziarPilha( TPilhaEnc *pilha ) {
    if( pilhaVazia(*pilha) ) return 0;

    TPilhaEnc aux, aux2;
    aux = *pilha;
    aux2 = aux;

    while( aux != NULL ) {
        free(aux2);
        aux = aux->prox;
        aux2 = aux;
    }

    *pilha = NULL;

    return 1;
}

int basePilha( TPilhaEnc pilha, tipo_dado *dado ) {
    if( pilhaVazia(pilha) ) return 0;

    while( pilha->prox != NULL ) {
        pilha = pilha->prox;
    }

    *dado = pilha->dado;
    return 1;
}

int desempilhaN( TPilhaEnc *pilha, int n ) {
    if( pilhaVazia(*pilha) ) return 0;

    register int i;
    for( i = 0; i < n; i++ ) {
        TPilhaEnc aux = *pilha;

    }
}

int subtopoPiha( TPilhaEnc pilha );
