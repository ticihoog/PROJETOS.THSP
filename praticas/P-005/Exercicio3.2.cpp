#include <iostream>
#include <limits> /

int main() {
    int num;

   
    std::cout << "Digite um número inteiro: ";
    std::cin >> num;

    
    std::cout << num << (num > std::numeric_limits<short>::max() ? " e maior que um short int" : " este valor pertence ao intervalo dos short int") << std::endl;

    return 0;
}
