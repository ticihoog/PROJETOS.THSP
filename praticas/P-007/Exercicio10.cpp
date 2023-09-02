#include <iostream>

int main() {
    int numero;
    int termoAnterior = 0;
    int termoAtual = 1;

    std::cout << "Digite um número inteiro: ";
    std::cin >> numero;

    std::cout << "Sequência de Fibonacci até " << numero << ": " << termoAnterior << " ";

    while (termoAtual <= numero) {
        std::cout << termoAtual << " ";

        int proximoTermo = termoAnterior + termoAtual;
        termoAnterior = termoAtual;
        termoAtual = proximoTermo;
    }

    std::cout << std::endl;

    return 0;
}
