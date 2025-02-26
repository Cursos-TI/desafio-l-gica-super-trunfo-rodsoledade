#include <stdio.h>

int main() {
    // Definindo o número de estados e cidades por estado
    int num_estados = 8; // Estados A e B
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
            printf("Digite a populacao da cidade: ");
            scanf("%d", &populacao);
            printf("Digite a area da cidade (em km²): ");
            scanf("%f", &area);
            printf("Digite o PIB da cidade (em milhoes): ");
            scanf("%f", &PIB);
            printf("Digite o numero de pontos turisticos: ");
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

    // Exibe os dados de todas as cidades cadastradas
    printf("\nDados de todas as cidades cadastradas:\n");
    for (int estado = 0; estado < num_estados; estado++) {
        for (int cidade = 0; cidade < num_cidades_por_estado; cidade++) {
            codigo[0] = 'A' + estado;
            codigo[1] = '0' + (cidade + 1) / 10;
            codigo[2] = '0' + (cidade + 1) % 10;
            codigo[3] = '\0';

            printf("\nCidade %s:\n", codigo);
            printf("Populacao: %d habitantes\n", populacoes[estado][cidade]);
            printf("Area: %.2f km²\n", areas[estado][cidade]);
            printf("PIB: %.2f milhoes\n", PIBs[estado][cidade]);
            printf("Pontos Turisticos: %d\n", pontos_turisticos_por_cidade[estado][cidade]);
            printf("Densidade Populacional: %.2f hab/km²\n", densidades_populacionais[estado][cidade]);
            printf("PIB per Capita: %.2f\n", PIBs_per_capita[estado][cidade]);
        }
    }

    // Comparação de cartas escolhidas pelo usuário
    printf("\nComparacao de Cartas:\n");

    char codigo1[4], codigo2[4];
    int estado1, cidade1, estado2, cidade2;

    // Solicita os códigos das cartas a serem comparadas
    printf("Digite o codigo da primeira carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o codigo da segunda carta (ex: B02): ");
    scanf("%s", codigo2);

    // Converte os códigos das cartas em índices da matriz
    estado1 = codigo1[0] - 'A';
    cidade1 = (codigo1[1] - '0') * 10 + (codigo1[2] - '0') - 1;
    estado2 = codigo2[0] - 'A';
    cidade2 = (codigo2[1] - '0') * 10 + (codigo2[2] - '0') - 1;

    // Verifica se os índices são válidos
    if (estado1 < 0 || estado1 >= num_estados || cidade1 < 0 || cidade1 >= num_cidades_por_estado ||
        estado2 < 0 || estado2 >= num_estados || cidade2 < 0 || cidade2 >= num_cidades_por_estado) {
        printf("Erro: Uma ou ambas as cartas nao existem!\n");
        return 1;
    }

    // Exibe os dados das cartas selecionadas
    printf("\nCarta %s:\n", codigo1);
    printf("Populacao: %d habitantes\n", populacoes[estado1][cidade1]);
    printf("Area: %.2f km²\n", areas[estado1][cidade1]);
    printf("PIB: %.2f milhoes\n", PIBs[estado1][cidade1]);
    printf("Pontos Turisticos: %d\n", pontos_turisticos_por_cidade[estado1][cidade1]);
    printf("Densidade Populacional: %.2f hab/km²\n", densidades_populacionais[estado1][cidade1]);
    printf("PIB per Capita: %.2f\n", PIBs_per_capita[estado1][cidade1]);

    printf("\nCarta %s:\n", codigo2);
    printf("Populacao: %d habitantes\n", populacoes[estado2][cidade2]);
    printf("Area: %.2f km²\n", areas[estado2][cidade2]);
    printf("PIB: %.2f milhoes\n", PIBs[estado2][cidade2]);
    printf("Pontos Turisticos: %d\n", pontos_turisticos_por_cidade[estado2][cidade2]);
    printf("Densidade Populacional: %.2f hab/km²\n", densidades_populacionais[estado2][cidade2]);
    printf("PIB per Capita: %.2f\n", PIBs_per_capita[estado2][cidade2]);

    // Comparação usando o atributo PIB (maior valor vence)
    printf("\nComparando por PIB:\n");
    printf("%s: %.2f milhoes\n", codigo1, PIBs[estado1][cidade1]);
    printf("%s: %.2f milhoes\n", codigo2, PIBs[estado2][cidade2]);

    // Lógica de decisão para determinar a vencedora
    if (PIBs[estado1][cidade1] > PIBs[estado2][cidade2]) {
        printf("Resultado: Carta %s vence com maior PIB!\n", codigo1);
    } else if (PIBs[estado1][cidade1] < PIBs[estado2][cidade2]) {
        printf("Resultado: Carta %s vence com maior PIB!\n", codigo2);
    } else {
        printf("Resultado: Empate em PIB!\n");
    }

    return 0;
}