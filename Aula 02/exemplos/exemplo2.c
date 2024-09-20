/*. Faça uma função que receba um número
inteiro e determine se ele é par ou ímpar.
 A função deverá retornar 1 se for par e 0 se
não for par.*/

#include <stdlib.h>
#include <stdio.h>

int parOuImpar(int n)
{
    if (n == 0)
    {
        printf("0");
        return n;
    }

    else if (n % 2 == 0)
    {
        printf("%d eh par", n);
        return 1;
    }
    else
    {
        printf("%d eh impar", n);
        return 0;
    }
}

int main()
{
    int n;

    printf("Qual numero vc quer ver se eh par ou impar? ");
    scanf("%d", &n);
    parOuImpar(n);
}