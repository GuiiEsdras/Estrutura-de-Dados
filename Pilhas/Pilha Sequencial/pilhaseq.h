#include <stdlib.h>
#include <stdio.h>

#define MAX 10
typedef int tipo_pilha;

typedef struct {
    tipo_pilha elementos[ MAX ];
    int topo;
} TPilha;

TPilha* criaPilha();

int tamanhoPilha(TPilha* p);

int pilhaVazia(TPilha *p);

int pilhaCheia(TPilha *p);

int empilhar(TPilha* p, tipo_pilha v);

int desempilhar(TPilha *p);

void elementoTopo(TPilha *p);

void imprimePilha(TPilha *p);

void esvaziaPilha(TPilha* p);
