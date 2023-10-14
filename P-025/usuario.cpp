#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Tweet;  // Forward declaration

class Usuario {
public:
    Usuario(const std::string& nome_usuario, const std::string& nome_real)
        : nome_usuario(nome_usuario), nome_real(nome_real) {}

    void postar_tweet(const std::string& conteudo);

    void seguir(Usuario& usuario);

    std::vector<Tweet> receber_feed();

    std::string getNomeUsuario() const {
        return nome_usuario;
    }

    std::string getNomeReal() const {
        return nome_real;
    }

private:
    std::string nome_usuario;
    std::string nome_real;
    std::vector<Usuario*> seguidores;
    std::vector<Usuario*> seguindo;
    std::vector<Tweet> tweets;
};

void Usuario::postar_tweet(const std::string& conteudo) {
    Tweet tweet(*this, conteudo);
    tweets.push_back(tweet);
}

void Usuario::seguir(Usuario& usuario) {
    if (this != &usuario) {  // Não pode seguir a si mesmo
        seguindo.push_back(&usuario);
        usuario.seguidores.push_back(this);
    }
}

std::vector<Tweet> Usuario::receber_feed() {
    std::vector<Tweet> feed;
    for (Usuario* seguido : seguindo) {
        for (const Tweet& tweet : seguido->tweets) {
            feed.push_back(tweet);
        }
    }
    std::sort(feed.begin(), feed.end(), [](const Tweet& a, const Tweet& b) {
        return a.getDataCriacao() > b.getDataCriacao();
    });
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

    time_t getDataCriacao() const {
        return data_criacao;
    }

private:
    Usuario autor;
    std::string conteudo;
    time_t data_criacao = time(0);
};

int main() {
    // Exemplo de uso da classe Usuario
    Usuario usuario1("user1", "Nome Real 1");
    Usuario usuario2("user2", "Nome Real 2");

    usuario1.postar_tweet("Primeiro tweet do usuário 1.");
    usuario2.postar_tweet("Tweet do usuário 2.");
    usuario2.postar_tweet("Outro tweet do usuário 2.");

    usuario1.seguir(usuario2);

    std::vector<Tweet> feed_usuario1 = usuario1.receber_feed();

    std::cout << "Feed do usuário 1:\n";
    for (const Tweet& tweet : feed_usuario1) {
        std::cout << "Autor: " << tweet.getAutor().getNomeReal()
                  << ", Conteúdo: " << tweet.getConteudo() << std::endl;
    }

    return 0;
}
