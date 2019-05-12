#include <stdlib.h>
#include <stdio.h>

#define MAX 51
#define FilaNormal 1
#define FilaPriori 2

typedef enum { false, true } bool;

typedef struct {
  char nome[MAX];
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

void printaFila(Fila*);
int tamanhoDaFila(Fila*);
void terminarFila(Fila*);

void separador();