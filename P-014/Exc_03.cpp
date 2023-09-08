#include <iostream>
#include <cmath>

// Definição da struct Ponto
struct Ponto {
    double x;
    double y;
};

// Função para calcular a distância entre dois pontos
double calcularDistancia(Ponto ponto1, Ponto ponto2) {
    double diferencaX = ponto2.x - ponto1.x;
    double diferencaY = ponto2.y - ponto1.y;
    
    return std::sqrt(diferencaX * diferencaX + diferencaY * diferencaY);
}

int main() {
    Ponto ponto1, ponto2;

    // Solicita ao usuário as coordenadas do primeiro ponto
    std::cout << "Digite as coordenadas do primeiro ponto:" << std::endl;
    std::cout << "X: ";
    std::cin >> ponto1.x;
    std::cout << "Y: ";
    std::cin >> ponto1.y;

    // Solicita ao usuário as coordenadas do segundo ponto
    std::cout << "Digite as coordenadas do segundo ponto:" << std::endl;
    std::cout << "X: ";
    std::cin >> ponto2.x;
    std::cout << "Y: ";
    std::cin >> ponto2.y;

    // Calcula a distância entre os dois pontos
    double distancia = calcularDistancia(ponto1, ponto2);

    // Exibe a distância calculada
    std::cout << "A distância entre os pontos é: " << distancia << std::endl;

    return 0;
}
