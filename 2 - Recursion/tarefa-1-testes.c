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