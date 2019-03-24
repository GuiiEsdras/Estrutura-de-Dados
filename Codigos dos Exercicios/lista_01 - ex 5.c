#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int a=5, b=6, c=7;
    int v[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    int * pt1, * pt2, * pt3;

    pt3= &c;

    pt1= pt2;
    pt3= pt2;
    *pt2 = *pt3 + 1000;

    printf("%d %d %d \n", a,b,c);

    pt1= v;
    //pt1 = pt1 + 1; // isto está errado, o correto seria pt1++
    pt1++;
    for (int k=0; k<2; k++) {
        *pt1 = *pt1 / 2;
        //pt1 = pt1 + 4; // isto está errado
    }

    // v[10] = { 0, 5, 20, 30, 40, 25, 60, 70, 80, 90 };
    printf("v[%d] = {", sizeof(v)/4);
    for( int i=0; i<10; i++) {
        printf(" %d,", v[i]);
    } printf(" }");

    return 0;
}