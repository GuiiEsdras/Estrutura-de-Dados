#include <stdio.h>
#include <stdlib.h> // Biblioteca usada para conversões de string.

int main(int argc, char *argv[]) {
    char intString[] = "1234";
    char floatString[] = "328.4";
    int strParaInt = atoi(intString); // da biblioteca stdlib.h | Converte de char/string para inteiro
    double strParaDouble = atof(floatString); // da biblioteca stdlib.h | Converte de char/string para double/float
    printf("intString = %s, floatString = %s\n", intString, floatString);
    printf("strParaInt = %d, strParaDouble = %.1f\n\n", strParaInt, strParaDouble);

    int a = 2;
    double b = 3.14;
    char umaString1[64], umaString2[64];
    sprintf(umaString1, "%d", a); // da biblioteca stdlib.h | Atribui a umaString1 o valor da variável inteira 'a' como String.
    sprintf(umaString2, "%.2f", b); // da biblioteca stdlib.h | Atribui a umaString2 o valor da variável double 'b' como String.
    printf("a = %d, b = %.2f\n", a, b);
    printf("umaString1 = %s, umaString2 = %s\n", umaString1, umaString2);

    return 0;
}