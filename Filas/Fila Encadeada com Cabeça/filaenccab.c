#include "filaenccab.h"
#include <stdlib.h>
#include <stdio.h>

void criarFila(TFilaEncCab* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

int filaVazia(TFilaEncCab fila) {
    return ( fila.inicio == NULL && fila.fim == NULL );
}

int tamanhoFila(TFilaEncCab fila) { return fila.tam; }

int elementoFrente(TFilaEncCab fila, tipo_fila* valor) {
    if( filaVazia( fila ) ) return 0;
    *valor = (fila.inicio)->dado;
    return 1;
}

int enfileirar(TFilaEncCab* fila, tipo_fila elemento) {
    no* novo = (no*) malloc(sizeof(no));
    if( novo == NULL ) return 0;

    novo->dado = elemento;
    novo->prox = NULL;

    if( filaVazia(*fila) ) fila->inicio = novo;
    else (fila->fim)->prox = novo;

    fila->fim = novo;
    (fila->tam)++;
    return 1;
}

int desenfileirar(TFilaEncCab* fila, tipo_fila* valor) {
    if( filaVazia(*fila) ) return 0;

    *valor = (fila->inicio)->dado;

    if( fila->inicio == fila->fim ) fila->fim = NULL;

    no* aux = fila->inicio;
    fila->inicio = (fila->inicio)->prox;
    free(aux);
    (fila->tam)--;
    return 1;
}

void imprimir( TFilaEncCab fila ) {
	printf("\nFila=[ ");
   	for (  ; fila.inicio != NULL; fila.inicio = (fila.inicio)->prox )
		printf( "%d ", (fila.inicio)->dado );
   	printf("]");
}
