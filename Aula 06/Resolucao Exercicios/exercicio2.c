#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b){
    // if(b == 0)
    //  return a;
    // return mdc(b, a%b);
    return b == 0 ? a : mdc(b,a%b);
}
int main(){
    int a, b;
    printf("Informe o primeiro valor: ");
    scanf("%d", &a);
    printf("Informe o segundo valor: ");
    scanf("%d", &b);

    printf("O mdc de %d e %d eh %d", a,b, a > b ? mdc(a,b) : mdc(b,a));
}