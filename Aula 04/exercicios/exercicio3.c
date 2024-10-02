/*Faça uma função que receba, por referência, dois
parâmetros inteiros a e b que, ao final da função o
maior valor entre a e b deverá estar armazenado em a
e o menor em b no main.*/

#include <stdlib.h>
#include <stdio.h>

void ordenar(int *x, int *y){ // x-> a, y ->b
    if( *y > *x){   //se (b->a)
        int aux = *y;   //aux = b;
        *y = *x;        //b = a;
        *x = aux;       //a = aux;
    }
    
}
int main(){
    int a, b;

    printf("Informe a: ");
    scanf("%d", &a);
    printf("Informe b: ");
    scanf("%d", &b);

    printf("\na = %d | b = %d", a,b);
    ordenar(&a, &b);
    printf("\na = %d | b = %d", a,b);
}