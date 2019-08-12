#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, N, tam, r, D[61], E[61];
    char pe;

    while( scanf("%d", &N) >= 0) {
        r = 0;

        for( i = 0; i < 61; i++ ) {
            E[i] = 0;
            D[i] = 0;
        }

        while( N-- ) {
        // Enquanto houver botas, ou seja, quando N = 0 ser� false, e o loop acaba.

            scanf("%d %c", &tam, &pe ); // L� tam e p�

            if( pe == 'E' ) { // Se o p� for E=esquerdo
                E[tam]++; // Adiciona +1 na posi��o M (tam)
            }

            else { D[tam]++; }

            if( E[tam] && D[tam] ) {
                E[tam]--;
                D[tam]--;
                r++;
            }
        }
        printf("%d\n", r);
    }

    return 0;
}
