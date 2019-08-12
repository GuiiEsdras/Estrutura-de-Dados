#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int i;
    float A[MAX];

    for( i = 0; i < MAX; i++) {
        scanf("%f", &A[i]);
    }

    for( i = 0; i < MAX; i++) {
        if( A[i] <= 10 ) {
            printf("A[%d] = %.1f\n", i, A[i]);
        }
    }

    return 0;
}
