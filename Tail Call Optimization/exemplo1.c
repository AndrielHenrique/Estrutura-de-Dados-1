#include <stdlib.h>
#include <stdio.h>

void contador(int a)
{
    if (a == 100000)
        return;
    printf("\n%d", a);
    contador(a + 1);
}

int main()
{
    contador(0);

    return 0;
}