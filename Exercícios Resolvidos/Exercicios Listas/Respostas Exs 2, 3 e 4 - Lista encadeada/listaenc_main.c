#include "listaenc.h"
#include <stdio.h>
#include <stdlib.h>

void imprime(list* lista);
void len(list* lista);
void verificaVazia(list* lista);
void linha();
void tracos();
void exercicio(int n);
void testando(char funcao[30]);

int main() {
    tracos();
    exercicio(2);

    // Testando createList
    testando("createList e printList");
    linha();
    list* lista = createList();
    imprime(lista);
    linha();

    // Testando size e isEmpty
    testando("size");
    linha();
    len(lista);
    linha();

    testando("isEmpty");
    linha();
    verificaVazia(lista);
    linha();

    // Testando add
    testando("add");
    linha();

    add(lista, 10);
    add(lista, 20);
    add(lista, 30);
    imprime(lista);
    len(lista);
    verificaVazia(lista);
    linha();

    // Testando removeBack
    testando("removeBack");
    linha();

    removeBack(lista);
    imprime(lista);
    len(lista);
    verificaVazia(lista);
    linha();

    add(lista, 40);
    imprime(lista);
    linha();

    removeBack(lista);
    removeBack(lista);
    imprime(lista);
    linha();

    removeBack(lista);
    imprime(lista);
    len(lista);
    verificaVazia(lista);
    linha();

	/*----------Exercicio 3----------*/
    tracos();
    exercicio(3);

    // Testando hasElement
    testando("hasElement");
    linha();

    add(lista, 1);
    add(lista, 2);
    add(lista, 4);
    printf("Verificando se existe o elemento [4]. Retorna: %d\n", hasElement(lista, 4));
    printf("Verificando se existe o elemento [3]. Retorna: %d\n", hasElement(lista, 3));
    linha();

    // Testando insertPosition
    testando("insertPosition");
    linha();

    imprime(lista);
    linha();
    insertPosition(lista, 3, 2);
    imprime(lista);
    linha();
    insertPosition(lista, 5, 4);
    imprime(lista);
    if(insertPosition(lista, 200, -1) < 0) printf("Erro na insercao. Posicao ou valor invalidos.\n");
    if(insertPosition(lista, 202, 10) < 0) printf("Erro na insercao. Posicao ou valor invalidos.\n");
    imprime(lista);
    linha();

    tracos();
    linha();

    add(lista, 6);
    imprime(lista);
    len(lista);
    linha();

    // Testando removePosition
    testando("removePosition");
    linha();

    removePosition(lista, 0);
    imprime(lista);
    linha();
    removePosition(lista, 1);
    imprime(lista);
    linha();
    removePosition(lista, 3);
    imprime(lista);
    linha();
    removePosition(lista, 2);
    removePosition(lista, 1);
    removePosition(lista, 0);
    imprime(lista);
    len(lista);
    verificaVazia(lista);
    linha();

    tracos();
    linha();

    add(lista, 1);
    add(lista, 2);
    add(lista, 3);
    add(lista, 4);
    imprime(lista);
    linha();

    // Testado removeElement
    testando("removeElement");
    linha();

    printf("Removendo elemento da posicao: %d\n", removeElement(lista, 1) );
    imprime(lista);
    linha();

    printf("Removendo elemento da posicao: %d\n", removeElement(lista, 3) );
    imprime(lista);
    linha();

    printf("Removendo elemento da posicao: %d\n", removeElement(lista, 4) );
    imprime(lista);
    linha();

    printf("Removendo elemento da posicao: %d\n", removeElement(lista, 2) );
    imprime(lista);
    linha();

    // Testando get
    testando("get");
    linha();

    int armazenador = 0;

    printf("armazenador = %d", armazenador);
    linha(); linha();

    insertPosition(lista, 11, 0);
    insertPosition(lista, 25, 1);
    add(lista, 37);
    add(lista, 48);
    imprime(lista);
    linha();

    get(lista, 0, &armazenador);
    printf("get(lista, 0, &armazenador) \narmazenador = %d", armazenador);
    linha();
    get(lista, 1, &armazenador);
    printf("get(lista, 1, &armazenador) \narmazenador = %d", armazenador);
    linha();
    get(lista, 2, &armazenador);
    printf("get(lista, 2, &armazenador) \narmazenador = %d", armazenador);
    linha();
    get(lista, 3, &armazenador);
    printf("get(lista, 3, &armazenador) \narmazenador = %d", armazenador);
    linha();


    tracos();
    linha();

    testando("minha funcao clear() extra");
    linha();

    imprime(lista);
    clear(lista);

    imprime(lista);

    add(lista, 1);
    imprime(lista);

    clear(lista);
    imprime(lista);

    return 0;
}

/* minhas funcoes auxiliares */

void imprime(list* lista) {
    printf("lista = "); printList(lista);
}

void len(list* lista) {
    printf("len(lista) = %d\n", size(lista) );
}

void verificaVazia(list* lista) {
    printf("vazia = %s", isEmpty(lista) ? "True" : "False");
    printf("\n");
}

void linha() { printf("\n"); }

void exercicio(int n) { printf(" Exercicio %d \n\n", n); }

void tracos() {
    register int i;
    for(i = 0; i < 21; i++) printf("-");
    printf("\n");
}

void testando(char funcao[30]) { printf("|------(Testando %s)\n", funcao); }
