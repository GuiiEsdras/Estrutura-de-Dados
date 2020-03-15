#include <stdlib.h>

typedef int tipo_fila; // se for float por ex, so alterar int para float

typedef struct nofila {
    tipo_fila dado;
    struct nofila *prox;
} no;

typedef struct cabeca {
    no* inicio;
    no* fim;
    int tam;
} TFilaEncCab;


void criarFila( TFilaEncCab *fila );

int filaVazia( TFilaEncCab fila );

int tamanhoFila( TFilaEncCab fila );

int elementoFrente( TFilaEncCab fila, tipo_fila *valor );

int enfileirar( TFilaEncCab *fila, tipo_fila elemento );

int desenfileirar( TFilaEncCab *fila, tipo_fila *valor );

void imprimir( TFilaEncCab fila );
