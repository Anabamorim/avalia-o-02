#include <stdio.h>

int validaQuantidade();
float calculaSalario(int quantidade);

// Função principal
int main() {
    int quantidade;
    char continuar;

    do {
       
        quantidade = validaQuantidade();

        calculaSalario(quantidade);

        printf("\nDeseja calcular o salário para outro funcionário? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}

int validaQuantidade() {
    int quantidade;

    do {
        printf("Digite a quantidade de peças fabricadas: ");
        scanf("%d", &quantidade);

        if (quantidade < 0) {
            printf("Quantidade inválida. Por favor, digite um valor não negativo.\n");
        }

    } while (quantidade < 0);

    return quantidade;
}

float calculaSalario(int quantidade) {
    const float salarioBase = 600.0;
    const float adicionalBaixo = 0.50;
    const float adicionalAlto = 0.75;
    const int limiteBaixo = 50;
    const int limiteAlto = 80;

    float salarioTotal = salarioBase;

    if (quantidade > limiteBaixo) {
        salarioTotal += (quantidade - limiteBaixo) * adicionalBaixo;

        if (quantidade > limiteAlto) {
            salarioTotal += (quantidade - limiteAlto) * (adicionalAlto - adicionalBaixo);
        }
    }

    printf("Salário total: R$ %.2f\n", salarioTotal);

    return salarioTotal;
}
