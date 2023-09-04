#include <iostream>
#include <string>

// Função para encontrar as ocorrências de uma letra em uma string
int* encontra_letra(const std::string& str, char letra, int& tamanho) {
    int* indices = nullptr; // Inicializa o vetor de índices como nulo
    tamanho = 0; // Inicializa o tamanho como zero

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == letra) {
            // A cada ocorrência da letra, realocamos o vetor para incluir o novo índice
            int* novo_indices = new int[tamanho + 1];

            // Copiamos os índices existentes para o novo vetor
            for (int j = 0; j < tamanho; j++) {
                novo_indices[j] = indices[j];
            }

            // Adicionamos o novo índice ao final do vetor
            novo_indices[tamanho] = i;

            // Atualizamos o vetor de índices e o tamanho
            delete[] indices;
            indices = novo_indices;
            tamanho++;
        }
    }

    return indices;
}

int main() {
    std::string texto;
    char letra;

    std::cout << "Digite uma string: ";
    std::cin >> texto;

    std::cout << "Digite uma letra para encontrar: ";
    std::cin >> letra;

    int tamanho;
    int* indices = encontra_letra(texto, letra, tamanho);

    if (tamanho == 0) {
        std::cout << "A letra '" << letra << "' não foi encontrada na string." << std::endl;
    } else {
        std::cout << "A letra '" << letra << "' foi encontrada nas seguintes posições: ";
        for (int i = 0; i < tamanho; i++) {
            std::cout << indices[i] << " ";
        }
        std::cout << std::endl;
    }

    // Lembre-se de liberar a memória alocada dinamicamente
    delete[] indices;

    return 0;
}
