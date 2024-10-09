/*1) Faça um programa que utilize uma função para
efetuar a potenciação de forma recursiva.*/

#include <stdlib.h>
#include <stdio.h>

int pot_rec(int n, int exp)
{
    if (exp == 0)
        return 1;
    else
        return n * pot_rec(n, exp - 1);
}
int main()
{
    int n, exp, res;
    printf("Informe N: \n");
    scanf("%d", &n);
    printf("Informe expoente: \n");
    scanf("%d", &exp);
    res = pot_rec(n, exp);
    printf("%d elevado a %d eh = a %d", n, exp, res);

    return 0;
}