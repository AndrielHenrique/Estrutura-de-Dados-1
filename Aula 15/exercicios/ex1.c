// 1) Leia uma Fila de N números diferentes
// de 0. Após a leitura, realize a inversão da
// Fila utilizando uma estrutura auxiliar que
// pode ser uma Lista, uma Pilha ou uma outra
// Fila.

#include <stdlib.h>
#include <stdio.h>
typedef struct No
{
    int info;
    struct No *prox;
} No;

typedef struct
{
    No *ini;
    No *fim;
} Fila;

struct pilha
{
    int info;
    struct pilha *prox;
};

typedef struct pilha Pilha;

void push(Pilha **p, int v)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->info = v;
    novo->prox = *p;
    *p = novo;
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

Fila *cria()
{
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;

    return f;
}

int vazia(Fila *f)
{
    return f->ini == NULL ? 1 : 0;
}

Fila *insere(Fila *f, int v)
{
    if (v == 0)
        return f;
    No *p;
    p = (No *)malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (vazia(f) == 0)
        f->fim->prox = p;
    f->fim = p;
    if (f->ini == NULL)
        f->ini = f->fim;
    return f;
}

No *retirar(Fila *f)
{
    No *no;
    if (vazia(f))
    {
        printf("fila vazia!\n");
        return NULL;
    }
    no = f->ini;
    f->ini = f->ini->prox;
    if (f->ini == NULL)
        f->fim = NULL;

    no->prox = NULL;
    return no;
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
int numeros()
{
    int v = 1;
    scanf("%d", &v);
    return v;
}

int menu()
{
    int op;
    printf("1 - Inserir valores\n");
    printf("2 - Ler valores \n");
    printf("3 - Inversao da Fila\n");
    printf("4 - Sair\n");
    scanf("%d", &op);
    return op;
}
void imprime(Fila *f)
{
    No *q;
    for (q = f->ini; q != NULL; q = q->prox)
        printf("Imprindo %d\n", q->info);
}
int main()
{
    No *generico = NULL;
    Pilha *p = NULL;
    Fila *f = cria();
    int op = 0, v = 1;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Informe os valores para inserir, e 0 para parar de informar!\n");
            do
            {
                v = numeros();
                insere(f, v);
            } while (v != 0);
            break;
        case 2:
            if (!vazia(f))
                imprime(f);
            else
                printf("Fila vazia!\n");
            break;
        case 3:
            if (vazia(f))
                printf("Fila vazia!\n");
            do
            {
                generico = retirar(f);
                push(&p, generico->info);
                free(generico);
            } while (!vazia(f));

            do
            {
                v = pop(&p);
                insere(f, v);
            } while (!pilhaVazia(p));
            printf("inversao da fila com uma pilha auxiliar completa!\n");
            imprime(f);
            break;
        case 4:
            printf("saindo..\n");
            libera(f);
            break;
        default:
            printf("Informe uma opcao valida!\n");
            break;
        }
    } while (op != 4);

    return 0;
}