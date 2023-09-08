#include <iostream>
#include <string>

// Struct para representar o Livro
struct Livro {
    std::string titulo;
    std::string autor;
    std::string genero;
    int numPaginas;
    int anoPublicacao;
    std::string isbn;
    double preco;

    // Método para abrir o livro
    void abrir() {
        std::cout << "O livro '" << titulo << "' foi aberto para leitura." << std::endl;
    }

    // Método para fechar o livro
    void fechar() {
        std::cout << "O livro '" << titulo << "' foi fechado após a leitura." << std::endl;
    }

    // Método para calcular o preço com desconto
    double calcularPrecoComDesconto(double desconto) {
        return preco - (preco * desconto);
    }

    // Método para exibir informações detalhadas sobre o livro
    void exibirInformacoes() {
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Autor: " << autor << std::endl;
        std::cout << "Gênero: " << genero << std::endl;
        std::cout << "Número de páginas: " << numPaginas << std::endl;
        std::cout << "Ano de publicação: " << anoPublicacao << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
        std::cout << "Preço: $" << preco << std::endl;
    }
};

int main() {
    // Criar uma instância da struct Livro
    Livro meuLivro;
    
    // Preencher os campos da struct
    meuLivro.titulo = "Dom Casmurro";
    meuLivro.autor = "Machado de Assis";
    meuLivro.genero = "Ficção";
    meuLivro.numPaginas = 250;
    meuLivro.anoPublicacao = 1899;
    meuLivro.isbn = "978-85-06-00037-3";
    meuLivro.preco = 29.99;

    // Exibir informações detalhadas sobre o livro
    meuLivro.exibirInformacoes();

    // Abrir e fechar o livro
    meuLivro.abrir();
    meuLivro.fechar();

    // Calcular o preço com desconto de 10%
    double desconto = 0.1;
    double precoComDesconto = meuLivro.calcularPrecoComDesconto(desconto);
    std::cout << "Preço com desconto de " << (desconto * 100) << "%: $" << precoComDesconto << std::endl;

    return 0;
}
