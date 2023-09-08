#include <iostream>
#include <vector>
#include <algorithm>

struct Aluno
{
    std::string nome;
    float nota;
};

bool compararAlunos(const Aluno &aluno1, const Aluno &aluno2)
{
    return aluno1.nome < aluno2.nome;
}

int main()
{
    std::vector<Aluno> alunos;
    char opcao;

    do
    {
        std::cout << "Deseja incluir mais alunos? (s/n): ";
        std::cin >> opcao;

        if (opcao == 's')
        {
            Aluno novoAluno;
            std::cout << "Digite o nome do aluno: ";
            std::cin >> novoAluno.nome;
            std::cout << "Digite a nota do aluno: ";
            std::cin >> novoAluno.nota;

            alunos.push_back(novoAluno);
            std::sort(alunos.begin(), alunos.end(), compararAlunos);
        }
    } while (opcao == 's');

    do
    {
        std::cout << "Deseja excluir algum aluno? (s/n): ";
        std::cin >> opcao;
        if (opcao == 's')
        {
            std::string nomeAluno;
            std::cout << "Digite o nome do aluno a ser excluído: ";
            std::cin >> nomeAluno;

            auto it = std::find_if(alunos.begin(), alunos.end(), [&](const Aluno &aluno)
                                   { return aluno.nome == nomeAluno; });

            if (it != alunos.end())
            {
                alunos.erase(it);
                std::cout << "Aluno excluído com sucesso." << std::endl;
            }
            else
            {
                std::cout << "Aluno não encontrado." << std::endl;
            }
        }
    } while (opcao == 's');
    return 0;
}