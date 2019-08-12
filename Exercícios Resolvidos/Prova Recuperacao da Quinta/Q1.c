#include <stdio.h>
#define max 51

int serveComoSenha(char* frase) { 
    int cont_LetrasNaPalavra = 0, cont_Vogais = 0, UmaPalavraTemVogal = 0; 

    register int i;
    for(i = 0; frase[i] != '\0'; i++) {

        if( frase[i] != ' ' ) cont_LetrasNaPalavra++;

        if( frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' ) cont_Vogais++;

        if( frase[i+1] == ' ' || frase[i+1] == '\0' ) { 
            if( (cont_LetrasNaPalavra == cont_Vogais) && (cont_LetrasNaPalavra > 0) ) UmaPalavraTemVogal = 1; 
            cont_LetrasNaPalavra = 0;
            cont_Vogais = 0;
        }
    }

    if(UmaPalavraTemVogal) printf("SIM");
    else printf("NAO");
}

int main() {
    char frase[max]; scanf("%[^\n]s", frase);
    serveComoSenha(frase);
    return 0;
}