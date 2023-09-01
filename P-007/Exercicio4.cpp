#include <iostream>

bool ehPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Números primos de 1 a 100:" << std::endl;
    
    for (int i = 1; i <= 100; ++i) {
        if (ehPrimo(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
