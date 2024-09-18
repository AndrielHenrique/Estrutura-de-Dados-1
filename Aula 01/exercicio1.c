/*1) Faça um programa que leia um vetor de 10 posições
de inteiros. Após a leitura, defina qual é o valor do
vetor mais próximo da média dos valores do vetor.*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int somatorio = 0, pos = 0;
    float media = 0;
    int vetor[10] = {10, 11, 20, 21, 30, 31, 40, 41, 0, 1};

    for (int i = 0; i < 10; i++)
    {
        printf("Somando: Somatorio %d + numero no vetor atual %d\n", somatorio, vetor[i]);
        somatorio += vetor[i];
        printf("Deu: %d\n", somatorio);
    }
    media = (float)somatorio / 10;
    printf("Media calculada = Somatorio: %d / 10 =  %.2f\n", somatorio, media);
    for (int i = 1; i < 10; i++)
    {

        if (fabs(vetor[i] - media) < fabs(vetor[pos] - media))
            pos = i;
    }

    printf("O valor mais proximo da media  %.2f eh: %d\n", media, vetor[pos]);
}