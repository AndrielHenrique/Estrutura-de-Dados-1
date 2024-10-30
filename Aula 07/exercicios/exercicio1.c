/*. Crie uma função recursiva que receba um número
inteiro positivo N e calcule o somatório dos números de
1 a N.*/

#include <stdlib.h>
#include <stdio.h>

int somatorioAteN(int somatorio, int n){ 
    return n == 0 ? somatorio : somatorioAteN(somatorio += n , n-1);
}

int main(){
    int n;
    printf("\nInforme N: ");
    scanf("%d", &n);
    
    printf("O somatorio 1 ate %d deu: %d", n, somatorioAteN(0,n));

}