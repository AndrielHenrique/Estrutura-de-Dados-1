#include <stdlib.h>
#include <stdio.h>

int contador(int a)
{
    if (a == 100000)
        return a;
    printf("\n%d", a);
    return a + contador(a + 1);
}

int main()
{
    contador(0);

    return 0;
}
