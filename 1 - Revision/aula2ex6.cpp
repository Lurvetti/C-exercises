/*

6. Dados dois números naturais m e n e duas sequências ordenadas com m e n números inteiros, 
obter uma única sequência ordenada contendo todos os elementos das sequências originais sem repetição.
Sugestão: Imagine uma situação real, por exemplo, dois fichários de uma biblioteca.
Exemplo: 
Sequência 1:  1, 1, 2, 3, 4, 8, 9
Sequência 2:  1, 3, 5, 7, 10
Sequência gerada (sem repetição): 1, 2, 3, 4, 5, 7, 8, 9, 10

*/

#include<stdio.h>

int main (){
	
	int m, n, cont1, cont2;
	
	printf("Length of first sequence: ");
	scanf("%d" , &m);
	printf("Length of second sequence: ");
	scanf("%d" , &n);
	
	int sq1[m];
	int sq2[n];
	int final[m+n];
	int aux;	
	
	//getting m, n and values
	for (cont1 = 0; cont1 < m; cont1++){
		printf("Enter element in first sequence: ");
		scanf("%d", &sq1[cont1]);
	}
	printf("\n");
	for (cont2 = 0; cont2 < n; cont2++){
		printf("Enter element in second sequence: ");
		scanf("%d", &sq2[cont2]);
	}
	
	//updating final with all elements
	for(cont1 = 0; cont1 < m; cont1++){
		final[cont1] = sq1[cont1];
	}
	for (cont1 = 0, cont2 = m; cont1 < (m+n); cont1++, cont2++){
		final[cont2] = sq2[cont1];
	}
	
	cont2 = 0;
	//sorting  values
	do{
		for(cont1 = 0; cont1 < m+n-1; cont1++){
			if(final[cont1] > final[cont1+1]){
				aux = final[cont1+1];
				final[cont1+1] = final[cont1];
				final[cont1] = aux;					
			}
		}
		cont2++;
	}while(cont2 <= m+n);

	//unique members
	printf("\nUnique ordered sequence: ");
	for(cont1 = 0; cont1 < m+n; cont1++){
		while(final[cont1] == final[cont1+1]){
			cont1++;
		}
		printf("%d " , final[cont1]);
	}
	
	return 0;
}
