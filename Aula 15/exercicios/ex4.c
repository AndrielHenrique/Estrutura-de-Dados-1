// 4) Implemente uma lista que leia N
// elementos em ordem crescente. Em
// seguida, inverta essa lista usando qualquer
// estrutura auxiliar.

#include <stdlib.h>
#include <stdio.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} Lista;

typedef struct pilha
{
    int info;
    struct pilha *prox;
} Pilha;
Lista *insere(Lista *l, int i)
{
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;

    return novo;
}
Lista *insereListaCresc(Lista *l, int v)
{
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = l;
    if (l == NULL || v < l->info)
    {
        novo->prox = l;
        return novo;
    }
    Lista *atual = l;

    while (atual->prox != NULL && atual->prox->info < v)
    {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    return l;
}

void desalocar(Lista *l)
{
    if (l != NULL)
    {
        desalocar(l->prox);
        free(l);
    }
}
void push(Pilha **p, int v)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->info = v;
    novo->prox = *p;
    *p = novo;
}

void percorrerRec(Lista *l, Pilha **p)
{
    if (l != NULL)
    {
        push(p, l->info);
        percorrerRec(l->prox, p);
    }
}
void imprimirRec(Lista *l)
{
    if (l != NULL)
    {
        printf("Lista:  %d\n", l->info);
        imprimirRec(l->prox);
    }
}

int pop(Pilha **p)
{
    int v;
    Pilha *aux;
    if ((*p) == NULL)
    {
        printf("Pilha vazia!\n");
        exit(1);
    }
    aux = *p;
    v = (*p)->info;
    *p = (*p)->prox;
    free(aux);
    return v;
}
int pilhaVazia(Pilha *p)
{
    return p == NULL ? 1 : 0;
}
int numeros()
{
    int v;

    scanf("%d", &v);
    return v;
}
int main()
{
    Lista *l = NULL;
    Pilha *p = NULL;
    Pilha *p2 = NULL;
    int v, i, n = 0;
    printf("Ate quantos elementos vc quer inserir? \n");
    scanf("%d", &n);
    printf("Agora informe os numeros ate %d\n", n);
    for (i = 0; i < n; i++)
    {
        v = numeros();
        l = insereListaCresc(l, v);
    }
    printf("\nLista preenchida: \n");
    imprimirRec(l);
    percorrerRec(l, &p);
    desalocar(l);
    l = NULL;

    while (!(pilhaVazia(p)))
    {
        v = pop(&p);
        push(&p2, v);
    }
    while (!pilhaVazia(p2))
    {
        v = pop(&p2);
        l = insere(l, v);
    }
    printf("Nova Lista invertida:  \n");
    imprimirRec(l);

    desalocar(l);
    l = NULL;
    return 0;
}