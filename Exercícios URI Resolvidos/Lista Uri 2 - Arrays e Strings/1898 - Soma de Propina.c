#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 61

int main()
{
    char c1[MAX], c2[MAX], cpf[12], v1[MAX], v2[MAX], soma[MAX];
    double value1, value2, total;
    scanf("%s", c1);
    scanf("%s", c2);

    int i, cont = 0, contv1 = 0, contv2 = 0;

    for( i = 0; c1[i] != '\0'; i++)
    {
        if( ( cont < 11 ) && ( c1[i] >= '0' && c1[i] <= '9') ) {
            cpf[cont] = c1[i];
            cont++;
        }

        else {
            if( c1[i] >= '0' && c1[i] <= '9' || c1[i] == '.' ) {
                v1[contv1] = c1[i];
                contv1++;
            }

            if( v1[contv1-3] == '.')  {
                break;
            }
        }
    }

    for( i = 0; c2[i] != '\0'; i++)
    {
        if( c2[i] >= '0' && c2[i] <= '9' || c2[i] == '.' )
        {
            v2[contv2] = c2[i];
            contv2++;
        }
        if( v2[contv2-3] == '.' ) {
            break;
        }
    }

    printf("cpf ");
    for( i = 0; i < 11; i++ ) {
        printf("%c", cpf[i]);
    } printf("\n");

    value1 = strtod(v1, NULL);
    value2 = strtod(v2, NULL);
    total = value1 + value2;

    sprintf(soma, "%.3lf", total);

    for( i = 0; soma[i+1] != '\0'; i++) {
        printf("%c", soma[i]);
    } printf("\n");

    return 0;
}
