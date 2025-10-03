#include <stdio.h>

// Exibir o menu
void exibirMenu() {
    printf("\n=== CALCULADORA ===\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("0. Sair\n");
}

int obterOpcao() {
    int opcao;
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// passagem por referência
void obterNumeros(float *a, float *b) {
    printf("Digite o primeiro numero: ");
    scanf("%f", a);
    printf("Digite o segundo numero: ");
    scanf("%f", b);
}

// Funções matemáticas (passagem por valor)
float somar(float x, float y) {
    return x + y;
}

float subtrair(float x, float y) {
    return x - y;
}

float multiplicar(float x, float y) {
    return x * y;
}

float dividir(float x, float y) {
    if (y == 0) {
        printf("Erro: divisao por zero!\n");
        return 0; // valor neutro
    }
    return x / y;
}

void exibirResultado(float resultado) {
    printf("Resultado: %.2f\n", resultado);
}

// Programa principal
int main() {
    int opcao;
    float num1, num2, resultado;

    do {
        exibirMenu();
        opcao = obterOpcao();

        switch (opcao) {
            case 1:
                obterNumeros(&num1, &num2);
                resultado = somar(num1, num2);
                exibirResultado(resultado);
                break;
            case 2:
                obterNumeros(&num1, &num2);
                resultado = subtrair(num1, num2);
                exibirResultado(resultado);
                break;
            case 3:
                obterNumeros(&num1, &num2);
                resultado = multiplicar(num1, num2);
                exibirResultado(resultado);
                break;
            case 4:
                obterNumeros(&num1, &num2);
                resultado = dividir(num1, num2);
                if (num2 != 0) { // só mostra se não for divisão por zero
                    exibirResultado(resultado);
                }
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

