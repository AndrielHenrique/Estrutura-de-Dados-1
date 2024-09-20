/*Calculadora
-> Faça uma calculadora com as quatro operações básicas:
soma, subtração, multiplicação e divisão.
-> Caso o usuário tente realizar a divisão por zero, deverá
ser informado que não é possível realizar a divisão.
-> Duas formas de resolver: funções para cada operação ou
uma função com um parâmetro extra com a operação.*/

#include <stdlib.h>
#include <stdio.h>

int n1()
{
    int n = 0;
    printf("Digite o primeiro numero: ");
    scanf("%d", &n);
    return n;
}
int n2()
{
    int n = 0;
    printf("Digite o segundo numero: ");
    scanf("%d", &n);
    return n;
}

void calculadora(int op)
{
    int x = n1(), y = n2();
    switch (op)
    {

    case 1:
        printf("Somando %d + %d = %d", x, y, x + y);
        break;
    case 2:
        printf("Subtraindo %d - %d = %d", x, y, x - y);
        break;
    case 3:
        if (y == 0)
        {
            printf("Nao eh possivel dividir um numero por 0");
            break;
        }
        else
            printf("Dividindo %d / %d = %d", x, y, x / y);
        break;
    case 4:
        printf("Multiplicando %d * %d = %d", x, y, x * y);
        break;
    case 5:
        printf("Saindo");
        break;
    default:
        printf("\nOp invalida, escolha de 1 a 5!");
        break;
    }
}
int main()
{
    int op;
    do
    {
        printf("\nQual calculo vc quer fazer?\n1-Somar\n2-Subtrair\n3-Dividir\n4-Multiplicar\n5- Sair\n ");
        scanf("%d", &op);
        calculadora(op);

    } while (op != 5);

    return 0;
}