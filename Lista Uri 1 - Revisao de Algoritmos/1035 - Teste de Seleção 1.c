#include <stdio.h>

int main (void) {
    int a = 0; scanf("%d", &a);
    int b = 0; scanf("%d", &b);
    int c = 0; scanf("%d", &c);
    int d = 0; scanf("%d", &d);

    if ( b > c && d > a && c + d > a + b && c > 0 && d > 0 && a % 2 == 0 )
    {
        printf("Valores aceitos\n");
    }

    else
    {
        printf("Valores nao aceitos\n");
    }
    
    return 0;
}