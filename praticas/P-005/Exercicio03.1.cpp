#include <iostream>

int main() {
    int n1, n2, n3;

    
    std::cout << "Digite dois números inteiros: " << std::endl;
    std::cin >> n1 >> n2;

    
    n3 = n1 + n2;
    std::cout << "Soma em hexadecimal: " << std::hex << n3 << std::endl;

    
    n3 = n1 * n2;
    std::cout << "Produto em octal: " << std::oct << n3 << std::endl;

    
    
    n3 = (n1 > n2) ? n1 - n2 : n2 - n1;
    std::cout << "Módulo (valor absoluto da diferença): " << n3 << std::endl;

    
    if (n2 != 0) {
        n3 = n1 / n2;
        std::cout << "Quociente: " << n3 << std::endl;
    } else {
        std::cout << "Divisão por zero não é possível." << std::endl;
    }

   
    if (n2 != 0 && n1 % n2 == 0) {
        std::cout << "a é divisível por b." << std::endl;
    } else {
        std::cout << "a não é divisível por b." << std::endl;
    }

    return 0;
}
