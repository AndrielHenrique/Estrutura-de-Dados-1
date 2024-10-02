/*3. Escreva uma função que receba um número
inteiro positivo n por parâmetro e retorne a
soma dos n primeiros inteiros positivos.*/


int somaN(int n){
    int i,soma = 0;
    for(i = 0; i<=n; i++){
        printf("\n%dSoma + i:%d = Deu:%d", soma, i, soma += i); 
    }
    return soma;
}
int main(){
    int n;

    printf("Informe n: ");
    scanf("%d", &n);

    printf("\nA soma dos N primeiros inteiros positivos deu: %d", somaN(n));
}