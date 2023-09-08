#include <iostream>

// Função para realizar a adição
double adicionar(double a, double b) {
    return a + b;
}

// Função para realizar a subtração
double subtrair(double a, double b) {
    return a - b;
}

// Função para realizar a multiplicação
double multiplicar(double a, double b) {
    return a * b;
}

// Função para realizar a divisão
double dividir(double a, double b) {
    if (b == 0) {
        std::cout << "Erro: Divisão por zero." << std::endl;
        return 0.0; // Ou qualquer outro valor adequado para lidar com o erro
    }
    return a / b;
}

int main() {
    double numero1, numero2;
    char operacao;

    std::cout << "Digite um número: ";
    std::cin >> numero1;

    std::cout << "Digite uma operação (+, -, *, /): ";
    std::cin >> operacao;

    std::cout << "Digite outro número: ";
    std::cin >> numero2;

    double resultado;

    // Realiza a operação com base na escolha do usuário
    switch (operacao) {
        case '+':
            resultado = adicionar(numero1, numero2);
            break;
        case '-':
            resultado = subtrair(numero1, numero2);
            break;
        case '*':
            resultado = multiplicar(numero1, numero2);
            break;
        case '/':
            resultado = dividir(numero1, numero2);
            break;
        default:
            std::cout << "Operação inválida." << std::endl;
            return 1;
    }

    std::cout << "Resultado: " << resultado << std::endl;

    return 0;
}
