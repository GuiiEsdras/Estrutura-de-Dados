#include "../include/bucketsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* .::Gera Array Aleatorio::.
 * -------------------
 *  arr: Ponteiro para um array vazio
 *  n: Numero de elementos a serem criados aleatoriamente e colocados neste array
 *  returns: true se conseguir, false caso contrario
 */
bool geraArrayAleatorio(long int *arr, long int n);

/* .::array Para TXT::.
 * -------------------
 *  int* arr: Ponteiro para o array na qual contem os elementos a serem transferidos para o .txt
 *  int n: Tamanho do array
 *  fileName: Nome do arquivo .txt a ser criado (Obs.: Nao e necessario colocar a extensao ".txt" no nome))
 *  returns: true se der tudo certo ou false se der algo errado
 */
bool arrayParaTXT(long int *arr, long int n, char *fileName);

/* .::Gera Lista Encadeada Aleatoria::.
 * -------------------
 *  le: Ponteiro para uma lista encadeada vazia
 *  n: Numero de elementos a serem criados aleatoriamente e colocados nesta lista encadeada
 *  returns: true se conseguir, false caso contrario
 */
bool geraListaEncAleatoria(ListaEnc *le, long int n);

/* .::Lista Encadeada Para TXT::.
 * -------------------
 *  le: Ponteiro para uma Lista Encadeada
 *  fileName: Nome do arquivo .txt a ser criado (Obs.: Nao e necessario colocar a extensao ".txt" no nome))
 *  returns: true se der tudo certo ou false se der algo errado
 */
bool listaEncParaTXT(ListaEnc *le, char *fileName);

/* 
 * Apenas gera um tempo de espera no programa
 */
void delay(int number_of_seconds);

// ! Apenas para Testes com Array
void imprimeArray(long int *, long int);