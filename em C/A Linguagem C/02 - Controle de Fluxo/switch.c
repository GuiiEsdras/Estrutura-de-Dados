#include <stdio.h>

int main(int argc, char *argv[]) {
    int num;
    printf("Digite um inteiro entre 1 e 3: ");
    scanf("%i", &num);
    
    switch (num)
    {
    case 1:
        printf("Opção 1\n");
        break;

    case 2:
        printf("Opção 2\n");
        break;

    case 3:
        printf("Opção 3\n");
        break;
    
    default:
        printf("Valor fora dos limites!\n");
        break;
    }
    return 0;
}