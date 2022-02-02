#include <stdio.h>
#include <stdlib.h>

#define TOT 18000

int* construtores (int num);

int tamanho (int* aux);

void imprimeConstrutoresArquivo(int n, FILE* arquivoOut);

//void imprimeConstrutores(int n);

int main(){
    /*
       Se quiser digitar os números pela linha de comando, basta descomentar da linha 30 até a 39, 12
    e da linha 227 até a 253. E comentar da linha 41 até a 101. Ou também pode apenas editar o arquivo
    algoc.in.
        Na função main, eu começo abrindo o arquivo de leitura e calculando o número de linhas contidas nele.
    Após feito isso, eu o fecho e abro o arquivo de saída (arquivo no qual ficará com as respostas salvas).
    Chamo a função 'imprimeConstrutoresArquivo' para imprimir as respostas e, se chegar no número 0 no arquivo
    de leitura o programa acaba, como foi pedido no documento da avaliação. Mas se quiser que o programa continue
    rodando, basta comentar a linha 81. E, caso queira que o arquivo seja impresso na tela, descomente as linhas
    89 até 101.
    */

    int qntdNum = 0; 
    int num[qntdNum]; 
    
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
    } /*else {
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
    }*/
}

int* construtores (int num){
    /*
       Nessa função contém a lógica do ALGOC. 
       Fiz uma parte para os números 1 e -1, já que seus construtores é apenas o PLUSONE ou o MINUSONE.
       Para encontrar os construtores dos números positivos eu crio uma variável chamada novoNum, para 
    que, a partir dela, eu possa saber quanto está dando a conta dos contrutores. Como para os números
    positivos não possui uma maneira de abaixar o valor do novoNum, eu uso a condição que, antes de *2
    eu confiro se vai passar do valor do num (número provindo do algoc.in). 
       Para encontrar os construtores dos números negativos, eu tirei a condição do "do-while" ser feito
    apenas se o novoNum for menor que num, até por que, com os números negativos é possível subtrair. E, 
    para encontrar resultados com um menor número de construtores, eu coloquei uma condição na hora de
    multiplicar.
       Após encontrado todos os construtores, eu coloco um zero na última posição do array tipo[]. Isso
    será usado na função 'tamanho'. 
    */

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
                //if((novoNum*2) < num){
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
    /*
       Fiz essa função para encontrar o tamanho do array gerado pela função 'contrutores'. Tentei 
    encontrar esse valor de outras maneiras, mas preferi fazendo assim.
       Pode-se perceber que usei aquela última posição do array igual a zero para encontrar o tamanho.
    */

    int tam = 0;
    do{  
        tam++;
    } while (aux[tam] != 0);
    return tam;
}

void imprimeConstrutoresArquivo(int n, FILE* arquivoOut){
    /*
    Essa função foi criada para imprimir os construtores com seus respectivos nomes.
    1 = PLUSONE;
    2 = MINUSONE;
    3 = INC;
    4 = DUP;
    */

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

/*void imprimeConstrutores(int n){
    //Essa função serve para imprimir na tela o resultado, caso o usuário opte por entrar
    //com os valores pela linha de comando ao invés do arquivo.

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
