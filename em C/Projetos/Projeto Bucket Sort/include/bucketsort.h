#include "../include/listaenc.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <math.h>

// Struct balde
typedef struct
{
    long int topo;   // contador de elementos dentro do balde
    long int *dados; // array que guarda os elementos do balde
} balde;

/* .::Bucket Sort Array::.
 * -------------------
 *  arr: Ponteiro para um array desordenado
 *  n: Numero de elementos desse array
 *  returns: true se conseguir ordenar o array, false caso contrario
 */
bool BucketSortArray(long int *a, long int n, int c);

bool BubbleSort(long int *a, long int n);

/* .::Bucket Sort Lista Encadeada::.
 * -------------------
 *  le: Ponteiro para uma lista encadeada desordenada
 *  returns: true se conseguir ordenar a lista, false caso contrario
 */
bool BucketSortListaEnc(ListaEnc *le, int c);
bool BucketSortListaEnc2(ListaEnc *le, int c);