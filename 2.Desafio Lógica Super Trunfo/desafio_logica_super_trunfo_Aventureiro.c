#include <stdio.h>

int main() {
    // Definindo o número de estados e cidades por estado
    int num_estados = 2; // Estados A e B
    int num_cidades_por_estado = 4; // 4 cidades por estado

    // Matriz para armazenar os dados de todas as cidades
    char codigos[8][4]; // Códigos das cartas (ex: A01, B02)
    int populacoes[8][4];
    float areas[8][4];
    float PIBs[8][4];
    int pontos_turisticos_por_cidade[8][4];
    float densidades_populacionais[8][4];
    float PIBs_per_capita[8][4];

    // Variáveis temporárias para entrada de dados
    char codigo[4];
    int populacao;
    float area, PIB;
    int pontos_turisticos;

    // Mensagem de boas-vindas
    printf("Bem-vindo ao cadastro de cartas do Super Trunfo!\n");

    // Loop para cadastrar as cidades de cada estado
    for (int estado = 0; estado < num_estados; estado++) {
        for (int cidade = 0; cidade < num_cidades_por_estado; cidade++) {
            // Gera o código da carta automaticamente
            codigo[0] = 'A' + estado;
            codigo[1] = '0' + (cidade + 1) / 10;
            codigo[2] = '0' + (cidade + 1) % 10;
            codigo[3] = '\0';

            // Solicita os dados da cidade ao usuário
            printf("\nCadastrando cidade %s:\n", codigo);
            printf("Digite a população da cidade: ");
            scanf("%d", &populacao);
            printf("Digite a área da cidade (em km²): ");
            scanf("%f", &area);
            printf("Digite o PIB da cidade (em milhões): ");
            scanf("%f", &PIB);
            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &pontos_turisticos);

            // Calcula propriedades derivadas
            float densidade_populacional = (float)populacao / area;
            float PIB_per_capita = (PIB * 1000000) / populacao;

            // Armazena os dados na matriz
            for (int i = 0; i < 4; i++) {
                codigos[estado][i] = codigo[i];
            }
            populacoes[estado][cidade] = populacao;
            areas[estado][cidade] = area;
            PIBs[estado][cidade] = PIB;
            pontos_turisticos_por_cidade[estado][cidade] = pontos_turisticos;
            densidades_populacionais[estado][cidade] = densidade_populacional;
            PIBs_per_capita[estado][cidade] = PIB_per_capita;
        }
    }

    // Comparação de cartas escolhidas pelo usuário
    printf("\nComparação de Cartas:\n");

    char codigo1[4], codigo2[4];
    int estado1, cidade1, estado2, cidade2;

    // Solicita os códigos das cartas a serem comparadas
    printf("Digite o código da primeira carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o código da segunda carta (ex: B02): ");
    scanf("%s", codigo2);

    // Converte os códigos das cartas em índices da matriz
    estado1 = codigo1[0] - 'A';
    cidade1 = (codigo1[1] - '0') * 10 + (codigo1[2] - '0') - 1;
    estado2 = codigo2[0] - 'A';
    cidade2 = (codigo2[1] - '0') * 10 + (codigo2[2] - '0') - 1;

    // Verifica se os índices são válidos
    if (estado1 < 0 || estado1 >= num_estados || cidade1 < 0 || cidade1 >= num_cidades_por_estado ||
        estado2 < 0 || estado2 >= num_estados || cidade2 < 0 || cidade2 >= num_cidades_por_estado) {
        printf("Erro: Uma ou ambas as cartas não existem!\n");
        return 1;
    }

    // Menu interativo para escolha do atributo
    int opcao;
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção (1-5): ");
    scanf("%d", &opcao);

    // Variáveis para armazenar os valores a serem comparados
    float valor1, valor2;
    char atributo[30];

    // Lógica de comparação com switch
    switch (opcao) {
        case 1: // População
            valor1 = populacoes[estado1][cidade1];
            valor2 = populacoes[estado2][cidade2];
            sprintf(atributo, "População");
            printf("\nComparando por %s:\n", atributo);
            printf("%s: %d habitantes\n", codigo1, (int)valor1);
            printf("%s: %d habitantes\n", codigo2, (int)valor2);
            if (valor1 > valor2) {
                printf("Resultado: Carta %s vence com maior %s!\n", codigo1, atributo);
            } else if (valor1 < valor2) {
                printf("Resultado: Carta %s vence com maior %s!\n", codigo2, atributo);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            valor1 = areas[estado1][cidade1];
            valor2 = areas[estado2][cidade2];
            sprintf(atributo, "Área");
            printf("\nComparando por %s:\n", atributo);
            printf("%s: %.2f km²\n", codigo1, valor1);
            printf("%s: %.2f km²\n", codigo2, valor2);
            if (valor1 > valor2) {
                printf("Resultado: Carta %s vence com maior %s!\n", codigo1, atributo);
            } else if (valor1 < valor2) {
                printf("Resultado: Carta %s vence com maior %s!\n", codigo2, atributo);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            valor1 = PIBs[estado1][cidade1];
            valor2 = PIBs[estado2][cidade2];
            sprintf(atributo, "PIB");
            printf("\nComparando por %s:\n", atributo);
            printf("%s: %.2f milhões\n", codigo1, valor1);
            printf("%s: %.2f milhões\n", codigo2, valor2);
            if (valor1 > valor2) {
                printf("Resultado: Carta %s vence com maior %s!\n", codigo1, atributo);
            } else if (valor1 < valor2) {
                printf("Resultado: Carta %s vence com maior %s!\n", codigo2, atributo);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Número de Pontos Turísticos
            valor1 = pontos_turisticos_por_cidade[estado1][cidade1];
            valor2 = pontos_turisticos_por_cidade[estado2][cidade2];
            sprintf(atributo, "Número de Pontos Turísticos");
            printf("\nComparando por %s:\n", atributo);
            printf("%s: %d pontos\n", codigo1, (int)valor1);
            printf("%s: %d pontos\n", codigo2, (int)valor2);
            if (valor1 > valor2) {
                printf("Resultado: Carta %s vence com maior %s!\n", codigo1, atributo);
            } else if (valor1 < valor2) {
                printf("Resultado: Carta %s vence com maior %s!\n", codigo2, atributo);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (menor valor vence)
            valor1 = densidades_populacionais[estado1][cidade1];
            valor2 = densidades_populacionais[estado2][cidade2];
            sprintf(atributo, "Densidade Demográfica");
            printf("\nComparando por %s:\n", atributo);
            printf("%s: %.2f hab/km²\n", codigo1, valor1);
            printf("%s: %.2f hab/km²\n", codigo2, valor2);
            if (valor1 < valor2) {
                printf("Resultado: Carta %s vence com menor %s!\n", codigo1, atributo);
            } else if (valor1 > valor2) {
                printf("Resultado: Carta %s vence com menor %s!\n", codigo2, atributo);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Escolha um número entre 1 e 5.\n");
            return 1;
    }

    return 0;
}