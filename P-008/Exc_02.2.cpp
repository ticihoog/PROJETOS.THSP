#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int numEstacoes = 250;
    const double temperaturaMaxima = 40.0;
    const double temperaturaMinima = 10.0;

    // Inicialize a semente para a função rand()
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Declare um array para armazenar as temperaturas reportadas por 250 estações meteorológicas
    double temperaturas[numEstacoes];

    // Preencha o array com temperaturas aleatórias
    for (int i = 0; i < numEstacoes; ++i) {
        temperaturas[i] = 10.0 + 30.0 * (std::rand() % 100) / 3000.0;
    }

    // Determine a temperatura máxima e mínima reportadas
    double temperaturaMax = temperaturas[0];
    double temperaturaMin = temperaturas[0];
    double somaTemperaturas = 0.0;

    for (int i = 0; i < numEstacoes; ++i) {
        if (temperaturas[i] > temperaturaMax) {
            temperaturaMax = temperaturas[i];
        }
        if (temperaturas[i] < temperaturaMin) {
            temperaturaMin = temperaturas[i];
        }
        somaTemperaturas += temperaturas[i];
    }

    // Determine a temperatura média entre as 250 estações
    double temperaturaMedia = somaTemperaturas / numEstacoes;

    // Atualize o array com as temperaturas das estações de acordo com a previsão do modelo
    for (int i = 0; i < numEstacoes; ++i) {
        if (temperaturas[i] > temperaturaMedia) {
            temperaturas[i] += 1.0;
        } else {
            temperaturas[i] -= 2.0;
        }
    }

    // Imprima os resultados
    std::cout << "Temperatura Máxima: " << temperaturaMax << "°C" << std::endl;
    std::cout << "Temperatura Mínima: " << temperaturaMin << "°C" << std::endl;
    std::cout << "Temperatura Média: " << temperaturaMedia << "°C" << std::endl;

    return 0;
}
