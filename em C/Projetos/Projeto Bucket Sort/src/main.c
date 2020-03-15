#include "../include/listlib.h"

#define MAXCHARLENGHT 50 // Limite de caracteres para o nome dos arquivos .txt a serem gerados

void exibeMenu();

int main()
{
    printf("Iniciando programa...\n");
    delay(1);

    time_t t_inicio, t_fim, t_final;
    char nameArrayDesordenado[MAXCHARLENGHT] = "Array desordenado"; // Nome do arquivo .txt desordenado
    char nameArrayOrdenado[MAXCHARLENGHT] = "Array ordenado";       // Nome do arquivo .txt ordenado

    char nameListaEncDesordenada[MAXCHARLENGHT] = "Lista Enc desordenada"; // Nome do arquivo .txt desordenado
    char nameListaEncOrdenada[MAXCHARLENGHT] = "Lista Enc ordenada";       // Nome do arquivo .txt ordenado

    exibeMenu();
    int opcao;

    while (true)
    {
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            printf("Tipo Array escolhido!\n");
            break;
        }
        else if (opcao == 2)
        {
            printf("Tipo Lista Encadeada escolhido!\n");
            break;
        }
        else
            printf("Opcao invalida! Digite de novo: ");
    }

    long int n; // Quantidade de elementos a serem ordenados
    printf("Digite a quantidade de elementos: ");
    scanf("%ld", &n);

    int c; // Quantidade de baldes usado no Bucket Sort
    printf("Digite a quantidade de baldes: ");
    scanf("%d", &c);

    printf("---\nIniciando algoritmo de ordenacao\n Aguarde...\n---\n");
    delay(1);

    switch (opcao)
    {
    case 1:
        t_inicio = clock(); //? Inicia cronometro antes da ordenacao

        long int *arr;
        arr = (long int *)malloc(n * sizeof(long int));

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

        t_fim = clock();                                       // Finaliza cronometro apos ordenacao
        t_final = (double)(t_fim - t_inicio) / CLOCKS_PER_SEC; // Calcula tempo de ordenacao
        printf("Tempo total levado para ordenar: %u segundo(s).\n", t_final);
        break;

    case 2:
        t_inicio = clock(); //? Inicia cronometro antes da ordenacao

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
        if (BucketSortListaEnc2(le, c)) //* Ordena a Lista Encadeada
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

        t_fim = clock();                                       // Finaliza cronometro apos ordenacao
        t_final = (double)(t_fim - t_inicio) / CLOCKS_PER_SEC; // Calcula tempo de ordenacao
        printf("Tempo total levado para ordenar: %u segundo(s).\n", t_final);
        break;
    }

    printf("Fim de programa.\n");
    return 0;
}

void exibeMenu()
{
    printf("Programa de Ordenacao com Bucket Sort!\n"
           " Escolha o tipo de lista na qual deseja gerar e ordenar:\n"
           "   [1] - Array\n"
           "   [2] - Lista Encadeada\n"
           "       Digite sua opcao: ");
}

/*
 * Para compilar:
 * gcc ./src/main.c ./lib/bucketsort.c ./include/bucketsort.h ./lib/listlib.c ./include/listlib.h ./include/listaenc.h ./lib/listaenc.c -o tba
 */