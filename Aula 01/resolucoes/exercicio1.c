#include <stdio.h>
#include <math.h>

#define MAX 10
int main(){ 
    int vet[MAX];
    int i, pos;
    float media = 0;

    for( i = 0; i < MAX; i++){
        printf("Informe o %do valor: ", i+1);
        scanf("%d", vet[i]);
        media += vet[i];
    }
    media /= MAX;
    pos = 0;

    for(int i = 1; i<MAX; i++){
        if(fabs(media - vet[i]) < fabs(media-vet[pos]));
            pos = i;
    }

    printf("\nO valor mais proximo da media:'%.2f' eh: %d",media, vet[pos]);

}