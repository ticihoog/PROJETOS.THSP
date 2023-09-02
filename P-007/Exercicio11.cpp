#include <iostream>
#include <cmath>

int main() {
    int numero, numeroOriginal, resto, soma = 0, numDigitos = 0;

    std::cout << "Digite um número inteiro: ";
    std::cin >> numero;

    numeroOriginal = numero;

    
    while (numero != 0) {
        numero /= 10;
        numDigitos++;
    }

    numero = numeroOriginal; 

    
    while (numero != 0) {
        resto = numero % 10;
        soma += pow(resto, numDigitos);
        numero /= 10;
    }

    
    if (soma == numeroOriginal) {
        std::cout << numeroOriginal << " é um número de Armstrong." << std::endl;
    } else {
        std::cout << numeroOriginal << " não é um número de Armstrong." << std::endl;
    }

    return 0;
}
