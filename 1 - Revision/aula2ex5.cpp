/*

5. Dados n e uma sequência de n números inteiros, determinar o
comprimento de um segmento crescente de comprimento máximo.
Exemplos:
Na sequência 5, 10, 3, <<2, 4, 7, 9>>, 8, 5 o comprimento do segmento crescente máximo é 4.
Na sequência 10, 8, 7, 5, 2 o comprimento de um segmento crescente máximo é 1.

*/

#include <stdio.h>

int main(){
	int d;
	int cont = 0;
	int ncre = 0, max = 0;
	
	printf("Informe o numero de elementos: ");
	scanf("%d", &d);
	int n[d];
	
	for (cont = 0; cont < d; cont++)
	{
		printf("Insira os elementos do vetor: ");
		scanf("%d", &n[cont]);
	}

	for (cont = 0; cont < d-1; cont++)
	{
		if (n[cont] < n[cont+1])
		{
			ncre += 1;	
		}
		else{
			ncre = 0;			
		}
		
		if(ncre >= max)	{
				max = ncre;	
			}
			
		printf("ncre = %d ", ncre);
		printf("max = %d\n", max);
	}
	
	if(max !=0){
		max++;
	}
	
	printf("O maximo segmento crescente tem %d valores ", max);
	return 0;	
}
