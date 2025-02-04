#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Um deque é uma fila de duas pontas, combina as caracteristicas de filas(FIFO)
// e pilhas(LIFO), portanto podemos "simular" tanto uma fila quanto uma pilha.
// Seu funcionamento é utilizando uma lista duplamente encadeada com ponteiros para o inicio e fim.

typedef struct No
{
    int info;
    struct No *ant;
    struct No *next;
} No;

typedef struct Deque
{
    No *ini; // conhecido como HEAD, mas inicio pra ficar mais facil e igua a uma fila
    No *fim; // conhecido como TAIL, mas fim pra ficar mais facil e igual a uma fila
} Deque;

Deque *criarDeque()
{
    Deque *d = (Deque *)malloc(sizeof(Deque)); // igual a como criar uma fila
    d->ini = NULL;
    d->fim = NULL;
    return d;
}

No *inserirNo(int v)
{
    No *novo = (No *)malloc(sizeof(No));

    novo->info = v;
    novo->ant = NULL;
    novo->next = NULL;

    return novo;
}

int dequeVazio(Deque *d)
{
    return (d->ini == NULL); // se o inicio for null, significa que ta vazio
}

void pushInicio(Deque *d, int v)
{
    No *novo = inserirNo(v);
    if (dequeVazio(d))
        d->ini = d->fim = novo; // se tiver vazia, entra aqui e insere no inicio.
    else
    {
        novo->next = d->ini; // o novo next vai ser o antigo primeiro.
        d->ini->ant = novo;  // o anterior do antigo inicio vai ser o novo
        d->ini = novo;       // o inicio é o novo;
    }
}

void pushFim(Deque *d, int v)
{
    No *novo = inserirNo(v);
    if (dequeVazio(d))
        d->ini = d->fim = novo; // se tiver vazia, ela iguala todos para o valor novo
    else
    {
        novo->ant = d->fim;  // o anterior do novo vai ser o atual fim
        d->fim->next = novo; // o atual fim next vai ser o novo
        d->fim = novo;       // o novo finalmente eh o topo
    }
}
int popInicio(Deque *d)
{
    if (dequeVazio(d))
    {
        printf("Deque vazio!\n");
        return -1;
    }

    No *temp = d->ini;
    int v = temp->info;

    if (d->ini == d->fim) // so tem um numero na lista
        d->ini = d->fim = NULL;
    else
    {
        d->ini = temp->next;
        d->fim->ant = NULL;
    }

    free(temp);

    return v;
}

int popFim(Deque *d)
{
    if (dequeVazio(d))
    {
        printf("Deque vazio!\n");
        return -1;
    }

    No *temp = d->fim;
    int v = temp->info;

    if (d->ini == d->fim) // a fila tem so 1 numero
        d->ini = d->fim = NULL;
    else
    {
        d->fim = temp->ant;  // atualiza o fim para o nó anterir
        d->fim->next = NULL; // o ultimo nao tem proximo
    }

    free(temp);

    return v;
}

void consultarInicio(Deque *d)
{
    if (dequeVazio(d))
    {
        printf("Deque vazio!\n");
        return;
    }
    printf("Consultando no inicio: %d\n", d->ini->info);
}

void consultarFim(Deque *d)
{
    if (dequeVazio(d))
    {
        printf("Deque vazio!\n");
        return;
    }
    printf("Consultando no fim: %d\n", d->fim->info);
}

void liberarDeque(Deque *d) // igual a de uma fila
{
    No *q = d->ini;
    No *t;
    while (q != NULL)
    {
        t = q->next;
        free(q);
        q = t;
    }
    d->ini = NULL;
    d->fim = NULL;
}
int menu()
{
    int op;
    printf("1 - Inserir no inicio\n");
    printf("2 - Remover do Inicio\n");
    printf("3 - Inserir no Fim\n");
    printf("4 - Remover do Fim\n");
    printf("5 - Consultar do inicio\n");
    printf("6 - Consultar do Fim\n");
    printf("7 - Sair!\n");
    scanf("%d", &op);
    return op;
}
int numeros()
{
    int v;
    printf("informe um valor para inserir: \n");
    scanf("%d", &v);
    return v;
}

int main()
{
    Deque *d = criarDeque();
    int op = 0, v;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            v = numeros();
            pushInicio(d, v);
            printf("%d inserido no inicio!\n", v);
            break;
        case 2:
            v = popInicio(d);
            printf("%d retirado no inicio!\n", v);
            break;
        case 3:
            v = numeros();
            pushFim(d, v);
            printf("%d inserido no fim!\n", v);
            break;
        case 4:
            v = popFim(d);
            printf("%d retirado no fim!\n", v);
            break;
        case 5:
            consultarInicio(d);
            break;
        case 6:
            consultarFim(d);
            break;
        case 7:
            printf("saindo!..\n");
            liberarDeque(d);
            break;
        default:
            printf("Informe uma opcao valida!\n");
            break;
        }
    } while (op != 7);

    return 0;
}