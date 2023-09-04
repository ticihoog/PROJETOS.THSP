#include <iostream>
#include <string>

// Função para codificar uma string
std::string codifica(const std::string& entrada) {
    std::string codificada = entrada; // Inicializa a string codificada com a entrada

    for (char& c : codificada) {
        if (std::isalpha(c)) { // Verifica se o caractere é uma letra
            if (c == 'z') {
                c = 'a'; // Substitui 'z' por 'a'
            } else if (c == 'Z') {
                c = 'A'; // Substitui 'Z' por 'A'
            } else {
                c++; // Incrementa a letra
            }
        }
    }

    return codificada;
}

// Função para decodificar uma string
std::string decodifica(const std::string& entrada) {
    std::string decodificada = entrada; // Inicializa a string decodificada com a entrada

    for (char& c : decodificada) {
        if (std::isalpha(c)) { // Verifica se o caractere é uma letra
            if (c == 'a') {
                c = 'z'; // Substitui 'a' por 'z'
            } else if (c == 'A') {
                c = 'Z'; // Substitui 'A' por 'Z'
            } else {
                c--; // Decrementa a letra
            }
        }
    }

    return decodificada;
}

int main() {
    std::string texto;
    std::cout << "Digite uma string: ";
    std::getline(std::cin, texto);

    std::string texto_codificado = codifica(texto);
    std::string texto_decodificado = decodifica(texto_codificado);

    std::cout << "Texto codificado: " << texto_codificado << std::endl;
    std::cout << "Texto decodificado: " << texto_decodificado << std::endl;

    return 0;
}
