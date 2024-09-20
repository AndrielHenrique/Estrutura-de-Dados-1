/*3) Faça um programa que determine o maior e o menor
valor de uma sequência de N valores inteiros
fornecidos pelo usuário*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{

    int n = 0;
    int val = 0;
    int maiorValor = 0, menorValor = 0;

    printf("\nDigite quantos numeros vai ter na sequencia: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nDigite o %do numero da sequencia: ", i + 1);
        scanf("%d", &val);

        if (i == 0)
        {
            menorValor = val;
            maiorValor = val;
        }
        else
        {
            if (val > maiorValor)
                maiorValor = val;
            if (val < menorValor)
                menorValor = val;
        }
    }

    printf("Menor valor eh: %d\n", menorValor);
    printf("Maior valor eh: %d\n", maiorValor);
}