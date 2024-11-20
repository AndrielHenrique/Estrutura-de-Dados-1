/*Adapte o exercício da aula 07 de forma que, ao
iniciar o programa, o usuário tenha que informar
o número máximo de alunos. Com o número
máximo, faça a alocação dinâmica do vetor que
antes era fixo em 40*/

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int ra;
    char nome[50];
    char curso[50];
    float notas[4];
    int anoInicio;
    int idade;
} Aluno;

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

float mediaAluno(Aluno aluno)
{
    int i;
    float soma = 0;
    for (i = 0; i < 4; i++)
    {
        soma += aluno.notas[i];
    }
    return soma / 4;
}

void exibirAluno(Aluno aluno)
{
    printf("\n%d\t%s\t\t%d\t%s\t\t%d\t%.2f\t%.2f\t%.2f\t%.2f,\t%.2f", aluno.ra, aluno.nome, aluno.idade, aluno.curso, aluno.anoInicio, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.notas[3], mediaAluno(aluno));
}

void cabecalhoAluno()
{
    printf("\nRA\tNOME\t\tIDADE\tCURSO\t\tINICIO\tN1\tN2\tN3\tN4\tMD");
}

void exibirTurma(Aluno turma[], int qtdAlunos)
{
    // int i;
    // cabecalhoAluno();
    // for (i = 0; i < qtdAlunos; i++)
    // {
    //     exibirAluno(turma[i]);
    // }
    if (qtdAlunos == 0)
        return;
    exibirTurma(turma, qtdAlunos - 1);
    cabecalhoAluno();
    exibirAluno(turma[qtdAlunos - 1]);
}

int buscarAlunoRA(Aluno turma[], int qtdAlunos, int ra)
{
    // int i;
    // for (i = 0; i < qtdAlunos; i++)
    // {
    //     if (turma[i].ra == ra)
    //         return i;
    // }
    // return -1;
    if (qtdAlunos == 0)
        return -1;
    if (turma[qtdAlunos - 1].ra == ra)
        return qtdAlunos - 1;
    return buscarAlunoRA(turma, qtdAlunos - 1, ra);
}

int alunoMaiorMedia(Aluno turma[], int qtdAlunos)
{
    if (qtdAlunos == 1) // qtdAlunos -1 como indice
        return 0;
    int indiceAlunoMaiorMedia = alunoMaiorMedia(turma, qtdAlunos - 1);
    if (mediaAluno(turma[qtdAlunos - 1]) > mediaAluno(turma[indiceAlunoMaiorMedia]))
    {
        return qtdAlunos - 1;
    }
    else
        return indiceAlunoMaiorMedia;
}

float mediaDaTurma(Aluno turma[], int qtdAlunos){
    float media = 0;
    int i;
    for(i = 0; i<0; i++)
        media += mediaAluno(turma[i])/qtdAlunos;
    return media;
}

void deletarAluno(Aluno turma[], int qtdAlunos, int posAluno){
    int i;
    for(i = posAluno; i<qtdAlunos;i++)
        turma[i] = turma[i + 1]; //turma[14] = turma[15]
}

int main()
{
    int *tam;
    int tamanho;

    printf("Qual o tamanho da turma?");
    scanf("%d", &tamanho);

    tam = (int *)(malloc(tamanho * sizeof(int)));

    if (tam == NULL)
    {
        printf("Erro de alocacao de memoria.");
        system("pause");
        exit(1);
    }

    Aluno turma[tamanho];
    Aluno temp;
    int qtdAlunos = 0, ra;
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            if (qtdAlunos < tamanho)
            {
                temp = lerAluno();
                turma[qtdAlunos++] = temp;
            }
            else
            {
                printf("\n\nTurma cheia!!");
            }
            break;
        case 2:
            if (qtdAlunos > 0)
                exibirTurma(turma, qtdAlunos);
            else
                printf("\nTurma vazia!!");
            break;
        case 3:
            if (qtdAlunos > 0)
            {
                printf("\nInforme o RA: ");
                scanf("%d", &ra);
                ra = buscarAlunoRA(turma, qtdAlunos, ra);
                if (ra >= 0)
                {
                    cabecalhoAluno();
                    exibirAluno(turma[ra]);
                }
                else
                    printf("\nRA nao encontrado!!");
            }
            else
                printf("\nTurma vazia!!");
            break;
        case 4:
                if(qtdAlunos > 0){
                    cabecalhoAluno();
                    exibirAluno(turma[alunoMaiorMedia(turma, qtdAlunos)]);
                }else
                    printf("\nTurma vazia!!");
                break;
        case 5:
                if(qtdAlunos > 0){
                    printf("\nMedia da turma: %.2f", mediaDaTurma(turma, qtdAlunos));

                }else
                    printf("\nTurma vazia!!");
                break;
        case 6:
                if(qtdAlunos > 0){
                    printf("\nInforme o RA: ");
                    scanf("%d", &ra);
                    int posAluno = buscarAlunoRA(turma, qtdAlunos, ra);
                    if(posAluno >= 0){
                        deletarAluno(turma, qtdAlunos--, posAluno);
                    }else
                        printf("\nRA nao encontrado!!");
                }else
                        printf("\nTurma vazia!!");
                break;
        case 7:
                printf("\nSaindo...");
                break;
        default:   
                printf("\nInforme uma opcao valida entre 1 a 7!");
                break;
        }

    } while (op != 7);
    return 0;
}