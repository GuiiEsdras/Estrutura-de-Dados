#include <stdio.h>

#define TAM 2001

int main(){

    int N; scanf("%d", &N);
    int lista[TAM] = {0}, i, pos;


    for(; N > 0 ; N--) {
        /* Este for pede ao usuário que digite os valores que serão printados posteriormente,
         * e ao invés de adicionar estes elementos à uma lista, ele simplesmente incrementa +1 à posição daquele valor na lista.
         */
        scanf("%d", &pos);
        lista[pos]++;

        }

    for( i = 0; i < TAM; i++ ) {
        /* Com este for é buscado se tem algum incremento na determinada posição na lista principal.
         * Ou seja, se o usuário digitou algum elemento naquela posição.
         * Se sim, o valor da posição será maior que 0, pois terá sido incrementado antes.
         * Então, o valor (posição) é printado, juntamente com a quantidade de incrementos (vezes digitado)
         */
        if( lista[i] > 0) {

            printf("%d aparece %d vez(es)\n", i, lista[i]);

            }

        }

    return 0;
}
