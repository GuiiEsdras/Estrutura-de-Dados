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
} Fila;

Fila* criaFila();
void enfileirar(Fila*, char*, int);
int desenfileirar(Fila*, Pessoa*);
void printaFila(Fila*);
int limpaFila(Fila*);
