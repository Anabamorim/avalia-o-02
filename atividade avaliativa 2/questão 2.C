#include <stdio.h>
#include <stdlib.h>

char validaSexo() {
    char sexo;
    do {
        printf("Informe o sexo (M/F): ");
        scanf(" %s", &sexo);
        if (sexo != 'M' && sexo != 'F') {
            printf("Sexo inválido. Informe M para masculino ou F para feminino.\n");
        }
    } while (sexo != 'M' && sexo != 'F');
    return sexo;
}

float validaSalario() {
    float salario;
    do {
        printf("Informe o salário (maior que R$1,00): ");
        scanf("%f", &salario);
        if (salario <= 1.00) {
            printf("Salário inválido. Deve ser maior que R$1,00.\n");
        }
    } while (salario <= 1.00);
    return salario;
}

char classificaSalario(float salario) {
    if (salario > 1400.00) {
        return 'A'; // Acima do salário mínimo
    } else if (salario == 1400.00) {
        return 'I'; // Igual ao salário mínimo
    } else {
        return 'B'; // Abaixo do salário mínimo
    }
}

void mostraClassificacao(char sexo, float salario, char classificacao) {
    printf("\nResultados para o assalariado:\n");
    printf("Sexo: %s\n", (sexo == 'M') ? "Masculino" : "Feminino");
    printf("Salário: R$%.2f\n", salario);

    switch (classificacao) {
        case 'A':
            printf("Classificação em relação ao salário mínimo: Acima do salário mínimo\n");
            break;
        case 'I':
            printf("Classificação em relação ao salário mínimo: Igual ao salário mínimo\n");
            break;
        case 'B':
            printf("Classificação em relação ao salário mínimo: Abaixo do salário mínimo\n");
            break;
    }
}

int main() {
    int numAssalariados;
    int abaixoSalarioMinimo = 0;
    int acimaSalarioMinimo = 0;

    printf("Informe o número de assalariados a serem pesquisados: ");
    scanf("%d", &numAssalariados);

    for (int i = 1; i <= numAssalariados; i++) {
        printf("\nDados para o assalariado %d:\n", i);

        char sexo = validaSexo();
        float salario = validaSalario();
        char classificacao = classificaSalario(salario);

        mostraClassificacao(sexo, salario, classificacao);

        
        if (classificacao == 'A') {
            acimaSalarioMinimo++;
        } else if (classificacao == 'B') {
            abaixoSalarioMinimo++;
        }
    }

    printf("\nResultados Finais:\n");
    printf("Assalariados abaixo do salário mínimo: %d\n", abaixoSalarioMinimo);
    printf("Assalariados acima do salário mínimo: %d\n", acimaSalarioMinimo);

    return 0;
}
