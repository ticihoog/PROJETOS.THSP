#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Usuario;  // Forward declaration
class Tweet;    // Forward declaration

class RedeSocial {
public:
    void registrar_usuario(const std::string& nome_usuario, const std::string& nome_real);

    Usuario* buscar_usuario(const std::string& nome_usuario);

    std::vector<Usuario> listar_usuarios();

    std::vector<Tweet> listar_tweets();

private:
    std::vector<Usuario> usuarios;
    std::vector<Tweet> tweets;
};

void RedeSocial::registrar_usuario(const std::string& nome_usuario, const std::string& nome_real) {
    Usuario usuario(nome_usuario, nome_real);
    usuarios.push_back(usuario);
}

Usuario* RedeSocial::buscar_usuario(const std::string& nome_usuario) {
    for (Usuario& usuario : usuarios) {
        if (usuario.getNomeUsuario() == nome_usuario) {
            return &usuario;
        }
    }
    return nullptr;
}

std::vector<Usuario> RedeSocial::listar_usuarios() {
    return usuarios;
}

std::vector<Tweet> RedeSocial::listar_tweets() {
    std::vector<Tweet> todos_tweets;
    for (Usuario& usuario : usuarios) {
        for (const Tweet& tweet : usuario.receber_feed()) {
            todos_tweets.push_back(tweet);
        }
    }
    std::sort(todos_tweets.begin(), todos_tweets.end(), [](const Tweet& a, const Tweet& b) {
        return a.getDataCriacao() > b.getDataCriacao();
    });
    return todos_tweets;
}

int main() {
    // Exemplo de uso da classe RedeSocial
    RedeSocial rede_social;

    rede_social.registrar_usuario("user1", "Nome Real 1");
    rede_social.registrar_usuario("user2", "Nome Real 2");

    Usuario* usuario1 = rede_social.buscar_usuario("user1");
    Usuario* usuario2 = rede_social.buscar_usuario("user2");

    if (usuario1 && usuario2) {
        usuario1->postar_tweet("Primeiro tweet do usuário 1.");
        usuario2->postar_tweet("Tweet do usuário 2.");
        usuario2->postar_tweet("Outro tweet do usuário 2.");

        usuario1->seguir(*usuario2);
    }

    std::vector<Usuario> lista_usuarios = rede_social.listar_usuarios();
    std::vector<Tweet> lista_tweets = rede_social.listar_tweets();

    std::cout << "Usuários registrados:\n";
    for (const Usuario& usuario : lista_usuarios) {
        std::cout << "Nome de Usuário: " << usuario.getNomeUsuario()
                  << ", Nome Real: " << usuario.getNomeReal() << std::endl;
    }

    std::cout << "Lista de Tweets:\n";
    for (const Tweet& tweet : lista_tweets) {
        std::cout << "Autor: " << tweet.getAutor().getNomeReal()
                  << ", Conteúdo: " << tweet.getConteudo() << std::endl;
    }

    return 0;
}
