#include <stdlib.h>
#include <stdio.h>

struct pilha
{
    int info;
    struct pilha *prox;
};

typedef struct pilha Pilha;

int menu()
{
    int op;
    printf("\n\n1 - Inserir na Pilha 1\n");
    printf("2 - Transferir um elemento da Pilha 1 para a Pilha 2\n");
    printf("3 - Transferir toda a Pilha 1 para a Pilha 2\n");
    printf("4 - Inserir na Pilha 2\n");
    printf("5 - Transferir um elemento da Pilha 2 para a Pilha 1\n");
    printf("6 - Transferir toda a Pilha 2 para a Pilha 1\n");
    printf("7 - Exibir as duas pilhas (Tente exibir as pilhas lado a lado)\n");
    printf("8 - Remover da Pilha 1\n");
    printf("9 - Remover da Pilha 2\n");
    printf("0 - Sair\n");
    scanf("%d", &op);

    return op;
}
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
void imprimePilha(Pilha *p)
{
    Pilha *q;
    for (q = p; q != NULL; q = q->prox)
        printf("%d\n ", q->info);
}
void imprimirDuasPilha(Pilha *p1, Pilha *p2)
{
    printf("Pilha 1\t\t\t\t\tPilha 2\n");
    printf("-----------------------------------------------------\n");

    while (p1 != NULL || p2 != NULL)
    {
        if (p1 != NULL && p2 != NULL)
        {
            printf("%d\t\t\t\t\t%d\n", p1->info, p2->info);
            p1 = p1->prox;
            p2 = p2->prox;
        }
        else if (p1 != NULL)
        {
            printf("%d\t\t\t\t\t\n", p1->info);
            p1 = p1->prox;
        }
        else
        {
            printf("\t\t\t\t\t%d\n", p2->info);
            p2 = p2->prox;
        }
    }
}
int pilhaVazia(Pilha *p)
{
    return p == NULL ? 1 : 0;
}

int main()
{
    Pilha *p1 = NULL;
    Pilha *p2 = NULL;
    // Lista *l = NULL;
    int op, v;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Informe o valor para inserir: \n");
            scanf("%d", &v);
            push(&p1, v);
            break;
        case 2:
            v = pop(&p1);
            push(&p2, v);
            break;
        case 3:
            do
            {
                v = pop(&p1);
                push(&p2, v);
            } while (!pilhaVazia(p1));

            break;
        case 4:
            printf("Informe o valor para inserir: \n");
            scanf("%d", &v);
            push(&p2, v);
            printf("Pilha 1 trasnferida para a Pilha 2\n");
            break;
        case 5:
            v = pop(&p2);
            push(&p1, v);
            break;
        case 6:
            do
            {
                v = pop(&p2);
                push(&p1, v);
            } while (!pilhaVazia(p2));
            printf("Pilha 2 trasnferida para a Pilha 1\n");
            break;
        case 7:
            imprimirDuasPilha(p1, p2);
            printf("-----------------------------------------------------\n");
            printf("Pilha 1\t\t\t\t\tPilha 2");

            break;
        case 8:
            pop(&p1);
            printf("Removido da Pilha 1!\n");
            break;
        case 9:
            pop(&p2);
            printf("Removido da Pilha 2!\n");
            break;
        case 0:

            break;
        default:
            printf("\nInforme uma opcao valida!\n");
            break;
        }
    } while (op != 0);

    return 0;
}