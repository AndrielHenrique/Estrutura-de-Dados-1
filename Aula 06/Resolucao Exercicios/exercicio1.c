#include <stdio.h>
#include <stdlib.h>

float potrec(float b, int e){
    return e == 0 ? 1 : b * potrec(b,e-1);
}

int main(){
    float b;
    int e;
    printf("Imforme a base: ");
    scanf("%f", &b);
    printf("Informe o expoente: ");
    scanf("%d", &e);

    printf("%.2f^%d = %.2f",b,e,potrec(b,e)); //b^e
}