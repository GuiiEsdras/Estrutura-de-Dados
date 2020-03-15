#include <stdio.h>

#define TAM 2001

int main(){

    int N; scanf("%d", &N);
    int lista[TAM] = {0}, i, pos;


    for(; N > 0 ; N--) {
        /* Este for pede ao usu�rio que digite os valores que ser�o printados posteriormente,
         * e ao inv�s de adicionar estes elementos � uma lista, ele simplesmente incrementa +1 � posi��o daquele valor na lista.
         */
        scanf("%d", &pos);
        lista[pos]++;

        }

    for( i = 0; i < TAM; i++ ) {
        /* Com este for � buscado se tem algum incremento na determinada posi��o na lista principal.
         * Ou seja, se o usu�rio digitou algum elemento naquela posi��o.
         * Se sim, o valor da posi��o ser� maior que 0, pois ter� sido incrementado antes.
         * Ent�o, o valor (posi��o) � printado, juntamente com a quantidade de incrementos (vezes digitado)
         */
        if( lista[i] > 0) {

            printf("%d aparece %d vez(es)\n", i, lista[i]);

            }

        }

    return 0;
}
