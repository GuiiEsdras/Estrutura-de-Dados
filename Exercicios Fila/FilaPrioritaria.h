#include "Fila.h"
#include <stdlib.h>

typedef struct FilaPrioritaria {
  Fila* menos65;
  Fila* mais65;
} FilaPrioritaria;

FilaPrioritaria* criaFilaPrioritaria();
int enfileirarFP(FilaPrioritaria*, char*, int);
int desenfileirarFP(FilaPrioritaria*, Pessoa*);
int limpaFilaFP(FilaPrioritaria*);

void printaFilaFP(FilaPrioritaria*);
void tamanhoDaFilaFP(FilaPrioritaria*);
void terminarFilaFP(FilaPrioritaria*);