#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct acc {
    int numero;
    char titular[30];
    int transPer;
    float* valores;
};
typedef struct acc Conta;


Conta* criaConta(int num, char* nome, int t_p);
int atribuiValor(Conta* c, int i, float v);
float maiorTrans(Conta* c);
void desaloca(Conta* c);
void printaConta(Conta* c);


int main() {
    /*Programa sem entradas:
    printf("Inicio do programa!\n");

    int numero = 777;
    char name[30] = "Exemplo";
    int trans_permitidas = 4;
    Conta* acc = criaConta(numero, name, trans_permitidas);
    //Conta* acc = criaConta(777, "Exemplo", 4) // Estilo new do java XD

    atribuiValor(acc, 0, 674.10);
    atribuiValor(acc, 1, 1273.44); // Testando fora dos limites
    atribuiValor(acc, 2, -581.25); // Testando negativo
    atribuiValor(acc, 3, -881.25);
    printaConta(acc);
    float maior_trans = maiorTrans(acc);
    printf("A maior transacao foi: %.2f\n", maior_trans);

    atribuiValor(acc, 0, 954.10);
    //maior_trans = maiorTrans(acc);
    //printf("A maior transacao foi: %.2f\n", maior_trans);
    printf("A maior transacao foi: %.2f\n", maiorTrans(acc) );

    desaloca(acc);
    printf("Fim do programa!\n");
    */

    ///*Programa com entradas:
    printf("Inicio do programa!\n");

    int numero; printf("Digite o numero da conta: "); scanf("%d", &numero);
    getchar();
    char name[30]; printf("Digite o nome do titular desta conta: "); scanf("%[^\n]s", name);
    int trans_permitidas; printf("Digite o limite de transacoes permitidas: "); scanf("%d", &trans_permitidas);
    Conta* acc = criaConta(numero, name, trans_permitidas);

    float v;
    register int i;
    for( i = 0; i < trans_permitidas; i++ ) {
        while(1) {
            printf("Digite o valor %d: ", i+1); scanf("%f", &v);
            if(atribuiValor(acc, i, v) > 0) break;
        }
    }
    printaConta(acc);

    float maior_trans = maiorTrans(acc);
    printf("A maior transacao foi: R$ %.2f\n", maior_trans);

    desaloca(acc);

    printf("Fim do programa!\n");
    //*/

    return 0;
}


Conta* criaConta(int num, char* nome, int t_p) {
    Conta* c = (Conta*) malloc(sizeof(Conta));
    if( c == NULL ) return NULL;

    c->numero = num;
    strcpy(c->titular, nome);
    c->transPer = t_p;
    c->valores = (float*) malloc(t_p * sizeof(float));

    printf("Conta criada com sucesso!\n");
    return c;
}

int atribuiValor(Conta* c, int i, float v) {
    if( i < 0 || i > c->transPer || v < -1000 || v > 1000 ) {
        printf("Valor(es) fora do(s) limite(s)!\n");
        return -1;
    }

    c->valores[i] = v;
    printf("Valor %.2f inserido na posicao %d com sucesso!\n\n", v, i);
    return 1;
}

float maiorTrans(Conta* c) {
    if( c == NULL ) return -1;

    int maiorTrans = 0;
    register int i;
    for( i = 0; i < c->transPer; i++ ) {
        if( (c->valores[i] < 0 && (c->valores[i] * -1) > maiorTrans) ||
            (c->valores[i] >= 0 && c->valores[i] > maiorTrans) ) maiorTrans = c->valores[i];
    }

    return maiorTrans;
}

void desaloca(Conta* c) {
    free(c->valores);
    free(c);
    printf("Conta desalocada...\n");
}

void printaConta(Conta* c) {
    if( c == NULL ) printf("Conta nao criada!\n");
    else {
        printf("|----Dados da Conta----|\n");
        printf("Numero da conta: %d\n", c->numero);
        printf("Titular da conta: %s\n", c->titular);
        printf("Limite de transacoes: %d\n", c->transPer);
        printf("Transacoes: [");
        register int i;
        for( i = 0; i < c->transPer; i++ ) {
            if( i < (c->transPer -1) ) printf("R$ %.2f, ", c->valores[i]);
            else printf("R$ %.2f", c->valores[i]);
        }
        printf("]\n");
    }
}