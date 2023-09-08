#include <iostream>
#include <string>
#include <vector>

struct Passageiro {
    int assento;
    std::string dataHora;
    std::string cpf;
    std::string nome;
    int idade;
};

struct Viagem {
    std::string origem;
    std::string destino;
    std::vector<Passageiro> passageiros;
};

int main() {
    
    Viagem viagemRioSP;
    viagemRioSP.origem = "Rio de Janeiro";
    viagemRioSP.destino = "São Paulo";

Passageiro passageiro1;
    passageiro1.assento = 1;
    passageiro1.dataHora = "01/01/2022 08:00";
    passageiro1.cpf = "123456789";
    passageiro1.nome = "Fulano";
    passageiro1.idade = 25;

    viagemRioSP.passageiros.push_back(passageiro1);

 Passageiro passageiro2;
    passageiro2.assento = 2;
    passageiro2.dataHora = "01/01/2022 08:00";
    passageiro2.cpf = "987654321";
    passageiro2.nome = "Ciclano";
    passageiro2.idade = 30;

    viagemRioSP.passageiros.push_back(passageiro2);

    
    double totalArrecadado = viagemRioSP.passageiros.size() * 80.0;
    std::cout << "Total arrecadado para a viagem: R$" << totalArrecadado << std::endl;


    std::string nomePassageiroAssento1 = viagemRioSP.passageiros[0].nome;
    std::cout << "Nome do passageiro do assento 1: " << nomePassageiroAssento1 << std::endl;

    
    int somaIdades = 0;
    for (const Passageiro& passageiro : viagemRioSP.passageiros) {
        somaIdades += passageiro.idade;
    }

     double mediaIdades = static_cast<double>(somaIdades) / viagemRioSP.passageiros.size();
    std::cout << "Média de idade dos passageiros: " << mediaIdades << std::endl;

    return 0;
}