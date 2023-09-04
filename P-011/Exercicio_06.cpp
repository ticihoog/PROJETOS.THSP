#include <iostream>

// Função para intercalar dois vetores
int* intercala(int *vet1, int tam1, int *vet2, int tam2) {
    int *resultado = new int[tam1 + tam2]; // Crie um novo vetor para armazenar o resultado
    int i = 0, j = 0, k = 0;

    // Intercale os elementos dos dois vetores
    while (i < tam1 && j < tam2) {
        resultado[k++] = vet1[i++];
        resultado[k++] = vet2[j++];
    }

    // Se um dos vetores tiver elementos restantes, copie-os para o resultado
    while (i < tam1) {
        resultado[k++] = vet1[i++];
    }

    while (j < tam2) {
        resultado[k++] = vet2[j++];
    }

    return resultado;
}

int main() {
    int tam1, tam2;

    std::cout << "Digite o tamanho do primeiro vetor: ";
    std::cin >> tam1;

    int *vetor1 = new int[tam1];

    std::cout << "Digite os elementos do primeiro vetor: ";
    for (int i = 0; i < tam1; i++) {
        std::cin >> vetor1[i];
    }

    std::cout << "Digite o tamanho do segundo vetor: ";
    std::cin >> tam2;

    int *vetor2 = new int[tam2];

    std::cout << "Digite os elementos do segundo vetor: ";
    for (int i = 0; i < tam2; i++) {
        std::cin >> vetor2[i];
    }

    int *resultado = intercala(vetor1, tam1, vetor2, tam2);

    std::cout << "Vetor intercalado: ";
    for (int i = 0; i < tam1 + tam2; i++) {
        std::cout << resultado[i] << " ";
    }
    std::cout << std::endl;

    // Lembre-se de liberar a memória alocada dinamicamente
    delete[] vetor1;
    delete[] vetor2;
    delete[] resultado;

    return 0;
}
