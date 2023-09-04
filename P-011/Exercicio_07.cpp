#include <iostream>

// Função para multiplicar cada elemento do vetor pelo multiplicador
void multiplica_por_n(int *vet, int qtde, int n) {
    for (int i = 0; i < qtde; i++) {
        vet[i] *= n;
    }
}

int main() {
    int qtde, multiplicador;

    std::cout << "Digite a quantidade de elementos no vetor: ";
    std::cin >> qtde;

    int *vetor = new int[qtde];

    std::cout << "Digite os elementos do vetor: ";
    for (int i = 0; i < qtde; i++) {
        std::cin >> vetor[i];
    }

    std::cout << "Digite o multiplicador: ";
    std::cin >> multiplicador;

    multiplica_por_n(vetor, qtde, multiplicador);

    std::cout << "Vetor multiplicado por " << multiplicador << ": ";
    for (int i = 0; i < qtde; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    // Lembre-se de liberar a memória alocada dinamicamente
    delete[] vetor;

    return 0;
}
