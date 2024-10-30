/*Faça uma função recursiva similar à
função do exercício 6, porém que exiba
os valores ímpares do vetor em ordem
inversa.*/

#include <stdlib.h>
#include <stdio.h>

void vetImpar(int vet[], int tam, int indice){
    int impar;
    if(indice >= tam)
      return;
    else{
	    if(vet[indice] % 2 != 0)
	        impar = vet[indice];
	    vetImpar(vet, tam, indice + 1);
	    printf("%d\n", impar);
	}
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

    return 0;
}