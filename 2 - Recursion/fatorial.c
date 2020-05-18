#include <stdio.h>

int fatorial(int n){   
    if(n == 0) return 1;
    else return n * fatorial(n-1);
}

int fatorial_iterativo (int n){
    int i, produto = 1;
    for ( i = 2; i <= n; i++){
        produto *= i;
    }
    return produto;

}

int main(){   
    printf("O fatorial (calc recursivo) de 4 vale %d\n", fatorial(4));
    printf("O fatorial (calc iterativo) de 4 vale %d\n", fatorial_iterativo(4));
    return 0;
}