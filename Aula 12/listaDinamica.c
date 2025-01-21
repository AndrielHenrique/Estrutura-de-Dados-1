#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 40

typedef struct
{
    int ra;
    char nome[50];
    char curso[50];
    float notas[4];
    int anoInicio;
    int idade;
} Aluno;

struct lista
{
    Aluno info;
    struct lista *prox;
};

typedef struct lista Lista;

int menu()
{
    int op;
    printf("\n1 - Cadastrar Aluno ");
    printf("\n2 - Listar todos Alunos ");
    printf("\n3 - Buscar Aluno pelo RA");
    printf("\n4 - Exibir Aluno com maior media");
    printf("\n5 - Exibir media da Turma ");
    printf("\n6 - Excluir Aluno pelo RA");
    printf("\n7 - Sair");
    printf("\nOpcao: ");
    scanf("%d", &op);
    return op;
}

Lista *inicializa()
{
    return NULL;
}
Aluno lerAluno()
{
    Aluno aluno;
    int i;
    printf("\nInforme o RA: ");
    scanf("%d", &aluno.ra);
    getchar(); // fflush(stdin)
    printf("\nInforme o nome: ");
    fgets(aluno.nome, 50, stdin);
    printf("\nInforme a idade: ");
    scanf("%d", &aluno.idade);
    getchar();
    printf("\nInforme o curso: ");
    fgets(aluno.curso, 50, stdin);
    printf("\nInforme o ano de inicio: ");
    scanf("%d", &aluno.anoInicio);
    for (i = 0; i < 4; i++)
    {
        printf("\nInforme a %da nota: ", i + 1);
        scanf("%f", &aluno.notas[i]);
    }

    return aluno;
}
Lista *insere(Lista *l, Aluno i)
{
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;

    if (l == NULL || strcmp(novo->info.nome, l->info.nome) < 0)
    {
        novo->prox = l;
        return novo;
    }
    Lista *atual = l;
    Lista *anterior = NULL;
    while (atual != NULL && strcmp(novo->info.nome, atual->info.nome) > 0)
    {
        anterior = atual;
        atual = atual->prox;
    }
    novo->prox = atual;
    anterior->prox = novo;
    return l;
}
void exibirAluno(Aluno aluno)
{
    printf("\n%d\t%s\t\t%d\t%s\t\t%d\t%.2f\t%.2f\t%.2f\t%.2f,\t", aluno.ra, aluno.nome, aluno.idade, aluno.curso, aluno.anoInicio, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.notas[3]);
}

void imprimirRec(Lista *l)
{
    if (l != NULL)
    {
        exibirAluno(l->info);
        imprimirRec(l->prox);
    }
}

Lista *excluir(Lista *l, int num)
{
    if (l == NULL)
    {
        printf("Nao foi encontrado aluno com esse ra!/n");
        return NULL;
    }
    else if (l->info.ra == num)
    {
        Lista *prox = l->prox;
        free(l);
        printf("Aluno excluido da lista!/n");
        return prox;
    }
    l->prox = excluir(l->prox, num);
    return l;
}

Lista *buscarec(Lista *l, int v)
{
    if (l != NULL)
    {
        if (l->info.ra == v)
            return l;
        else
            return buscarec(l->prox, v);
    }
    return NULL;
}
float mediaAluno(Aluno alunoRa)
{
    int i;
    float soma = 0;
    for (i = 0; i < 4; i++)
        soma += alunoRa.notas[i];
    return soma / 4;
}

void maiorMedia(Lista *l)
{
    float maior = 0;
    char nomeAluno[30];
    while (l != NULL)
    {
        float media = 0;

        for (int i = 0; i < 4; i++)
            media += l->info.notas[i];
        media = media / 4;
        if (media > maior)
        {
            maior = media;
            strcpy(nomeAluno, l->info.nome);
        }

        l = l->prox;
    }
    printf("Aluno com a maior media eh %s", nomeAluno);
    printf("A media dele eh %.2f ", maior);
}

void mediaMedia(Lista *l)
{
    float mediaDasMedias = 0;
    int cont = 0;
    while (l != NULL)
    {
        float media = 0;
        for (int i = 0; i < 4; i++)
        {
            media += l->info.notas[i];
            cont++;
        }
        l = l->prox;
        mediaDasMedias += media;
    }
    printf("Media das Medias da turma %.2f", mediaDasMedias / cont);
}

void cabecalhoAluno()
{
    printf("\nRA\tNOME\t\tIDADE\tCURSO\t\tINICIO\tN1\tN2\tN3\tN4\tMD");
}

int vazia(Lista *l)
{
    return l == NULL ? 1 : 0;
}
void desalocar(Lista *l)
{
    if (l != NULL)
    {
        desalocar(l->prox);
        free(l);
    }
}
int main()
{

    Lista *l;
    l = inicializa();
    Aluno temp;

    int ra;
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            temp = lerAluno();
            if (!buscarec(l, temp.ra))
                l = insere(l, temp);
            else
                printf("JA existe um aluno come esse RA!\nd");
            break;
        case 2:
            if (!vazia(l))
                imprimirRec(l);
            else
                printf("Lista vazia!\n");
            break;
        case 3:
            if (!vazia(l))
            {
                printf("Informe o RA do aluno: \n");
                scanf("%d", &ra);
                Lista *res = buscarec(l, ra);
                if (res != NULL)
                    exibirAluno(res->info);
                else
                    printf("Aluno com ra %d nao encontrado!\n", ra);
            }
            else
                printf("Lista vazia!\n");
            break;
        case 4:
            if (!vazia(l))
                maiorMedia(l);
            else
                printf("Lista vazia!\n");
            break;
        case 5:
            if (!vazia(l))
                mediaMedia(l);
            else
                printf("Lista vazia!\n");
            break;
        case 6:
            if (!vazia(l))
            {
                printf("Informe o RA do aluno: \n");
                scanf("%d", &ra);
                Lista *res = buscarec(l, ra);
                if (res != NULL)
                    excluir(l, ra);
                else
                    printf("Aluno com ra %d nao encontrado!\n", ra);
            }
            else
                printf("Lista vazia!\n");
            break;
        case 7:
        {
            printf("\nSaindo...");
            desalocar(l);
        }
        break;
        default:
            printf("\nInforme uma opcao valida entre 1 a 7!");
            break;
        }
    } while (op != 7);
    return 0;
}