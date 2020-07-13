#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct pixel{
	int R, G, B;
} PIXEL;

// read/save images
int** lerImagem(char * nomeArquivo, int *pLinhas, int *pColunas, int *pMaxValor)
{	FILE *fp;
	fp = fopen(nomeArquivo,"r");
	/* Arquivo ASCII, para leitura */
	if(!fp)
	{	printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}

	//leia tipo do arquivo
	char buffer[1001];
	fgets (buffer, 1000, fp); //Primeira linha
	if(strstr(buffer, "P2") == NULL) // o tipo de arquivo eh diferente de P2?
	{	printf( "\nErro no tipo do arquivo\n\n");
		exit(-2);
	}

	//leia comentario
	fgets (buffer, 1000, fp);
	
	//leia dados da imagem
	fscanf(fp, "%d%d%d", pColunas, pLinhas, pMaxValor);
	
	//criando a matriz
	int **mat, i;
	mat = (int **) malloc(*pLinhas * sizeof(int *));
	for(i=0; i< *pLinhas; i++)
		mat[i] = (int *) malloc(*pColunas * sizeof(int));

	int l, c;
	for(l=0; l<*pLinhas; l++)
	{	for(c=0; c<*pColunas; c++)
			fscanf(fp, "%d", &mat[l][c]);
	}
	fclose(fp);
	return mat;
}
PIXEL** lerImagemCol(char * nomeArquivo, int *pLinhas, int *pColunas, int *pMaxValor)
{	FILE *fp;
	fp = fopen(nomeArquivo,"r");
	/* Arquivo ASCII, para leitura */
	if(!fp)
	{	printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}

	//leia tipo do arquivo
	char buffer[1001];
	fgets (buffer, 1000, fp); //Primeira linha
	if(strstr(buffer, "P3") == NULL) // o tipo de arquivo eh diferente de P3?
	{	printf( "\nErro no tipo do arquivo\n\n");
		exit(-2);
	}

	//leia comentario
	fgets (buffer, 1000, fp);
	
	//leia dados da imagem
	fscanf(fp, "%d%d%d", pColunas, pLinhas, pMaxValor);

	//criando a matriz
	PIXEL **mat;
	int i;
	mat = (PIXEL **) malloc(*pLinhas * sizeof(PIXEL *));
	for(i=0; i< *pLinhas; i++)
		mat[i] = (PIXEL *) malloc(*pColunas * sizeof(PIXEL));

	int l, c;
	for(l=0; l<*pLinhas; l++)
	{	for(c=0; c<*pColunas; c++)
		{	fscanf(fp, "%d", &mat[l][c].R);
			fscanf(fp, "%d", &mat[l][c].G);
			fscanf(fp, "%d", &mat[l][c].B);
		}
	}
	fclose(fp);
	return mat;
}
void escreverImagem(char * nomeArquivo, int ** mat, int linhas, int colunas, int maxValor)
{	FILE *fp;
	fp = fopen(nomeArquivo,"w");
	// Arquivo ASCII, para leitura
	if(!fp)
	{	printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}

	//escreva tipo do arquivo
	fprintf (fp, "P2\n");
	//escreva comentario
	fprintf (fp, "#Figura modificada...\n");
	//colunas, linhas
	fprintf(fp, "%d %d\n", colunas, linhas);
	//maxValor
	fprintf(fp, "%d\n", maxValor);

	int l, c;
	for(l=0; l<linhas; l++)
	{	for(c=0; c<colunas; c++)
		{	fprintf(fp, "%d ", mat[l][c]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}
void escreverImagemCol(char * nomeArquivo, PIXEL ** mat, int linhas, int colunas, int maxValor)
{	FILE *fp;
	fp = fopen(nomeArquivo,"w");
	// Arquivo ASCII, para leitura
	if(!fp)
	{	printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}

	//escreva tipo do arquivo
	fprintf (fp, "P3\n");
	//escreva comentario
	fprintf (fp, "#Figura modificada...\n");
	//colunas, linhas
	fprintf(fp, "%d %d\n", colunas, linhas);
	//maxValor
	fprintf(fp, "%d\n", maxValor);

	int l, c;
	for(l=0; l<linhas; l++)
	{	for(c=0; c<colunas; c++)
			fprintf(fp, "%d\n%d\n%d\n", mat[l][c].R, mat[l][c].G, mat[l][c].B);
	}
	fclose(fp);
}

// exposure
void aumentarBrilho(int** original, int linhas, int colunas, int maxValor){	
	int l, c;
	for(l=0; l<linhas; l++)
	{	for(c=0; c<colunas; c++)
		{	original[l][c] = (int)(original[l][c] * 1.2);
			if(original[l][c] > maxValor)
				original[l][c] = maxValor;
		}
	}
}
void diminuirBrilho(int** original, int linhas, int colunas, int maxValor){
	int l, c;
	for(l=0; l<linhas; l++)
	{	for(c=0; c<colunas; c++)
		{	original[l][c] = (int)(original[l][c] * 0.8);
			if(original[l][c] > maxValor)
				original[l][c] = maxValor;
		}
	}
}
void aumentarBrilhoCol(PIXEL** original, int linhas, int colunas, int maxValor)
{	int l, c;
	for(l=0; l<linhas; l++)
	{	for(c=0; c<colunas; c++)
		{	original[l][c].R = (int)(original[l][c].R * 1.2);
			if(original[l][c].R > maxValor)
				original[l][c].R = maxValor;
			original[l][c].G = (int)(original[l][c].G * 1.2);
			if(original[l][c].G > maxValor)
				original[l][c].G = maxValor;
			original[l][c].B = (int)(original[l][c].B * 1.2);
			if(original[l][c].B > maxValor)
				original[l][c].B = maxValor;
		}
	}
}
void diminuirBrilhoCol(PIXEL** original, int linhas, int colunas, int maxValor)
{	int l, c;
	for(l=0; l<linhas; l++)
	{	for(c=0; c<colunas; c++)
		{	original[l][c].R = (int)(original[l][c].R * 0.8);
			if(original[l][c].R > maxValor)
				original[l][c].R = maxValor;
			original[l][c].G = (int)(original[l][c].G * 0.8);
			if(original[l][c].G > maxValor)
				original[l][c].G = maxValor;
			original[l][c].B = (int)(original[l][c].B * 0.8);
			if(original[l][c].B > maxValor)
				original[l][c].B = maxValor;
		}
	}
}

//contrast
void aumentarContraste(int** original, int linhas, int colunas, int maxValor){
	int l, c;
	for(l=0; l<linhas; l++){	
		for(c=0; c<colunas; c++){
			original[l][c] = maxValor / (1.0 + exp(-(10.0 * original[l][c]/(float)maxValor - 5.0)));
		}
	}
}
void aumentarContrasteCol(PIXEL** original, int linhas, int colunas, int maxValor){
	int l, c;
	for(l=0; l<linhas; l++){	
		for(c=0; c<colunas; c++){
			original[l][c].R = maxValor / (1.0 + exp(-(10.0 * original[l][c].R/(float)maxValor - 5.0)));
			original[l][c].G = maxValor / (1.0 + exp(-(10.0 * original[l][c].G/(float)maxValor - 5.0)));
			original[l][c].B = maxValor / (1.0 + exp(-(10.0 * original[l][c].B/(float)maxValor - 5.0)));
		}
	}
}
void diminuirContraste(int** original, int linhas, int colunas, int maxValor){
	int l, c;
	for(l=0; l<linhas; l++){	
		for(c=0; c<colunas; c++){
			original[l][c] = maxValor / (1.0 + exp(-(2.0 * original[l][c]/(float)maxValor - 1.0)));
		}
	}
}
void diminuirContrasteCol(PIXEL** original, int linhas, int colunas, int maxValor){
	int l, c;
	for(l=0; l<linhas; l++){	
		for(c=0; c<colunas; c++){
			original[l][c].R = maxValor / (1.0 + exp(-(2.0 * original[l][c].R/(float)maxValor - 1.0)));
			original[l][c].G = maxValor / (1.0 + exp(-(2.0 * original[l][c].G/(float)maxValor - 1.0)));
			original[l][c].B = maxValor / (1.0 + exp(-(2.0 * original[l][c].B/(float)maxValor - 1.0)));
		}
	}
}

// blur
void borrar(int** original, int linhas, int colunas, int tamanhoBorrao){	
	int l, c;
	for(l=1; l<linhas-1; l++){	
		for(c=1; c<colunas-1; c++){
			original[l][c] = (original[l][c] + original[l-1][c] + original[l-1][c] +
			original[l][c-1] + original[l][c+1] + original[l+1][c+1] + original[l-1][c-1] + 
			original[l+1][c-1] + original[l-1][c+1]) / 9;
		}
	}
}
void borrarCol(PIXEL** original, int linhas, int colunas, int tamanhoBorrao){	
	int l, c;
	for(l=1; l<linhas-1; l++){	
		for(c=1; c<colunas-1; c++){
			original[l][c].R = (original[l][c].R + original[l-1][c].R + original[l-1][c].R +
			original[l][c-1].R + original[l][c+1].R + original[l+1][c+1].R + original[l-1][c-1].R + 
			original[l+1][c-1].R + original[l-1][c+1].R) / 9;

			original[l][c].G = (original[l][c].G + original[l-1][c].G + original[l-1][c].G +
			original[l][c-1].G + original[l][c+1].G + original[l+1][c+1].G + original[l-1][c-1].G + 
			original[l+1][c-1].G + original[l-1][c+1].G) / 9;

			original[l][c].B = (original[l][c].B + original[l-1][c].B + original[l-1][c].B +
			original[l][c-1].B + original[l][c+1].B + original[l+1][c+1].B + original[l-1][c-1].B + 
			original[l+1][c-1].B + original[l-1][c+1].B) / 9;
		}
	}
}

// frame
void moldura(int** original, int linhas, int colunas, int maxValor){
	int l, c;
	for(l=0; l<linhas; l++){	
		for(c=0; c<colunas; c++){	
			if(l<0.1*linhas || l>0.9*linhas || c<0.1*colunas|| c>0.9*colunas)
				original[l][c] = 0;
		}
	}
}
void molduraCol(PIXEL** original, int linhas, int colunas, int maxValor){
	int l, c;
	for(l=0; l<linhas; l++){	
		for(c=0; c<colunas; c++){	
			if(l<0.1*linhas || l>0.9*linhas || c<0.1*colunas|| c>0.9*colunas)
				original[l][c].R = 0, original[l][c].G = 0, original[l][c].B = 0;
		}
	}
}

// mirror
void espelhamentoHorizontal(int** original, int linhas, int colunas){
	int l, c, c2;
	for(l=0; l<linhas; l++){	
		for(c=0, c2=colunas-1; c<colunas/2; c++,c2--){
			int aux = original[l][c];
			original[l][c] = original[l][c2];
			original[l][c2] = aux;
		}
	}
}
void espelhamentoHorizontalCol(PIXEL** original, int linhas, int colunas){
	int l, c, c2;
	for(l=0; l<linhas; l++){	
		for(c=0, c2=colunas-1; c<colunas/2; c++,c2--){
			PIXEL aux = original[l][c];
			original[l][c].R = original[l][c2].R;
			original[l][c2].R = aux.R;

			original[l][c].G = original[l][c2].G;
			original[l][c2].G = aux.G;

			original[l][c].B = original[l][c2].B;
			original[l][c2].B = aux.B;
		}
	}
}
void espelhamentoVertical(int** original, int linhas, int colunas){
	int l, c, l2;
	for(c=0; c<colunas; c++){	
		for(l=0, l2=linhas-1; l<linhas/2; l++,l2--){
			int aux = original[l][c];
			original[l][c] = original[l2][c];
			original[l2][c] = aux;
		}
	}
}
void espelhamentoVerticalCol(PIXEL** original, int linhas, int colunas){
	int l, c, l2;
	for(c=0; c<colunas; c++){	
		for(l=0, l2=linhas-1; l<linhas/2; l++,l2--){
			PIXEL aux = original[l][c];
			original[l][c].R = original[l2][c].R;
			original[l2][c].R = aux.R;

			original[l][c].G = original[l2][c].G;
			original[l2][c].G = aux.G;

			original[l][c].B = original[l2][c].B;
			original[l2][c].B = aux.B;
		}
	}
}

//rotate
int ** girar (int** original, int * plinhas, int * pcolunas)
{	int l, c;
	//criando a matriz nova dinamicamente
	int **nova, i, L = *pcolunas, C = *plinhas;
	nova = (int **) malloc(L * sizeof(int *));
	for(i=0; i<L; i++)
		nova[i] = (int *) malloc(C * sizeof(int));
	
	//fazer a transposição
	for(l=0; l<L; l++)
		for(c=0; c<C; c++)
			nova[l][c] = original[c][l];
	
	//espelhar horizontalmente
	espelhamentoHorizontal (nova, L, C);
	*plinhas = L;
	*pcolunas = C;
	return nova;
}
PIXEL ** girarCol (PIXEL ** original, int * plinhas, int * pcolunas)
{	int l, c;
	//criando a matriz nova dinamicamente
	PIXEL **nova;
	int i, L = *pcolunas, C = *plinhas;
	nova = (PIXEL **) malloc(L * sizeof(PIXEL *));
	for(i=0; i<L; i++)
		nova[i] = (PIXEL *) malloc(C * sizeof(PIXEL));
	
	//fazer a transposição
	for(l=0; l<L; l++)
		for(c=0; c<C; c++){
			nova[l][c].R = original[c][l].R;
			nova[l][c].G = original[c][l].G;
			nova[l][c].B = original[c][l].B;
		}
	
	//espelhar horizontalmente
	espelhamentoHorizontalCol (nova, L, C);
	*plinhas = L;
	*pcolunas = C;
	return nova;
}

//RGB channels
void canaisRGB(PIXEL** original, int linhas, int colunas, int maxValor){
	int l, c;
	char channel[10] = "0";
	printf("Selecione R, G ou B: ");
	gets(channel);

	if(strcmp(channel, "R") == 0 ){
		for(l=0; l<linhas; l++){
			for(c=0; c<colunas; c++){
				original[l][c].R = (int)(original[l][c].R * 1.2);
				if(original[l][c].R > maxValor)	original[l][c].R = maxValor;
			}
		}
	}

	if(strcmp(channel, "G") == 0 ){
		for(l=0; l<linhas; l++){
			for(c=0; c<colunas; c++){
				original[l][c].G = (int)(original[l][c].G * 1.2);
				if(original[l][c].G > maxValor)	original[l][c].G = maxValor;
			}
		}
	}

	if(strcmp(channel, "B") == 0 ){
		for(l=0; l<linhas; l++){
			for(c=0; c<colunas; c++){
				original[l][c].B = (int)(original[l][c].B * 1.2);
				if(original[l][c].B > maxValor)	original[l][c].B = maxValor;
			}
		}
	}

}

// main and menu
int main(int argc, char * argv[]){
	char opcao[10]="0";
	int color_flag = 0;
	int linhas=0, colunas=0, maxValor=0; 
	int **mat=NULL;
	PIXEL **mat_col=NULL;
	int tamanhoBorrao = 8;
	char nomeArquivo[100]="";
	char nomeArquivoLeitura[100]="";
	char nomeArquivoEscrita[100]="";
	while(strcmp(opcao, "sair") != 0){
		printf("\n\nMini-photoshop\n\n");
		printf("1) Ler imagem\n");	
		printf("2) Gravar imagem\n");	
		printf("3) Aumentar o brilho\n");	
		printf("4) Diminuir o brilho\n");	
		printf("5) Aumentar contraste\n");
		printf("6) Diminuir contraste\n");
		printf("7) Desfocar\n");
		printf("8) Fazer moldura\n");
		printf("9) Espelhamento Horizontal\n");
		printf("10) Espelhamento Vertical\n");
		printf("11) Rotacao 90 graus, horaria.\n");
		printf("12) Reforcar canais RGB.\n");
		printf("\nOu digite 'sair' para sair...\n");
		printf("\nEntre a opcao desejada: ");
		gets(opcao);

		if(strcmp(opcao, "1") == 0 ){
			char color_option[10] = "0";
			printf("\n\nEntre com o nome da imagem (sem extensao): ");
			fgets(nomeArquivo, 100, stdin);
			nomeArquivo[strlen(nomeArquivo)-1]='\0';
			strcpy (nomeArquivoLeitura, nomeArquivo);

			printf("\nDigite 1 para uma imagem PB, 2 para uma imagem colorida: ");
			gets(color_option);

			if (strcmp(color_option, "1") == 0){
				strcat (nomeArquivoLeitura, ".pgm");
				printf("\nLer PB");
				mat = lerImagem(nomeArquivoLeitura, &linhas, &colunas, &maxValor);
				color_flag = 1;
			}else if (strcmp(color_option, "2") == 0){
				strcat (nomeArquivoLeitura, ".ppm");
				printf("\nLer colorida");
				mat_col = lerImagemCol(nomeArquivoLeitura, &linhas, &colunas, &maxValor);
				color_flag = 2;
			}else printf("Voltando ao menu..");

		}

		if(strcmp(opcao, "2") == 0 ){
			strcpy (nomeArquivoEscrita, nomeArquivo);	
			if(color_flag == 1){
				strcat (nomeArquivoEscrita, "_editada.pgm");
				escreverImagem(nomeArquivoEscrita, mat, linhas, colunas, maxValor);
			}
			if(color_flag == 2){
				strcat (nomeArquivoEscrita, "_editada.ppm");
				escreverImagemCol (nomeArquivoEscrita, mat_col, linhas, colunas, maxValor);
			}
			printf("\n\nA imagem sera salva como %s\n", nomeArquivoEscrita);
		}

		//exposure
		if(strcmp(opcao, "3") == 0 && color_flag == 1) aumentarBrilho(mat, linhas, colunas, maxValor);
		if(strcmp(opcao, "3") == 0 && color_flag == 2) aumentarBrilhoCol(mat_col, linhas, colunas, maxValor);
		if(strcmp(opcao, "4") == 0 && color_flag == 1) diminuirBrilho(mat, linhas, colunas, maxValor);
		if(strcmp(opcao, "4") == 0 && color_flag == 2) diminuirBrilhoCol(mat_col, linhas, colunas, maxValor);

		//contrast
		if(strcmp(opcao, "5") == 0 && color_flag == 1) aumentarContraste(mat, linhas, colunas, maxValor);
		if(strcmp(opcao, "5") == 0 && color_flag == 2) aumentarContrasteCol(mat_col, linhas, colunas, maxValor);
		if(strcmp(opcao, "6") == 0 && color_flag == 1) diminuirContraste(mat, linhas, colunas, maxValor);
		if(strcmp(opcao, "6") == 0 && color_flag == 2) diminuirContrasteCol(mat_col, linhas, colunas, maxValor);

		//blur
		if(strcmp(opcao, "7") == 0 && color_flag == 1) borrar(mat, linhas, colunas, tamanhoBorrao);
		if(strcmp(opcao, "7") == 0 && color_flag == 2) borrarCol(mat_col, linhas, colunas, tamanhoBorrao);

		//frame
		if(strcmp(opcao, "8") == 0 && color_flag == 1) moldura(mat, linhas, colunas, maxValor);
		if(strcmp(opcao, "8") == 0 && color_flag == 2) molduraCol(mat_col, linhas, colunas, maxValor);

		//mirror
		if(strcmp(opcao, "9") == 0 && color_flag == 1) espelhamentoHorizontal(mat, linhas, colunas);
		if(strcmp(opcao, "9") == 0 && color_flag == 2) espelhamentoHorizontalCol(mat_col, linhas, colunas);
		if(strcmp(opcao, "10") == 0 && color_flag == 1) espelhamentoVertical(mat, linhas, colunas);
		if(strcmp(opcao, "10") == 0 && color_flag == 2) espelhamentoVerticalCol(mat_col, linhas, colunas);

		//rotate
		if(strcmp(opcao, "11") == 0 && color_flag == 1) mat = girar(mat, &linhas, &colunas);
		if(strcmp(opcao, "11") == 0 && color_flag == 2) mat_col = girarCol(mat_col, &linhas, &colunas);

		//RGB channels
		if(strcmp(opcao, "12") == 0 && color_flag == 1) printf("\nImagem PB! Carregue uma imagem colorida.\n");
		if(strcmp(opcao, "12") == 0 && color_flag == 2) canaisRGB(mat_col, linhas, colunas, maxValor);
	}
	return 0;
}