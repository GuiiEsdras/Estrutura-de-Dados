#include "listaenc.h"
#include <stdio.h>
#include <stdlib.h>

list* createList() {
    list *l = (list*) malloc( sizeof(list) );
    l->begin = NULL;
    l->tamanho = 0;
    return l;
}

void add(list *l, int v) {
    node* newnode;
    newnode = (node*) malloc( sizeof(node) );

    newnode->data = v;
    newnode->next = NULL;

    if( isEmpty(l) ) l->begin = newnode; // Se a lista estiver vazia (apenas com a cabeça construida) o novo nó se conectará com a cabeça.

    else {
        node* aux = l->begin;
        while( aux ->next != NULL ) { // Percorre a lista até chegar no último nó;
            aux = aux->next;
        }
        aux->next = newnode; // Conecta o novo nó na última posição;
    }

    l->tamanho++;
    printf("lista.append(%d)\n", v);
}

void printList(const list *l) {
    printf("[");
    node *aux = l->begin;
    while( aux != NULL ) {

        if( aux->next == NULL ) printf("%d", aux->data);
        else printf("%d, ", aux->data);

        aux = aux->next;
    }
    printf("]\n");
}

int isEmpty(const list *l) {
    return ( l->begin == NULL );
}

void removeBack(list *l) {
    if(size(l) > 1) {
        node* ultimo = l->begin;
        node* penultimo = l->begin;
        while( ultimo->next != NULL ) {
            ultimo = ultimo->next;

            if( ultimo->next != NULL ) {
                penultimo = penultimo->next;
            }
        }

        printf("lista.pop()  (Removendo [%d]...)\n", ultimo->data);
        free(ultimo);
        penultimo->next = NULL;
        l->tamanho--;

    } else {
        node* ultimo = l->begin;
        printf("lista.pop()  (Removendo [%d]...)\n", ultimo->data);
        free(ultimo);
        l->begin = NULL;
        l->tamanho--;

    }
}

int size(const list *l) {
    if( isEmpty(l) ) return 0;
    else return l->tamanho;

    /*
    else {
        node* aux = l->begin;
        int cont = 1;
        while( aux->next != NULL) {
            cont++;
            aux = aux->next;
        }
        return cont;
    }
    */
}



int hasElement(const list *l, int v) {
    int i, cont = 0;
    node* aux = l->begin;
    for(i = 0; i < size(l); i++) {
        if( aux->data == v ) return cont;
        else {
            aux = aux->next;
            cont++;
        }
    }
    return -1;
}

int insertPosition(list *l, int v, int pos) {
    if( pos < 0 || pos > size(l) ) return -1;

    else {
        node* newnode;
        newnode = (node*) malloc( sizeof(node) );

        newnode->data = v;
        newnode->next = NULL;

        if( pos == 0 ) {
            node* primeiro = l->begin;
            newnode->next = primeiro;
            l->begin = newnode;
            l->tamanho++;

            printf("lista.insert(%d, %d)\n", pos, v);
            return 0;

        } else {
            int cont = 1;
            node* aux = l->begin;
            node* aux2 = aux->next;

            while(cont != pos) {
                aux = aux->next;
                aux2 = aux->next;
                cont++;
            }

            aux->next = newnode;
            newnode->next = aux2;

            l->tamanho++;
            printf("lista.insert(%d, %d)\n", pos, v);
            return 0;
        }
    }
}

int removePosition(list *l, int pos) {
	if( isEmpty(l) || ( pos < 0 || pos >= size(l) ) ) return -1;

    else {
    	if( pos == 0 ) {
    		node* aux = l->begin;
			node* aux2 = aux->next;

			free(aux);
			l->begin = aux2;
            l->tamanho--;

			printf("del(lista[%d])\n", pos);
			return 0;

		} else {
			int cont = 1;

			node* aux = l->begin;
			node* aux2 = aux->next;

			while( cont != pos ) {
				aux = aux->next;
				aux2 = aux->next;
				cont++;
			}

			aux->next = aux2->next;
			free(aux2);

            l->tamanho--;

			printf("del(lista[%d])\n", pos);
			return 0;
		}
    }
}


int removeElement(list *l, int v) {
	if( isEmpty(l) ) return -1;

	else {
		int i, cont = 0;
		node* aux = l->begin;

		if( aux->data == v && cont == 0 ) {
			l->begin = aux->next;
			free(aux);
            l->tamanho--;
            //printf("Elemento removido da posicao: %d\n", cont);
			return cont;

		} else {
			cont++;
			node* aux2 = aux->next;

			for(i = cont; i < size(l); i++) {
				if( aux2->data == v ) {

					aux->next = aux2->next;
					free(aux2);
                    l->tamanho--;
					//printf("Elemento removido da posicao: %d\n", cont);
					return cont;

				} else {
				    aux = aux->next;
				    aux2 = aux->next;
				    cont++;
				}
			}
		}
	}
}

int get(const list *l, int pos, int *vret) {
	if( isEmpty(l) || ( pos < 0 || pos >= size(l) ) ) return -1;

	else {
        node* aux = l->begin;
        register int i;
        for(i = 0; i <= pos; i++) {
            if( i == pos ) {
                *vret = aux->data;
                return 0;
            } else aux = aux->next;
        }
	}
}


int clear(list *l) {
    if( isEmpty(l) ) return -1;

    else {
        while( l->begin != NULL ) {
            node* aux = l->begin;
            l->begin = aux->next;
            free(aux);
        }
        printf("lista.clear()\n");
        return 0;
    }
}
