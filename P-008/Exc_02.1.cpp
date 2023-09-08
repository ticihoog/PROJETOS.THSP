#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    const int tamanhoArray = 100;
    const int valorMaximo = 20;

    // Inicialize a semente para a função rand()
    std::srand(std::time(0));

    // Preencha um array com 100 elementos de tipo int com valores aleatoriamente gerados entre 1 e 20
    int array[tamanhoArray];
    for (int i = 0; i < tamanhoArray; ++i) {
        array[i] = 1 + std::rand() % valorMaximo;
    }

    // Utilize um array de 20 posições para determinar quantas vezes se repete cada um dos possíveis valores gerados no array
    int contagem[valormaximo] = {0};
    for (int i = 0; i < tamanhoArray; ++i) {
        int valor = array[i];
        contagem[valor - 1]++;
    }

    // Determine qual ou quais os números que mais vezes aparecem no array
    int maxFrequencia = 0;
    for (int i = 0; i < valorMaximo; ++i) {
        if (contagem[i] > maxFrequencia) {
            maxFrequencia = contagem[i];
        }
    }

    std::cout << "Números mais frequentes: ";
    for (int i = 0; i < valorMaximo; ++i) {
        if (contagem[i] == maxFrequencia) {
            std::cout << i + 1 << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
