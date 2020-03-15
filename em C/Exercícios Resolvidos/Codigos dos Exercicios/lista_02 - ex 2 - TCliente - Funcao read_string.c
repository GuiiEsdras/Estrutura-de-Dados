/************************************************************************************************
 * Instituto Federal de Educação Ciência e Tecnologia da Paraíba
 * Campus Campina Grande
 * Curso Superior de Bacharel em Engenharia de Computação
 * Componente Curricular: Estrutura de Dados e Algoritmos - 2º Período
 * Professor: Cesar Vasconcelos
 * 
 * Copyright - Guilherme Esdras
 * Esta é a minha solução para o Exercício 2 da Lista de Exercícios 2 que pede o seguinte:
 * 
 * 2) Defina uma estrutura que modele um novo tipo TCliente do mundo real. Use typedef para agilizar
 * este processo. Esta estrutura deve conter: codigo, nome, idade, salario, rua, bairro e cep. Faça com que o
 * programa receba estes dados do usuário e atribua as entradas digitadas por ele em cada um dos
 * campos da estrutura (cuidado com estouro de capacidade dos vetores! O programa deve atribuir
 * apenas a capacidade suportada pelos campos). Ao final, crie uma função imprimeCliente que
 * percorra a estrutura imprimindo cada um dos campos usando apontadores.
 * 
 ************************************************************************************************/
// #include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros //
#define MAX_Nome 41
#define MAX_Rua 81
#define MAX_Bairro 31

// *********************************************************************** //
// ========= Área de Dados do TAD Nome completo | Cliente.h ======== //

typedef struct cliente {
    int codigo;
    char* nome;
    int idade;
    float salario;
    char* rua;
    char* bairro;
    int cep;
} TCliente;

// Interface de uso do TAD Cliente //

// Operação que cria e aloca dinâmicamente um Cliente //
TCliente* criarCliente(int codigo, char nome[], int idade, float salario, char rua[], char bairro[], int cep);
// Operação que verifica se o ponteiro possui um endereço válido //
int enderecoValido( TCliente* cliente );
// Operação que exibi os dados do Cliente (alocado dinâmicamente) //
void exibirCliente( TCliente* cliente );
// Operação que libera o espaço alocado pelo Cliente no final do programa //
void liberarCliente( TCliente* cliente );
// Le strings
void read_string(char *the_string, int size);

// *********************************************************************** //
// ============== Programa Principal | Cliente_MAIN.c ============== //
// # include "Cliente.h"

int main()
{
    int codigo, idade, cep;
    float salario;
    char nome[MAX_Nome], rua[MAX_Rua], bairro[MAX_Bairro];

    printf("Digite seu codigo: "); scanf("%d", &codigo);
    printf("\nDigite seu nome: "); read_string(nome, MAX_Nome);
    printf("\nDigite sua idade: "); scanf("%d", &idade);
    printf("\nDigite seu salario: "); scanf("%f", &salario);
    printf("\nDigite sua rua: "); read_string(rua, MAX_Rua);
    printf("\nDigite seu bairro: "); read_string(bairro, MAX_Bairro);
    printf("\nDigite seu cep: "); scanf("%d", &cep);

    TCliente* cliente = criarCliente( codigo, nome, idade, salario, rua, bairro, cep );

    if( cliente != NULL ) exibirCliente( cliente );

    liberarCliente( cliente );

    return 0;
}

// *********************************************************************** //
// =========== Área de designação de Funções | Cliente.c =========== //
// # include "Cliente.h"

TCliente* criarCliente(int codigo, char nome[], int idade, float salario, char rua[], char bairro[], int cep) {
    TCliente *clienteP = NULL;

    if( ( clienteP = (TCliente*) malloc(sizeof(TCliente) ) ) == NULL ) return NULL;

    clienteP->codigo = codigo;
    clienteP->nome = nome;
    clienteP->idade = idade;
    clienteP->salario = salario;
    clienteP->rua = rua;
    clienteP->bairro = bairro;
    clienteP->cep = cep;

    return clienteP;
}

int enderecoValido( TCliente* cliente ) { return cliente != NULL; }

void exibirCliente( TCliente* cliente ) {
    if( enderecoValido( cliente ) ) {
        printf("Codigo: %d", cliente->codigo);
        printf("\nNome: %s", cliente->nome);
        printf("\nIdade: %d", cliente->idade);
        printf("\nSalario: %.2f", cliente->salario);
        printf("\nRua: %s", cliente->rua);
        printf("\nBairro: %s", cliente->rua);
        printf("\nCEP: %d", cliente->cep);
    
    } else {
        printf("Sem dados para exibir. Cliente nao cadastrado.");
    }
}

void liberarCliente( TCliente* cliente ) { if( cliente != NULL ) free( cliente ); }

void read_string(char *the_string, int size) {

    char ch;

    fgets(the_string, size, stdin);
    strtok(the_string, "\n");
    if (strlen(the_string) == size - 1) {
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
}

// *********************************************************************** //