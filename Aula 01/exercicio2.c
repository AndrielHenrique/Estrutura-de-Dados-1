/*2) Faça um programa que leia um vetor de dez posições
de inteiros. Em seguida, informe o menor e maior valor
para o usuário.*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{

    int vetor[10] = {10, 111, 220, 21, 30, 31, 40, 41, 120, 1};
    int menorValor = vetor[0], maiorValor = vetor[0];

    for (int i = 0; i < 10; i++)
    {
        printf("Verificando valor no vetor: %d\n", vetor[i]);
        if (vetor[i] < menorValor)
        {
            menorValor = vetor[i];
        }
        if (vetor[i] > maiorValor)
        {
            maiorValor = vetor[i];
        }
    }

    printf("Menor valor no Vetor: %d\n", menorValor);
    printf("Maior valor no vetor: %d\n", maiorValor);
}