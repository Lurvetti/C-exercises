/*
Validador de CNPJ. 11.222.333/0001-XX
*/

#include<stdio.h>

int validarDV(int p_cnpj[14], int end){
    int multiplier [13] = {6 , 5 , 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int contc, contm = 0, dv, sum = 0;

    //setup the counter for multiplier iteration
    if (end == 12){
        contm = 1;
    }

    for (contc = 0; contc < end; contc++, contm++){
        sum += p_cnpj[contc] * multiplier[contm];
    }

    if(sum % 11 < 2){
        dv = 0;
    }else{
        dv = 11 - (sum % 11);
    }

    //test DV
    if(dv == p_cnpj[end]){
            printf("DV is valid!\n");
            return 1;
        }else{
            printf("DV is invalid!");
            return 0;
        }
}

int main(){
    int cnpj[14];
    int cont;

    printf("Enter CNPJ: ");
    for(cont = 0; cont < 14; cont ++){
        scanf("%d" , &cnpj[cont]);
    }

    if(validarDV(cnpj, 12) && validarDV(cnpj, 13)){
        printf("\nCNPJ IS VALID!");
    }else{
        printf("\nCNPJ IS INVALID!");
    }

    return 0;
}