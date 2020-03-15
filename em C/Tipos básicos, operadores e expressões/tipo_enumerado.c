#include <stdio.h>

enum meses {
        JAN=1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ 
};

int main(int argc, char *argv[]) {
    enum meses mes;
    mes = JAN;
    printf("%d\n", mes);

    enum meses outroMes = FEV;
    if (outroMes == ABR) {
        printf("Niver \\o/");
    }

    int i;
    for (i = JAN; i <= DEZ; i++) {
        printf("%d ", i);
    }
    return 0;
}