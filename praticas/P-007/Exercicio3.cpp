#include <iostream>

int main() {
    int numero;

    
    std::cout << "Digite um número inteiro: ";
    std::cin >> numero;

    
    std::cout << "Os divisores de " << numero << " são: ";
    for (int divisor = 1; divisor <= numero; ++divisor) {
        if (numero % divisor == 0) {
            std::cout << divisor << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
