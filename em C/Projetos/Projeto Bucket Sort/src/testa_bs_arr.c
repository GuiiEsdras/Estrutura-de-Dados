#include "../include/listlib.h"

#define MAXCHARLENGHT 50 // Limite de caracteres para o nome dos arquivos .txt a serem gerados

/*
 * Para compilar:
 * gcc ./src/testa_bs_arr.c ./lib/bucketsort.c ./include/bucketsort.h ./lib/listlib.c ./include/listlib.h ./include/listaenc.h ./lib/listaenc.c -o tba
 */

int main()
{
    printf("Iniciando programa...\n");
    delay(1);

    char nameArrayDesordenado[MAXCHARLENGHT] = "Array desordenado"; // Nome do arquivo .txt desordenado
    char nameArrayOrdenado[MAXCHARLENGHT] = "Array ordenado";       // Nome do arquivo .txt ordenado

    long int n; // Tamanho do Array
    printf("Digite a quantidade de elementos: ");
    scanf("%ld", &n);

    int c; // Quantidade de baldes usado no Bucket Sort
    printf("Digite a quantidade de baldes: ");
    scanf("%d", &c);

    printf("---\nIniciando algoritmo de ordenacao\n Aguarde...\n---\n");
    delay(1);

    time_t t_inicio = clock(); //? Inicia cronometro antes da ordenacao

    long int *arr;
    arr = (long int*) malloc(n * sizeof(long int));

    geraArrayAleatorio(arr, n); //* Gerando Array com n elementos aleatorios e desordenados

    //*-----GERANDO TXT DESORDENADO-----*/
    //!imprimeArray(arr, n) //! APENAS PARA TESTES !
    if (arrayParaTXT(arr, n, nameArrayDesordenado)) // Gera um TXT com os elementos do array desordenado
    {
        printf("Array Desordenado convertido em TXT com sucesso!\n");
        printf("---\n");
    }
    else
    {
        printf("Falha ao gerar TXT desordenado!\n");
        printf("Saindo...\n");
        free(arr);
        arr = NULL;
        exit(EXIT_FAILURE);
    }

    //*-----ORDENANDO ARRAY-----*/
    if (BucketSortArray(arr, n, c)) //* Ordena Array
    {
        printf("Ordenacao finalizada com sucesso!\n");
        printf("---\n");
    }
    else
    {
        printf("Falha ao ordenar array!\n");
        printf("---\n");
        printf("Saindo...\n");
        free(arr);
        arr = NULL;
        exit(EXIT_FAILURE);
    }

    //*-----GERANDO TXT ORDENADO-----*/
    if (arrayParaTXT(arr, n, nameArrayOrdenado)) // Gera um TXT com os elementos do array ordenado
    {
        printf("Array Ordenado convertido em TXT com sucesso!\n");
        printf("---\n");
    }
    else
    {
        printf("Falha ao gerar TXT ordenado!\n");
        printf("Saindo...\n");
        free(arr);
        arr = NULL;
        exit(EXIT_FAILURE);
    }

    free(arr);
    arr = NULL;

    time_t t_fim = clock();                                       // Finaliza cronometro apos ordenacao
    time_t t_final = (double)(t_fim - t_inicio) / CLOCKS_PER_SEC; // Calcula tempo de ordenacao
    printf("Tempo total levado para ordenar: %u segundo(s).\n", t_final);

    printf("Fim de programa.\n");
    return 0;
}