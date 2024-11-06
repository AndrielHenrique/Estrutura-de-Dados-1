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
void cadastrarAluno(int contador, Aluno alunos[MAX])
{
    if (contador >= 40)
        printf("A lista esta cheia!\n");
    else
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
}
void listarAlunos(int contador, Aluno aluno[MAX])
{
    if (contador > 0)
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
    else
        printf("Nao existe nenhum aluno cadastrado!\n");
}
void exibirAluno(int contador, Aluno aluno[MAX])
{
    if (contador > 0)
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
            {
                printf("RA nao encontrado.\n");
            }
        }
    }
    else
        printf("Nao existe nenhum aluno cadastrado!\n");
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
            cadastrarAluno(contador, alunos);
            contador++;
            break;
        case 2:
            listarAlunos(contador, alunos);
            break;
        case 3:

            exibirAluno(contador, alunos);
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

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