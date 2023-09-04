#include <iostream>

// Função que realiza as operações descritas
void calcula(int &X, int &Y) {
    // Soma X e Y e armazena o resultado em X
    X = X + Y;

    // Subtrai Y de X e armazena o resultado em Y
    Y = X - 2 * Y; // Subtrair 2 * Y para obter a subtração X - Y
}

int main() {
    int numeroX, numeroY;

    std::cout << "Digite dois números inteiros X e Y: ";
    std::cin >> numeroX >> numeroY;

    calcula(numeroX, numeroY);

    std::cout << "Valor de X após a operação: " << numeroX << std::endl;
    std::cout << "Valor de Y após a operação: " << numeroY << std::endl;

    return 0;
}
