#include<stdio.h>
#include<locale.h>

int procurarLinha(int L, int C, int mat[L][C], int proc){
	//aqui você completa ....
	//esta função retorna a linha em que proc aparece na matriz
    int l,c;
    int line;
    
    for(l = 0; l < L; l++){
        for(c = 0; c < C; c++){
            if(mat[l][c] == proc){
                printf("Linha = %d - ", l);
                return l;
            }
        }
    }
}


//Calendário permanente de 1901 a 2092

int A1[28][4], A2[28][4];
int B[28][12]=
	{{4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,6,2,4,0,2,5,1,3,6,1}};
int C[7][6];

int main()
{
	int l,c,x;
	//populando a tabela A1
	x=-3;
	for(c=0;c<4;c++)
		for(l=0;l<28;l++, x++)
			if(x<1) A1[l][c]=-1;
			else if(x<100) A1[l][c]=x;
			else if(x==100) A1[l][c]=0;
			else A1[l][c]=-1;

	//populando a tabela A2
	x=-19;
	for(c=0;c<4;c++)
		for(l=0;l<28;l++, x++)
			if(x<1) A2[l][c]=-1;
			else A2[l][c]=x;
	
	//populando a tabela C
	x=1;
	for(c=0;c<6;c++)
		for(l=0;l<7;l++, x++)
			if(x>37) C[l][c]=-1;
			else C[l][c]=x;

	int dia, mes, ano, resposta, linha;
	setlocale(LC_ALL, "Portuguese");
	printf("\nEntre com uma data no formato DD/MM/AAAA: ");
	scanf("%d/%d/%d", &dia, &mes, &ano);

	if(ano < 1901 || ano > 2092) printf("Erro!! O ano deve ser de 1901 a 2092.\n");

	//aqui você completa ......
    if(ano <= 2000){
        linha = procurarLinha(28, 4, A1, ano % 100);
    }else{
        linha = procurarLinha(28, 4, A2, ano % 100);
    }

    printf("  %d", B[linha][mes - 1] + dia);

    for(c=0; c < 6; c++){
		for(l=0; l < 7; l++){
            if(C[l][c] == B[linha][mes - 1] + dia){
                printf("\nLinha do dia = %d", l);
				printf("\n\nDia da semana:");
                    if(l == 0) printf(" Domingo");
                    if(l == 1) printf(" Segunda-Feira");
                    if(l == 2) printf(" Terca-Feira");
                    if(l == 3) printf(" Quarta-Feira");
                    if(l == 4) printf(" Quinta-Feira");
                    if(l == 5) printf(" Sexta-Feira");
                    if(l == 6) printf(" Sabado");
				printf("\n");
            }
        }
    }
	return 0;
}
