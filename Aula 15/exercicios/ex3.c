// 3) Implemente uma Lista que leia um fixo N
// de elementos. Em seguida, percorra a lista
// colocando os elementos ímpares em uma
// Fila e os pares em uma Pilha.

#include <stdlib.h>
#include <stdio.h>

struct lista
{
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

struct pilha
{
    int info;
    struct pilha *prox;
};

typedef struct pilha Pilha;

typedef struct No
{
    int info;
    struct No *prox;
} No;

typedef struct fila
{
    No *ini;
    No *fim;
} Fila;

void push(Pilha **p, int v)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->info = v;
    novo->prox = *p;
    *p = novo;
}

void imprimePilha(Pilha *p)
{
    Pilha *q;
    for (q = p; q != NULL; q = q->prox)
        printf("Pilha %d\n ", q->info);
}
int pilhaVazia(Pilha *p)
{
    return p == NULL ? 1 : 0;
}

Fila *cria()
{
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;

    return f;
}
void imprimeFila(Fila *f)
{
    No *q;
    for (q = f->ini; q != NULL; q = q->prox)
        printf("Fila %d\n", q->info);
}

int vaziaFila(Fila *f)
{
    return f->ini == NULL ? 1 : 0;
}

Fila *insereFila(Fila *f, int v)
{
    if (v == 0)
        return f;
    No *p;
    p = (No *)malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (vaziaFila(f) == 0)
        f->fim->prox = p;
    f->fim = p;
    if (f->ini == NULL)
        f->ini = f->fim;
    return f;
}

void libera(Fila *f)
{
    No *q = f->ini;
    No *t;

    while (q != NULL)
    {
        t = q->prox;
        free(q);
        q = t;
    }
    f->ini = NULL;
    f->fim = NULL;
}

Lista *insereLista(Lista *l, int i)
{
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;

    return novo;
}

void imprimerecLista(Lista *l)
{
    if (l != NULL)
    {
        printf("Lista = %d\n", l->info);
        imprimerecLista(l->prox);
    }
}
void percorrerLista(Lista *l, Fila *f, Pilha **p)
{
    if (l != NULL)
    {
        if (l->info % 2 == 0)
            push(p, l->info);
        else
            insereFila(f, l->info);

        percorrerLista(l->prox, f, p);
    }
}

int vaziaLista(Lista *l)
{
    return l == NULL ? 1 : 0;
}
void desalocarLista(Lista *l)
{
    if (l != NULL)
    {
        desalocarLista(l->prox);
        free(l);
    }
}

int numeros()
{
    int v;
    scanf("%d", &v);
    return v;
}
int main()
{
    Fila *f = cria();
    Pilha *p = NULL;
    Lista *l = NULL;

    int fixo = 10, i;

    printf("Informe os numeros ate %d(fixo)\n", fixo);
    for (i = 0; i < fixo; i++)
        l = insereLista(l, numeros());
    printf("Lista preenchida: \n");
    imprimerecLista(l);

    percorrerLista(l, f, &p);
    printf("numeros pares da lista na pilha: \n");
    imprimePilha(p);
    printf("numeros impares da lista na fila: \n");
    imprimeFila(f);

    desalocarLista(l);
    l = NULL;
    return 0;
}