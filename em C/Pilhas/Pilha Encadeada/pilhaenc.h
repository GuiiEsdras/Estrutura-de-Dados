#include <stdlib.h>

typedef int tipo_dado;

typedef struct elemento {
    tipo_dado dado;
    struct elemento *prox;
} no;

typedef no* TPilhaEnc;

// TPilhaEnc* criaPilha();

void criarPilha( TPilhaEnc *pilha );

/* Verificar se a pilha está vazia ou não */
int pilhaVazia( TPilhaEnc pilha );

/* Tamanho da pilha */
int tamanhoPilha( TPilhaEnc pilha );

/* Empilhar um elemento */
int empilhar( TPilhaEnc *pilha, tipo_dado dado );

/* Desempilhar um elemento */
int desempilhar( TPilhaEnc *pilha, tipo_dado *dado );

/* Consultar o topo pilha */
int elementoTopo( TPilhaEnc pilha, tipo_dado *dado );

/* Exibir todos os elementos da pilha */
int imprimir ( TPilhaEnc pilha );


int esvaziarPilha( TPilhaEnc *pilha );

int basePilha( TPilhaEnc pilha, tipo_dado *dado);

int desempilhaN( TPilhaEnc *pilha, int n );

int subtopoPiha( TPilhaEnc pilha );
