Exercício 5

#include <iostream>
#include <cstdlib> 
#include <ctime>   

int main() {
    
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int numeroAleatorio = std::rand() % 100 + 1; 
    int palpite;
    int tentativas = 0;

    std::cout << "Bem-vindo ao jogo de adivinhação!" << std::endl;

    do {
        std::cout << "Tente adivinhar o número (entre 1 e 100): ";
        std::cin >> palpite;
        tentativas++;

        if (palpite < numeroAleatorio) {
            std::cout << "Seu palpite está baixo. Tente novamente." << std::endl;
        } else if (palpite > numeroAleatorio) {
            std::cout << "Seu palpite está alto. Tente novamente." << std::endl;
        } else {
            std::cout << "Parabéns! Você acertou o número " << numeroAleatorio << " em " << tentativas << " tentativas." << std::endl;
        }
    } while (palpite != numeroAleatorio);

    return 0;
}