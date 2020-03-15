#include <stdio.h>

int fatorial (int numero) { return numero == 0 ? 1 : numero * fatorial(numero - 1); }

int main() {
    int n=0;
    while(scanf("%d", &n) && n != -1)
        printf("%d\n", fatorial(n));
    
	return 0;
}