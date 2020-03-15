#include "../include/listlib.h"

#define MAXCHARLENGHT 50 // Limite de caracteres para o nome dos arquivos .txt a serem gerados

/*
 * Para compilar:
 * gcc ./src/testa_bs_enc.c ./lib/bucketsort.c ./include/bucketsort.h ./lib/listlib.c ./include/listlib.h ./include/listaenc.h ./lib/listaenc.c -o tbe
 */

int main()
{
    printf("Iniciando programa...\n");
    delay(1);

    char nameListaEncDesordenada[MAXCHARLENGHT] = "Lista Enc desordenada"; // Nome do arquivo .txt desordenado
    char nameListaEncOrdenada[MAXCHARLENGHT] = "Lista Enc ordenada";       // Nome do arquivo .txt ordenado

    long int n; // Tamanho da Lista Enc
    printf("Digite a quantidade de elementos: ");
    scanf("%ld", &n);

    int c; // Quantidade de baldes usado no Bucket Sort
    printf("Digite a quantidade de baldes: ");
    scanf("%d", &c);

    printf("---\nIniciando algoritmo de ordenacao\n Aguarde...\n---\n");
    delay(1);

    time_t t_inicio = clock(); //? Inicia cronometro antes da ordenacao

    ListaEnc *le = criaListaEnc();

    geraListaEncAleatoria(le, n); //* Gerando Lista Enc com n elementos aleatorios e desordenados

    //*-----GERANDO TXT DESORDENADO-----*/
    //!imprimeArray(arr, n) //! APENAS PARA TESTES !
    if (listaEncParaTXT(le, nameListaEncDesordenada)) // Gera um TXT com os elementos do lista encadeada desordenado
    {
        printf("Lista Encadeada Desordenada convertida em TXT com sucesso!\n");
        printf("---\n");
    }
    else
    {
        printf("Falha ao gerar TXT desordenado!\n");
        printf("Saindo...\n");
        clear(le);
        exit(EXIT_FAILURE);
    }

    //*-----ORDENANDO ARRAY-----*/
    if (BucketSortListaEnc(le, c)) //* Ordena a Lista Encadeada
    {
        printf("Ordenacao finalizada com sucesso!\n");
        printf("---\n");
    }
    else
    {
        printf("Falha ao ordenar lista encadeada!\n");
        printf("---\n");
        printf("Saindo...\n");
        clear(le);
        exit(EXIT_FAILURE);
    }

    //*-----GERANDO TXT ORDENADO-----*/
    if (listaEncParaTXT(le, nameListaEncOrdenada)) // Gera um TXT com os elementos do lista encadeada ordenada
    {
        printf("Lista Encadeada Ordenada convertida em TXT com sucesso!\n");
        printf("---\n");
    }
    else
    {
        printf("Falha ao gerar TXT ordenado!\n");
        printf("Saindo...\n");
        clear(le);
        exit(EXIT_FAILURE);
    }

    clear(le);

    time_t t_fim = clock();                                       // Finaliza cronometro apos ordenacao
    time_t t_final = (double)(t_fim - t_inicio) / CLOCKS_PER_SEC; // Calcula tempo de ordenacao
    printf("Tempo total levado para ordenar: %u segundo(s).\n", t_final);

    printf("Fim de programa.\n");
    return 0;
}