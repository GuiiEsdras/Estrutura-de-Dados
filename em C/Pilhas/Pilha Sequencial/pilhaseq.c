#include "pilhaseq.h"
#include <stdlib.h>
#include <stdio.h>

TPilha* criaPilha() {
    TPilha* p = (TPilha*) malloc(sizeof(TPilha));
    if( p != NULL ) {
        p->topo = 0;
        return p;
    }
}

int tamanhoPilha(TPilha* p) {
    if( p == NULL ) return -1;
    return ( p->topo );
}

int pilhaVazia(TPilha *p) {
    if( p == NULL ) return -1;
    return ( tamanhoPilha(p) == 0 );
}

int pilhaCheia(TPilha* p) {
    if( p == NULL ) return -1;
    return ( tamanhoPilha(p) == MAX );
}

int empilhar(TPilha* p, tipo_pilha v) {
    if( p == NULL || pilhaCheia(p) ) return -1;

    p->elementos[ p->topo ] = v;
    p->topo++;

    printf("Elemento empilhado: [ %d ] \n", v);
    return 1;
}

int desempilhar(TPilha *p) {
    if( p == NULL || pilhaVazia(p) ) return -1;
    p->topo--;
    printf("Elemento desempilhado: [ %d ] \n", p->elementos[ p->topo]);
    return 1;
}

void elementoTopo(TPilha *p) {
    if( p == NULL || pilhaVazia(p) ) printf("Pilha vazia! \n");
    else {
        printf("Elemento do topo: [ %d ] \n", p->elementos[ p->topo -1]);
    }
}

void imprimePilha(TPilha *p) {
    if( p == NULL || pilhaVazia(p) ) {
            printf("Pilha vazia! \n");
    }
    else {
        printf("Pilha: [ ");
        register int i;
        for( i = 0; i < tamanhoPilha(p); i++ ) {
            printf("%d ", p->elementos[ i ]);
        }
        printf("] \n");
    }

}

void esvaziaPilha(TPilha* p) {
    p->topo = 0;
    free(p);
    printf("Pilha esvaziada! \n");
}
