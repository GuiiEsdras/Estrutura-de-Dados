#include <stdlib.h>

typedef int Contador; // Define um novo tipo chamado "Contador" que na verdade é apenas uma "renomeação" para o tipo int
typedef int outroContador; // outra definição

// outros exemplos:
typedef double exemplo;
typedef char outroExemplo;

int main(int argc, char *argv[]) {
    Contador i;
    outroContador x = 10;
    for (i = 0; i < x; i++) printf("%d ", i);
    return 0;
}