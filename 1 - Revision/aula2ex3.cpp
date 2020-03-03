/*

3. Dado um número natural na base decimal, transformá-lo para a base binária.
Exemplo: Dado 18 a saída deverá ser 10010.

Dica e explicação da ideia:

 18 |__2__
 0     9  |__2__
<-     1     4   |__2__
      <-     0      2   |__2__
            <-      0      1   |__2__
                   <-      1      0
                          <-

(10010)  == (18)
       2        10

0 x 1      =     0
1 x 10     =    10
0 x 100    =     0
0 x 1000   =     0
1 x 10000  = 10000    +
---------------------
             10010

*/

#include <stdio.h>
#include <math.h>

int main(){
	int dec = 0, cont = 0, bin = 0;
	
	printf("Enter a decimal number: ");
	scanf("%d", &dec);
	
	while (dec != 0){
		bin = bin + ((dec%2) * pow(10,cont));
		dec = dec/2;
		cont++;
		printf("%d ", dec);
			
	}
	printf("\nBinary = %d", bin);
		
	return 0;
}

