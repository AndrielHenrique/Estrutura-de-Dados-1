/*Faça uma função recursiva que receba
um vetor e seu tamanho por parâmetro e
exiba seus valores pares da primeira até
a última posição.*/

#include <stdlib.h>
#include <stdio.h>

int percorrerVet(int vet[], int indice, int tam){
    if(indice >= tam)
        return;
    printf("%d\n", vet[indice]);
    percorrerVet(vet, indice + 1, tam);
}

int main(){
    int tam = 0;
    printf("Informe o tamanho do Vetor: ");
    scanf("%d", &tam);
    int vetor[tam];
    for(int i = 0; i < tam; i++)
    {
        printf("Informe o %do valor vetor: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    percorrerVet(vetor, 0, tam);
    return 0;
}