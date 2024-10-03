/* 1- Escreva uma função que recebe um inteiro
positivo m e escreve na tela todos os números
primos entre 0 e m*/

#include <stdio.h>
#include <stdlib.h>

int primosM(int m)
{
    int i;

    if (m <= 2)
        return 0;

    i = 2;
    while (i < (m / 2 + 1))
    {
        if (m % i == 0)
        {
            return 0;
        }
        i++;
    }

    return 1;
}

void lerPrimos(int m)
{
    int i;
    for (i = 2; i < m; i++)
    {
        if (primosM(i))
            printf(" %d ", i);
    }
}

int main()
{
    int m;
    printf("Informe m: ");
    scanf("%d", &m);

    if (m > 0)
    {
        printf("Numeros primos entre 0 e %d: ", m);
        lerPrimos(m);
    }
}