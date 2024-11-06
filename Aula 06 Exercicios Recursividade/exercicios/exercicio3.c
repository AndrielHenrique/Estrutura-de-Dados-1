/*A multiplicação de dois números inteiros pode ser feita
através de somas sucessivas. Proponha um algoritmo
recursivo Multip(n1,n2) que calcule a multiplicação de
dois inteiros.*/

#include <stdlib.h>
#include <stdio.h>

int Multip(int somatorio, int n1, int n2)
{
    return n2 == 0 ? somatorio : Multip(somatorio += n1, n1, n2 - 1);
}
int main()
{
    int a, b;
    printf("Informe n1: ");
    scanf("%d", &a);
    printf("Informe n2: ");
    scanf("%d", &b);
    printf("A soma sucessiva deu: %d", Multip(0, a, b));
    
}