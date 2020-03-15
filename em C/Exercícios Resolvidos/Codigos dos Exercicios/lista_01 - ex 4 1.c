#include <stdio.h>
#include <string.h>

int main() {
    int y, *p, x;
    y = 0;
    p = &y; // p aponta para y
    x = *p; // x recebe o mesmo valor de y (0)
    x = 4;
    (*p)++; // y agora recebe +1 e passa a valer 1
    x--; // x agora decresce -1 e passa a valer 3
    (*p) += x; // y vai receber y + o valor de x (3)
    y = (*p) + 10; // y vai receber o próprio valor +10 (y agora tem 14)
    printf ("y = %d\n", y); // y = 14
    printf ("x = %d\n", x); // x = 3
    printf ("(*p) = %d\n", *p); // como p aponta para y, irá imprimir o mesmo valor de y, ou seja, (*p) = 14
    return 0;
}