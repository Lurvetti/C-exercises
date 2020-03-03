/*

2. Dado um número natural na base binária, transformá-lo para a base decimal.
Exemplo: Dado 10010 a saída será 18, pois 1. 2^4 + 0. 2^3 + 0. 2^2 + 1. 2^1 + 0. 2^0 = 18

*/

#include <stdio.h>
#include <math.h>

int main(){
	int bin = 0, cont = 0, n = 0, final = 0;
	
	printf("Enter binary number: ");
	scanf("%d", &bin);
	
	while(bin > 0){
		n = bin % 10;
		printf("%d ", n);
		
		if(n == 1){
			final = final + pow(2, cont);
		}
		
		cont++;
		bin = bin/10;
	}
	printf("Final = %d", final);
	
	return 0;	
}
