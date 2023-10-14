#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

class Tweet;  

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
    RedeSocial rede_social;

    while (true) {
        std::cout << "Escolha uma opção:\n";
        std::cout << "1. Publicar um tweet\n";
        std::cout << "2. Seguir outro usuário\n";
        std::cout << "3. Ler seu feed\n";
        std::cout << "4. Listar todos os usuários e tweets\n";
        std::cout << "5. Sair\n";
        int escolha;
        std::cin >> escolha;

        if (escolha == 1) {
            std::string nome_usuario, conteudo;
            std::cout << "Digite seu nome de usuário: ";
            std::cin >> nome_usuario;
            Usuario* usuario = rede_social.buscar_usuario(nome_usuario);
            if (usuario) {
                std::cin.ignore();  // Limpa o buffer
                std::cout << "Digite o conteúdo do tweet: ";
                std::getline(std::cin, conteudo);
                usuario->postar_tweet(conteudo);
                std::cout << "Tweet publicado com sucesso!" << std::endl;
            } else {
                std::cout << "Usuário não encontrado." << std::endl;
            }
        } else if (escolha == 2) {
            std::string nome_usuario, nome_usuario_a_seguir;
            std::cout << "Digite seu nome de usuário: ";
            std::cin >> nome_usuario;
            Usuario* usuario = rede_social.buscar_usuario(nome_usuario);
            if (usuario) {
                std::cout << "Digite o nome de usuário que deseja seguir: ";
                std::cin >> nome_usuario_a_seguir;
                Usuario* usuario_a_seguir = rede_social.buscar_usuario(nome_usuario_a_seguir);
                if (usuario_a_seguir) {
                    usuario->seguir(*usuario_a_seguir);
                    std::cout << "Agora você está seguindo " << nome_usuario_a_seguir << "." << std::endl;
                } else {
                    std::cout << "Usuário a seguir não encontrado." << std::endl;
                }
            } else {
                std::cout << "Usuário não encontrado." << std::endl;
            }
        } else if (escolha == 3) {
            std::string nome_usuario;
            std::cout << "Digite seu nome de usuário: ";
            std::cin >> nome_usuario;
            Usuario* usuario = rede_social.buscar_usuario(nome_usuario);
            if (usuario) {
                std::vector<Tweet> feed = usuario->receber_feed();
                if (!feed.empty()) {
                    std::cout << "Feed de @" << usuario->getNomeUsuario() << ":\n";
                    for (const Tweet& tweet : feed) {
                        std::cout << "@" << tweet.getAutor().getNomeUsuario() << ": " << tweet.getConteudo() << std::endl;
                    }
                } else {
                    std::cout << "Seu feed está vazio." << std::endl;
                }
            } else {
                std::cout << "Usuário não encontrado." << std::endl;
            }
        } else if (escolha == 4) {
            std::vector<Usuario> lista_usuarios = rede_social.listar_usuarios();
            std::vector<Tweet> lista_tweets = rede_social.listar_tweets();

            std::cout << "Usuários registrados:\n";
            for (const Usuario& usuario : lista_usuarios) {
                std::cout << "Nome de Usuário: @" << usuario.getNomeUsuario()
                          << ", Nome Real: " << usuario.getNomeReal() << std::endl;
            }

            std::cout << "Lista de Tweets:\n";
            for (const Tweet& tweet : lista_tweets) {
                std::cout << "@" << tweet.getAutor().getNomeUsuario() << ": " << tweet.getConteudo() << std::endl;
            }
        } else if (escolha == 5) {
            std::cout << "Saindo do programa..." << std::endl;
            break;
        } else {
            std::cout << "Escolha uma opção válida." << std::endl;
        }
    }

    return 0;
}
