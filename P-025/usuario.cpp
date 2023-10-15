#include <iostream>
#include <string>
#include <vector>

class Usuario;
class Tweet;

class Usuario {
public:
    Usuario(const std::string& nome_usuario, const std::string& nome_real)
        : nome_usuario(nome_usuario), nome_real(nome_real) {}

    void seguir(Usuario& usuario);

    std::vector<Tweet> receber_feed() const;

    std::string getNomeUsuario() const {
        return nome_usuario;
    }

private:
    std::string nome_usuario;
    std::string nome_real;
    std::vector<Usuario*> seguindo;
};

void Usuario::seguir(Usuario& usuario) {
    if (this != &usuario) {
        seguindo.push_back(&usuario);
        std::cout << "Agora você está seguindo @" << usuario.getNomeUsuario() << std::endl;
    }
}

std::vector<Tweet> Usuario::receber_feed() const {
    std::vector<Tweet> feed;
    for (const Usuario* seguido : seguindo) {
        for (const Tweet& tweet : seguido->tweets) {
            feed.push_back(tweet);
        }
    }
    return feed;
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
    Usuario usuario2("bob", "Bob Smith");
    Usuario usuario3("carol", "Carol Davis");

    while (true) {
        std::cout << "Escolha uma opção:\n";
        std::cout << "1. Seguir usuário\n";
        std::cout << "2. Ler feed\n";
        std::cout << "3. Sair\n";
        int escolha;
        std::cin >> escolha;

        if (escolha == 1) {
            std::string nome_usuario;
            std::cout << "Digite o nome de usuário do usuário que você deseja seguir: ";
            std::cin >> nome_usuario;

            Usuario* usuario_alvo = nullptr;

            if (nome_usuario == usuario2.getNomeUsuario()) {
                usuario_alvo = &usuario2;
            } else if (nome_usuario == usuario3.getNomeUsuario()) {
                usuario_alvo = &usuario3;
            } else {
                std::cout << "Nome de usuário inválido." << std::endl;
                continue;
            }

            usuario1.seguir(*usuario_alvo);
        } else if (escolha == 2) {
            std::vector<Tweet> feed = usuario1.receber_feed();
            std::cout << "Feed de @" << usuario1.getNomeUsuario() << ":\n";
            for (const Tweet& tweet : feed) {
                std::cout << "@" << tweet.getAutor().getNomeUsuario() << ": " << tweet.getConteudo() << std::endl;
            }
        } else if (escolha == 3) {
            std::cout << "Saindo do programa..." << std::endl;
            break;
        } else {
            std::cout << "Escolha uma opção válida." << std::endl;
        }
    }

    return 0;
}

