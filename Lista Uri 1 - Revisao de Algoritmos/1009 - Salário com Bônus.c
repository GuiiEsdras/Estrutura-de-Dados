#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome_do_vendedor[100];
    double salario, vendas, salario_final;

    scanf("%s", nome_do_vendedor);
    scanf("%lf", &salario );
    scanf("%lf", &vendas );

    salario_final = salario + (0.15 * vendas);

    printf("TOTAL = R$ %.2lf\n", salario_final );

    return 0;
}