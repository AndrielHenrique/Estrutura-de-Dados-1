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
	int ra, disp = 0;
    printf("Informe os dados do novo aluno: \n");
    
    alunos[contador].ra = contador + 1;
    printf("RA:  %d\n", alunos[contador].ra);
//    scanf("%d", &alunos[contador].ra);
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
    	printf("\t********************\n");
        printf("\tRA: %d\n", aluno[i].ra);
        printf("\tNome: %s\n", aluno[i].nome);
        printf("\tCurso: %s", aluno[i].curso);
        printf("\tNotas: %.2f %.2f %.2f %.2f\n", aluno[i].notas[0], aluno[i].notas[1], aluno[i].notas[2], aluno[i].notas[3]);
        printf("\tMedia das Notas: %.2f\n", (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2] + aluno[i].notas[3]) / 4);
        printf("\tAno de Inicio: %d\n", aluno[i].anoInicio);
        printf("\tIdade: %d\n", aluno[i].idade);
        printf("\t********************\n");
    }
}
int menu(){
    int op;
    printf("Escolha uma opcao\n");
    printf("1 - Cadastrar novo aluno\n");
    printf("2 - Listar todos os alunos\n");
    printf("3 - Sair\n");
    scanf("%d", &op);
    return op;
}
int main(){
    int contador = 0;
    int op;
    Aluno alunos[MAX];
    do{
    	op = menu();
        switch(op){
        case 1:
            cadastrarAluno(contador, alunos);
            contador++;
        break;
        case 2:
            if(contador > 0)
                listarAlunos(contador, alunos);
            else
            printf("Turma vazia!\n");
        	break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Informe um valor de 1 a 3");
            break;
        }
    } while(op != 3);
	return 0;
}