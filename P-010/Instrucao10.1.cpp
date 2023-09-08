#include <iostream>
#include <string>
#include <queue>

struct Aluno
{
    std::string nome;
    float nota1;
    float nota2;
    float media;
    bool aprovado;
};

int main()
{
    std::queue<Aluno> filaAlunos;

    // Adicione os alunos à fila (exemplo)
    Aluno aluno1 = {"João", 8.5, 7.2, 0.0, false};
    Aluno aluno2 = {"Maria", 6.8, 9.1, 0.0, false};
    filaAlunos.push(aluno1);
    filaAlunos.push(aluno2);
    while (!filaAlunos.empty())
    {
        Aluno aluno = filaAlunos.front();
        filaAlunos.pop();

        aluno.media = (aluno.nota1 + aluno.nota2) / 2;

        if (aluno.media >= 7)
        {
            aluno.aprovado = true;
        }
        else
        {
            aluno.aprovado = false;
        }

        // Imprima o resultado
        std::cout << "Aluno: " << aluno.nome << std::endl;
        std::cout << "Nota 1: " << aluno.nota1 << std::endl;
        std::cout << "Nota 2: " << aluno.nota2 << std::endl;
        std::cout << "Média: " << aluno.media << std::endl;
        if (aluno.aprovado)
        {
            std::cout << "Situação: Aprovado" << std::endl;
        }
        else
        {
            std::cout << "Situação: Reprovado" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
