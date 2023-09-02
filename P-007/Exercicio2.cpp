#include <iostream>

int main() {
    int num, originalNum, reversedNum = 0;

    
    std::cout << "Digite um número inteiro: ";
    std::cin >> num;

    originalNum = num; 

    
    while (num > 0) {
        int digito = num % 10;
        reversedNum = reversedNum * 10 + digito;
        num /= 10;
    }

    
    if (originalNum == reversedNum) {
        std::cout << "O número é um palíndromo." << std::endl;
    } else {
        std::cout << "O número não é um palíndromo." << std::endl;
    }

    return 0;
}
