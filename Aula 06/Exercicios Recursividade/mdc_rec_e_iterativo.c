/*2) Faça um programa que implemente uma
função iterativa que calcule o máximo divisor
comum (MDC) de dois números e depois faça
também outra função recursiva para o mesmo
caso*/

#include <stdlib.h>
#include <stdio.h>

int maxDivComumIterativa(int a, int b)
{
    int mdc;
    while (b != 0)
    {
        mdc = a % b;
        a = b;
        b = mdc;
    }
    return a;
}

int maxDivComumRecursiva(int a, int b)
{
    int mdc;
    if (b == 0)
        return a;
    return mdc = maxDivComumRecursiva(b, a % b);
}

int main()
{
    int a, b, mdc;
    printf("Informe a: ");
    scanf("%d", &a);
    printf("Informe b: ");
    scanf("%d", &b);

    mdc = maxDivComumIterativa(a, b);
    printf("\nO mdc eh = a %d ", mdc);

    mdc = maxDivComumRecursiva(a, b);
    printf("\nO mdc eh = a %d ", mdc);

    return 0;
}