#include <iostream>
#include <string>
#include <vector>
#include "livro.cpp"
#include "usuario.cpp"

int main() {
    std::vector<Livro> livros;
    std::vector<Usuario> usuarios;

    Livro livro1("Livro A", "Autor A", 5);
    Livro livro2("Livro B", "Autor B", 3);
    Livro livro3("Livro C", "Autor C", 2);
    
    livros.push_back(livro1);
    livros.push_back(livro2);
    livros.push_back(livro3);

    Usuario usuario1("Usuário 1");
    Usuario usuario2("Usuário 2");

    usuarios.push_back(usuario1);
    usuarios.push_back(usuario2);

    while (true) {
        int choice;
        std::cout << "Menu:\n";
        std::cout << "1. Listar Livros Disponíveis\n";
        std::cout << "2. Listar Livros Emprestados por Usuário\n";
        std::cout << "3. Emprestar Livro\n";
        std::cout << "4. Devolver Livro\n";
        std::cout << "5. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> choice;

        if (choice == 1) {
            Livro::listarLivros(livros);
        } else if (choice == 2) {
            int userChoice;
            std::cout << "Selecione o usuário (1 ou 2): ";
            std::cin >> userChoice;

            if (userChoice == 1) {
                usuarios[0].listarLivrosEmprestados();
            } else if (userChoice == 2) {
                usuarios[1].listarLivrosEmprestados();
            } else {
                std::cout << "Usuário inválido." << std::endl;
            }
        } else if (choice == 3) {
            int bookChoice, userChoice;
            std::cout << "Selecione o livro (1, 2 ou 3): ";
            std::cin >> bookChoice;
            std::cout << "Selecione o usuário (1 ou 2): ";
            std::cin >> userChoice;

            if (bookChoice >= 1 && bookChoice <= 3 && userChoice >= 1 && userChoice <= 2) {
                usuarios[userChoice - 1].emprestarLivro(livros[bookChoice - 1]);
            } else {
                std::cout << "Escolha inválida." << std::endl;
            }
        } else if (choice == 4) {
            int bookChoice, userChoice;
            std::cout << "Selecione o livro (1, 2 ou 3): ";
            std::cin >> bookChoice;
            std::cout << "Selecione o usuário (1 ou 2): ";
            std::cin >> userChoice;

            if (bookChoice >= 1 && bookChoice <= 3 && userChoice >= 1 && userChoice <= 2) {
                usuarios[userChoice - 1].devolverLivro(livros[bookChoice - 1]);
            } else {
                std::cout << "Escolha inválida." << std::endl;
            }
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    }

    return 0;
}
