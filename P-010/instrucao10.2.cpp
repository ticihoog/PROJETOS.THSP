#include <iostream>
#include <vector>
#include <string>

void bubbleSort(std::vector<std::string> &nomes)
{
    int n = nomes.size();
    bool trocou = true;
    while (trocou)
    {
        trocou = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (nomes[i] > nomes[i + 1])
            {
                std::swap(nomes[i], nomes[i + 1]);
                trocou = true;
            }
        }
        n--;
    }
}

int main()
{
    int limite_alunos;
    std::cout << "Informe o limite de alunos: ";
    std::cin >> limite_alunos;

    std::vector<std::string> nomes;
    std::vector<float> notas1;
    std::vector<float> notas2;

    for (int i = 0; i < limite_alunos; i++)
    {
        std::string nome;
        float nota1, nota2;
        std::cout << "Informe o nome do aluno " << i + 1 << ": ";
        std::cin >> nome;
        nomes.push_back(nome);

        std::cout << "Informe a primeira nota do aluno " << i + 1 << ": ";
        std::cin >> nota1;
        notas1.push_back(nota1);

        std::cout << "Informe a segunda nota do aluno " << i + 1 << ": ";
        std::cin >> nota2;
        notas2.push_back(nota2);
    }

    bubbleSort(nomes);
    for (int i = 0; i < limite_alunos; i++)
    {
        std::cout << "Aluno: " << nomes[i] << ", Nota 1: " << notas1[i] << ", Nota 2: " << notas2[i] << std::endl;
    }

    return 0;
}