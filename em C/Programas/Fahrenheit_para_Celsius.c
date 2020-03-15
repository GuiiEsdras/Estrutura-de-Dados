#include <stdlib.h>

double f_para_c(double graus_f) {
    double graus_c;
    graus_c = (graus_f - 32) / 1.8;
    return graus_c;
}

int main(int argc, char *argv[]) {
    printf("%.2f", f_para_c(32));
    return 0;
}