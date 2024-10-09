//Fibonnaci

#include <stdlib.h>
#include <stdio.h>

int fibo_com_rec(int n){
    if(n<3)
        return n-1;
    else    
        return fibo_com_rec(n-1) + fibo_com_rec(n-2);
}

int main(){
    int n;
    printf("Informe n: ");
    scanf("%d", &n);

    fibo_com_rec(n);
}