#include <stdio.h>

int main(int argc, char *argv[]) {

    // .::Break::. //

    // Verifica se 80 está entre os 20 primeiros múltiplos de 5
    int mult = 0;
    for (int i = 0; i <= 20; i++) {
        mult = 5 * i;
        if (mult == 80) {
            printf("80 está nos primeiros 20 múltiplos de 5! \n 5 x %d = %d\n", i, mult);
            break;
            printf("O loop não atinge esse ponto\n");
        }
    }
    printf("O loop 1 terminou\n");


    // .::Continue::. //

    for (int i = 0; i < 11; i++) {
        if (i == 5) {
            continue; // Ignora tudo o que estiver após nessa rodada do loop
        }
        printf("%d ", i);
    }

    printf("\nO loop 2 terminou!\n");
    return 0;
}