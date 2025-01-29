// 2) Implemente uma Pilha que leia N
// números do usuário (o usuário deverá
// informar quantos números quer informar).
// Em seguida, inverta a Pilha inicial em uma
// segunda Pilha.
// Pilhas, Listas ou Filas auxiliares podem ser
// utilizadas.

#include <stdlib.h>
#include <stdio.h>

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

void desalocarPilha(Pilha **p)
{
    if (p != NULL)
    {
        desalocarPilha(&(*p)->prox);
        free(*p);
        *p = NULL;
    }
}

void imprime(Pilha *p)
{
    Pilha *q;
    for (q = p; q != NULL; q = q->prox)
        printf("Imprimindo %d\n", q->info);
}
int menu()
{
    int op;
    printf("1 - Inserir na pilha\n");
    printf("2 - Inverter a pilha inicial em uma segunda\n");
    printf("3 - Sair\n");
    scanf("%d", &op);
    return op;
}
int numeros()
{
    int v;
    scanf("%d", &v);
    return v;
}
int main()
{
    Pilha *p = NULL;
    Pilha *aux = NULL;
    Pilha *p2 = NULL;
    int v, op, i;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Informe quantos numeros vc quer adicionar: \n");
            scanf("%d", &v);
            printf("Agora vamos adicionar os numeros: \n");
            for (i = 0; i < v; i++)
            {
                int atualInsere = numeros();
                printf("\n");
                push(&p, atualInsere);
            }
            printf("Pilha inserida!\n");
            imprime(p);
            break;
        case 2:
            do
            {
                v = pop(&p);
                push(&aux, v);
                push(&p2, v);
            } while (!pilhaVazia(p));
            printf("Pilha invertida! \n");
            imprime(aux);
            printf("\n-----------\nPilha original\n");
            do
            {
                v = pop(&p2);
                push(&p, v);
            } while (!pilhaVazia(p2));
            imprime(p);
            break;
        case 3:
            printf("Saindo... \n");
            desalocarPilha(&p);
            desalocarPilha(&aux);
            break;
        default:
            printf("Informe uma opcao validA!\n");
            break;
        }

    } while (op != 3);
    return 0;
}