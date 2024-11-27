#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8

typedef struct
{
    char nome[30];
    char responsavel[30];
    int votos;
} Chapas;

Chapas criarChapa()
{
    Chapas chapa;
    printf("Informe o nome da chapa: ");
    fgets(chapa.nome, 30, stdin);
    printf("Informe o nome do responsavel: ");
    fgets(chapa.responsavel, 30, stdin);

    chapa.votos = 0;

    return chapa;
}

void lerChapa(Chapas chapa[], int pos)
{
    printf("\nNome da chapa: %s", chapa[pos].nome);
    printf("\nNome do responsavel: %s", chapa[pos].responsavel);
}

int main()
{
    int maxChapas = 2, i, voto;
    Chapas chapa[maxChapas];

    printf("=== Cadastro de Chapas ===\n");
    for (i = 0; i < maxChapas; i++)
    {
        printf("\nCadastro da chapa %d\n", i + 1);
        chapa[i] = criarChapa();
    }

    printf("\n=== Votacao ===\n");
    for (i = 0; i < MAX; i++)
    {
        printf("\nChapas disponiveis:\n");
        for (int j = 0; j < maxChapas; j++)
            printf("%d - %s\n", j + 1, chapa[j].nome);

        printf("\nQual chapa voce vai votar? 1 ou 2 \n");
        scanf("%d", &voto);
        if (voto >= 1 && voto <= maxChapas)
            chapa[voto - 1].votos++;
        else
            printf("Vote entre a chapa 1 ou a 2.\n");
    }
    printf("\n=== Resultado ===\n");
    if (chapa[1].votos > chapa[0].votos)
    {
        printf("Chapa 2 foi a campea com %d votos", chapa[1].votos);
    }
    else if (chapa[1].votos == chapa[0].votos)
        printf("Deu empate com %d votos", chapa[0].votos);
    else
        printf("Chapa 1 foi a campea com %d votos", chapa[0].votos);
    return 0;
}