#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[30];
    char codigo[10];
    char cidade[50];
    unsigned long int populacao; // agora é unsigned long int
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

int main() {
    struct Carta carta1;
    struct Carta carta2;

    // Entrada de dados para a primeira carta
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

    // Entrada de dados para a segunda carta
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

    // Cálculos da densidade populacional e PIB per capita
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;

    // Cálculo do Super Poder
    carta1.superPoder = (float)carta1.populacao + carta1.area + (carta1.pib * 1000000000) + carta1.pontosTuristicos + carta1.pibPerCapita + (1 / carta1.densidadePopulacional);
    carta2.superPoder = (float)carta2.populacao + carta2.area + (carta2.pib * 1000000000) + carta2.pontosTuristicos + carta2.pibPerCapita + (1 / carta2.densidadePopulacional);

    // Exibição das cartas (informativo para o jogador)
    printf("Carta 1:\n");
    printf("Estado: %s\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.cidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Número de Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);
    printf("Super Poder: %.2f\n", carta1.superPoder);

    printf("\n");

    printf("Carta 2:\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.cidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Número de Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pibPerCapita);
    printf("Super Poder: %.2f\n", carta2.superPoder);

    printf("\n");

    // Comparações dos atributos
    printf("Comparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", carta1.populacao > carta2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", carta1.area > carta2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta1.pib > carta2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", carta1.pontosTuristicos > carta2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", carta1.densidadePopulacional < carta2.densidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", carta1.pibPerCapita > carta2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", carta1.superPoder > carta2.superPoder);

    return 0;
}
