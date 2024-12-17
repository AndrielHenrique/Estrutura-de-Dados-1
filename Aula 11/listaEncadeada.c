#include <stdlib.h>
#include <stdio.h>

struct lista
{
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

Lista *inicializa(void)
{
    return NULL;
}

Lista *insere(Lista *l, int i)
{
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;

    return novo;
}

void imprime(Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
        printf("Info = %d\n", p->info);
}

void imprimerec(Lista *l)
{
    if (l != NULL)
    {
        printf("info = %d\n", l->info);
        imprimerec(l->prox);
    }
}

Lista *busca(Lista *l, int v)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
        if (p->info == v)
            return p;
    return NULL;
}

Lista *buscarec(Lista *l, int v)
{
    if (l != NULL)
    {
        if (l->info == v)
        {
            return l;
        }
        else
            return buscarec(l->prox, v);
    }
    return NULL;
}

Lista *excluir(Lista *l, int num)
{
    if (l == NULL)
    {
        printf("\nNao foi encontrado o numero.");
        return NULL;
    }
    if (l->info == num)
    {
        Lista *prox = l->prox;
        free(l);
        printf("Numero excluido da lista!");
        return prox;
    }
    l->prox = excluir(l->prox, num);

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
int vazia(Lista *l)
{
    return l == NULL ? 1 : 0;
}

int main()
{
    Lista *l;
    l = inicializa();
    int op, num;
    do
    {
        printf("\n1-Inserir\n2-Imprimir\n3-Buscar\n4-Excluir\n5-Sair\nEscolha uma opcao: \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Informe um numero pra inserir: \n");
            scanf("%d", &num);
            if (buscarec(l, num) == NULL)
                l = insere(l, num);
            else
                printf("Ja existe um numero com esse valor na lista!\n");
            break;
        case 2:
            if (!vazia(l))
            {
                printf("Imprimindo a lista \n");
                imprime(l);
            }
            else
                printf("Lista vazia");
            break;
        case 3:
            if (!vazia(l))
            {
                printf("Informe um numero pra buscar: \n");
                scanf("%d", &num);
                Lista *res = buscarec(l, num);
                if (res != NULL)
                    printf("%d encontrado na lista.", res->info);
                else
                    printf("Numero nao encontrado");
            }
            else
                printf("Lista vazia");
            break;
        case 4:
            if (!vazia(l))
            {
                printf("Informe um numero pra excluir: \n");
                scanf("%d", &num);
                l = excluir(l, num);
            }
            else
                printf("Lista vazia\n");
            break;
        case 5:
            printf("saindo...\n");
            desalocar(l);
            break;
        default:
            break;
        }
    } while (op != 5);
    return 0;
}