#include <stdio.h>

int main() {
    int opcao = 0;
    int Qprodutos = 0;
    int idproduto[100];

    do {
        printf("====================================\n");
        printf("          MENU DO ESTOQUE\n");
        printf("====================================\n");
        printf("1. Cadastrar produtos\n");
        printf("2. Registrar entradas mensais de um produto\n");
        printf("3. Registrar quantidade atual em estoque\n");
        printf("4. Listar todos os produtos (resumo)\n");
        printf("5. Exibir ficha completa de um produto\n");
        printf("6. Estatisticas do estoque\n");
        printf("7. Ranking (Top 5 produtos com maior estoque)\n");
        printf("8. Sair\n");
        printf("====================================\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("qual a quantidade de produtos a serem registrados?\n");
                scanf("%d", &Qprodutos);
                while(Qprodutos < 1 || Qprodutos > 40){
                    printf("Quantidade nao aceita, tente novamente digitando um numero entre 1 e 40 ;D\n");
                    scanf("%d", &Qprodutos);
                }
                for (int i = 0; i < Qprodutos; i++)
                {
                    printf("Digite o ID do produto, no qual seja maior que zero e unico!\n");
                    scanf("%d", &idproduto[i]);
                    while(idproduto[i] < 0){
                        printf("ID não permitido\n");
                        scanf("%d", &idproduto[i]);
                    
                    }
                }
                
                printf("oi\n");
                break;

            case 2:
                // Registrar entradas mensais de um produto
                break;

            case 3:
                // Registrar quantidade atual em estoque
                break;

            case 4:
                // Listar todos os produtos (resumo)
                break;

            case 5:
                // Exibir ficha completa de um produto
                break;

            case 6:
                // Estatisticas do estoque
                break;

            case 7:
                // Ranking (Top 5 produtos com maior estoque)
                break;

            case 8:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Digite um numero entre 1 e 8.\n");
                break;
        }
    } while (opcao != 8);

    return 0;
}