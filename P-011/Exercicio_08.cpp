#include <iostream>

// Função para verificar se um número é primo
bool eh_primo(int numero) {
    if (numero <= 1) {
        return false;
    }

    // Verifica se o número é divisível por algum número entre 2 e a raiz quadrada dele
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }

    return true;
}

// Função para contar números primos em um vetor
int conta_primos(int *vetor, int qtde) {
    int count = 0;

    for (int i = 0; i < qtde; i++) {
        if (eh_primo(vetor[i])) {
            count++;
        }
    }

    return count;
}

int main() {
    int qtde;

    std::cout << "Digite a quantidade de elementos no vetor: ";
    std::cin >> qtde;

    int *vetor = new int[qtde];

    std::cout << "Digite os elementos do vetor: ";
    for (int i = 0; i < qtde; i++) {
        std::cin >> vetor[i];
    }

    int quantidade_primos = conta_primos(vetor, qtde);

    std::cout << "Quantidade de números primos no vetor: " << quantidade_primos << std::endl;

    // Lembre-se de liberar a memória alocada dinamicamente
    delete[] vetor;

    return 0;
}
