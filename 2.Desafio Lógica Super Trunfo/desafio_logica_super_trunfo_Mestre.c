#include <stdio.h>
#include <string.h>

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
    printf("\nComparação de Cartas - Nível Mestre:\n");

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

    // Variáveis para escolhas dos atributos
    int opcao1, opcao2;
    float valor1_atr1, valor2_atr1, valor1_atr2, valor2_atr2;
    char atributo1[30], atributo2[30];
    float soma1, soma2;

    // Primeiro menu interativo para escolher o primeiro atributo
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção (1-5): ");
    scanf("%d", &opcao1);

    // Atribui o primeiro valor com base na escolha
    switch (opcao1) {
        case 1:
            valor1_atr1 = populacoes[estado1][cidade1];
            valor2_atr1 = populacoes[estado2][cidade2];
            strcpy(atributo1, "População");
            break;
        case 2:
            valor1_atr1 = areas[estado1][cidade1];
            valor2_atr1 = areas[estado2][cidade2];
            strcpy(atributo1, "Área");
            break;
        case 3:
            valor1_atr1 = PIBs[estado1][cidade1];
            valor2_atr1 = PIBs[estado2][cidade2];
            strcpy(atributo1, "PIB");
            break;
        case 4:
            valor1_atr1 = pontos_turisticos_por_cidade[estado1][cidade1];
            valor2_atr1 = pontos_turisticos_por_cidade[estado2][cidade2];
            strcpy(atributo1, "Número de Pontos Turísticos");
            break;
        case 5:
            valor1_atr1 = densidades_populacionais[estado1][cidade1];
            valor2_atr1 = densidades_populacionais[estado2][cidade2];
            strcpy(atributo1, "Densidade Demográfica");
            break;
        default:
            printf("Opção inválida para o primeiro atributo!\n");
            return 1;
    }

    // Segundo menu interativo (dinâmico) para escolher o segundo atributo
    printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1) { // Exclui a opção já escolhida
            switch (i) {
                case 1: printf("%d - População\n", i); break;
                case 2: printf("%d - Área\n", i); break;
                case 3: printf("%d - PIB\n", i); break;
                case 4: printf("%d - Número de Pontos Turísticos\n", i); break;
                case 5: printf("%d - Densidade Demográfica\n", i); break;
            }
        }
    }
    printf("Digite sua opção: ");
    scanf("%d", &opcao2);

    // Verifica se o segundo atributo é igual ao primeiro
    if (opcao2 == opcao1) {
        printf("Erro: O segundo atributo deve ser diferente do primeiro!\n");
        return 1;
    }

    // Atribui o segundo valor com base na escolha
    switch (opcao2) {
        case 1:
            valor1_atr2 = populacoes[estado1][cidade1];
            valor2_atr2 = populacoes[estado2][cidade2];
            strcpy(atributo2, "População");
            break;
        case 2:
            valor1_atr2 = areas[estado1][cidade1];
            valor2_atr2 = areas[estado2][cidade2];
            strcpy(atributo2, "Área");
            break;
        case 3:
            valor1_atr2 = PIBs[estado1][cidade1];
            valor2_atr2 = PIBs[estado2][cidade2];
            strcpy(atributo2, "PIB");
            break;
        case 4:
            valor1_atr2 = pontos_turisticos_por_cidade[estado1][cidade1];
            valor2_atr2 = pontos_turisticos_por_cidade[estado2][cidade2];
            strcpy(atributo2, "Número de Pontos Turísticos");
            break;
        case 5:
            valor1_atr2 = densidades_populacionais[estado1][cidade1];
            valor2_atr2 = densidades_populacionais[estado2][cidade2];
            strcpy(atributo2, "Densidade Demográfica");
            break;
        default:
            printf("Opção inválida para o segundo atributo!\n");
            return 1;
    }

    // Normaliza Densidade Demográfica (inverte para maior valor vencer)
    if (opcao1 == 5) {
        valor1_atr1 = 1 / valor1_atr1; // Inverte para que maior valor seja "melhor"
        valor2_atr1 = 1 / valor2_atr1;
    }
    if (opcao2 == 5) {
        valor1_atr2 = 1 / valor2_atr2;
        valor2_atr2 = 1 / valor2_atr2;
    }

    // Calcula as somas usando operador ternário
    soma1 = valor1_atr1 + valor1_atr2;
    soma2 = valor2_atr1 + valor2_atr2;

    // Exibe os resultados
    printf("\nResultados da Comparação:\n");
    printf("Carta %s:\n", codigo1);
    printf("  %s: %.2f\n", atributo1, opcao1 == 5 ? 1/valor1_atr1 : valor1_atr1); // Reverte se densidade
    printf("  %s: %.2f\n", atributo2, opcao2 == 5 ? 1/valor1_atr2 : valor1_atr2);
    printf("  Soma dos atributos: %.2f\n", soma1);

    printf("Carta %s:\n", codigo2);
    printf("  %s: %.2f\n", atributo1, opcao1 == 5 ? 1/valor2_atr1 : valor2_atr1);
    printf("  %s: %.2f\n", atributo2, opcao2 == 5 ? 1/valor2_atr2 : valor2_atr2);
    printf("  Soma dos atributos: %.2f\n", soma2);

    // Determina o vencedor com operador ternário e if-else
    char* resultado = (soma1 > soma2) ? codigo1 : (soma2 > soma1) ? codigo2 : "Empate!";
    printf("\nResultado final: %s\n", strcmp(resultado, "Empate!") == 0 ? "Empate!" : resultado);

    return 0;
}