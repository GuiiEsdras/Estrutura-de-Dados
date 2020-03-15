#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    long int dado;
    struct no *prox;
} No;

typedef struct {
    long int tamanho;
    No *cabeca; // ou PrimeiroElemento : Armazena o ponteiro para o primeiro elemento da Lista
} ListaEnc;


ListaEnc* criaListaEnc();

void add(ListaEnc *l, long int v);

int size(const ListaEnc *l);

bool estaVazia(const ListaEnc *l);

bool clear(ListaEnc* l);

bool getElementByPos(const ListaEnc *l, long int pos, long int *vret);

bool insertVInPosition(ListaEnc *l, long int v, long int pos);



int hasElement_ListaEnc(const ListaEnc *l, int v);

void removeBack_ListaEnc(ListaEnc *l);

int removePosition_ListaEnc(ListaEnc *l, int pos);

int removeElement_ListaEnc(ListaEnc *l, int v);

void print_ListaEnc(const ListaEnc *l);
