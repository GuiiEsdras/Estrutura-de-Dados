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
#include "Nome_completo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *********************************************************************** //
// ============== Programa Principal | Nome_completo_MAIN.c ============== //

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
