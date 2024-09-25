#include <stdio.h>

int ehPrimo(int val){
    int i;

    if(val == 1)
        return 0;

    i = 2;
    
    while(i < (val/2+1)){
        if( val % i++ == 0){
            return 0;
        }
    }
    return 1;
}

int main(){

}