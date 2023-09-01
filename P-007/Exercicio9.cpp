#include <iostream>

int main() {
    int numero;
    int somaDivisores = 0;

    std::cout << "Digite um número inteiro: ";
    std::cin >> numero;

    for (int i = 1; i <= numero / 2; ++i) {
        if (numero % i == 0) {
            somaDivisores += i;
        }
    }

    if (somaDivisores == numero) {
        std::cout << numero << " é um número perfeito." << std::endl;
    } else {
        std::cout << numero << " não é um número perfeito." << std::endl;
    }

    return 0;
}
