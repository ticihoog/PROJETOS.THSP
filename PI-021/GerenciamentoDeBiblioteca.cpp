#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Livro {
public:
    Livro(const std::string& titulo, const std::string& autor, int numCopias)
        : titulo(titulo), autor(autor), numCopias(numCopias), numCopiasDisponiveis(numCopias) {}

    const std::string& getTitulo() const {
        return titulo;
    }

    const std::string& getAutor() const {
        return autor;
    }

    int getNumCopias() const {
        return numCopias;
    }

    int getNumCopiasDisponiveis() const {
        return numCopiasDisponiveis;
    }

    static void adicionarLivro(const std::string& titulo, const std::string& autor, int numCopias);
    static void listarLivros();
    static void emprestarLivro(const std::string& titulo, const std::string& usuario);
    static void devolverLivro(const std::string& titulo, const std::string& usuario);
    static void listarLivrosEmprestados(const std::string& usuario);

private:
    std::string titulo;
    std::string autor;
    int numCopias;
    int numCopiasDisponiveis;
    static std::vector<Livro> biblioteca;
};

std::vector<Livro> Livro::biblioteca;

void Livro::adicionarLivro(const std::string& titulo, const std::string& autor, int numCopias) {
    biblioteca.push_back(Livro(titulo, autor, numCopias));
    std::cout << "Livro adicionado à biblioteca: " << titulo << " (" << autor << ")\n";
}

void Livro::listarLivros() {
    std::cout << "Livros na biblioteca:\n";
    for (const Livro& livro : biblioteca) {
        std::cout << "Título: " << livro.getTitulo() << " | Autor: " << livro.getAutor() << " | Disponíveis: " << livro.getNumCopiasDisponiveis() << "/" << livro.getNumCopias() << std::endl;
    }
}

void Livro::emprestarLivro(const std::string& titulo, const std::string& usuario) {
    for (Livro& livro : biblioteca) {
        if (livro.getTitulo() == titulo && livro.numCopiasDisponiveis > 0) {
            livro.numCopiasDisponiveis--;
            std::cout << "Livro emprestado: " << titulo << " por " << usuario << std::endl;
            return;
        }
    }
    std::cout << "Livro não disponível: " << titulo << std::endl;
}

void Livro::devolverLivro(const std::string& titulo, const std::string& usuario) {
    for (Livro& livro : biblioteca) {
        if (livro.getTitulo() == titulo) {
            livro.numCopiasDisponiveis++;
            std::cout << "Livro devolvido: " << titulo << " por " << usuario << std::endl;
            return;
        }
    }
}

void Livro::listarLivrosEmprestados(const std::string& usuario) {
    std::cout << "Livros emprestados por " << usuario << ":\n";
    for (const Livro& livro : biblioteca) {
        if (livro.getNumCopias() - livro.getNumCopiasDisponiveis > 0) {
            std::cout << "Título: " << livro.getTitulo() << " | Autor: " << livro.getAutor() << std::endl;
        }
    }
}

class Usuario {
public:
    Usuario(const std::string& nome) : nome(nome) {}

    const std::string& getNome() const {
        return nome;
    }

    static void listarLivrosEmprestados(const std::string& usuario);

private:
    std::string nome;
};

void Usuario::listarLivrosEmprestados(const std::string& usuario) {
    Livro::listarLivrosEmprestados(usuario);
}

int main() {
    while (true) {
        std::cout << "Escolha uma opção:\n";
        std::cout << "1. Adicionar livro à biblioteca\n";
        std::cout << "2. Listar livros na biblioteca\n";
        std::cout << "3. Emprestar livro\n";
        std::cout << "4. Devolver livro\n";
        std::cout << "5. Listar livros emprestados por usuário\n";
        std::cout << "6. Sair\n";
        int escolha;
        std::cin >> escolha;

        if (escolha == 1) {
            std::string titulo, autor;
            int numCopias;
            std::cout << "Digite o título do livro: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            std::cout << "Digite o autor do livro: ";
            std::getline(std::cin, autor);
            std::cout << "Digite o número de cópias: ";
            std::cin >> numCopias;
            Livro::adicionarLivro(titulo, autor, numCopias);
        } else if (escolha == 2) {
            Livro::listarLivros();
        } else if (escolha == 3) {
            std::string titulo, usuario;
            std::cout << "Digite o título do livro: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            std::cout << "Digite o nome do usuário: ";
            std::getline(std::cin, usuario);
            Livro::emprestarLivro(titulo, usuario);
        } else if (escolha == 4) {
            std::string titulo, usuario;
            std::cout << "Digite o título do livro: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            std::cout << "Digite o nome do usuário: ";
            std::getline(std::cin, usuario);
            Livro::devolverLivro(titulo, usuario);
        } else if (escolha == 5) {
            std::string nome_usuario;
            std::cout << "Digite o nome do usuário: ";
            std::cin.ignore();
            std::getline(std::cin, nome_usuario);
            Usuario user(nome_usuario);
            user.listarLivrosEmprestados(nome_usuario);
        } else if (escolha == 6) {
            std::cout << "Saindo do programa..." << std::endl;
            break;
        } else {
            std::cout << "Escolha uma opção válida." << std::endl;
        }
    }

    return 0;
}
