#include "Fila.h"
#include <stdlib.h>

typedef struct FilaPrioritaria {
  Fila* menos65;
  Fila* mais65;
} FilaPrioritaria;

FilaPrioritaria* criaFilaPrioritaria();
void enfileirarFP(FilaPrioritaria*, char*, int);
int desenfileirarFP(FilaPrioritaria*, Pessoa*);
//void limpaFilaFP(FilaPrioritaria*);