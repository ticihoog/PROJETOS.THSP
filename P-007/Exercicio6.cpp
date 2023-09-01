#include <iostream>
#include <vector> 

struct Aluno {
    int matricula;
    double nota1;
    double nota2;
    double nota3;
    double media;
};

int main() {
    char continuar;
    std::vector<Aluno> alunos; 

    std::cout << "Cadastro de Alunos" << std::endl;

    do {
        Aluno aluno;

        
        std::cout << "Digite a matrícula do aluno (apenas números): ";
        std::cin >> aluno.matricula;

        
        std::cout << "Digite a primeira nota: ";
        std::cin >> aluno.nota1;
        std::cout << "Digite a segunda nota: ";
        std::cin >> aluno.nota2;
        std::cout << "Digite a terceira nota: ";
        std::cin >> aluno.nota3;

        
        aluno.media = (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;

        
        alunos.push_back(aluno);

        
        std::cout << "Deseja cadastrar outro aluno? (S/N): ";
        std::cin >> continuar;
    } while (continuar == 'S' || continuar == 's');

    
    std::cout << "Dados dos Alunos Cadastrados:" << std::endl;
    std::cout << "Matrícula | Nota 1 | Nota 2 | Nota 3 | Média" << std::endl;
    for (const Aluno& aluno : alunos) {
        std::cout << aluno.matricula << " | " << aluno.nota1 << " | " << aluno.nota2 << " | " << aluno.nota3 << " | " << aluno.media << std::endl;
    }

    return 0;
}
