#include <iostream>
#include <string>
#include <vector>

class Livro {
public:
    Livro(const std::string& titulo, const std::string& autor, int copiasDisponiveis)
        : titulo(titulo), autor(autor), copiasDisponiveis(copiasDisponiveis) {}

    const std::string& getTitulo() const {
        return titulo;
    }

    const std::string& getAutor() const {
        return autor;
    }

    int getCopiasDisponiveis() const {
        return copiasDisponiveis;
    }

    void emprestarLivro() {
        if (copiasDisponiveis > 0) {
            copiasDisponiveis--;
            std::cout << "Livro emprestado com sucesso." << std::endl;
        } else {
            std::cout << "Não há cópias disponíveis para empréstimo." << std::endl;
        }
    }

    void devolverLivro() {
        copiasDisponiveis++;
        std::cout << "Livro devolvido com sucesso." << std::endl;
    }

    static void listarLivros(const std::vector<Livro>& livros) {
        std::cout << "Lista de Livros Disponíveis:\n";
        for (const Livro& livro : livros) {
            std::cout << "Título: " << livro.getTitulo() << ", Autor: " << livro.getAutor()
                      << ", Cópias Disponíveis: " << livro.getCopiasDisponiveis() << std::endl;
        }
    }

private:
    std::string titulo;
    std::string autor;
    int copiasDisponiveis;
};

