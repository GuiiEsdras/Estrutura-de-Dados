#include <stdlib.h>
#include <stdio.h>

typedef struct {
  char nome[51];
  int idade;
} Pessoa;

typedef struct PessoaNaFila {
  Pessoa p;
  struct PessoaNaFila* prox;
} PessoaNaFila; // Chamei um nó de 'Pessoa na fila'.

typedef struct {
  PessoaNaFila* inicio;
  PessoaNaFila* fim;
  int tamanhoDaFila;
} Fila;

Fila* criaFila();
int enfileirar(Fila*, char*, int);
int desenfileirar(Fila*, Pessoa*);
int limpaFila(Fila*);

int printaFila(Fila*);
int tamanhoDaFila(Fila*);
void terminarFila(Fila*);

void separador();