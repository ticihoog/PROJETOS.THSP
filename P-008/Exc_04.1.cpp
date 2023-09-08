#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int larguraImagem = 640;
const int alturaImagem = 480;
const int valorMaximo = 255;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Simula a captura de uma imagem em tons de cinza
    int imagem[alturaImagem][larguraImagem];

    for (int y = 0; y < alturaImagem; ++y) {
        for (int x = 0; x < larguraImagem; ++x) {
            imagem[y][x] = rand() % (valorMaximo + 1);
        }
    }

    // Constrói o histograma da imagem
    int histograma[valorMaximo + 1] = {0};

    for (int y = 0; y < alturaImagem; ++y) {
        for (int x = 0; x < larguraImagem; ++x) {
            int intensidade = imagem[y][x];
            histograma[intensidade]++;
        }
    }

    // Imprime o histograma
    for (int i = 0; i <= valorMaximo; ++i) {
        std::cout << "Intensidade " << i << ": " << histograma[i] << " pixels" << std::endl;
    }

    return 0;
}
