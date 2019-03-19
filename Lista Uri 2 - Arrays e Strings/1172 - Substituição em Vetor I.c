#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main()
{
    int i, X[TAM];

    for( i = 0; i < TAM; i++) {
        scanf("%d", &X[i]);
    }

    for( i = 0; i < TAM; i++) {

        if( X[i] <= 0 ) {
            X[i] = 1;
            printf("X[%d] = %d\n", i, X[i]);
        }

        else {
            printf("X[%d] = %d\n", i, X[i]);
        }
    }

    return 0;
}
