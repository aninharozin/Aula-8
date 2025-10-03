#include <stdio.h>

#define ALUNOS 5
#define DISCIPLINAS 4

void inserir_notas(float notas[ALUNOS][DISCIPLINAS]) {
    int i, j;
    for (i = 0; i < ALUNOS; i++) {
        printf("Digite as notas do aluno %d:\n", i + 1);
        for (j = 0; j < DISCIPLINAS; j++) {
            if (scanf("%f", &notas[i][j]) != 1) { // validação básica
                printf("Entrada invalida! Zerando nota.\n");
                notas[i][j] = 0;
                while (getchar() != '\n'); // limpa buffer
            }
        }
    }
}

void exibir_notas(const float notas[ALUNOS][DISCIPLINAS]) {
    int i, j;
    printf("\n=== MATRIZ DE NOTAS ===\n");
    for (i = 0; i < ALUNOS; i++) {
        printf("Aluno %d: ", i + 1);
        for (j = 0; j < DISCIPLINAS; j++) {
            printf("%.1f ", notas[i][j]);
        }
        printf("\n");
    }
}

float calcular_media_aluno(const float notas[ALUNOS][DISCIPLINAS], int aluno) {
    int j;
    float soma = 0;
    for (j = 0; j < DISCIPLINAS; j++) {
        soma += notas[aluno][j];
    }
    return soma / DISCIPLINAS;
}

float calcular_media_disciplina(const float notas[ALUNOS][DISCIPLINAS], int disciplina) {
    int i;
    float soma = 0;
    for (i = 0; i < ALUNOS; i++) {
        soma += notas[i][disciplina];
    }
    return soma / ALUNOS;
}

void exibir_relatorio_final(const float notas[ALUNOS][DISCIPLINAS]) {
    int i;
    float media;
    printf("\n=== RELATÓRIO FINAL ===\n");
    for (i = 0; i < ALUNOS; i++) {
        media = calcular_media_aluno(notas, i);
        printf("Aluno %d - Media: %.2f - ", i + 1, media);
        if (media >= 6.0)
            printf("Aprovado\n");
        else
            printf("Reprovado\n");
    }
}


int main(void) {
    float notas[ALUNOS][DISCIPLINAS] = {0};
    int opcao = -1;
    int aluno, disciplina;

    do {
        printf("\n=== SISTEMA DE GESTAO DE NOTAS ===\n");
        printf("1. Inserir notas\n");
        printf("2. Exibir notas\n");
        printf("3. Calcular media de um aluno\n");
        printf("4. Calcular media de uma disciplina\n");
        printf("5. Exibir relatorio final\n");
        printf("0. Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) { // validação de entrada
            printf("Entrada invalida!\n");
            while (getchar() != '\n'); //limpa buffer
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                inserir_notas(notas);
                break;
            case 2:
                exibir_notas(notas);
                break;
            case 3:
                printf("Digite o numero do aluno (1-%d): ", ALUNOS);
                if (scanf("%d", &aluno) == 1 && aluno >= 1 && aluno <= ALUNOS) {
                    printf("Media do aluno %d: %.2f\n", aluno, calcular_media_aluno(notas, aluno - 1));
                } else {
                    printf("Aluno invalido!\n");
                    while (getchar() != '\n'); // limpa buffer
                }
                break;
            case 4:
                printf("Digite o numero da disciplina (1-%d): ", DISCIPLINAS);
                if (scanf("%d", &disciplina) == 1 && disciplina >= 1 && disciplina <= DISCIPLINAS) {
                    printf("Media da disciplina %d: %.2f\n", disciplina, calcular_media_disciplina(notas, disciplina - 1));
                } else {
                    printf("Disciplina invalida!\n");
                    while (getchar() != '\n'); // limpa buffer
                }
                break;
            case 5:
                exibir_relatorio_final(notas);
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

