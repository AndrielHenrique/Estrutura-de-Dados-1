/*Faça uma função recursiva que permita somar os
elementos de um vetor de inteiros.*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 3

int somarVetorRec(int vetor[], int somatorio, int indice){
    if(indice >= MAX)
        return somatorio;
    somarVetorRec(vetor, somatorio += vetor[indice], indice + 1 );
}
int main(){
    int vetor[MAX];
    for(int i = 0; i < MAX; i++){
        printf("\nInforme o elemento na %da posicao: ", i+1);
        scanf("%d", &vetor[i]);
    }
    printf("Somar os elementos do vetor: %d", somarVetorRec(vetor,0,0));
}