#include <stdio.h>
#include <string.h>

int palindromo2(char palavra[], int inicio, int fim)
{
    if (inicio >= fim)
        return 1;
    if (palavra[inicio] != palavra[fim])
        return 0;
    return palindromo2(palavra, inicio + 1, fim - 1);
}

void palindromo3(char palavra[])
{
    palavra[strcspn(palavra, "\n")] = '\0';
    if (palindromo2(palavra, 0, strlen(palavra) - 1))
        printf("%s eh um palindromo", palavra);
    else
        printf("%s nao eh um palindromo", palavra);
}

int main()
{
    char palavra[50];
    printf("Informe uma palavra ");
    fgets(palavra, 50, stdin);

    palindromo(palavra);
    printf("\n");
    palindromo3(palavra);
    return 0;
}