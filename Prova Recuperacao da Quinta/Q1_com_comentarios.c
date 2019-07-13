#include <stdio.h>
#define max 51

// Como toda string é um ponteiro para o primeiro caractere do vetor de caracteres...
// então dá pra usar 'char*' pra receber um array de char no parametro da função.
int serveComoSenha(char* frase) { 
    int cont_LetrasNaPalavra = 0; // Armazena temporariamente o numero de letras de uma palavra.
    int cont_Vogais = 0; // Armazena temporariamente o numero de vogais de uma palavra.
    int UmaPalavraTemVogal = 0; // Se no final terminar com 1 é porque a frase tem pelo menos uma palavra feita apenas de vogais.

    register int i;
    for(i = 0; frase[i] != '\0'; i++) { // '\0' significa "fim de string", então: Enquanto não for fim de string, rode esse loop...

        if( frase[i] != ' ' ) { // Se nao for um espaço em branco...
            cont_LetrasNaPalavra++; // é uma letra... então incrementa numero de letras nessa palavra.
        }

        if( frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' ) { // Se for uma vogal...
            cont_Vogais++; // incrementa numero de vogais nessa palavra.
        }

        if( frase[i+1] == ' ' || frase[i+1] == '\0' ) { // Se o proximo caractere for um espaço ou fim de frase, a palavra acabou.
            if( (cont_LetrasNaPalavra == cont_Vogais) && cont_LetrasNaPalavra > 0) { 
                // Se a quantidade de letras na palavra for igual a quantidade de vogais contadas...
                // é porque a palavra é feita apenas de vogais.
                UmaPalavraTemVogal = 1; // Isso significa que pelo menos 1 palavra dessa frase é feita apenas de vogais.
            }

            // Já que o proximo caracter é um espaço... 
            // quer dizer que a palavra acabou. Então reseta os contadores para a próxima palavra.
            cont_LetrasNaPalavra = 0;
            cont_Vogais = 0;
        }
    }

    // Se depois que o loop terminar (verificar palavra por palavra da frase)...
    // ...a variável "UmaPalavraTemVogal" for igual a 1, é porque a condição foi atingida.
    if(UmaPalavraTemVogal) printf("SIM"); // Printa SIM se pelo menos uma palavra tiver apenas vogais...
    else printf("NAO"); // Se não, printa NAO.
}

int main() {
    char frase[max]; scanf("%[^\n]s", frase);
    serveComoSenha(frase);
    return 0;
}