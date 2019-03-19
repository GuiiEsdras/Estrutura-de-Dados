#include <stdio.h>
#include <ctype.h>

#define MAX 12

int main()
{
    char O; scanf("%c", &O); O = toupper(O);
    int lin, col, cont=0;
    double soma = 0, media = 0, M[MAX][MAX];

    for( lin = 0; lin < MAX; lin++)
    {
        for( col = 0; col < MAX; col++)
        {
            scanf("%lf", &M[lin][col]);

            if( col > lin )
            {
                soma += M[lin][col];
                cont++;
            }
        }
    }

    if( O == 'S' ) {
        printf("%.1lf\n", soma);
    }
    else if( O == 'M' ) {
        media = soma / cont;
        printf("%.1lf\n", media);
    }

    return 0;
}
