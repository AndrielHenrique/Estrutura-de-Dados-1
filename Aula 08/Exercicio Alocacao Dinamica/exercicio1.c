// Pesquise como é feita a alocação
// dinâmica de vetores e matrizes, além da
// sua manipulação.

/* Alocação dinâmica é uma maneira
de alocar a memória com o programa
em execução, é feita enquanto o programa
ja esta rodando.
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void alocacaoVetores()
{
    int *p;
    int i, quant_elementos;

    printf("Digite a quantidade e elementos do vetor: ");
    scanf("%d", &quant_elementos);

    p = (int *)(malloc(quant_elementos * sizeof(int)));

    if (p == NULL)
    {
        printf("\nErro de alocacao de memoria");
        system("pause");
        exit(1);
    }
    for (i = 0; i < quant_elementos; i++)
    {
        printf("Digite o numero para o indice [%d] : ", i);
        scanf("%d", &p[i]);
    }

    printf("\n");
    for (i = 0; i < quant_elementos; i++)
    {
        printf("valor armazenado no elemento de indice [%d] = %d\n", i, p[i]);
    }

    printf("\n");

    free(p);
    system("pause");
}
// Para alocar em uma matriz dinamicamente, Utiliza ponteiro para ponteiro, é um vetor de vetores.
void alocacaoMatrizes()
{
    int **mat, i, j;
    mat = malloc(4 * sizeof(int *));

    for (i = 0; i < 4; i++)
        mat[i] = malloc(3 * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
            mat[i][j] = rand() % 100;
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    free(mat);
    system("pause");
}
int main(void)
{
    // alocacaoVetores();
    alocacaoMatrizes();
    return 0;
}
