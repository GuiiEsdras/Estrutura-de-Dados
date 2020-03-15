#include <stdio.h>

enum meses {
        JAN=1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ 
};

int main() {
    enum meses mes;
    mes = JAN;
    printf("%d\n", mes);

    int i;
    for (i = JAN; i <= DEZ; i++) {
        printf("%d ", i);
    }
}