#include "../include/listlib.h"

// Gerador de numeros aleatorios para Array vazio
bool geraArrayAleatorio(long int *arr, long int n)
{
    printf("Gerando array com %ld elementos...\n", n);

    srand(time(NULL));
    long int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = (rand() * rand()) % n + 1;
    }

    printf("Array gerado!\n");
    return true;
}

// Passa elementos de um determinado Array para um novo TXT
bool arrayParaTXT(long int *arr, long int n, char *fileName)
{

    strcat(fileName, ".txt");
    printf("Gerando arquivo \"%s\"...\n", fileName);

    FILE *pFile;
    pFile = fopen(fileName, "w");

    if (pFile == NULL)
    {
        printf("Erro ao tentar escrever arquivo! =(\n");
        return NULL;
    }

    printf("Iniciando gravacao...\n");
    long int i;
    for (i = 0; i < n; i++)
    {
        if (i < n - 1)
            fprintf(pFile, "%ld\n", arr[i]);
        else
            fprintf(pFile, "%ld", arr[i]);
    }

    printf("Arquivo gerado!\n");
    fclose(pFile);
    return true;
}

// Gerador de numeros aleatorios para Lista Encadeada vazia
bool geraListaEncAleatoria(ListaEnc *le, long int n)
{

    printf("Gerando lista encadeada com %ld elementos...\n", n);

    srand(time(NULL));
    long int i;
    for (i = 0; i < n; i++)
    {
        long int temp = (rand() * rand()) % n + 1;
        add(le, temp);
    }

    printf("Lista encadeada gerada!\n");
    return true;
}

// Passa elementos de uma determinada Lista Encadeada para um novo TXT
bool listaEncParaTXT(ListaEnc *le, char *fileName)
{

    if (estaVazia(le))
    {
        printf("Lista Encadeada vazia ou nao iniciada!\n");
        return false;
    }

    strcat(fileName, ".txt");
    printf("Gerando arquivo \"%s\"...\n", fileName);

    FILE *pFile;
    pFile = fopen(fileName, "w");

    if (pFile == NULL)
    {
        printf("Erro ao tentar escrever arquivo! =(\n");
        return NULL;
    }

    printf("Iniciando gravacao...\n");
    No *aux = le->cabeca;
    while (aux != NULL)
    {

        if (aux->prox != NULL)
            fprintf(pFile, "%ld\n", aux->dado);
        else
            fprintf(pFile, "%ld", aux->dado);

        aux = aux->prox;
    }

    free(aux);
    fclose(pFile);

    printf("Arquivo gerado!\n");
    return true;
}

// Gera um tempo de espera/pausa no programa
void delay(int number_of_seconds)
{
    // Converte o numero de segundos para milisegundos
    int milli_seconds = 1000 * number_of_seconds;

    // Inicia tempo
    clock_t start_time = clock();

    // Entra em um loop ate o tempo ser atingido
    while (clock() < start_time + milli_seconds)
        ;
}

// ! Apenas para Testes com Array
void imprimeArray(long int *arr, long int TAM)
{
    long int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%ld\n", arr[i]);
    }
    printf("**************************************************************\n");
}