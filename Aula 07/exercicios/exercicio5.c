/*Faça uma função recursiva que receba
um número inteiro positivo N e imprima
todos os números naturais de 0 ate N em
ordem decrescente*/

#include <stdlib.h>
#include <stdio.h>

void NaturaisRec(int n)
{
    if (n == 0)
        return;
    else
    {
        printf("%d ", n);
        NaturaisRec(n - 1);
    }
}

int main()
{
    int n;
    printf("Informe N: ");
    scanf("%d", &n);

    printf("Os numeros naturais ate %d em ordem decrescente\n", n);
    NaturaisRec(n);
    return 0;
}