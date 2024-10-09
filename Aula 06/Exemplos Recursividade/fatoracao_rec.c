#include <stdlib.h>
#include <stdio.h>

int fato_rec(int n){
    int resp;

    if(n ==1)
        return 1;
    else{
        resp = fato_rec(n-1)*n;
        printf(" %d ", resp);
        return resp;
    }
}

int main(){
    int n;
    printf("Informe n: ");
    scanf("%d", &n);

    fato_rec(n);
}