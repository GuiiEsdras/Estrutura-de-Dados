#include <stdlib.h>

#define MAX 10

typedef int tipo_fila;

typedef struct {
    tipo_fila elementos[ MAX ];
    int frente, fim, tam;
} TFilaSeqCirc;

void criarFila( TFilaSeqCirc *fila );

int filaVazia( TFilaSeqCirc *fila );

int filaCheia( TFilaSeqCirc *fila );

int enfileirar( TFilaSeqCirc *fila, tipo_fila dado );

int desenfileirar( TFilaSeqCirc *fila, tipo_fila *d );

int elementoFrente( TFilaSeqCirc* fila, tipo_fila *valor );

void imprimir( TFilaSeqCirc *fila );
