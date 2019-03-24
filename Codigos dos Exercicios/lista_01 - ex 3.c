#include <stdio.h>
#include <string.h>

int main() {
    int a=5, b=6, c=7;
    int v[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    int * pt1, * pt2, * pt3;

    pt1= &a; // pt1 aponta para a, *pt1 == 5
    pt2= &b; // pt2 aponta para b, *pt2 == 6
    pt3= &c; // pt3 aponta para c, *pt3 == 7

    pt2= pt1; // pt2 agora aponta para pt1 que apontam ambos para a, *pt1 == 5 e *pt2 == 5
    *pt3 = *pt2 + 2000; // o conteúdo de pt3 (7) vai receber o conteúdo de pt2 (5) + 2000

    // pt3 == c, *pt3 == 2005 (5 + 2000), c == 2005
    printf("%d %d %d \n", a, b, c);

    pt1= &v[8];
    for (int k=0; k<2; k++) {
        *pt1 = *pt1 - 5;
        pt1 = pt1 - 3;
    }

    // v[10] = { 0, 10, 20, 30, 40, 45, 60, 70, 75, 90 };
    printf("v[%d] = {", sizeof(v)/4);
    for( int i=0; i<10; i++) {
        printf(" %d,", v[i]);
    } printf(" }");

    return 0;
}