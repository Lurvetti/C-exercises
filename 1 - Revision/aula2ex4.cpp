/*

4. Dados n e uma sequência de n números inteiros, determinar quantos segmentos de números iguais consecutivos compõem essa sequência.
Exemplo: A seguinte sequência é formada por 5 segmentos de números iguais: 5, 2, 2, 3, 4, 4, 4, 4, 1, 1
Ou seja, contarei assim: <<5>>,<< 2, 2>>,<< 3>>,<< 4, 4, 4, 4>>, <<1, 1>> 
Portanto, tenho 5 grupos.

*/

#include <stdio.h>

int main(){
	int d;
	int cont = 0;
	int ncre = 0, max = 0;
	
	printf("Insert n: ");
	scanf("%d", &d);
	int n[d];
	
	for (cont = 0; cont < d; cont++)
	{
		printf("Insert the vector elements: ");
		scanf("%d", &n[cont]);
	}

	for (cont = 0; cont < d-1;cont++){
		if (n[cont] == n[cont+1]){
			max++;
			while (n[cont] == n[cont+1]){
				cont++;	
			}
		}
	}
	
	printf("There are %d sequences of equal numbers!", max);
	return 0;
}
