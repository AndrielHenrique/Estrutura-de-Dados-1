#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[30];
    char destino[30];
    int qtdPassageiros;
} Aviao;

typedef struct No
{
    Aviao info;
    struct No *prox;
} No;

typedef struct
{
    No *ini;
    No *fim;
} Fila;

int menu()
{
    int op;
    printf("1 - Listar o numero de avioes aguardando na fila de decolagem\n");
    printf("2 - Autorizar a decolagem do primeiro aviao da fila\n");
    printf("3 - Adicionar um aviao a fila de espera;\n");
    printf("4 - Listar todos os avioes na fila de espera\n");
    printf("5 - Listar as caracteristicas do primeiro aviao da fila\n");
    printf("6 - Sair\n");
    scanf("%d", &op);
    return op;
}

Aviao lerAviao()
{
    Aviao aviao;
    printf("\nInforme o id do aviao: ");
    scanf("%d", &aviao.id);
    getchar();
    printf("\nInforme o nome da marca do aviao: ");
    fgets(aviao.marca, 30, stdin);
    printf("\nInforme o destino do aviao: ");
    fgets(aviao.destino, 30, stdin);
    printf("\nInforme a quantidade de passageiros: ");
    scanf("%d", &aviao.qtdPassageiros);

    return aviao;
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

Fila *insere(Fila *f, Aviao v)
{
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
        printf("Fila vazia!\n");
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
void imprime(Fila *f)
{
    No *q;
    for (q = f->ini; q != NULL; q = q->prox)
    {
        printf("=============================================\n");
        printf("Id do aviao %d\n", q->info.id);
        printf("Marca do aviao %s\n", q->info.marca);
        printf("Destino do aviao %s\n", q->info.destino);
        printf("Quantidade de passageiros %d\n", q->info.qtdPassageiros);
        printf("=============================================\n");
    }
}
void imprime1(Fila *f)
{
    printf("Caracteristicas do primeiro aviao da fila:\n");
    printf("Id do aviao %d\n", f->ini->info.id);
    printf("Marca do aviao %s\n", f->ini->info.marca);
    printf("Destino do aviao %s\n", f->ini->info.destino);
    printf("Quantidade de passageiros %d\n", f->ini->info.qtdPassageiros);
}
int main()
{
    No *generico = NULL;
    Fila *f = cria();
    Aviao temp;
    int op, qtdAvioes = 0;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            if (qtdAvioes > 0)
                printf("Quantidade de avioes aguardando na fila de decolagem %d\n", qtdAvioes);
            else
                printf("Nao tem nenhum aviao na lista de decoalagem!\n");
            break;
        case 2:
            if (qtdAvioes > 0)
            {
                imprime1(f);
                printf("Autorizado a decolagem!\n");
                generico = retirar(f);
                free(generico);
                qtdAvioes--;
            }
            else
                printf("Nao tem nenhum aviao na lista de decolagem!\n");
            break;
        case 3:
            temp = lerAviao();
            insere(f, temp);
            printf("Novo aviao adicionado na fila de decoalgem!\n");
            qtdAvioes++;
            break;
        case 4:
            if (qtdAvioes > 0)
                imprime(f);
            else
                printf("Nao tem nenhum aviao na lista de decolagem!\n");
            break;
        case 5:
            if (qtdAvioes > 0)
                imprime1(f);
            else
                printf("Nao tem nenhum aviao na lista de decolagem!\n");
            break;
            break;
        case 6:
            printf("saindo...\n");
            libera(f);
            break;
        default:
            printf("Informe uma opcao valida!\n");
            break;
        }
    } while (op != 6);
    return 0;
}