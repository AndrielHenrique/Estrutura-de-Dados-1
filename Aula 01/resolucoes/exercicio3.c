#include <stdio.h>

int main(){
    int n = 0, num, min, max;

    printf("Qual a quantidade de valores: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("\nInforme o %do valor da sequencia: ", i+1);
        scanf("%d", &num);

        if( i == 0){
            min = num;
            max = num;
        }
        else if(num< min)
            min = num;
        else if(num > max)
            max = num;
    }
    
    printf("O menor numero da sequencia eh: %d", min);
    printf("\nO maior numero da sequencia eh: %d", max);
}