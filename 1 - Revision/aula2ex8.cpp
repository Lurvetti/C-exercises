/*

8. Imprimir as n primeiras linhas do tri�ngulo de Pascal. Voc� pode fazer com uma matriz ou mesmo utilizando um �nico vetor.
Dicas:
a) a primeira coluna sempre cont�m 1.
b) o �ltimo elemento de cada linha sempre � 1.
c) todos os outros elementos podem ser calculados somando-se o de cima com o de cima � esquerda.

1
1   1
1   2   1
1   3   3   1
1   4   6   4   1
1   5 10  10  5   1

*/

#include <stdio.h>

int main(){
	int l = 0;
	int contl= 0 , contc = 0;
	
	printf("Digite o numero de linhas do triangulo de pascal: ");
	scanf("%d", &l);
	
	int triangulo[l][l];
	for (contl = 0; contl < l; contl++){
		for (contc = 0; contc <= contl; contc++){
			if(contc == 0 || contc == contl)
			{
			triangulo[contl][contc] = 1;	
			}
			else{
				triangulo[contl][contc] = triangulo[contl-1][contc-1] + triangulo[contl-1][contc];
			}
			
			printf("%d ", triangulo[contl][contc]);
			
			
		}
		printf("\n");
	}
	
	return 0;
}
