/* 1- Escreva uma função que recebe um inteiro
positivo m e escreve na tela todos os números
primos entre 0 e m*/

#include <stdio.h>
#include <stdlib.h>


int primosM(m){
    int i;
    
    if(m == 1)
        return 0;
    i = 2;
    while(i < (m/(2+1))){
        if(m % i == 0){
            return 0;
            } 
        else{
            printf(" %d ", i);
        }
    }
    return 1;
    
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