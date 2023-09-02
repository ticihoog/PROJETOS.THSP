#include <iostream>

int main() {
    char ch1, ch2, ch3;

    
    std::cout << "Digite um caractere: ";
    std::cin >> ch1;

    
    (ch1 >= 'A' && ch1 <= 'Z') ? std::cout << "Letra maiúscula" << std::endl :
    (ch1 >= 'a' && ch1 <= 'z') ? std::cout << "Letra minúscula" << std::endl :
    (ch1 >= '0' && ch1 <= '9') ? std::cout << "Dígito" << std::endl :
    std::cout << "Outro tipo de caractere" << std::endl;

    
    ch2 = 81;
    std::cout << "ch2 em decimal: " << static_cast<int>(ch2) << std::endl;
    std::cout << "ch2 em octal: " << std::oct << static_cast<int>(ch2) << std::endl;
    std::cout << "ch2 em hexadecimal: " << std::hex << static_cast<int>(ch2) << std::endl;
    std::cout << "ch2 como caractere: " << ch2 << std::dec << std::endl;

    
    ch3 = ch2 + ('a' - 'A');
    std::cout << "ch3 em decimal: " << static_cast<int>(ch3) << std::endl;
    std::cout << "ch3 em octal: " << std::oct << static_cast<int>(ch3) << std::endl;
    std::cout << "ch3 em hexadecimal: " << std::hex << static_cast<int>(ch3) << std::endl;
    std::cout << "ch3 como caractere: " << ch3 << std::dec << std::endl;

    return 0;
}
