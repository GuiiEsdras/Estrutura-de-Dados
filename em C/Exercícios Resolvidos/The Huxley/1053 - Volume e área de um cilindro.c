#include <stdio.h>

int main (void)
{
    double h; scanf("%lf", &h);
    double r; scanf("%lf", &r);

    double pi = 3.14;

    double v = h * pi * (r*r);
    double a = 2 * pi * (r*r) + 2 * pi * r * h;

    printf("%.2f\n", v);
    printf("%.2f\n", a);

    return 0;
}