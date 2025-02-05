#include <stdio.h>
#include <stdlib.h>

// Um deque é uma fila de duas pontas, combina as caracteristicas de filas(FIFO)
// e pilhas(LIFO), portanto podemos "simular" tanto uma fila quanto uma pilha.
// Seu funcionamento é utilizando uma lista circular com ponteiro para head.

typedef struct No
{
    int info;
    struct No *ant;
    struct No *next;
} No;

typedef struct
{
    No *head;
} Deque;

Deque *criarDeque()
{
    Deque *d = (Deque *)malloc(sizeof(Deque));
    d->head = (No *)malloc(sizeof(No));
    d->head->next = d->head;
    d->head->ant = d->head;
    return d;
}

int dequeVazio(Deque *d)
{
    return (d->head->next == d->head); // Se o próximo do head for ele mesmo, deque ta vazio
}

No *inserirNo(int v)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->info = v;
    novo->ant = NULL;
    novo->next = NULL;
    return novo;
}

void pushInicio(Deque *d, int v)
{
    No *novo = inserirNo(v);
    if (dequeVazio(d)) // Se estiver vazio, o novo nó será o único elemento
    {
        novo->next = d->head;
        novo->ant = d->head;
        d->head->next = novo;
        d->head->ant = novo;
    }
    else // Caso contrário, insere no início normalmente
    {
        novo->next = d->head->next;
        novo->ant = d->head;
        d->head->next->ant = novo;
        d->head->next = novo;
    }
}

void pushFim(Deque *d, int v)
{
    No *novo = inserirNo(v);
    if (dequeVazio(d))
    {
        novo->next = d->head;
        novo->ant = d->head;
        d->head->next = novo;
        d->head->ant = novo;
    }
    else
    {
        novo->ant = d->head->ant;
        novo->next = d->head;
        d->head->ant->next = novo;
        d->head->ant = novo;
    }
}
int popInicio(Deque *d)
{
    if (dequeVazio(d))
    {
        printf("Deque vazio!\n");
        return -1;
    }
    No *remover = d->head->next;
    int v = remover->info;

    if (remover == d->head->ant) // se tiver 1 elemento, ela vai apontar pro head dnv
    {
        d->head->next = d->head;
        d->head->ant = d->head;
    }
    else
    {
        d->head->next = remover->next;
        remover->next->ant = d->head;
    }
    free(remover);
    return v;
}

int popFim(Deque *d)
{
    if (dequeVazio(d))
    {
        printf("Deque vazio!\n");
        return -1;
    }
    No *remover = d->head->ant;
    int v = remover->info;

    if (remover == d->head->next) // se tiver 1 elemento, ela vai apontar pro head dnv
    {
        d->head->next = d->head;
        d->head->ant = d->head;
    }
    else
    {
        d->head->ant = remover->ant;
        remover->ant->next = d->head;
    }
    free(remover);
    return v;
}

void consultarInicio(Deque *d)
{
    if (dequeVazio(d))
    {
        printf("Deque vazio!\n");
        return;
    }
    printf("Inicio do deque: %d\n", d->head->next->info);
}

void consultarFim(Deque *d)
{
    if (dequeVazio(d))
    {
        printf("Deque vazio!\n");
        return;
    }
    printf("Fim do deque: %d\n", d->head->ant->info);
}

void exibirDeque(Deque *d)
{
    if (dequeVazio(d))
    {
        printf("Deque vazio!\n");
        return;
    }
    No *aux = d->head->next;
    printf("Deque: ");
    while (aux != d->head)
    {
        printf("%d ", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

void liberarDeque(Deque *d)
{
    No *aux = d->head->next;
    while (aux != d->head)
    {
        No *temp = aux;
        aux = aux->next;
        free(temp);
    }
    free(d->head);
    free(d);
}

int menu()
{
    int op;
    printf("\n1 - Inserir no inicio\n");
    printf("2 - Remover do inicio\n");
    printf("3 - Inserir no fim\n");
    printf("4 - Remover do fim\n");
    printf("5 - Consultar inicio\n");
    printf("6 - Consultar fim\n");
    printf("7 - Exibir deque\n");
    printf("8 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    return op;
}

int obterNumero()
{
    int v;
    printf("Informe um valor: ");
    scanf("%d", &v);
    return v;
}

int main()
{
    Deque *d = criarDeque();
    int op, v;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            v = obterNumero();
            pushInicio(d, v);
            printf("%d inserido no inicio!\n", v);
            break;
        case 2:
            v = popInicio(d);
            if (v != -1)
                printf("%d removido do inicio!\n", v);
            break;
        case 3:
            v = obterNumero();
            pushFim(d, v);
            printf("%d inserido no fim!\n", v);
            break;
        case 4:
            v = popFim(d);
            if (v != -1)
                printf("%d removido do fim!\n", v);
            break;
        case 5:
            consultarInicio(d);
            break;
        case 6:
            consultarFim(d);
            break;
        case 7:
            exibirDeque(d);
            break;
        case 8:
            printf("Saindo...\n");
            liberarDeque(d);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (op != 8);

    return 0;
}
