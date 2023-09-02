#include <iostream>

int main() {
    int altura;
    char caractere = 'A';

    std::cout << "Digite a altura do padrão: ";
    std::cin >> altura;

    for (int i = 1; i <= altura; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << caractere;
            caractere++;
        }
        std::cout << std::endl;
    }

    return 0;
}
