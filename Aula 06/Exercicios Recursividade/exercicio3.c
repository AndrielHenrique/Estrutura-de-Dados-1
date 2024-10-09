/*3) Faça um programa que percorra
recursivamente um vetor de inteiros de
tamanho 10 exibindo seus valores.*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 10

void percorrerVetorRec(int n[], int tamanho, int indice)
{
    if (indice >= tamanho)
        return;
    printf(" %d ", n[indice]);
    return percorrerVetorRec(n, tamanho, indice + 1);
}

int main()
{
    int i;
    int n[MAX];
    for (i = 0; i < MAX; i++)
    {
        printf("\n%do valor: ", i + 1);
        scanf("%d", &n[i]);
    }

    percorrerVetorRec(n, MAX, 0);
    return 0;
}