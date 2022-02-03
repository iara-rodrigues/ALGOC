#include <stdio.h>
#include <stdlib.h>

#define TOT 20000

int* construtores (int num);

int tamanho (int* aux);

void imprimeConstrutoresArquivo(int n, FILE* arquivoOut);

int main(){

    int qntdNum = 0; 
    int num[qntdNum]; 

    FILE *arquivoIn;
    arquivoIn = fopen("algoc.in", "r");
    if (arquivoIn == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        exit(-1);
    }

    int i = 0;
    do{
        qntdNum ++;
        fscanf(arquivoIn, "%d", &num[i]);
        i++;
    } while (!feof(arquivoIn));

    for (int i = 0; i < qntdNum; i++){
        fscanf(arquivoIn, "%d", &num[i]);
    }
           
    fclose(arquivoIn);

    FILE *arquivoOut;
    arquivoOut = fopen("algoc.out", "w");
    if (arquivoOut == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        exit(-1);
    }

    fprintf(arquivoOut, "\n");
    fprintf(arquivoOut, "Constantes: \n");
    
    for (int i = 0; i < qntdNum; i++){
        fprintf(arquivoOut, "%d\n", num[i]);
    }

    for (int i = 0; i < qntdNum; i++){
        if (num [i] != 0){
            imprimeConstrutoresArquivo(num[i], arquivoOut);
        } else {
            fprintf(arquivoOut, "\n");
            fprintf(arquivoOut, "Chegou no número zero.\n");
            break;
        }
    }

    int sucesso = fclose(arquivoOut);
    if (sucesso != 0) {
        printf("ERRO AO ENCERRAR O ARQUIVO\n");
        exit(-1);
    } 

    printf("\nArquivo escrito com sucesso!\n");
}

int* construtores (int num){

    int novoNum  = 0, aux = 0, i = 0;
    int count1 = 0, count2 = 0, seg1 = 0, seg2 = 0, a = 0, novoNum2 = 0;

    int *tipo = (int*) malloc (TOT * sizeof(int));
    int *tipo2 = (int*) malloc (TOT * sizeof(int));
    int *tipoResult = (int*) malloc (TOT * sizeof(int));

    if ((num == 1) || (num == -1)){
        if (num == 1){
            tipoResult[0] = 1;
        } else {
            tipoResult[0] = 2;
        }

    } else {
        if (num > 0){
            novoNum += 1;
            tipo[0] = 1;
            novoNum2 += 1;
            tipo2[0] = 1;
            
            do{
                i++;
                
                if((aux%2 == 0) && ((novoNum*2) <= num)){
                    novoNum *= 2;
                    tipo[i] = 4;
                    seg1 ++;
                } else {
                    novoNum += 1;
                    tipo[i] = 3;
                    seg1 += 2;
                }
                
                aux = num - novoNum;

                if(novoNum > num){
                    printf("ERRO1: não foram encontrados os construtores.");
                }
                count1++;
            } while ((novoNum != num) && (novoNum < num));

            do{
                a++;
                if((novoNum2*2) < num){
                    novoNum2 *= 2;
                    tipo2[a] = 4;
                    seg2++;
                } else {
                    novoNum2 += 1;
                    tipo2[a] = 3;
                    seg2 += 2;
                }
                
                aux = num - novoNum2;

                if(novoNum2 > num){
                    printf("ERRO2: não foram encontrados os construtores.");
                }
                count2++;
            } while ((novoNum2 != num) && (novoNum2 < num));
               
            if (count2 < count1){
                for (int k = 0; k < a+1; k++){
                    tipoResult[k] = tipo2[k];
                }
                tipoResult[a+1] = 0;
            } else {
                if (count2 > count1){
                    for (int k = 0; k < i+1; k++){
                    tipoResult[k] = tipo[k];
                }
                tipoResult[i+1] = 0;
                } else {
                    if(seg2 < seg1){
                        for (int k = 0; k < a+1; k++){
                            tipoResult[k] = tipo2[k];
                        }
                        tipoResult[a+1] = 0;
                    } else{
                        if (count2 > count1){
                            for (int k = 0; k < i+1; k++){
                                tipoResult[k] = tipo[k];
                            }
                            tipoResult[i+1] = 0;
                        } else {
                            for (int k = 0; k < i+1; k++){
                                tipoResult[k] = tipo[k];
                            }
                            tipoResult[i+1] = 0;
                        }
                    }
                }
            }

        } else {
            novoNum -= 1;
            tipoResult[0] = 2;
            do{
                i++;

                if((novoNum * 2) >= (num-1)){
                    novoNum *= 2;
                    tipoResult[i] = 4;
                } else {
                    novoNum += 1;
                    tipoResult[i] = 3;
                }

            } while ((novoNum != num));
            tipoResult[i+1] = 0;
        }
    }

    return tipoResult;
    free(tipo);
    free(tipo2);
    free(tipoResult);
}

int tamanho (int* aux){

    int tam = 0;
    do{  
        tam++;
    } while (aux[tam] != 0);
    return tam;
}

void imprimeConstrutoresArquivo(int n, FILE* arquivoOut){

    int* tp = construtores(n);

    int tam = tamanho(tp);

    fprintf(arquivoOut, "\n");
    fprintf(arquivoOut, "Constant %d\n", n);

    for (int k = 0; k < tam; k++){   
        switch (tp[k]){
        case 1:
            fprintf(arquivoOut, "PLUSONE\n");
            break;
        case 2:
            fprintf(arquivoOut, "MINUSONE\n");
            break;
        case 3:
            fprintf(arquivoOut, "INC\n");
            break;
        case 4:
            fprintf(arquivoOut, "DUP\n");
            break;
        }
    }
    free(tp);
}