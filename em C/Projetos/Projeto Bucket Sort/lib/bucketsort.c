#include "../include/bucketsort.h"

// recebe um array e a quantidade de elementos
// sendo estes membros da estrutura "balde"
bool BubbleSort(long int *a, long int n)
{
    printf(".");
    long int i, j;
    // realiza uma busca sem atingir o final do array
    // ja que e garantido que um numero sempre sera trocado com um a sua frente
    for (i = 0; i < (n - 1); i++)
    {
        for (j = 0; j < (n - i - 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                long int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    printf(".");
    return true;
}

// essa funcao recebe como paramento um ponteiro de um array, a quantidade de elementos do array e a quantidade de caixas que voce quer usar
bool BucketSortArray(long int *a, long int n, int c)
{
    printf("Iniciando Bucket Sort com %ld elementos e %d baldes!\n", n, c);
    long int i, j, k;                                         // variaveis usadas em repeticoes (for/while)
    long int menor = __INT_MAX__, maior = (-1 * __INT_MAX__); // variaveis que guardarao o maior e menor numero dentro da lista
    balde baldes[c];                                          // criacao dos baldes

    printf("Buscando maior e menor elemento da lista...\n");
    for (i = 0; i < n; i++)
    { // for para buscar o menor e o maior elemento da lista
        if (a[i] < menor)
            menor = a[i];
        if (a[i] > maior)
            maior = a[i];
    }

    long int range = maior - menor; // calcula a diferença entre o maior e o menor
    double x = (double)range / c;   // variavel de cast para usar a funcao ceil que arredonda para cima um numero do tipo double
    // importante para garantir a quantidade de intervalos com precisao
    long int interval = ceil(x); // arredondamento

    printf("\nPreparando para iniciar e alocar os baldes...\n");
    printf("- Iniciando e alocando balde:");
    for (i = 0; i < c; i++)
    { // repeticao que inicializa cada balde, zerando os dados guardados e fazendo seu topo ser 0
        printf(" %ld...", i + 1);
        baldes[i].topo = 0;
        baldes[i].dados = (long int *)malloc(n * sizeof(long int));
    }
    printf(" Concluido!\n\n");

    printf("Preparando para separar baldes! Aguarde...\n");
    printf("- Separando balde:");
    for (i = 0; i < c; i++)
    {
        printf(" %ld...", i + 1);
        for (j = 0; j < n; j++)
        {
            if ((menor <= a[j]) && (a[j] <= (menor + interval)))
            { // se um numero estiver no intervalo menor < a[j](a == array passado pra funcao) < menor + intervalo
                if (a[j] != -1)
                {                                             // se o numero nunca foi verificado (marco os verificados como -1)
                    baldes[i].dados[baldes[i].topo++] = a[j]; // adiciona o numero ao seu respectivo balde
                    a[j] = -1;                                // marca
                }
            }
        }
        menor += interval; // aumenta o menor valor possivel de se obter ja que provavelmente todos ja foram verificados
    }
    printf(" Concluido!\n\n");

    printf("Preparando para ordenar baldes usando Bubble Sort! Aguarde...\n");
    printf("- Ordenando balde:");
    for (i = 0; i < c; i++)
    {
        printf(" %ld", i + 1);
        BubbleSort(baldes[i].dados, baldes[i].topo); // funcao que ordena cada um dos baldes separadamente
        printf(".");
    }
    printf(" Concluido!\n\n");

    i = 0;

    printf("Juntando todos os baldes em 1 e retornando para o array...\n");
    // repeticao para jogar todos os elementos em 1 unico array
    while (i < n)
    {
        for (j = 0; j < c; j++)
        {
            for (k = 0; k < baldes[j].topo; k++)
            {
                a[i++] = baldes[j].dados[k];
            }
        }
    }

    printf("Finalizando funcao...\n");
    printf("- Liberando espaco alocado no balde:");
    for (i = 0; i < c; i++)
    { // repeticao que libera a memoria alocada em cada balde
        printf(" %ld...", i + 1);
        free(baldes[i].dados);
    }
    printf(" Finalizado!\n\n");

    printf("Bucket Sort concluido!\n");
    return true;
}

/*******BUCKET SORT LISTA ENCADEADA*******/

bool BucketSortListaEnc2(ListaEnc *le, int c)
{
    // inicializa e aloca memoria das variaveis usadas dentro desta funcao
    long int tam = le->tamanho, *arr = (long int *)malloc(tam * sizeof(long int)), i = 0;

    No *aux = le->cabeca; // cria um no auxiliar que percorrera a lista encadeada
    while (aux != NULL)
    {
        arr[i++] = aux->dado; // adiciona cada elemento da lista encadeada ao array temporario
        aux = aux->prox;
    }
    free(aux); // libera o no auxiliar

    BucketSortArray(arr, tam, c); // ordena o array temporario

    i = 0;
    No *aux2 = le->cabeca; // cria outro no auxiliar
    while (aux2 != NULL)
    {
        aux2->dado = arr[i++]; // transfere todos os elementos do array temporario para a lista encadeada passada como parametro
        aux2 = aux2->prox;
    }

    return true;
}

bool BucketSortListaEnc(ListaEnc *le, int c)
{
    printf("Iniciando Bucket Sort em uma Lista Encadeada com %ld elementos e %d baldes!\n", le->tamanho, c);
    long int i, j, k;                                         // variaveis que usarei em repeticoes (for/while)
    long int menor = __INT_MAX__, maior = (-1 * __INT_MAX__); // variaveis que guardaram o maior e menor numero dentro da lista
    balde baldes[c];                                          // criacao dos baldes

    printf("Buscando maior e menor elemento da lista...\n");
    No *aux;          // Cria um no auxiliar
    aux = le->cabeca; // faz o no apontar para o primeiro elemento da lista
    // usa o no auxiliar para percorrer a lista em busca do maior e do menor elemento
    while (aux != NULL)
    {
        if (aux->dado < menor)
            menor = aux->dado;
        if (aux->dado > maior)
            maior = aux->dado;
        aux = aux->prox;
    }
    free(aux);

    long int range = maior - menor; // tiro a diferença entre o maior e o menor
    double x = (double)range / c;   // variavel de cast para usar a funcao ceil que arredonda para cima um numero do tipo double
    // importante para garantir a quantidade de intervalos com precisao
    long int interval = ceil(x); // arredondamento

    printf("Maior: %ld & Menor: %ld\n", maior, menor);
    printf("Interval: %ld\n", interval);

    printf("\nPreparando para iniciar e alocar baldes...\n");
    printf("- Iniciando e alocando balde:");
    for (i = 0; i < c; i++)
    { // repeticao que inicializa cada balde, zerando os dados guardados e fazendo seu topo ser 0
        printf(" %ld...", i + 1);
        baldes[i].topo = 0;
        baldes[i].dados = (long int *)malloc(le->tamanho * sizeof(long int));
    }
    printf(" Concluido!\n\n");

    printf("Preparando para separar baldes...\n");
    printf("- Separando balde:");

    for (i = 0; i < c; i++)
    {
        printf(" %ld...", i + 1);

        for (j = 0; j < le->tamanho; j++)
        {
            No *aux2 = le->cabeca;
            long int i = 0;
            while (i < j)
            {
                aux2 = aux2->prox;
                i++;
            }

            if ((menor <= aux2->dado) && (aux2->dado <= (menor + interval)))
            { // se o numero sendo analisado estiver no intervalo menor < este numero < menor + intervalo
                if (aux2->dado != -1)
                {                                                   // se o numero nunca foi verificado (marco os verificados como -1)
                    baldes[i].dados[baldes[i].topo++] = aux2->dado; // adiciono o numero ao seu respectivo balde
                    aux2->dado = -1;
                }
            }
        }
        menor += interval; // aumento o menor valor possivel de se obter ja q provavelmente todos ja foram verificados
    }

    printf(" Concluido!\n\n");

    printf("Preparando para ordenar baldes usando Bubble Sort! Aguarde...\n");
    printf("- Ordenando balde:");
    for (i = 0; i < c; i++)
    {
        printf(" %ld", i + 1);
        BubbleSort(baldes[i].dados, baldes[i].topo); // funcao que ordena cada um dos baldes separadamente
        printf(".");
    }
    printf(" Concluido!\n\n");

    i = 0;

    printf("Juntando todos os baldes em 1 e retornando para a lista encadeada...\n");
    // repeticao para jogar todos os elementos em 1 unico array
    while (i < le->tamanho)
    {
        for (j = 0; j < c; j++)
        {
            for (k = 0; k < baldes[j].topo; k++)
            {
                insertVInPosition(le, baldes[j].dados[k], i++);
            }
        }
    }

    printf("Finalizando funcao...\n");
    printf("- Liberando espaco alocado no balde:");
    for (i = 0; i < c; i++)
    { // repeticao que libera a memoria alocada em cada balde
        printf(" %ld", i + 1);
        free(baldes[i].dados);
    }
    printf(" Finalizado!\n\n");

    printf("Bucket Sort concluido na Lista Encadeada!\n");
    return true;
}