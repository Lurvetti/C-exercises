/*

1. Dizemos que um inteiro positivo n � perfeito se for igual � soma de seus divisores positivos diferentes de n.
Exemplo: 6 � perfeito, pois 1+2+3 = 6. Dado um inteiro positivo n, verificar se n � perfeito

*/

#include <stdio.h>

int main(){
	
	int n;
	int sum = 0;
	int cont;
	
	printf("Enter n to check if its perfect or not: ");
	scanf("%d", &n);
	
	for(cont = 1; cont <= n/2; cont++){
		if(n%cont == 0){
			sum = sum + cont;
		}
	}
	
	
	if (sum == n){
		printf("%d is a perfect number!", n);
	}else{
		printf("%d is not a perfect number!", n);
	}
	
	return 0;
}
