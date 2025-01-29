#include <stdio.h>
#include <stdlib.h>

#define max 5

struct nodetype
{
    int info;
    int next;
};

struct nodetype no[max];

void inserir()
{
    int i;
    for (i = 0; i < max; i++)
    {
        printf("digite o valor: ");
        scanf("%d", &no[i].info);
        no[i].next = i + 1;
    }
    no[max - 1].next = -1;
}
void exibir()
{
    int i;
    for (i = 0; i < max; i++)
        printf("Posicao:%d\t\tValor:%d\n", i, no[i].info);
}

void remover(int v)
{
    int i = 0, j;
    if (v == no[max - 1].info)
    {
        no[max - 1].next = -1;
        no[max - 1].info = -1;
        return;
    }
    while (i < max)
    {
        if (no[i].info == v)
        {
            j = i;
            while (j < max - 1)
            {
                no[j].next = no[j + 1].next;
                no[j].info = no[j + 1].info;
                j++;
            }
            no[max - 1].next = -1;
            no[max - 1].info = 0;
            return;
        }
        i++;
    }
    printf("Valor nao encontrado!\n");
}

int main()
{
    int v;
    exibir();
    inserir();
    exibir();
    printf("Informe o valor pra remover: ");
    scanf("%d", &v);
    remover(v);
    printf("removido\n");
    exibir();

    return 0;
}