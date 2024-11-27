#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*1. Um problema típico em computação consiste em converter um
número da sua forma decimal para a forma binária. Por exemplo, o
número 12 tem a sua representação binária igual a 1100. A forma
mais simples de fazer isso é dividir o número sucessivamente por
2, onde o resto da i-ésima divisão vai ser o dígito i do número
binário (da direita para a esquerda). Faça um programa utilizando
recursividade criando uma função Dec2Bin(int n) que dado um
número decimal imprima a sua representação binária
corretamente.
Relembrando: 12 / 2 = 6, resto 0 (1º dígito da direita para esquerda), 6 /
2 = 3, resto 0(2º dígito da direita para esquerda), 3 / 2 = 1 resto 1 (3º
dígito da direita para esquerda), 1 / 2 = 0 resto 1 (4º dígito da direita
para esquerda). Resultado: 12 = 1100*/
void Dec2Bin(int n)
{
    if (n == 0)
        return;
    int n2 = n;
    n = n / 2;
    Dec2Bin(n);
    printf("%d", n2 % 2);
}
/*2. Implemente uma função recursiva que
receba um vetor de inteiros e retorne seu
maior valor.*/

int maiorDoVetor(int vetor[], int contador)
{
    if (contador == 1)
        return vetor[0];
    int maior = maiorDoVetor(vetor, contador - 1);
    return (vetor[contador - 1] > maior ? vetor[contador - 1] : maior);
}

/* 3.
 */
typedef struct
{
    char nome[50];
    int notaS;
    int notaE;
} Alunos;

Alunos lerAluno()
{
    Alunos aluno;
    printf("\nInforme o nome do Aluno: ");
    getchar();
    fgets(aluno.nome, 50, stdin);
    printf("\nInforme a nota obtida ao longo do semestre: ");
    scanf("%d", &aluno.notaS);
    printf("\nInforme a nota obtida na avaliacao especial: ");
    scanf("%d", &aluno.notaE);

    return aluno;
}

float mediaAluno(Alunos aluno)
{
    float media = 0;
    media += aluno.notaE + aluno.notaS;
    return media / 2;
}
float mediaMedias(Alunos turma[], int qtdALunos)
{
    float media = 0;
    int i;
    for (i = 0; i < qtdALunos; i++)
        media += mediaAluno(turma[i]) / qtdALunos;
    return media;
}

void exibirAluno(Alunos aluno)
{
    printf("\t\nNome do Aluno %s", aluno.nome);
    printf("\t\nNota do aluno ao longo do semestre: %d", aluno.notaE);
    printf("\t\nNota do aluno na avalicao especial: %d", aluno.notaS);
    printf("\t\nMedia final: %.2f", mediaAluno(aluno));
}

void exibirTurma(Alunos alunos[], int qtdAlunos)
{
    if (qtdAlunos == 0)
        return;
    exibirTurma(alunos, qtdAlunos - 1);
    exibirAluno(alunos[qtdAlunos - 1]);
}

int main()
{
    // Dec2Bin(12);
    // printf("\n");
    // Dec2Bin(8);
    // printf("\n");
    // Dec2Bin(3);

    int vetor[] = {8, 12, 133, 155, 18, 1, 2, 3, 21, 6};
    int tam = 10, op, tamTurma = 10, qtdAlunos = 0;
    Alunos turma[tamTurma];
    Alunos temp;
    printf("%d", maiorDoVetor(vetor, tam));
    do
    {
        printf("\n1, 2, 3 ou 4: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (qtdAlunos <= tamTurma)
            {
                temp = lerAluno();
                turma[qtdAlunos++] = temp;
            }
            else
                printf("\nTurma cheia.");
            break;
        case 2:
            if (qtdAlunos > 0)
                exibirTurma(turma, qtdAlunos);
            else
                printf("\nTurma vazia.");
            break;
        case 3:
            if (qtdAlunos > 0)
                printf("%.2f Media", mediaMedias(turma, qtdAlunos));
            else
                printf("\nTurma vazia.");
            break;
        case 4:
            printf("\nsaindo..");
            break;
        default:
            printf("\n1 a 4");
            break;
        }
    } while (op != 4);

    return 0;
}