#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome [30];
    int idade;
    float altura;
    float peso;
} Pessoa;

void ler(Pessoa *p){
    fgets(pessoa->nome, 30, stdin);
    scanf("%f", &pessoa.altura);
    scanf("%f", &pessoa.peso);
}

void diff(Pessoa *p1, Pessoa *p2){
    printf("%d", abs(p1.idade - p2.idade));
}

int main(){

    Pessoa* joao;
    Pessoa* jose;

    joao = (Pessoa*) malloc(sizeof(Pessoa));
    jose = (Pessoa*) malloc(sizeof(Pessoa));


    ler(joao);
    ler(jose);
    diff(joao, jose);
    free(joao);
    free(jose);

    return 0;
}