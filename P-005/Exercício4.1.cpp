#include <iostream>
#include <cmath> // Biblioteca para funções matemáticas, incluindo sqrt

int main() {
    double x, y, z;

    
    std::cout << "Digite dois números de ponto flutuante (x e y): "<< std::endl;
    std::cin >> x >> y;

    
    double fxy = 5 * x + 2;
    if (y > fxy) {
        std::cout << "O ponto (" << x << ", " << y << ") está acima da curva." << std::endl;
    } else if (y < fxy) {
        std::cout << "O ponto (" << x << ", " << y << ") está abaixo da curva." << std::endl;
    } else {
        std::cout << "O ponto (" << x << ", " << y << ") está sobre a curva." << std::endl;
    }

    
    z = std::sqrt(x * x + y * y);

    
    double product = x * y;
    std::cout << "A distância euclidiana do ponto (" << x << ", " << y << ") ao centro é: " << z << std::endl;
    std::cout << "O produto de x e y em notação científica: " << std::scientific << product << std::endl;

    return 0;
}
