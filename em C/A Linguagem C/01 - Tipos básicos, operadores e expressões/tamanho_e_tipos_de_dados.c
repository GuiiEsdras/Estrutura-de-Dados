#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Um char possui %ld bytes\n", sizeof(char));
    printf("Um int possui %ld bytes\n", sizeof(int));
    printf("Um float possui %ld bytes\n", sizeof(float));
    printf("Um double possui %ld bytes\n", sizeof(double));
    printf("Um short int possui %ld bytes\n", sizeof(short int));
    printf("Um long int possui %ld bytes\n", sizeof(long int));
    printf("Um long double possui %ld bytes\n", sizeof(long double));
    return 0;
}