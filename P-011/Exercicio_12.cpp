#include <iostream>
#include <string>

std::string caracteresComuns(const std::string& A, const std::string& B) {
    std::string C = "";

    // Percorre os caracteres da string A
    for (char a : A) {
        // Verifica se o caractere a está presente em B
        if (B.find(a) != std::string::npos) {
            // Se estiver presente, adiciona-o à string C se ainda não estiver lá
            if (C.find(a) == std::string::npos) {
                C += a;
            }
        }
    }

    return C;
}

int main() {
    std::string stringA, stringB;

    std::cout << "Digite a primeira string: ";
    std::cin >> stringA;

    std::cout << "Digite a segunda string: ";
    std::cin >> stringB;

    std::string stringC = caracteresComuns(stringA, stringB);

    if (stringC.empty()) {
        std::cout << "Não há caracteres em comum nas duas strings." << std::endl;
    } else {
        std::cout << "Caracteres comuns: " << stringC << std::endl;
    }

    return 0;
}
