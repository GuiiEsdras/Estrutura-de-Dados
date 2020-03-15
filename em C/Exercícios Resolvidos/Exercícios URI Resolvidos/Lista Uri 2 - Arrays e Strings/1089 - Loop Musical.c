#include <stdio.h>

int main(){

    int n, i, v[3], picos, p0, p1;

    while(1)
    {
        scanf("%d", &n);
        if( n == 0 ) break;

        picos = 0;

        scanf("%d", &v[0]);
        scanf("%d", &v[1]);

        if( n == 2 )
        {
             if( v[0] != v[1] ) picos = 2;
        }

        else
        {
             p0 = v[0];
             p1 = v[1];

            for( i = 2; i < n; i++ )
            {
                   scanf("%d", &v[2]);
                   if( ( (v[1] > v[0]) && (v[1] > v[2]) ) || ( (v[1] < v[0]) && (v[1] < v[2]) ) ) ++picos;
                   v[0] = v[1];
                   v[1] = v[2];
             }

            if( (p0 > p1 && p0 > v[2]) || (p0 < p1 && p0 < v[2]) ) ++picos;

            if( (v[2] > v[0] && v[2] > p0) || (v[2] < v[0] && v[2] < p0) ) ++picos;
        }

        printf("%d\n", picos);

    }

    return 0;
}
