/*4- Faça uma função que recebe um número N que, caso
seja positivo, calcule e exiba todos múltiplos de 5 entre
0 e N*/

void multiplos(int n){
    int i;
    for(i = 0; i<=n; i++){
        if( i % 5 == 0){
            printf(" %d ", i);
        }
    }
}
int main(){
    int n = 0;

    printf("Informe N: ");
    scanf("%d", &n);

    if(n>0){
        printf("Multiplos de 5 entre 0 e %d: ", n);
        multiplos(n);
    }
}