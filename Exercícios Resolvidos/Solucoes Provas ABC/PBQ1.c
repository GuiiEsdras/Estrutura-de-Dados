#include <stdio.h>

void ehNumerica(char* frase) {
    int palavraTemNum = 0;
    int quant_de_Palavras = 0;
    int quant_de_PalavrasComNumeros = 0;

    register int i;
    for( i = 0; frase[i] != '\0'; i++ ) {
        if( frase[i] >= '0' && frase[i] <= '9' ) {
            palavraTemNum = 1;
        }

        if( frase[i] != ' ' && (frase[i+1] == ' ' || frase[i+1] == '\0') ) {
            if( palavraTemNum ) { 
                quant_de_PalavrasComNumeros++;
            }
            quant_de_Palavras++;
            palavraTemNum = 0;
        }
    }

    if( quant_de_Palavras == quant_de_PalavrasComNumeros ) printf("SIM");
    else printf("NAO");
    //printf("\nPalavras: %d, Palavras com numeros: %d\n", quant_de_Palavras, quant_de_PalavrasComNumeros);
}

int main() {
    //printf("Digite a frase: ");
    char frase[50]; scanf("%[^\n]s", frase);
    ehNumerica(frase);
    return 0;
}