#include "filaseqcirc.h"
#include <stdio.h>
#include <stdlib.h>

void criarFila( TFilaSeqCirc *fila ) {
    fila->frente = 0;
    fila->fim = -1;
    fila->tam = 0;
}

int filaVazia( TFilaSeqCirc *fila ) { return fila->tam == 0; }

int filaCheia( TFilaSeqCirc *fila ) { return fila->tam == MAX; }

int enfileirar( TFilaSeqCirc *fila, tipo_fila dado ) {
    if( filaCheia(fila) ) return 0;
    fila->elementos[ fila->fim ] = dado;
    fila->fim = (fila->fim +1) % MAX;
    fila->tam++;
    return 1;
}

int desenfileirar( TFilaSeqCirc *fila, tipo_fila *d ) {
    if( filaVazia(fila) ) return 0;

    d = fila->elementos[ fila->fim ];
    fila->frente = (fila->frente +1) % MAX;
    fila->tam--;
    return 1;
}

int elementoFrente( TFilaSeqCirc* fila, tipo_fila *valor ) {
	if ( filaVazia( fila ) ) return 0;
	*valor = fila->elementos[ (fila->frente) ];
	return 1;
}

void imprimir(TFilaSeqCirc* fila) {
    if( filaVazia(fila) ) printf("Fila vazia! \n");
    else {
        printf("Fila: [ ");

        register int i, aux;
        for( i = 1, aux = fila->frente;
                i <= fila->tam;
                i++, aux = (aux +1) % MAX ) {

                printf("%d ", fila->elementos[ aux ]);
        }

        printf("]");
    }
}
