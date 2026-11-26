#include <stdio.h>
#include <string.h>

int main()
{
    int opcao = 0;
    int Qprodutos = 0;
    int totalCadastrados = 0;
    int idproduto[40];
    int idrepetido = 0;
    char nomeproduto[40][60];
    char categoria[40][40];
    float preco[40];
    int estoque[40];
    int entradas[40][4];
    int idEntrada;

    do
    {
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

        switch (opcao)
        {
        case 1:
            if (totalCadastrados >= 40)
            {
                printf("Limite maximo de 40 produtos ja atingido!\n");
            }
            else
            {
                printf("Qual a quantidade de produtos a serem registrados? (Disponivel: %d)\n", 40 - totalCadastrados);
                scanf("%d", &Qprodutos);
                while (Qprodutos < 1 || totalCadastrados + Qprodutos > 40)
                {
                    printf("Quantidade nao aceita, digite um numero entre 1 e %d:\n", 40 - totalCadastrados);
                    scanf("%d", &Qprodutos);
                }

                for (int i = totalCadastrados; i < totalCadastrados + Qprodutos; i++)
                {
                    printf("\n--- Produto %d ---\n", i + 1);
                    printf("Digite o ID do produto (maior que zero e unico):\n");
                    scanf("%d", &idproduto[i]);
                    idrepetido = 0;
                    for (int j = 0; j < i; j++)
                    {
                        if (idproduto[i] == idproduto[j])
                        {
                            idrepetido = 1;
                        }
                    }

                    while (idproduto[i] <= 0 || idrepetido == 1)
                    {
                        printf("ID nao permitido ou ja existente! Digite um ID valido:\n");
                        scanf("%d", &idproduto[i]);
                        idrepetido = 0;
                        for (int j = 0; j < i; j++)
                        {
                            if (idproduto[i] == idproduto[j])
                            {
                                idrepetido = 1;
                            }
                        }
                    }

                    while (getchar() != '\n');

                    printf("Digite o nome do produto (nao deixe vazio):\n");
                    fgets(nomeproduto[i], 60, stdin);

                    int contadorletra = 0;
                    for (int k = 0; nomeproduto[i][k] != '\0'; k++)
                    {
                        if (nomeproduto[i][k] == '\n')
                        {
                            nomeproduto[i][k] = '\0';
                        }
                        else if (nomeproduto[i][k] != ' ')
                        {
                            contadorletra++;
                        }
                    }

                    while (contadorletra == 0)
                    {
                        printf("Nome vazio nao permitido! Digite um nome valido:\n");
                        fgets(nomeproduto[i], 60, stdin);

                        contadorletra = 0;
                        for (int k = 0; nomeproduto[i][k] != '\0'; k++)
                        {
                            if (nomeproduto[i][k] == '\n')
                            {
                                nomeproduto[i][k] = '\0';
                            }
                            else if (nomeproduto[i][k] != ' ')
                            {
                                contadorletra++;
                            }
                        }
                    }

                    printf("Digite o preco do produto:\n");
                    scanf("%f", &preco[i]);
                    while (preco[i] <= 0)
                    {
                        printf("Preco invalido, precisa ser maior que 0 reais. Tente novamente:\n");
                        scanf("%f", &preco[i]);
                    }

                    while (getchar() != '\n');

                    printf("Digite a categoria do produto (ex.: Eletronico, Alimento, Vestuario, Outro):\n");
                    fgets(categoria[i], 40, stdin);

                    contadorletra = 0;
                    for (int k = 0; categoria[i][k] != '\0'; k++)
                    {
                        if (categoria[i][k] == '\n')
                        {
                            categoria[i][k] = '\0';
                        }
                        else if (categoria[i][k] != ' ')
                        {
                            contadorletra++;
                        }
                    }

                    while (contadorletra == 0)
                    {
                        printf("Categoria vazia nao permitida! Digite uma categoria valida:\n");
                        fgets(categoria[i], 40, stdin);

                        contadorletra = 0;
                        for (int k = 0; categoria[i][k] != '\0'; k++)
                        {
                            if (categoria[i][k] == '\n')
                            {
                                categoria[i][k] = '\0';
                            }
                            else if (categoria[i][k] != ' ')
                            {
                                contadorletra++;
                            }
                        }
                    }

                    estoque[i] = 0;
                    for (int m = 0; m < 4; m++)
                    {
                        entradas[i][m] = -1;
                    }
                }

                totalCadastrados += Qprodutos;
                printf("\nCadastro concluido com sucesso! Total de produtos no sistema: %d\n", totalCadastrados);
            }
            break;

        case 2:
            if (totalCadastrados == 0)
            {
                printf("Nenhum produto cadastrado ainda! Cadastre produtos na Opcao 1 primeiro.\n");
            }
            else
            {
                printf("Digite o ID do produto que deseja: \n");
                scanf("%d", &idEntrada);
                int pos = -1;
                for (int i = 0; i < totalCadastrados ; i++)
                {
                    if (idproduto[i] == idEntrada)
                    {
                        pos = i;
                    }
                    
                }
                if(pos == -1){
                    printf("O produto solicitado não existe!! ;P\n");
                }
                else
{
    printf("\nRegistrando entradas mensais para: %s\n", nomeproduto[pos]);
    for (int m = 0; m < 4; m++)
    {
        printf("Digite a quantidade de entrada do Mes %d: ", m + 1);
        scanf("%d", &entradas[pos][m]);

        while (entradas[pos][m] < 0)
        {
            printf("Valor invalido! Digite um numero maior ou igual a zero para o Mes %d: ", m + 1);
            scanf("%d", &entradas[pos][m]);
        }
    }
    printf("Entradas mensais atualizadas com sucesso!\n");
}
                
            }
            
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