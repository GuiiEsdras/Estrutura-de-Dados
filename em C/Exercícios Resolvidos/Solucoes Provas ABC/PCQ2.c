#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31

typedef struct al {
    char nome[MAX];
    char cpf[MAX];
    int idade;
    int quant_disciplinas;
    float* notas;
} Aluno;


Aluno* criaAluno(char* nome, char* CPF, int idade, int quant);
int atribuiNota(Aluno* a, int i, float n);
float mediaGeral(Aluno* a);
void desaloca(Aluno* a);
void printaAluno(Aluno* a);


int main() {
    /*Programa sem entradas:
    printf("Inicio do Programa!\n");
    char nome[MAX] = "Exemplo";
    char CPF[MAX] = "777.xxx.xxx-33";
    int idade = 20;
    int quant_disciplinas = 5;
    Aluno* al = criaAluno(nome, CPF, idade, quant_disciplinas);

    atribuiNota(al, 0, 70);
    atribuiNota(al, 1, 30);
    atribuiNota(al, 2, 0);
    atribuiNota(al, 3, 85);
    atribuiNota(al, 4, 100);
    printaAluno(al);

    float media = mediaGeral(al);
    printf("Media Geral: %.2f\n", media);

    desaloca(al);
    printf("Fim do Programa!\n");
    */

    ///*Programa com entradas:
    printf("Inicio do Programa!\n");
    char nome[MAX]; printf("Insira o nome do aluno: "); scanf("%[^\n]s", nome);
    getchar();
    char CPF[MAX]; printf("Insira o CPF do aluno: "); scanf("%s", CPF);
    int idade; printf("Insira a idade do aluno: "); scanf("%d", &idade);
    int quant_disciplinas; printf("Insira a quantidade de disciplinas do aluno: "); scanf("%d", &quant_disciplinas);
    Aluno* al = criaAluno(nome, CPF, idade, quant_disciplinas);

    float nota;
    register int i;
    for( i = 0; i < quant_disciplinas; i++ ) {
        while(1) {
            printf("Insira a nota %d [entre 0 e 10.0]: ", i+1); scanf("%f", &nota);
            if( atribuiNota(al, i, nota) > 0 ) break;
        }
    }
    printaAluno(al);

    float media = mediaGeral(al);
    printf("Media Geral: %.2f\n", media);

    desaloca(al);
    printf("Fim do Programa!\n");
    //*/
    return 0;
}


Aluno* criaAluno(char* nome, char* CPF, int idade, int quant_dis) {
    Aluno* a = (Aluno*) malloc(sizeof(Aluno));
    if( a == NULL ) return NULL;

    strcpy(a->nome, nome);
    strcpy(a->cpf, CPF);
    a->idade = idade;
    a->quant_disciplinas = quant_dis;
    a->notas = (float*) malloc(quant_dis * sizeof(float));

    printf("Aluno criado com sucesso!\n");
    return a;
}

int atribuiNota(Aluno* a, int i, float n) {
    if( i < 0 || i > a->quant_disciplinas || n < 0 || n > 10.0 ) {
        printf("Valor(es) fora do(s) limite(s)!\n");
        return -1;
    } else {
        a->notas[i] = n;
        printf("Nota %.1f atribuida a posicao %d com sucesso!\n", n, i);
        return 1;
    }
}

float mediaGeral(Aluno* a) {
    if( a == NULL ) {
        printf("Aluno nao criado!\n");
        return -1;
    }
    int sum = 0;
    register int i;
    for( i = 0; i < a->quant_disciplinas; i++ ) {
        sum += a->notas[i];
    }

    if( sum > 0 ) return sum / a->quant_disciplinas;
    else return sum;
}
void desaloca(Aluno* a) {
    if( a == NULL ) printf("Aluno nao foi criado!\n");
    else {
        free(a->notas);
        free(a);
        printf("Aluno desalocado...\n");
    }
}
void printaAluno(Aluno* a) {
    if( a == NULL ) printf("Aluno nao foi criado!\n");
    else {
        printf("|--- Dados do Aluno ---|\n");
        printf("Nome: %s\n", a->nome);
        printf("CPF: %s\n", a->cpf);
        printf("Idade: %d\n", a->idade);
        printf("Quantidade de Disciplinas: %d\n", a->quant_disciplinas);
        printf("Notas: ");
        register int i;
        for( i = 0; i < a->quant_disciplinas; i++ ) {
            if( i < (a->quant_disciplinas-1) ) printf("%.2f, ", a->notas[i]);
            else printf("%.1f\n", a->notas[i]);
        }
    }
}