#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31

typedef struct prod {
    char nome[MAX];
    int quantidade;
    float* preco;
} Produto;


Produto* criaProduto(char* nome, int quant);
int atribuiPreco(Produto* p, int i, float v);
float mediaDePreco(Produto* p);
void desaloca(Produto* p);
void printaProduto(Produto* p);


int main() {
    /*Exemplo sem entrada de dados:
    printf("Programa iniciado!\n");

    char name[MAX] = "Exemplo";
    int quantity = 5;
    Produto* product = criaProduto(name, quantity);
    //Produto* product = criaProduto("Guilherme", 5)

    atribuiPreco(product, 0, 100.10);
    atribuiPreco(product, 1, 150.20);
    atribuiPreco(product, 2, 200.30);
    atribuiPreco(product, 3, 250.40);
    atribuiPreco(product, 4, 300.50);
    printaProduto(product);

    float media = mediaDePreco(product);
    printf("Media dos precos: %.2f\n", media);
    //printf("Media dos precos: %.2f\n", mediaDePreco(product) );

    desaloca(product);
    printf("Fim do programa!\n");
    */

    //----------------------------//
    //*Exemplo com entrada de dados:
    printf("Programa iniciado!\n");

    char name[MAX]; printf("Insira o nome do produto: "); scanf("%[^\n]s", name);
    int quantity; printf("Insira a quantidade: "); scanf("%d", &quantity);
    Produto* product = criaProduto(name, quantity);

    float value;
    register int posicao;
    for( posicao = 0; posicao < product->quantidade; posicao++ ) {
        while(1) {
            printf("Insira o valor %d: ", posicao+1); scanf("%f", &value);
            if(atribuiPreco(product, posicao, value) > 0) break;
        }
    }
    printaProduto(product);

    float media = mediaDePreco(product);
    printf("Media dos precos: %.2f\n", media);

    desaloca(product);
    printf("Fim do programa!\n");
    //*/

    return 0;
}


Produto* criaProduto(char* nome, int quant) {
    if( quant < 1 ) {
        printf("Quantidade inferior ao permitido");
        return NULL;
    }

    Produto* p; 
    p = (Produto*) malloc(sizeof(Produto)); 
    if( p == NULL ) return NULL; 

    strcpy(p->nome, nome);
    p->quantidade = quant;
    p->preco = (float*) malloc(quant * sizeof(float));

    printf("Produto criado com sucesso!\n");
    return p;
}

int atribuiPreco(Produto* p, int index, float value) {
    if( index < 0 || index > p->quantidade-1 || value <= 0 ) {
        printf("Falha na insercao! Valores fora dos limites!\n");
        return -1;
    }
    
    register int i;
    for( i = 0; i < p->quantidade; i++ ) {
        if( i == index ) {
            p->preco[i] = value;
            printf("Valor %.2f atribuido a posicao %d com sucesso!\n\n", value, index);
        }
    }
    return 1;
}

float mediaDePreco(Produto* p) {
    if( p == NULL ) return -1;

    float sum = 0;
    register int i;
    for( i = 0; i < p->quantidade; i++ ) {
        if( p->preco[i] > 0 ) {
            sum += p->preco[i];
        }
    }

    if( sum > 0 ) {
        return sum / p->quantidade;
    } else return -1;
}

void desaloca(Produto* p) {
    free(p->preco);
    free(p);
    printf("Produto desalocado...\n");
}


void printaProduto(Produto* p) {
    if( p == NULL ) printf("Produto nao criado!\n");
    else {
        printf("|----Dados do Produto---|\n");
        printf("Nome do produto: %s\n", p->nome);
        printf("Quantidade: %d\n", p->quantidade);
        printf("Precos: [");
        register int i;
        for( i = 0; i < p->quantidade; i++ ) {
            if( p->preco[i] > 0 ) {
                if( i < p->quantidade-1 ) printf("R$ %.2f, ", p->preco[i]);
                else printf("R$ %.2f", p->preco[i]);
            }
        }
        printf("]\n");
    }
}
