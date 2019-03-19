#include <stdio.h>

int main() 
{
	int tempo_gasto = 0; scanf("%d", &tempo_gasto);
	int vel_media = 0; scanf("%d", &vel_media);
	double calc1 = 0;
	double calc2 = 0;

	calc1 = vel_media / 12.0;
	calc2 = calc1 * tempo_gasto;

	printf("%.3lf\n", calc2);

	return 0;
}