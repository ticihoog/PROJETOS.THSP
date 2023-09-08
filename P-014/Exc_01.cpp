#include <iostream>

unsigned long long calcularFatorial(int numero) {
    if (numero < 0) {
        // Fatorial não está definido para números negativos
        return 0;
    } else if (numero == 0 || numero == 1) {
        // O fatorial de 0 e 1 é 1
        return 1;
    } else {
        // Caso geral: calcula o fatorial recursivamente
        return numero * calcularFatorial(numero - 1);
    }
}

int main() {
    int numero1, numero2, numero3;

    std::cout << "Digite o primeiro número: ";
    std::cin >> numero1;

    std::cout << "Digite o segundo número: ";
    std::cin >> numero2;

    std::cout << "Digite o terceiro número: ";
    std::cin >> numero3;

    unsigned long long fatorial1 = calcularFatorial(numero1);
    unsigned long long fatorial2 = calcularFatorial(numero2);
    unsigned long long fatorial3 = calcularFatorial(numero3);

    std::cout << "Fatorial de " << numero1 << ": " << fatorial1 << std::endl;
    std::cout << "Fatorial de " << numero2 << ": " << fatorial2 << std::endl;
    std::cout << "Fatorial de " << numero3 << ": " << fatorial3 << std::endl;

    return 0;
}
