/*Faça uma função que receba um número N
qualquer do usuário e imprima os N primeiros
números de Fibonacci.*/

#include <stdlib.h>
#include <stdio.h>

void seqFib(int n)
{
    int atual = 0;
    int ant = 1;
    int prox = 0;
    for (int i = 0; i <= n; i++)
    {
        printf("\n%d", atual);
        prox = ant + atual;
        ant = atual;
        atual = prox;
    }
}

int main()
{
    int n = 0;
    printf("Informe n: ");
    scanf("%d", &n);
    seqFib(n);
}