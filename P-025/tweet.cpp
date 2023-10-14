#include <iostream>
#include <string>
#include <vector>

class Usuario;
class Tweet;

class Usuario {
public:
    Usuario(const std::string& nome_usuario, const std::string& nome_real)
        : nome_usuario(nome_usuario), nome_real(nome_real) {}

    void postar_tweet(const std::string& conteudo);

    std::string getNomeUsuario() const {
        return nome_usuario;
    }

private:
    std::string nome_usuario;
    std::string nome_real;
    std::vector<Tweet> tweets;
};

void Usuario::postar_tweet(const std::string& conteudo) {
    Tweet tweet(*this, conteudo);
    tweets.push_back(tweet);
    std::cout << "Tweet postado com sucesso!" << std::endl;
}

class Tweet {
public:
    Tweet(Usuario& autor, const std::string& conteudo)
        : autor(autor), conteudo(conteudo) {}

    std::string getConteudo() const {
        return conteudo;
    }

    Usuario getAutor() const {
        return autor;
    }

private:
    Usuario autor;
    std::string conteudo;
};

int main() {
    Usuario usuario1("alice", "Alice Johnson");

    while (true) {
        std::cout << "Escolha uma opção:\n";
        std::cout << "1. Postar tweet\n";
        std::cout << "2. Sair\n";
        int escolha;
        std::cin >> escolha;

        if (escolha == 1) {
            std::string conteudo;
            std::cout << "Digite o conteúdo do tweet: ";
            std::cin.ignore();
            std::getline(std::cin, conteudo);
            usuario1.postar_tweet(conteudo);
        } else if (escolha == 2) {
            std::cout << "Saindo do programa..." << std::endl;
            break;
        } else {
            std::cout << "Escolha uma opção válida." << std::endl;
        }
    }

    return 0;
}
