#include <stdlib.h>
#include <stdio.h>

int primo(int n){// 1 se primo ou 0 se nao primo
    int n = 2;
    while(i<n/2+1){
        if(n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

void primosAteM(int n){
    int i;
    printf("\nOs primos de 0 ate %d", n);
    for(i = 2; i<=n;i++){
        if(primo(i))
            printf("%d ", i);
    }
}

float areaQuadrado(float lado){
    return lado*lado;
}

int somatorio(int n){
    int i, soma = 0;
    for(i = 1;i <= n; i++){
        soma += i;
    }
    return soma;
}

void multiplosCinco(int n){
    int i;
    printf("\nMultiplos de 5 ate %d: \n", n);
    for(i = 1; i<=n; i++){
        if(i % 5 == 0)
            printf("%d ", i);
    }
}

int menu(){
    int op;
    printf("\n1-Primos ate m");
    printf("\n2-Area do quadrado");
    printf("\n3-Soma de 1 ate N");
    printf("\n4- Multiplos de 5");
    printf("\n5-Sair");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &op);
    return op;
}



int main(){
    int n, op;
    float m;

    do{
        op = menu();
        switch(op){
            case 1:
                printf("Informe m: ");
                scanf("%d", &n);
                primosAteM(n);
                break;
            case 2:
                printf("\nInforme o lado do quadrado: ");
                scanf("%f", m);
                printf("\nA area do quadrado eh: %.2f",areaQuadrado(m));
                break;
            case 3:
                printf("\nInforme N: ");
                scanf("%d", &n);
                printf("O somatorio ate %d eh = %d", n, somatorio(n));
                break;
            case 4:
                printf("\nInforme N: ");
                scanf("%d", &n);
                multiplosCinco(n);
                break;
            case 5:
                printf("\nAte logo");
                break;
            default:
                printf("\nOPCAO INVALIDA");
                break;
        }
        
    } while(op!=5);
}