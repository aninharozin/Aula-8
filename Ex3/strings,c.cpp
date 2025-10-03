#include <stdio.h>
#include <string.h>

#define TAM 100

// Função para ler uma string do usuário
void lerString(char *str, int tamanho) {
    printf("Digite uma string: ");
    fgets(str, tamanho, stdin);

    // Remove o '\n' do final se existir
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Função para contar caracteres (passagem por valor)
int contarCaracteres(const char *str) {
    return strlen(str);
}

// Função para inverter string in-place (passagem por referência)
void inverterString(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Função para converter para maiúscula in-place (passagem por referência)
void converterMaiuscula(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // diferença entre 'a' e 'A'
        }
    }
}

// Função para converter para minúscula in-place (passagem por referência)
void converterMinuscula(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // diferença entre 'A' e 'a'
        }
    }
}

// Função para contar número de palavras (passagem por valor)
int contarPalavras(const char *str) {
    int i = 0, palavras = 0;
    int dentroPalavra = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && dentroPalavra == 0) {
            palavras++;
            dentroPalavra = 1;
        } else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            dentroPalavra = 0;
        }
        i++;
    }
    return palavras;
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n=== MANIPULADOR DE STRINGS ===\n");
    printf("1. Contar caracteres\n");
    printf("2. Inverter string\n");
    printf("3. Converter maiuscula\n");
    printf("4. Converter minuscula\n");
    printf("5. Contar palavras\n");
    printf("0. Sair\n");
    printf("Opcao: ");
}

int main() {
    char texto[TAM];
    int opcao;
    int caracteres, palavras;

    lerString(texto, TAM);

    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // consumir o \n deixado pelo scanf

        switch (opcao) {
            case 1:
                caracteres = contarCaracteres(texto);
                printf("A string possui %d caracteres.\n", caracteres);
                break;
            case 2:
                inverterString(texto);
                printf("String invertida: %s\n", texto);
                break;
            case 3:
                converterMaiuscula(texto);
                printf("String em maiusculas: %s\n", texto);
                break;
            case 4:
                converterMinuscula(texto);
                printf("String em minusculas: %s\n", texto);
                break;
            case 5:
                palavras = contarPalavras(texto);
                printf("A string possui %d palavras.\n", palavras);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

