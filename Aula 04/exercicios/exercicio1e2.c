/* 1. Faça uma programa usando função, que receba um
valor inteiro n e retorne o fatorial de n.*/

/*  2. Faça um programa usando função, que receba um
valor inteiro n e retorne a soma dos n primeiros termos
da série:
1+ 1/1! + 1/2! + 1/3! + ... + 1/n!
Utilize a função fatorial*/

#include <stdlib.h>
#include <stdio.h>

int fatorial(int n){ //5! = 5.4.3.2.1
    int i, res = 1;
    for(i = 1; i<=n; i++){
        res *= i;
    }
    return res;
}

float serie(int n){
    float resultado = 1;
    int i;

    for(i = 1; i<=n;i++){
        resultado += 1/fatorial(i);
    }
    return resultado;
}

int main(){
    int n;
    printf("Informe n: \n");
    scanf("%d", &n);

    printf("%d! = %d", n, fatorial(n));
    printf("\nResultado da serie: %.2f", serie(n));



}