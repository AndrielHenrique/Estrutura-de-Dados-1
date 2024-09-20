/*. Faça uma função que receba um número
inteiro e determine se ele é primo ou não.*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int ehPrimo(int n)
{
    if (n < 2)
    {
        printf("%d Nao eh primo", n);
        return 0;
    }
    if (n == 2)
    {
        printf("%d Eh primo", n);
        return 0;
    }
    for (int i = 3; i < n; i += 2)
    {

        if (n % i == 0)
        {
            printf("%d Nao eh primo", n);
            return 0;
        }
    }
    printf("%d eh primo", n);

    return 1;
}
int main()
{
    int n;

    printf("Digite o numero que vc quer ver se eh primo: ");
    scanf("%d", &n);
    ehPrimo(n);
}