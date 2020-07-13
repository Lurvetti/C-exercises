//Código Base para o Mini-Projeto Agenda de Amigos

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

struct ficha{
	char nome[40];
	char telefone[20];
    char endereco[50];
    char email[20];
    char idade[10];
};


void menu(){
	printf("\n-----------------------------");
	printf("\nEntre com a opcao desejada:\n");
	printf("\n1) Inserir ficha");
	printf("\n2) Procurar por nome");
	printf("\n3) Listar toda a base");
	printf("\n4) Excluir por nome");
	printf("\n5) Atualizar registro");
	printf("\n6) Sair\n\n");
}

void mostrar_info(struct ficha user){
    printf("\nNome: %s", user.nome);
    printf("\nTelefone: %s", user.telefone);
    printf("\nEndereco: %s", user.endereco);
    printf("\nEmail: %s", user.email);
    printf("\nIdade: %d", user.idade);
}

int procurar(char procurado[], struct ficha vetor[], int num_fichas, int i){
	if (i == num_fichas){
		printf("\nRegistro nao encontrado!\n");
		exit;
	}
	if(strstr (vetor[i].nome, procurado) == vetor[i].nome){	
		printf("\nRegistro encontrado!\n");
		mostrar_info(vetor[i]);
		return i;
	}
	else{
		return procurar(procurado, vetor, num_fichas, i+1);	
	}
}

//retorna um novo registro para a agenda
struct ficha get_info(){
	struct ficha new;
	printf("\nEntre com um nome:");
	gets(new.nome);
	printf("Entre com um telefone:"); 
	gets(new.telefone);
	printf("Entre com um endereco:");
	gets(new.endereco);
	printf("Entre com um email:");
	gets(new.email);
	printf("Entre com um idade:");
	gets(new.idade);
	return new;
}


int main(){
	struct ficha agenda[100];
	int fichas_existentes = 0, proxima = 0;
	char opcao[10]="0";
    setlocale(LC_ALL, "Portuguese");

	while(opcao[0] != '6'){
		menu();
		gets(opcao);
        
		//inserir novo registro
		if(opcao[0] == '1'){		
			agenda[proxima] = get_info();
			fichas_existentes++;
			proxima++;
		}

        //procurar  e exibir registro
		if(opcao[0] == '2'){
			if(fichas_existentes > 0){
				char procurado[40];
				printf("\nEntre com o nome procurado:");
				gets(procurado);
				procurar(procurado, agenda, fichas_existentes, 0);

			}else printf("\nA base de dados esta vazia!\n");
		}
        
        //listar todos os registros
		if(opcao[0] == '3'){ 
			int i;
			printf("\n--- LISTA DE REGISTROS ---", i);
			for(i=0; i < fichas_existentes; i++){
			    mostrar_info(agenda[i]);
				printf("\n");
			}
			if(fichas_existentes == 0)  printf("\nA base de dados esta vazia!\n");
		}

        //excluir registro
		if(opcao[0] == '4'){
			if(fichas_existentes > 0){
				char procurado[40];
				int exclude;
				printf("\nEntre com o nome que sera excluido:");
				gets(procurado);
				exclude = procurar(procurado, agenda, fichas_existentes, 0);

				printf("\n\nO registro de %s foi removido\n", agenda[exclude].nome);
				agenda[exclude] = agenda[fichas_existentes-1];
				fichas_existentes--;
				proxima--;

			}else printf("\nA base de dados esta vazia!\n");
		}

		//atualizar registro
		if(opcao[0] == '5'){
			if(fichas_existentes > 0){
				char atualizado[40];
				int registro;

				printf("\nEntre com o nome que sera atualizado:");
				gets(atualizado);
				registro = procurar(atualizado, agenda, fichas_existentes, 0);
				agenda[registro] = get_info();

			}else printf("\nA base de dados esta vazia!\n");
		}
	}
	return 0;
}	