//1) Faça o teste de mesa para os algoritmos abaixo. Você pode usar o modo de depuração (debug) do ambiente de desenvolvimento Java para lhe ajudar:

//a)
int alg1 (int n)
{	
   if (n == 0) return 2;
   else return 2 * alg1 (n - 1) + 3;
}

/*Suponha que alg1 é invocado p/ n = 4.

RESOLUÇÃO:

n	alg1(n)
4	2 * alg1(3) + 3		(else)
3	2 * alg1(2) + 3		(else)
2	2 * alg1(1) + 3		(else)
1	2 * alg1(0) + 3		(else)
0	2 ( Base de retorno de alg1(n) )		(if)
1	2 * alg1(0) + 3 => 2 * 2 + 3 = 7
2	2 * alg1(1) + 3 => 2 * 7 + 3 = 17
3	2 * alg1(2) + 3 => 2 * 17 + 3 = 37
4	2 * alg1(3) + 3 => 2 * 37 + 3 = 77

*/

//b)
int alg2(int n)
{
   if (n == 0) return 1;
   else return 3 * alg2(n/2) + 1;
}

/*Suponha que alg2 é invocado com n = 10.
n   alg2(n/2)
10  3*alg2(5) + 1 = 121
5   3*alg2(2) + 1 = 40
2   3*alg2(1) + 1 = 13
1   3*alg2(0) + 1 = 4
0   1

Resposta = 121
*/


//c)
int alg3(int n)
{
   if (n <= 0) return 2;
   else return 2 * alg3(n - 2) + 1;
}

/*
Suponha que alg3 é invocado com n = 7.
n   alg3(n-2)
7   alg3(5) = 2*23 + 1 = 47
5   alg3(3) = 2*11 + 1 = 23 
3   alg3(1) = 2*5 + 1 = 11
1   alg3(-1) = 2*2 + 1 = 5
-1  2

Resposta = 47
*/


//d)
int alg4(int n)
{
   if (n <= 0) return 2;
   else return  alg4(n - 1) * alg4(n - 2);
}

/*
Suponha que alg4 foi invocado com n = 4.
n   alg4(n - 1) * alg4(n - 2)
4   alg(3)*alg(2) = 32 * 8 = 256
3   alg(2)*alg(1) = 8 * 4 = 32
2   alg(1) * alg(0) = 4 * 2 = 8
1   alg(0) * alg(-1) = 4
0   2
-1  2

Resposta = 256
*/

//e)
int alg5(int n, int k)
{
   if(n == 0)  return 0;
   else return alg5(n - 1, k) + k;
}

/*
Suponha que alg5 é invocado p/ n = 4 e k = 5.
n	k	alg5(n,k)
4	5	alg5(3, 5) + 5 = 20			(else)	
3	5	alg5(2, 5) + 5 = 15			(else)
2	5	alg5(1, 5) + 5 = 10			(else)
1	5	alg5(0, 5) + 5 = 5			(else)
0	5	0 (BASE, Uhhuuuuuu!!)		(if)

Resposta = 20
*/

//f)
int alg6(int n, int k)
{
   if(n < k)  return 0;
   else return  	alg6(n-k, k) + 1;
}

/*
Suponha que alg6 é invocado p/ n = 32 e k = 5. O que faz esse algoritmo? 
n   k   alg6(n-k, k) + 1
32  5   alg6(27, 5) + 1 = 6
27  5   alg6(22, 5) + 1 = 5
22  5   alg6(18, 5) + 1 = 4
18  5   alg6(13, 5) + 1 = 3
13  5   alg6(8, 5) + 1 = 2
8  5    alg6(3, 5) + 1 = 1
3  5    0 

Resposta = 6. O algoritmo faz a divisão inteira.
*/

//g)
int alg7(int n, int k)
{
   if(n < k)  return 0;
   else return alg7(n / k, k) + 1;
}

/*
Suponha que alg7 é invocado p/ n = 32 e k = 2.
n   k   alg7(n/k, k) + 1
32  2   alg(16, 2) + 1 = 5
16  2   alg(8, 2) + 1 = 4
8  2   alg(4, 2) + 1 = 3
4  2   alg(2, 2) + 1 = 2
2  2   alg(1, 2) + 1 = 1
1  2   0

Resposta = 5. log de n na base k?
*/

//h)
int alg8(int n, int k)
{
   if(n <=  1)  return 0;
   else return alg8(n - 1, k + 1) + n*k;
}

/*
Suponha que alg8 é invocado p/ n = 4 e k = 1.
n   k   alg8(n - 1, k + 1) + n*k
4   1   alg(3, 2) + 4 = 16
3   2   alg(2, 3) + 6 = 12
2   3   alg(1, 4) + 6 = 6
1   4   0

Resposta = 16
*/

/*
2) Crie uma função recursiva que calcule potenciações através de multiplicações sucessivas:

	x^y = x * x * x * x ......* x   --> y vezes
	
	Matematicamente, x^0 = 1  e  x^y = x * x^(y-1)

a) Base: expoente == 0 -> resultado = 1
b) x^(y-1) é mais simples
c) x^y = x * x^(y-1)
*/
float potenciacao(float base, int expoente)
{	if(expoente == 0) return 1.0;
	else return base * potenciacao(base, expoente-1);
}

