#include <stdlib.h>
#include <stdio.h>

/*1. Um problema típico em computação consiste em converter um
número da sua forma decimal para a forma binária. Por exemplo, o
número 12 tem a sua representação binária igual a 1100. A forma
mais simples de fazer isso é dividir o número sucessivamente por
2, onde o resto da i-ésima divisão vai ser o dígito i do número
binário (da direita para a esquerda). Faça um programa utilizando
recursividade criando uma função Dec2Bin(int n) que dado um
número decimal imprima a sua representação binária
corretamente.
Relembrando: 12 / 2 = 6, resto 0 (1º dígito da direita para esquerda), 6 /
2 = 3, resto 0(2º dígito da direita para esquerda), 3 / 2 = 1 resto 1 (3º
dígito da direita para esquerda), 1 / 2 = 0 resto 1 (4º dígito da direita
para esquerda). Resultado: 12 = 1100*/
void Dec2Bin(int n)
{
    if (n == 0)
        return;
    int n2 = n;
    n = n / 2;
    Dec2Bin(n);
    printf("%d", n2 % 2);
}
/*. Implemente uma função recursiva que
receba um vetor de inteiros e retorne seu
maior valor.*/

int maiorDoVetor(int vetor[], int contador)
{
    if (contador == 1)
        return vetor[0];
    int maior = maiorDoVetor(vetor, contador - 1);
    return (vetor[contador - 1] > maior ? vetor[contador - 1] : maior);
}
int main()
{
    // Dec2Bin(12);
    // printf("\n");
    // Dec2Bin(8);
    // printf("\n");
    // Dec2Bin(3);

    int vetor[] = {8, 12, 133, 155, 18, 1, 2, 3, 21, 6};
    int tam = 10;
    // printf("%d", maiorDoVetor(vetor, tam));
    return 0;
}