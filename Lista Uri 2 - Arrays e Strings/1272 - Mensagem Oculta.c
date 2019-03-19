#include <stdio.h>
#include <string.h>
#define MAX 51

int main(){

    int i, tam, j, N; scanf("%d", &N);
    char frase[MAX];

    getchar();
    for( i = 0; i < N; ++i )
    {
        gets(frase);
        tam = strlen(frase);

        for( j = 0; j < tam; ++j )
        {
            if( j == 0 && frase[0] != ' ' ) {
                printf("%c", frase[0]);
            }

            else if( frase[j-1] == ' ' && frase[j] != ' ' ) {
                printf("%c", frase[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
