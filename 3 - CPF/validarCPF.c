/*

Validador de CPF. 463.788.548-58

Multiplicador 1 (9 vezes): 10*4 9*6 8*3 7*7 6*8 5*8 4*5 3*4 2*8
Somar tudo.
Digito 1 (5) = ((soma de tudo * 10) % 11) % 10 
(o último resto de divisão serva para que se for 10, consideramos 0)

Multiplicador 2 (10 vezes): 11*4 10*6 9*3 8*7 7*8 6*8 5*5 4*4 3*8 2*5
Somar tudo
Digito 2 (8) = ((soma de tudo*10) % 11) % 10

*/

#include<stdio.h>
#include<stdbool.h>

void mostrarEstado(int digito){
    /*checar o digito associado ao estado de emissao*/
    switch(digito){
        case 0:
            printf("Rio Grande do Sul");
            break;
        case 1:
            printf("Distrito Federal, Goias, Mato Grosso, Mato Grosso do Sul e Tocantins");
            break;
        case 2:
            printf("Amazonas, Para, Roraima, Amapa, Acre e Rondonia");
            break;
        case 3:
            printf("Ceara, Maranhao e Piaui");
            break;
        case 4:
            printf("Paraiba, Pernambuco, Alagoas e Rio Grande do Norte");
            break;
        case 5:
            printf("Bahia e Sergipe");
            break;
        case 6:
            printf("Minas Gerais");
            break;
        case 7:
            printf("Rio de Janeiro e Espirito Santo");
            break;
        case 8:
            printf("Sao Paulo");
            break;
        case 9:
            printf("Parana e Santa Catarina");
            break;
    }
}

bool verificarRepetidos(int pcpf[]){
    /*verifica se o CPF possui digitos repetidos, ex. 111.111.111-11*/
    int i;
    for (i = 0; i < 10; i++){
        if(pcpf[i] != pcpf[i + 1]){
            return false;
        }
    }
    printf("\nDigitos repetidos!");
    return true;
}

bool validarCPF(int pcpf[], int mult){
    /*algoritmo que confere os digitos*/
    int soma = 0;
    int resto = 0;
    int i;
    int j = mult;

    for(i = 0; j >= 1; j--, i++){
        soma = soma + pcpf[i]*(j + 1);
    }
    resto = ((soma*10) % 11)%10;

    if (resto == pcpf[mult]){
        printf("\nDigito valido!");
        return true;
    }else{
        printf("\nDigito invalido!");
        return false;
    }
}

int main(){
	int cpf[11];
	int i;
	
	printf("Entre com os 11 digitos do CPF: ");
	for(i = 0; i < 11; i++){	
	    scanf("%d", &cpf[i]);
	}
	
    if (validarCPF(cpf, 9) && 
        validarCPF(cpf, 10) && 
        !verificarRepetidos(cpf)){
        printf("\nCPF valido!\nEstado(s): ");
        mostrarEstado(cpf[8]);
    }else{
        printf("\nCPF invalido!");
    }

    printf("\n\n");
	return 0;
}