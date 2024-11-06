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
    float media;
} Aluno;
void cadastrarAluno(int contador, Aluno alunos[MAX])
{
    printf("Informe os dados do novo aluno: \n");
    printf("RA: ");
    scanf("%d", &alunos[contador].ra);
    printf("Nome: ");
    getchar();
    fgets(alunos[contador].nome, sizeof(alunos[contador].nome), stdin);
    printf("Curso: ");
    fgets(alunos[contador].curso, sizeof(alunos[contador].curso), stdin);
    printf("Notas(4): ");
    scanf("%f %f %f %f", &alunos[contador].notas[0], &alunos[contador].notas[1], &alunos[contador].notas[2], &alunos[contador].notas[3]);
    printf("Ano de Inicio: ");
    scanf("%d", &alunos[contador].anoInicio);
    printf("Idade: ");
    scanf("%d", &alunos[contador].idade);

    printf("Cadastrado com sucesso!\n");
}

void listarAlunos(int contador, Aluno aluno[MAX])
{
    for (int i = 0; i < contador; i++)
    {
        printf("\nRA: %d", aluno[i].ra);
        printf("\nNome: %s", aluno[i].nome);
        printf("\nCurso: %s", aluno[i].curso);
        printf("\nNotas: %.2f %.2f %.2f %.2f", aluno[i].notas[0], aluno[i].notas[1], aluno[i].notas[2], aluno[i].notas[3]);
        printf("\nMedia das Notas: %.2f", (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2] + aluno[i].notas[3]) / 4);
        printf("\nAno de Inicio: %d", aluno[i].anoInicio);
        printf("\nIdade: %d", aluno[i].idade);
    }
}

void exibirAluno(int contador, Aluno aluno[MAX])
{
    int ra;
    printf("Informe o RA: ");
    scanf("%d", &ra);

    for (int i = 0; i < contador; i++)
    {
        if (ra == aluno[i].ra)
        {
            printf("\nRA: %d\n", aluno[i].ra);
            printf("Nome: %s\n", aluno[i].nome);
            printf("Curso: %s\n", aluno[i].curso);
            printf("Notas: %.2f %.2f %.2f %.2f\n", aluno[i].notas[0], aluno[i].notas[1], aluno[i].notas[2], aluno[i].notas[3]);
            printf("Media das Notas: %.2f\n", (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2] + aluno[i].notas[3]) / 4);
            printf("Ano de Inicio: %d\n", aluno[i].anoInicio);
            printf("Idade: %d\n", aluno[i].idade);
        }
        else
            printf("RA nao encontrado.\n");
    }
}

void maiorMedia(int contador, Aluno aluno[MAX])
{
    int aux = 0;
    for (int i = 0; i < contador; i++)
    {
        aluno[i].media = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2] + aluno[i].notas[3]) / 4;
        if (aluno[i].media > aluno[aux].media)
        {
            aluno[aux] = aluno[i];
        }
    }
    printf("Aluno com a maior media: ");
    printf("\n\nRA: %d", aluno[aux].ra);
    printf("\nNome: %s", aluno[aux].nome);
    printf("\nCurso: %s", aluno[aux].curso);
    printf("\nNotas: %2f %2f %2f %2f", aluno[aux].notas[0], aluno[aux].notas[1], aluno[aux].notas[2], aluno[aux].notas[3]);
    printf("\nAno inicio: %d", aluno[aux].anoInicio);
    printf("\nIdade: %d", aluno[aux].idade);
    printf("\nMedia do aluno: %.2f", aluno[aux].media);
}

void mediaDasMedias(int contador, Aluno aluno[MAX])
{
    float medias;
    for (int i = 0; i < contador; i++)
    {
        medias += aluno[i].media;
    }
    printf("Media das medias: %.2f", medias / contador);
}
void excluirAlunos(int contador, Aluno aluno[MAX])
{
    int ra, encontrado;
    printf("Informe o RA do aluno para excluir: ");
    scanf("%d", &ra);
    for (int i = 0; i < contador; i++)
    {
        if (ra == aluno[i].ra)
        {
            encontrado = 1;
            for (int j = 0; j < contador - 1; j++)
            {
                aluno[j] = aluno[j + 1];
            }
            printf("Aluno excluido com sucesso!\n");
            break;
        }
    }
    if (!encontrado)
        printf("Nao existe aluno com esse RA!\n");
}
int main()
{
    int op;
    int contador = 0;
    Aluno alunos[MAX];
    do
    {
        printf("Escolha uma opcao\n");
        printf("1 - Cadastrar novo aluno\n");
        printf("2 - Listar todos os alunos\n");
        printf("3 - Buscar aluno pelo RA\n");
        printf("4 - Exibir o aluno com a maior média\n");
        printf("5 - Exibir a média das médias\n");
        printf("6 - Excluir aluno pelo RA\n");
        printf("7 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (contador >= 40)
                printf("A lista esta cheia!\n");
            else
                cadastrarAluno(contador, alunos);
            contador++;
            break;
        case 2:
            if (contador > 0)
                listarAlunos(contador, alunos);
            else
                printf("Turma vazia!\n");
            break;
        case 3:
            if (contador > 0)
                exibirAluno(contador, alunos);
            else
                printf("Turma vazia!\n");
            break;
        case 4:
            if (contador > 0)
                maiorMedia(contador, alunos);
            else
                printf("Turma vazia!\n");
            break;
        case 5:
            if (contador > 0)
                mediaDasMedias(contador, alunos);
            else
                printf("Turma vazia!\n");
            break;
        case 6:
            if (contador > 0)
            {
                excluirAlunos(contador, alunos);
                contador--;
            }
            else
                printf("Turma vazia!\n");
            break;
        case 7:
            printf("Saindo...");
            break;
        default:
            printf("Erro, Informe um numero de 1 a 7!");
            break;
        }
    } while (op != 7);
    return 0;
}