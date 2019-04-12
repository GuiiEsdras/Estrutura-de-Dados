#include <stdio.h>
#include <stdlib.h>
#include "listalinear.h"

lista * criaLista(int n) {
    lista *nova = (lista*)malloc(sizeof(lista));
    nova->val = (int*)malloc(n*sizeof(int));
    nova->max = n;
    nova->ue = 0;
    return nova;
}

int insere(lista * l, int v) {
    if(l->ue == l->max) {
       int *aux = (int*)realloc(l->val, 2*l->max*sizeof(int));
        if (aux == NULL) {
            return -1;
        }
        else {
            printf("Realocou para poder inserir o elemento %d\n", v);
            l->val = aux;
            l->max *= 2;
        }
    }
    l->val[l->ue] = v;
    l->ue++;
    printf("Inseriu %d\n", v);
    return 0;
}

int remove_pos(lista *l, int i) {
    if(i >= l->ue || i < 0) return -1;
    else {
        int k;
        for(k = i+1; k < l->ue; k++) {
            l->val[k-1] = l->val[k];
        }
        printf("Removeu pos %d\n", i);
        l->ue--;
        return 0;
    }
}

int get(const lista *l, int i) {
    if(i >= 0 && i < l->ue)
    	return l->val[i];
}

int size(const lista *l) {
    return l->ue;
}

void printLista(const lista *l) {
    printf("[");
    int i;
    for(i = 0; i < l->ue; i++) {
        if(i < l->ue-1){
            printf("%d,",l->val[i]);
        }
        else {
            printf("%d]",l->val[i]);
        }
    }
    printf("\n");
}

void libera(lista *l) {
    free(l->val);
    free(l);
}

int hasElement(const lista *l, int v) {
    register int i = 0;
    for(i = 0; i < size(l); i++) {
        if( l->val[i] == v ) {
                printf("Existe o elemento %d na posicao %d\n", v, i);
                return 1;
        }
    }

    printf("Nao existe o elemento %d nesta lista\n", v);
    return -1;
}

int insertPosition(lista *l, int v, int pos) {
    if(pos < 0 || pos > size(l)) {
            return -1;
    }

    if( l->ue == l->max ) {
        int *aux = (int*)realloc(l->val, 2*l->max*sizeof(int));

        if (aux == NULL) {
            return -1;
        }

        else {
            printf("Realocou para poder inserir o elemento %d na pos %d\n", v, pos);
            l->val = aux;
            l->max *= 2;

            register int i = 0;
            for(i = l->ue; i >= pos; i--) {
                l->val[i+1] = l->val[i];
                if(i == pos) {
                    l->val[i] = v;
                    }
            }

            l->ue++;
            printf("Inseriu %d na pos %d\n", v, pos);
        }
    }

    else {

        register int i = 0;
        for(i = l->ue; i >= pos; i--) {
            l->val[i+1] = l->val[i];
            if(i == pos) {
                l->val[i] = v;
            }
        }

        printf("Inseriu %d na pos %d\n", v, pos);
        l->ue++;

    }

    return 0;
}

int removeElement(lista *l, int v) {
    if(hasElement(l, v) > 0) {
        register int i = 0;
        int pos = 0;

        for(i = 0; i < size(l); i++) {
            if( l->val[i] == v ) {
                pos = i;
                break;
            }
        }

        remove_pos(l, pos);
    }

    else return -1;
}
