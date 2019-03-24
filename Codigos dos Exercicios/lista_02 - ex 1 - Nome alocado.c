/************************************************************************************************
 * Instituto Federal de Educação Ciência e Tecnologia da Paraíba
 * Campus Campina Grande
 * Curso Superior de Bacharel em Engenharia de Computação
 * Componente Curricular: Estrutura de Dados e Algoritmos - 2º Período
 * Professor: Cesar Vasconcelos
 * 
 * Copyright - Guilherme Esdras
 * Esta é a minha solução para o Exercício 1 da Lista de Exercício 2 que pede o seguinte:
 * 
 * 1) Faça um programa simples que peça o nome completo do usuário (máximo 40 caracteres) e
 * possa alocar dinamicamente esta cadeia de caracteres em memória no tamanho exato ao número
 * de careacteres que compõem a cadeia digitada na entrada. Finalmente, o programa deve imprimir
 * esta cadeia utilizando apontadores. Não esqueça de liberar a memória alocada no final!
 * 
 ************************************************************************************************/
// #include "Nome_completo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *********************************************************************** //
// ========= Área de Dados do TAD Nome completo | Nome_completo.h ======== //

typedef struct nome_completo {
    char* nome;
} TNome;

// Interface de uso do TAD Nome completo //

// Operação que aloca dinâmicamente o nome completo do usuário //
TNome* alocarNome (char nome[]);
// Operação que verifica se o ponteiro possui um endereço válido //
int enderecoValido( TNome *a );
// Operação que exibi o nome completo do usuário (alocado dinâmicamente) //
void exibirNome( TNome* a );
// Operação que libera o espaço alocado pelo nome completo no final do programa //
void liberarNome( TNome* a );

// *********************************************************************** //
// ============== Programa Principal | Nome_completo_MAIN.c ============== //
// # include "Nome_completo.h"

int main()
{
    char nome_inicio[41];

    printf("Digite seu nome completo: "); scanf("%40[^\n]", nome_inicio);

    TNome * nome_alocado = alocarNome( nome_inicio );

    if( nome_alocado != NULL ) exibirNome( nome_alocado );

    liberarNome( nome_alocado );

    return 0;
}

// *********************************************************************** //
// =========== Área de designação de Funções | Nome_completo.c =========== //
// # include "Nome_completo.h"

TNome* alocarNome(char nome[]) {
    TNome *p = NULL;

    if( ( p = (TNome*) malloc( sizeof(TNome) ) ) == NULL ) return NULL;

    p -> nome = nome;

    return p;
}

int enderecoValido(TNome* a){ return a != NULL; }

void exibirNome(TNome* a){
    if( enderecoValido( a ) ) {
        printf("Seu Nome Completo: %s", a->nome );

    } else {
        printf("Nao ha dados a serem exibidos. Sem nome.");
    }
}

void liberarNome(TNome* a){ if( a != NULL ) free( a ); }

// *********************************************************************** //