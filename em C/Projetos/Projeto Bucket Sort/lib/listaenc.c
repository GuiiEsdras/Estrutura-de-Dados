#include "../include/listaenc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

ListaEnc *criaListaEnc()
{
    ListaEnc *l = (ListaEnc *)malloc(sizeof(ListaEnc));
    l->cabeca = NULL;
    l->tamanho = 0;
    return l;
}

void add(ListaEnc *l, long int valor)
{
    No *novoNo;
    novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
        return;

    novoNo->dado = valor;
    novoNo->prox = NULL;

    // Se a lista estiver vazia (apenas com a cabeça construida) o novo nó se conectará com a cabeça.
    if (estaVazia(l))
        l->cabeca = novoNo;

    else
    {
        No *aux = l->cabeca;
        while (aux->prox != NULL)
        { // Percorre a lista até chegar no último nó;
            aux = aux->prox;
        }
        aux->prox = novoNo; // Conecta o novo nó na última posição;
    }

    l->tamanho++;
}

int size(const ListaEnc *l)
{
    if (estaVazia(l))
        return 0;
    else
        return l->tamanho;
}

bool estaVazia(const ListaEnc *l)
{
    return (l->cabeca == NULL);
}

bool clear(ListaEnc *l)
{
    if (estaVazia(l))
        return false;

    else
    {
        while (l->cabeca != NULL)
        {
            No *aux = l->cabeca;
            l->cabeca = aux->prox;
            free(aux);
        }
        printf("Lista Encadeada limpada e desalocada!\n");
        return true;
    }
}

bool getElementByPos(const ListaEnc *l, long int pos, long int *vret)
{
    if (estaVazia(l) || (pos < 0 || pos >= size(l)))
        return false;

    else
    {
        No *aux = l->cabeca;
        long int i;
        for (i = 0; i <= pos; i++)
        {
            if (i == pos)
            {
                *vret = aux->dado;
                return true;
            }
            else
                aux = aux->prox;
        }
    }
}

bool insertVInPosition(ListaEnc *l, long int v, long int pos)
{
    if (pos < 0 || pos > size(l))
        return false;

    else
    {
        No *novoNo;
        novoNo = (No *) malloc(sizeof(No));

        novoNo->dado = v;
        novoNo->prox = NULL;

        if (pos == 0)
        {
            No *primeiro = l->cabeca;
            novoNo->prox = primeiro;
            l->cabeca = novoNo;
            l->tamanho++;

            return true;
        }
        else
        {
            int cont = 1;
            No *aux = l->cabeca;
            No *aux2 = aux->prox;

            while (cont != pos)
            {
                aux = aux->prox;
                aux2 = aux->prox;
                cont++;
            }

            aux->prox = novoNo;
            novoNo->prox = aux2;

            l->tamanho++;
            return true;
        }
    }
}




void print_ListaEnc(const ListaEnc *l)
{
    printf("[");
    No *aux = l->cabeca;
    while (aux != NULL)
    {

        if (aux->prox == NULL)
            printf("%d", aux->dado);
        else
            printf("%d, ", aux->dado);

        aux = aux->prox;
    }
    printf("]\n");
}

void removeBack_ListaEnc(ListaEnc *l)
{
    if (size(l) > 1)
    {
        No *ultimo = l->cabeca;
        No *penultimo = l->cabeca;
        while (ultimo->prox != NULL)
        {
            ultimo = ultimo->prox;

            if (ultimo->prox != NULL)
            {
                penultimo = penultimo->prox;
            }
        }

        printf("lista.pop()  (Removendo [%d]...)\n", ultimo->dado);
        free(ultimo);
        penultimo->prox = NULL;
        l->tamanho--;
    }
    else
    {
        No *ultimo = l->cabeca;
        printf("lista.pop()  (Removendo [%d]...)\n", ultimo->dado);
        free(ultimo);
        l->cabeca = NULL;
        l->tamanho--;
    }
}

int hasElement_ListaEnc(const ListaEnc *l, int v)
{
    int i, cont = 0;
    No *aux = l->cabeca;
    for (i = 0; i < size(l); i++)
    {
        if (aux->dado == v)
            return cont;
        else
        {
            aux = aux->prox;
            cont++;
        }
    }
    return -1;
}

int removePosition_ListaEnc(ListaEnc *l, int pos)
{
    if (estaVazia(l) || (pos < 0 || pos >= size(l)))
        return -1;

    else
    {
        if (pos == 0)
        {
            No *aux = l->cabeca;
            No *aux2 = aux->prox;

            free(aux);
            l->cabeca = aux2;
            l->tamanho--;

            printf("del(lista[%d])\n", pos);
            return 0;
        }
        else
        {
            int cont = 1;

            No *aux = l->cabeca;
            No *aux2 = aux->prox;

            while (cont != pos)
            {
                aux = aux->prox;
                aux2 = aux->prox;
                cont++;
            }

            aux->prox = aux2->prox;
            free(aux2);

            l->tamanho--;

            printf("del(lista[%d])\n", pos);
            return 0;
        }
    }
}

int removeElement_ListaEnc(ListaEnc *l, int v)
{
    if (estaVazia(l))
        return -1;

    else
    {
        int i, cont = 0;
        No *aux = l->cabeca;

        if (aux->dado == v && cont == 0)
        {
            l->cabeca = aux->prox;
            free(aux);
            l->tamanho--;
            //printf("Elemento removido da posicao: %d\n", cont);
            return cont;
        }
        else
        {
            cont++;
            No *aux2 = aux->prox;

            for (i = cont; i < size(l); i++)
            {
                if (aux2->dado == v)
                {

                    aux->prox = aux2->prox;
                    free(aux2);
                    l->tamanho--;
                    //printf("Elemento removido da posicao: %d\n", cont);
                    return cont;
                }
                else
                {
                    aux = aux->prox;
                    aux2 = aux->prox;
                    cont++;
                }
            }
        }
    }
}