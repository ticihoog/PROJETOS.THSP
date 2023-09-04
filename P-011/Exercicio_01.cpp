#include <iostream>

void maxmin(int vetor[], int n, int &maximo, int &minimo) {
    if (n <= 0) {
        // Se o vetor estiver vazio, não faz nada.
        return;
    }

    maximo = vetor[0];
    minimo = vetor[0];

    for (int i = 1; i < n; i++) {
        if (vetor[i] > maximo) {
            maximo = vetor[i];
        } else if (vetor[i] < minimo) {
            minimo = vetor[i];
        }
    }
}

int main() {
    int tamanho;
    std::cout << "Digite o tamanho do vetor: ";
    std::cin >> tamanho;

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        std::cout << "Digite o elemento " << i + 1 << ": ";
        std::cin >> vetor[i];
    }

    int max, min;

    maxmin(vetor, tamanho, max, min);

    std::cout << "Máximo: " << max << std::endl;
    std::cout << "Mínimo: " << min << std::endl;

    return 0;
}
