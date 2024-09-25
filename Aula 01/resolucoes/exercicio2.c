#include <stdio.h>

#define MAX 10

int main(){

    int vet[MAX];   
    int i, min, max;

    for(i= 0; i<MAX; i++){
        printf("Informe o %do valor: ", i + 1);
        scanf("%d", &vet[i]);
        if(i == 0){
            min = vet[i];
            max = vet[i];
        }
            else if(vetor[i] < min)
                min = vet[i];

            else if(vetor[i] > max)
                max = vet[i];
        }

    printf("\nO menor valor eh: %d", min);
    printf("\nO maior valor eh: %d", max);
    }
    
    