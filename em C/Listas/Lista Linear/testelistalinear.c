#include <stdio.h>
#include "listalinear.h"

int main() {
    lista *l = criaLista(5);
    insere(l,10);
    insere(l,20);
    insere(l,5);
    printLista(l);
    remove_pos(l,1);
    printLista(l);
    insere(l,40);
    insere(l,60);
    insere(l,70);
    printLista(l);
    printf("Size: %d\n", size(l));
    printf("Max: %d\n",l->max);
    insere(l,90);
    printf("Size: %d\n", size(l));
    printf("Max: %d\n",l->max);
    insere(l,100);
    printLista(l);
    printf("Elemento pos %d = %d\n", 3, get(l,3));
    printf("Elemento pos %d = %d\n", 1, get(l,1));
    printf("Size: %d\n", size(l));
    printf("Max: %d\n",l->max);

    hasElement(l, 100);

    insertPosition(l, 1, 7);
    printLista(l);
    printf("Size: %d\n", size(l));
    printf("Max: %d\n",l->max);

    insertPosition(l, 2, 0);
    printLista(l);
    printf("Size: %d\n", size(l));
    printf("Max: %d\n",l->max);

    insertPosition(l, 3, 0);
    printLista(l);
    printf("Size: %d\n", size(l));
    printf("Max: %d\n",l->max);

    insertPosition(l, 4, 0);
    printLista(l);
    printf("Size: %d\n", size(l));
    printf("Max: %d\n",l->max);

    printf("\n");

    removeElement(l, 100);
    printLista(l);
    printf("Size: %d\n", size(l));
    printf("Max: %d\n",l->max);

    libera(l);
    return 0;
}

