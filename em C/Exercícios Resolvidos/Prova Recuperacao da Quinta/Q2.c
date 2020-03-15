#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31

typedef struct {
    char nome[MAX];
    int ano;
    char cor[MAX];
    int numero_revisoes;
    float* revisoes;
} Carro;


Carro* criaCarro(char*,int,char*,int);
int atribuiKm(Carro*,int,float);
float kmUltimaRevisao(Carro*);
void desalocaCarro(Carro*);
void printaCarro(Carro*);


int main() {
    printf("Inicio do programa!\n");

    char nome[MAX] = "Exemplo";
    int ano = 2019;
    char cor[MAX] = "Vermelho Escuro";
    int n_revisoes = 5;
    Carro* newCar;

    /* *Programa Simples Sem Entrada:*
    newCar = criaCarro(nome, ano, cor, n_revisoes);
    atribuiKm(newCar, 0, 75000);
    atribuiKm(newCar, 1, 55000.2);
    atribuiKm(newCar, 2, 185000.35);
    atribuiKm(newCar, -1, 85000.3); // Testa index negativo
    atribuiKm(newCar, 8, 85000.3); // Testa index outofbounds
    atribuiKm(newCar, 3, 125000.4);
    atribuiKm(newCar, 4, 5000.7); // Testa valor outofbounds
    atribuiKm(newCar, 4, 255000.7); // Testa valor outofbounds
    atribuiKm(newCar, 4, 155000.71);
    */


    //* *Programa Com Entradas:*
    printf("Digite o nome do carro: "); scanf("%[^\n]s", nome);
    printf("Digite o ano do carro: "); scanf("%d", &ano);
    getchar();
    printf("Digite a cor do carro: "); scanf("%[^\n]s", cor);
    printf("Digite o numero de revisoes: "); scanf("%d", &n_revisoes);
    newCar = criaCarro(nome, ano, cor, n_revisoes);

    printf("\n");
    float valor;
    register int i;
    for(i = 0; i < n_revisoes; i++) {
        printf("Digite a quilometragem %d: ", i+1); scanf("%f", &valor);
        while(1) {
            if(atribuiKm(newCar, i, valor) > 0) {
                break;
            }
            else {
                printf("Digite novamente a quilometragem %d: ", i+1);
                scanf("%f", &valor);
            }
        }
    }
    //*/


    printaCarro(newCar);
    float maior = kmUltimaRevisao(newCar);
    printf("Km da Ultima Revisao: %.2f\n", maior); // printf("Km da Ultima Revisao: %.2f\n", kmUltimaRevisao(newCar));

    desalocaCarro(newCar);

    printf("Fim do programa!\n");
    return 0;
}


Carro* criaCarro(char* nome, int ano, char* cor, int nR) {
    Carro* c = (Carro*) malloc(sizeof(Carro));
    if( c == NULL ) return NULL;

    strcpy(c->nome, nome);
    strcpy(c->cor, cor);

    c->ano = ano;
    c->numero_revisoes = nR;

    c->revisoes = (float*) malloc(sizeof(float));
    if(c->revisoes == NULL) return NULL;

    return c;
}

int atribuiKm(Carro* c,int i, float v) {
    if( i < 0 || i > c->numero_revisoes || v < 10000 || v > 200000) {
        printf("Valor(es) fora do(s) limite(s)!\n\n");
        return -1;
    }
    c->revisoes[i] = v;
    printf("%.2f Kms atribuidos a posicao %d com sucesso!\n\n", v, i);
    return 1;
}

float kmUltimaRevisao(Carro* c) {
    if(c == NULL) return -1;
    float maior = 0;
    register int i;
    for(i = 0; i < c->numero_revisoes; i++) {
        if(c->revisoes[i] > maior) maior = c->revisoes[i];
    }
    return maior;
}

void desalocaCarro(Carro* c) {
    free(c->revisoes);
    free(c);
    printf("Carro desalocado...\n");
}

void printaCarro(Carro* c) {
    if(c == NULL) printf("Carro não criado!\n");
    else {
        printf("|--- Dados do Carro ---|\n");
        printf("Nome: %s\n", c->nome);
        printf("Ano: %d\n", c->ano);
        printf("Cor: %s\n", c->cor);
        printf("Numero de revisoes: %d\n", c->numero_revisoes);
        printf("Revisoes: ");
        register int i;
        for(i = 0; i < c->numero_revisoes; i++) {
            if( i < c->numero_revisoes-1) printf("%.2f, ", c->revisoes[i]);
            else printf("%.2f\n", c->revisoes[i]);
        }
    }
}
