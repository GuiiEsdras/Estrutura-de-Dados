#include <stdio.h>

void decodificaProva(char* cod);

int main() {
    //printf("Insira o codigo: ");
    char codigo[30]; scanf("%s", codigo);
    decodificaProva(codigo);
    return 0;
}

void decodificaProva(char* cod) {
    register int i;
    for( i = 0; cod[i] != '\0'; i++ ) {
        if( cod[i-1] == 'R' && cod[i] >= '0' && cod[i] <= '9' ) {
            printf("%c\n", cod[i]);
        }
    }
}