/*Escreva uma função que imprima o seguinte menu e,
de acordo com a opção escolhida, execute o exercício
escolhido. O menu deve ser apresentado após a
finalização do exercício escolhido:
1. Exercício 1: Primos ate m
2. Exercício 2: Área do quadrado
3. Exercício 3: Soma de 1 a n
4. Exercício 4: Múltiplos de 5
5. Sair*/

#include <stdlib.h>
#include <stdio.h>

int primosM(int m)
{
    int i;

    if (m <= 1)
        return 0;

    i = 2;
    while (i < (m / 2 + 1))
    {
        if (m % i == 0)
        {
            return 0;
        }
        i++;
    }

    return 1;
}

void lerPrimos(int m)
{
    int i;
    for (i = 2; i <= m; i++)
    {
        if (primosM(i))
            printf(" %d ", i);
    }
}

int areaQuadrado(int lado)
{
    return lado * lado;
}

int somaN(int n)
{
    int i, soma = 0;
    for (i = 0; i <= n; i++)
    {
        soma += i;
        printf("\nSomando +%d = Deu: %d", i, soma);
    }
    return soma;
}

void multiplos(int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        if (i % 5 == 0)
        {
            printf(" %d ", i);
        }
    }
}

void menu()
{
    int op, m, lado, n;
    do
    {
        printf("\n\n*Menu*\n\n1. Exercicio 1: Primos ate m\n2. Exercicio 2: Area do quadrado\n3. Exercicio 3: Soma de 1 a n\n4. Exercicio 4: Multiplos de 5\n5. Sair\nEscolha uma opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nExercicio 1: Primos ate m");
            printf("\nInforme m: ");
            scanf("%d", &m);
            if (m > 0)
            {
                printf("\nNumeros primos entre 0 e %d: ", m);
                lerPrimos(m);
            }
            else
                printf("\nM tem que ser positivo e maior que zero\n");
            break;
        case 2:
            printf("\nExercicio 2: Area do quadrado");
            printf("\nInforme o lado do quadrado: ");
            scanf("%d", &lado);
            if (lado > 0)
                printf("A area do quadrado eh: %d", areaQuadrado(lado));
            else
                printf("\nInforme o lado positivo e maior que zero\n");
            break;
        case 3:
            printf("\nExercicio 3: Soma de 1 a n");
            printf("\nInforme N: ");
            scanf("%d", &n);
            if (n > 0)
                printf("\nA soma dos N primeiros inteiros positivos deu: %d", somaN(n));
            else
                printf("\nN tem que ser positivo e maior que zero\n");
            break;
        case 4:
            printf("\nExercicio 4: Multiplos de 5");
            printf("\nInforme N: ");
            scanf("%d", &n);
            if (n > 0)
            {
                printf("\nMultiplos de 5 entre 0 e %d: ", n);
                multiplos(n);
            }
            else
                printf("\nN tem que ser positivo e maior que zero\n");
            break;
        case 5:
            printf("Saindo");
            break;
        default:
            printf("informe um valor valido de 1 a 5.");
            break;
        }
    } while (op != 5);
}
int main()
{
    menu();

    return 0;
}