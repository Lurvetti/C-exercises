/*

7. Dadas duas sequências com n números inteiros entre 0 e 9, interpretadas como dois números inteiros de n algarismos, calcular a sequência de números que representa a soma dos dois inteiros.
Exemplo: n = 8,
		1ª sequência		8 2 4 3 4 2 5 1
		2ª sequência		3 3 7 5 2 3 3 7  +
					     -----------------------
					     1 1 6 1 8 6 5 8 8
						 
*/
					     
#include <stdio.h>

int main(){
    int i = 0;
    int soma[9];
    
    int n1[] = {8,2,4,3,4,2,5,1};
    int n2[] = {3,3,7,5,2,3,3,7};
 
    
    for(i = 7; i >= 0; i--)
    {        
        if(n1[i] + n2[i] > 9){
            soma[i+1] = (n1[i] + n2[i]) % 10;
            n1[i-1] += 1;
            if(i==1){
              soma[0] = 1;
              break;
            }
        }
        
        if(n1[i] + n2[i] <= 9){
        soma[i+1] = n1[i] + n2[i];
        }
    }
    
    printf("Soma: ");
    for(i = 0; i<9; i++){
    	printf("%d ", soma[i]);
	}
    return 0; 
}
