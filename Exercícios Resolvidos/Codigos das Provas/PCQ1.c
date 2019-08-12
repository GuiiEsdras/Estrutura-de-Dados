#include <stdio.h>

void temEsseChar(char caractere, char* frase) {
    int TemOChar = 0;
    int palavras_QTemOChar = 0;
    register int i;
    for( i = 0; frase[i] != '\0'; i++ ) {
        if( frase[i] == caractere ) {
            TemOChar = 1;
        }
        if( frase[i+1] == ' ' || frase[i+1] == '\0' ) {
            if( TemOChar ) {
                palavras_QTemOChar++;
            }
            TemOChar = 0;
        }
    }

    printf("%d", palavras_QTemOChar);
}

int main() {
    char caractere; scanf("%c", &caractere);
    getchar();
    char palavras[100]; scanf("%[^\n]s", palavras);
    temEsseChar(caractere, palavras);
    return 0;
}