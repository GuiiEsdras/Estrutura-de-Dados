#include <stdio.h>

int main(int argc, char *argv[]) {
    int n, x;

    n = 3;
    x = 0;
    printf("n = %d, x = %d\n", n, x);
    x = n++; // PRIMEIRO atribui valor de n a x e DEPOIS incrementa n em +1
    printf("n = %d, x = %d\n\n", n, x);

    n = 3;
    x = 0;
    printf("n = %d, x = %d\n", n, x);
    x = ++n; // PRIMEIRO incrementa n em +1printf("a / b = %.3f\n", a/b); e DEPOIS atribui valor de n a x
    printf("n = %d, x = %d\n", n, x);

    return 0;
}