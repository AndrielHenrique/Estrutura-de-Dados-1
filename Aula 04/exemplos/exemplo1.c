#include <stdio.h>
#include <stdlib.h>

int main (){
    int n = 10;
    int *p;
    p= &n;

    printf("Valor na memoria: %d\n", *p);
    printf("Endereco de memoria %p\n", p);

    *p = 5;

    printf("Valor de n: %d", n);

    return 0;
    
}