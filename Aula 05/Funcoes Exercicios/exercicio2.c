/*2 - Escreva uma função que receba um dos lados
de um quadrado e retorne o valor de sua área*/

int areaQuadrado(int lado){
    return lado * lado;
}
int main(){
    int lado,area;
    printf("Informe o lado do quadrado: ");
    scanf("%d", &lado);
    printf("A area do quadrado eh: %d", areaQuadrado(lado));
}