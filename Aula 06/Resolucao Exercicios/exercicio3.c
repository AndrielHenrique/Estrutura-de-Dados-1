#include <stdlib.h>
#include <stdio.h>

void perc(int v[], int tam){
    if(tam > 0){
        perc(v[tam-1]);
        printf("%d", v[tam-1]);
    }
}

int main(){

}