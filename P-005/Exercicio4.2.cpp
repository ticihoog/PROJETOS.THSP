#include <iostream>
#include <cmath> // Biblioteca para funções matemáticas, incluindo sqrt

int main() {
    double a, b, c;

    
    std::cout << "Digite os coeficientes a, b e c do polinômio (ax^2 + bx + c): "<< std::endl;
    std::cin >> a >> b >> c;

    
    double delta = b * b - 4 * a * c;

    
    if (delta > 0) {
        double root1 = (-b + std::sqrt(delta)) / (2 * a);
        double root2 = (-b - std::sqrt(delta)) / (2 * a);
        std::cout << "O polinômio tem duas raízes reais:" << std::endl;
        std::cout << "Raiz 1: " << root1 << std::endl;
        std::cout << "Raiz 2: " << root2 << std::endl;
    } else if (delta == 0) {
        double root = -b / (2 * a);
        std::cout << "O polinômio tem uma raiz real:" << std::endl;
        std::cout << "Raiz: " << root << std::endl;
    } else {
        std::cout << "O polinômio não possui raízes reais." << std::endl;
    }

    
    double x;
    std::cout << "Digite um valor para x: ";
    std::cin >> x;
    double px = a * x * x + b * x + c;
    std::cout << "p(x) = " << px << std::endl;

    return 0;
}
