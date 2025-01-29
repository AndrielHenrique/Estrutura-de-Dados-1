#include <stdlib.h>
#include <stdio.h>

#define NUMNOS 100

int p[NUMNOS];
int spos = 0;
int rpos = 0;

void inserir()
{
    int num;
    printf("Digite um valor inteiro: \n");
    scanf("%d", &num);
    if (spos == NUMNOS)
    {
        printf("Lista cheia!\n");
        return;
    }
    p[spos] = num;
    spos++;
}

void exibir()
{
    int i;
    for (i = rpos; i < spos; i++)
        printf("Posicao: %d\t\tValor:%d\n", i + 1, p[i]);
}

void remover()
{
    if (rpos == spos)
    {
        printf("Lista vazia!\n");
        return;
    }
    rpos++;
}

int main()
{

    inserir();
    inserir();
    inserir();
    inserir();
    exibir();
    printf("Iniciando remocao!\n");
    remover();
    exibir();
}