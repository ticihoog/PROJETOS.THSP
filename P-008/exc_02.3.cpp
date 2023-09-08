#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALUNOS 15

int main() {
    float notas_1[NUM_ALUNOS];
    float notas_2[NUM_ALUNOS];
    float media[NUM_ALUNOS];

    // Inicialize a semente para a função rand()
    srand(time(NULL));

    // Preencha o primeiro array com as notas da primeira avaliação
    printf("Notas da primeira avaliacao:\n");
    for (int i = 0; i < NUM_ALUNOS; ++i) {
        notas_1[i] = ((float)rand() / RAND_MAX) * 10.0;
        printf("Aluno %d: %.2f\n", i + 1, notas_1[i]);
    }

    // Preencha o segundo array com as notas da segunda avaliação
    printf("\nNotas da segunda avaliacao:\n");
    for (int i = 0; i < NUM_ALUNOS; ++i) {
        notas_2[i] = ((float)rand() / RAND_MAX) * 10.0;
        printf("Aluno %d: %.2f\n", i + 1, notas_2[i]);
    }

    // Compare as notas de cada aluno na segunda avaliação em relação à primeira
    printf("\nComparacao de notas:\n");
    for (int i = 0; i < NUM_ALUNOS; ++i) {
        if (notas_2[i] > notas_1[i]) {
            printf("Aluno %d: Melhorou\n", i + 1);
        } else if (notas_2[i] < notas_1[i]) {
            printf("Aluno %d: Piorou\n", i + 1);
        } else {
            printf("Aluno %d: Manteve a nota\n", i + 1);
        }

        // Calcule a média das notas das duas avaliações para cada aluno
        media[i] = (notas_1[i] + notas_2[i]) / 2.0;
    }

    // Imprima a média de cada aluno nas duas avaliações
    printf("\nMedia das notas:\n");
    for (int i = 0; i < NUM_ALUNOS; ++i) {
        printf("Aluno %d: %.2f\n", i + 1, media[i]);
    }

    return 0;
}
