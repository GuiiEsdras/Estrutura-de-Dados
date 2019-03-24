#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nomeVetor[15] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140 };
    int * p;
    int * pt1, * pt2;

    pt1 = &nomeVetor[6];
    pt2 = nomeVetor;

    printf("nomeVetor[15] = {");
    for(int i = 0; i < 15; i++) {
        if( i != 14 ) printf(" %d,", nomeVetor[i]);
        else printf(" %d", nomeVetor[i]);
    } printf(" }\n");

    p = nomeVetor;
    // p está apontando para a primeira posição de nomeVetor, ou seja, aponta para a posição do elemento { 10 }
    printf("p = nomeVetor: %d \n", *p); // Imprime o conteúdo de onde p está apontando.

    /*
    printf("%d \n", p); // Imprime o endereço de onde p está apontando.
    printf("%d \n", &nomeVetor); // Imprime o endereço da primeira posição do nomeVetor.
    printf("%p \n", p); // Imprime o endereço de onde p está apontando em Hexadecimal.
    printf("%p \n", nomeVetor); // Imprime o endereço da primeira posição do nomeVetor em Hexadecimal.
    printf("%d \n", &p); // Imprime o endereço do ponteiro p.
    printf("%p \n", &p); // Imprime o endereço do ponteiro p em Hexadecimal.

    // Quando se usa %p ele imprime o endereço da variável em formato Hexadecimal.
    */

    p = &nomeVetor[3];
    // p aponta para o 3º elemento do vetor, ou seja, nomeVetor[3] ou { 30 }
    printf("p = &nomeVetor[3]: %d \n", *p);

   p++;
    // avança +1 posição, ou seja, agora p aponta para o elemento { 40 }, ou seja, nomeVetor[4]
    printf("p++: %d \n", *p);

    printf("*p++: %d \n", *p++);
    // primeiro printa o valor { 40 } e depois avança uma posição adiante (vai para nomeVetor[5])

    printf("p: %d \n", *p);
    // exibe 50

    printf("(*p)++: %d \n", (*p)++);
    // ele primeiro irá printar o valor da posição atual,
    // e depois do print somar +1 ao elemento dessa posição

    printf("*(p++): %d \n", *(p++));
    // ele primeiro irá printar o valor dessa posição,
    // e depois do print irá avançar +1 posição

    printf("p: %d \n", *p);
    // agora depois do print p está apontando para o nomeVetor[6], ou seja, { 60 }

    printf("*(p + 8): %d \n", *(p + 8));
    // imprime +8 posições à partir de onde ele está apontando,
    // ou seja, o elemento nomeVetor[14], ou seja, { 140 }

    printf("(*p) + 8: %d \n", (*p) + 8);
    // printa o valor na qual p está apontando somado com 8
    // ele aponta para 60, com +8 fica 68

    printf("*(p + 2): %d \n", *(p + 2));
    // desloca 2 posições à frente de onde p está apontando

    printf("p[2]: %d \n", p[2]);
    // exibe o elemento da posição 2 à partir de onde p está apontando

    if( pt1 == (pt2 + 6) ) {
        printf("Sim!");
    } // Basicamente está conferindo se pt1 está apontando para o mesmo lugar que o pt2 deslocado 6 posições adiante

    return 0;
}
