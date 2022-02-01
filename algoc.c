#include <stdio.h>
#include <stdlib.h>
#define TOT 100

int* construtores (int num){
    int novoNum  = 0, aux = 0, i = 0;

    int *tipo = (int*) malloc (TOT * sizeof(int));

    if ((num == 1) || (num == -1)){
        if (num == 1){
            tipo[0] = 1;
        } else {
            tipo[0] = 2;
        }

    } else {
        if (num > 0){
            novoNum += 1;
            tipo[0] = 1;

            do{
                i++;
                aux = num - novoNum;

                if((aux%2 == 0) && ((novoNum*2) < num)){
                    novoNum *= 2;
                    tipo[i] = 4;
                } else {
                    novoNum += 1;
                    tipo[i] = 3;
                }

                if(novoNum > num){
                    printf("ERRO: não foram encontrados os construtores.");
                }
            } while ((novoNum != num) && (novoNum < num));

        } else {
            novoNum -= 1;
            tipo[0] = 2;
            do{
                i++;

                if((novoNum * 2) >= (num-1)){
                    novoNum *= 2;
                    tipo[i] = 4;
                } else {
                    novoNum += 1;
                    tipo[i] = 3;
                }

            } while ((novoNum != num));
        }
    }

    tipo[i+1] = 0;

    return tipo;
    free(tipo);
}


int tamanho (int* aux){
    int tam = 0;
    do{  
        tam++;
    } while (aux[tam] != 0);
    return tam;
}


void imprimeConstrutores(int n){
    int* tp = construtores(n);

    int tam = tamanho(tp);

    printf("\n");
    printf("Constant %d\n", n);
    for (int k = 0; k < tam; k++){   
        switch (tp[k]){
        case 1:
            printf("PLUSONE\n");
            break;
        case 2:
            printf("MINUSONE\n");
            break;
        case 3:
            printf("INC\n");
            break;
        case 4:
            printf("DUP\n");
            break;
        }
    }
}


int main(){
    int qntdNum = 0, num[qntdNum]; 

    printf("Quantos numeros gostaria de digitar? ");
    scanf("%d", &qntdNum);
    printf("Digite os dados de Entrada: ");
    for (int i = 0; i < qntdNum; i++){
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < qntdNum; i++){
        imprimeConstrutores(num[i]);
    }
}