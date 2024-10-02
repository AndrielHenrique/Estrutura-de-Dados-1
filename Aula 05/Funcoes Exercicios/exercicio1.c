/* 1- Escreva uma função que recebe um inteiro
positivo m e escreve na tela todos os números
primos entre 0 e m*/

#include <stdio.h>
#include <stdlib.h>


void primosM(m){
    int i;
    
    for(i = 0; i< m/(2+1); i++){
        if(m % i == 0)
            return 0;
        else{
            printf(" %d ", i);
        }
    }
}

int main(){
    int m;
    printf("Informe m: ");
    scanf("%d", &m);

    if(m>0){
        printf("Numeros primos entre 0 e %d,", m);
        primosM(m);
    }
    
}