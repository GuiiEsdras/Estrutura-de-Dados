#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=5, b=6, c=7, i;
    int v[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    int * pt1, * pt2, * pt3;

    pt1= &a;
    pt2= &b;
    pt3= &c;

    pt1= pt3;
    pt2= pt3;
    *pt1 = *pt2 + *pt3;

    printf("%d %d %d \n", a, b, c);

    pt1= &v[3];
    for (int k=0; k<3; k++) {
        *pt1 = *pt1 + 1000;
        pt1 = pt1 + 2;
    }

    for(i=0; i < 10; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
