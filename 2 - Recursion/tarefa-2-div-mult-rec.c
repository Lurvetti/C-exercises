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