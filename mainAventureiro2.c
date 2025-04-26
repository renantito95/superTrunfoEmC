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
    int escolha;

    // Cadastro fixo para simplificação
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

    // Cálculo da densidade populacional e PIB per capita
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;

    // Menu Interativo
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção: ");
    scanf("%d", &escolha);

    printf("\n");

    // Switch para escolher o atributo
    switch (escolha) {
        case 1:
            printf("Comparação de População:\n");
            printf("%s (%s): %lu habitantes\n", carta1.cidade, carta1.estado, carta1.populacao);
            printf("%s (%s): %lu habitantes\n", carta2.cidade, carta2.estado, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Comparação de Área:\n");
            printf("%s (%s): %.2f km²\n", carta1.cidade, carta1.estado, carta1.area);
            printf("%s (%s): %.2f km²\n", carta2.cidade, carta2.estado, carta2.area);

            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("Comparação de PIB:\n");
            printf("%s (%s): %.2f bilhões de reais\n", carta1.cidade, carta1.estado, carta1.pib);
            printf("%s (%s): %.2f bilhões de reais\n", carta2.cidade, carta2.estado, carta2.pib);

            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Comparação de Pontos Turísticos:\n");
            printf("%s (%s): %d pontos turísticos\n", carta1.cidade, carta1.estado, carta1.pontosTuristicos);
            printf("%s (%s): %d pontos turísticos\n", carta2.cidade, carta2.estado, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Comparação de Densidade Demográfica:\n");
            printf("%s (%s): %.2f hab/km²\n", carta1.cidade, carta1.estado, carta1.densidadePopulacional);
            printf("%s (%s): %.2f hab/km²\n", carta2.cidade, carta2.estado, carta2.densidadePopulacional);

            if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
                printf("Resultado: %s venceu!\n", carta1.cidade);
            } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
                printf("Resultado: %s venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Por favor, escolha um número entre 1 e 5.\n");
            break;
    }

    return 0;
}
