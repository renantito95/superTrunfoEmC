#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[30];
    char codigo[10];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    struct Carta carta1;
    struct Carta carta2;
    int escolha1, escolha2;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    float somaCarta1 = 0, somaCarta2 = 0;

    // Cadastro fixo
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código da Carta: ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.cidade);
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    printf("\n");

    printf("Digite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código da Carta: ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.cidade);
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    printf("\n");

    // calculo da densidade populacional e PIB per capita
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;

    // menu interativo , escolha do primeiro atributo
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção: ");
    scanf("%d", &escolha1);

    if (escolha1 < 1 || escolha1 > 5) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 1;
    }

    // menu interativo, escolha do segundo atributo
    printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != escolha1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Número de Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }
    printf("Digite a opção: ");
    scanf("%d", &escolha2);

    if (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 1;
    }

    printf("\n");

    // funçao para buscar valor do primeiro atributo
    switch (escolha1) {
        case 1:
            valor1_carta1 = (float)carta1.populacao;
            valor1_carta2 = (float)carta2.populacao;
            printf("População:\n");
            break;
        case 2:
            valor1_carta1 = carta1.area;
            valor1_carta2 = carta2.area;
            printf("Área:\n");
            break;
        case 3:
            valor1_carta1 = carta1.pib;
            valor1_carta2 = carta2.pib;
            printf("PIB:\n");
            break;
        case 4:
            valor1_carta1 = (float)carta1.pontosTuristicos;
            valor1_carta2 = (float)carta2.pontosTuristicos;
            printf("Número de Pontos Turísticos:\n");
            break;
        case 5:
            valor1_carta1 = carta1.densidadePopulacional;
            valor1_carta2 = carta2.densidadePopulacional;
            printf("Densidade Demográfica:\n");
            break;
        default:
            printf("Erro ao selecionar atributo!\n");
            return 1;
    }
    printf("%s (%s): %.2f\n", carta1.cidade, carta1.estado, valor1_carta1);
    printf("%s (%s): %.2f\n\n", carta2.cidade, carta2.estado, valor1_carta2);

    // funçao para buscar valor do segundo atributo
    switch (escolha2) {
        case 1:
            valor2_carta1 = (float)carta1.populacao;
            valor2_carta2 = (float)carta2.populacao;
            printf("População:\n");
            break;
        case 2:
            valor2_carta1 = carta1.area;
            valor2_carta2 = carta2.area;
            printf("Área:\n");
            break;
        case 3:
            valor2_carta1 = carta1.pib;
            valor2_carta2 = carta2.pib;
            printf("PIB:\n");
            break;
        case 4:
            valor2_carta1 = (float)carta1.pontosTuristicos;
            valor2_carta2 = (float)carta2.pontosTuristicos;
            printf("Número de Pontos Turísticos:\n");
            break;
        case 5:
            valor2_carta1 = carta1.densidadePopulacional;
            valor2_carta2 = carta2.densidadePopulacional;
            printf("Densidade Demográfica:\n");
            break;
        default:
            printf("Erro ao selecionar atributo!\n");
            return 1;
    }
    printf("%s (%s): %.2f\n", carta1.cidade, carta1.estado, valor2_carta1);
    printf("%s (%s): %.2f\n\n", carta2.cidade, carta2.estado, valor2_carta2);

    // plicando a regra de comparação por atributo
    // para densidade demográfica, vence o menor, nos outros vence o maior

    float pontosCarta1 = 0, pontosCarta2 = 0;

    // primeiro atributo
    if (escolha1 == 5) { // densidade
        pontosCarta1 += (valor1_carta1 < valor1_carta2) ? 1 : (valor1_carta2 < valor1_carta1) ? 0 : 0;
        pontosCarta2 += (valor1_carta2 < valor1_carta1) ? 1 : (valor1_carta1 < valor1_carta2) ? 0 : 0;
    } else {
        pontosCarta1 += (valor1_carta1 > valor1_carta2) ? 1 : (valor1_carta2 > valor1_carta1) ? 0 : 0;
        pontosCarta2 += (valor1_carta2 > valor1_carta1) ? 1 : (valor1_carta1 > valor1_carta2) ? 0 : 0;
    }

    // segundo atributo
    if (escolha2 == 5) { // densidade
        pontosCarta1 += (valor2_carta1 < valor2_carta2) ? 1 : (valor2_carta2 < valor2_carta1) ? 0 : 0;
        pontosCarta2 += (valor2_carta2 < valor2_carta1) ? 1 : (valor2_carta1 < valor2_carta2) ? 0 : 0;
    } else {
        pontosCarta1 += (valor2_carta1 > valor2_carta2) ? 1 : (valor2_carta2 > valor2_carta1) ? 0 : 0;
        pontosCarta2 += (valor2_carta2 > valor2_carta1) ? 1 : (valor2_carta1 > valor2_carta2) ? 0 : 0;
    }

    // soma dos valores
    somaCarta1 = valor1_carta1 + valor2_carta1;
    somaCarta2 = valor1_carta2 + valor2_carta2;

    // exibindo resultados
    printf("\nSoma dos atributos:\n");
    printf("%s (%s): %.2f\n", carta1.cidade, carta1.estado, somaCarta1);
    printf("%s (%s): %.2f\n", carta2.cidade, carta2.estado, somaCarta2);

    if (somaCarta1 > somaCarta2) {
        printf("Resultado: %s venceu!\n", carta1.cidade);
    } else if (somaCarta2 > somaCarta1) {
        printf("Resultado: %s venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
