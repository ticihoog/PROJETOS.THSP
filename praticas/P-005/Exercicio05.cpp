#include <iostream>
#include <bitset> 

int main() {
    unsigned char informacaoGenetica;

    
    std::cout << "Digite a informação genética da planta (um caractere sem sinal): "<< std::endl;
    std::cin >> informacaoGenetica;

    
    int genesPresentes = std::bitset<8>(informacaoGenetica).count();

    
    std::cout << "Número de genes presentes: " << genesPresentes << std::endl;

    
    int numeroGene;
    std::cout << "Digite o número do gene que deseja verificar (entre 1 e 8): ";
    std::cin >> numeroGene;

    
    if (numeroGene >= 1 && numeroGene <= 8) {
        bool estaPresente = (informacaoGenetica & (1 << (numeroGene - 1))) != 0;
        if (estaPresente) {
            std::cout << "O gene " << numeroGene << " está presente nesta planta." << std::endl;
        } else {
            std::cout << "O gene " << numeroGene << " não está presente nesta planta." << std::endl;
        }
    } else {
        std::cout << "Número de gene inválido. Deve estar entre 1 e 8." << std::endl;
    }

    return 0;
}
