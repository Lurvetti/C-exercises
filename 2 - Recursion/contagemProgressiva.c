#include <stdio.h>

void progressivo(int inicio, int fim)
{   if(inicio <= fim)
    {   printf("%d - ", inicio);
        progressivo(inicio+1, fim);
    }
}

int main()
{   progressivo(1, 10);
    return 0;
}