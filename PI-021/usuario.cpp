#include <iostream>
#include <string>
#include <vector>

class Usuario {
public:
    Usuario(const std::string& nome) : nome(nome) {}

    const std::string& getNome() const {
        return nome;
    }

    void emprestarLivro(Livro& livro) {
        livro.emprestarLivro();
        livrosEmprestados.push_back(&livro);
        std::cout << "Livro emprestado para " << nome << std::endl;
    }

    void devolverLivro(Livro& livro) {
        livro.devolverLivro();
        livrosEmprestados.erase(
            std::remove(livrosEmprestados.begin(), livrosEmprestados.end(), &livro),
            livrosEmprestados.end());
        std::cout << "Livro devolvido por " << nome << std::endl;
    }

    void listarLivrosEmprestados() {
        std::cout << "Livros emprestados para " << nome << ":\n";
        for (const Livro* livro : livrosEmprestados) {
            std::cout << "Título: " << livro->getTitulo() << ", Autor: " << livro->getAutor() << std::endl;
        }
    }

private:
    std::string nome;
    std::vector<const Livro*> livrosEmprestados;
};

