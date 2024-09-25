#include <stdio.h>

void fibonacci(int n){
    int i = 0, ult, pen, aux;
    pen = 0;
    ult = 1;
    
    while( ++i <= n){
        if(i < 3)
            printf("%d ", i-1);
        else{
            aux = pen + ult;
            pen = ult;
            ult = aux;
            printf("%d ", ult);
        }
    }
}

int main(){
    int n;
    printf("Informe n: ");
    scanf("%d", &n);

    fibonacci(n);

}