/*
3) Crie uma função recursiva que calcule multiplicações através de somas sucessivas:

	x*y = x + x + x + x ...... + x   -> y vezes

	Matematicamente, x*0 = 0  e  x*y = x + x*(y-1)

a) Base: y == 0 -> resultado = 0
b) x*(y-1) é mais simples
c)  x*y = x + x*(y-1)

*/
int multiplicação(int x, int y)
{	if(y == 0) return 0;
	else return x + multiplicacao(x, y-1);
}


/*
4) Calcule recursivamente o valor da expressão: 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + ...+ 1/(n-1) + 1/n

a) Base: n==1 -> resultado = 1.0
b) expressão (n-1) é mais simples
c) expressao(n) = expressao(n-1) + 1/n
*/

float expressao(int n){	
    if (n==1) return 1.0; /*denominador não pode ser 0*/
	else return 1.0/n + expressao(n-1);
}

/*
5) Crie uma função recursiva que calcule divisões através de subtrações sucessivas:
	x/y = número de vezes que consigo subtrair y de x (x - y - y - y - y ...... >= 0)
*/

float div_sub(int x, int y){
    if (x < y) return 0;
    else return div_sub(x-y, y) + 1;
}

/*
x   y   div_sub(x-y, y) + 1
25  5   div_sub(20, 5) + 1 = 5
20  5   div_sub(15, 5) + 1 = 4
15  5   div_sub(10, 5) + 1 = 3
10  5   div_sub(5, 5) + 1 = 2
5   5   div_sub(0, 5) + 1 = 1
0   5   0   


*/

/*
6) Ache recursivamente a soma dos números ímpares positivos até n:

1 + 3 + 5 + 7 + 9 + 11 + .... n (n ímpar)
ou
1 + 3 + 5 + 7 + 9 + 11 + .... n-1 (n par)
*/

7) Crie uma função recursiva que calcule logaritmos através de divisões sucessivas:

	logaritmo x na base y = número de vezes que consigo dividir x por y

	Matematicamente,	se x < y  --> resposta = 0
					caso contrário, log x na base y = (log de (x/y) na base y) + 1

8) Crie uma função recursiva que converta um número binário em decimal.
 

9) Crie uma função recursiva que converta um número decimal em binário.
	

10) Crie uma função recursiva que procure um número dentro de um vetor, a partir de um dado índice. Se achar o mesmo, o método retorna o índice onde ele se encontra, senão, retorna -1 (busca linear recursiva).

-> Só para entendermos melhor o problema, a versão interativa (não-recursiva) seria assim:

	int busca(int vet[ ], int N, int indiceInicio, int procurado)
	{	int i;
		for(i=indiceInicio; i < N; i++)
		{	if(procurado == vet[i])
			{	return i;
			}
		}
		return -1;
	}

	Agora vamos pensar na versão recursiva.... 

int buscaRecursiva(int vet[ ], int N, int indiceInicio, int procurado)
	

11) Crie um método recursivo que retorne o maior elemento de um vetor.


12) Crie uma função recursiva para calcular o máximo divisor comum (MDC) entre dois números inteiros, usando o algoritmo de Euclides.


13) Torre de Hanói

"Édouard Lucas teve inspiração de uma lenda para construir o jogo das Torres de Hanói em 1883[1]. Já seu nome foi inspirado na torre símbolo da cidade de Hanói, no Vietnã[2]. Existem várias lendas a respeito da origem do jogo, a mais conhecida diz respeito a um templo Hindu, situado no centro do universo. Diz-se que Fuças supostamente havia criado uma torre com 64 discos de ouro e mais duas estacas equilibradas sobre uma plataforma. Fuças ordenara-lhes que movessem todos os discos de uma estaca para outra segundo as suas instruções. As regras eram simples: apenas um disco poderia ser movido por vez e nunca um disco maior deveria ficar por cima de um disco menor. Segundo a lenda, quando todos os discos fossem transferidos de uma estaca para a outra, o templo desmoronar-se-ia e o mundo desapareceria. Dessa forma criaria-se um novo mundo, o mundo de Hanói." (Wikipedia)
      É possível fazer uma solução recursiva para o problema de um jeito bem simples:

Base da Recursão: resolver o quebra-cabeças com um disco é trivial, bastando fazer um movimento e pronto!
Caso Geral: se sei resolver o quebra-cabeças para N-1 discos fica fácil resolvê-lo para N discos. Transporto N-1 discos para o pino auxiliar (eu disse que sabia resolver para N-1 discos!), transporto o disco maior que sobrou para o pino destino e, finalmente, transporto os N-1 discos do pino auxiliar para o pino destino (novamente eu disse que sabia resolver para N-1 discos!).

      Veja como fica a implementação:

#include<stdio.h>
void hanoi (int n, char origem, char destino, char auxiliar) 
{ 
         if(n==1) printf("Mova o disco do pino %c para o pino %c\n", origem, destino); 
         else{ 
            hanoi(n-1, origem, auxiliar, destino); 
            printf("Mova o disco do pino %c para o pino %c\n", origem, destino);  
            hanoi(n-1, auxiliar, destino, origem); 
         } 
}    
int main () 
{ 
         printf("Resolvendo a Torre de Hanoi para 3 discos:\n"); 
         hanoi(3, 'A', 'C', 'B'); 
                
         printf("Resolvendo a Torre de Hanoi para 4 discos:\n"); 
         hanoi(4, 'A', 'C', 'B');
         return 0;
} 	

