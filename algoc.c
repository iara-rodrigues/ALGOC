#include <stdio.h>
#include <stdlib.h>

int* construtores (int num){
    int novoNum  = 0, aux = 0, aux2 = 0, i = 0;

    int *tipo = (int*) malloc (10 * sizeof(int));

    for (int k = 0; k < 10; k++){
        tipo[k] = 0;
    }

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

int main(){
    int qntdNum = 0, num[qntdNum]; 

    printf("Quantos numeros gostaria de digitar? ");
    scanf("%d", &qntdNum);
    printf("Digite os dados de Entrada: ");
    for (int i = 0; i < qntdNum; i++){
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < qntdNum; i++){
        
        int* tp = construtores(num[i]);

        int tam = tamanho(tp);

        printf("Constant %d\n", num[i]);
        for (int k = 0; k < tam; k++){   
            printf("Tipo: %d\n", tp[k]);
        }
        printf("\n");
    }
}