#include <stdio.h>

void recursivo(int n)
{   if(n > 0)
    {   printf("%d - ", n);
        recursivo(n-1);
    }
}

int main()
{   recursivo(10);
    return 0;
}