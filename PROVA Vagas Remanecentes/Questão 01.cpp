#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATOS 20
#define MAX_PARTIDOS 4


void lerNomeCandidato(char nomeCandidato[MAX_CANDIDATOS][50], int i) {
    printf("Informe o nome do CANDIDATO %d: ", i + 1);
    scanf("%s", nomeCandidato[i]);
}


void lerPartido(char partido[MAX_CANDIDATOS][20], int i) {
    printf("Informe o NOME DO PARTIDO do candidato %d: ", i + 1);
    scanf("%s", partido[i]);
}


void lerVotos(int votos[MAX_CANDIDATOS], int i) {
    printf("Informe a QUANTIDADE DE VOTOS para este candidato %d: ", i + 1);
    scanf("%d", &votos[i]);
    printf("---------------------------------------------------------------\n");
}


float calcularCoeficienteEleitoral(int votos[MAX_CANDIDATOS], int numCandidatos) {
    int totalVotos = 0;
    for (int i = 0; i < numCandidatos; i++) {
        totalVotos += votos[i];
    }
    return (float)totalVotos / 7.0; 
}


void calcularVotosPorPartido(char partido[MAX_CANDIDATOS][20], int votos[MAX_CANDIDATOS], int numCandidatos, int votosPorPartido[MAX_PARTIDOS]) {
    memset(votosPorPartido, 0, sizeof(votosPorPartido));

    for (int i = 0; i < numCandidatos; i++) {
        for (int j = 0; j < MAX_PARTIDOS; j++) {
            if (strcmp(partido[i], partido[j]) == 0) {
                votosPorPartido[j] += votos[i];
                break;
            }
        }
    }
}


void imprimirCoeficientesEleitorais(char partido[MAX_PARTIDOS][20], int votosPorPartido[MAX_PARTIDOS], float coeficienteEleitoral) {
    printf("---------------------------------------------------------------\n");
    printf("\nCoeficientes Eleitorais por Partido:\n");
    for (int i = 0; i < MAX_PARTIDOS; i++) {
        printf("%s: %.2f\n", partido[i], (float)votosPorPartido[i] / coeficienteEleitoral);
    }
}


void encontrarCandidatosEleitos(char nomeCandidato[MAX_CANDIDATOS][50], int votos[MAX_CANDIDATOS], char partido[MAX_CANDIDATOS][20], float coeficienteEleitoral) {
    printf("---------------------------------------------------------------\n");
    printf("\nCandidatos Eleitos:\n");
    int vagasRestantes = 7; 

    while (vagasRestantes > 0) {
        int indiceEleito = -1;
        float maiorFracao = -1.0;

        for (int i = 0; i < MAX_CANDIDATOS; i++) {
            if (votos[i] > 0) {
                float fracao = (float)votos[i] / coeficienteEleitoral;
                if (fracao > maiorFracao) {
                    maiorFracao = fracao;
                    indiceEleito = i;
                }
            }
        }

        if (indiceEleito >= 0) {
            printf("%s (%s)\n", nomeCandidato[indiceEleito], partido[indiceEleito]);
            votos[indiceEleito] = 0;
            vagasRestantes--;
        } else {
            break; 
        }
    }
}

int main() {
    char nomeCandidato[MAX_CANDIDATOS][50];
    char partido[MAX_CANDIDATOS][20];
    int votos[MAX_CANDIDATOS];
    int votosPorPartido[MAX_PARTIDOS];
    float coeficienteEleitoral;

    int numCandidatos;

    printf("\n\n---------------------- TOTALIZADOR DE VOTOS PARA DEPUTADO ----------------------\n\n");
    printf("Informe o número de candidatos a Deputado desta eleição (máximo de 20 candidatos): ");
    scanf("%d", &numCandidatos);
     printf("\n ---------------------------------------------------------------\n\n");

    for (int i = 0; i < numCandidatos; i++) {
        lerNomeCandidato(nomeCandidato, i);
        lerPartido(partido, i);
        lerVotos(votos, i);
    }

    coeficienteEleitoral = calcularCoeficienteEleitoral(votos, numCandidatos);
    calcularVotosPorPartido(partido, votos, numCandidatos, votosPorPartido);
    imprimirCoeficientesEleitorais(partido, votosPorPartido, coeficienteEleitoral);
    encontrarCandidatosEleitos(nomeCandidato, votos, partido, coeficienteEleitoral);

    return 0;
}
