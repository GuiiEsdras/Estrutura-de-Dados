#include <stdio.h>
#include <stdlib.h>

int main() {
    int turma = 1, maiormed = 0, N; scanf("%d", &N);

    while( N != 0) {
        int cod[N], med[N];
        int i;

        for( i = 0; i < N; i++ ) {
            scanf("%d%d", &cod[i], &med[i]);
        }

        maiormed = 0;
        for( i = 0; i < N; i++ ) {
            if( med[i] >= maiormed ) maiormed = med[i];
        }

        printf("Turma %d\n", turma);
        for( i = 0; i < N; i++ ) {
            if( med[i] == maiormed ) printf("%d ", cod[i]);
        }

        printf("\n\n");
        turma++;
        scanf("%d", &N);
    }

    return 0;
}
