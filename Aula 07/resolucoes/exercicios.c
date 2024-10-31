#include <stdlib.h>
#include <stdio.h>

//Exercicio 1
int somaAteN(int n){
    return n <= 0 ? 0 : n + somaAteN(n-1);
}

//Exercicio 2
int somaVetor(int vet[], int tam){
    if( tam == 1)
        return vet[tam - 1];
    return vet[tam - 1] + somaVetor(vet, tam-1);
}

//Exercicio 3
int mult(int x, int y){
    if(abs(y) == 0)
        return 0;
    return abs(x) + mult(abs(x) ,abs(y)-1);
}
//Exercicio 4
void print0aN(int n){
    if(n == 0)
        printf("%d", n);
    else{
        print0aN(n - 1);
        printf("%d", n);
    }
}
//Exercicio 5
void printNa0(int n){
    if(n == 0)
        printf("%d", n);
    else{
        printf("%d", n);
        printNa0(n - 1);
    }
}
//Exercicio 6
void exe6(int v[], int tam){
    if( tam > 0){
        exe6(v, tam - 1);
        if(v[tam - 1] % 2 == 0)
          printf("%d\n", v[tam-1]);
    }
}

//Exercicio 7
void exe7(int v[], int tam){
    if(tam > 0){
        if(v[tam - 1] % 2 != 0)
            printf("%d\n", v[tam-1]);
        exe7(v, tam-1);
    }
}
int main(){
    int a = -10;
    int b = -2;

    if((a < 0) ^ (b < 0))
        printf("%d", -1*mult(a,b));
    else    
        printf("%d", mult(a,b));

    return 0;
}
