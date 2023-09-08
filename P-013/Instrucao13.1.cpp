#include <iostream>

struct empregado {
    std::string nome;
    std::string sobrenome;
    int ano_nascimento;
    std::string RG;
    int ano_admissao;
    float salario;
};

void Reajusta_dez_porcento(empregado empregados[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        empregados[i].salario *= 1.1; 
    }
}
int main() {
    empregado empregados[50];
    empregados[0] = {"João", "Silva", 1985, "123456789", 2010, 2000.0};
    empregados[1] = {"Maria", "Santos", 1990, "987654321", 2015, 2500.0};
    empregados[2] = {"Pedro", "Almeida", 1988, "567891234", 2012, 1800.0};

    Reajusta_dez_porcento(empregados, 3); 
    for (int i = 0; i < 3; i++) {
        std::cout << "Nome: " << empregados[i].nome << std::endl;
        std::cout << "Sobrenome: " << empregados[i].sobrenome << std::endl;
        std::cout << "Ano de Nascimento: " << empregados[i].ano_nascimento << std::endl;
        std::cout << "RG: " << empregados[i].RG << std::endl;
        std::cout << "Ano de Admissão: " << empregados[i].ano_admissao << std::endl;
        std::cout << "Salário: " << empregados[i].salario << std::endl;
        std::cout << "-----------------" << std::endl;
    }

    return 0;
}
