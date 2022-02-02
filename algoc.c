#include <stdio.h>
#include <stdlib.h>

#define TOT 300

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

/*void imprimeConstrutores(int n){
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
}*/

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
}


int main(){
    int qntdNum = 0; 
    int num[qntdNum]; 

    //Se quiser escrever os números, basta descomentar da linha 131 até a 142,
    //e da linha 72 até a 95. E comentar da linha 143 até a 199.

    /*int qntdNum = 0, num[qntdNum]; 

    printf("Quantos numeros gostaria de digitar? ");
    scanf("%d", &qntdNum);
    printf("Digite os dados de Entrada: ");
    for (int i = 0; i < qntdNum; i++){
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < qntdNum; i++){
        imprimeConstrutores(num[i]);
    }*/

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
    //printf("Quantidade de Constantes no arquivo: %d\n", qntdNum);

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
        imprimeConstrutoresArquivo(num[i], arquivoOut);
    }

    int sucesso = fclose(arquivoOut);
    if (sucesso != 0) {
        printf("ERRO AO ENCERRAR O ARQUIVO\n");
        exit(-1);
    } else {
        FILE *arquivo;
        arquivo = fopen("algoc.out", "r");
        if (arquivo == NULL) {
            printf("ERRO AO ABRIR O ARQUIVO\n");
            exit(-1);
        }

        char c;
        do{
            putchar(c);
        }while((c = fgetc(arquivo)) != EOF);
    }
}