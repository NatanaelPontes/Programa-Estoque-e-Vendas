#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int opcao = 0, i, quant = 0;
    int quantIngredientes, quantSabores;
    float precoSabor, totalVendas, quantVendida;
    char produto[20];
    char ingredientes[20][20];
    char sabores[20][20];
    char arqEst[20];
    char arqVen[20];

    printf("Informe o produto: ");
    scanf("%s", produto);

    printf("\nDigite quantos produtos serao contabilizados na entrada de estoque e vendas como ingredientes\n");
    scanf("%d", &quant);

    printf("\nDigite quantos sabores e variacoes do produto %s serao contabilizados:\n", produto);
    scanf("%d", &quantSabores);

    do{

        printf("\nSelecione a opcao desejada: \n\n\t1 - Informar ingredientes presentes no estoque\n\t2 - Quantidade de Estoque\n\t3 - Sabores e/ou Variacoes\n\t4 - Vendas\n\n\t5 - Salvar arquivo de Estoque\n\t6 - Salvar arquivo de Vendas\n\t7 - Ler arquivo relatorio de Estoque\n\t8 - Ler arquivo relatorio de Vendas\n\n\t0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:

                for(i = 0; i < quant; i++){
                    printf("Digite o ingrediente %d do produto %s: ", i + 1, produto);
                    scanf("%s", ingredientes[i]);
                }

                break;

            case 2:

                for(i = 0; i < quant; i++){
                    printf("Digite a quantidade do ingrediente %s presente no estoque atualmente: ", ingredientes[i]);
                    scanf("%d", &quantIngredientes);
                }
                break;

            case 3:

                for(i = 0; i < quantSabores; i++){
                    printf("Digite o sabor/variacao %d do produto %s:", i + 1, produto);
                    scanf("%s", sabores[i]);
                }

                break;

            case 4:

                totalVendas = 0;

                for (i = 0; i < quantSabores; i++) {
                    printf("Informe o preco do sabor/variacao %s: ", sabores[i]);
                    scanf("%f", &precoSabor);

                    printf("Informe a quantidade de vendas do sabor/variacao %s:  \n", sabores[i]);
                    scanf("%f", &quantVendida);
                    scanf("%c");

                    totalVendas += precoSabor * quantVendida;
                }

                printf("Total de vendas de hoje foi de R$ %.2f\n", totalVendas);

                break;

            case 5:
                printf("Digite o nome do arquivo a ser salvo acrescentando o seu formato no final (como .doc ou .txt, por exemplo): ");
                scanf("%s", arqEst);

                FILE *file = fopen(arqEst, "w");


                if(file){

                    fprintf(file, "\n\t------------------- RELATORIO DE ESTOQUE -------------------\n\n");

                    for (i = 0; i < quant; i++){
                        printf("Confirme a quantidade do ingrediente %s presente no estoque atualmente: ", ingredientes[i]);
                        scanf("%d", &quantIngredientes);
                        fprintf(file, "A quantidade do do ingrediente %s no estoque atualmente e de %d.\n\n", ingredientes[i], quantIngredientes);
                    }

                    fclose(file);
                }
                else
                    printf("Nao foi possivel abrir o arquivo!");


                break;

             case 6:
            {
                printf("Digite o nome do arquivo a ser salvo acrescentando o seu formato no final (como .doc ou .txt, por exemplo): ");
                scanf("%s", arqVen);

                FILE *venfile = fopen(arqVen, "w");

                if (venfile) {

                    fprintf(venfile, "\n\t------------------- RELATORIO DE VENDAS -------------------\n\n");

                    for (i = 0; i < quantSabores; i++) {
                        fprintf(venfile, "%s: R$ %.2f\n\n", sabores[i], quantVendida);
                    }

                    fprintf(venfile, "Total de vendas de hoje foi de R$ %.2f\n", totalVendas);

                    fclose(venfile);
                }
                else
                    printf("Nao foi possivel abrir o arquivo!");

                break;
            }

            case 7:

                    printf("Digite o nome do arquivo a ser aberto e sua extensao: ");
                    scanf("%s", arqEst);

                    FILE *filee = fopen(arqEst, "r");

                    if(filee){
                        char linha[100];
                        while (fgets(linha, sizeof(linha), filee) != NULL){
                            printf("%s", linha);
                        }
                        fclose(filee);
                    }
                    else {
                        printf("Nao foi possivel abrir o arquivo desejado\n");
                    }

                break;

            case 8:

                printf("Digite o nome do arquivo a ser aberto e sua extensao: ");
                    scanf("%s", arqVen);

                    FILE *fileee = fopen(arqVen, "r");

                    if(filee){
                        char linhaa[100];
                        while (fgets(linhaa, sizeof(linhaa), fileee) != NULL){
                            printf("%s", linhaa);
                        }
                        fclose(fileee);
                    }
                    else {
                        printf("Nao foi possivel abrir o arquivo desejado\n");
                    }

                break;

            default:
                if(opcao != 0)
                    printf("\nDigite uma opcao valida! \n");
                break;

        }

    }while(opcao != 0);


    return 0;
}
