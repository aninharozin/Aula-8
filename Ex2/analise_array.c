#include <stdio.h>

#define TAM 10

// Fun��o para preencher o array (passagem por refer�ncia)
void preencherArray(int arr[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("N�mero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Fun��o para exibir o array (passagem por valor usando const)
void exibirArray(const int arr[], int tamanho) {
    int i;
    printf("[");
    for (i = 0; i < tamanho; i++) {
        printf("%d", arr[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Fun��o para encontrar o maior valor (passagem por valor)
int maiorValor(const int arr[], int tamanho) {
    int maior = arr[0];
    int i;
    for (i = 1; i < tamanho; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }
    return maior;
}

// Fun��o para encontrar o menor valor (passagem por valor)
int menorValor(const int arr[], int tamanho) {
    int menor = arr[0];
    int i;
    for (i = 1; i < tamanho; i++) {
        if (arr[i] < menor) {
            menor = arr[i];
        }
    }
    return menor;
}

// Fun��o para calcular a m�dia (passagem por valor)
float calcularMedia(const int arr[], int tamanho) {
    int soma = 0;
    int i;
    for (i = 0; i < tamanho; i++) {
        soma += arr[i];
    }
    return (float)soma / tamanho;
}

// Fun��o para ordenar o array em ordem crescente (passagem por refer�ncia)
void ordenarArray(int arr[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int numeros[TAM];

    printf("Digite %d n�meros:\n", TAM);
    preencherArray(numeros, TAM);

    printf("\nArray original: ");
    exibirArray(numeros, TAM);

    printf("Maior valor: %d\n", maiorValor(numeros, TAM));
    printf("Menor valor: %d\n", menorValor(numeros, TAM));
    printf("M�dia: %.2f\n", calcularMedia(numeros, TAM));

    ordenarArray(numeros, TAM);
    printf("Array ordenado: ");
    exibirArray(numeros, TAM);

    return 0;
}

